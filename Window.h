#ifndef Window_Included

#define Window_Included

#include "Student.h"

class Window{
	private:
		int max;
	public:
		Student **windowsArray;
		Window(int maxNumber);
		int firstAvailableWindow();
};


#endif