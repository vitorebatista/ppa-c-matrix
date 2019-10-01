# GNU Makefile
# Revisão: ago/2019

CC = gcc
CCFLAGS = -Wall -O3
LDFLAGS =
TARGET = main gmat mainEx01 mainEx02 mainEx03 help

all: $(TARGET)

%.o: %.c
	$(CC) $(CCFLAGS) -c $<

%: %.o
	$(CC) $(LDFLAGS) $^ -o $@

main: main.c matrizv3.o toolsv3.o
			$(CC) $(CCFLAGS) matrizv3.o toolsv3.o main.c -o $@ $(LDFLAGS)

mainEx01: mainEx01.c matrizv3.o toolsv3.o
			$(CC) $(CCFLAGS) matrizv3.o toolsv3.o mainEx01.c -o $@ $(LDFLAGS)


mainEx02: mainEx02.c matrizv3.o toolsv3.o matriz-operacoesv3.o
		$(CC) $(CCFLAGS) matriz-operacoesv3.o matrizv3.o toolsv3.o mainEx02.c -o $@ $(LDFLAGS)

mainEx03: mainEx03.c matrizv3.o toolsv3.o matriz-operacoesv3.o
		$(CC) $(CCFLAGS) matriz-operacoesv3.o matrizv3.o toolsv3.o mainEx03.c -o $@ $(LDFLAGS)

gmat: matrizv3.o toolsv3.o gera_matrizv3.c
		$(CC) $(CCFLAGS) matrizv3.o toolsv3.o gera_matrizv3.c -o $@ $(LDFLAGS)

help:
	@echo
	@echo
	@echo "####### Exemplo de Execução #######"
	@echo "./main "
	@echo "./mainEx01 mat_a3x4.example mat_b4x3.example"
	@echo "./gmat 5 5 && ./mainEx02 5x5-mat.map 5x5-mat.map"
	@echo "./gmat 5 5 && ./mainEx03 5x5-mat.map 5x5-mat.map"

clean:
	rm -f *.o *~ $(TARGET) *.map *.result
