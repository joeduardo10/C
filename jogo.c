#include <stdio.h>
#include <stdlib.h>
#include <time.h>

    int main()
{
    // Imprime o cabeçalho do jogo
// printf("                        _   |~  _\n"
//        "                       [_]--'--[_]\n"
//        "                       |'|\"\"`\"\"|'|\n"
//        "                       | | /^/ | |\n"
//        "                       |_|_|I|_|_|\n"
//        "********************************************************\n"
//        "*       Bem Vindo ao Nosso Jogo de Adivinhação         *\n"
//        "* Vamos ver se você consegue adivinhar o número secreto*\n"
//        "********************************************************\n\n");
   printf("\n");
   printf("!_\n"
           "                                                  |*~=-.,\n"
           "                                                  |_,-'`\n"
           "                                                  |\n"
           "                                                  |\n"
           "                                                 /^\\\n"
           "                   !_                           /   \\\n"
           "                   |*`~-.,                     /,    \\\n"
           "                   |.-~^`                     /#\"     \\\n"
           "                   |                        _/##_   _  \\_\n"
           "              _   _|  _   _   _            [ ]_[ ]_[ ]_[ ]\n"
           "             [ ]_[ ]_[ ]_[ ]_[ ]            |_=_-=_ - =_|\n"
           "           !_ |_=_ =-_-_  = =_|           !_ |=_= -    |\n"
           "           |*`--,_- _        |            |*`~-.,= []  |\n"
           "           |.-'|=     []     |   !_       |_.-\"`_-     |\n"
           "           |   |_=- -        |   |*`~-.,  |  |=_-      |\n"
           "          /^\\  |=_= -        |   |_,-~`  /^\\ |_ - =[]  |\n"
           "      _  /   \\_|_=- _   _   _|  _|  _   /   \\|=_-      |\n"
           "     [ ]/,    \\[ ]_[ ]_[ ]_[ ]_[ ]_[ ]_/,    \\[ ]=-    |\n"
           "      |/#\"     \\_=-___=__=__- =-_ -=_ /#\"     \\| _ []  |\n"
           "     _/##_   _  \\_-_ =  _____       _/##_   _  \\_ -    |\\\n"
           "    [ ]_[ ]_[ ]_[ ]=_0~{_ _ _}~0   [ ]_[ ]_[ ]_[ ]=-   | \\\n"
           "    |_=__-_=-_  =_|-=_ |  ,  |     |_=-___-_ =-__|_    |  \\\n"
           "     | _- =-     |-_   | ((* |      |= _=       | -    |___\\\n"
           "     |= -_=      |=  _ |  `  |      |_-=_       |=_    |/+\\|\n"
           "     | =_  -     |_ = _ `-.-`       | =_ = =    |=_-   ||+||\n"
           "     |-_=- _     |=_   =            |=_= -_     |  =   ||+||\n"
           "     |=_- /+\\    | -=               |_=- /+\\    |=_    |^^^|\n"
           "     |=_ |+|+|   |= -  -_,--,_      |_= |+|+|   |  -_  |=  |\n"
           "     |  -|+|+|   |-_=  / |  | \\     |=_ |+|+|   |-=_   |_-/\n"
           "     |=_=|+|+|   | =_= | |  | |     |_- |+|+|   |_ =   |=/\n"
           "     | _ ^^^^^   |= -  | |  <&>     |=_=^^^^^   |_=-   |/\n"
           "     |=_ =       | =_-_| |  | |     |   =_      | -_   |\n"
           "     |_=-_       |=_=  | |  | |     |=_=        |=-    |\n"
           "^^^^^^^^^^`^`^^`^`^`^^^\"\"\"\"\"\"\"\"^`^^``^^`^^`^^`^`^``^`^``^``^^\n"
           "                Bem vindo ao jogo de adivinhação\n\n");   


    int segundos = time(0);
    srand(segundos);
    int numeroGrande = rand();
    int numeroSecreto = numeroGrande % 100;
    int chute;
    int tentativas = 1;
    double pontos = 1000;
    int acertou = 0;
    int nivel;
    printf("Qual o nível de dificuldade?\n\n");
    printf("(1) Fácil (2) Médio (3) Difícil\n\n\n");
    printf("Escolha: ");
    scanf("%d", &nivel);
    
    int nr_tentativas;
    
    switch(nivel){
        case 1:
            nr_tentativas = 18;
            break;
        case 2:
            nr_tentativas = 12;
            break;
        default:
            nr_tentativas = 6;
            break;
    }

    for(int i = 1; i <= nr_tentativas; i++){
        printf("Qual é o seu chute? ");
        scanf("%d", &chute);
        printf("Tentativa %d de \n", tentativas);
        printf("Seu chute foi %d\n", chute);

        if(chute < 0){
            printf("Você não pode chutar números negativos\n");
            continue;
        }
        acertou = (chute == numeroSecreto);
        int maior = chute > numeroSecreto;
        if (acertou){
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
    printf("¯\\(°_o)/¯\n");
    printf("fim de jogo\n ");
    if(acertou){
        printf("Parabéns! Você Ganhou !!! 	(*・‿・)ノ⌒*:･ﾟ✧ \n");
        printf("Você acertou em %d tentativas\n", tentativas);
        printf("Total de pontos: %.1f\n", pontos);
    }else{
        printf("Você perdeu! (︶︹︶)\n o nr sorteado foi %d  -  Tente novamente\n", numeroSecreto);
    }
    return 0;
}