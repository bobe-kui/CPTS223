#ifndef AVLNODE_H
#define AVLNODE_H

template <class Key, class Value>
class AVLNode{

public:
    AVLNode();
    AVLNode(Key newKey, Value newValue, AVLNode<Key, Value>* &newLeft, AVLNode<Key, Value>* &newRight, int newLeftBalance, int newRightBalance);
    ~AVLNode();

    void setKey(Key newKey);
    void setValue(Value newValue);
    void setLeft(AVLNode<Key,Value>* newLeft);
    void setRight(AVLNode<Key, Value>* newRight);
    void setLeftBal(int newLeftBal);
    void setRightBal(int newRightBal);

    Key getKey() const;
    Value getValue() const;
    AVLNode<Key, Value>* getLeft() const;
    AVLNode<Key, Value>* getRight() const;
    int getLeftBal() const;
    int getRightBal() const;

private:
    Key mKey;
    Value mValue;
    AVLNode<Key, Value>* mLeft;
    AVLNode<Key, Value>* mRight;
    int mLBal;
    int mRBal;

};

template <class Key, class Value>
AVLNode<Key, Value>::AVLNode()
{
    this->mLeft = nullptr;
    this->mRight = nullptr;
    this->mLBal = 0;
    this->mRBal = 0;
}

template <class Key, class Value>
AVLNode<Key, Value>::AVLNode(Key newKey, Value newValue, AVLNode<Key, Value>* &newLeft, AVLNode<Key, Value>* &newRight, int newLeftBalance, int newRightBalance)
{
    this->mKey = newKey;
    this->mValue = newValue;
    this->mLeft = newLeft;
    this->mRight = newRight;
    this->mLBal = newLeftBalance;
    this->mRBal = newRightBalance;
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
void AVLNode<Key, Value>::setLeftBal(int newLeftBal)
{
    this->mLBal = newLeftBal;
}

template <class Key, class Value>
void AVLNode<Key, Value>::setRightBal(int newRightBal)
{
    this->mRBal = newRightBal;
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
int AVLNode<Key, Value>::getLeftBal() const
{
    return this->mLBal;
}

template <class Key, class Value>
int AVLNode<Key, Value>::getRightBal() const
{
    return this->mRBal;
}
#endif