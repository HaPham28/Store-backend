/*
 * Driver.cpp
 *
 *  Created on: Oct 16, 2019
 *      Author: Ha V. Pham
 */




#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>

#include "Manager.h"

void printGreeting() {
	cout << "Ha Pham, Section 502" <<endl;
}
int main(int argc, char* argv[]) {
	std::ofstream outputFileStream;

	//print greeting
	printGreeting();
	//take in store and order files
	Manager manager(argv[1], argv[2]);

	//open output file
	outputFileStream.open("results.txt");

	manager.printStatus(outputFileStream);

	manager.fillOrders(outputFileStream);

	manager.printStatus(outputFileStream);

	outputFileStream.close();

	return EXIT_SUCCESS;

}
