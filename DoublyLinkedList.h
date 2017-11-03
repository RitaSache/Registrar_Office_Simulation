#include "ListNode.h"

class DoublyLinkedList {
	private:
		ListNode *front;
		ListNode *back;
		unsigned int size;
	public: 
		DoublyLinkedList();
		~DoublyLinkedList();
		void insertFront(int data);
		void insertBack(int data);
		int removeFront();
		int removeBack();
		int remove(int key);
		void printList();
		int deletePos(int pos);
		int find(int value);
		bool insertAfter(int pos, int val);
		bool isEmpty();
		unsigned int getSize();
		int showFrontNode();
};