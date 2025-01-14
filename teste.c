#include <stdio.h>
#include <stdlib.h>

int main(){
int tabuada = 1;
printf("Escolha a tabuada:" );
scanf("%d", &tabuada );
    for(int i = 1; i<=10; i++){
    printf("%d" "x" "%d ""=" "%d\n", tabuada, i, tabuada * i );
}
return 0; 
}

