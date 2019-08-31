# [PPA - Matriz](https://github.com/vitorebatista/ppa-c-matrix/)

## Objetivo
Implementar funções no arquivo `matrizv3.c` para manipular matrizes de inteiro em C.

## Como executar

Faça a chamada do comando `make`, gerando o seguinte resultado:
```
$ make


####### Exemplo de Execução #######
./main 
./mainEx01 mat_a3x4.example mat_b4x3.example
```

Agora faça a chamada do rotina `.\main`:

```
$ ./main

malocar =[10,10]
        (0)     (1)     (2)     (3)     (4)     (5)     (6)     (7)     (8)     (9)
(0)      0       0       0       0       0       0       0       0       0       0
(1)      0       0       0       0       0       0       0       0       0       0
(2)      0       0       0       0       0       0       0       0       0       0
(3)      0       0       0       0       0       0       0       0       0       0
(4)      0       0       0       0       0       0       0       0       0       0
(5)      0       0       0       0       0       0       0       0       0       0
(6)      0       0       0       0       0       0       0       0       0       0
(7)      0       0       0       0       0       0       0       0       0       0
(8)      0       0       0       0       0       0       0       0       0       0
(9)      0       0       0       0       0       0       0       0       0       0


        (0)     (1)     (2)     (3)     (4)     (5)     (6)     (7)     (8)     (9)
(0)      0       0       0       0       0       0       0       0       0       0
(1)      0       0       0       0       0       0       0       0       0       0
(2)      0       0       0       0       0       0       0       0       0       0
(3)      0       0       0       0       0       0       0       0       0       0
(4)      0       0       0       0       0       0       0       0       0       0
(5)      0       0       0       0       0       0       0       0       0       0
(6)      0       0       0       0       0       0       0       0       0       0
(7)      0       0       0       0       0       0       0       0       0       0
(8)      0       0       0       0       0       0       0       0       0       0
(9)      0       0       0       0       0       0       0       0       0       0


        (0)     (1)     (2)     (3)     (4)     (5)     (6)     (7)     (8)     (9)
(0)      88      78      83      39      83      54      78      61      11      65
(1)      55      65      63      27      21      38      14      72      76      77
(2)      44      41      83      3       53      46      0       53      36      13
(3)      91      25      44      74      64      79      28      95      40      91
(4)      60      95      56      75      74      29      13      88      53      89
(5)      18      97      31      53      53      84      0       53      90      36
(6)      19      81      61      63      7       78      42      88      73      83
(7)      31      33      30      88      9       57      69      74      45      23
(8)      64      15      72      95      69      25      31      69      31      73
(9)      57      50      54      19      65      14      97      59      2       70


```

Para executar o valgrind e verificar inconsistências executar o comando abaixo:
```
$ valgrind ./main
==7494== Memcheck, a memory error detector
==7494== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==7494== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==7494== Command: ./main
==7494== 
...
...
...
...

==7494== 
==7494== HEAP SUMMARY:
==7494==     in use at exit: 0 bytes in 0 blocks
==7494==   total heap usage: 12 allocs, 12 frees, 1,504 bytes allocated
==7494== 
==7494== All heap blocks were freed -- no leaks are possible
==7494== 
==7494== For counts of detected and suppressed errors, rerun with: -v
==7494== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```


Agora para executar o programa `./mainExe01`:

```
$ ./mainEx01 mat_a3x4.example mat_b4x3.example

malocar =[3,4]

malocar =[4,3]

 ##### Comparação dos resultados das matrizes #####
[mat_a vs mat_b]
O elemento [0,0] é diferente nas matrizes analisadas!
Os valores são 1 e 3
```


Para executar o valgrind deste programa:
```
$ valgrind ./mainEx01 mat_a3x4.example mat_b4x3.example
==7609== Memcheck, a memory error detector
==7609== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==7609== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==7609== Command: ./mainEx01 mat_a3x4.example mat_b4x3.example
==7609== 

malocar =[3,4]

malocar =[4,3]

 ##### Comparação dos resultados das matrizes #####
[mat_a vs mat_b]
O elemento [0,0] é diferente nas matrizes analisadas!
Os valores são 1 e 3
==7609== 
==7609== HEAP SUMMARY:
==7609==     in use at exit: 0 bytes in 0 blocks
==7609==   total heap usage: 70 allocs, 70 frees, 11,301 bytes allocated
==7609== 
==7609== All heap blocks were freed -- no leaks are possible
==7609== 
==7609== For counts of detected and suppressed errors, rerun with: -v
==7609== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```
```
