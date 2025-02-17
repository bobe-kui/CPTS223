#ifndef NODE_HPP
#define NODE_HPP

template <class T>
class Node
{
    public:
        Node();
        Node(T data);
        ~Node();

        void destroyNode(Node<T>* head);

        T getData() const;
        Node<T>* getLeft() const;
        Node<T>* getRight () const;

        void setData(T newData);
        void setLeft(Node<T>* newLeft);
        void setRight(Node<T>* newRight);
        
        friend ostream &operator<<(ostream &os, const Node<T> &node)
        {
            os << node.m_data;
            return os;
        }
        
    private:
        T m_data;
        Node<T>* mP_left;
        Node<T>* mP_right;
};

template <class T>
Node<T>::Node()
{
    this->mP_left = nullptr;
    this->mP_right = nullptr;
}

template <class T>
Node<T>::Node(T data)
{
    this->m_data = data;
    this->mP_left = nullptr;
    this->mP_right = nullptr;
}

template <class T>
Node<T>::~Node()
{   
    if(this->mP_left != nullptr)
    {
        mP_left = nullptr;
    }
    if(this->mP_right != nullptr)
    {
        mP_right = nullptr;
    }
}

template <class T>
void Node<T>::destroyNode(Node<T>* head)
{

}

template <class T>
T Node<T>::getData() const{
    return this->m_data;
}

template <class T>
Node<T>* Node<T>::getLeft() const{
    return this->getLeft;
}

template <class T>
Node<T>* Node<T>::getRight() const{
    return this->getRight;
}

template <class T>
void Node<T>::setData(T newData){
    this.m_data = newData;
}

template <class T>
void Node<T>::setLeft(Node<T>* newLeft)
{
    this->mP_left = newLeft;
}

template <class T>
void Node<T>::setRight(Node<T>* newRight)
{
    this->mP_right = newRight;
}


#endif
