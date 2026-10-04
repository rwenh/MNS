#include <stdio.h>
#include "dsa/recursion.h"
#include "dsa/array_ops.h"
#include "dsa/stack_queue.h"
#include "dsa/linked_list.h"
#include "dsa/trees_bst.h"
#include "dsa/heap.h"
#include "dsa/graph.h"

int main(void) {
    printf("=== DSA Module Runner ===\n\n");
    // 1. Recursion
    DynamicArray *da = da_create(4);
    da_insert_at(da, 0, 30);
    da_insert_at(da, 0, 10);
    da_insert_at(da, 1, 20);
    printf("[2] Dynamic Array elements: %d, %d, %d\n\n", da->data[0], da->data[1], da->data[2]);
    da_free(da);

    // 3. Stack & Queue
    printf("[3] Bracket Matching '({[]})':%s\n\n", bracket_matching("({[]})") ? "Valid": "Invalid");

    // 4. Linked List
    ListNode *head = NULL;
    head = list_insert_tail(head, 10);
    head = list_insert_tail(head, 20);
    head = list_insert_tail(head, 30);
    head = list_reverse(head);
    printf("[4] Reversed List head value: %d\n\n", head->val);
    list_free(head);

    // 5. BST
    TreeNode *bst = NULL;
    bst = bst_insert(bst, 50);
    bst = bst_insert(bst, 30);
    bst = bst_insert(bst, 70);
    printf("[5] BST Inorder Traversal: ");
    traversal_inorder(bst);
    printf("\n\n");
    tree_free(bst);

    // 6. Heap
    MinHeap *heap = heap_create(5);
    heap_insert(heap, 15);
    heap_insert(heap, 5);
    heap_insert(heap, 20);
    printf("[6] Extracted min from heap: %d\n\n", heap_extract_min(heap));
    heap_free(heap);

    // 7. Graph
    Graph *g = graph_create(4);
    graph_add_edge(g, 0, 1, 2);
    graph_add_edge(g, 0, 2, 4);
    graph_add_edge(g, 1, 3, 1);
    graph_bfs(g, 0);
    graph_dijkstra(g, 0);
    graph_free(g);

    return 0;
}
