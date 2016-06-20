main: main.o obra.o escultura.o pintura.o literatura.o empleado.o guardia.o conservador.o 
	g++ main.o obra.o escultura.o pintura.o literatura.o empleado.o guardia.o conservador.o -o proyecto -lncurses 
	
main.o:	main.cpp obra.h escultura.h pintura.h literatura.h empleado.h guardia.h conservador.h
	g++ -c main.cpp --std=c++11 

obra.o:		obra.cpp obra.h
	g++ -c obra.cpp 

escultura.o:	escultura.cpp escultura.h obra.h
	g++ -c escultura.cpp

pintura.o:	pintura.cpp pintura.h obra.h
	g++ -c pintura.cpp

literatura.o:	literatura.cpp literatura.h obra.h
	g++ -c literatura.cpp

empleado.o:	empleado.cpp empleado.h
	g++ -c empleado.cpp

guardia.o:	guardia.cpp guardia.h empleado.h
	g++ -c guardia.cpp

conservador.o:	conservador.cpp conservador.h empleado.h
	g++ -c conservador.cpp
