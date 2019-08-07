#include <iostream>
#include <cassert>
#include <string>
#include <cctype> //included to allow 'tolower' and 'isdigit' 
using namespace std;


bool checkOnTime(string commands, int& charMarker) //function returns true if the minutes late or early for scheduled arrival is 1-3 characters, and then moves on through the string
{
	if (isdigit(commands[charMarker]) && isdigit(commands[charMarker + 1]) && isdigit(commands[charMarker + 2]))
	{
		charMarker = charMarker + 3;
		return true;
	}
	else if (isdigit(commands[charMarker]) && isdigit(commands[charMarker + 1]))
	{	 
		charMarker = charMarker + 2;
		return true;
	}
	else if (isdigit(commands[charMarker]))
	{		 
		charMarker++;
		return true;
	}
	else
		return false;
}

bool checkFlightNumber(string commands, int& charMarker) //function returns true if the flight number is 1-3 characters, and then moves on through the string
{
	if (isdigit(commands[charMarker]) && isdigit(commands[charMarker + 1]) && isdigit(commands[charMarker + 2]))
	{
		charMarker = charMarker + 3;
		return true;
	}
	else if (isdigit(commands[charMarker]) && isdigit(commands[charMarker + 1]))
	{	 
		charMarker = charMarker + 2;
		return true;
	}
	else if (commands[charMarker] == '0') //this one ensures the flight number is not 0 because unlike the ontime, that would be invalid here
		return false;
	else if (isdigit(commands[charMarker]))
	{	 
		charMarker++;
		return true;	
	}
	else
		return false;
}

bool isWellFormedAirportString(string commands) //first function to check if the commands string is valid
{
	string airlineCode; //temp string used to hold lower case verions of 'commands'
	for (int charMarker = 0; charMarker < commands.size();) //for loop moves through the string 
	{
		airlineCode += tolower(commands[charMarker]); //makes all letters lower case
		charMarker++;
		airlineCode += tolower(commands[charMarker]);
		charMarker++;

		if (airlineCode == "aa" || airlineCode == "ua" || airlineCode == "dl" || airlineCode == "sw" || airlineCode == "al" || airlineCode == "va") //checks if airline abbreviation is one of the ones given
		{
			airlineCode = ""; //resets for future iterations
			if (checkFlightNumber(commands, charMarker)) //runs checker function
			{
				if (commands[charMarker] == '+' || commands[charMarker] == '-') //checks for appropriate symbol
				{
					charMarker++; //moves on
					if (checkOnTime(commands, charMarker)) //runs other checker function
							continue; // if no error is found for loop continues
					else
						return false; //otherwise returns false 
				}
				else
					return false;
			}
			else 
				return false;
		}
		else
			return false;
	}
	return true; //if no problems are found in the string the function returns true
} 

bool airlineXX(string& airlinecode, int& codeCounter, string& twoLetters) //function similar to the airline code checker above, but also checks to make sure its two characters
{
	if (isalpha(airlinecode[codeCounter]) && airlinecode.size() < 3)
	{
		twoLetters += tolower(airlinecode[codeCounter]); //makes "airlinecode" lowercase (passed by reference)
		codeCounter++;
		twoLetters += tolower(airlinecode[codeCounter]);
		if (twoLetters == "aa" || twoLetters == "ua" || twoLetters == "dl" || twoLetters == "sw" || twoLetters == "al" || twoLetters == "va") 
		{
			return true;
		}
	}
	else
		return false;
}

