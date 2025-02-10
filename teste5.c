// Jogo da Velha em C geredo por IA nao funcionou
#include <stdio.h>
#include <stdlib.h>

#define SIZE 3

// Função para inicializar o tabuleiro com espaços vazios
void inicializarTabuleiro(char tabuleiro[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            tabuleiro[i][j] = ' ';
        }
    }
}

// Função para imprimir o tabuleiro
void imprimirTabuleiro(char tabuleiro[SIZE][SIZE]) {
    system("clear"); // Use "cls" no Windows
    printf("\n Jogo da Velha\n\n");
    for (int i = 0; i < SIZE; i++) {
        printf(" ");
        for (int j = 0; j < SIZE; j++) {
            printf(" %c ", tabuleiro[i][j]);
            if(j < SIZE - 1)
                printf("|");
        }
        printf("\n");
        if(i < SIZE - 1)
            printf("-----------\n");
    }
    printf("\n");
}

// Função para verificar se há um vencedor ou empate
// Retorna 'X' ou 'O' se houver vencedor, 'E' se empate ou ' ' se o jogo continua.
char verificarVencedor(char tabuleiro[SIZE][SIZE]) {
    // Verifica linhas e colunas
    for (int i = 0; i < SIZE; i++) {
        if (tabuleiro[i][0] != ' ' && tabuleiro[i][0] == tabuleiro[i][1] && tabuleiro[i][1] == tabuleiro[i][2])
            return tabuleiro[i][0];
        if (tabuleiro[0][i] != ' ' && tabuleiro[0][i] == tabuleiro[1][i] && tabuleiro[1][i] == tabuleiro[2][i])
            return tabuleiro[0][i];
    }
    // Verifica diagonais
    if (tabuleiro[0][0] != ' ' && tabuleiro[0][0] == tabuleiro[1][1] && tabuleiro[1][1] == tabuleiro[2][2])
        return tabuleiro[0][0];
    if (tabuleiro[0][2] != ' ' && tabuleiro[0][2] == tabuleiro[1][1] && tabuleiro[1][1] == tabuleiro[2][0])
        return tabuleiro[0][2];

    // Verifica empate ou jogo continua
    int espacosLivres = 0;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (tabuleiro[i][j] == ' ')
                espacosLivres++;
        }
    }
    if (espacosLivres == 0)
        return 'E'; // Empate

    return ' '; // Jogo continua
}

int main() {
    char tabuleiro[SIZE][SIZE];
    int linha, coluna;
    char jogadorAtual = 'X';
    char resultado = ' ';
    
    inicializarTabuleiro(tabuleiro);

    while (resultado == ' ') {
        imprimirTabuleiro(tabuleiro);
        printf("Vez do jogador %c. Digite linha e coluna (0, 1 ou 2): ", jogadorAtual);
        
        if (scanf("%d %d", &linha, &coluna) != 2) {
            printf("Entrada inválida. Tente novamente.\n");
            while(getchar() != '\n'); // limpar buffer
            continue;
        }

        // Verificar se a posição é válida e está vazia
        if (linha < 0 || linha >= SIZE || coluna < 0 || coluna >= SIZE) {
            printf("Posição inválida. Tente novamente.\n");
            continue;
        }
        if (tabuleiro[linha][coluna] != ' ') {
            printf("Posição já ocupada. Tente novamente.\n");
            continue;
        }

        // Marca a jogada
        tabuleiro[linha][coluna] = jogadorAtual;
        
        // Verifica se houve vitória ou empate
        resultado = verificarVencedor(tabuleiro);
        
        // Troca de jogador
        if (jogadorAtual == 'X')
            jogadorAtual = 'O';
        else
            jogadorAtual = 'X';
    }
    
    imprimirTabuleiro(tabuleiro);
    if (resultado == 'E') {
        printf("O jogo terminou empatado!\n");
    } else {
        // Trocar jogador novamente para indicar quem foi o último a jogar
        if (jogadorAtual == 'X')
            printf("O vencedor é o jogador O!\n");
        else
            printf("O vencedor é o jogador X!\n");
    }
    
    return 0;
}