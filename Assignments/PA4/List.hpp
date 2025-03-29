#include <iostream>
#include "Node.hpp"

template <typename T>
class List
{   
    public: 
        List();
        List(Node<T>* newHead);
        ~List();

        Node<T>* getHead() const;
        void setHead(Node<T>* newHead);

        bool isEmpty();
        void printList();

        void insertFront(T newData, string newKey);

    private:
        Node<T>* mHead;
};

template <typename T>
List<T>::List()
{
    this->mHead = nullptr;
}

template <typename T>
List<T>::List(Node<T>* newHead)
{
    this->mHead = newHead;
}

template <typename T>
List<T>::~List()
{

}

template <typename T>
Node<T>* List<T>::getHead() const
{
    return this->mHead;
}

template <typename T>
void List<T>::setHead(Node<T>* newHead)
{
    this->mHead = newHead;
}

template <typename T>
bool List<T>::isEmpty()
{
    if(this->mHead != nullptr)
    {
        return false;
    }
    return true;
}

template <typename T>
void List<T>::printList()
{
    List<T> tempList(this->getHead());
    Node<T>* printNode = tempList.getHead();
    while(printNode != nullptr)
    {
        cout << printNode->getData() << endl;
        printNode = printNode->getNext();
    }
}

template <typename T>
void List<T>::insertFront(T newData, string newKey)
{
    Node<T>* newNode = new Node<T>(newData, newKey);
    if(this->getHead() == nullptr)
    {
        this->setHead(newNode);
    }
    else
    {
        newNode->setNext(this->getHead());
        this->setHead(newNode);
    }
}