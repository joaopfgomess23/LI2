#include <stdio.h>
#include <stdlib.h>
#include <math.h> 

double verificacao(int E, int M, char *lista) {
    int sinal = (lista[0] == '1') ? -1 : 1;
    int exp = 0;


    for (int i = 0; i < E; i++) {
        exp = (exp << 1) | (lista[i + 1] - '0');
    }

    double frac = 0.0;
    for (int i = 0; i < M; i++) {
        if (lista[i + E + 1] == '1') {
            frac += pow(2, -i - 1);
        }
    }

    if (exp == (1 << E) - 1) {
        if (frac == 0.0) {
            return sinal == -1 ? -INFINITY : INFINITY;
        } else {
            return NAN;
        }
    }

    double bias = pow(2, E - 1) - 1;
    if (exp == 0) {
        return sinal * frac * pow(2, 1 - bias);
    } else {
        return sinal * (1 + frac) * pow(2, exp - bias);
    }
}

int main() {
    int N;
    if (scanf("%d", &N) == 1) {
        double resultados[N];

        for (int i = 0; i < N; i++) {
            int E, M;
            char bits[20];
            if (scanf("%d %d %s", &E, &M, bits) == 3) {
                resultados[i] = verificacao(E, M, bits);
            }
        }

        for (int i = 0; i < N; i++) {
            if (isnan(resultados[i])) {
                printf("NaN\n");
            } else if (isinf(resultados[i])) {
                printf("%sInfinity\n", (resultados[i] < 0) ? "-" : "+");
            } else {
                printf("%lg\n", resultados[i]);
            }
        }
    }

    return 0;
}