#include <iostream>
#include "Queue.h"

int main() {

	genQueue y;
	y.insert(1);
	y.insert(2);
	y.printQueue();
	y.peek();
	return 0;
}