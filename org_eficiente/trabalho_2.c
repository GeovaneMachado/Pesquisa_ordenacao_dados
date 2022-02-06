//Nome: Geovane Machado dos Santos
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void swap(int vet[], int i, int j)      //Faz a troca de um valor de m vetor da posição i para a posição j
{
    int aux;
    aux = vet[j];        
    vet[j] = vet[i];       
    vet[i] = aux;     
}

int particiona(int vet[], int inicio, int fim) // Vai particiona o vetor do Quick 
{
    int posPivo =fim; //Pivo sera o ultimo da partição
    int j = inicio;
    for(int i =inicio;i<fim;i++)
    {
        if(vet[i]<=vet[posPivo]) //Se o valor na posição i for menor ou igual ao pivo faz a troca entre j e i
        {
            swap(vet, i, j);
            j++;
        }
    }
    if(vet[j]>vet[posPivo]) swap(vet, j, posPivo);  // Se o valor na posição j for maior que o pivo faz a troca entre eles
    return posPivo;
}

void quick(int vet[], int inicio, int fim)
{
    if(inicio<fim)
    {
        int posPivo = particiona(vet, inicio, fim); //Vai definir a posição do pivo no vetor
        quick(vet, inicio, posPivo -1); //Chama a função recursivamente para o lado esquerdo do pivo
        quick(vet, posPivo +1, fim);        //Chama a função recursivamente para o lado direito do pivo
    }
}

void intercala(int vet[], int inicio,int meio, int fim) 
{
    int *aux = (int *)malloc((fim - inicio +1)*sizeof(int)); //vetor auxiliar que guarda os valores ordenados
    int i = inicio;
    int j = meio + 1;
    int k = 0;
    while (i<=meio && j<= fim)
    {
        if(vet[i] <=vet[j]) //Se o valor da posição i no vetor for menor que da posição j insere o i valor na posição k do aux 
        {
            aux[k] = vet[i];
            i++;  
        } 
        else //se não insere o j
        {
            aux[k] = vet[j];
            j++;
        }
        k++;
    }
    while(i<=meio)  //Faz a inserção do valor ordenado na primeira parte do vetor
    {
        aux[k] = vet[i];
        k++;
        i++;
    }
    while(j<=fim) //Faz a inserção do valor ordenado na segunda parte do vetor
    {
        aux[k] = vet[j];
        k++;
        j++;
    }
    for(k=inicio;k<=fim;k++) vet[k] = aux[k-inicio]; //O vetor original recebe os dados ordenados
    free(aux);
}

void merge(int vet[], int inicio, int fim)
{
    if(inicio<fim)
    {
        int meio = (inicio + fim)/2; //encontra a metade do vetor
        merge(vet, inicio, meio); //chama a função recursivamente para dividir do lado esquerdo do vetor
        merge(vet, meio+1,fim); //chama a função recursivamente para dividir do lado direito do vetor
        intercala(vet, inicio, meio, fim); 
    }
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

int main()
{
    int n, i; 
    double time;
    clock_t start, end;
    printf("Digite o tamanho do vetor: ");
    scanf("%d", &n);
    int vet_merge[n], vet_quick[n], vet_heap[n]; //Cria os vetores que vão ser ordenados
    cria_vetor(vet_merge, vet_quick, vet_heap, n); //Insere o valor nos vetores 
    start = clock(); //Conta o tempo que leva para a função executar
    merge(vet_merge, 0, n); //Organiza pela função merge
    end = clock();
    time =((double)end - start)/CLOCKS_PER_SEC;    
    printf("Tempo Merge: %lf ms\n", time*1000);
    start = clock();
    quick(vet_quick, 0, n);//Organiza pela função quick
    end = clock();
    time =((double)end - start)/CLOCKS_PER_SEC;   
    printf("Tempo Quick: %lf ms\n", time*1000);
    start = clock(); 
    heap(vet_heap, n); //Organiza pela função heap
    end = clock();
    time =((double)end - start)/CLOCKS_PER_SEC;
    printf("Tempo Heap: %lf ms\n", time*1000);
    return 0;
}
