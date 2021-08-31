#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct stack_node {
    int data;
    struct node *next;
};

typedef struct stack {
    struct stack_node *top;//deikths pros
    // ton komvo korufhs ths stoivas
};

void pop_from_stack(struct stack *s);

bool push_in_stack(struct stack *s, int d);

bool is_stack_empty(struct stack *s);

int get_stack_top(struct stack *s);

struct stack *create_stack();

void display_stack(struct stack *s);

int main() {
    int sel, key;
    struct stack *mystack = create_stack();
    while (1) {
        printf("menu selection\n");
        printf("--------\n");
        printf("0. Exit\n");
        printf("1. Insert\n");
        printf("2. Extract\n");
        printf("3. Display Top\n");
        printf("4. Display All\n");

        printf("enter choice : ");
        scanf("%d", &sel);

        switch (sel) {
            case 0:
                exit(0);
            case 1:
                printf("dwse timh : ");
                scanf("%d", &key);
                if (!push_in_stack(mystack, key)) {
                    printf("no available memory\n");
                }
                break;
            case 2:
                pop_from_stack(mystack);
                break;
            case 3:
                if (!is_stack_empty(mystack)) {
                    printf("%d\n", get_stack_top(mystack));
                } else {
                    printf("empty stack\n");
                }
                break;
            case 4:
                if (!is_stack_empty(mystack)) {
                    display_stack(mystack);
                } else {
                    printf("empty stack\n");
                }
                break;
            default:
                printf("wrong input\n");
                break;
        }
    }
    return 0;
}

struct stack *create_stack() {
    struct stack *st = (struct stack *) malloc(sizeof(struct stack));
    st->top = NULL;
    return st;
}

bool push_in_stack(struct stack *s, int d) {
    struct stack_node *new;
    new = (struct stack_node *) malloc(sizeof(struct stack_node));
    if (new == NULL) {
        return false;
    }
    new->data = d;
    new->next = s->top;
    s->top = new;
    return true;
}

void pop_from_stack(struct stack *s) {
    struct stack_node *temp;
    int d;
    if (is_stack_empty(s)) {
        printf("empty stack\n");
        return;
    }
    printf("%d popped\n", s->top->data);
    temp = s->top->next;
    free(s->top);
    s->top = temp;
}

bool is_stack_empty(struct stack *s) {
    if (s->top == NULL) {
        return true;
    } else {
        return false;
    }
}

int get_stack_top(struct stack *s) {
    return s->top->data;
}

void display_stack(struct stack *s) {
    struct stack_node *p;
    if (is_stack_empty(s)) {
        return;
    }
    p = s->top;
    while (p)//p!=NULL
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}
