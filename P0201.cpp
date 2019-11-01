#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include <conio.h>
#include <iostream> 
#include <string>

int i = 0, linha = 0, tempo, inseridos = 0;
char entrada[255];
char vars[200][20];
char temp[255];
char pre[9][7] = {"IF", "ELSE", "THEN", "PRINT", "READ", "OF", "GOTO", "END", "LET"};

void e0();
void e1();
void e2();
void e3();
void e4();
void e5();
void e6();

void sigma1();
void sigma2();
void sigma3();
void sigma4();
void sigma5();
void sigma6();
void sigma7();
void sigma8();
void sigma9();
void sigma10();

void aceita(){
    printf("\nAceito.");
}

int rejeita(){
    printf("\nRejeitado.");
    exit(0);
}

void insereMatriz (){
    //char um[20] = "B26";
    char matriz[20];
    int c = 0, s = 0, a = 0;

    for(int l = 0; l < inseridos; l++){
        for(int c = 0; c < 20; c++){
            matriz[c] = vars[l][c];
            //vars[l][c] = um[c];
        }

        //printf("\nTenho isso no temp dentro de InsereMatriz: %s", temp);
        while(temp[s] == matriz[s] && temp[s] != '\0'){
            s++;
        }

        if(temp[s + 1] == '\0'){
            //a = 1;
            //printf("\nEntrei aqui, ");
            inseridos--;
            printf("V(%d)", l);
            //printf("\nIgual");
        }
        else if (temp [s + 1] != '\0'){
            //printf("agora aqui");
            for(int x = 0; x < 20; x++){
                vars[inseridos - 1][x] = temp[x];
                //printf("V(%d)", linha);
            }
            printf("V(%d)", linha);
            linha++;
        }
    }  

    
    //printf("\nInseridos: %d", inseridos);
    /*for(int l = 0; l < inseridos; l++){
        printf("Tem isso: ");
        for(int c = 0; c < 20; c++){
            printf("%c", vars[l][c]);
        }
        printf("\n");
    } */
}



void sigma1(){
    tempo = 0;
    temp[tempo] = entrada[i];
}

void sigma2(){
    tempo++;
    temp[tempo] = entrada[i];
}

void sigma4(){
    tempo = 0;
    temp[tempo] = entrada[i];
}

void sigma5(){
    tempo++;
    temp[tempo] = entrada[i];
}

void sigma7(){
    printf("%c", entrada[i]);
    i++;
}

void sigma8(){
    printf("%c%c", entrada[i], entrada[i+1]);
    i++;
} 

void e0(){
    while(entrada[i] != '\0'){
        if(entrada[i] == 32){
            i++;
            e0();
        }

        if(entrada[i] >= '0' && entrada[i] <= '9'){
            sigma1();
            i++;
            //printf("\nChamei o e1");
            e1();
        }

        else if(entrada[i] >= 'A' && entrada[i] <= 'Z'){
            sigma4();
            i++;
            //printf("\nChamei o e2");
            e2();
        }
        
        else if(entrada[i] == ':'){
            e3();
        }

        else if(entrada[i] == '%'){
            i++;
            e5();
        }

        else{
            e6();
        }

        i++;
    }
}

void e1(){
    if(entrada[i] >= '0' && entrada[i] <= '9'){
        sigma2();
        i++;
        e1();
    }
    else{
        tempo++;
        temp[tempo] = 0;
        //insereMatriz();  
        printf("N(%s)", temp);
        e0();
    }
    /*int x = entrada[i] - '0';
    int resultado = x;

    while(entrada[i + 1] >= '0' && entrada[i + 1] <= '9' && entrada[i + 1] != 32){
        resultado = (x * 10) + (entrada[i + 1] - '0');
        x = resultado;
        i++;
    }

    printf("N(%d)", resultado);
    resultado = 0;*/
}

void e2(){
    int final = 0;
    if(entrada[i] >= 'A' && entrada[i] <= 'Z' || entrada[i] >= '0' && entrada[i] <= '9'){
        sigma5();
        i++;
        e2();
    }
    else{
        tempo++;
        temp[tempo] = 0;
        int pos;

        //printf("\nTenho isso no temp: %s", temp);
        for(int l = 0; l < 9; l++){
            int c = 0;
            while(temp[c] == pre[l][c] && temp[c] != '\0'){
                if(temp[c + 1] == '\0'){
                        final = 1;
                        pos = l;
                }
                c++;
            }
            /*for(int c = 0; c < 7; c++){
                if(temp[c] == pre[l][c]){
                    if(temp[c + 1] == '\0'){
                        final = 1;
                        pos = l;
                    }
                }    
            }*/
        }
        
        //printf("\nO final vale isso: %d", final);

        if(final == 0){
            inseridos++;
            insereMatriz();
        }
        else if (final == 1){
            printf("P(%d)", pos);
            final = 0;
        }
    
        
        //printf("%s", temp);
        e0();
    }
    final = 0;
}

void e3(){
    if(entrada[i + 1] == '='){
        e4();
    }
    
    else{
        sigma7();
        e0();
    }
}

void e4(){
    sigma8();
}

void e5(){
    if(entrada[i] != '\0'){
        i++;
        e5();
    }
    else{
        e0();
    }
        
}

void e6(){
    printf("%c", entrada[i]);
    i++;
    e0();
}

int main(void) {
  	printf("Entrada: ");
	fgets(entrada, 255, stdin);

    e0();

    return 0;
}