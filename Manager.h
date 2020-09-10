/*
 * Manager.h
 *
 *  Created on: Oct 16, 2019
 *      Author: Ha V. Pham
 */

#ifndef MANAGER_H_
#define MANAGER_H_

#include "Store.h"
#include "Orders.h"

class Manager {
	Store m_store;
	Orders m_orders;
public:
	Manager(string a, string b);
	void createStore(string filename);
	void createOrders(string filename);
	void fillOrders(ofstream & os);
	void printStatus(ofstream & os);
};



#endif /* MANAGER_H_ */
