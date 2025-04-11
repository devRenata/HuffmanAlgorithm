#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define ASCII_SIZE 256

typedef struct {
    char character;
    int frequency;
    char *code;
} Symbol;

void countFrequence(const char *text, int *frequence);
int createAndSordArrayBySymbol(const char *text, int *frequence);
void assignCodes(Symbol *symbols, int totalNumberOfSymbols);
char* encodeText(const char *text, Symbol *symbols, int totalNumberOfSymbols);

void countFrequence(const char *text, int *frequence) {
    for (int i = 0; text[i] != '\0'; i++) {
        frequence[(unsigned char)text[i]]++;
    }
}

int createAndSortArrayBySymbol(const char *text, int *frequence, Symbol **symbols) {
    // Conta quantos caracteres únicos existem
    int count = 0;
    for (int i = 0; i < ASCII_SIZE; i++) {
        if (frequence[i] > 0) {
            count++;
        }
    }

    // Aloca memória para os símbolos
    *symbols = malloc(count * sizeof(Symbol));
    if (*symbols == NULL) {
        return 0;
    }

    // Preenche o array de símbolos
    int index = 0;
    for (int i = 0; i < ASCII_SIZE; i++) {
        if (frequence[i] > 0) {
            (*symbols)[index].character = (char)i;
            (*symbols)[index].frequency = frequence[i];
            (*symbols)[index].code = NULL;
            index++;
        }
    }

    return count;
}

void assignCodes(Symbol *symbols, int totalNumberOfSymbols) {
    // Ordena os símbolos por frequência de forma decrescente com Bubble Sort
    for (int i = 0; i < totalNumberOfSymbols-1; i++) {
        for (int j = i+1; j < totalNumberOfSymbols; j++) {
            if (symbols[i].frequency < symbols[j].frequency) {
                Symbol temp = symbols[i];
                symbols[i] = symbols[j];
                symbols[j] = temp;
            }
        }
    }

    // Atribui códigos
    for (int i = 0; i < totalNumberOfSymbols; i++) {
        symbols[i].code = malloc(i+2);
        for (int j = 0; j < i; j++) {
            symbols[i].code[j] = '1';
        }
        symbols[i].code[i] = '0';
        symbols[i].code[i+1] = '\0';
    }
}

char* encodeText(const char *text, Symbol *symbols, int totalNumberOfSymbols) {
    // Calcula o tamanho do texto
    int size = 0;
    for (int i = 0; text[i] != '\0'; i++) {
        for (int j = 0; j < totalNumberOfSymbols; j++) {
            if (symbols[j].character == text[i]) {
                size += strlen(symbols[j].code);
                break;
            }
        }
    }

     // Aloca memória para o texto codificado
    char *codedText = malloc(size + 1);
    codedText[0] = '\0';

    // Concatena os códigos
    for (int i = 0; text[i] != '\0'; i++) {
        for (int j = 0; j < totalNumberOfSymbols; j++) {
            if (symbols[j].character == text[i]) {
                strcat(codedText, symbols[j].code);
                break;
            }
        }
    }
    
    return codedText;
}

int main() {
    char *mock = "Huffman Algorithm";
    int frequence[ASCII_SIZE] = {0};
    Symbol *symbols = NULL;
    int totalNumberOfSymbols;
    
    countFrequence(mock, frequence);
    totalNumberOfSymbols = createAndSortArrayBySymbol(mock, frequence, &symbols);

    assignCodes(symbols, totalNumberOfSymbols);

    for (int i = 0; i < totalNumberOfSymbols; i++) {
        printf("%c (%d): %s\n", symbols[i].character, symbols[i].frequency, symbols[i].code);
    }

    char *codedText = encodeText(mock, symbols, totalNumberOfSymbols);
    printf("\nString original: %s\n", mock);
    printf("String codificada: %s\n", codedText);

    for (int i = 0; i < totalNumberOfSymbols; i++) {
        free(symbols[i].code);
    }
    free(symbols);
    free(codedText);

    return 0;
}

