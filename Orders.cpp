/*
 * Orders.cpp
 *
 *  Created on: Oct 16, 2019
 *      Author: Ha V. Pham
 */
#include "Orders.h"

FOOD_TYPE ConvertType(string str) {
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
	else {
		return Fruit;
	}
}
Orders::Orders(): m_pCurrentOrder(nullptr) {};
void Orders::addOrder(Order* order) {
	m_ordersUnfilled.push(order);
}
void Orders::completeOrder() {
	m_ordersCompleted.push(m_ordersUnfilled.front());
	m_ordersUnfilled.pop();
}
Order* Orders::getCurrentOrder() {
	return m_ordersUnfilled.front();
}
int Orders::getSize() {
	return m_ordersUnfilled.size();
}
void Orders::loadOrders(string filename) {
	string line, name, partial, food;
	ifstream file;
	stringstream ss;
	bool credit;
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

		ss << line;
		ss >> partial;

		if (partial == "yes") {
			credit = true;
		} else credit = false;

		m_ordersUnfilled.push(new Order(name, credit));

		while (!ss.eof()) {
			ss >> food;
			FOOD_TYPE f = ConvertType(food);
			m_ordersUnfilled.back()->addRequestToOrder(f);
		}
		ss.clear();
	}
}
void Orders::printOrders(ofstream & os) {
	os << "---------- Orders -----------" << endl;
	if (m_ordersCompleted.size() == 0) {
		this->dump = m_ordersUnfilled;
		while (this->dump.size() != 0) {
			this->dump.front() -> printOrder(os);
			this->dump.pop();
		}
	}
	else {
		while (m_ordersCompleted.size() != 0) {
			m_ordersCompleted.front()->printOrder(os);
			m_ordersCompleted.pop();
		}
	}
}



