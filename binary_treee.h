
typedef struct _binary_tree binary_tree;
typedef struct _list list;

list* creat_list();
//cria uma arvore binaria
binary_tree* create_binary_tree( char item, int size, binary_tree *left, binary_tree *right);

//inicia a arvore com NULL
binary_tree* start_tree();

//troca 2 nós
binary_tree* change_tree(binary_tree *a, binary_tree *b);

//imprime a arvore como lista ligada
void print_list(binary_tree *head);

//imprime a lista ao contrario
void print_inverse(binary_tree *head);

//retorna a quantidade de nós 
int size_of_List(binary_tree *head);

//verifica se a arvore/lista ta vazia
int is_empty(binary_tree *head);

//adiciona elemento na cabeça da lista
binary_tree* add_head(binary_tree *head, int item);

//adiciona no final da lista
void add_end(binary_tree *head, int item);

//adiciona ordenado na lista
binary_tree* add_sorted(binary_tree *head, int item);

//adiciona uma no de maneira ordenada
void add_sorted_tree(binary_tree *head, binary_tree *newbinary_tree,int item);

//bubble sort para a lista
void sort(binary_tree *head);

//verifica se um no ja existe na lista, se existir incrementa seu tamanho, e adiciona 
//no lugar certo
int search_increment(binary_tree *head, int item);

//adiciona elementos na arvore, se existir imcrementa seu tamanho, se nao adiciona o elemento
binary_tree* add_for_size(binary_tree *head, int item);

//remove a cabeça da lista
int remove_head(binary_tree *head);

//remove o ultimo item da lista
int remove_tail(binary_tree *head);

//remove um item da lista
int remove_item(binary_tree *head, int item);

//verifica e um item está na lista
int search(binary_tree *head, int item);

//soma o tamanho so size de 2 nós
int tam(binary_tree *a, binary_tree* b);

//cria um nova arvore com os dois primeiros da lista
binary_tree* merge_tree(binary_tree *bt);

