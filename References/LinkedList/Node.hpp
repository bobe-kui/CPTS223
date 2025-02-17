#ifndef NODE_HPP
#define NODE_HPP

template <class T>
class Node
{
    public:
        Node();
        Node(T data);
        ~Node();

        T getData() const;
        Node<T>* getNext() const;

        void setData(T newData);
        void setNextPtr(Node<T>* newNext);
        
        friend ostream &operator<<(ostream &os, const Node<T> &node)
        {
            os << node.m_data;
            return os;
        }
        
    private:
        T m_data;
        Node<T>* mP_next;
};

template <class T>
Node<T>::Node()
{
    this->mP_next = nullptr;
}

template <class T>
Node<T>::Node(T data)
{
    this->m_data = data;
    this->mP_next = nullptr;
}

template <class T>
Node<T>::~Node()
{
    if (mP_next != nullptr)
    {
        mP_next = nullptr;
    }
    
}

template <class T>
T Node<T>::getData() const{
    return this->m_data;
}

template <class T>
Node<T>* Node<T>::getNext() const{
    return this->mP_next;
}

template <class T>
void Node<T>::setData(T newData){
    this.m_data = newData;
}

template <class T>
void Node<T>::setNextPtr(Node<T>* newNext)
{
    this->mP_next = newNext;
}


#endif