#ifndef BST_HPP
#define BST_HPP
#include "BSTNode.hpp"

template <class T>
class BST
{
    public:
        BST();
        BST(T newData);
        ~BST();
    
    void destroyTree(Node<T>* head);
    void setRoot(Node<T>* newRoot);
    Node<T>* getRoot() const;
    int calculateHeight(Node<T>* head);

    bool insertNode(T newData, Node<T>* root);

    private:
        Node<T>* mP_root;

};

template <class T>
BST<T>::BST(){
    this->mP_root = nullptr;
}

template <class T>
BST<T>::BST(T newData){
    this->mP_root = new Node(newData);
}

template <class T>
BST<T>::~BST(){
    this->destroyTree(this->mP_root);
}

template <class T>
void BST<T>::destroyTree(Node<T>* head)
{
    if(head->getLeft() != nullptr)
    {
        destroyTree(head->getLeft);
    }
    if(head->getRight() != nullptr)
    {
        destroyTree(head->getRight);
    }
    else
    {
        delete head;
    }
}

template <class T>
void BST<T>::setRoot(Node<T>* newRoot)
{
    this->mP_root = newRoot;
}

template <class T>
Node<T>* BST<T>::getRoot() const
{
    return this->mP_root;
}

template <class T>
bool BST<T>::insertNode(T newData, Node<T>* root)
{
    if(root == nullptr)
    {
        root = new Node<T>(newData);
    }
    if(newData < root.getData())
    {
        if(root->getLeft() == nullptr)
        {
            root->setLeft(new Node<T>(newData));
        }
        else
        {
            insertNode(newData, root->getLeft());
        }
    }
    if(newData > root->getData())
    {
        if(root->getRight() == nullptr)
        {
            root->setRight(new Node<T>(newData));
        }
        else
        {
            insertNode(newData, root->getRight());
        }
    }
    else
    {
        cout << "Error inserting data" <<
        return false;
    }
    return true;
}

template <class T>
int BST<T>::calculateHeight(Node<T>* root)
{
    int leftHeight = 0;
    int rightHeight = 0;
    if(root == nullptr)
    {
        return -1;
    }
    if(root->getLeft() != nullptr)
    {
        leftHeight = (root->getLeft());
    }
    if(root->getRight() != nullptr)
    {
        calculateHeight(root->getRight());
    }
    if(leftHeight >= rightHeight)
    {
        return leftHeight + 1;
    }
    else
    {
        return rightHeight + 1;
    }

}
#endif