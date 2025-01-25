#include <stdio.h>
#include <string.h>

void abertura(){
    printf("**********************************************\n");
    printf("**         J O G O   DE   F O R C A         **\n");
    printf("**********************************************\n\n");
}

void chuta(char chutes[26], int* tentativas){
    char chute;
    scanf(" %c", &chute); // espaço " %c" ignora a quebra de linha
    chutes[(*tentativas)] = chute;
    (*tentativas)++;
}
int jachutou(char letra, char chutes[26],int tentativas){
int achou = 0;
for(int j = 0; j < tentativas; j++){
    if(chutes[j] == letra){
        achou = 1;
        break;
        }   
    }
    return achou;
}
void desenhaforca(char palavrasecreta[20], char chutes[26], int tentativas){
     for (int i = 0; i < strlen(palavrasecreta); i++){
        int achou = jachutou(palavrasecreta[i], chutes, tentativas);
         if(achou){
            printf("%c ", palavrasecreta[i]);
            }else {
                printf("_ ");
            }
        }
        printf("\n"); //\n\n
}
void escolhepalavra (char palavrasecreta[20]){
    sprintf(palavrasecreta, "MELANCIA");
}          


int main()
{
    char palavrasecreta[20];
    int acertou = 0;
    int enforcou = 0;
    char chutes[26];
    int tentativas = 0;

    escolhepalavra(palavrasecreta);
    abertura();

    do{
        desenhaforca(palavrasecreta, chutes, tentativas);
        
        chuta(chutes,&tentativas);
        
    } while (!acertou && !enforcou);
}