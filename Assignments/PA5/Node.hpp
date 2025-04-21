#include <iostream>
#include <string>
using namespace std;

template <typename T>
class Node
{

    public:
        Node();
        Node(T newData, string newKey); //Constructor
        Node(Node<T>& copy);
        ~Node();

        T getData() const;
        Node<T>* getNext() const;
        string getKey() const;

        void setData(T newData);
        void setNext(Node<T>* newNext);
        void setKey(string newKey);

        Node<T>* operator=(Node<T>* rhs)
        {
            this->mData = rhs->getData();
            this->mKey = rhs->getKey();
            this->setNext(rhs->getNext());
        }

        

    private:
        T mData;
        Node<T>* mNext;
        string mKey;
};

template<typename T>
Node<T>::Node()
{
    this->mNext = nullptr;
}

template <typename T>
Node<T>::Node(T newData, string newKey)
{
    this->mData = newData;
    this->mNext = nullptr;
    this->mKey = newKey;
}

template <typename T>
Node<T>::~Node()
{
    this->mNext = nullptr;
}

template <typename T>
Node<T>::Node(Node<T>& copy)
{
    this->mData = copy.mData;
    this->mKey = copy.mKey;
    this->mNext = nullptr;
}

template <typename T>
T Node<T>::getData() const
{
    return this->mData;
}

template <typename T>
Node<T>* Node<T>::getNext() const{
    return this->mNext;
}

template <typename T>
string Node<T>::getKey() const
{
    return this->mKey;
}

template <typename T>
void Node<T>::setData(T newData)
{
    this->mData = newData;
}

template <typename T>
void Node<T>::setNext(Node<T>* newNext)
{
    this->mNext = newNext;
}

template <typename T>
void Node<T>::setKey(string newKey)
{
    this->mKey = newKey;
}