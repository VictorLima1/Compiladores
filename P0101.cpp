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

//void criaFuncao(char* nomePrograma, int estados, int simbolos, char* sigma, int delta[estados][simbolos], int inicial){
	
//}

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
		int i, j;
        //criaFuncao(nomePrograma, estados, simbolos, sigma, delta, inicial);
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

		for(i = 0; i < estados; i++){
			fprintf(fp, "\nvoid e%d() {", i);
			for(j = 0; j < simbolos; j++){
                if(delta[i][j] != -1){
                    fprintf(fp, "\n\tif(f[p] == '%c') {\n", sigma[j]);
					fprintf(fp, "\t\tp++;\n\t\te%d();\n\t}", delta[i][j]);
				}
			}

			for(int k = 0; k < finais; k++){
                if(i == final[k]){
					if(delta[i][j] == -1 && delta[i][j+1] == -1){
                        fprintf(fp, "\n\t\tif(f[p] == '\\0') {\n\t\t\taceita();\n\t}");
					}
					else{
                         fprintf(fp, "\n\telse\n\t\tif(f[p] == '\\0') {\n\t\t\taceita();\n\t}");
					}
                   
				}
			}
			fprintf(fp, "\n\telse{\n\t\trejeita();\n\t}");
			fprintf(fp, "\n}\n");
		}

		fprintf(fp, "\nvoid aceita() {\n\tputs(\"Aceita\");\n\texit(0);\n}");
		fprintf(fp, "\nvoid rejeita() {\n\tputs(\"Rejeita\");\n\texit(0);\n}");

		fprintf(fp, "\nint main() {\n\tprintf(\"Digite a palavra: \");\n\tgets(f);\n\te%d();\n\treturn 0;\n}", inicial);

		fclose(fp);
	}
	else if(opcao == 2){
		criaGoto(nomePrograma);
	}
	
	printf("\n");
	
	for(int i = 0; i < estados; i++){
		for(int j = 0; j < simbolos; j ++){
			printf("%d\t", delta[i][j]);
		}
		printf("\n");
	}

	getch();
  	return 0;
}
