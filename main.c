/*

    Willian Ribeiro de Araujo - 042200004
*/
#include <stdio.h>
#include <math.h>
#include <string.h>

float imc(float peso, float altura){

    float imc = peso / pow(altura,2);
    
    return(imc);
}

char* categoria_imc(imc)
{
    char* categoria_imc;

    if (imc < 18.5)
    {
        categoria_imc = "ABAIXO DO PESO";
    }

    else 
        if (imc >= 18.5 && imc<25)
        {
            categoria_imc = "PESO NORMAL";
        }
    

    else 
        if (imc >= 25 && imc < 30 )
        {
            categoria_imc = "SOBREPESO";
        }
    

    else
        if (imc >= 30)        
        {
            categoria_imc = "OBESIDADE";
        }

        
    return (categoria_imc) ;
}

struct dados{
    char nome[40];
    int sexo;
    float altura;
    float peso;
    char indicePeso[40];
    };



int main(void)
{
    int i ;
    char  valorimc;

    struct dados ficha[6];

    for(i=0 ; i < 6; i++){
    
    printf("Digite seu nome\n");
    fflush(stdin);
    gets(ficha[i].nome);

    printf("Digite Qual seu sexo:0-Masculino ou para 1-Feminino \n");
    scanf("%d",&ficha[i].sexo);

    printf("Digite sua altura\n");
    scanf("%f",&ficha[i].altura);

    printf("Digite seu peso\n");
    scanf("%f",&ficha[i].peso);


    valorimc = imc(ficha[i].peso,ficha[i].altura);

    strcpy(ficha[i].indicePeso , categoria_imc(valorimc));

    
    }

    for ( i = 0; i < 6; i++)
    {   
        printf("######################\n");
        printf("%s \n",ficha[i].nome);
        printf("%.1f \n",ficha[i].altura);
        printf("%d \n",ficha[i].sexo);
        printf("%.1f \n",ficha[i].peso);
        printf("%s \n",ficha[i].indicePeso);
        printf("######################\n");
    }
    

    
    
}
