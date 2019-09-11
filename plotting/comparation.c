#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Cria um tipo long long int */
typedef long long int LLI;

/* Cria structs para lista simplesmente encadeada e árvore, respectivamente */
typedef struct list
{
    LLI item;
    struct list *next;
} Head;

typedef Head *LIST;

typedef struct tree
{
    LLI value;
    struct tree *left;
    struct tree *right;
} Tree;

typedef Tree *TREE;

/* Cria lista vazia para os números do gráfico, alocando um espaço na memória para ela e fazendo-a apontar para NULL */
LIST create_empty_list()
{
    LIST new_list = (LIST)malloc(sizeof(LIST));
    new_list->item = 0;
    new_list->next = NULL;
    return new_list;
}

/* Cria árvore vazia para os números do gráfico e faz ela apontar para NULL */
TREE create_empty_tree()
{
    return NULL;
}

/* Cria lista a partir do valor de um item */
LIST createList(LLI item)
{
    /* Aloca um espaço na memória para a lista */
    LIST new_list = (LIST)malloc(sizeof(Head));
    /* Salva o novo item na lista */
    /* Faz o item da lista apontar para o novo item */
    new_list->item = item;
    /* Faz o ponteiro de next da lista apontar para NULL */
    new_list->next = NULL;
    /* Retorna a nova lista para usá-la depois */
    return new_list;
}

/* Recebe a cabeça da lista já criada e o valor do novo item */
LIST add_list(LIST h, LLI item)
{
    /* Caso a lista esteja vazia, cria o primeiro nó */
    if (h == NULL)
    {
        return createList(item);
    }
    /* O ponteiro de NULL da lista vai apontar para um novo nó */
    /* add_list recebe próximo nó e o novo item */
    h->next = add_list(h->next, item);
    /* Retorna o nó */
    return h;
}

/* Recebe o valor para o nó e os ponteiros para esquerda e direita */
TREE createTree(LLI value, TREE right, TREE left)
{
    /* Aloca um espaço na memória para a árvore */
    TREE new_tree = (TREE)malloc(sizeof(Tree));
    /* Salva o novo valor na árvore */
    /* Faz o valor da árvore apontar para o novo valor */
    new_tree->value = value;
    /* Faz o ponteiro de right da árvore apontar para o valor de right passado no parâmetro */
    new_tree->right = right;
    /* Faz o ponteiro de left da árvore apontar para o valor de left passado no parâmetro */
    new_tree->left = left;
    /* Retorna a nova árvore */
    return new_tree;
}

/* Recebe a árvore e o novo item */
TREE add_tree(TREE t, LLI item)
{
    /* Cria um novo nó se a árvore estiver vazia */
    if (t == NULL)
        return createTree(item, NULL, NULL);
    /* Adiciona de forma ordenada na árvore */
    /* Os valores menores ficam à esquerda e os maiores à direita */
    if (item < t->value)
    {
        t->left = add_tree(t->left, item);
    }
    else
    {
        t->right = add_tree(t->right, item);
    }
    /* Retorna a nova árvore */
    return t;
}

