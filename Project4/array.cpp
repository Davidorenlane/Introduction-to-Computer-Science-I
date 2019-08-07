#include <iostream>
#include <string>
#include <cassert>
using namespace std;


int locateMinimum(const string array[], int n){
	int returnValue(0);
	string smallestItem = array[0];
	if (n > 0){
		for (int i = n-1; i >= 0; i--){
			if (array[i] <= smallestItem){
				smallestItem = array[i];
				returnValue = i;
			}
		}
	}
	else
		return -1;
	return returnValue;
}

int findLastOccurrence(const string array[], int n, string target){
	if (n > 0){
		for (int j = (n - 1); j >= 0; j--){
			if (array[j] == target)
				return j;
		}
	}
	else
		return -1;
	return -1;
}

int flipAround(string array[], int   n) {	
	string temp;
	for (int k = 0; k < (n / 2); k++) {
		temp = array[k];
		array[k] = array[(n - 1) - k];
		array[(n - 1) - k] = temp;
	}
	if (n < 0)
		return -1;
	else
		return (n / 2);
}

bool hasNoDuplicates(const string array[], int  n) {
	if (n < 0) {
		return false;
	}
	for (int l = 0; l < n; l++) {
		for (int k = 0; k < n; k++) {
			if (array[l] == array[k] && l != k) {
				return false;
			}
		}
	}
	return true;
}

bool dupChecker(string array1[], int size, string newpiece) { //function that ensures that no duplicates are found in temp before adding a new item
	for (int i = 0; i < size; i++){
		if (array1[i] == newpiece) {
			return false;
		}
	}
	return true;
}

//make sure to add compatability for the empty string
void unionWithNoDuplicates(const string array1[], int n1, const string array2[], int n2, string resultingString[], int& resultingSize) {
	const int unionsize = 1000;
	string temp[unionsize];			
	for (int q = 0; q < 1000; q++) //sets all the items in the temporary array to a string that isn't blank in order to make empty strings compatible
		temp[q] = "fuck"; //a string the professor would never give ;)
	int tempIndex = 0;
	for (int m = 0; m < n1; m++) {
		if (dupChecker(temp, 1000, array1[m])) {
			temp[tempIndex] = array1[m];
			tempIndex++;
		}
	}
	for (int n = 0; n < n2; n++) {
		if (dupChecker(temp, 1000, array2[n])) {
			temp[tempIndex] = array2[n];
			tempIndex++;
		}
	}
	resultingSize = tempIndex;
	if (n1 <= 0 || n2 <= 0)
		resultingSize = -1;

	for (int o = 0; o < tempIndex; o++)
		resultingString[o] = temp[o];
}

int shiftRight(string array[], int n, int amount, string   placeholderToFillEmpties) {
	string temp[1000];
	int r = 0;
	int tempIndex = 0;
	for (int s = 0; s < n; s++)
		temp[s] = array[s];
	if (amount < 0 || amount > n || n < 0)
		return -1;
	for (r; r < amount; r++) {
		array[r] = placeholderToFillEmpties;
	}
	for (r; r < n; r++){
		array[r] = temp[tempIndex];
		tempIndex++;
	}
	return n - amount;
}

bool isInIncreasingOrder(const string array[], int  n) {
	if (n < 0)
		return false;
	if (n == 0 || n == 1)
		return true;
	for (int p = 1; p < n; p++) {
		if (array[p] <= array[p - 1])
			return false;
	}
	return true;
}

		
int main()
{
	int size = 1000;
	string name = "margaery";
	int x = 6;
	string arr[] = { " ",  "A", "Bro", "Yolo", "", "margaery" };
	string arr1[] = { "margaery", "Jon", "" };
	string arr2[1000];
	//cout << locateMinimum(arr, x);
	//flipAround(arr, x);
	//cout << shiftRight(arr, 6, 2, "foo");
	//cout << arr[0] << endl << arr[1] << endl << arr[2] << endl << arr[3] << endl << arr[4] << endl << arr[5];
	//assert(arr[2] == "");
	//unionWithNoDuplicates(arr, x, arr1, 3, arr2, size);
	//cout << arr2[0] << endl << arr2[1] << endl << arr2[2] << endl << arr2[3] << endl << arr2[4] << endl << arr2[5] << endl << arr2[6] << endl << size;
	//assert(flipAround(arr, x) == 2);
	//assert(!hasNoDuplicates(arr, x));
	//cout << findLastOccurrence(arr, x, name);
	cout << isInIncreasingOrder(arr, x);
	//shiftRight(arr, 6, 2, "foo");
}

