# Principais Estruturas de Dados utilizadas na implementação de Sistemas Operacionais

## Listas

Uma lista é essencialmente uma sequência finita de zero ou mais elementos, sendo possível
percorrer essa lista sequencialmente. Uma lista pode ser implementada de várias maneiras, sendo
que cada uma apresenta vantagens e desvantagens sobre a outra. 

### Implementação por array, conhecida como lista sequencial ou array dinâmico.

Uma maneira de implementar uma lista é utilizar um array de elementos. Uma lista representado
por array tem uma tamanho máximo fixo e seus elementos devem ser do mesmo tipo. Dadas essas 
características, aliadas ao fato de que os elementos são armazenados na memória de maneira contígua,
o tempo de execução das operações básicas em uma lista representado por array têm as seguintes
complexidades assintótica no pior caso:

|  Operação | Complexidade assintótica  |
| ------------ | ------------ |
| Inserção de elemento em posição qualquer | O(n)  |
| Inserção de elemento no final  | O(1)  |
| Remoção de um elemento no final  | O(1)  |
| Acesso a um elemento  | O(1)  |


Caso a lista implementada por array precise manipulada de modo a sempre estar ordenada, então
as seguintes complexidades assintótica no pior caso se aplicam aos tempos de execução:

|  Operação | Complexidade assintótica  |
| ------------ | ------------ |
| Inserção ordenada de elemento| O(n)  |
| IRemoção ordenada de elemento  | O(n)  |
| Busca binária de elemento por chave  | O(lg(n))  |


### Implementação por ponteiros, conhecida como lista ligada ou lista encadeada.
 
Nessa implementação, cada elemento possui, além de seu dado, uma referência para ao menos o próximo
elemento. Uma lista ligada pode ter um tamanho variável, isto é, não é preciso definir uma 
tamanho	máximo ao iniciá-la, já que a alocação de memória se dá quando for necessário adicionar
um elemento. Além disso, seus elementos podem ser do diferentes tipos. Sendo assim, considerado
a implementação mais sofisticada de uma lista ligada, a lista circular duplamente ligada, suas
operações têm as seguintes complexidades assintótica no pior caso:

|  Operação | Complexidade assintótica  |
| ------------ | ------------ |
| Inserção de elemento no início, meio ou fim | O(1)  |
| Remoção de um elemento, no início, meio ou fim  | O(1)  |
| Acesso a um elemento, no início, meio ou fim | O(1)  |
| Acesso a um elemento que não esteja no início, meio ou fim | O(n)  |

Caso a lista ligada precise ser manipulada de modo a sempre estar ordenada, então as seguintes
complexidades assintótica se aplicam:

|  Operação | Complexidade assintótica  |
| ------------ | ------------ |
| Inserção ordenada de elemento | O(n)  |
| Remoção ordenada de elemento  | O(n)  |
| Busca de elemento por chave | O(n)  |


## Pilhas

Uma pilha é uma lista de elementos na qual as operações de inserção, acesso e remoção se
dão apenas no seu início, chamado de Topo. Como uma pilha é um tipo especial de lista, ele também
pode ser implementada ou como um sequência estática e homogênia de elementos, isto é um array,
bem como uma lista ligada. As vantagens e desvantagens de cada implementação com relação a
possibilidade de inserção indefinida de elementos também se aplicam a pilha.


## Filas 

Assim como uma pilha, uma fila é um tipo especial de lista, sendo que a operação de
inserção se dá apenas no final da fila, e a de acesso, apenas no início. Uma fila também pode ser
implementada tanto como array como uma lista ligada, apresentado as mesmas restrições em cada
implementação


## Função Hash:

Uma Função Hash é uma função que associa chaves a valores, formando assim a estrutura chamada
Tabela Hash. Esta estrutura é utilizada para fornecer acesso rápido aos elementos, isto é,
em tempo de execução constante. Segundo Cormen, uma Table Hash é uma estrutura de dados
eficiente para implementar as operações de dicionários, sendo elas as operações de Inserção,
Busca e Remoção. Uma Tabela Hash geralmente usa um array de tamanho equivalente ao número de
chaves.


## Bitmap:

Um Bitmap é simplesmente um array de tipos booleanos, isto é, que podem armazenar apenas 1 dentre
dois valores. Bitmaps são estruturas altamente eficientes para representar a relação de pertinência
entre uma sequência de elementos e um determinado conjunto. As operações realizadas nos elementos
de um Bitmap são as operações Bitwise, ou operações bit a bit, por exemplo: OR, AND, XOR e NOT.


## Referências:

1. CORMEN, Thomas H. et al. Introduction to Algorithms. 3. ed. Cambridge: The MIT Press, 2009. 1313 p.
