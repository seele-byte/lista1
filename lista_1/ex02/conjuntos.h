typedef struct conjunto CONJUNTO;
CONJUNTO* criar_conjunto();
//cria um conjunto vazio
void inserir_elemento(CONJUNTO *conjunto,int inteiro);
//adiciona um elemento no conjunto
void remover_elemento(CONJUNTO *conjunto,int inteiro);
//remove um elemento de um conjunto
void conjunto_uniao(CONJUNTO* conjunto1,CONJUNTO *conjunto2,CONJUNTO *conjunto3);
//preenche o terceiro conjunto com a união dos 2 primeiros conjuntos
void conjunto_interseccao(CONJUNTO *conjunto1,CONJUNTO *conjunto2,CONJUNTO *conjunto3);
//preenche o terceiro conjunto com a interseccao dos dois primeiros conjuntos
void diferenca_de_conjuntos(CONJUNTO *conjunto1,CONJUNTO *conjunto2,CONJUNTO *conjunto3);
//preenche o terceiro conjunto com apenas os elementos do primeiro conjunto que não estão no segundo conjunto
int menor_elemento(CONJUNTO *conjunto);
//retorna o menor elemento do conjunto
int maior_elemento(CONJUNTO *conjunto);
//retorna o maior elemento do conjunto
int sao_iguais(CONJUNTO *conjunto1,CONJUNTO *conjunto2);
//retorna 1 se os conjuntos são iguais e 0 caso contrário
void destruir_conjunto(CONJUNTO *conjunto);
//deleta o conjunto
void exibir_conjunto(CONJUNTO *conjunto);
//mostra os elementos do conjunto
int pertence(CONJUNTO *conjunto1,int valor);
//retorna 1 caso o elemento pertença ao conjunto, e 0 caso não pertença