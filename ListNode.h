
class ListNode {
	public:
		int data; // node has to be able to store data
		ListNode *next; // node consists of two components: data component and a pointer to the 
		ListNode *prev;
		//next node
		ListNode();
		ListNode(int data);
};