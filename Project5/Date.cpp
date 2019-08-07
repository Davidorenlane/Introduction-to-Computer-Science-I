#include "Date.h"
#include <iostream>
using namespace std;

 Date::Date() { //default constructor definition
	mMonth = 1;
	mDay = 1;
}
 Date::Date(int month, int day) { //constructor definition, when called passes in parameters to the private variables in class Date
	mMonth = month;
	mDay = day;
}
int Date::getMonth() { //getter functions return private variables so they can be used pseudo-publically
	return mMonth;
}
int Date::getDay() { //getter functions return private variables so they can be used pseudo-publically
	return mDay;
}
void Date::setDate(int month, int day) { //just the setter function I included for practice
	mMonth = month;
	mDay = day;
}