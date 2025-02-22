#include <iostream>
#include "BST.h" 
/*Conceptual Questions*/

/*1. What is a move constructor?
	A move constructor is a class constructor that transfers the data from an existing
	object of the same type into a new object.
*/
/*2. What is a move assignment operator?
	A move assignment operator transfers the data from an existing object into
	another existing operator
*/
/*Worst case type complexity*/
/* 
BST::empty() O(1) Because regardless of the size and shape of the list,
	 it only takes oepration step to determine if the tree is empty or not.
*/
/*
BST::add() O(N) Because worst case scenario it will call addHelper()
	which if the objects are added in ascending or descending order, 
	will have a time complexity of O(N) because the BST would behave
	as a list, and it would have to traverse the tree N times to add
	the new node.
*/
/*
BST::makeEmpty() O(N) Because in the worst case scenario, makeEmpty() calls
	makeEmptyHelper() which must traverse each node once to delete the entire
	tree, so the function will use N operations to complete.
*/
/*
BST::printLevelOrder() O(N) because the two loops in the function traverse each
	node only once meaning it has a time complexity of O(N) + O(N) which can be
	simplified to a time complexity of O(N).
*/
/*
BST::cloneTree() O(N) because it must traverse and clone every node in the BST,
	so as the number of nodes N increase, it must complete N operations.
*/
int main(){

	/* MA TODO: Implement */
	/* Create a BST string tree (bst_test) ; add the following string values to the bst_test in order: "C", "p", "t", "s", "2", "3" , "B", "S", "T"*/
	BST<string> bst_test;
	bst_test.add("C");
	bst_test.add("p");
	bst_test.add("t");
	bst_test.add("s");
	bst_test.add("2");
	bst_test.add("3");
	bst_test.add("B");
	bst_test.add("S");
	bst_test.add("T");
	/* MA TODO: Implement */
	// Test1: Test printLevelOrder()
	/* Print the tree you created using
	    a. In-order print
	    a. Level-order print
	    a. Post-order print
	    a. Pre-order print */
	cout << "Testing printInOrder..." << endl;
	bst_test.printInOrder();
	cout << endl;
	cout << "Testing pritnLevelOrder..." << endl;
	bst_test.printLevelOrder();	
	cout << endl;
	cout << "Testing printPostOrder..." << endl;
	bst_test.printPostOrder();
	cout << endl;
	cout << "Testing printPreOrder..." << endl;
	bst_test.printPreOrder();
	cout << endl;
	/* MA TODO: Implement */
	// Test2: Test copy constructor -1
	/* Create a new BST tree (bst_copy1) ; initialize bst_copy1 with 'bst_test's data, using the copy constructor */
	/* Test condition: Check if the size of bst_copy1 is same as bst_test; and  bst_copy1 contains the values "B", "S", "T" 
	    * if so, print the mesaage: "Copy constructor test-1 passed!"";
		* else *print the message: "Copy constructor test-1 failed!"" and print both bst_test and bst_copy1 using level order print.*/

	BST<string> bst_copy1(bst_test);
	if((bst_copy1.size() == bst_test.size()) && (bst_copy1.contains("B")) && (bst_copy1.contains("S")) && (bst_copy1.contains("T")))
	{
		cout << "Copy constructor test-1 passed!" << endl;
	}
	else{
		cout << "Copy constructor test-1 failed!" << endl;
		bst_test.printLevelOrder();
		bst_copy1.printLevelOrder();
	}
	/* MA TODO: Implement */
	// Test3: Test copy constructor - 2
	/* Update one of the strings in bst_copy1 tree using the following statement:  */
	   // bst_copy1.getNode("B")->setValue("A");
	/* Assuming copy constructor does a deep copy, the above statement should update bst_copy1 only, and not bst_test. */
	/* Test condition: 
	    * if bst_test contains "B" and it doesn't contain "A", test passes. Print the message: "Copy constructor test-2 passed!"";
		* else *print the message: "Copy constructor test-2 failed!"" and print bst_test using level order print.*/
	bst_copy1.getNode("B")->setValue("A");
	if(bst_test.contains("B") && !bst_test.contains("A"))
	{
		cout << "Copy constructor test-2 passed!" << endl;
	}
	else{
		cout << "Copy constructor test-2 failed!" << endl;
		bst_copy1.printLevelOrder();
	}

	/* MA TODO: Implement */
	// Test4: Test copy assignment
	/* Create a new BST tree (bst_copy2) ; initialize bst_copy2 with 'bst_test's data, using the copy assignment operator. */
	/* Test condition: Check if the size of bst_copy2 is same as bst_test and  bst_copy2 contains the values "B", "S", "T" 
	    * if so, print the mesaage: "Copy assignment operator test passed!"";
		* else *print the message: "Copy assignment operator test failed!"" and print both bst_test and bst_copy2 using level order print.*/

	BST<string> bst_copy2;
	bst_copy2 = bst_test;
	if((bst_copy2.size() == bst_test.size()) && (bst_copy2.contains("B")) && (bst_copy2.contains("S")) && (bst_copy2.contains("T")))
	{
		cout << "Copy assignment operator passed!" << endl;
	}
	else{
		cout << "Copy assignment operator failed!" << endl;
		bst_test.printLevelOrder();
		bst_copy2.printLevelOrder();
	}
	/* MA TODO: Implement */
	// Test5: Test move constructor
	/* Create a new BST tree (bst_move1) ; initialize bst_move1 with 'bst_test's data, using the move constructor */
	/* Test condition: Check if the size of bst_move1 is 9 and  bst_move1 contains the values "B", "S", "T", and bst_test is empty (use the empty() function of BST to check if bst_test is empty.).  
	    * if so, print the mesaage: "Move constructor test passed!"";
		* else *print the message: "Move constructor test failed!"" and print bst_move1 using level order print.*/

	BST<string> bst_move1(std::move(bst_test));
	if((bst_move1.size() == 9) && (bst_move1.contains("B")) && (bst_move1.contains("S")) && (bst_move1.contains("T")) && bst_test.empty())
	{
		cout << "Move constructor test passed!" << endl;
	}
	else{
		cout << "Move constructor test failed!" << endl;
		bst_move1.printLevelOrder();
	}
	/* MA TODO: Implement */
	// Test6: Test move assignment 
	/* Create a new BST tree (bst_move2) ; initialize bst_move2 with rvalue BST<string>({"B","S","T"}), using the move assignment operator */
	/* Test condition: Check if the size of bst_move2 is 3 and  bst_move2 contains the values "B", "S", "T". 
	    * if so, print the mesaage: "Move assignment operator test passed!"";
		* else *print the message: "Move assignment operator test failed!"" and print  bst_move2  using level order print.*/
	BST<string> bst_move2;
	bst_move2 = BST<string>({"B","S","T"});
	if(bst_move2.size() ==3 && bst_move2.contains("B") && bst_move2.contains("S") && bst_move2.contains("T"))
	{
		cout << "Move assignment passed!" << endl;
	}
	else{
		cout << "Move assignment failed!" << endl;
		bst_move2.printLevelOrder();
	}

	return 0;
}