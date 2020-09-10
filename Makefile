PROJ = driver.out
CXX  = g++
CXXFLAGS = -g -ansi -Wall -std=c++11
OBJS = Driver.o Manager.o Store.o Orders.o Order.o Food.o

$(PROJ): $(OBJS) 
	$(CXX) $(CXXFLAGS) -o $(PROJ) $(OBJS)

Driver.o: Driver.cpp Manager.h
	$(CXX) $(CXXFLAGS) -c $<
Manager.o: Manager.cpp Manager.h
	$(CXX) $(CXXFLAGS) -c $<
Store.o: Store.cpp Store.h
	$(CXX) $(CXXFLAGS) -c $<
Orders.o: Orders.cpp Orders.h
	$(CXX) $(CXXFLAGS) -c $<
Order.o: Order.cpp Order.h
	$(CXX) $(CXXFLAGS) -c $<
Food.o: Food.cpp Food.h
	$(CXX) $(CXXFLAGS) -c $<



# -f removes any error messages if the file is not present
.PHONY: clean run valgrind
clean:
	rm -rf *.o
	rm -f *.out
	
run:
	./$(PROJ) $(var1) $(var2)
	
valgrind:
	valgrind ./$(PROJ)

