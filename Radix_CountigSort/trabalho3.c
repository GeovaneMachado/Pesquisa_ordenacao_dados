// NOME: Geovane Machado dos Santos
#include<stdio.h>
#include<stdlib.h>

typedef struct 
{
    int ano;
    char modelo[10];
}Carro;


void print(Carro vet[])
{
    for(int i = 0; i<15; i++)
        printf("N %d = Ano: %d   Modelo: %s\n\n", i+1, vet[i].ano, vet[i].modelo);
}



void RadixSort(Carro vet[], int n)
{
    int i, max = vet[0].ano;
    for(i=0; i < n; i++) 
        if(vet[i].ano>max) 
            max = vet[i].ano; //Verifica qual o maior elemento dentrro do vetor
    for(i = 1; max/i>0; i*=10) CountingSort(vet, n, i); 
}



int CountingSort(Carro vet[], int n, int pos)
{
    int i, count[10], number;
    Carro aux[n]; //Aux tem o tamanho do maior elemento no vetor principal +1
    for(i=0;i< 10;i++) count[i] =0;  //inicia o vetor aux com 0
    for(i=0;i< n;i++)
    {
        number = (vet[i].ano/pos) % 10; //Isola o digito
        count[number]++;
    }
    for(i=1;i< 10;i++) count[i] += count[i-1]; //Acumula os valores no vetor
    for(i=n-1;i>=0;i--)
    {
        number = (vet[i].ano/pos) % 10;
        count[number]--;
        aux[count[number]] = vet[i]; //Vai colocar os valores na ordem certa
    }
    for(i=0; i<n; i++) vet[i] = aux[i]; //Copia para o vetor original
}

int main()
{
    Carro cars[15] = 
    {
        {1970, "Fusca"},
        {1980, "Brazilia"},
        {1970, "Opala"},
        {2013, "Mustang"},
        {2011, "Fox"},
        {2007, "Uno"},
        {1960, "Opala"},
        {2013, "Gol"},
        {1996, "Vectra"},
        {2019, "Fox"},
        {2021, "Hb20"},
        {1997, "Marea"},
        {1999, "Vectra"},
        {1999, "Santana"},
        {2013, "LaFerrari"}
    };
    RadixSort(cars, 15); //ORGANIZA O VETOR
    print(cars); //IMPRIME O VETOR ORGANIZADO
    return 0;
}
