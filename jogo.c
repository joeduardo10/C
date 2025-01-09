#include <stdio.h>
#include <stdlib.h>

int main() {
    // Imprime o cabeçalho do jogo
    printf("********************************************************\n");
    printf("* Bem Vindo ao Nosso Jogo de Adivinhação               *\n");
    printf("* Vamos ver se você consegue adivinhar o número secreto* \n");
    printf("*********************************************************\n");
    printf("\n");
    int numeroSecreto = 42;
    int chute;
    printf("Qual é o seu chute? ");
    scanf("%d", &chute);
    printf("Seu chute foi %d\n", chute);

    if (chute == numeroSecreto)
    {
        printf("Parabéns você acertou o número secreto\n");
    }
    else
    {
        printf("que pena você errou o chute\n");
    }

    return 0;
}