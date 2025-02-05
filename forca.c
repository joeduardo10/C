#include <stdio.h>
#include <string.h>
#include "forca.h"



// variáveis globais
char palavrasecreta[20];
char chutes[26];
int chutesdados = 0;

// agora aqui começam as implementações das funções,
// do jeito que você está acostumado.


void abertura() {
    printf("/****************/\n");
    printf("/ Jogo de Forca */\n");
    printf("/****************/\n\n");
}

void chuta() {
    char chute;
    printf("Qual letra? ");
    scanf(" %c", &chute);

    chutes[chutesdados] = chute;
}

// Essa função não foi discutida no último vídeo
int jachutou(char letra) {
    int achou = 0;
    for(int j = 0; j < chutesdados; j++) {
        if(chutes[j] == letra) {
            achou = 1;
            break;
        }
    }

    return achou;
}

// Essa função não foi discutida no último vídeo
void desenhaforca() {

    printf("Você já deu %d chutes\n", chutesdados);

    for(int i = 0; i < strlen(palavrasecreta); i++) {

        if(jachutou(palavrasecreta[i])) {
            printf("%c ", palavrasecreta[i]);
        } else {
            printf("_ ");
        }

    }
    printf("\n");

}

// Essa função não foi discutida no último vídeo
void escolhepalavra() {
    sprintf(palavrasecreta, "MELANCIA");
}
int enforcou() {

    int erros = 0;

    // vamos fazer o loop em todos os chutes dados
    for(int i = 0; i < chutesdados; i++) {

        int existe = 0;
        // agora vamos olhar letra a letra da palavra secreta
        // e ver se encontramos o chute aqui
        for(int j = 0; j < strlen(palavrasecreta); j++) {
            if(chutes[i] == palavrasecreta[j]) {
                // encontramos, vamos quebrar o loop
                existe = 1;
                break;
            }
        }
        // se nao encontrou, soma um na quantidade de erros
        if(!existe) erros++;
    }
    // se tivermos mais do que 5 erros, retornamos 1
    // caso contrario, retornamos 0.
    return erros >= 5;
}
int acertou() {
    for(int i = 0; i < strlen(palavrasecreta); i++) {
        if(!jachutou(palavrasecreta[i])) {
            return 0;
        }
    }

    return 1;
}

int main() {
    abertura();
    escolhepalavra();

    do {

        desenhaforca();
        chuta();

        chutesdados++;

    } while (!acertou() && !enforcou());

}
