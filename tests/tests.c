#include <CUnit/Basic.h>
#include <stdlib.h>
#include "CUtestfunctions.c"

void test_create_node() // testando create_node
{
    NODE_TREE *new = create_node();
    new->frequency = 10;
    new->character = 'x';
    new->next = NULL;
    new->left = NULL;
    new->right = NULL;
    NODE_TREE *test = build_node_tree('x', 10, NULL, NULL);

    CU_ASSERT(test != NULL);
    CU_ASSERT_EQUAL(new->frequency, test->frequency);
    CU_ASSERT_EQUAL(new->character, test->character);
    CU_ASSERT_PTR_EQUAL(new->next, test->next);
    CU_ASSERT_PTR_EQUAL(new->left, test->left);
    CU_ASSERT_PTR_EQUAL(new->right, test->right);
}

void enqueue_test()
{
    NODE_TREE *new1 = build_node_tree('x', 10, NULL, NULL);
    NODE_TREE *new2 = build_node_tree('y', 6, NULL, NULL);

    PRIORITY_QUEUE *pq;
    pq->head->character = 'x';
    pq->head->frequency = 10;

    enqueue(pq, new1); // lista vazia retorna um new..

    CU_ASSERT(pq != NULL);
    CU_ASSERT_EQUAL(pq->head->frequency, new1->frequency);
    CU_ASSERT_EQUAL(pq->head->character, new1->character);
    CU_ASSERT_PTR_EQUAL(pq->head->next, new1->next);
    CU_ASSERT_PTR_EQUAL(pq->head->left, new1->left);
    CU_ASSERT_PTR_EQUAL(pq->head->right, new1->right);

    pq->head->character = 'y';
    pq->head->frequency = 6;

    enqueue(pq, new2);

    CU_ASSERT(new2 == NULL);
    CU_ASSERT_EQUAL(pq->head->frequency, new2->frequency);
    CU_ASSERT_EQUAL(pq->head->character, new2->character);
    CU_ASSERT_PTR_EQUAL(pq->head->left, new2->left);
    CU_ASSERT_PTR_EQUAL(pq->head->right, new2->right);
}

void queue_empty_test()
{
    PRIORITY_QUEUE *pq;
    // CU_ASSERT(pq == NULL);
    CU_ASSERT(pq != NULL);
}

void create_hash_test()
{
    HASH_TABLE *new = create_hash();

    CU_ASSERT(new != NULL);
}

void build_node_test()
{
    NODE_TREE *node_huff = create_node();
    PRIORITY_QUEUE *test = (PRIORITY_QUEUE *)malloc(sizeof(PRIORITY_QUEUE));

    NODE_TREE *node1 = dequeue(test);
    NODE_TREE *node2 = dequeue(test);
    node_huff = huffman_create_node(node1, node2);

    enqueue(test, node_huff);
}

int main()
{

    if (CUE_SUCCESS != CU_initialize_registry())
    {
        return CU_get_error();
    }
    CU_basic_set_mode(CU_BRM_VERBOSE);

    CU_pSuite pSuite = NULL, pSuite2 = NULL;
    pSuite = CU_add_suite("TEST", 0, 0);

    if (NULL == pSuite)
    {
        CU_cleanup_registry();
        return CU_get_error();
    }
    if (NULL == CU_add_test(pSuite, "test - 1", test_create_node))
    {
        CU_cleanup_registry();
        return CU_get_error();
    }
    if (NULL == CU_add_test(pSuite, "test - 2", enqueue_test))
    {
        CU_cleanup_registry();
        return CU_get_error();
    }
    if (NULL == CU_add_test(pSuite, "test - 3", queue_empty_test))
    {
        CU_cleanup_registry();
        return CU_get_error();
    }
    if (NULL == CU_add_test(pSuite, "test - 4", create_hash_test))
    {
        CU_cleanup_registry();
        return CU_get_error();
    }

    CU_basic_run_tests();
    return CU_get_error();
}
