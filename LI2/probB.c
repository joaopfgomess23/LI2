#include <stdio.h>
#include <locale.h>
#include <wchar.h>

void funcao (unsigned long long int numero){
    wchar_t primeiro = 0x4DC0;

    wchar_t lista[64];
int elem = 0;
if (numero == 0){
    lista[elem++] = primeiro;
}
while (numero > 0){
    unsigned long long int resto = (numero % 64);
    lista[elem++] = (resto + primeiro);
    numero /= 64;
}

int indice = elem-1;
for(indice= elem -1; indice>0; indice--){
    wchar_t x= lista[indice];
    wprintf(L"%lc ", x);
}
wchar_t x = lista[indice];
wprintf(L"%lc", x);
wprintf(L"\n", indice);
}


int main(){
    unsigned long long int numero;
    setlocale(LC_CTYPE, "C.UTF-8");
     if (scanf("%llu", &numero) == 1) {
        funcao(numero);
    }
return 0;
}