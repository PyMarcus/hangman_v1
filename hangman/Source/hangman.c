#include <stdio.h>
#include "prototypes.h"


// parametros
char correct[5] = {0, 0, 0, 0, 0};
int erros = 0;


void lines(int lenght_of_word){
    // pega o tamanho da palavra e desenha os tracejados
    for(int countt = 0; countt < lenght_of_word; countt ++){
        printf("__  ");
    }
}


int youAreWrong(int erro){
    // se estiver errado, pode cancelar a execucao
    // ou exibir o hangman
    printf("ERROR: %d", erro);
    printf("\n");
    switch (erro)
    {
    case 1:
        head();
        break;
    case 2:
        armRight();
        break;
    case 3:
        armLeft();
        break;
    case 4:
        body();
        break;
    case 5:
        legRight();
        break;
    case 6:
        legLeft();
        break;  
    case 7:
        gameOver();
        return 1;
        break;
    default:
        break;
    }
    return 0;
}


int correctChar(char insert, char string_choised[5]){
    /* verifica se a letra informa da está
     na string escolhida 'randomicamente'
     se estiver, desenha a nova linha
     :param insert: letra informada pelo player
     :param string_choised: palavra escolhida pelo jogo
     :return 0 ou 1 (true or false)
     */
    
    int count = 0;

    printf("\n");

    int correctt = 0;
    for(int i = 0; i < 5; i++){
        if(insert == string_choised[i]){
             correct[i] = insert;  
             correctt = 1;
        }
    }
    // verifica se correct já está preenchido
    for(int i = 0; i < 5; i++){
        if(correct[i] != 0) count++;
    }
    // se estiver, o usuario ganhou
    if(count >= 5){
        printf("word: %s", string_choised);
        printf("\n ****** WINNER!!! ******\n");
        return 0;
    }


    if(correctt == 0){
        erros++;
    }


   int response = youAreWrong(erros);
   if(response == 1){
    return 0;
   }

    

    for(int i = 0; i < 5; i++){
        if(correct[i] != 0) printf(" %c ", correct[i]);
        else printf(" __ ");        
    }
    printf("\n");
    return 1;
}