#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <conio.h>

typedef struct node {
    int data;
    struct node *next;
} node;
struct node *queue_head, *queue_tail;//deixnoun sthn oura kai thn korufh tou stack of
void extract();

bool insert(int d);

void displayhead();

bool is_empty();

int main() {
    char ch;
    int price;
    queue_head = queue_tail = NULL;//arxikopoihsh ouras kai kefalhs me keno
    while (1) {
        printf("0. exit , 1. insert, 2. extract, 3. display head:\n");
        ch = getch();
        switch (ch) {
            case 0:
                exit(0);
            case 1:
                printf("dwse arithmo : ");
                scanf("%d", &price);
                if (insert(price) == false)
                    puts("not available memory ");
                break;
            case 2:
                extract();
                break;
            case 3:
                displayhead();
                break;
            default:
                puts("wrong key");
        }
    }
    return 0;
}

bool insert(int d) {
    struct node *new;
    new = malloc(sizeof(node));
    if (new == NULL) {
        return false;
    }
    new->data = d;
    if (queue_tail != NULL) {
        queue_tail->next = new;//an h oura den einai kenh, tote h oura deixnei ston neo komvo poy
        //eisagetaI
    }
    new->next = NULL;//an einai kenh,o neos komvos mhdenizetai
    queue_tail = new;//eisagwgh twrinou komvou ws oura
    if (queue_head == NULL) {
        queue_head = queue_tail;//an h kefali einai kenh, oi list_head kai list_tail,
        // tha deixnoun kai oi 2 ston neo komvo
    }
    return true;
}

void extract() {
    struct node *temp;
    if (is_empty()) {
        puts("is_empty true\n");
        return;
    }
    printf("eksagwgh tou stoixeioy: %d\n ",
           queue_head->data);//skepsou to ws oura se magazi,neos pelaths prostithetai sto telos
    //o pelaths sthn arxh eksuphreteitai kai fevgei
    temp = queue_head->next;//kataxwrhsh tou epomenou komvou poy deixnei h kefalh sto temp
    free(queue_head);// eksagwgh twrinou head
    queue_head = temp;//nea kefalh, to epomeno stoixeio
}

bool is_empty() {
    return (queue_head == NULL);//an queue_head == NULL epistrofh true
}

void displayhead() {
    if (is_empty()) {
        puts("tail empty\n");
    }
    printf("head of queue : %d", queue_head->data);
}
