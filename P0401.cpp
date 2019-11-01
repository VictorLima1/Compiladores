#include <iostream>
#include <stdio.h>
#include <string.h>

char entrada[255], num[255][255], simb[255][255];
int p = 0, colunaNum = 0, linhaNum = 0, linhaSimb = 0, colunaSimb = 0;

void empilhaSimb(){
    simb[linhaSimb][colunaSimb] = entrada[p];
    printf("\nMandei pra matriz de simbolos: %c", simb[linhaSimb][colunaSimb]);
    linhaSimb++;
}

void empilhaNum(){
    num[linhaNum][colunaNum] = entrada[p];
    printf("\nMandei pra matriz de numeros: %c", num[linhaNum][colunaNum]);
    linhaNum++;
}

void resolvePendencia(){
    printf("Cheguei em pendencias");
}

void pegaEntrada(){
    while(entrada[p] != 0){
        if(entrada[p] >= '0' && entrada[p] <= '9'){
            empilhaNum();
            p++;
        }
        else if(entrada[p] == '+' || entrada[p] == '-'){
            if(simb[
        }
        else if(entrada[p] == 32)
            p++;
    }
    
}

int main(){
    memset(num, 0, 65025);
    memset(simb, 0, 65025);

    printf("Entrada: ");
    fgets(entrada, 255, stdin);

    int c;

    for(c = 0; entrada[c]; c++);
    
    entrada[c - 1] = 0;

    pegaEntrada();   

    return 0;
}