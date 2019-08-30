#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

// Victor Lima - 22.216.014-5
// Guilherme Ferreira - 22.216.024-4

void criaGoto(char* nomePrograma){
	strcat(nomePrograma,".cpp");
	FILE *fp = fopen(nomePrograma, "w+");
	
	fprintf(fp, "#include <stdio.h> \n" \
				"#include <stdlib.h> \n" \
				"#include <string.h> \n" \
				"#include <conio.h>\n\n");
				
				
	fprintf(fp, "int main() {\n");
	
	fprintf(fp,"\tchar f[200];\n\tint p = 0;\n\tprintf(\"Cadeia: \");\n\tfgets(f, 200, stdin);\n\tgoto e0;\n\n");
	
	
	
	
	fprintf(fp,"\n\treturn 0;");
	fprintf(fp,"\n}");
	
	fclose(fp);
}

void criaFuncao(char* nomePrograma, int estados, int simbolos, char* sigma){
	strcat(nomePrograma,".cpp");
	FILE *fp = fopen(nomePrograma, "w+");
	
    fprintf(fp, "#include <stdio.h> \n" \
				"#include <stdlib.h> \n" \
				"#include <string.h> \n" \
				"#include <conio.h>\n\n");
				
	for(int i = 0; i < estados; i++){
        fprintf(fp, "void e%d();\n", i);
	}

	fprintf(fp, "void aceita(); \n" \
				"void rejeita(); \n");
				
	fprintf(fp, "\nchar f[100]; \n" \
				"int p; \n");
				
	for(int i = 0; i < estados; i++){
		fprintf(fp, "\nvoid e%d() {", i);
		for(int j = 0; j < simbolos; j++){
			if(j == 0){
				fprintf(fp, "\n\tif(f[p] == '%c') {\n", sigma[j]);
				fprintf(fp, "\t\tp++;\n\t\te%d();\n\t}", i);
			}
			else{
				fprintf(fp, "\n\telse\n\t\tif(f[p] == '%c') {\n", sigma[j]);
				fprintf(fp, "\t\t\tp++;\n\t\t\te%d();\n\t}", i);
			}
			
		}
		
		fprintf(fp, "\n\telse\n\t\tif(f[p] == '\\0') {\n\t\t\taceita();\n\t}");
		fprintf(fp, "\n\telse{\n\t\t\trejeita();\n\t}");
		fprintf(fp, "\n}\n");	
	}
	
	fprintf(fp, "\nvoid aceita() {\n\tputs(\"Aceita\");\n\texit(0);\n}");
	fprintf(fp, "\nvoid rejeita() {\n\tputs(\"Rejeita\");\n\texit(0);\n}");
	
	fprintf(fp, "\nint main() {\n\tprintf(\"Digite a palavra: \");\n\tgets(f);\n\te0();\n\treturn 0;\n}");
/*	fprintf(fp, "\tprintf(\"Digite a palavra: \");\n");
  	fprintf(fp, "\tgets(f);\n");
  	fprintf(fp, "\te0();\n");
  	fprintf(fp, "\treturn 0;\n}");*/
			
	fclose(fp);
}

int main(void) {
  	int simbolos; // quantidade de símbolos
  	char sigma[100]; // array de símbolos
  	int final[100]; // array de estados finais
  	int estados; // quantidades de estados
  	int inicial; // estado inicial
  	int finais; // quantidade de estados finais
  	int opcao; // opção de função ou GoTo
  	char nomePrograma[100]; // nome do rogerinho do ingá

  	printf("Quantos simbolos? ");
  	scanf("%d", &simbolos);

	for(int i = 0; i < simbolos; i++){
		printf("Qual o simbolo %d? ", i);
		fflush(stdin);
    	scanf("%c", &sigma[i]);
	}
	
	printf("\nQuantos estados? ");
  	scanf("%d", &estados);
  	
    int delta[simbolos][estados];
  	
  	for(int i = 0; i < estados; i++){
		for(int j = 0; j < simbolos; j ++){
			printf("Para o estado e%d, e o simbolo %c, qual o estado seguinte? ", i, sigma[j]);
			scanf("%d", &delta[i][j]);
		}
	}
	
	printf("\nQual o estado inicial? ");
	scanf("%d", &inicial);
	
	printf("\nQuantos estados finais? ");
  	scanf("%d", &finais);

	for(int i = 0; i < finais; i++){
		printf("Qual o estado final %d? ", i);
    	scanf("%d", &final[i]);
	}
	
	// P0102
	
	printf("\nQual vai ser a opcao? ");
	printf("\n1 - Funcao\n2 - GoTo\n");
	scanf("%d",&opcao);
	
	printf("\nQual o nome do programa? ");
	scanf("%s",&nomePrograma);
	
	if(opcao == 1){
        criaFuncao(nomePrograma, estados, simbolos, sigma);
	}
	else if(opcao == 2){
		criaGoto(nomePrograma);
	}
	
	/*
	printf("\nQuantidade de simbolos: %d", simbolos);
    printf("\nVetor sigma:\n");
    for(int i = 0; i < simbolos; i++){
		printf("%c\t", sigma[i]);
	}
	*/
	printf("\n");
	
	for(int i = 0; i < estados; i++){
		for(int j = 0; j < simbolos; j ++){
			printf("%d\t", delta[i][j]);
		}
		printf("\n");
	}
	
	/*
	printf("\nQuantidade de estados: %d", estados);
	printf("\nq0: e%d", inicial);
	printf("\nQuantidade de estados finais: %d", finais);
	printf("\nVef: ", finais);
	for(int i = 0; i < finais; i++){
		printf("e%d ", final[i]);
	}*/

	getch();
  	return 0;
}
