#include "BST.hpp"

int main(void)
{

    BST<int> testTree;
    testTree.insertNode(10, testTree.getRoot());
    testTree.insertNode(3, testTree.getRoot());
    testTree.insertNode(14, testTree.getRoot());
    testTree.insertNode(5,testTree.getRoot());



    return 0;
}