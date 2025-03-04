#ifndef AVLNODE_H
#define AVLNODE_H


template <class Key, class Value>
class AVLNode{

public:
    AVLNode();
    AVLNode(AVLNode<Key, Value> &node);//copy constructor
    AVLNode(AVLNode<Key, Value> &&node);//move constructor
    AVLNode(Key newKey, Value newValue, AVLNode<Key, Value>* newLeft, AVLNode<Key, Value>* newRight, int newLHeight, int newRHeight);
    ~AVLNode();

    void setKey(Key newKey);
    void setValue(Value newValue);
    void setLeft(AVLNode<Key,Value>* newLeft);
    void setRight(AVLNode<Key, Value>* newRight);
    void setLHeight(int newLHeight);
    void setRHeight(int newRHeight);

    Key getKey() const;
    Value getValue() const;
    AVLNode<Key, Value>* getLeft() const;
    AVLNode<Key, Value>* getRight() const;
    int getLHeight() const;
    int getRHeight() const;

    AVLNode& operator=(AVLNode& other) //copy operator
    {
        this->mKey = other.mKey;
        this->mValue = other.mValue;
        this->mLeft = other.mLeft;
        this->mRight = other.mRight;
        this->mLHeight = other.mLHeight;
        this->mRHeight = other.mRHeight;
        return *this;
    }

private:
    Key mKey;
    Value mValue;
    AVLNode<Key, Value>* mLeft;
    AVLNode<Key, Value>* mRight;
    int mLHeight;
    int mRHeight;
};

template <class Key, class Value>
AVLNode<Key, Value>::AVLNode()
{
    this->mLeft = nullptr;
    this->mRight = nullptr;
    this->mHeight = 0;
}

template <class Key, class Value>
AVLNode<Key, Value>::AVLNode(AVLNode<Key, Value> &node)
{
    this->mKey = node.mKey;
    this->mValue = node.mValue;
    this->mLeft = node.mLeft;
    this->mRight = node.mRight;
    this->mLHeight = node.mLHeight;
    this->mRHeight = node.mRHeight;
}

template <class Key, class Value>
AVLNode<Key, Value>::AVLNode(AVLNode<Key, Value> &&node)
{
    this = node;
    delete node;
}

template <class Key, class Value>
AVLNode<Key, Value>::AVLNode(Key newKey, Value newValue, AVLNode<Key, Value>* newLeft, AVLNode<Key, Value>* newRight, int newLHeight, int newRHeight)
{
    this->mKey = newKey;
    this->mValue = newValue;
    this->mLeft = newLeft;
    this->mRight = newRight;
    this->mLHeight = newLHeight;
    this->mRHeight = newRHeight;
}

template <class Key, class Value>
AVLNode<Key, Value>::~AVLNode()
{
    this->mLeft = nullptr;
    this->mRight = nullptr;
}

template <class Key, class Value>
void AVLNode<Key, Value>::setKey(Key newKey)
{
    this->mKey = newKey;
}

template <class Key, class Value>
void AVLNode<Key, Value>::setValue(Value newValue)
{
    this->mValue = newValue;
}

template <class Key, class Value>
void AVLNode<Key, Value>::setLeft(AVLNode<Key, Value>* newLeft)
{
    this->mLeft = newLeft;
}

template <class Key, class Value>
void AVLNode<Key, Value>::setRight(AVLNode<Key, Value>* newRight)
{
    this->mRight = newRight;
}

template <class Key, class Value>
void AVLNode<Key, Value>::setLHeight(int newLHeight)
{
    this->mLHeight = newLHeight;
}

template <class Key, class Value>
void AVLNode<Key, Value>::setRHeight(int newRHeight)
{
    this->mRHeight = newRHeight;
}

template <class Key, class Value>
Key AVLNode<Key, Value>::getKey() const
{
    return this->mKey;
}

template <class Key, class Value>
Value AVLNode<Key, Value>::getValue() const
{
    return this->mValue;
}

template <class Key, class Value>
AVLNode<Key, Value>* AVLNode<Key, Value>::getLeft() const
{
    return this->mLeft;
}

template <class Key, class Value>
AVLNode<Key, Value>* AVLNode<Key, Value>::getRight() const
{
    return this->mRight;
}

template <class Key, class Value>
int AVLNode<Key, Value>::getLHeight() const
{
    return this->mLHeight;
}

template <class Key, class Value>
int AVLNode<Key, Value>::getRHeight() const
{
    return this->mRHeight;
}

#endif