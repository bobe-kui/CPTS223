#include <iostream>
#include <string>
#include <hashtable.h>
#include "List.hpp"
using namespace std;

template <typename T>
class HashTable
{
public:
    HashTable(); // Constructor
    ~HashTable(); // Destructor

    bool isEmpty() const;
    int hashFunction(const string& key) const;
    void insertItem(string key, const T& value);
    //void insertItemSeparate(string key, const T& value);
    void removeItem(const string& value);
    T searchItem(const string& key) const;
    List<T> searchBucket(const string& key) const;
    void printTable();

private:
    static const int mSize =  (5*10e3) + 9 ; // Size of the hash table
    List<T> table[mSize]; // Array of linked lists for chaining
};

template <typename T>
HashTable<T>::HashTable() {

}

template <typename T>
HashTable<T>::~HashTable() {

}

template <typename T>
bool HashTable<T>::isEmpty() const {
    for (int i = 0; i < mSize; i++) {
        if (this->table[i].getHead()) {
            return false;
        }
    }
    return true;
}

template <typename T>
int HashTable<T>::hashFunction(const string& key) const {
    int sum=0;
    for(char c : key)
    {
        sum += static_cast<int>(c);
    }
    return sum % mSize; // Simple modulo-based hash function
}

template <typename T>
void HashTable<T>::insertItem(string key, const T& value) {
    int index = hashFunction(key);    
    table[index].insertFront(value, key);

}


template <typename T>
T HashTable<T>::searchItem(const string& key) const {
    int index = hashFunction(key);
    Node<T>* current = table[index].getHead();
    Item newItem;
    while (current != nullptr) {
        if (current->getKey() == key) {
            newItem =  current->getData();
        }
        current = current->getNext();
    }
    return newItem;
}

template <typename T>
List<T> HashTable<T>::searchBucket(const string& key) const
{
    int index = hashFunction(key);
    return this->table[index];   
}


template <typename T>
void HashTable<T>::printTable() {
    for (int i = 0; i < mSize; i++) {
        cout << "Index: " << i << ":" << endl;
        this->table[i].printList();
    }
}