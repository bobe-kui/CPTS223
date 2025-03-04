#ifndef AVL_MAP_H
#define AVL_MAP_H
#include "avlNode.h"
#include <iostream>
#include <iterator>
#include <string>
#include <fstream>

template <class Key, class Value>
class AVLMap{

    class Iterator
    {
        public: 
        Iterator()
        {
            this->mMap.mRoot != nullptr;
        }

        Iterator(AVLMap<Key, Value>* newMap)
        {
            this->mMap = newMap;
            this->mPoint = nullptr;
        }

        ~Iterator()
        {

        }

        void operator++()
        {
           this->findNext(this->mMap->mRoot);
        }
        AVLNode<Key, Value>* getPoint()
        {
            return this->mPoint;
        }
        void setPoint(AVLNode<Key, Value>* point)
        {
            this->mPoint = point;
        }


        private:
        AVLMap<Key, Value>* mMap;
        AVLNode<Key, Value>* mPoint;

        void findNext(AVLNode<Key, Value>* root)
        {
           AVLNode<Key, Value>* successor = root;
           AVLNode<Key, Value>* temp = root;
           while(temp != this->mPoint)
           {
                //traverse tree
                //move right if temp moves left, leave successor until tree moves right
                if(temp->getKey() < this->mPoint->getKey())
                {
                    temp = temp->getRight();
                }
                //move left
                else if(temp->getKey() > this->mPoint->getKey())
                {
                    successor = temp;
                    temp = temp->getLeft();
                }
           }
           //Current point has right children
           if(temp->getRight() != nullptr)
           {
            successor = temp->getRight();
            while(successor->getLeft() != nullptr)
            {
                successor = successor->getLeft();
            }
            this->setPoint(successor);
           }
           //Current point does not ahve right children
           else if(successor->getLeft() != nullptr && this->mPoint->getKey() < successor->getKey())
           {
            this->setPoint(successor);
           }
           else
           {
            this->setPoint(nullptr);
           }
        }
    };

public: 

    AVLMap();
    AVLMap(AVLMap<Key, Value> &newRoot); //Deep copy constructor
    ~AVLMap();

    AVLNode<Key, Value>* getRoot();

    void insert(const Key& key, const Value& value);
    void erase(const Key& key);
    Iterator find(const Key& key);
    bool empty();
    void printPreorder();
private:
    AVLNode<Key, Value>* mRoot;
    
    void insertHelper(AVLNode<Key, Value>** root, Key newKey,  Value newVal);
    void eraseHelper(AVLNode<Key, Value>** root, Key newKey);
    void deleteTreeHelper(AVLNode<Key, Value>* root);
    void rotate(AVLNode<Key, Value>** root);
    void printPreorderHelper(AVLNode<Key, Value>* root);
    AVLNode<Key, Value>* findHelper(AVLNode<Key, Value>* root, const Key& key);

};


template <class Key, class Value>
bool AVLMap<Key, Value>::empty()
{
    if(this->mRoot != nullptr)
    {
        return false;
    }
    else{
        return true;
    }
}

template <class Key, class Value>
AVLMap<Key, Value>::AVLMap()
{
    this->mRoot = nullptr;
}

template <class Key, class Value>
AVLMap<Key, Value>::AVLMap(AVLMap<Key, Value> &newMap)
{
    this->mRoot = newMap.mRoot;
}

template <class Key, class Value>
AVLMap<Key, Value>::~AVLMap()
{
    if(this->empty() != true)
    {
        this->deleteTreeHelper(this->mRoot);
    }
}

template <class Key, class Value>
void AVLMap<Key, Value>::deleteTreeHelper(AVLNode<Key, Value>* root)
{
    if(root->getLeft() != nullptr)
    {
        deleteTreeHelper(root->getLeft());
    }
    if(root->getRight() != nullptr)
    {
        deleteTreeHelper(root->getRight());
    }
    delete root;
}

template <class Key, class Value>
AVLNode<Key, Value>* AVLMap<Key, Value>::getRoot()
{
    return this->mRoot;
}

template <class Key, class Value>
void AVLMap<Key, Value>::insert(const Key& key, const Value& value)
{

    //Case 1: empty tree
    if(this->empty() == true)
    {
        this->mRoot = new AVLNode<Key, Value>(key, value, nullptr, nullptr, 0, 0);
    }
    else
    {
        insertHelper(&this->mRoot, key, value);
    }

}