double ontimeArrivalPercentage(string commands, string airlinecode)
{
	string twoLetters; //'airlinecode' in lowercase form
	string codeLetters;  //same purpose as "airlineCode" (not "airlinecode") in the validity checker
	double codeInstances(0);
	double lateInstances(0);
	double onTimeRatio;
	int codeCounter(0);	
	if (isWellFormedAirportString(commands)) //checks if 'commands' is valid
		{
		if (airlineXX(airlinecode, codeCounter, twoLetters))	//checks if 'airlinecode' is valid	
		{
			for (int charCounter = 0; charCounter <= commands.size(); charCounter++) // for loop to move through the string and find late/ontime flights
			{
				if (isalpha(commands[charCounter])) //makes letters in 'commands' compatible with 'twoLetters'
				{
					codeLetters += tolower(commands[charCounter]);
					charCounter++;
					codeLetters += tolower(commands[charCounter]);
					charCounter++;
					if (codeLetters == twoLetters)
					{
						codeInstances++; //when we find an instance of twoLetters in commands 
						if (isdigit(commands[charCounter]) && isdigit(commands[charCounter + 1]) && isdigit(commands[charCounter + 2])) //these three move through the string to the +/- sign
						{
							charCounter = charCounter + 3;
							
						}
						else if (isdigit(commands[charCounter]) && isdigit(commands[charCounter + 1]))
						{
							charCounter = charCounter + 2;
					
						}
						else if (isdigit(commands[charCounter]))
						{
							charCounter++;
							
						}
						if (commands[charCounter] == '+') //if - sign we know flight is on time, the following is the logic to check if a flight is more than 14 minutes late
						{
							if (commands[charCounter + 1] == '0')
							{
								
								if (commands[charCounter + 2] == '1')
								{
									if (commands[charCounter + 3] == '5' || commands[charCounter + 3] == '6' || commands[charCounter + 3] == '7' || commands[charCounter + 3] == '8' || commands[charCounter + 3] == '9')
										lateInstances++;

								}
								else if (commands[charCounter + 2] == '2' || commands[charCounter + 2] == '3' || commands[charCounter + 2] == '4' || commands[charCounter + 2] == '5' || commands[charCounter + 2] == '6' || commands[charCounter + 2] == '7' || commands[charCounter + 2] == '8' || commands[charCounter + 2] == '9')
									if (commands[charCounter + 3] == '0' || commands[charCounter + 3] == '1' || commands[charCounter + 3] == '2' || commands[charCounter + 3] == '3' || commands[charCounter + 3] == '4' || commands[charCounter + 3] == '5' || commands[charCounter + 3] == '6' || commands[charCounter + 3] == '7' || commands[charCounter + 3] == '8' || commands[charCounter + 3] == '9')
										lateInstances++;
							}
							if (commands[charCounter + 1] == '1')
							{
								if (charCounter + 2 < commands.size()) //the problem spot discussed in the report. "commands[charCounter + 2]" was looking for out of bounds characters causing undefined behavior
								{
									if (commands[charCounter + 2] == '5' || commands[charCounter + 2] == '6' || commands[charCounter + 2] == '7' || commands[charCounter + 2] == '8' || commands[charCounter + 2] == '9')
										lateInstances++;
									else if (charCounter + 3 < commands.size()) 
									{
										if (commands[charCounter + 3] == '0' || commands[charCounter + 3] == '1' || commands[charCounter + 3] == '2' || commands[charCounter + 3] == '3' || commands[charCounter + 3] == '4' || commands[charCounter + 3] == '5' || commands[charCounter + 3] == '6' || commands[charCounter + 3] == '7' || commands[charCounter + 3] == '8' || commands[charCounter + 3] == '9')
											lateInstances++; //if logic holds, flight is late
									}
								}
							}
							if (commands[charCounter + 1] == '2' || commands[charCounter + 1] == '3' || commands[charCounter + 1] == '4' || commands[charCounter + 1] == '5' || commands[charCounter + 1] == '6' || commands[charCounter + 1] == '7' || commands[charCounter + 1] == '8' || commands[charCounter + 1] == '9')
								if (commands[charCounter + 2] == '0' || commands[charCounter + 2] == '1' || commands[charCounter + 2] == '2' || commands[charCounter + 2] == '3' || commands[charCounter + 2] == '4' || commands[charCounter + 2] == '5' || commands[charCounter + 2] == '6' || commands[charCounter + 2] == '7' || commands[charCounter + 2] == '8' || commands[charCounter + 2] == '9')
									lateInstances++; //if logic holds, flight is late
						}

					}
					codeLetters = "";
				}
			}
			if (codeInstances == 0)
				return 0; //if no instances of the airlinecode are found in commands
		}
		else
			return -1; //if not a valid airlinecode
	}
	else
		return -1; //if not a valid commands string
	onTimeRatio = 1 - (lateInstances / codeInstances); //1 - the percent of late flightss = the percent of ontime flights
	return onTimeRatio;
}

int main()
{
	string x = "";
	cin >> x;
	cout << ontimeArrivalPercentage(x, "AA");
}


