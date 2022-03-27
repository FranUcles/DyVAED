a.exe: Dato.o GeneradorCasos.o Comprobador.o Programa.o GeneradorTiempos.o main.o 
	g++ -o ejecutable.exe Dato.o GeneradorCasos.o Comprobador.o Programa.o GeneradorTiempos.o main.o

Dato.o: Dato.cpp Dato.hpp
	g++ -c Dato.cpp

GeneradorCasos.o: GeneradorCasos.cpp GeneradorCasos.hpp 
	g++ -c GeneradorCasos.cpp

Comprobador.o: Comprobador.cpp Comprobador.hpp Dato.hpp
	g++ -c Comprobador.cpp

Programa.o: Programa.cpp Programa.hpp 
	g++ -c Programa.cpp

GeneradorTiempos.o: GeneradorTiempos.cpp GeneradorTiempos.hpp Programa.hpp GeneradorCasos.hpp
	g++ -c GeneradorTiempos.cpp

main.o: main.cpp Comprobador.hpp Dato.hpp Programa.hpp GeneradorTiempos.hpp
	g++ -c main.cpp