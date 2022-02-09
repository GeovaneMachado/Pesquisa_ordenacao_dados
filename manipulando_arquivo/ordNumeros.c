#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main(){
    FILE* arq = fopen("numeros.txt", "rt");
    if(arq == NULL){
        printf("Erro ao abrir arquivo!!");
        exit(1);
    }
    int vet[20];
    int i = 0;
    while (!feof(arq))
    {
        if(fgetc(arq) != ' ' || fgetc(arq) != ',') vet[i] = fgetc(arq);
    }
    for(int i=0; i<20; i++) printf("%d -", vet[i]);
    return 0;
}