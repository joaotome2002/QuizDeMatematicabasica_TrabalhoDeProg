/*
TRABALHO DE INTRODUÇÃO A PROGAMAÇÃO

Professor: Carlos Maurício Dourado 
Curso: Engenharia de Computação 
Alunos: Carlos Henrique Oliveira de Almeida, Emerson de Oliveira, Felipe Alves, João Lucas Tomé Caetano

*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h> 

FILE *arq;                                  //ponteiro criado para chamar o arquivo.
int r,j,g=1,u;                              //variáveis: r = resposta certa da questão; j = resposta do usuário; g = geração do número da questão; u = para receber os comando iniciais do jogo.
int i, o, c;                                //variáveis criadas para gerar números aleatórios; i, c = são para auxiliar na criação das questões;  o = auxilia na aleatoriedade das posições das alternativas.
int s1=0, s2=0;                             //variáveis criadas para acumular pontos das questões que o usuário acertou.
int j1 [4][11];                             //matriz criada para receber a geração de alternativas de cada questão do jogador 1.
int j2 [4][11];                             //matriz criada para receber a geração de alternativas de cada questão do jogador 2.
char nome1[50], nome2[50], nome[50];        //chars criadas para receber e gravar o nome dos jogadores.

//função criada para gerar a tela inicial do programa.
int inicio (){
	printf("\n\n\n\n\n");
	printf("\n                                                    -----------------------------------------");
    printf("\n                                                   | ### BEM VINDO AO QUIZ DE MATEMATICA ### | ");    
	printf("\n                                                   |-----------------------------------------|");
	printf("\n                                                   | ***jogo feito para se jogar de dupla*** |");
	printf("\n                                                    -----------------------------------------");
	printf("\n\n\n\n\n");
    //opções para o jogador ou proseguir ou fechar o programa.
    
	printf("                                            ***********************************************************\n");
	printf("                                            *                                                         *");
	printf("\n                                            * Digite '1' para continuar ou qualquer coisa para fechar *\n");
	printf("                                            *                                                         *\n");
	printf("                                            ***********************************************************");
    scanf("%i",&u);

    //condição para verificar a opção que o jogador escolheu.
    if (u == 1){
        return 0;
    }else {
        exit(0);
    }

    return 0;
	
}

//função criada para ler e mostrar o histórico, no início do programa, dos últimos dois jogadores que jogaram.
int lerhistorico (){
	printf("******************************\n");
	printf("*                            *\n");    
	printf("*   Ultima Partida:          *\n");
	printf("*   ---------------------    *");
	
    //leitura do conteúdo das linhas.
    arq = fopen ("historico.txt","r");
    fgets(nome,50,arq);
    fgets(nome1,50,arq);
    fgets(nome2,50,arq);
    arq = fclose (arq);

    //mostrar na tela do usuário aquilo que foi lido no arquivo.
    printf("\n    %s",nome1);
    printf("    %s         \n",nome2);
	printf("*   ---------------------    *\n");
	printf("*                            *\n");
	printf("******************************");

    //opções para o jogador ou proseguir ou fechar o programa.
    printf("\n\n  Digite '1' para comecar o jogo ou qualquer coisa para fechar\n");
    scanf("%i",&u);

    //condição para verificar a opção que o jogador escolheu.
    if (u == 1){

        //receber nome dos jogadores.
		printf("\n\nBEM VINDO!!!\nDigite o nome dos jogadores que irao participar\n");
        gets(nome);
        printf("\nNome do jogador 1:\n");
        gets(nome1);
        printf("\nNome do jogador 2:\n");
        gets(nome2);
        return 0;
    }else {
        exit(0);
    }

    return 0;
}

//função criada para mostrar a pontuação final de cada jogador.
int scores (){

    //condição para verificar a quantidade de questões acertadas por cada jogador e mostrar mensagens diferentares dependendo dela.

    if (s1 != 0){
		printf("****************************************************\n");
        printf("    Parabens! %s voce acertou %i pergunta(s)",nome1,s1);
		printf("\n****************************************************\n");
    }else{
        printf("\nInfelizmente o jogador 1 nao acertou nenhuma questao.\n");
    }
    
     
    if (s2 != 0){
		printf("\n\n****************************************************");
        printf("\n    Parabens! %s voce acertou %i pergunta(s)\n",nome2,s2);
		printf("****************************************************\n");
    }else{
        printf("\nInfelizmente o jogador 2 nao acertou nenhuma questao.\n");
    }

    return 0;
}

//função criada para gravar e salvar no arquivo o nome e a pontuação de cada jogador ao final da partida.
int gravarhistorico (){

    arq = fopen ("historico.txt","w");
    fprintf(arq,"%s \n",nome);
    fprintf(arq,"%s --> %i pnt(s)\n",nome1,s1);
    fprintf(arq,"%s --> %i pnt(s)",nome2,s2);
    arq = fclose (arq);
    
    return 0;

}

//função criada unicamente para gerar númros aleatórios para as variáveis i, o, c.
int geracaoaleatoria (){
    
    srand(time(NULL));
    i=rand()%11;
    o=rand()%4;
    c=rand()%11;
    
    return 0;
}

//laço para atribuir as alternativas a matriz do jogador 1.
int lacoj1 (){
    
    //laço para atribuir as alternativas a matriz.
    for(int k=0; k<4; k++){
        j1 [k][g] = r + k - o;
    }

    //laço para mostrar as alternativas na tela do usuário.
    for (int z=0; z<4; z++){
        printf("                                   %i\n", j1 [z][g]);
    }

    printf("                                   Resposta:");
    scanf("%d",&j);

    //condição para verificar se a resposta digitada pelo jogador está correta.
    if(j == r){
		printf("\n                                            ********************\n");
        printf("                                            *Jogador 1 Acertou!*\n");
		printf("                                            ********************\n");
        s1++;
    }else{
		printf("\n                                            ------------------");
        printf("\n                                            |Jogador 1 Errou!|\n");
		printf("                                            ------------------\n");
    }

    //somar +1 a variável g para sequenciar o número das questões.
    g++;

    return 0;
}

//laço para atribuir as alternativas a matriz do jogador 2.
int lacoj2 (){

    //laço para atribuir as alternativas a matriz.
    for(int k=0; k<4; k++){
        j2 [k][g] = r + k - o;
    }

    //laço para mostrar as alternativas na tela do usuário.
    for (int z=0; z<4; z++){
        printf("                                   %i\n", j2 [z][g]);
    }

    printf("                                   Resposta:");
    scanf("%d",&j);

    //condição para verificar se a resposta digitada pelo jogador está correta.
    if(j == r){
        printf("\n                                            ********************\n");
        printf("                                            *Jogador 2 Acertou!*\n");
		printf("                                            ********************\n");
        s2++;
    }else{
        printf("\n                                            ------------------");
        printf("\n                                            |Jogador 2 Errou!|\n");
		printf("                                            ------------------\n");
    }

    //somar +1 a variável g para sequenciar o número das questões.
    g++;

    return 0;
}

//função criada para gerar um pergunta de soma para o jogador 1.
int perguntadesomaj1 (){

    r=c+i;  

    printf("\n                                   ##Questao %i para %s - Quanto eh %d + %d ?\n",g,nome1,c,i);
    printf("                                   Alternativas:\n");

    lacoj1 ();

    return 0;
}

//função criada para gerar um pergunta de soma para o jogador 2.
int perguntasdesomaj2 (){

    r=c+i;

    printf("\n                                   ##Questao %i para %s - Quanto eh %d + %d ?\n",g,nome2,c,i);
    printf("                                   Alternativas:\n");

    lacoj2 ();

    return 0;
}

//função criada para gerar um pergunta de subtração para o jogador 1.
int perguntadesubtracaoj1 (){

    r=c-i;

    printf("\n                                   ##Questao %i para %s - Quanto eh %d - %d ?\n",g,nome1,c,i);
    printf("                                   Alternativas:\n");

    lacoj1 ();

    return 0;
}

//função criada para gerar um pergunta de subtração para o jogador 2.
int perguntasdesubtracaoj2 (){

    r=c-i;

    printf("\n                                   ##Questao %i para %s - Quanto eh %d - %d ?\n",g,nome2,c,i);
    printf("                                   Alternativas:\n");

    lacoj2 ();

    return 0;
}

//função criada para gerar um pergunta de multiplicação para o jogador 1.
int perguntademultiplicacaoj1 (){

    r=c*i;

    printf("\n                                   ##Questao %i para %s - Quanto eh %d x %d ?\n",g,nome1,c,i);
    printf("                                   Alternativas:\n");

    lacoj1 ();

    return 0;
}

//função criada para gerar um pergunta de multiplicação para o jogador 2.
int perguntasdemultiplicacaoj2 (){

    r=c*i;

    printf("\n                                   ##Questao %i para %s - Quanto eh %d x %d ?\n",g,nome2,c,i);
    printf("                                   Alternativas:\n");

    lacoj2 ();
    
    return 0;
}


int main() { 
    
    inicio ();

    lerhistorico ();

    //laço para gerar 2 vezes 
    for(int l=1; l<=2; l++){

    //Questões jogador 1
    
    geracaoaleatoria();
    perguntadesomaj1 ();

    geracaoaleatoria();
    perguntadesubtracaoj1 ();

    geracaoaleatoria();
    perguntademultiplicacaoj1 ();

    //Questões jogador 2

    geracaoaleatoria();
    perguntasdesomaj2 ();

    geracaoaleatoria();
    perguntasdesubtracaoj2 ();
    
    geracaoaleatoria();
    perguntasdemultiplicacaoj2 ();
    
    }

    scores ();
      
    gravarhistorico ();

    return 0;
}