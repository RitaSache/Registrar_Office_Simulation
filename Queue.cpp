#include <iostream>
#include "Queue.h"

genQueue::genQueue(){
	myList = new DoublyLinkedList;
}

genQueue::~genQueue(){
	delete myList;
}

void genQueue::insert(int data) {
	myList->insertBack(data);
}

int genQueue::remove(int key){ 
	return myList->remove(key);
}

int genQueue::peek(){
	return myList->showFrontNode();
}

int genQueue::isEmpty(){
	return myList->isEmpty();
}

void genQueue::printQueue(){
	myList->printList();
}

unsigned int genQueue::getSize(){
	return myList->getSize();
}





