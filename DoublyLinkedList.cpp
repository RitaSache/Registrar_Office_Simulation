#include "DoublyLinkedList.h"
#include <iostream>

using namespace std;

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

void DoublyLinkedList::insertFront(Student *d){
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
void DoublyLinkedList::insertBack(Student *d){
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

Student* DoublyLinkedList::removeFront(){ //to remove, check if it's the only node in the list or there's more
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
	Student *temp = node -> data;//temp used to be an int
	delete node;
	--size;
	return temp;
}

Student* DoublyLinkedList::removeBack(){
	ListNode *node = back;

	if(back -> prev == NULL){
		front = NULL;
	}
	else { 
		back -> prev -> next = NULL;
	}
	back = back -> prev;
	node -> prev = NULL;
	Student *temp = node -> data;
	delete node;
	--size;
	return temp;
}

Student* DoublyLinkedList::deletePos(int pos) {
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
	Student *d = curr -> data;
	delete curr;
	size--;
	return d;
}

void DoublyLinkedList::printList(){
	ListNode *curr = front;

	while(curr) {
		ListNode *next = curr -> next;
		cout << curr -> data -> timeOfArrival << ',' << curr -> data ->timeNeededAtAWindow  << endl;
		curr = next;	
	}
}

bool DoublyLinkedList::isEmpty(){
	if(size == 0) {
		return true;
	}
	else{
		return false;
	}
}

unsigned int DoublyLinkedList::getSize(){
	return size;
}

Student* DoublyLinkedList::showFrontNode(){
	return front->data;
}








