#include <iostream>
#include <string>
#include "Rectangle2D.h" //EX04_04 11.9
#include "Course.h" //EX04_05 11.13
using namespace std;

int* doubleCapacity(const int* list, int size); //EX04_02 11.3
int smallestValue(const int* list, int size); //EX04_03 11.5


int main() {
	//EX04_01 11.1
	cout << "test for 11.1\n";
	int size;
	cout << "Array size: ";
	cin >> size;
	int * ptest = new int[size];
	int total = 0;
	for (int i = 0; i < size; i++) {
		cout << "Value " << i + 1 << ": ";
		cin >> ptest[i];
		total += ptest[i];
	}
	double average = (total / size);
	int count = 0;
	for (int i = 0; i < size; i++) {
		if (ptest[i] > average)
			count++;
	}
	cout << "There are " << count << " numbers above the average " << average << endl << endl;
	delete[] ptest;

	//EX04_02 11.3 test
	cout << "test for 11.3\n";
	int * ptr = new int[5];
	for (int i = 0; i < 5; i++) {
		ptr[i] = 4;
	}
	cout << "Double array size 5 filled with integer 4 to size 10" << endl;
	int * ptr2 = doubleCapacity(ptr, 5);
	for (int i = 0; i < 10; i++) {
		cout << ptr2[i] << endl;
	}
	cout << endl;
	delete[] ptr;
	delete[] ptr2;

	//EX04_03 11.5
	cout << "test for 11.5\n";
	int list[] = { 1, 2, 4, 5, 10, 100, 2, -22 };
	cout << smallestValue(list, 8) << endl << endl;

	//EX04_04 11.9 test
	cout << "test for 11.9\n"; 
	Rectangle2D r1(2, 2, 5.5, 4.9), r2(4, 5, 10.5, 3.2), r3(3, 5, 2.3, 5.4);
	cout << "r1 perimeter = " << r1.getPerimeter() << endl << "r1 area = " << r1. getArea() << endl;
	cout << "r1 contains (3,3) ? " << boolalpha << r1.contains(3, 3) << endl;
	cout << "r1 contains r2? " << r1.contains(r2) << endl;
	cout << "r1 overlaps r3? " << r1.overlaps(r3) << endl;
	cout << endl;

	//EX04_05 11.13 test
	cout << "test for 11.13\n";
	Course course1("Computer Science", 10); //creates course 1 computer science, capacity = 10
	course1.addStudent("peter");
	course1.addStudent("peter2");
	course1.addStudent("peter3");
	course1.dropStudent("peter2");
	cout << "Students in Computer Science";
	for (int i = 0; i < course1.getNumberOfStudents(); i++) {
		cout << (course1.getStudents())[i] << endl;
	}
	return 0;
}


//EX04_02 11.3
int* doubleCapacity(const int* list, int size) {
	int * test = new int[size * 2];
	for (int i = 0; i < size; i++)
		test[i] = list[i];
	return test;
}

//EX04_03 11.5 
int smallestValue(const int* list, int size) {
	int smallest = list[0];
	for (int i = 1; i < size; i++) { 
		if (list[i] < smallest)
			smallest = list[i];
	}
	return smallest;
}