#ifndef Student_Included

#define Student_Included

class Student{
	public:
		int ID;
		int timeOfArrival;
		int timeNeededAtAWindow;
		Student(int timeOfArr, int timeNeeded, int id);
		~Student();
	};


#endif