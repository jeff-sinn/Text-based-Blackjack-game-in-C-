readwrite.o: readwrite.cpp readwrite.h
	g++ -c readwrite.cpp
specialcase.o: specialcase.cpp specialcase.h
	g++ -c specialcase.cpp
bjmain.o: bjmain.cpp readwrite.h specialcase.h
	g++ -c bjmain.cpp
bjmain: readwrite.o specialcase.o bjmain.o
	g++ readwrite.o specialcase.o bjmain.o -o bjmain
