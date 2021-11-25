#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//MENU DO PROGRAMA, ESCOLHE A ORDEM DE ORGANIZAR

int order_type()
{
    int choice;
    printf("\n\t\tMENU\nESCOLHA A ORDEM:\n[1] - CRESCENTE\n[2] - DECRESCENTE\n[3] - ALEATORIO\n");
    scanf("%d", &choice);
    return choice;
}

void troca_buble(int vet[], int j)
{
    int right;
    right = vet[j];         //right vai receber o valor de vet[j] 
    vet[j] = vet[j+1];       //vet[j] recebe o proximo valor
    vet[j+1] = right;     //O proximo valor do vetor vai receber right
}

int buble(int vet[], int n, int opc)
{
    int i, j, flag = 1, cont = 0;
    if(opc == 1)        //Ordena de forma crescente
    {
        for(i=0; i<n;i++)  //Quantidade de vezes que o j vai percorrer o vetor no pior caso possivel
        {
            flag = 1; //Vai mudar para 1 quando comecar o laco
            for(j=0; j<n;j++) //Percorre o vetor
            {    
                cont += 1; //Contabiliza as comparacoes feitas no vetor
                if(vet[j] > vet[j+1]) //se o valor da posicao j no vetor for maior que o proximo faz a troca
                {
                    troca_buble(vet, j);
                    flag = 0; //Vetor não ordenado quando flag continuar 0
                }
            }
            if(flag == 1) break; //Se continuar em 1 o flag, para  a repeticao e termina a funcao 
        }
    }
    else if(opc == 2)  //Ordena de forma decrescente
    {
        for(i=0; i<n;i++)
        {
            flag = 1;
            for(j=0; j< n;j++)
            {    
                cont += 1;
                if(vet[j] < vet[j+1])//se o valor da posicao j no vetor for menor que o proximo faz a troca
                {
                    troca_buble(vet, j);
                    flag = 0;
                }
            }
            if(flag == 1) break;
        }
    }
    return cont;
}
void troca_selection(int vet, int aux)
{

}

int Selection_sort(int vet[], int n, int choice)
{
    int i, j, aux = vet[0];
    if(choice == 1)
    {
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                if(vet[j] < aux) aux = vet[j];
            }
        }
    }
}

void printVet(int vet[], int n)
{
    int i;
    for(i = 0; i<n; i++)
    {
        printf("valor %d: %d\n", i, vet[i]);
    } 
}


int main()
{
    printf("Digite o tamanho do vetor: ");
    int n, i, cont, opc = 1; 
    double time;
    clock_t start, end;
    scanf("%d", &n);
    int vet[n];
    for(i = 0;i<n; i++)
    {
        printf("Valor %d: ", i);
        scanf("%d", &vet[i]);
    }
    int choice = order_type();
    start = clock();
    cont = buble(vet, n, choice);
    end = clock();
    time =((double)end - start)/CLOCKS_PER_SEC;
    printVet(&vet, n);    
    printf("Tempo Buble: %lf ms, Comparacoes: %d", time*1000, cont);
    return 0;
}
