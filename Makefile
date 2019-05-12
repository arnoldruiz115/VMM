VMM: main.o MMU.o address.o PCB.o BackingStore.o PCB.o RAM.o
	g++ -o main.exe main.o MMU.o address.o PCB.o BackingStore.o PCB.o RAM.o

clean:
	-rm main.exe main.o MMU.o address.o PCB.o BackingStore.o RAM.o
