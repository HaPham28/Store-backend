/*
 * Orders.h
 *
 *  Created on: Oct 16, 2019
 *      Author: Ha V. Pham
 */

#ifndef ORDERS_H_
#define ORDERS_H_

#include <fstream>
#include "Food.h"
#include "Order.h"
#include <sstream>

FOOD_TYPE ConvertType(string str);
class Orders {
	queue <Order*> m_ordersUnfilled;
	queue <Order*> m_ordersCompleted;
	Order* m_pCurrentOrder;
public:
	queue <Order*> dump;
	Orders();
	void addOrder(Order* order);
	void completeOrder();
	Order* getCurrentOrder();
	int getSize();
	int getSizeofFilled();
	int getSizeofNotFilled();
	void loadOrders(string filename);
	void printOrders(ofstream & os);
};



#endif /* ORDERS_H_ */
