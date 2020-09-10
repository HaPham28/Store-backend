/*
 * Manager.cpp
 *
 *  Created on: Oct 16, 2019
 *      Author: Ha V. Pham
 */
#include "Manager.h"

Manager::Manager(string a, string b) {
	this->createStore(a);
	this->createOrders(b);
}
void Manager::createStore(string filename){
	m_store.stockStore(filename);
}
void Manager::createOrders(string filename){
	m_orders.loadOrders(filename);
}
void Manager::fillOrders(ofstream & os){
	while (m_orders.getSize() != 0) { //orders
		Order* current = m_orders.getCurrentOrder();

		bool stop=false;
		while (stop == false && current->getSize() != 0) { //order
			FOOD_TYPE currentType = current->getNextRequest();

			Food* food = m_store.getFoodByType(currentType);
			if (food != nullptr) {//store has food
				current->addFoodToOrder(food);
			}

			else {//store do not have food
				if (current->isAcceptPartial() == false) {
					while (current->getSize() != 0) { //remember the requests that are not filled
						current->addNotfilledRequest(currentType, true);
						currentType = current->getNextRequest();
					}
						while (current->getSizeofFilled() != 0) {//return food because not get and remember the ones returned
							Food* popFood = current->popFoodFromOrder();
							m_store.addFood(popFood);
							current->addNotfilledRequest(popFood->getType(), false);
						}
					stop=true;
					break;
				}
				else current->addNotfilledRequest(currentType, true);
			}

		}
		if (stop == false) {
			current->setOrderComplete();
		}
		m_orders.completeOrder();
	}
}
void Manager::printStatus(ofstream & os) {
	m_store.printStore(os);
	m_orders.printOrders(os);
}
