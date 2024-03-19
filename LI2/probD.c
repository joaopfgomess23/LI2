#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define TAMANHO_ALFABETO 26

struct Dados {
    char letra;
    double expected;
};

struct Dados dados[] = {
        {'A', 43.31}, {'B', 10.56}, {'C', 23.13}, {'D', 17.25}, {'E', 56.88}, {'F', 9.24}, {'G', 12.59}, {'H', 15.31}, {'I', 38.45}, 
        {'J', 1.00}, {'K', 5.61}, {'L', 27.98}, {'M', 15.36}, {'N', 33.92}, {'O', 36.51}, {'P', 16.14}, {'Q', 1.00}, {'R', 38.64}, 
        {'S', 29.23}, {'T', 35.43}, {'U', 18.51}, {'V', 5.13}, {'W', 6.57}, {'X', 1.48}, {'Y', 9.06}, {'Z', 1.39}
    };

void frequencia(const char *frase, int *repeticoes) {
    int i, indice;

    for (i = 0; i < TAMANHO_ALFABETO; i++) {
        repeticoes[i] = 0;
    }

    for (i = 0; frase[i] != '\0'; i++) {
        char letra = tolower(frase[i]);
        if (letra >= 'a' && letra <= 'z') {
            indice = letra - 'a';
            repeticoes[indice]++;
        }
    }
}

double calculo(const char frase[]) {
    double soma = 0;
    int repeticoes[TAMANHO_ALFABETO] = {0};

    frequencia(frase, repeticoes);

    for (int i = 0; i < TAMANHO_ALFABETO; i++) {
        if (repeticoes[i] == 0) {
            soma += dados[i].expected;
        } else {
            soma += (pow((dados[i].expected - repeticoes[i]), 2)) / dados[i].expected;
        }
    }
    return soma;
}

void encriptar(char *mensagem, int K) {
    int i = 0;
    char letra;
    while (mensagem[i] != '\0') {
        letra = mensagem[i];
        if (isalpha(letra)) { 
            char base = isupper(letra) ? 'A' : 'a';
            letra = (letra - base + K) % 26 + base; 
        }
        mensagem[i] = letra;
        i++;
    }
}

int main(){
    char frase[10000], fraseCifrada[10000];
    
    if (fgets(frase, sizeof(frase), stdin) == NULL) {
        printf("Erro\n");
        return 1;
    }

    frase[strcspn(frase, "\n")] = '\0';

    double menor_soma = INFINITY;
    int deslocamento_otimo = -1;

    for (int deslocamento = 0; deslocamento < 26; deslocamento++) {
        strcpy(fraseCifrada, frase); 
        encriptar(fraseCifrada, deslocamento); 
        double soma_atual = calculo(fraseCifrada); 
        if (soma_atual < menor_soma) {
            menor_soma = soma_atual;
            deslocamento_otimo = deslocamento;
        }
    }

    encriptar(frase, deslocamento_otimo);
    printf("%d %s\n", deslocamento_otimo, frase);

    return 0;
    }
