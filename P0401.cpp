#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char pilhaSimbolos[255][255], pilhaNumeros[255][255], pilhaSaidas[255], entrada[255], saida[2];

int p = 0, linhaNumeros = 0, colunaNumeros = 0, linhaSimbolos = 0, colunaSimbolos = 0, linhaSaida = 65;

void empilhaNumero(){
    pilhaNumeros[linhaNumeros][colunaNumeros] = entrada[p];
    linhaNumeros++;

    //printf("\nVou empilhar esse número: %c", pilhaNumeros[linhaNumeros - 1][colunaNumeros]);
}

void empilhaSimbolo(){
    pilhaSimbolos[linhaSimbolos][colunaSimbolos] = entrada[p];
    linhaSimbolos++;

    //printf("\nVou empilhar esse símbolo: %c", pilhaSimbolos[linhaSimbolos - 1][colunaSimbolos]);
}

int verificaPrioridade(){
    for(int i = 0; i <= linhaSimbolos; i++){
        if(strcmp(pilhaSimbolos[i], "*") == 0 || strcmp(pilhaSimbolos[i], "/") == 0)
            return 1;
    }

    return 0;
}

void resolvePendencia(){
    //printf("\nVou resolver uma pendência");
    
    printf("LDA: %s\n", pilhaNumeros[linhaNumeros - 1]);

    if(pilhaSimbolos[linhaSimbolos - 1][colunaSimbolos] == '*')
        printf("MUL: %s\n", pilhaNumeros[linhaNumeros - 2]);
    
    if(pilhaSimbolos[linhaSimbolos - 1][colunaSimbolos] == '/')
        printf("DIV: %s\n", pilhaNumeros[linhaNumeros - 2]);

    saida[0] = linhaSaida;

    linhaSaida++;

    linhaNumeros = linhaNumeros - 2;

    pilhaNumeros[linhaNumeros][colunaNumeros] = saida[0];

    for(int i = 0; i <= linhaNumeros; i++)
        printf("\nNa matriz de números: %s", pilhaNumeros[linhaNumeros]);

    printf("\nTenho %d elementos na matriz de números.", linhaNumeros);

    printf("STA: %s\n", saida);

    pilhaSimbolos[linhaSimbolos - 1][colunaSimbolos] = 0;
    linhaSimbolos--;
}

void pegaElementos(){    
    while(entrada[p] != 0){
        if(entrada[p] >= '0' && entrada[p] <= '9'){
            empilhaNumero();
            p++;
        }
        else if(entrada[p] == '*' || entrada[p] == '/'){
            if(linhaSimbolos != 0){
                if(verificaPrioridade() == 1){
                    resolvePendencia();
                }
            }
            else{
                empilhaSimbolo();
                p++;
            }
                
        }
    }
}

void leEntrada(){    
    int i;

    memset(pilhaSimbolos, 0, 65025);
    memset(pilhaNumeros, 0, 65025);

    printf("Entrada: ");
    fgets(entrada, 255, stdin);

    for(i = 0; entrada[i]; i++);

    entrada[i - 1] = 0;    

    pegaElementos();
}

int main(){
    leEntrada();    

    return 0;
}