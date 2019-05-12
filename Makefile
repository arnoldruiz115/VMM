VMM: main.o MMU.o PCB.o BackingStore.o PCB.o RAM.o PageReplacementAlg.o
	g++ -o VMManager main.o MMU.o PCB.o BackingStore.o PCB.o RAM.o PageReplacementAlg.o

clean:
	-rm VMManager main.o MMU.o PageReplacementAlg.o PCB.o BackingStore.o RAM.o
