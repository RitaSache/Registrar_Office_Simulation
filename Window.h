#ifndef Window_Included

#define Window_Included

#include "Student.h"

class Window{
	public:
		int max;
		Student **windowsArray;
		Window(int maxNumber);
		~Window();
		int firstAvailableWindow();
};


#endif