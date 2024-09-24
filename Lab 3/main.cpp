/*
	Delvis Kouete
	Computer Science Fall 2024
	Due: Oct. 1, 2024
	Lab 3, Lab 3 User and File I/O
	Write an interactive C++ program that computes and outputs the mean and 
	population standard deviation of a set of four integers
	*/
#include <iostream>
#include <string>
#include "Statscalcr.h"
#include "fstream"
int getInput(std::string nubName);
void printNumber(int number);

int main()
{
	std::cout << "We need four numbers from you: " << std::endl;
	
	int number1 = getInput("first");
	int number2 = getInput("second");
	int number3 = getInput("third");
	int number4 = getInput("forth");
	printNumber(number1);
	printNumber(number2);
	printNumber(number3);
	printNumber(number4);

	std::ifstream inFile;
	inFile.open("inMeanStd.dat");
	inFile >> number1 >> number2 >> number3 >> number4;
	inFile.close();

	Statscalcr statscalcr;
	float mean = statscalcr.mean(number1, number2, number3, number4);
	std::cout << "The mean of the numbers is: " << mean << std::endl;
		
	std::ofstream outFile;
	outFile.open("output.dat");
	outFile << "The mean of the numbers is: " << mean << std::endl;
	outFile.close();

	std::cout << "You entered: " << number1 << std::endl;

	return 0;
}

int getInput(std::string nubName)
{
	std::cout << "Please enter the " << nubName << "number: ";
	int input;
	std::cin >> input;
	return input;

}
void printNumber(int Number)
{
	std::cout << "You entered: " << Number << std::endl;
}