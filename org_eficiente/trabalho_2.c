#include<stdio.h>
#include<stdlib.h>
#include<time.h>



void intercala(int vet[], int inicio,int meio, int fim)
{
    int *aux = (int *)malloc(sizeof(fim - inicio +1));
    int i = inicio, j = meio + 1, k = 0;
    while (i<=meio && j<= fim)
    {
        if(vet[i] <=vet[j]) i++;
        else
        {
            aux[k] = vet[i];
            j++;
        }
        k++;
    }
    while(i<=meio)
    {
        aux[k] = vet[i];
        k++;
        i++;
    }
    while(j<=fim)
    {
        aux[k] = vet[j];
    }
}


//MENU DO PROGRAMA, ESCOLHE A ORDEM DE ORGANIZA

int order_type()
{
    int choice;
    printf("\n\t\tMENU\nESCOLHA A ORDEM:\n[1] - CRESCENTE\n[2] - DECRESCENTE\n[3] - ALEATORIO\n");
    scanf("%d", &choice);
    if(choice > 3 || choice <= 0) return order_type();
    else return choice;
}


void cria_vetor(int vet_merge[], int vet_quick[], int vet_heap[], int tamanho)
{
    int choice = order_type(), i;
    if(choice == 1) //Cria vetor em ordem crescente
    {
        for(i=0;i<tamanho;i++)
        {
            vet_merge[i] = i;
            vet_quick[i] = i; 
            vet_heap[i] = i;
        }
    }
    else if(choice == 2)//Cria vetor em ordem decrescente
    {
        int valor = 0;
        for(i=tamanho;i>=0;i--)
        {
            vet_merge[i] = valor;
            vet_quick[i] = valor; 
            vet_heap[i] = valor;
            valor++;
        }
    }
    else       //Cria vetor em ordem aleatoria
    {
        int valor;
        for(i=0;i<tamanho;i++)
        {
            valor = rand()%100;
            vet_merge[i] = valor;
            vet_quick[i] = valor; 
            vet_heap[i] = valor;
        }
    }
}

void print(int vet[], int n)
{
    for(int i = 0; i<n;i++)printf("valor %d: %d\n", i, vet[i]);
}

int main()
{
    int n, i, cont; 
    double time;
    clock_t start, end;
    printf("Digite o tamanho do vetor: ");
    scanf("%d", &n);
    int vet_merge[n], vet_quick[n], vet_heap[n]; //Cria os vetores que vão ser ordenados
    cria_vetor(vet_merge, vet_quick, vet_heap, n); //Insere o valor nos vetores 
    print(vet_heap, n);
    /*=================================================================================================
    start = clock(); //Conta o tempo 
    end = clock();
    time =((double)end - start)/CLOCKS_PER_SEC;    
    printf("Tempo Merge: %lf ms, Comparacoes: %d \n", time*1000, cont);
    start = clock();//Conta o tempo 
    end = clock();
    time =((double)end - start)/CLOCKS_PER_SEC;    
    printf("Tempo Quick: %lf ms, Comparacoes: %d \n", time*1000, cont);
    start = clock(); //Conta o tempo 
    end = clock();
    time =((double)end - start)/CLOCKS_PER_SEC;
    printf("Tempo Heap: %lf ms, Comparacoes: %d \n", time*1000, cont); 
    ===================================================================================================*/
    return 0;
}
