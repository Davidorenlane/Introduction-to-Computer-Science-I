#include <iostream>
#include <string>
using namespace std;

int main()
{
	string name;		//establishing all variables and their types
	double miles;
	double minutes;
	double fare;
	string rideType;


	cout.setf(ios::fixed);		//code to set number outputs to show two digits after the decimal point
	cout.setf(ios::showpoint);
	cout.precision(2);

	cout << "Customer Name: ";
	//cin.ignore(1000, '/n');	//requesting the inputs to all 4 variables
	getline(cin, name);
	cout << "Miles to be driven: ";
	cin >> miles;
	cout << "Minutes to be driven: ";
	cin >> minutes;
	cout << "Ride Type: ";
	cin >> rideType;

 if (name.size() == 0)			//if size of string is 0 characters
 {
	 cout << "--- You must enter a customer name."				//All the error messages
	 << endl;
	
	 return 0;
 }
 if (miles <= 0)
 {
	 cout << "--- The mileage must be positive."
	<< endl;
	 return 0;
 }
 if (minutes <= 0)
 {
	 cout << "--- The time must be positive."
		 << endl;
	 return 0;
 }
 if (rideType == "Br-UberX")			//establishing which fare calc to use when rideType is given as Br-UberX
 {
	 fare = ((miles * 0.9) + (minutes * 0.15) + 1.65);	//Fare calculation using given variables
	 cout << "--- The fare for " << name << " is $";
	 if (fare > 5.15)									//used to establish minimum fare of $5.15
	 {
		 cout << fare
			 << endl;
	 }
	 else
	 {
		 cout << "5.15"
			 << endl;
	 }
 }
 else if (rideType == "Br-UberXL")		//establishing which fare calc to use when rideType is given as Br-UberXL
 {
	 fare = ((miles * 1.55) + (minutes * 0.3) + 1.65);
	 cout << "--- The fare for " << name << " is $";
	 if (fare > 7.65)
	 {
		 cout << fare
			 << endl;
	 }
	 else
	 {
		 cout << "7.65"
			 << endl;
	 }
 }
 else
 {
	 cout << "--- The ride type is not valid." << endl;
	 return 0;
 }
	return 0;
}
