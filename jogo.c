#include <stdio.h>
#include <stdlib.h>
#include <time.h>

    int main()
{
    // Imprime o cabeçalho do jogo
    printf("********************************************************\n");
    printf("*       Bem Vindo ao Nosso Jogo de Adivinhação         *\n");
    printf("* Vamos ver se você consegue adivinhar o número secreto*\n");
    printf("********************************************************\n");
    printf("\n");
    int segundos = time(0);
    srand(segundos);
    int numeroGrande = rand();
    int numeroSecreto = numeroGrande % 100;
    int chute;
    int tentativas = 1;
    double pontos = 1000;
    
    while(1){
        printf("Qual é o seu chute? ");
        scanf("%d", &chute);
        printf("Tentativa %d de \n", tentativas);
        printf("Seu chute foi %d\n", chute);

        if(chute < 0){
            printf("Você não pode chutar números negativos\n");
            continue;
        }

        int acertou = (chute == numeroSecreto);
        int maior = chute > numeroSecreto;
        if (acertou)
        {
            printf("Parabéns você acertou o número secreto\n");
            break;
        }
        else if(maior){
            
            printf("Seu chute foi maior que o número secreto\n");  
        }
        else{
            printf("Seu chute foi menor que o número secreto\n");
        }
        tentativas++;
        double pontosPerdidos = abs(chute - numeroSecreto) / (double)2;
        pontos -= pontosPerdidos;

    }
    printf("fim de jogo\n");
    printf("Você acertou em %d tentativas\n", tentativas);
    printf("Total de pontos: %.1f\n", pontos);
    return 0;
}