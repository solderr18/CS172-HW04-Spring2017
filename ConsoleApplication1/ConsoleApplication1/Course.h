#ifndef COURSE_H
#define COURSE_H
#include <iostream>
#include <string>
using namespace std;

//EX04_05 11.13
class Course { //code primarily from text
private:
	string CourseName;
	string * students;
	int NumberOfStudents;
	int Capacity;
public:
	Course(const string & courseName, int capacity) {
		NumberOfStudents = 0;
		this->CourseName = courseName;
		this->Capacity = capacity;
		students = new string[capacity];
	}
	
	
	string getCourseName() const { return CourseName; }
	
	///:::ACTUAL 11.3 ASSIGNMENT CODE:::
	void addStudent(const string& name) {
		if (NumberOfStudents > Capacity) {
			string * test = new string[Capacity + 1];
			for (int i = 0; i < Capacity; i++)
				test[i] = students[i];
			students = test;
			delete[] test;
			Capacity++;
			NumberOfStudents++; 
		}
		else {
			students[NumberOfStudents + 1] = name;
			NumberOfStudents++;
		}
	}
	void dropStudent(const string& name) { 
		//copy things that aren't the student youre removing into new array
		int j = 0;
		string * placeholder = new string[Capacity];
		for (int i = 0; i < NumberOfStudents; i++) {
			if (students[i] != name) { //when it reaches the name, it will skip this & j wont incriment
				placeholder[j] = students[i];
				j++;
			}
		}
		students = placeholder;
		delete[] placeholder;
		NumberOfStudents--; //this is also true
	}
	void clear() { //removes all students from the course
		string * ptr = new string[Capacity]; 
		students = ptr; //studetns is now this pointer filled with gibberish
		delete[] ptr;
		NumberOfStudents = 0;
	}
	//destructor
	~Course() {
		delete[] students;
	}
	//copy constructor
	Course(Course & a) {
		CourseName = a.CourseName;
		NumberOfStudents = a.NumberOfStudents;
		Capacity = a.Capacity;
		students = new string[Capacity];
		for (int i = 0; i < NumberOfStudents; i++) {
			students[i] = a.students[i];
		}
	}

	//end assignment code
	string * getStudents() const { return students; } //there is a problem with this fxn but I dont know what
													// won't return (pointer to ) array?
													//something wrong with add/drop student code??
	int getNumberOfStudents() const { return NumberOfStudents; }

	void printCourse(const Course c) { //for organization in test
		cout << "Course Name: " << c.getCourseName() << endl;
		cout << "Number of Stuents: " << c.getNumberOfStudents() << endl;
	}
};

#endif