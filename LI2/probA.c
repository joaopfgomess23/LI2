#include <stdio.h>
#include <locale.h>
#include <wchar.h>

int main(){
    int dia, mes;

    setlocale(LC_CTYPE, "C.UTF-8");

    if (scanf("%d %d", &dia, &mes) != 2) {
        printf("Erro ao ler entrada.\n");
        return 1; 
    }

    if ((mes==1 && dia <= 19) || (mes==12 && dia >= 22)) {
        wchar_t c = 0x2651;
        wprintf(L"%lc\n", c);
    } else if ((mes==1 && dia > 19) || (mes==2 && dia <= 18)) {
        wchar_t c = 0x2652;
        wprintf(L"%lc\n", c);
    } else if ((mes==2 && dia > 18) || (mes == 3 && dia <= 20)) {
        wchar_t c = 0x2653;
        wprintf(L"%lc\n", c);
    } else if ((mes==3 && dia > 20) || (mes == 4 && dia <= 20)) {
        wchar_t c = 0x2648;
        wprintf(L"%lc\n", c);
    } else if ((mes==4 && dia > 20) || (mes == 5 && dia <= 20)) {
        wchar_t c = 0x2649;
        wprintf(L"%lc\n", c);
    } else if ((mes==5 && dia > 20) || (mes == 6 && dia <= 20)) {
        wchar_t c = 0x264a;
        wprintf(L"%lc\n", c);
    } else if ((mes==6 && dia > 20) || (mes == 7 && dia <= 22)) {
        wchar_t c = 0x264b;
        wprintf(L"%lc\n", c);
    } else if ((mes==7 && dia > 22) || (mes == 8 && dia <= 22)) {
        wchar_t c = 0x264c;
        wprintf(L"%lc\n", c);
    } else if ((mes==8 && dia > 22) || (mes == 9 && dia <= 22)) {
        wchar_t c = 0x264d;
        wprintf(L"%lc\n", c);
    } else if ((mes==9 && dia > 22) || (mes == 10 && dia <= 22)) {
        wchar_t c = 0x264e;
        wprintf(L"%lc\n", c);
    } else if ((mes==10 && dia > 22) || (mes == 11 && dia <= 21)) {
        wchar_t c = 0x264F;
        wprintf(L"%lc\n", c);
    } else {
        wchar_t c = 0x2650;
        wprintf(L"%lc\n", c);
    } 

    return 0;
}