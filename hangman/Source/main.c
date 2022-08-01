#include <stdio.h>
#include "prototypes.h"
#include <stdlib.h>

// checagem dos sistemas
#ifdef __unix__         
    #include <unistd.h>
    #include <stdlib.h>

#elif defined(_WIN32) || defined(WIN32) 

   #define OS_Windows

   #include <windows.h>

#endif


void clear();
char* randomicWord();
void intro();


int main(){
    // funcao principal
    // para sair, o usuario deve apertar o numero zero
    int start = 1, intro_;
    char option;



    printf("******* WELCOME TO THE HANGMAN GAME ********\n");
    
    intro();
    scanf("%d", &intro_);
    if(intro_ == 2){
        printf("This is version of the classic letter guessing game called Hangman. You are shown a set of blank letters that match a word or phrase and you have to guess what these letters are to reveal the hidden word.");
        printf("\nYou guess by picking letters from those displayed on the sides. When the man is inished, he is hung and the game is lost. \n");
        exit(0);
    }else if(intro_ == 3){
        printf("bye");
        exit(0);
    }
    clear();
     fflush(stdin);  // limpa o buffer de entrada para o proximo scanf ler normalmente, sem o enter
    // loop principal do jogo (main loop)
     while(start){
       
        printf("press 0 to exit\n");
        printf("choice a char: ");
        scanf("%c", &option);
        printf("\n");
        if(option != ' ' || option != '\n'){
            if(option == 0) start = 0;
            start = correctChar(option, randomicWord());
        }
        fflush(stdin);  // limpa o buffer de entrada para o proximo scanf ler normalmente, sem o enter
        //clear();
        
    }
}


char* randomicWord(){
    //generate a 'randomic' word
    // for a 1 version, thats dont be real randomic
    return "Hello";
}

void clear(){
    #ifdef OS_Windows
    /* limpa a tela windows */
        system("cls");
    #else
    /* limpa a tela unix */
        system("clear");
    #endif 
}


void intro(){
    printf("\n------- Choise a option -------");
    printf("\n------- 1) - to start -------");
    printf("\n------- 2) - to help -------");
    printf("\n------- 3) to exit -------");
    printf("\nOPTION: ");
    printf("\n");
    fflush(stdin);
}