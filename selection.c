#include<stdio.h>
#include<stdlib.h>

void swap(int vet[], int i, int j)      //Faz a troca de um valor de m vetor da posição i para a posição j
{
    int aux;
    aux = vet[j];        
    vet[j] = vet[i];       
    vet[i] = aux;     
}

void heap(int vet[], int n)
{
    int i;
    for(i= n/2-1; i >= 0; i--) CriaHeap(vet, i, n); //Organiza o heap da subarvore 
    for(i = n-1; i >= 1; i--)
    {
        swap(vet, 0, i);
        CriaHeap(vet, 0, i); //Vai reorganizar deixando de fora os ordenados
    }

}

void CriaHeap(int vet[], int i, int n)
{
    int maior = i;
    int left = 2*i+1; 
    int right = 2*i+2;
    if(left<n && vet[left]>vet[maior]) maior = left;  //Se o left ou right for menor que o tamanho do vetor e a 
    if(right<n && vet[right]>vet[maior]) maior = right; //posição de um deles no vetor for maior que a variavel maior, muda o valor de maior
    if(maior!=i) //Se a raiz não for o valor maior faz a troca com o maior valor
    {
        swap(vet, i, maior);
        CriaHeap(vet, maior, n); //Recusividade para as subarvores
    }
    p(vet);
}

void p(int vet[])
{
    for(int i = 0; i<10; i++)
        printf("%i; ", vet[i]);
    printf("\n");
}

int main()
{
    int vet[10] = {29, 93, 14, 54, 0, 75, 33, 29, -1, 60};
    heap(vet, 10);
    p(vet);
    return 0;
}