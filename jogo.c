#include <stdio.h>
#include <stdlib.h>
#define NUMERO_DE_TENTATIVAS 5

int main()
{
    // Imprime o cabeçalho do jogo
    printf("********************************************************\n");
    printf("*       Bem Vindo ao Nosso Jogo de Adivinhação         *\n");
    printf("* Vamos ver se você consegue adivinhar o número secreto*\n");
    printf("********************************************************\n");
    printf("\n");
    int numeroSecreto = 42;
    int chute;
    
    for (int i = 1; i <= NUMERO_DE_TENTATIVAS; i++)
    {
        printf("Qual é o seu chute? ");
        scanf("%d", &chute);
        printf("Tentativa %d de %d\n", i, NUMERO_DE_TENTATIVAS);
        printf("Seu chute foi %d\n", chute);

        if(chute < 0){
            printf("Você não pode chutar números negativos\n");
            i--;
            continue;
        }

        int acertou = (chute == numeroSecreto);
        int maior = chute > numeroSecreto;
        int menor = chute < numeroSecreto;

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
        
    }
    printf("fim de jogo\n");
    return 0;
}