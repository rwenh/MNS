#ifndef DSA_LINKED_LIST_H
#define DSA_LINKED_LIST_H

#include <stdbool.h>

typedef struct ListNode {
  int val;
  struct ListNode *next;
} ListNode;

ListNode* list_create_node(int val);
void list_free(ListNode *head);

ListNode* list_insert_head(ListNode *head, int val);
ListNode* list_insert_tail(ListNode *head, int val);
ListNode* list_delete_node(ListNode *head, int target);

ListNode* list_reverse(ListNode *head);
bool list_has_cycle(ListNode *head);
ListNode* list_merge_sorted(ListNode *l1, ListNode *l2);
ListNode* list_find_middle(ListNode *head);

#endif
