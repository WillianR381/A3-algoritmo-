/*
    Bruno de Abreu -  042200017
    Willian Ribeiro - 042200004  
    Helvécio Neto -   042200019

    TOTAL DA MATRICULA - 60156902

*/

#include <stdio.h>
#include <math.h>
#include <string.h>

float imc(float peso, float altura) {
    float imc = peso / pow(altura,2);
    return(imc);
}


char* categoria_imc(float imc) {
    char* categoria_imc;

    if (imc < 18.5) {
        categoria_imc = "ABAIXO DO PESO";
    } else if (imc >= 18.5 && imc < 25) {
        categoria_imc = "PESO NORMAL";
    } else if (imc >= 25 && imc < 30 ) {
        categoria_imc = "SOBREPESO";
    } else if (imc >= 30) {
        categoria_imc = "OBESIDADE";
    }
   
    return (categoria_imc) ;
}

struct dados {
    char nome[40];
    int sexo;
    char genero[20];
    float altura;
    float peso;
    char indicePeso[40];
};



int main(void) {
    int i;
    float valorimc;

    struct dados ficha[6];

    for (i = 0 ; i < 6; i++) {
        printf("Digite seu nome: ");
        fflush(stdin);
        gets(ficha[i].nome);
        printf("\n");

        printf("Digite Qual seu sexo: 0 - Masculino ou para 1 - Feminino: ");
        scanf("%d", &ficha[i].sexo);
        printf("\n");

        if (ficha[i].sexo == 1) {
            strcpy(ficha[i].genero, "FEMININO");
        } else {
            strcpy(ficha[i].genero, "MASCULINO");
        }

        printf("Digite sua altura: ");
        scanf("%f", &ficha[i].altura);
        printf("\n");

        printf("Digite seu peso: ");
        scanf("%f", &ficha[i].peso);
        printf("\n");

        valorimc = imc(ficha[i].peso, ficha[i].altura);
       
        strcpy(ficha[i].indicePeso, categoria_imc(valorimc));

        printf("######################\n");
        printf("Nome: %s \t", ficha[i].nome);
        printf("Altura: %.1f \t", ficha[i].altura);
        printf("Sexo: %s \t", ficha[i].genero);
        printf("Peso: %.1f \t", ficha[i].peso);
        printf("Categoria: %s \t", ficha[i].indicePeso);
        printf("IMC: %.1f \t", valorimc);
        printf("\n######################\n");
    }
    

    //Imprimir Variável 
    for (i = 0; i < 6; i++) {  

        if (strcmp(ficha[i].indicePeso, "SOBREPESO") == 0){
            printf("%s \n",ficha[i].nome);
        }

        if (strcmp(ficha[i].indicePeso, "OBESIDADE") == 0){
            printf("Nome: %s \t", ficha[i].nome);
            printf("Sexo: %s", ficha[i].genero);
        } 
    }
}