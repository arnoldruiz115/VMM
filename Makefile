VMM: main.o MMU.o address.o
	g++ -o main.exe main.o MMU.o address.o

clean:
	-rm main.exe main.o MMU.o address.o
