from random import randint

vetor = []
tamanho = randint(0, 10000)
print(tamanho)
i = 0
while(i <= tamanho):
    number = randint(0, 100000)
    vetor.append(int(number))
    i += 1
tamanho += 1
tipo = randint(1, 3)
with open('numeros.txt', 'w') as arq:
    arq.write(str(tamanho) + '\n')
    for i in vetor:
        arq.write(str(i) + '\n') 
    arq.write(str(tipo) + '\n')  
