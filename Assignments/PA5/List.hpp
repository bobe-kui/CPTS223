#include <iostream>
#include "Node.hpp"

template <typename T>
class List
{   
    public: 
        List();
        List(Node<T>* newHead); // Copy Constructor
        List(const List<T>& copy);
        ~List();

        Node<T>* getHead() const;
        void setHead(Node<T>* newHead);

        bool isEmpty();
        void printList();

        void insertFront(T newData, string newKey);
        void insertBack(T newData, string newKey);

        vector<pair<T, string>> listToVector();
        List<T> vectorToList( vector<pair<T, string>> sortTable);

        List<T> insertionSort();
        List<T> insertionSortDesc();
        List<T> mergeSort();
        List<T> mergeSortDesc();
        vector<pair<T, string>> mergeHelper(vector<pair<T, string>> table);
        vector<pair<T, string>> mergeHelperDesc(vector<pair<T, string>> table);


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
List<T>::List(const List<T>& copy)
{
    this->setHead(nullptr);
    if(copy.getHead() != nullptr)
    {
        Node<T>* currNode = copy.getHead();
        while(currNode != nullptr)
        {
            this->insertBack(currNode->getData(), currNode->getKey());
            currNode = currNode->getNext();
        }
    }
    else
    {
        this->setHead(nullptr);
    }
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

template <typename T>
void List<T>::insertBack(T newData, string newKey)
{
    Node<T>* newNode = new Node<T>(newData, newKey);
    Node<T>* tempNode;
    if(this->getHead() == nullptr)
    {
        this->setHead(newNode);
    }
    else
    {
        tempNode = this->getHead();
        while(tempNode->getNext() != nullptr)
        {
            tempNode = tempNode->getNext();
        }
        tempNode->setNext(newNode);
    }
}

template <typename T> 
vector<pair<T, string>> List<T>::listToVector()
{
    vector<pair<T, string>> sortTable;
    Node<T>* currNode = this->getHead();
    while(currNode != nullptr)
    {
        sortTable.push_back(make_pair(currNode->getData(), currNode->getKey()));
        currNode = currNode->getNext();
    }
    return sortTable;
}

template <typename T>
List<T> List<T>:: vectorToList(vector<pair<T, string>> sortTable)
{
    List<T> newList;
    for(int k = sortTable.size() - 1; k >= 0; k--)
    {
        newList.insertFront(sortTable[k].first, sortTable[k].second);
    }
    return newList;
}

template <typename T>
List<T> List<T>::insertionSort()
{
    vector<pair<T, string>> sortTable;
    pair<T, string> tempData;
    unsigned int i, j;
    //create array

    sortTable = this->listToVector();
    for(i = 1; i < sortTable.size(); i++)
    {
        j = i;
        while(j > 0 && sortTable[j].first.getPrice() < sortTable[j-1].first.getPrice())
        {
                tempData = sortTable[j-1];
                sortTable[j-1] = tempData;
                sortTable[j-1] = sortTable[j];
                sortTable[j] = tempData;
                j--;
        }
    }
    return vectorToList(sortTable);
}

template <typename T>
List<T> List<T>::insertionSortDesc()
{
    vector<pair<T, string>> sortTable;
    pair<T, string> tempData;
    unsigned int i, j;
    //create array
    sortTable = this->listToVector();
    for(i = 1; i < sortTable.size(); i++)
    {
        j = i;
        while(j > 0 && sortTable[j].first.getPrice() > sortTable[j-1].first.getPrice())
        {
                tempData = sortTable[j-1];
                sortTable[j-1] = tempData;
                sortTable[j-1] = sortTable[j];
                sortTable[j] = tempData;
                j--;
        }
    }
    return vectorToList(sortTable);
}

template <typename T>
List<T> List<T>::mergeSort()
{
    vector<pair<T, string>> sortTable;
    sortTable = this->listToVector();
    sortTable = mergeHelper(sortTable);
    return vectorToList(sortTable);
}

template <typename T>
List<T> List<T>::mergeSortDesc()
{
    vector<pair<T, string>> sortTable;
    sortTable = this->listToVector();
    sortTable = mergeHelperDesc(sortTable);
    return vectorToList(sortTable);
}


template <typename T>
vector<pair<T, string>> List<T>::mergeHelper(vector<pair<T, string>> table)
{
    if(table.size() == 1)
    {
        return table;
    }
    else //split tables
    {
        vector<pair<T, string>> sortTable;
        unsigned int mid = table.size()/2;
        vector<pair<T, string>> t1(table.begin(), table.begin() + mid);
        vector<pair<T, string>> t2(table.begin()+mid, table.end());
        t1 = mergeHelper(t1);
        t2 = mergeHelper(t2);
        
        while(!t1.empty()|| !t2.empty())
        {
            if(t2.empty() && !t1.empty())
            {
                sortTable.push_back(t1[0]);
                t1.erase(t1.begin());
            }
            else if(t1.empty() && !t2.empty())
            {
                sortTable.push_back(t2[0]);
                t2.erase(t2.begin());
            }
            else if (t1[0].first.getPrice() < t2[0].first.getPrice())
            {
                sortTable.push_back(t1[0]);
                t1.erase(t1.begin());
            }
            else if( t1[0].first.getPrice() > t2[0].first.getPrice())
            {
                sortTable.push_back(t2[0]);
                t2.erase(t2.begin());
            }
            else
            {
                break;
            }
        }
        return sortTable;
    }

}

template <typename T>
vector<pair<T, string>> List<T>::mergeHelperDesc(vector<pair<T, string>> table)
{
    if(table.size() == 1)
    {
        return table;
    }
    else //split tables
    {
        vector<pair<T, string>> sortTable;
        unsigned int mid = table.size()/2;
        vector<pair<T, string>> t1(table.begin(), table.begin() + mid);
        vector<pair<T, string>> t2(table.begin()+mid, table.end());
        t1 = mergeHelperDesc(t1);
        t2 = mergeHelperDesc(t2);
        
        while(!t1.empty()|| !t2.empty())
        {
            if(t2.empty() && !t1.empty())
            {
                sortTable.push_back(t1[0]);
                t1.erase(t1.begin());
            }
            else if(t1.empty() && !t2.empty())
            {
                sortTable.push_back(t2[0]);
                t2.erase(t2.begin());
            }
            else if (t1[0].first.getPrice() > t2[0].first.getPrice())
            {
                sortTable.push_back(t1[0]);
                t1.erase(t1.begin());
            }
            else if( t1[0].first.getPrice() < t2[0].first.getPrice())
            {
                sortTable.push_back(t2[0]);
                t2.erase(t2.begin());
            }
            else
            {
                break;
            }
        }
        return sortTable;
    }

}