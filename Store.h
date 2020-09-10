/*
 * Store.h
 *
 *  Created on: Oct 16, 2019
 *      Author: Ha V. Pham
 */

#ifndef STORE_H_
#define STORE_H_

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <stack>
#include <vector>
#include "Food.h"

FOOD_TYPE Convert(string str);
class Store {
	vector<stack<Food*>> m_bins;
	stack<Food*> SWEET;
	stack<Food*> STARCH;
	stack<Food*> MEAT;
	stack<Food*> VEGETABLE;
	stack<Food*> FRUIT;
public:
	Store();
	void addFood(Food* food);
	Food* getFoodByType(FOOD_TYPE type);
	void stockStore(string filename);
	void printStore(ofstream & os);
};



#endif /* STORE_H_ */
