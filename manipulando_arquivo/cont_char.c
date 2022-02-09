#include<stdio.h>
#include<stdlib.h>

int main(){
    FILE* arq = fopen("TExtoQualquer.txt", "rt");
    if(arq == NULL){
        printf("Erro ao abrir arquivo!!");
        exit(1);
    }
    int contCar = 0, contEsp = 0, contQuebraLinha = 0;
    char esp;
    while(!feof(arq)){
        esp = fgetc(arq);
        if(esp == ' '){
            contEsp++;
        }
        else if (esp == '\n')
        {
            contQuebraLinha++;
        }
        else{
            contCar++;
        }
    }
    printf("\nChar: %d\nEspaco: %d\nQuebra Linha: %d\n", contCar-1, contEsp, contQuebraLinha);
    fclose(arq);
    return 0;
}