OPCIONS = -D_JUDGE_ -D_GLIBCXX_DEBUG -O2 -Wall -Werror -Wextra -Wno-sign-compare -std=c++11

program.exe: program.o Conjunto_alfabetos.o Conjunto_mensajes.o Mensaje.o Alfabeto.o 
	g++ -o program.exe program.o Conjunto_alfabetos.o Conjunto_mensajes.o Mensaje.o Alfabeto.o 

Alfabeto.o: Alfabeto.cc Alfabeto.hh 
	g++ -c Alfabeto.cc $(OPCIONS)

Mensaje.o: Mensaje.cc Mensaje.hh Conjunto_alfabetos.cc Conjunto_alfabetos.hh Alfabeto.cc Alfabeto.hh 
	g++ -c Mensaje.cc $(OPCIONS) 

Conjunto_mensajes.o: Conjunto_mensajes.cc Conjunto_mensajes.hh Mensaje.cc Mensaje.hh Conjunto_alfabetos.cc Conjunto_alfabetos.hh 
	g++ -c Conjunto_mensajes.cc $(OPCIONS)
	
Conjunto_alfabetos.o: Conjunto_alfabetos.cc Conjunto_alfabetos.hh 
	g++ -c Conjunto_alfabetos.cc $(OPCIONS) 


program.o: program.cc Conjunto_mensajes.hh Conjunto_alfabetos.hh
	g++ -c program.cc $(OPCIONS) 

tar: program.cc Alfabeto.hh Alfabeto.cc Conjunto_alfabetos.cc Conjunto_alfabetos.hh Conjunto_mensajes.hh Conjunto_mensajes.cc Mensaje.cc Mensaje.hh Makefile
	tar -cvf practica.tar program.cc Alfabeto.hh Alfabeto.cc Conjunto_alfabetos.cc Conjunto_alfabetos.hh Conjunto_mensajes.hh Conjunto_mensajes.cc Mensaje.cc Mensaje.hh Makefile
	
clean:
	rm *.o
	rm *.exe 