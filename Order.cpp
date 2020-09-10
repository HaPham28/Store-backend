/*
 * Order.cpp
 *
 *  Created on: Oct 16, 2019
 *      Author: Ha V. Pham
 */
#include "order.h"
string String(FOOD_TYPE type) {
	if ( type == Sweet) {
			return "Sweet";
	}
	else if (type == Starch) {
		return "Starch";
	}
	else if (type == Meat) {
		return "Meat";
	}
	else if (type == Vegetable) {
		return "Vegetable";
	}
	else {
		return "Fruit";
	}
}
Order::Order(string name, bool partial): m_sCustomerName(name),m_bAcceptsPartialOrder(partial), m_bOrderCompleted(false) {};

void Order::setCustomerName(string name) {
	m_sCustomerName = name;
}
void Order::setAcceptPartial(bool x) {
	m_bAcceptsPartialOrder = x;
}
void Order::setOrderComplete() {
	m_bOrderCompleted = true;
}
bool Order::isAcceptPartial() {
	return m_bAcceptsPartialOrder;
}

FOOD_TYPE Order::getNextRequest() {

	return m_requests.front();
}
size_t Order::getSize() {
	return m_requests.size();
}
size_t Order::getSizeofFilled() {
	return m_filledRequests.size();
}
size_t Order::getSizeofNotFilled() {
	return m_notfilledRequests.size();
}
string Order::getCustomerName() {
	return m_sCustomerName;
}
void Order::setdump() {
	dump=m_requests;
}
void Order::addRequestToOrder(FOOD_TYPE type) {
	m_requests.push(type);
}
void Order::addNotfilledRequest(FOOD_TYPE type, bool popR) {
	m_notfilledRequests.push(type);
	if (popR == true) {
		m_requests.pop();
	}
}
void Order::addFoodToOrder(Food* food) {
	m_filledRequests.push(food);
	m_requests.pop(); //?????????
}
Food* Order::popFoodFromOrder() {
	Food* temp = m_filledRequests.front();
	m_filledRequests.pop();
	return temp;
}

void Order::printOrder(ofstream & os) {
	double sum = 0;
	Food* f = nullptr;
	os << m_sCustomerName;

	//if order is not complete
	if (m_requests.size() != 0) {
		os << endl;
		os << "Requests:";
		this->setdump();
		while ( this->dump.size() != 0) {
			os << " " << String(this->dump.front());
			this->dump.pop();
		}
		os << endl;
		os << "-----" << endl;
	}

	else if ( m_notfilledRequests.size() != 0) {
		//if order is partially completed
		if (m_bAcceptsPartialOrder == true) {
			os << " (Partial)" << endl;
			os << "Unfilled Requests:";
			while (m_notfilledRequests.size() != 0) {
				os << " " << String(m_notfilledRequests.front());
				m_notfilledRequests.pop();
			}
			os << endl;
			os << "Items:" << endl;
			while (m_filledRequests.size() != 0) {
				f = this->popFoodFromOrder();
				f->printFood(os);
				sum += f->getCost();
			}
			os << "***Total: $" << sum << endl;
			os << "-----" << endl;

		//if order is not completed because not accept partial
		} else {
			os << " - Unable to complete order" << endl;
			os << "Unfilled Requests:";
			while (m_notfilledRequests.size() != 0) {
				os << " " << String(m_notfilledRequests.front());
				m_notfilledRequests.pop();
			}
			os << endl;
			os << "-----" << endl;
		}
	}

	//if order is completed with all items requested
	else {
		os << endl;
		os << "Items:" << endl;
		while (m_filledRequests.size() != 0) {
			f = this->popFoodFromOrder();
			f->printFood(os);
			sum += f->getCost();
		}
		os << "***Total: $" << sum << endl;

		os << "-----" <<endl;
	}
}

