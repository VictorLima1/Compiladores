#include <iostream> 

char entrada[255], pilha[255];
int i = 0, j = 0;

void A();
void B();
void C();
void D();

void desempilha(){
    //printf("\nVou desempilhar em");
    j--;
    D();
}

void D(){
    //printf("\nEntrei no D");
    B();
}

void C(){
    //printf("\nEntrei no C");
    pilha[j] = ')';
    j++;
    A();
}

void B(){
    //printf("\nEntrei no B, com entrada: %c", entrada[i]);
    if(entrada[i] == '+' || entrada[i] == '-' || entrada[i] == '*'){
        i++;
        A();
    }
    
    else if(entrada[i] == ')'){
        //printf("\nEntrei no desempilha");
        i++;
        desempilha();
    }

    else if(j == 0 && entrada[i] == '\0'){
        //printf("\nJ vale: %d", j); 
        printf("\nAceita\n");
    }
    else{
        //printf("\nJ vale: %d, entrada de i: %c", j, entrada[i]);
        printf("\nRejeita\n");
    }
}

void A(){
    //printf("\nEntrei no A");
    if(entrada[i] >= '0' && entrada[i] <= '9'){
        //printf("\nTo vendo: %c ", entrada[i]);
        i++;
        B();
    }

    else if(entrada[i] == '('){
        //printf("\nTo vendo: %c ", entrada[i]);
        i++;
        C();
    }
    

    /*else
        printf("\nRejeita");*/
    
}

int main(){
    printf("Entrada: ");
    fgets(entrada, 255, stdin);
    
    int c;
    for(c = 0; entrada[c]; c++);
    entrada[c - 1] = 0;
    //entrada[6] = '\0';
    A();
    return 0;
}