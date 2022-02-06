#include<stdio.h>
#include<stdlib.h>
#include<string.h>



void Abrir(FILE* arquivo){
    arquivo = fopen("input.txt", "r+");
    if (arquivo == NULL){
        printf("Erro");        
        exit(1);
    }
}
//20 - Geovane Machado dos Santos;
void LerDados(FILE *arquivo){
    char nome[40];
    int id;
    /*
    fscanf(arquivo, "%d - %s;\n", &id, nome);
    printf("id: %d\n Nome: %s\n", id, nome);*/
    while( fscanf(arquivo, "%d - %s", &id, nome) != EOF )
    {
        printf("%d - %s\n", id, nome);
    }
}

void Escreve(FILE* arquivo){
    int id;
    char texto[100];
    scanf("%d - %s", &id, texto);
    fprintf(arquivo, "%d - %s;\n", id, texto);
}

int main(){
    FILE* arquivo;
    //Abrir(arquivo);
    arquivo = fopen("input.txt", "r+");
    if (arquivo == NULL){
        printf("Erro");        
        exit(1);
    }
    //Escreve(arquivo);
    LerDados(arquivo);
    return 0;
}