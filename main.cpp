#include <iostream>
#include "ListNode.h"
using namespace std;


int main() {

	DoublyLinkedList r;

	r.insertFront(4);
	r.insertFront(6);
	r.insertFront(8);
	r.insertBack(10);
	r.insertBack(11);
	r.removeBack();
	r.insertBack(9);
	r.printList();
	r.deletePos(4);
	r.printList();

	return 0;
}