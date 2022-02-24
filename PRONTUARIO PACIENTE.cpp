#include <stdio.h>

#define TAM_NOME_CLIENTE 100

/*
Uma observação importante é caso o operador & não é usado na função scanf(). 
Isso ocorre porque, ao usarmos o nome de um vetor sem a especificação de um índice para ele, 
o compilador já entende que se trata de um endereço de memória.
Essa forma de atribuição tem uma limitação: só é possível armazenar palavras simples; compostas, não. 
Isso acontece porque a função scanf() interrompe a atribuição quando encontra um espaço em branco. 
Para contornar essa limitação, uma opção é usar a função fgets(),Essa função apresenta a seguinte sintaxe:

fgets(destino,tamanho,fluxo);

O destino especifica o nome da string que será usada para armazenar o valor lido do teclado. 
O tamanho deve ser o mesmo da declaração da string. 
O fluxo indica de onde está vindo a string, no nosso caso, sempre virá do teclado, portanto usaremos stdin (standard input).

Veja que antes de usar o fgets(), usamos a função fflush(stdin). 
Apesar de não ser obrigatório, isso é uma boa prática, pois garante que a entrada padrão (stdin) seja limpa 
(sem informações de leituras anteriores) antes de armazenar.

printf("\n Informe o nome do cliente: "); ---> O NOME DO CLIENTE SERÁ COMPOSTO POR MAIS DE UMA PALAVRA, É UMA VARIAVEL COMPOSTA QUE NAO SERIA LIDA PELO SCANF
fflush(stdin);
fgets(cli.nome, TAM_NOME_CLIENTE, stdin);

%.2lf is used of long double it is a format specifier used in C language. .2 is used for controlling the width of the decimal places.

*/

struct paciente {
    char nome[30];
    int idade;
    float peso;
    float altura;
    float pressao;
    };

int main(){
    struct paciente paciente;
    float imc;
	        	    // PRESTAR ATENÇÃO AQUI, ONDE SE USA FFLUSH FGETS
    printf("\n Informe o nome do paciente: ");   //NOME neste caso vira com sobrenome e espaço, o comando scan f não le espaço, por isso usaremos fflush e fgets
    fflush(stdin);                              //O fluxo indica de onde está vindo a string, no nosso caso, sempre virá do teclado, portanto usaremos stdin (standard input).
    fgets(paciente.nome, 30, stdin);           //fgets(destino,tamanho,fluxo);

    
    printf("\n Informe a idade do paciente: ");
    scanf("%d", &paciente.idade);
    
    printf("\n Informe o peso do paciente: ");
    scanf("%f", &paciente.peso);
    
    printf("\n Informe a pressao do paciente: ");
    scanf("%f", &paciente.pressao);
    
    printf("\n Informe a altura do paciente: ");
    fflush(stdin);
    scanf("%f", &paciente.altura);
    
    imc = (paciente.peso) / (paciente.altura*paciente.altura);
    
    printf("\n\n PRONTUARIO");
    
    printf("\n\n Paciente: %s", paciente.nome);
    printf("\n Idade: %d anos", paciente.idade);
    printf("\n\n Peso: %.2lf kg", paciente.peso);                    //%.2lf is used of long double it is a format specifier used in C language. .2 is used for controlling the width of the decimal places.
    printf("\n\n Pressao: %.2lf mmHg", paciente.pressao);           //%.2lf is used of long double it is a format specifier used in C language. .2 is used for controlling the width of the decimal places.
    printf("\n\n Altura: %.2lf m", paciente.altura);               //%.2lf is used of long double it is a format specifier used in C language. .2 is used for controlling the width of the decimal places.
    printf("\n\n Indice de massa corporal e: %.2lf" , imc);       //%.2lf is used of long double it is a format specifier used in C language. .2 is used for controlling the width of the decimal places.
    
    if (imc > 25){
       printf("\n\n O paciente esta com excesso de peso");
       if (paciente.pressao >= 12.8){
	       printf("\n\n A pressao nao esta satisfatoria");
   	   } 
   	   else{
   	   	printf("\n\n A pressao esta satisfatoria");
		  }
}
    if  (imc < 18){
     printf("\n\n O paciente esta abaixo do peso ideal");
      
	  if (paciente.pressao >= 12.8){
	       printf("\n\n A pressao nao esta satisfatoria");
   	   } 
   	   else{
   	   	printf("\n\n A pressao esta satisfatoria");
		  }
}
    if (imc >=18 && imc<=25){
       printf("\n\n O paciente esta com peso saudavel");
       if (paciente.pressao >= 12.8){
	       printf("\n\n A pressao nao esta satisfatoria");
   	   } 
   	   else{
   	   	printf("\n\n A pressao esta satisfatoria");
		  }
}
return 0;
}
