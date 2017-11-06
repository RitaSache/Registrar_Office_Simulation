#ifndef Student_Included

#define Student_Included

class Student{
	public:
		int ID;
		int timeOfArrival;
		int timeNeededAtAWindow;
		Student(int timeOfArrival, int timeNeededAtAWindow, int ID);
		~Student();
};


#endif