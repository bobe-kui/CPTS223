#ifndef LIST_HPP
#define LIST_HPP
#include "Node.hpp"

template <class T>
class List
{
    public:

        List();
        List(Node<T>* newHead);
        ~List();

        Node<T>* getHead() const;
        void setHead(Node<T>* newHead);

        void insertFront(T newData);
        void insertBack(T newData);
        void removeNode(T data);
        int listLength(Node<T>* pHead, int &length);

        friend ostream &operator<<(ostream &os, const List<T> &list)
        {
            Node<T>* p_Current = list.getHead();
            if (p_Current == nullptr)
            {
                os << "List is empty" << endl;
            }
            else
            {
                while(p_Current != nullptr)
                {
                    os << *p_Current;
                    p_Current = p_Current->getNext();
                }
            }
            return os;
        }


    private:
        Node<T>* mP_Head;
        void destroyList(Node<T>* const p_Mem);

};

template <class T>
List<T>::List()
{
    mP_Head = nullptr;
}

template <class T>
List<T>::List(Node<T>* newHead)
{
    this->mP_head = newHead;
}

template <class T>
List<T>::~List()
{
    destroyList(mP_Head);
}

template <class T>
void List<T>::destroyList(Node<T>* p_Mem)
{
    if(p_Mem != nullptr)
    {
        destroyList(p_Mem->getNext());
        delete p_Mem;
    }
    
}

template <class T> 
Node<T>* List<T>::getHead() const
{
    return this->mP_Head;
}

template <class T>
void List<T>::setHead(Node<T>* newHead)
{
    this->mP_Head = newHead;
}

template <class T>
void List<T>::insertFront(T newData)
{
    Node<T>* p_New = new Node<T>(newData);
    Node<T>* p_temp = this->mP_Head;

    if(p_New != nullptr)
    {
        if (p_temp == nullptr)
        {
            this->setHead(p_New);
        }
        else{
            p_New->setNextPtr(p_temp);
            this->setHead(p_New);   
        }
    }
}

template <class T>
void List<T>::insertBack(T newData)
{
    Node<T>* p_Current = nullptr;
    Node<T>* p_New = new Node<T>(newData);
    p_Current = this->mP_Head;

    if(p_Current == nullptr)
    {
        this->setHead(p_New);
    }
    while(p_Current->getNext() != nullptr)
    {
        p_Current = p_Current->getNext();
    }
    p_Current->setNextPtr(p_New);
}

template <class T>
void List<T>::removeNode(T data)
{
    Node<T>* pCurrent = nullptr;
    Node<T>* pTemp = nullptr;
    pTemp = this->getHead();
    pCurrent = pTemp->getNext();

    //Case 1: First command is a match
    if(pTemp->getData() == data)
    {
        this->setHead(pTemp->getNext());
        return;
    }
    else
    {
        while(pCurrent != nullptr)
        {
            if(pCurrent->getData() == data)
            {
                break;
            }
            pTemp = pTemp->getNext();
            pCurrent = pCurrent->getNext();
        }
    //Case 2: Command is in the middle of the list
        if(pCurrent->getNext() != nullptr)
        {
            pTemp->setNextPtr(pCurrent->getNext());
        }
    //Case 3: Command is the last int the list
        else
        {
            pTemp->setNextPtr(nullptr);
        }
        pCurrent = nullptr;
    }


}

template <class T>
int List<T>::listLength(Node<T>* pHead, int &length)
{
    if(pHead != nullptr)
    {
        listLength(pHead->getNext(), length);
        length ++;
    }
    return length;
}
#endif
