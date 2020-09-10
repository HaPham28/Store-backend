/*
 * Store.cpp
 *
 *  Created on: Oct 16, 2019
 *      Author: Ha V. Pham
 */
#include "Store.h"
#include <clocale>

FOOD_TYPE Convert(string str) {
	if (str == "sweet") {
		return Sweet;
	}
	else if (str == "starch") {
		return Starch;
	}
	else if (str == "meat") {
		return Meat;
	}
	else if (str == "vegetable") {
		return Vegetable;
	}
	else return Fruit;
}
Store::Store() {
}

void Store::addFood(Food* food) {
	if (food->getType() == Sweet) {
		//m_bins.at(0).push(food);
		return SWEET.push(food);
	} else if (food->getType() == Starch) {
		//m_bins.at(1).push(food);
		return STARCH.push(food);
	} else if (food->getType() == Meat) {
		//m_bins.at(2).push(food);
		return MEAT.push(food);
	} else if (food->getType() == Vegetable) {
		//m_bins.at(3).push(food);
		return VEGETABLE.push(food);
	} else {
		//m_bins.at(4).push(food);
		return FRUIT.push(food);
	}
}
Food* Store::getFoodByType(FOOD_TYPE type) {

	Food* t = nullptr;

	if (type == Sweet) {
		if (SWEET.size() == 0) {


			return nullptr;
		}
		t = SWEET.top();
		SWEET.pop();
		return t;

	} else if (type == Starch) {

		if (STARCH.size() == 0) {
			return nullptr;
		}
		t = STARCH.top();
		STARCH.pop();
		return t;

	} else if (type == Meat) {

		if (MEAT.size() == 0) {
			return nullptr;
		}

		t = MEAT.top();
		MEAT.pop();
		return t;

	} else if (type == Vegetable) {
		if (VEGETABLE.size() == 0) {
			return nullptr;
		}

		t = VEGETABLE.top();
		VEGETABLE.pop();
		return t;

	} else {
		if (FRUIT.size() == 0) {
			return nullptr;
		}
		t = FRUIT.top();
		FRUIT.pop();
		return t;
	}
}
void Store::stockStore(string filename) {
	string line, name, food, cost;
	ifstream file;
	file.open(filename);
	if (!file.is_open()) {
		cout << "Cannot open file" <<endl;
	}
	while (!file.eof()) {


		getline(file, line);

		int begin = line.find_first_of("\"");
		int end = line.find_last_of("\"");
		name = line.substr(begin+1, end-1);
		line.erase(begin, end+1);


		stringstream ss;
		ss << line;
		ss >> food;
		ss >> cost;
		double c = stod(cost);
		FOOD_TYPE type = Convert(food);

		this->addFood(new Food(name,c,type));
	}
}
void Store::printStore(ofstream & os) {
	stack<Food*> Sw,St,M,V,F;
	m_bins.push_back(Sw);
	m_bins.push_back(St);
	m_bins.push_back(M);
	m_bins.push_back(V);
	m_bins.push_back(F);
	m_bins.at(0) = STARCH;
	m_bins.at(1) = SWEET;
	m_bins.at(2) = MEAT;
	m_bins.at(3) = VEGETABLE;
	m_bins.at(4) = FRUIT;

	os << "---------- Store ----------" << endl;

	//print Meat
	os << "Meat: " << m_bins.at(2).size();
	if (m_bins.at(2).size() != 0) {
	while (m_bins.at(2).size() > 1) {
		Food* f = m_bins.at(2).top();
		os << " " << f->getName() << ",";
		m_bins.at(2).pop();
	}
	Food* f = m_bins.at(2).top();
	os << " " << f->getName();
	m_bins.at(2).pop();
	}
	os << endl;

	//print Fruit
	os << "Fruit: " << m_bins.at(4).size();
	if (m_bins.at(4).size() != 0) {
	while (m_bins.at(4).size() > 1) {
		Food* f = m_bins.at(4).top();
		os << " " << f->getName() << ",";
		m_bins.at(4).pop();
	}
	Food* f = m_bins.at(4).top();
	os << " " << f->getName();
	m_bins.at(4).pop();
	}
	os << endl;

	//print vegetable
	os << "Vegetable: " << m_bins.at(3).size();
	if (m_bins.at(3).size() != 0) {
	while (m_bins.at(3).size() > 1) {
		Food* f = m_bins.at(3).top();
		os << " " << f->getName() << ",";
		m_bins.at(3).pop();
	}
	Food* f = m_bins.at(3).top();
	os << " " << f->getName();
	m_bins.at(3).pop();
	}
	os << endl;

	//print starch
	os << "Starch: " << m_bins.at(0).size();
	if (m_bins.at(0).size() != 0) {
	while (m_bins.at(0).size() > 1) {
		Food* f = m_bins.at(0).top();
		os << " " << f->getName() << ",";
		m_bins.at(0).pop();
	}
	Food* f = m_bins.at(0).top();
	os << " " << f->getName();
	m_bins.at(0).pop();
	}
	os << endl;

	//print sweet
	os << "Sweet: " << m_bins.at(1).size();
	if (m_bins.at(1).size() != 0) {
	while (m_bins.at(1).size() > 1) {
		Food* f = m_bins.at(1).top();
		os << " " << f->getName() << ",";
		m_bins.at(1).pop();
	}
	Food* f = m_bins.at(1).top();
	os << " " << f->getName();
	m_bins.at(1).pop();
	}
	os << endl;
}
