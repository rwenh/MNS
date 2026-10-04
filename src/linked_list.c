#include "dsa/linked_list.h"
#include <stdlib.h>

ListNode* list_create_node(int val) {
    ListNode *node = malloc(sizeof(ListNode));
    node->val = val;
    node->next = NULL;
    return node;
}

void list_free(ListNode *head) {
    while (head) {
        ListNode *temp = head;
        head = head->next;
        free(temp);
    }
}

ListNode* list_insert_head(ListNode *head, int val) {
    ListNode *node = list_create_node(val);
    node->next = head;
    return node;
}

ListNode* list_insert_tail(ListNode *head, int val) {
    ListNode *node = list_create_node(val);
    if(!head) return node;
    ListNode *curr = head;
    while (curr->next) curr = curr->next;
    curr->next = node;
    return head;
}

ListNode* list_delete_node(ListNode *head,int target) {
    if (!head) return NULL;
    if (head->val == target) {
        ListNode *temp = head->next;
        free(head);
        return temp;
    }
    ListNode *curr = head;
    while (curr->next && curr->next->val != target) {
        curr = curr->next;
    }
    if (curr->next) {
        ListNode *temp = curr->next;
        curr->next = curr->next->next;
        free(temp);
    }
    return head;
}

ListNode* list_reverse(ListNode *head) {
    ListNode *prev = NULL, *curr = head, *next = NULL;
    while (curr) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

bool list_has_cycle(ListNode *head) {
    if (!head) return false;
    ListNode *slow = head, *fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) return true;
    }
    return false;
}

ListNode* list_merge_sorted(ListNode *l1, ListNode *l2) {
    ListNode dummy;
    ListNode *tail = &dummy;
    dummy.next = NULL;

    while (l1 && l2) {
        if (l1->val <= l2->val) {
            tail->next = l1;
            l1 = l1->next;
        } else {
            tail->next = l2;
            l2 = l2->next;
        }
        tail = tail->next;
    }
    tail->next = l1 ? l1 : l2;
    return dummy.next;
}

ListNode* list_find_middle(ListNode *head){
    if (!head) return NULL;
    ListNode *slow = head, *fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}