template <class Key, class Value>
void AVLMap<Key, Value>::insertHelper(AVLNode<Key, Value>** root,  Key newKey,  Value newVal)
{
    if(newKey < (*root)->getKey()) //left
    {
        //root->setHeight(root->getHeight()+1);
        if((*root)->getLeft() == nullptr)
        {
            (*root)->setLeft(new AVLNode<Key, Value>(newKey, newVal, nullptr, nullptr, 0, 0));
        }
        else
        {
            AVLNode<Key, Value>* leftChild = (*root)->getLeft();
            insertHelper(&(leftChild), newKey, newVal);
            (*root)->setLeft(leftChild);
        }
        (*root)->setLHeight(std::max((*root)->getLeft()->getLHeight(), (*root)->getLeft()->getRHeight())+1);
    }
    if(newKey > (*root)->getKey()) //right
    {
        //root->setHeight(root->getHeight()+1);
        if((*root)->getRight() == nullptr)
        {
            (*root)->setRight(new AVLNode<Key, Value>(newKey, newVal, nullptr, nullptr, 0, 0));
        }
        else
        {
            AVLNode<Key, Value>* rightChild = (*root)->getRight();
            insertHelper(&(rightChild), newKey, newVal);
            (*root)->setRight(rightChild);
        }
        (*root)->setRHeight(std::max((*root)->getRight()->getLHeight(), (*root)->getRight()->getRHeight())+1);
    }
    rotate(root);
}

template <class Key, class Value>
void AVLMap<Key, Value>::erase(const Key& newKey)
{
    if(this->empty() == true)
    {
        return;
    }
    else if(this->mRoot->getKey() == newKey && this->mRoot->getLeft() == nullptr && this->mRoot->getRight() == nullptr)
    {
        delete this->mRoot;
    }
    else
    {
        eraseHelper(&this->mRoot, newKey);
    }
}

template <class Key, class Value>
void AVLMap<Key, Value>::eraseHelper(AVLNode<Key, Value>** root, Key newKey)
{
    //delete node
    if((*root)->getKey() == newKey || (*root)->getLeft()->getKey() == newKey || (*root)->getRight()->getKey() == newKey)
    {
        //Deletion direction
        AVLNode<Key, Value>* delNode;
        int delCase = 0;
        if((*root)->getKey() == newKey)
        {
            delNode = *root;
            delCase = 0;
        }
        else if((*root)->getLeft()->getKey() == newKey)
        {
            delNode = (*root)->getLeft();
            delCase = -1;
        }
        else if((*root)->getRight()->getKey() == newKey)
        {
            delNode = (*root)->getRight();
            delCase = 1;
        }

        //Deletion implementation
        //Case 1: Leaf node
        if(delNode->getLeft() == nullptr && delNode->getRight() == nullptr) 
        {
            if(delCase == -1)
            {
                (*root)->setLeft(nullptr);
            }
            else if(delCase == 1)
            {
                (*root)->setRight(nullptr);
            }
            delete delNode;
        }
        //Case 2: Left children only replace parent left with target left
        else if(delNode->getRight() == nullptr && delNode->getLeft() != nullptr)
        {   
            if(delCase == -1)
            {
                (*root)->setLeft(delNode->getLeft());
            }
            if(delCase == 1)
            {
                (*root)->setRight(delNode->getLeft());
            }
            if(delCase == 0)
            {
                (*root) = delNode->getLeft();
            }
            delNode->setLeft(nullptr);
            delete delNode;
        }
        //case 3: has right children only
        else if(delNode->getLeft() == nullptr & delNode->getRight() != nullptr)
        {
            if(delCase == -1)
            {
                (*root)->setLeft(delNode->getRight());
            }
            if(delCase == 1)
            {
                (*root)->setRight(delNode->getRight());
            }
            if(delCase == 0)
            {
                *root = delNode->getRight();
            }
            delNode->setRight(nullptr);
            delete delNode;
        }
        else //Has two children replace w successor
        {
            AVLNode<Key, Value>* tempNode = delNode->getRight();
            AVLNode<Key, Value>* postNode = tempNode->getLeft();
            if(postNode == nullptr)
            {
                postNode = tempNode;                
            }
            else
            {
                //traverse to successor
                while(postNode->getLeft() != nullptr)
                {
                    tempNode = postNode;
                    postNode = postNode->getLeft();
                }
                tempNode->setLeft(postNode->getRight());
                postNode->setRight(nullptr); 
            }    
            //Replacement node points right to target right node
            if(delNode->getRight() != postNode)
            {
                postNode->setRight(delNode->getRight());
                postNode->setRHeight(delNode->getRHeight());
            }
            postNode->setLeft(delNode->getLeft());
            if(delCase == -1)
            {
                (*root)->setLeft(postNode);
            }
            else if(delCase == 1)
            {
                (*root)->setRight(postNode); 
            }
            else if(delCase == 0)
            {
                *root = postNode;
            }
            delete delNode;    
        }
    }
    else
    {
        //move right
        if((*root)->getKey() < newKey)
        {
            AVLNode<Key, Value>* rightNode = (*root)->getRight();
            eraseHelper(&rightNode, newKey);
        }
        //move left
        else if((*root)->getKey() > newKey)
        {
            AVLNode<Key, Value>* leftNode = (*root)->getLeft();
            eraseHelper(&leftNode, newKey);
        }
    }
    //update heights
    if((*root)->getLeft() != nullptr)
    {
        (*root)->setLHeight(std::max((*root)->getLeft()->getLHeight(), (*root)->getLeft()->getRHeight())+1);
    }
    else
    {
        (*root)->setLHeight(0);
    }
    if((*root)->getRight() != nullptr)
    {
        (*root)->setRHeight(std::max((*root)->getRight()->getLHeight(), (*root)->getRight()->getRHeight())+1);
    }
    else
    {
        (*root)->setRHeight(0);
    }
    rotate(root);
}


