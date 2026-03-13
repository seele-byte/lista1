typedef struct aluno ALUNO;
typedef struct node NODE;
/* =================== createNode ====================
Creates a node in dynamic memory and stores data
pointer in it.
Pre itemPtr is pointer to data to be stored.
Post node created and its address returned.
*/
NODE* createNode (void* itemPtr);// createNode
void inserir_aluno(ALUNO* aluno);
void melhor_aluno(ALUNO* aluno);