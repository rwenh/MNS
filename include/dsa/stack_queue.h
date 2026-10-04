#ifndef DSA_STACK_QUEUE_H
#define DSA_STACK_QUEUE_H

#include <stdbool.h>
#include <stddef.h>

typedef struct {
    int *data;
    int top;
    size_t capacity;
} Stack;

Stack* stack_create(size_t capacity);
void stack_free(Stack *s);
bool stack_push(Stack *s, int val);
bool stack_pop(Stack *s, int *out);
bool stack_peek(const Stack *s, int *out);
bool stack_is_empty(const Stack *s);

bool bracket_matching(const char *expr);
void infix_to_postfix(const char *infix, char *postfix);

typedef struct {
    Stack *main_stack;
    Stack *min_stack;
} MinStack;

MinStack* min_stack_create(size_t capacity);
void min_stack_free(MinStack *ms);
void min_stack_push(MinStack *ms, int val);
int min_stack_pop(MinStack *ms);
int min_stack_get_min(const MinStack *ms);

typedef struct {
    int *data;
    int front;
    int rear;
    size_t size;
    size_t capacity;
} CircularQueue;

CircularQueue* cq_create(size_t capacity);
void cq_free(CircularQueue *q);
bool cq_enqueue(CircularQueue *q, int val);
bool cq_dequeue(CircularQueue *q, int *out);

#endif
