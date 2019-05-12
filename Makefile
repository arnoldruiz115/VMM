VMM: main.o MMU.o address.o PCB.o BackingStore.o
	g++ -o main.exe main.o MMU.o address.o PCB.o BackingStore.o 

clean:
	-rm main.exe main.o MMU.o address.o PCB.o BackingStore.o
