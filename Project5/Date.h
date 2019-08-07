//#pragma once
#ifndef __DATE_H_INCLUDED__ //header guard required
#define __DATE_H_INCLUDED__

class  Date { // class declaration
private:	//private variables
	int mMonth;
	int mDay;
public: //functions public
	Date(); //default constructor 
	Date(int month, int day); //constructor
	int getMonth(); //accesor functions used to access private variables
	int getDay();
	void setDate(int month, int day); //setter function, kind of irrelevant, just for practice :)
};

#endif 