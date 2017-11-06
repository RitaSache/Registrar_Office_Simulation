#include <iostream>
#include <fstream>
#include "Queue.h"
#include "Window.h"
using namespace std;

//main method reads and saves numbers from a file, simulates, and calculates statistics
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
	int numberOfWindowsOpen = stoi(line); 
	Window windows(numberOfWindowsOpen);
	int ID=0;
	//while in input file save all numbers into their respective description variables
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
	inputFile.close();
	int sizeOfQueue = students.getSize();
	int *waitTimes = new int[students.getSize()];
	int *idleWindowTimes = new int[numberOfWindowsOpen];
	int time = 0;
	//simulates the queue and window assignments for students until the queue is empty and everyone's requests are processed
	//saves waiting times and window idle times into arrays to later perfrom statistical analysis
	while(!students.isEmpty()){
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
					waitTimes[students.peek() -> ID] = (time - students.peek() -> timeOfArrival) +1;
					//cout << "time of arrival of the first student in a queue " << students.peek() -> timeOfArrival << endl;
					//cout << "wait time of student in a queue " << waitTimes[i] << endl;
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
	for(int i=0; i<sizeof(waitTimes); i++){
		sum+=waitTimes[i];
	}
	float meanWaitingTime = 0;
	float medianWaitingTime = 0;
	meanWaitingTime = sizeOfQueue/(float)sum;
	/*sort(waitTimes, sizeof(waitTimes));
	if(sizeof(waitTimes)%2 != 0){
		medianWaitingTime = ((float)sizeof(waitTimes)+1/2)-1;
	}
	else{
		medianWaitingTime = ((float)sizeof(waitTimes)/2)-1;
	}*/
	cout << "Mean student waiting time is " << meanWaitingTime << endl;
	//cout<<"Median student waiting time is " << medianWaitingTime << endl;
	return 0;
}






