#ifndef AVL_MAP_H
#define AVL_MAP_H
#include "avlNode.h"
#include <iostream>
#include <iterator>
#include <string>
#include <fstream>

template <class Key, class Value>
class AVLMap{

public: 

    AVLMap();
    AVLMap(AVLMap<Key, Value> &newRoot); //Deep copy constructor
    ~AVLMap();

    void insert(const Key& key, const Value& value);
    void erase(const Key& key);
    AVLNode<Key, Value> find(const Key& key);
    bool empty();
private:
    AVLNode<Key, Value>* mRoot;
    
    void insertHelper(AVLNode<Key, Value>* root, const Key& newKey, const Value& newVal);
    void deleteTreeHelper(AVLNode<Key, Value>* root);
    AVLNode<Key, Value> findHelper(AVLNode<Key, Value>* root, const Key& key);

};

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
void AVLMap<Key, Value>::insert(const Key& key, const Value& value)
{

    //Case 1: empty tree
    if(this->empty() == true)
    {
        this->mRoot = new AVLnode<Key, Value>(key, value);
    }
    insertHelper(this->mRoot, key, value);
}

template <class Key, class Value>
void AVLMap<Key, Value>::insertHelper(AVLNode<Key, Value>* root, const Key& newKey, const Value& newVal)
{
    if(newKey < root->getKey())
    {
        if(root->getLeft == nullptr)
        {
            root->setLeft(new AVLNode<Key, Value>(newKey, newVal));
        }
        else
        {
            insertHelper(root->getLeft(), newKey, newVal);
        }
    }
    if(newKey > root->getKey())
    {
        if(root->getRight() == nullptr)
        {
            root->setRight(new AVLNode<Key, Value>(newKey, newVal));
        }
        else
        {
        insertHelper(root->getRight(), newKey, newVal);
        }
    }
}

template <class Key, class Value>
AVLNode<Key, Value> AVLMap<Key, Value>::find(const Key& key)
{
    AVLNode<Key, Value> returnNode;
    //Find key of root
    if(this->mRoot->getKey() == key)
    {
        return this->mRoot;
    }
    else //Find key of other nodes
    {
        returnNode = this->findHelper(this->mRoot, key);
    }
    if(returnNode == nullptr)
    {
        cout << "Item not found" << endl;
    }
    return returnNode;
}

template <class Key, class Value>
AVLNode<Key, Value> AVLMap<Key, Value>::findHelper(AVLNode<Key, Value>* root, const Key& key)
{
    if(key == root->getKey())
    {
        return root;
    }
    if(key < root->getKey())
    {
        if(root->getLeft() != nullptr)
        {
            return this->findHelper(root->getLeft(), key);
        }
        else
        {
            return nullptr;
        }
    }
    if(key > root->getKey())
    {
        if(root->getRight() != nullptr)
        {
            return this->findHelper(root->getRight(), key);
        }
        else
        {
            return nullptr;
        }
    } 
}

#endif