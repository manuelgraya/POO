all: pruebafecha

fecha.o: fecha.cpp fecha.hpp
	c++ -c fecha.cpp

mainfecha.o: mainfecha.cpp fecha.hpp
	c++ -c mainfecha.cpp

pruebafecha: fecha.o mainfecha.o
	c++ -o pruebafecha fecha.o mainfecha.o

clean:
	del *.exe *.o