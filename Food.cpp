/*
 * Food.cpp
 *
 *  Created on: Oct 16, 2019
 *      Author: Ha V. Pham
 */

#include "Food.h"

//Food::Food(FOOD_TYPE type): m_sName(""), m_eType(type), m_dCost(0) {};
Food::Food(string name, double cost, FOOD_TYPE type): m_sName(name), m_eType(type), m_dCost(cost) {};
FOOD_TYPE Food::getType() {
	return m_eType;
}
string Food::getName() {
	return m_sName;
}
double Food::getCost() {
	return m_dCost;
}
void Food::printFood(ofstream & os) {
	os << m_sName << " $" << m_dCost << endl;
}

