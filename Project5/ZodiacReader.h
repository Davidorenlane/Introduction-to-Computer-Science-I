//#pragma once
#ifndef ZODIACREADER_H //header guard
#define ZODIACREADER_H

#include <string>
#include <iostream>
#include "Date.h"  // includes the class created to store dates so Date can be used as a type
using namespace std;

class ZodiacReader { //a second class
private:
	Date mDate; //once Date class is created we can use it as a variable type, this will be private
public: //all the functions are public
	ZodiacReader(); //default constructor
	ZodiacReader(Date date); //constructor
	enum Sign{ARIES, TAURUS, GEMINI, CANCER, LEO, VIRGO, 
		LIBRA, SCORPIO, SAGITTARIUS, CAPRICORN, AQUARIUS, PISCES}; //enumerates the 12 zodiac signs just to make them slightly easier to refer to
	ZodiacReader::Sign checkSign(); // function which, when given a date, returns the Sign from ZodiacReader
	bool onCusp(); // checks if a date is "on the cusp" of another sign
	ZodiacReader::Sign cuspSign(); //returns the sign before or after the sign of the date accordingly
	string stringifySign(ZodiacReader::Sign sign); //turns an enumerated Sign into a string, this is where enum helps, dont need to type out full sign name only number
};

#endif 
