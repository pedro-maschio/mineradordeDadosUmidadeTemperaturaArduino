/* PEDRO DE TORRES MASCHIO.
	 DATE: 12/10/2016
   All rights reserved.
*/
#include <stdio.h>
main(){
	char diretorio[] = "LOG_THS2.txt"; // nome do arquivo gerado pelo Arduíno
    FILE *arquivo = fopen(diretorio, "a+");
	char umidnome1[7], umidnome2[2], umidnome3[3];
	char ch;
	float umid, soma1=0, soma2=0, soma3=0; // indicador 1
	float soma11=0, soma22=0, soma33=0; // indicador 2
	float soma111=0, soma222=0, soma333=0; // indicador 3
	float soma1111=0, soma2222=0, soma3333=0; // indicador 4
	float soma11111=0, soma22222=0, soma33333=0; // indicador 5
	int linhas=1;
	int cont=0;
	/* número de linhas do arquivo 20865. Cada indicador (serão 5) será composto
		pela média dos dados de 4172 linhas do arquivo. Exceto o indicador 5, que
		será composto pela média dos dados de 3992.
		
		Indicador 1: linha 1 a linha 4173
		Indicador 2: linha 4174 a linha 8346
		Indicador 3: linha 8347 a linha 12519
		Indicador 4: linha 12520 a linha 16692
		Indicador 5: linha 16693 a linha 20685  
	*/

	while((ch = fgetc(arquivo)) != EOF){
		fscanf(arquivo, "%s %s %s %f", umidnome1, umidnome2, umidnome3, &umid);
		/*Cada vez que a função fscanf é executada, umid armazena uma das
		variáveis do arquivo, primeiro a umidade do ar, depois a umidade,
		e por fim a umidade do solo.
		*/
		if(linhas <= 12519){	
   			if(cont == 0){
   				soma1 += umid;
   				cont++;
   			}
   			else if(cont == 1){
   				soma2 += umid;
				cont++;	
			}
   			else if(cont == 2){
   				soma3 += umid;
				cont++;	
			}
			
			if(linhas %3 == 0)
				cont=0;

		}
		else if(linhas <= 25038){
   			if(cont == 0){
   				soma11 += umid;
   				cont++;
   			}
   			else if(cont == 1){
   				soma22 += umid;
				cont++;	
			}
   			else if(cont == 2){
   				soma33 += umid;
				cont++;	
			}
			
			if(linhas %3 == 0)
				cont=0;	
		}
		else if(linhas <= 37557){
   			if(cont == 0){
   				soma111 += umid;
   				cont++;
   			}
   			else if(cont == 1){
   				soma222 += umid;
				cont++;	
			}
   			else if(cont == 2){
   				soma333 += umid;
				cont++;	
			}
			
			if(linhas %3 == 0)
				cont=0;		
		}
		else if(linhas <= 50076){
   			if(cont == 0){
   				soma1111 += umid;
   				cont++;
   			}
   			else if(cont == 1){
   				soma2222 += umid;
				cont++;	
			}
   			else if(cont == 2){
   				soma3333 += umid;
				cont++;	
			}
			
			if(linhas %3 == 0)
				cont=0;		
		}
		else if(linhas <= 62055){
   			if(cont == 0){
   				soma11111 += umid;
   				cont++;
   			}
   			else if(cont == 1){
   				soma22222 += umid;
				cont++;	
			}
   			else if(cont == 2){
   				soma33333 += umid;
				cont++;	
			}
			
			if(linhas %3 == 0)
				cont=0;		
		}
		
		linhas++;
	}
	printf("Umidade do ar, media 1: %f\n", soma1/4172);
	printf("Temperatura do ar, media 1: %f\n", soma2/4172);
	printf("Umidade do solo, media 1: %f\n\n", soma3/4172);
	
	printf("Umidade do ar, media 2: %f\n", soma11/4172);
	printf("Temperatura do ar, media 2: %f\n", soma22/4172);
	printf("Umidade do solo, media 2: %f\n\n", soma33/4172);
	
	printf("Umidade do ar, media 3: %f\n", soma111/4172);
	printf("Temperatura do ar, media 3: %f\n", soma222/4172);
	printf("Umidade do solo, media 3: %f\n\n", soma333/4172);
	
	printf("Umidade do ar, media 4: %f\n", soma1111/4172);
	printf("Temperatura do ar, media 4: %f\n", soma2222/4172);
	printf("Umidade do solo, media 4: %f\n\n", soma3333/4172);
	
	printf("Umidade do ar, media 5: %f\n", soma11111/3992);
	printf("Temperatura do ar, media 5: %f\n", soma22222/3992);
	printf("Umidade do solo, media 5: %f\n", soma33333/3992);
}
