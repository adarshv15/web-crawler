#ifndef CRAWLER_H
#define CRAWLER_H

#define MAX_URL_LEN 200
#define MAX_LINKS 20

typedef struct Node {
    char url[MAX_URL_LEN];
    struct Node* next;
} Node;

// Queue for BFS crawling
typedef struct {
    Node* front;
    Node* rear;
} Queue;

// Stack for backtracking and depth control
typedef struct {
    char urls[100][MAX_URL_LEN];
    int top;
} Stack;

// Linked list for visited URLs
typedef struct Visited {
    char url[MAX_URL_LEN];
    struct Visited* next;
} Visited;

// Queue functions
void initQueue(Queue* q);
void enqueue(Queue* q, char* url);
char* dequeue(Queue* q);
int isQueueEmpty(Queue* q);

// Stack functions
void initStack(Stack* s);
void push(Stack* s, char* url);
char* pop(Stack* s);
int isStackEmpty(Stack* s);

// Visited list functions
int isVisited(Visited* head, char* url);
void addVisited(Visited** head, char* url);
void displayVisited(Visited* head);

// NEW FUNCTIONS
int DuplicateCheck(Visited* head, char* url);
int DepthLimitControl(Stack* s, int maxDepth);

// Crawler functions
void simulateExtractLinks(char* current, Queue* q, Visited** visited);
void StartCrawl(Queue* q, Visited** visited);
void CrawlNext(Queue* q, Visited** visited, Stack* s);
void Backtrack(Stack* s);
void DisplayMenu();

#endif
