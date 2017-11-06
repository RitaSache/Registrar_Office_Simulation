#ifndef ListNode_Included

#define ListNode_Included

#include "Student.h"

class ListNode {
	public:
		Student *data; // node has to be able to store data
		ListNode *next; // node consists of two components: data component and a pointer to the 
		ListNode *prev;
		//next node
		ListNode();
		ListNode(Student *data);
};

#endif