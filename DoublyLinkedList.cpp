#include "ListNode.h"
using namespace std;

ListNode::ListNode(int d){ 
	data = d; 
	next = NULL;
	prev = NULL;
}

ListNode::~ListNode(){
	/*
	if (next != NULL){
		delete next;
	}
	next = NULL;
	prev = NULL;
*/}

DoublyLinkedList::DoublyLinkedList(){
	size = 0;
	front = NULL;
	back = NULL;
}

DoublyLinkedList::~DoublyLinkedList(){
	ListNode *curr = front;
	while (curr) {
		ListNode* next = curr -> next;
		delete curr;
		curr = next;
	}
}

void DoublyLinkedList::insertFront(int d){
	ListNode *node = new ListNode(d);

	if (size == 0) {
		back = node;
	}
	else { //not empty
		front -> prev = node;
		node -> next = front;
	}

	front = node;
	size++;
}
void DoublyLinkedList::insertBack(int d){
	ListNode *node = new ListNode(d);

	if (size == 0) {
		front = node;
	}
	else{ //not empty
		back -> next = node;
		node -> prev = back;
	}
	back = node;
	++size;
}

int DoublyLinkedList::removeFront(){ //to remove, check if it's the only node in the list or there's more
	//nodes are pointing in both directions: |-|_|_|_| -> |_|_|_| -> |_|_|_| -|
										  // =	 	   <-         <-          =
 	ListNode *node = front;
	if(front -> next == NULL){//if only node in list
		//set pointers to null
		back = NULL;
	}
	else { //if more than one node
		//null out the next in line node's pointer pointing to the first (front) node.
		front -> next -> prev = NULL;//front arrow next, arrow previous is now null
	}
	front = front -> next;
	//then remove pointer of the front node that used to point to the next in line node
	node -> next = NULL; 
	int temp = node -> data;
	delete node;
	--size;
	return temp;
}

int DoublyLinkedList::remove(int key) {
	ListNode *curr = front; //curr in pointing to front and needed to keep track of where i am at in the linkedlist
	//start looking for node
	while(curr ->data != key) {
		curr = curr -> next;
		if(curr == NULL){
			return 0; //if not found, we're done looking
		}
	}
	//if value to delete is found, need to check if it's in the front, back or middle
	if(curr == front) {
		front = curr -> next;
	}
	else {//node is in the middle somewhere and we need to update pointers
		curr->prev -> next = curr ->next;//previous node's to current node pointer gets pointed to the node right after the current node instead
	}

	if(curr == back) {
		back = curr->prev;
	}
	else {
		curr->next->prev = curr -> prev;
	}
	curr->next = NULL;//nulling out the current node
	curr->prev = NULL;

	int temp = curr->data;
	delete curr; //deleting the node
	--size;
	return temp;
}

int DoublyLinkedList::removeBack(){
	ListNode *node = back;

	if(back -> prev == NULL){
		front = NULL;
	}
	else { 
		back -> prev -> next = NULL;
	}
	back = back -> prev;
	node -> prev = NULL;
	int temp = node -> data;
	delete node;
	--size;
	return temp;
}

int DoublyLinkedList::deletePos(int pos) {
	int idx = 0;
	ListNode *curr = front;
	ListNode *prev = front;
	ListNode *next = curr -> next;
	while(idx != pos) {
		prev = curr; 
		curr = curr -> next;
		++idx;
	}
	/*if (idx == 0) {
		curr -> next = NULL;
		next -> prev = NULL;
		int d = curr -> data;
		delete curr;
		size--;
		return d;
	}*/

	prev -> next = curr -> next;
	curr -> next = NULL;
	next -> prev = curr -> prev;
	curr -> prev = NULL;
	int d = curr -> data;
	delete curr;
	size--;
	return d;
}

void DoublyLinkedList::printList(){
	ListNode *curr = front;

	while(curr) {
		ListNode *next = curr -> next;
		cout << curr -> data << endl;
		curr = next;	
	}
}












