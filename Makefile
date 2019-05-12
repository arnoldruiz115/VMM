VMM: main.o MMU.o PCB.o BackingStore.o PCB.o RAM.o PageReplacementAlg.o
	g++ -o main.exe main.o MMU.o PCB.o BackingStore.o PCB.o RAM.o PageReplacementAlg.o

clean:
	-rm main.exe main.o MMU.o PageReplacementAlg.o PCB.o BackingStore.o RAM.o