/* Recebe uma árvore, uma lista com os valores, um índice e o número de comparações */
int searchTree(TREE t, LLI value[], int i, LLI *number_of_comparisons)
{
    /* Desconsidera quando a árvore estiver nula */
    if (t == NULL)
        return -1;
    /* Incrementa no número de comparações */
    (*number_of_comparisons) += 1;
    /* Compara na árvore os valores do array de valores */
    if (t->value == value[i])
    {
        /* Retorna a quantidade de comparações quando for igual */
        return *number_of_comparisons;
    }
    else
    {
        /* Define o fluxo da busca a depender do valor encontrado */
        if (value[i] < t->value)
        {
            return searchTree(t->left, value, i + 1, number_of_comparisons);
        }
        else
        {
            return searchTree(t->right, value, i + 1, number_of_comparisons);
        }
    }
}
/* Recebe uma lista e retorna a quantidadede comparações feitas para achar aquele item*/
int searchList(LIST list, LLI item[], LLI i, LLI *number_of_comparisons_list)
{
    while (list != NULL)
    {
        (*number_of_comparisons_list) += 1;
        if (list->item == item[i])
        {
            return *number_of_comparisons_list;
        }
        list = list->next;
    }
}
/* Adiciona os numeros gerados aleatoriamente na lista e vai retornar a lista completa*/
LIST add_numbers_to_the_list(LIST list, LLI size)
{
    int i;
    for (i = 0; i < size; i++)
    {
        list = add_list(list, i);
    }
    return list;
}
/* Adiciona os valores gerados aleatoriamente na arvore e vai retornar a arvore completa */
TREE add_numbers_to_the_tree(TREE tree, LLI size)
{
    int i;
    for (i = 0; i < size; i++)
    {
        tree = add_tree(tree, i);
    }
    return tree;
}

/*Gera os valores aleatorios para serem colocados nas estruturas*/
void generate_random(LLI size, LLI random_numbers[])
{
    srand((unsigned)time(NULL));
    int i;
    for (i = 0; i < size; i++)
    {
        random_numbers[i] = rand() % size;
    }
}
/* Ordena os numeros que foram gerados aleatoriamente da arvore*/
void order_abb_numbers(LLI size, LLI numbers[])
{
    LLI i, j;
    LLI aux;
    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size - 1; j++)
        {
            if (numbers[j] > numbers[j + 1])
            {
                aux = numbers[j];
                numbers[j] = numbers[j + 1];
                numbers[j + 1] = aux;
            }
        }
    }
}
/* Ordena os numeros que foram gerados aleatoriamente na lista*/
void order_list_numbers(LLI size, LLI numbers[])
{
    LLI i, j;
    LLI aux;
    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size - 1; j++)
        {
            if (numbers[j] > numbers[j + 1])
            {
                aux = numbers[j];
                numbers[j] = numbers[j + 1];
                numbers[j + 1] = aux;
            }
        }
    }
}

int main()
{
    LLI size, i, number, quantity, quantity_comparations;
    LLI comparations_list = 0;
    LLI comparations_abb = 0;
    /*Quantidade de numeros para ser feita as comparações*/
    printf("Enter the quantity of the elements to be inserted: \n");
    scanf("%lld", &size);

    LIST list = create_empty_list();
    TREE tree = create_empty_tree();

    /* Cria os dois arquivos de lista e arvore com permissao para escrever*/
    FILE *listArchive = fopen("listaArchive.csv", "w");
    FILE *treeArchive = fopen("treeArchive.csv", "w");

    fprintf(listArchive, "size,list_c\n");
    fprintf(treeArchive, "size,abb\n");

    printf("Add numbers to the list e abb\n");
    list = add_numbers_to_the_list(list, size);
    tree = add_numbers_to_the_tree(tree, size);

    LLI random_numbers[size];
    printf("Searching the numbers\n");
    generate_random(size, random_numbers);

    LLI sort_abb[size], sort_list[size];

    for (i = 1; i <= size; i++)
    {
        searchList(list, random_numbers, i, &comparations_list);
        searchTree(tree, random_numbers, i, &comparations_abb);
        /* Salva os valores gerados aleatoriamente nos vetores*/
        sort_list[i] = comparations_list;
        sort_abb[i] = comparations_abb;

        comparations_list = 0;
        comparations_abb = 0;
    }
    /* ordena os numeros gerados aleatoriamente*/
    order_abb_numbers(size, sort_abb);
    order_list_numbers(size, sort_list);

    /* coloca os valores no arquivo */
    for (i = 0; i < size - 1; i++)
    {
        fprintf(listArchive, "%lld,%lld\n", i, sort_list[i]);
        fprintf(treeArchive, "%lli,%lli\n", i, sort_abb[i]);
    }
    fclose(listArchive);
    fclose(treeArchive);

    return 0;
}