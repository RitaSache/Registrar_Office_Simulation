#include <iostream>
#include "Queue.h"

genQueue::genQueue(){
	myList = new DoublyLinkedList;
}

genQueue::~genQueue(){
	delete myList;
}

void genQueue::insert(Student *data) {
	myList->insertBack(data);
}

Student* genQueue::remove(){ 
	return myList->removeFront();
}

Student* genQueue::peek(){
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





