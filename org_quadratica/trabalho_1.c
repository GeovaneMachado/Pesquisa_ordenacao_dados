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
    for(i=0; i<n-1;i++)  //Quantidade de vezes que o j vai percorrer o vetor no pior caso possivel
    {
        flag = 1; //Vai mudar para 1 quando comecar o laco
        for(j=0; j<n-1;j++) //Percorre o vetor
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
    for(i=0;i<n-1;i++) //Vai percorrer o vetor enquanto ele não estiver ordenado 
    {
        menor = i;
        for(j=i+1;j<n;j++)
        {
            cont++;
            if(vet[j] < vet[menor]) menor = j;
        }
        troca_Selection(vet, i, menor);//troca o valor na posição i pelo menor numero que está na posição menor
    }
    return cont;
}

int insertion_sort(int vet[], int n)
{
    int i, j, cont=0, aux;
    for(i=1;i<n;i++)
    {
        aux = vet[i]; //Recebe o valor que está na posição i do vetor
        j = i - 1; 
        if(aux>vet[j]) cont++;
        while(aux < vet[j] && j>=0) //Se o aux for menor que o valor na posição j e j maior ou igual a 0 faz as trocas
        {
            vet[j+1] = vet[j]; //Move cada elemento uma posição a direita
            j--;
            cont++;
        }
        vet[j+1] = aux; //Insere o aux na posição ordenada
    }
    return cont;
}


void cria_vetor(int vet_buble[], int vet_selection[], int vet_insertion[], int tamanho)
{
    int choice = order_type(), i;
    if(choice == 1) //Cria vetor em ordem crescente
    {
        for(i=0;i<tamanho;i++)
        {
            vet_buble[i] = i;
            vet_selection[i] = i; 
            vet_insertion[i] = i;
        }
    }
    else if(choice == 2)//Cria vetor em ordem decrescente
    {
        int valor = 0;
        for(i=tamanho;i>=0;i--)
        {
            vet_buble[i] = valor;
            vet_selection[i] = valor; 
            vet_insertion[i] = valor;
            valor++;
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
    int n, i, cont; 
    double time;
    clock_t start, end;
    printf("Digite o tamanho do vetor: ");
    scanf("%d", &n);
    int vet_buble[n], vet_selection[n], vet_insertion[n]; //Cria os vetores que vão ser ordenados
    cria_vetor(vet_buble, vet_selection, vet_insertion, n); //Insere o valor nos vetores
    start = clock(); //Conta o tempo de buble
    cont = buble(vet_buble, n); //Ordena o vetor do buble
    end = clock();
    time =((double)end - start)/CLOCKS_PER_SEC;    
    printf("Tempo Buble: %lf ms, Comparacoes: %d \n", time*1000, cont);
    start = clock();//Conta o tempo de selection
    cont = Selection_sort(vet_selection, n); //Ordena o vetor do selection
    end = clock();
    time =((double)end - start)/CLOCKS_PER_SEC;    
    printf("Tempo Selection: %lf ms, Comparacoes: %d \n", time*1000, cont);
    start = clock(); //Conta o tempo de insertion
    cont = insertion_sort(vet_insertion, n); //Ordena o vetor do insertion
    end = clock();
    time =((double)end - start)/CLOCKS_PER_SEC;
    printf("Tempo insertion: %lf ms, Comparacoes: %d \n", time*1000, cont); 
    return 0;
}
