#include <stdio.h>

#define TAM_NOME_CLIENTE 100

/*
Uma observa��o importante � caso o operador & n�o � usado na fun��o scanf(). 
Isso ocorre porque, ao usarmos o nome de um vetor sem a especifica��o de um �ndice para ele, 
o compilador j� entende que se trata de um endere�o de mem�ria.
Essa forma de atribui��o tem uma limita��o: s� � poss�vel armazenar palavras simples; compostas, n�o. 
Isso acontece porque a fun��o scanf() interrompe a atribui��o quando encontra um espa�o em branco. 
Para contornar essa limita��o, uma op��o � usar a fun��o fgets(),Essa fun��o apresenta a seguinte sintaxe:

fgets(destino,tamanho,fluxo);

O destino especifica o nome da string que ser� usada para armazenar o valor lido do teclado. 
O tamanho deve ser o mesmo da declara��o da string. 
O fluxo indica de onde est� vindo a string, no nosso caso, sempre vir� do teclado, portanto usaremos stdin (standard input).

Veja que antes de usar o fgets(), usamos a fun��o fflush(stdin). 
Apesar de n�o ser obrigat�rio, isso � uma boa pr�tica, pois garante que a entrada padr�o (stdin) seja limpa 
(sem informa��es de leituras anteriores) antes de armazenar.

printf("\n Informe o nome do cliente: "); ---> O NOME DO CLIENTE SER� COMPOSTO POR MAIS DE UMA PALAVRA, � UMA VARIAVEL COMPOSTA QUE NAO SERIA LIDA PELO SCANF
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
	        	    // PRESTAR ATEN��O AQUI, ONDE SE USA FFLUSH FGETS
    printf("\n Informe o nome do paciente: ");   //NOME neste caso vira com sobrenome e espa�o, o comando scan f n�o le espa�o, por isso usaremos fflush e fgets
    fflush(stdin);                              //O fluxo indica de onde est� vindo a string, no nosso caso, sempre vir� do teclado, portanto usaremos stdin (standard input).
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
