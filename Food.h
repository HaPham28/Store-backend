/*
 * Food.h
 *
 *  Created on: Oct 16, 2019
 *      Author: Ha V. Pham
 */

#ifndef FOOD_H_
#define FOOD_H_

#include <iostream>
#include <fstream>
#include <string>

using namespace std;


enum FOOD_TYPE {Sweet, Starch, Meat, Vegetable, Fruit};

class Food {
	string m_sName;
	FOOD_TYPE m_eType;
	double m_dCost;
public:
	//Food(FOOD_TYPE type);
	Food(string name, double cost, FOOD_TYPE type);
	FOOD_TYPE getType();
	double getCost();
	string getName();
	void printFood(ofstream & os);
};



#endif /* FOOD_H_ */
