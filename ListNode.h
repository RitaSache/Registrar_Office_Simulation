#include <iostream>
using namespace std;

class ListNode {
	public:
		int data; // node has to be able to store data
		ListNode *next; // node consists of two components: data component and a pointer to the 
		ListNode *prev;
		//next node
		ListNode();
		ListNode(int data);
		~ListNode();
};

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
};