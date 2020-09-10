/*
 * Order.h
 *
 *  Created on: Oct 16, 2019
 *      Author: Ha V. Pham
 */

#ifndef ORDER_H_
#define ORDER_H_

#include <queue>
#include "food.h"

class Order {
	string m_sCustomerName;
	queue <FOOD_TYPE> m_requests;
	bool m_bAcceptsPartialOrder;
	bool m_bOrderCompleted;
	queue <Food*> m_filledRequests;
	queue <FOOD_TYPE> m_notfilledRequests;
public:
	Order(string name, bool partial);
	queue <FOOD_TYPE> dump;
	void setdump();
	void setCustomerName(string name);
	void setAcceptPartial(bool x);
	void setOrderComplete();
	bool isAcceptPartial();

	FOOD_TYPE getNextRequest();
	size_t getSize();
	size_t getSizeofFilled();
	size_t getSizeofNotFilled();
	string getCustomerName();
	void addNotfilledRequest(FOOD_TYPE type, bool popR);
	void addRequestToOrder(FOOD_TYPE type);
	void addFoodToOrder(Food* food);
	Food* popFoodFromOrder();

	void printOrder(ofstream & os);

};



#endif /* ORDER_H_ */
