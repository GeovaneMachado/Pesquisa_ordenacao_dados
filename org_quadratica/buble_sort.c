#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//MENU DO PROGRAMA, ESCOLHE A ORDEM DE ORGANIZAR

int order_type()
{
    int choice;
    printf("\n\t\tMENU\nESCOLHA A ORDEM:\n[1] - CRESCENTE\n[2] - DECRESCENTE\n[3] - ALEATORIO\n");
    scanf("%d", &choice);
    if(choice > 3 || choice <= 0) return order_type();
    else return choice;
}
/*
void troca_buble(int vet[], int j)
{
    int right;
    right = vet[j];         //right vai receber o valor de vet[j] 
    vet[j] = vet[j+1];       //vet[j] recebe o proximo valor
    vet[j+1] = right;     //O proximo valor do vetor vai receber right
}

int buble(int vet[], int n)
{
    int i, j, flag = 1, cont = 0;
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
    return cont;
}
*/
void troca_Selection(int vet[], int i, int menor) // Faz a troca dos elementos do selection
{
    int aux;
    aux = vet[i]; //Aux recebe o valor que está na posição i do vetor
    vet[i] = vet[menor]; //vet[i] recebe o valor que está na posição menor
    vet[menor] = aux; //vet[menor] recebe o valor que estava na posição i
}

int Selection_sort(int vet[], int n)
{
    int i, j, menor, cont = 0, verifica = 0;
    for(i=0;i<n;i++) //Vai percorrer o vetor enquanto ele não estiver ordenado 
    {
        menor = i;
        for(j=0;j<n;j++)
        {
            cont += 1;
            if(vet[j] < vet[menor]) menor = j;
        }
        if(menor!=i) troca_Selection(vet, i, menor);//troca o valor na posição i pelo menor numero que está na posição menor
    }
    return cont;
}


void printVet(int vet[], int n)
{
    int i;
    for(i = 0; i<n; i++)
    {
        printf("valor %d: %d\n", i, vet[i]);
    } 
}

void cria_vetor(int vet_buble[], int vet_selection[], int vet_insertion[], int tamanho)
{
    int choice = order_type(), i;
    if(choice == 1) //Cria vetor em ordem crescente
    {
        for(i=0;i<tamanho;i++)
        {
          //  vet_buble[i] = i;
            vet_selection[i] = i; 
          //  vet_insertion[i] = i;
        }
    }
    else if(choice == 2)//Cria vetor em ordem decrescente
    {
        for(i=tamanho;i>0;i--)
        {
            vet_buble[i] = i;
            vet_selection[i] = i; 
            vet_insertion[i] = i;
        }
    }
    else       //Cria vetor em ordem aleatoria
    {
        int valor;
        for(i=0;i<tamanho;i++)
        {
            valor = rand()%100;
            vet_buble[i] = valor;
            vet_selection[i] = valor; 
            vet_insertion[i] = valor;
        }
    }
}

int main()
{
    printf("Digite o tamanho do vetor: ");
    int n, i, cont, opc = 1; 
    double time;
    clock_t start, end;
    scanf("%d", &n);
    int vet_buble[n], vet_selection[n], vet_insertion[n]; //Cria os vetores que vão ser ordenados
    cria_vetor(vet_buble, vet_selection, vet_insertion, n); //Insere o valor nos vetores
    /*start = clock();
    cont = buble(vet_buble, n); //Ordena o vetor do buble
    end = clock();
    time =((double)end - start)/CLOCKS_PER_SEC;
    printVet(&vet_buble, n);    
    printf("Tempo Buble: %lf ms, Comparacoes: %d \n", time*1000, cont);*/
    start = clock();
    cont = Selection_sort(vet_selection, n); //Ordena o vetor do selection
    end = clock();
    time =((double)end - start)/CLOCKS_PER_SEC;
    printVet(&vet_selection, n);    
    printf("Tempo Selection: %lf ms, Comparacoes: %d \n", time*1000, cont);
    //printVet(&vet_insertion, n); 
    return 0;
}
