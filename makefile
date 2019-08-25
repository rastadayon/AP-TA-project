a.out: main.o interface.o angryKid.o cowardKid.o exception.o kid.o madHouse.o peacefulKid.o yard.o brick.o wall.o
	g++ main.o interface.o angryKid.o cowardKid.o exception.o kid.o madHouse.o peacefulKid.o yard.o brick.o wall.o -std=c++11

main.o: main.cpp
	g++ -c main.cpp -std=c++11

interface.o: interface.cpp
	g++ -c interface.cpp -std=c++11

angryKid.o: angryKid.cpp
	g++ -c angryKid.cpp -std=c++11

cowardKid.o: cowardKid.cpp
	g++ -c cowardKid.cpp -std=c++11

exception.o: exception.cpp
	g++ -c exception.cpp -std=c++11

kid.o: kid.cpp
	g++ -c kid.cpp -std=c++11

madHouse.o: madHouse.cpp
	g++ -c madHouse.cpp -std=c++11

peacefulKid.o: peacefulKid.cpp
	g++ -c peacefulKid.cpp -std=c++11

yard.o: yard.cpp
	g++ -c yard.cpp -std=c++11

brick.o: brick.cpp
	g++ -c brick.cpp -std=c++11

wall.o: wall.cpp
	g++ -c wall.cpp -std=c++11

clean:
	rm *.o a.out