template <class Key, class Value>
typename AVLMap<Key, Value>::Iterator AVLMap<Key, Value>::find(const Key& key)
{
    typename AVLMap<Key, Value>::Iterator returnIt(this);
    //Find key of root
    if(this->mRoot->getKey() != key)
    {
        returnIt.setPoint(this->findHelper(this->mRoot, key));
        if(returnIt.getPoint() == nullptr)
        {
            cout << "Item not found" << endl;
        }
    }
    return returnIt;
}

template <class Key, class Value>
AVLNode<Key, Value>* AVLMap<Key, Value>::findHelper(AVLNode<Key, Value>* root, const Key& key)
{
    if(key < root->getKey())
    {
        return this->findHelper(root->getLeft(), key);

    }
    if(key > root->getKey())
    {
        return this->findHelper(root->getRight(), key);        
    } 
    if(key == root->getKey())
    {
        return root;
    }
    else
    {
        return nullptr;
    }
}

template <class Key, class Value>
void AVLMap<Key, Value>::rotate(AVLNode<Key, Value>** root)
{

    //Rotate CCW
    if(((*root)->getRHeight() - (*root)->getLHeight()) > 1)
    {
        AVLNode<Key, Value>* tempNode = *root;
        *root = (*root)->getRight();
        tempNode->setRight((*root)->getLeft());
        (*root)->setLeft(tempNode);
        if((*root)->getLeft()->getRight() == nullptr)
        {
            (*root)->getLeft()->setRHeight(0);
        }
        else
        {
            (*root)->getLeft()->setRHeight(std::max((*root)->getLeft()->getRight()->getLHeight(), (*root)->getLeft()->getRight()->getRHeight())+1);
        }
        (*root)->setLHeight(std::max((*root)->getLeft()->getLHeight(), (*root)->getLeft()->getRHeight())+1);
    }
    //Rotate CW
    if(((*root)->getRHeight()-(*root)->getLHeight()) < -1)
    {
        AVLNode<Key, Value>* tempNode = *root;
        *root = (*root)->getLeft();
        tempNode->setLeft((*root)->getRight());
        (*root)->setRight(tempNode);
        if((*root)->getRight()->getLeft() == nullptr)
        {
            (*root)->getRight()->setLHeight(0);
        }
        else
        {
            (*root)->getRight()->setLHeight(std::max((*root)->getRight()->getLeft()->getLHeight(), (*root)->getRight()->getLeft()->getRHeight()+1));
        }
    }
    
}

template <class Key, class Value>
void AVLMap<Key, Value>::printPreorder()
{
    printPreorderHelper(this->mRoot);
}

template <class Key, class Value>
void AVLMap<Key, Value>::printPreorderHelper(AVLNode<Key, Value>* root)
{
    if(root != nullptr)
    {
        cout << root->getKey() << " ";
    }
    if(root->getLeft() != nullptr)
    {
        printPreorderHelper(root->getLeft());
    }
    if(root->getRight() != nullptr)
    {
        printPreorderHelper(root->getRight());
    }
}


#endif