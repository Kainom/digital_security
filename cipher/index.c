#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *mensagem = "Hello,World!";
char *encripty_message;
void cifra(char *mensagem,int deslocamento);




int main(){
    int value;
    printf("%s\n",mensagem);

    printf("Por favor,insira um valor inteiro positivo diferente de zero: ");

    scanf("%d",&value);

    if(value <=0){
        printf("O valor não pode ser menor ou igual a zero\n");
    }

    cifra(mensagem);

}



void cifra(char *mensagem,int deslocamento){
    deslocamento = deslocamento % 26;
    for (int i = 0; mensagem[i] != '\0'; i++) {
        if(mensagem[i] >= 65 && mensagem[i] <=90){
           
            if(deslocamento >90){
                *encripty_message = 65 +  (deslocamento - 90)
            }

        } else{
            *encripty_message = mensagem[i];
        }
    }
}