#include <stdio.h>


void freadFile(){
    /*Lê arquivo*/
    FILE *file; //define um ponteiro para o arquivo
    char text_content;

    file = fopen("./files/file1.txt", "r");

    if(file){
        while((text_content = getc(file)) != EOF){
        // enquanto cada caractere obtido pelo arquivo for diferente de end of file
            printf("%c", text_content);
        }
    }else{
        printf("Arquivo não encontrado");
    }

    fclose(file); // fecha o processo que abriu o arquivo
}


void fsumNumbersFromFile(){
    /*
    Lê arquivo e calcula a soma dos números contidos
    no arquivo
    */
   FILE *file;
   int sum = 0, num; // é necessário um ponteiro, pois do contrário ele voltara a ler a ultima linha com conteudo
   char analise[10], *lines; // analisa as linhas do arquivo para ver se há quebra

   file = fopen("./files/file2.txt", "r");
   printf("\n");
   if(file){
        while(!feof(file)){
            fscanf(file, "%d", &num);
            lines = fgets(analise, 10, file); // file ou stdin (teclado->standard input)
            if(lines){ // como a ultima verificacao é nula, deve-se ignorala (0)
                sum += num;
            }
         }
        printf("\nA soma vale: %d\n", sum);
   }else{
        printf("Não foi possível abrir o arquivo");
   }
   fclose(file);
}


void fwriteInFile(){
    // escreve no arquivo os numeros
    FILE *file;
    //char enter[10];
    file = fopen("./files/file3.txt", "w"); // w , a etc
    printf("\n");
    if(file != NULL){
       for(int i = 0; i < 10; i++){
            printf("[+]Salvando dados...\n");
            fprintf(file, "%d\n", i);
            //enter[0] =  i;
            // fputs(enter, file); para strings
        }
    }else{
        printf("Houve um problema ao criar o arquivo");
    }
    fclose(file);
}