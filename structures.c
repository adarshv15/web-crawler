#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "crawler.h"

// --------------------------------------
// QUEUE FUNCTIONS
// --------------------------------------
void initQueue(Queue* q) {
    q->front = q->rear = NULL;
}

void enqueue(Queue* q, char* url) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->url, url);
    newNode->next = NULL;

    if (q->rear == NULL)
        q->front = q->rear = newNode;
    else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
}

char* dequeue(Queue* q) {
    if (q->front == NULL)
        return NULL;

    Node* temp = q->front;
    char* url = temp->url;

    q->front = q->front->next;
    if (q->front == NULL)
        q->rear = NULL;

    return url;
}

int isQueueEmpty(Queue* q) {
    return q->front == NULL;
}

// --------------------------------------
// STACK FUNCTIONS
// --------------------------------------
void initStack(Stack* s) {
    s->top = -1;
}

void push(Stack* s, char* url) {
    if (s->top < 99) {
        s->top++;
        strcpy(s->urls[s->top], url);
    }
}

char* pop(Stack* s) {
    if (s->top == -1)
        return NULL;

    return s->urls[s->top--];
}

int isStackEmpty(Stack* s) {
    return s->top == -1;
}

// --------------------------------------
// VISITED LIST FUNCTIONS
// --------------------------------------
int isVisited(Visited* head, char* url) {
    Visited* temp = head;
    while (temp != NULL) {
        if (strcmp(temp->url, url) == 0)
            return 1;
        temp = temp->next;
    }
    return 0;
}

void addVisited(Visited** head, char* url) {
    Visited* newNode = (Visited*)malloc(sizeof(Visited));
    strcpy(newNode->url, url);
    newNode->next = *head;
    *head = newNode;
}

void displayVisited(Visited* head) {
    printf("\n--- Crawled URLs ---\n");
    Visited* temp = head;
    while (temp != NULL) {
        printf("%s\n", temp->url);
        temp = temp->next;
    }
    printf("---------------------\n");
}

// --------------------------------------
// NEW FEATURE FUNCTIONS
// --------------------------------------


int DuplicateCheck(Visited* head, char* url) {
    return isVisited(head, url);  // same logic reused
}

// 2. DEPTH LIMIT CONTROL
int DepthLimitControl(Stack* s, int maxDepth) {
    if (s->top + 1 >= maxDepth) {
        printf("Depth limit reached! Cannot crawl deeper.\n");
        return 0;
    }
    return 1;
}
