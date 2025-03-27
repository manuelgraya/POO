all: pruebafecha

fecha.o: fecha.cpp fecha.hpp
	c++ -g -c fecha.cpp

mainfecha.o: mainfecha.cpp fecha.hpp
	c++ -g -c mainfecha.cpp

pruebafecha: fecha.o mainfecha.o
	c++ -o pruebafecha fecha.o mainfecha.o

cadena.o: cadena.cpp cadena.hpp
	c++ -c cadena.cpp

maincadena.o: maincadena.cpp cadena.hpp
	c++ -c maincadena.cpp

pruebacadena: cadena.o maincadena.o
	c++ -o pruebacadena cadena.o maincadena.o

clean:
	del *.exe *.o