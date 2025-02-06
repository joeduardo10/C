#include <stdio.h>
#include<stdlib.h>
#include <string.h>
#include <time.h>
#include "forca.h"

// variáveis globais
char palavrasecreta[TAMANHO_PALAVRA];
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
    int erros = chuteserrados();

printf("  _______       \n");
printf(" |/      |      \n");
printf(" |      %c%c%c  \n", (erros>=1?'(':' '), 
    (erros>=1?'_':' '), (erros>=1?')':' '));
printf(" |      %c%c%c  \n", (erros>=3?'\\':' '), 
    (erros>=2?'|':' '), (erros>=3?'/': ' '));
printf(" |       %c     \n", (erros>=2?'|':' '));
printf(" |      %c %c   \n", (erros>=4?'/':' '), 
    (erros>=4?'\\':' '));
printf(" |              \n");
printf("_|___           \n");
printf("\n\n");

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
//ADICIONA PALAVRA
void adicionapalavra(){
    char quer;
    printf("Você deseja adicionar uma nova palavra ao jogo? (S / N)");
    scanf(" %c", &quer);
    if(quer == 'S'){
        char novapalavra[TAMANHO_PALAVRA];
        printf("Qual a nova palavra?");
        scanf("%s", novapalavra);
        FILE* f;
        f = fopen("palavras.txt", "r+");
           if(f == 0){
            printf("Desculpe banco de dados não disponível\n\n");
            exit(1);
        }
        int qtd;
        fscanf(f,"%d", &qtd);
        qtd++;
        fseek(f, 0, SEEK_SET);
        fprintf(f, "%d", qtd);
        fseek(f, 0, SEEK_END);
        fprintf(f, "\n%s",novapalavra);
        fclose;
    }
}
// Essa função não foi discutida no último vídeo
void escolhepalavra() {
    FILE* f;
   f = fopen("palavras.txt","r");
   if(f == 0){
    printf("Desculpe banco de dados não disponível\n\n");
    exit(1);
   }
   int qtddepalavras;
   fscanf(f,"%d", &qtddepalavras);
   
   srand(time(0));
   int randomico = rand() % qtddepalavras;
   for(int i=0; i<= randomico; i++){
        fscanf(f, "%s", palavrasecreta );
   }

   fclose(f);
}
int chuteserrados(){

    int erros = 0;
    
    for(int i = 0; i < chutesdados; i++) {

        int existe = 0;
        for(int j = 0; j < strlen(palavrasecreta); j++) {
            if(chutes[i] == palavrasecreta[j]) {
                existe = 1;
                break;
            }
        }
        if(!existe) erros++;
    }
    return erros;
}
int enforcou() {
    return chuteserrados()>=5;

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
    if(acertou()){
        printf("parabens você ganhou !!!\n\n");
            printf("       ___________      \n");
    printf("      '._==_==_=_.'     \n");
    printf("      .-\\:      /-.    \n");
    printf("     | (|:.     |) |    \n");
    printf("      '-|:.     |-'     \n");
    printf("        \\::.    /      \n");
    printf("         '::. .'        \n");
    printf("           ) (          \n");
    printf("         _.' '._        \n");
    printf("        '-------'       \n\n");
    }else{
        printf("que pena... você perdeu tente novamente ! \n");
        printf("A palavra era: %s \n\n", palavrasecreta);

    printf("    _______________         \n");
    printf("   /               \\       \n"); 
    printf("  /                 \\      \n");
    printf("//                   \\/\\  \n");
    printf("\\|   XXXX     XXXX   | /   \n");
    printf(" |   XXXX     XXXX   |/     \n");
    printf(" |   XXX       XXX   |      \n");
    printf(" |                   |      \n");
    printf(" \\__      XXX      __/     \n");
    printf("   |\\     XXX     /|       \n");
    printf("   | |           | |        \n");
    printf("   | I I I I I I I |        \n");
    printf("   |  I I I I I I  |        \n");
    printf("   \\_             _/       \n");
    printf("     \\_         _/         \n");
    printf("       \\_______/           \n");

    }
    adicionapalavra();

}
