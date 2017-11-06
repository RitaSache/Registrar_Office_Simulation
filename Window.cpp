#include <iostream>
#include "Window.h"

Window::Window(int maxNumber){
	windowsArray = new Student*[maxNumber];
	for (int i = 0; i < maxNumber; i++) {
		windowsArray[i] = NULL;
	}
	max = maxNumber;
}


int Window::firstAvailableWindow(){
	for(int i = 0; i < max; i++){
		if(windowsArray[i] == NULL){
			return i;
		}
	}
	return -1;
}