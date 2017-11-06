#include <iostream>
#include <fstream>
#include "Queue.h"
#include "Window.h"
using namespace std;

int main(int argc, char **argv) {

	ifstream inputFile;
	inputFile.open(argv[1]);
	if(!inputFile) {
		cout << "File was not found, exiting program" << endl;
		exit(0);
	}
	genQueue students;

	string line;
	getline(inputFile, line);
	int numberOfWindowsOpen = stoi(line); //converting from string to int
	Window windows(numberOfWindowsOpen);//where i make my windows array with that size
	int ID=0;
	while(!inputFile.eof()){

		getline(inputFile, line);
		int timeOfArr = stoi(line);

		getline(inputFile, line);
		int numberOfStudents = stoi(line);

		for(int i =0; i< numberOfStudents; i++){
			getline(inputFile,line);
			int timeNeededAtAWindow = stoi(line);
			Student *student = new Student(timeOfArr, timeNeededAtAWindow, ID);
			students.insert(student);
			ID++;
		}
	}
	int sizeOfQueue = students.getSize();
	int *waitTimes = new int[students.getSize()];
	int *idleWindowTimes = new int[numberOfWindowsOpen];
	int time = 0;
	while(time){
		for(int i = 0; i < windows.max; i++){
			if(windows.windowsArray[i] != NULL) {
				if(windows.windowsArray[i]-> timeNeededAtAWindow == 0){
					windows.windowsArray[i] = NULL;
				}
			}
		}
		for(int i = 0; i < students.getSize(); i++){
			if(time >= students.peek() -> timeOfArrival){
				if (windows.firstAvailableWindow() != -1){
					windows.windowsArray[windows.firstAvailableWindow()] = students.peek();
					students.remove();
				}
				else{
					waitTimes[students.peek() -> ID] = time - students.peek() -> timeOfArrival +1;
				}
			}
		}
		for(int i = 0; i < windows.max; i++){
			if(windows.windowsArray[i] != NULL)
				windows.windowsArray[i] -> timeNeededAtAWindow--;
			else{
				idleWindowTimes[i]++;
			}
		}
		time++;
	}
	int sum = 0;
	for(int i=0; i<sizeOfQueue; i++){
		sum+=waitTimes[i];
	}
	int meanWaitingTime = 0;
	meanWaitingTime = sizeOfQueue/sum;
	cout << "Mean student waiting time is " << meanWaitingTime << endl;

}