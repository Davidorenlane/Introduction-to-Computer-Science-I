#include "Date.h" //we include both header files to include both classes because we need both for this cpp file
#include "ZodiacReader.h"
#include <string>
#include <iostream>

ZodiacReader::ZodiacReader(){ //default constructor
	mDate = Date(); //uses the default constructor of Date to set
}

ZodiacReader::ZodiacReader(Date date){ //constructor
	mDate = date;
}

ZodiacReader::Sign ZodiacReader::checkSign() { 
	if ((mDate.getMonth() == 3 && mDate.getDay() >= 21 && mDate.getDay() <= 31) || (mDate.getMonth() == 4 && mDate.getDay() >= 1 && mDate.getDay() <= 19)) //all these if statements
		return ARIES;
	if ((mDate.getMonth() == 4 && mDate.getDay() >= 20 && mDate.getDay() <= 31) || (mDate.getMonth() == 5 && mDate.getDay() >= 1 && mDate.getDay() <= 20))// are just checking the date supplied
		return TAURUS;
	if ((mDate.getMonth() == 5 && mDate.getDay() >= 21 && mDate.getDay() <= 31) || (mDate.getMonth() == 6 && mDate.getDay() >= 1 && mDate.getDay() <= 20))//using the accessor functions in class Date
		return GEMINI;
	if ((mDate.getMonth() == 6 && mDate.getDay() >= 21 && mDate.getDay() <= 31) || (mDate.getMonth() == 7 && mDate.getDay() >= 1 && mDate.getDay() <= 22))//and then if they correspond with a sign
		return CANCER;
	if ((mDate.getMonth() == 7 && mDate.getDay() >= 23 && mDate.getDay() <= 31) || (mDate.getMonth() == 8 && mDate.getDay() >= 1 && mDate.getDay() <= 22)) //returning the enum ofthat Sign
		return LEO;
	if ((mDate.getMonth() == 8 && mDate.getDay() >= 23 && mDate.getDay() <= 31) || (mDate.getMonth() == 9 && mDate.getDay() >= 1 && mDate.getDay() <= 22))
		return VIRGO;
	if ((mDate.getMonth() == 9 && mDate.getDay() >= 23 && mDate.getDay() <= 31) || (mDate.getMonth() == 10 && mDate.getDay() >= 1 && mDate.getDay() <= 22))
		return LIBRA;
	if ((mDate.getMonth() == 10 && mDate.getDay() >= 23 && mDate.getDay() <= 31) || (mDate.getMonth() == 11 && mDate.getDay() >= 1 && mDate.getDay() <= 21))
		return SCORPIO;
	if ((mDate.getMonth() == 11 && mDate.getDay() >= 22 && mDate.getDay() <= 31) || (mDate.getMonth() == 12 && mDate.getDay() >= 1 && mDate.getDay() <= 21))
		return SAGITTARIUS;
	if ((mDate.getMonth() == 12 && mDate.getDay() >= 22 && mDate.getDay() <= 31) || (mDate.getMonth() == 1 && mDate.getDay() >= 1 && mDate.getDay() <= 19))
		return CAPRICORN;
	if ((mDate.getMonth() == 1 && mDate.getDay() >= 20 && mDate.getDay() <= 31) || (mDate.getMonth() == 2 && mDate.getDay() >= 1 && mDate.getDay() <= 18))
		return AQUARIUS;
	if ((mDate.getMonth() == 2 && mDate.getDay() >= 19 && mDate.getDay() <= 31) || (mDate.getMonth() == 3 && mDate.getDay() >= 1 && mDate.getDay() <= 20)) {
		return PISCES;
	}
	return ARIES; //if a bad date were to be given it would default to ARIES
}
bool ZodiacReader::onCusp() {
	if ((mDate.getMonth() == 3 && mDate.getDay() >= 19 && mDate.getDay() <= 22) || //using the accesor funtions from Date again
		(mDate.getMonth() == 4 && mDate.getDay() >= 18 && mDate.getDay() <= 21) || //this just lists all the possible cusp dates
		(mDate.getMonth() == 5 && mDate.getDay() >= 19 && mDate.getDay() <= 22) || //if the date supplied is one of these it returns true
		(mDate.getMonth() == 6 && mDate.getDay() >= 19 && mDate.getDay() <= 22) || //otherwise false
		(mDate.getMonth() == 7 && mDate.getDay() >= 21 && mDate.getDay() <= 24) ||
		(mDate.getMonth() == 8 && mDate.getDay() >= 21 && mDate.getDay() <= 24) ||
		(mDate.getMonth() == 9 && mDate.getDay() >= 21 && mDate.getDay() <= 24) ||
		(mDate.getMonth() == 10 && mDate.getDay() >= 21 && mDate.getDay() <= 24) ||
		(mDate.getMonth() == 11 && mDate.getDay() >= 20 && mDate.getDay() <= 23) ||
		(mDate.getMonth() == 12 && mDate.getDay() >= 20 && mDate.getDay() <= 23) ||
		(mDate.getMonth() == 1 && mDate.getDay() >= 18 && mDate.getDay() <= 21) ||
		(mDate.getMonth() == 2 && mDate.getDay() >= 17 && mDate.getDay() <= 20)) {
		return true;
	}
	return false;
}
ZodiacReader::Sign ZodiacReader::cuspSign() {
	if((mDate.getMonth() == 3 && mDate.getDay() >= 19 && mDate.getDay() <= 20) || //given all the previously listed cusp dates,
		(mDate.getMonth() == 4 && mDate.getDay() >= 20 && mDate.getDay() <= 21)) // if the dates are those before or after a certain sign starts
		return ARIES;
	if ((mDate.getMonth() == 4 && mDate.getDay() >= 18 && mDate.getDay() <= 19) || // this returns that sign
		(mDate.getMonth() == 5 && mDate.getDay() >= 21 && mDate.getDay() <= 22))
		return TAURUS;
	if ((mDate.getMonth() == 5 && mDate.getDay() >= 19 && mDate.getDay() <= 20) ||
		(mDate.getMonth() == 6 && mDate.getDay() >= 21 && mDate.getDay() <= 22))
		return GEMINI;
	if ((mDate.getMonth() == 6 && mDate.getDay() >= 19 && mDate.getDay() <= 20) ||
		(mDate.getMonth() == 7 && mDate.getDay() >= 23 && mDate.getDay() <= 24))
		return CANCER;
	if ((mDate.getMonth() == 7 && mDate.getDay() >= 21 && mDate.getDay() <= 22) ||
		(mDate.getMonth() == 8 && mDate.getDay() >= 23 && mDate.getDay() <= 24))
		return LEO;
	if ((mDate.getMonth() == 8 && mDate.getDay() >= 21 && mDate.getDay() <= 22) ||
		(mDate.getMonth() == 9 && mDate.getDay() >= 23 && mDate.getDay() <= 24))
		return VIRGO;
	if ((mDate.getMonth() == 9 && mDate.getDay() >= 21 && mDate.getDay() <= 22) ||
		(mDate.getMonth() == 10 && mDate.getDay() >= 23 && mDate.getDay() <= 24))
		return LIBRA;
	if ((mDate.getMonth() == 10 && mDate.getDay() >= 21 && mDate.getDay() <= 22) ||
		(mDate.getMonth() == 11 && mDate.getDay() >= 22 && mDate.getDay() <= 23))
		return SCORPIO;
	if ((mDate.getMonth() == 11 && mDate.getDay() >= 20 && mDate.getDay() <= 21) ||
		(mDate.getMonth() == 12 && mDate.getDay() >= 22 && mDate.getDay() <= 23))
		return SAGITTARIUS;
	if ((mDate.getMonth() == 12 && mDate.getDay() >= 20 && mDate.getDay() <= 21) ||
		(mDate.getMonth() == 1 && mDate.getDay() >= 20 && mDate.getDay() <= 21))
		return CAPRICORN;
	if ((mDate.getMonth() == 1 && mDate.getDay() >= 18 && mDate.getDay() <= 19) ||
		(mDate.getMonth() == 2 && mDate.getDay() >= 19 && mDate.getDay() <= 20))
		return AQUARIUS;
	if ((mDate.getMonth() == 2 && mDate.getDay() >= 17 && mDate.getDay() <= 18) ||
		(mDate.getMonth() == 3 && mDate.getDay() >= 21 && mDate.getDay() <= 22)) {
		return PISCES;
	}
	return ARIES;  //if it's not a cusp date we default to ARIES
}
string ZodiacReader::stringifySign(ZodiacReader::Sign sign) {
	if (sign == 0)
		return "Aries"; //given an enumerated Sign,
	if (sign == 1)		//this function simply prints out the name of the enum as a string
		return "Taurus";
	if (sign == 2)
		return "Gemini";
	if (sign == 3)
		return "Cancer";
	if (sign == 4)
		return "Leo";
	if (sign == 5)
		return "Virgo";
	if (sign == 6)
		return "Libra";
	if (sign == 7)
		return "Scorpio";
	if (sign == 8)
		return "Sagittarius";
	if (sign == 9)
		return "Capricorn";
	if (sign == 10)
		return "Aquarius";
	if (sign == 11) {
		return "Pisces";
	}
	return "Aries";
}