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
Agora para executar o programa `./mainExe01` primeiramente precisamos criar um arquivo para realizar a somatório e multiplicação:

```sh
$ ./gmat 5 5

malocar =[5,5]
        (0)     (1)     (2)     (3)     (4)
(0)      63      99      22      75      73
(1)      72      12      54      78      97
(2)      45      50      32      32      35
(3)      2       59      94      79      75
(4)      48      72      10      12      18


                **** PRINT mat_c NxM(5,5) **** 
#####
 Arquivo com a matriz gerada (5x5-mat.map).
#####

malocar =[5,5]
        (0)     (1)     (2)     (3)     (4)
(0)      63      99      22      75      73
(1)      72      12      54      78      97
(2)      45      50      32      32      35
(3)      2       59      94      79      75
(4)      48      72      10      12      18


##### Arquivo 5x5-mat.map: VERIFICADO! #####
```

Agora realize a chamada do `mainEx02` passando como parâmetro o arquivo gerado:

```sh
$ ./mainEx02 10x10-mat.map 10x10-mat.map 

malocar =[10,10]

malocar =[10,10]

 ##### somar_t0 de Matrizes #####

malocar =[10,10]
        (0)     (1)     (2)     (3)     (4)     (5)     (6)     (7)     (8)     (9)
(0)      8       44      152     176     56      134     60      114     82      186
(1)      34      160     28      126     98      188     168     134     102     108
(2)      132     190     152     142     144     40      18      88      80      76
(3)      50      88      24      2       66      80      42      30      98      28
(4)      16      132     190     44      58      88      138     28      126     144
(5)      136     58      38      192     2       86      34      124     176     114
(6)      104     130     108     128     134     78      112     80      108     10
(7)      108     28      46      2       176     10      194     114     142     120
(8)      162     78      84      0       174     190     88      112     114     168
(9)      132     122     98      144     50      136     22      162     16      34


        Runtime: 0.000017

 ##### somar_t1 de Matrizes #####

malocar =[10,10]
        (0)     (1)     (2)     (3)     (4)     (5)     (6)     (7)     (8)     (9)
(0)      8       44      152     176     56      134     60      114     82      186
(1)      34      160     28      126     98      188     168     134     102     108
(2)      132     190     152     142     144     40      18      88      80      76
(3)      50      88      24      2       66      80      42      30      98      28
(4)      16      132     190     44      58      88      138     28      126     144
(5)      136     58      38      192     2       86      34      124     176     114
(6)      104     130     108     128     134     78      112     80      108     10
(7)      108     28      46      2       176     10      194     114     142     120
(8)      162     78      84      0       174     190     88      112     114     168
(9)      132     122     98      144     50      136     22      162     16      34


        Runtime: 0.000017

%%%%%%%%

 ##### multiplicar_t0 de Matrizes #####

malocar =[10,10]
lin 10 col 10
        (0)     (1)     (2)     (3)     (4)     (5)     (6)     (7)     (8)     (9)
(0)      26483   26751   20587   22943   23363   23163   17607   25190   25046   20110
(1)      26392   28517   21538   27026   26309   29785   27699   28813   32415   25843
(2)      19198   29807   25234   24120   25331   28695   24393   24970   26560   28165
(3)      11444   12932   11558   12758   12090   15764   12473   13431   14501   15186
(4)      25397   30169   22829   26105   25045   26330   18636   25440   23158   20523
(5)      22473   20040   17915   18660   23609   26604   18928   24534   24370   24645
(6)      19441   26454   23297   21771   24718   25713   23583   21960   27378   25642
(7)      20874   24022   26986   20269   25636   24414   23926   22550   23693   24176
(8)      26388   28380   30138   32521   24756   30969   25030   31134   31104   32710
(9)      17875   20975   17751   22289   20520   20790   20950   22533   25801   23854


        Runtime: 0.000025

 ##### multiplicar_t1 de Matrizes #####

malocar =[10,10]
lin 10 col 10
        (0)     (1)     (2)     (3)     (4)     (5)     (6)     (7)     (8)     (9)
(0)      26483   26751   20587   22943   23363   23163   17607   25190   25046   20110
(1)      26392   28517   21538   27026   26309   29785   27699   28813   32415   25843
(2)      19198   29807   25234   24120   25331   28695   24393   24970   26560   28165
(3)      11444   12932   11558   12758   12090   15764   12473   13431   14501   15186
(4)      25397   30169   22829   26105   25045   26330   18636   25440   23158   20523
(5)      22473   20040   17915   18660   23609   26604   18928   24534   24370   24645
(6)      19441   26454   23297   21771   24718   25713   23583   21960   27378   25642
(7)      20874   24022   26986   20269   25636   24414   23926   22550   23693   24176
(8)      26388   28380   30138   32521   24756   30969   25030   31134   31104   32710
(9)      17875   20975   17751   22289   20520   20790   20950   22533   25801   23854


        Runtime: 0.000026

 ##### multiplicar_t2 de Matrizes #####

malocar =[10,10]
lin 10 col 10
        (0)     (1)     (2)     (3)     (4)     (5)     (6)     (7)     (8)     (9)
(0)      26483   26751   20587   22943   23363   23163   17607   25190   25046   20110
(1)      26392   28517   21538   27026   26309   29785   27699   28813   32415   25843
(2)      19198   29807   25234   24120   25331   28695   24393   24970   26560   28165
(3)      11444   12932   11558   12758   12090   15764   12473   13431   14501   15186
(4)      25397   30169   22829   26105   25045   26330   18636   25440   23158   20523
(5)      22473   20040   17915   18660   23609   26604   18928   24534   24370   24645
(6)      19441   26454   23297   21771   24718   25713   23583   21960   27378   25642
(7)      20874   24022   26986   20269   25636   24414   23926   22550   23693   24176
(8)      26388   28380   30138   32521   24756   30969   25030   31134   31104   32710
(9)      17875   20975   17751   22289   20520   20790   20950   22533   25801   23854


        Runtime: 0.000025

 ##### multiplicar_t3 de Matrizes #####

malocar =[10,10]
lin 10 col 10
        (0)     (1)     (2)     (3)     (4)     (5)     (6)     (7)     (8)     (9)
(0)      26483   26751   20587   22943   23363   23163   17607   25190   25046   20110
(1)      26392   28517   21538   27026   26309   29785   27699   28813   32415   25843
(2)      19198   29807   25234   24120   25331   28695   24393   24970   26560   28165
(3)      11444   12932   11558   12758   12090   15764   12473   13431   14501   15186
(4)      25397   30169   22829   26105   25045   26330   18636   25440   23158   20523
(5)      22473   20040   17915   18660   23609   26604   18928   24534   24370   24645
(6)      19441   26454   23297   21771   24718   25713   23583   21960   27378   25642
(7)      20874   24022   26986   20269   25636   24414   23926   22550   23693   24176
(8)      26388   28380   30138   32521   24756   30969   25030   31134   31104   32710
(9)      17875   20975   17751   22289   20520   20790   20950   22533   25801   23854


        Runtime: 0.000049

 ##### multiplicar_t4 de Matrizes #####

malocar =[10,10]
lin 10 col 10
        (0)     (1)     (2)     (3)     (4)     (5)     (6)     (7)     (8)     (9)
(0)      26483   26751   20587   22943   23363   23163   17607   25190   25046   20110
(1)      26392   28517   21538   27026   26309   29785   27699   28813   32415   25843
(2)      19198   29807   25234   24120   25331   28695   24393   24970   26560   28165
(3)      11444   12932   11558   12758   12090   15764   12473   13431   14501   15186
(4)      25397   30169   22829   26105   25045   26330   18636   25440   23158   20523
(5)      22473   20040   17915   18660   23609   26604   18928   24534   24370   24645
(6)      19441   26454   23297   21771   24718   25713   23583   21960   27378   25642
(7)      20874   24022   26986   20269   25636   24414   23926   22550   23693   24176
(8)      26388   28380   30138   32521   24756   30969   25030   31134   31104   32710
(9)      17875   20975   17751   22289   20520   20790   20950   22533   25801   23854


        Runtime: 0.000023

 ##### multiplicar_t5 de Matrizes #####

malocar =[10,10]
lin 10 col 10
        (0)     (1)     (2)     (3)     (4)     (5)     (6)     (7)     (8)     (9)
(0)      26483   26751   20587   22943   23363   23163   17607   25190   25046   20110
(1)      26392   28517   21538   27026   26309   29785   27699   28813   32415   25843
(2)      19198   29807   25234   24120   25331   28695   24393   24970   26560   28165
(3)      11444   12932   11558   12758   12090   15764   12473   13431   14501   15186
(4)      25397   30169   22829   26105   25045   26330   18636   25440   23158   20523
(5)      22473   20040   17915   18660   23609   26604   18928   24534   24370   24645
(6)      19441   26454   23297   21771   24718   25713   23583   21960   27378   25642
(7)      20874   24022   26986   20269   25636   24414   23926   22550   23693   24176
(8)      26388   28380   30138   32521   24756   30969   25030   31134   31104   32710
(9)      17875   20975   17751   22289   20520   20790   20950   22533   25801   23854


        Runtime: 0.000025

 ##### Comparação dos resultados da adição de matrizes #####
[soma_t0 vs soma_t1]
Matrizes são idênticas!! :)
Tempo de processamento: 0.000001

 ##### Comparação dos resultados da Multiplicação de matrizes #####
[mult_t0 vs mult_t1]
Matrizes são idênticas!! :)
Tempo de processamento: 0.000000
[mult_t0 vs mult_t2]
Matrizes são idênticas!! :)
Tempo de processamento: 0.000000
[mult_t0 vs mult_t3]
Matrizes são idênticas!! :)
Tempo de processamento: 0.000000
[mult_t0 vs mult_t4]
Matrizes são idênticas!! :)
Tempo de processamento: 0.000000
[mult_t0 vs mult_t5]
Matrizes são idênticas!! :)
Tempo de processamento: 0.000000

```

Para executar o _valgrind_ é só realizar a chamada conforme abaixo:

```sh
$ valgrind ./mainEx02 10x10-mat.map 10x10-mat.map 
==4354== Memcheck, a memory error detector
==4354== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==4354== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==4354== Command: ./mainEx02 10x10-mat.map 10x10-mat.map
==4354== 

...
...
...

==4354== 
==4354== HEAP SUMMARY:
==4354==     in use at exit: 0 bytes in 0 blocks
==4354==   total heap usage: 399 allocs, 399 frees, 58,286 bytes allocated
==4354== 
==4354== All heap blocks were freed -- no leaks are possible
==4354== 
==4354== For counts of detected and suppressed errors, rerun with: -v
==4354== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```