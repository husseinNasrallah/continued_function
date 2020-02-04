//a program that gives you the terms for an infinit continued fraction
//note:for the exersices just enter the number as e in decimal and same for the radical and it should give the same answer that you want this is just the code without the execrsises
#include <iostream>
using namespace std;
int* fracterm(double number, int count, int* terms, double epsilon);

int main() {
	//intialize the variables number,count,epsilon by getting the values from the user
	cout << "enter the number you want" << endl;
	double number;
	cin >> number;
	cout << "enter the number of terms to be calculated" << endl;
	int count;
	cin >> count;
	int* terms = new int[count];
	cout << "enter the epsilon that you want" << endl;
	double epsilon;
	cin >> epsilon;
	//initialize the array to epsilon for later comparison
	for (int i = 0; i < count; i++) {
		terms[i] = epsilon;
	}
	//call the function of the continues fraction
	terms=fracterm(number, count, terms, epsilon);
	int counter = 0;
	//print the terms that we want from the array only if the terms are not epsilon 
	while (terms[counter] != epsilon && counter<count) {
		cout << terms[counter] << ",";
		counter++;
	}

}
//the function fracterm it returns an adress to an array that contains the terms of the contnues fraction
int* fracterm(double number, int count, int* terms, double epsilon)
{
	//check if the number is positive or negative by comparing it to epsilon if greater it is possitive else negative
	if (number > epsilon) {
		//check if the number is an integer by subtracting the cast of the number into integer whcih will give the integer part of it 
		if (number - (int)(number) > epsilon) {
			//if not integer do the continues fraction by doing subtraction the integer part of the number and putting it in the array and then setting the number to 1 over the remaining of the number and do it as much as the user want
			for (int i = 0; i < count; i++) {
				terms[i] = (int)(number);
				number = number - (int)(number);
				number = 1 / number;
			}
		}
		//if not fraction the just place the integer in 0 address of the array and return the array
		else {
			terms[0] = (int)(number);
		}
	}
	//returning the negative number in the index of the array at the position 0
	else {
		terms[0] = -1;
	}
	return terms;
}