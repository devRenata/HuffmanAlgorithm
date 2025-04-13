# Algoritmo de Huffman para Compressão de Texto

Este repositório contém uma implementação do algoritmo de Huffman em C, desenvolvido como parte da disciplina de Laboratório II na Universidade Federal de Santa Maria - UFSM. O projeto teve como objetivo principal o aprendizado prático de alocação dinâmica de memória e aplicação de estruturas de dados.

### Sobre o Algoritmo de Huffman

O algoritmo de Huffman é um método eficiente de compressão de dados que utiliza codificação de tamanho variável. Ele atribui códigos menores aos caracteres que aparecem com maior frequência no texto e códigos maiores aos menos frequentes, resultando em uma representação compacta dos dados.

### Funcionalidades Implementadas

1. Contagem de frequência de caracteres: analisa o texto de entrada e conta quantas vezes cada caractere aparece.
2. Criação e ordenação de símbolos: organiza os caracteres por frequência de ocorrência.
3. Atribuição de bits: gera códigos binários ótimos para cada caractere baseado em sua frequência.
4. Codificação do texto: transforma o texto original em sua versão compactada usando os códigos gerados.

### Aprendizados

Este projeto me proporcionou:
- Prática com alocação dinâmica de memória em C (malloc, free).
- Manipulação de estruturas de dados complexas.
- Implementação de algoritmos de ordenação (Bubble Sort).

### Como compilar e executar

```c
gcc main.c -o main
```

### Exemplo de saída

```c
f (2): 0
m (2): 10
H (1): 110
a (1): 1110
  (1): 11110
g (1): 111110
h (1): 1111110
i (1): 11111110
l (1): 111111110
A (1): 1111111110
n (1): 11111111110
o (1): 111111111110
r (1): 1111111111110
t (1): 11111111111110
u (1): 111111111111110

String original: Huffman Algorithm
String codificada: 110111111111111110001011101111111111011110111111111011111111011111011111111111011111111111101111111011111111111110111111010

```
