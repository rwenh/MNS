#include "dsa/stack_queue.h"
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

Stack* stack_create(size_t capacity) {
    Stack *s = malloc(sizeof(Stack));
    if (!s) return NULL;
    s->data = malloc(sizeof(int) * capacity);
    if (!s->data) {
        free(s);
        return NULL;
    }
    s->top = -1;
    s->capacity = capacity;
    return s;
}

void stack_free(Stack *s) {
    if (s) {
        free(s->data);
        free(s);
    }
}

bool stack_push(Stack *s, int val) {
    if (!s || (size_t)(s->top + 1) >= s->capacity) return false;
    s->data[++(s->top)] = val;
    return true;
}

bool stack_pop(Stack *s, int *out) {
    if (!s || s->top < 0) return false;
    *out = s->data[(s->top)--];
    return true;
}

bool stack_peek(const Stack *s, int *out) {
    if (!s || s->top < 0) return false;
    *out = s->data[s->top];
    return true;
}

bool stack_is_empty(const Stack *s) {
    return !s || s->top < 0;
}

bool bracket_matching(const char *expr) {
    if (!expr) return false;
    Stack *s = stack_create(100);
    if (!s) return false;

    for (int i = 0; expr[i] != '\0'; i++) {
        char ch = expr[i];
        if (ch == '(' || ch == '{' || ch == '[') {
            stack_push(s, (int)ch);
        } else if (ch == ')' || ch == '}' || ch == ']') {
            int top_val;
            if (!stack_pop(s, &top_val)) {
                stack_free(s);
                return false;
            }
            if ((ch == ')' && top_val != '(') ||
                (ch == '}' && top_val != '{') ||
                (ch == ']' && top_val != '[')) {
                stack_free(s);
                return false;
            }
        }
    }
    bool is_empty = stack_is_empty(s);
    stack_free(s);
    return is_empty;
}

static int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    if (op == '^') return 3;
    return 0;
}

void infix_to_postfix(const char *infix, char *postfix) {
    if (!infix || !postfix) return;
    Stack *s = stack_create(strlen(infix) + 1);
    if (!s) {
        postfix[0] = '\0';
        return;
    }
    int k = 0;
    for (int i = 0; infix[i]; i++) {
        char ch = infix[i];
        if (isalnum((unsigned char)ch)) {
            postfix[k++] = ch;
        } else if (ch == '(') {
            stack_push(s, (int)ch);
        } else if (ch == ')') {
            int top_val;
            while (stack_peek(s, &top_val) && top_val != '(') {
                stack_pop(s, &top_val);
                postfix[k++] = (char)top_val;
            }
            stack_pop(s, &top_val); // Pop '('
        } else {
            int top_val;
            while (stack_peek(s, &top_val) &&
                   precedence((char)top_val) >= precedence(ch)) {
                stack_pop(s, &top_val);
                postfix[k++] = (char)top_val;
            }
            stack_push(s, (int)ch);
        }
    }
    int top_val;
    while (stack_pop(s, &top_val)) {
        postfix[k++] = (char)top_val;
    }
    postfix[k] = '\0';
    stack_free(s);
}

MinStack* min_stack_create(size_t capacity) {
    MinStack *ms = malloc(sizeof(MinStack));
    if (!ms) return NULL;
    ms->main_stack = stack_create(capacity);
    ms->min_stack = stack_create(capacity);
    if (!ms->main_stack || !ms->min_stack) {
        stack_free(ms->main_stack);
        stack_free(ms->min_stack);
        free(ms);
        return NULL;
    }
    return ms;
}

void min_stack_free(MinStack *ms) {
    if (ms) {
        stack_free(ms->main_stack);
        stack_free(ms->min_stack);
        free(ms);
    }
}

void min_stack_push(MinStack *ms, int val) {
    if (!ms) return;
    stack_push(ms->main_stack, val);
    int current_min;
    if (stack_peek(ms->min_stack, &current_min)) {
        if (val <= current_min) {
            stack_push(ms->min_stack, val);
        }
    } else {
        stack_push(ms->min_stack, val);
    }
}

int min_stack_pop(MinStack *ms) {
    if (!ms) return -1;
    int val;
    if (!stack_pop(ms->main_stack, &val)) return -1;
    int current_min;
    if (stack_peek(ms->min_stack, &current_min) && val == current_min) {
        int dummy;
        stack_pop(ms->min_stack, &dummy);
    }
    return val;
}

int min_stack_get_min(const MinStack *ms) {
    if (!ms) return -1;
    int min_val;
    if (stack_peek(ms->min_stack, &min_val)) return min_val;
    return -1;
}

CircularQueue* cq_create(size_t capacity) {
    CircularQueue *q = malloc(sizeof(CircularQueue));
    if (!q) return NULL;
    q->data = malloc(sizeof(int) * capacity);
    if (!q->data) {
        free(q);
        return NULL;
    }
    q->front = 0;
    q->rear = -1;
    q->size = 0;
    q->capacity = capacity;
    return q;
}

void cq_free(CircularQueue *q) {
    if (q) {
        free(q->data);
        free(q);
    }
}

bool cq_enqueue(CircularQueue *q, int val) {
    if (!q || q->size == q->capacity) return false;
    q->rear = (q->rear + 1) % (int)q->capacity;
    q->data[q->rear] = val;
    q->size++;
    return true;
}

bool cq_dequeue(CircularQueue *q, int *out) {
    if (!q || q->size == 0) return false;
    *out = q->data[q->front];
    q->front = (q->front + 1) % (int)q->capacity;
    q->size--;
    return true;
}
