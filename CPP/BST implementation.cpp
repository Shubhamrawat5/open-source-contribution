#include<stdio.h>
#include<iostream>
using namespace std;

struct Node {
	int data;
	Node* leftChild;
	Node* rightChild;

	Node() {
		this->data = INT_MIN;
		this->leftChild = NULL;
		this->rightChild = NULL;
	}
};

Node* CreateNewNode(int value) {

	Node* newNode = new Node();

	newNode->data = value;
	newNode->leftChild = NULL;
	newNode->rightChild = NULL;

	return newNode;
}

Node* FindMinimumValuedNode(Node* rootNode) {

	if (rootNode == NULL)
		return NULL;
	else if (rootNode->leftChild != NULL)
		return FindMinimumValuedNode(rootNode->leftChild);

	return rootNode;
}

Node* Search(Node* currentNode, int item) {

	if (currentNode == NULL || currentNode->data == item) {
		return currentNode;
	}
	else if (item > currentNode->data) {
		Search(currentNode->rightChild, item);
	}
	else {
		Search(currentNode->leftChild, item);
	}

}

Node* Inseart(Node* rootNode, int item) {
	if (rootNode != NULL && rootNode->data == INT_MIN && rootNode->leftChild == NULL && rootNode->rightChild == NULL) {
		rootNode->data = item;
		return rootNode;
	}

	if (rootNode == NULL)
		return CreateNewNode(item);
	else if (item > rootNode->data) {
		rootNode->rightChild = Inseart(rootNode->rightChild, item);
	}
	else {
		rootNode->leftChild = Inseart(rootNode->leftChild, item);
	}
	
	return rootNode;
}

Node* Delete(Node* rootNode, int item) {
	if (rootNode == NULL)
		return NULL;

	if (rootNode->data == INT_MIN && rootNode->leftChild == NULL && rootNode->rightChild == NULL) {
		return NULL;
	}

	// Step 1: Searching for the item to be deleted
	
	if (item > rootNode->data)
		rootNode->rightChild = Delete(rootNode->rightChild, item);
	else if (item < rootNode->data)
		rootNode->leftChild = Delete(rootNode->leftChild, item);
	else {
		// Step 2-1: No-Child 
		if (rootNode->leftChild == NULL && rootNode->rightChild == NULL) {
			free(rootNode);
			return NULL;
		}

		// Step 2-2: One-Child
		if (rootNode->leftChild == NULL || rootNode->rightChild == NULL) {
			Node* tempNode;

			if (rootNode->leftChild == NULL)
				tempNode = rootNode->rightChild;
			else
				tempNode = rootNode->leftChild;

			free(rootNode);

			return tempNode;
		}

		// Step 2-3: Two-Child
		else {
			Node* minimumValuedNode = FindMinimumValuedNode(rootNode->rightChild);

			rootNode->data = minimumValuedNode->data;
			rootNode->rightChild = Delete(rootNode->rightChild, minimumValuedNode->data);
		}
	}

	return rootNode;

}

void PreOrder(Node* rootNode) {
	if (rootNode == NULL)
		return;

	if (rootNode->data == INT_MIN && rootNode->leftChild == NULL && rootNode->rightChild == NULL) {
		return;
	}

	cout << rootNode->data << " ";

	PreOrder(rootNode->leftChild);
	PreOrder(rootNode->rightChild);
}

void InOrder(Node* rootNode) {
	if (rootNode == NULL)
		return;

	if ( rootNode->data == INT_MIN && rootNode->leftChild == NULL && rootNode->rightChild == NULL) {
		return;
	}

	InOrder(rootNode->leftChild);

	cout << rootNode->data << " ";

	InOrder(rootNode->rightChild);
}

void PostOrder(Node* rootNode) {
	if (rootNode == NULL)
		return;

	if (rootNode->data == INT_MIN && rootNode->leftChild == NULL && rootNode->rightChild == NULL) {
		return;
	}

	PostOrder(rootNode->leftChild);

	PostOrder(rootNode->rightChild);

	cout << rootNode->data << " ";
}

void displayChooseOptions() {

	cout << "\n*****MAIN MENU *****" << endl;
	cout << "1. Insert" << endl;
	cout << "2. Delete" << endl;
	cout << "3. Search" << endl;
	cout << "4. Preorder Traversal" << endl;
	cout << "5. Inorder Traversal" << endl;
	cout << "6. Postorder Traversal" << endl;
	cout << "7. Exit";

	cout << "\nEnter your option: ";
}

void chooseOption(Node* rootNode) {
	char choice;
	do {
		displayChooseOptions();
		cin >> choice;

		int item = INT_MIN;
		Node* deletedNode = new Node();
		Node* foundItemNode = new Node();
		Node* insertedNode = new Node();

		switch (choice)
		{
		case '1':
			cout << "\n\n--- Insert item into the BST ---" << endl;
			
			cout << "Enter value for insertion : ";
			cin >> item;
			insertedNode  = Inseart(rootNode, item);
			if(insertedNode != NULL)
				cout << "Inserting item successfully done." << endl << endl;
			else
				cout << "Inserting item failed." << endl << endl;
			break;
		case '2':
			cout << "\n\n--- Delete item from the BST ---" << endl;
			//int item;
			cout << "Enter value for deletion : ";
			cin >> item;
			deletedNode = Delete(rootNode, item);
			if (deletedNode != NULL)
				cout << "Deletion item(" << item << ") successfully done" << endl;
			else
				cout << "Deletion item failed. Because, No item found with this value!" << endl << endl;
			break;
		case '3':
			cout << "\n\n--- Search item from the BST ---" << endl;
			cout << "Enter value for searching : ";
			cin >> item;
			foundItemNode = Search(rootNode, item);
			if (foundItemNode != NULL)
				cout << "Item(" << item << ") successfully found." << endl;
			else
				cout << "Searching item failed. Because, No item found with this value!" << endl << endl;
			break;
		case '4':
			cout << "\n\n--- Preorder Traversal ---" << endl;
			if (rootNode->data == INT_MIN)
				cout << "Empty!" << endl;
			PreOrder(rootNode);
			break;
		case '5':
			cout << "\n\n--- Inorder Traversal ---" << endl;
			if (rootNode->data == INT_MIN)
				cout << "Empty!" << endl;
			InOrder(rootNode);
			break;
		case '6':
			cout << "\n\n--- Postorder Traversal ---" << endl;
			if (rootNode->data == INT_MIN)
				cout << "Empty!" << endl;
			PostOrder(rootNode);
			break;
		case '7':
			cout << "\nTHANKS FOR USING THIS CONSOLE APPLICATION.\n  created by \"MD. HAMIDUR RHAMAN\"" << endl;
			return;
		default:
			cout << "\nInvalid Choice!";
		}
	} while (choice);
}

int main()
{
	cout << "--- Welcome to console program: Binary Search Tree (BST) ---" << endl;

	Node* rootNode;
	rootNode = new Node();
	
	chooseOption(rootNode);

	return 0;
}