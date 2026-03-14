#include <stdio.h>
#include <stdlib.h>
#include "crawler.h"

int main() {
    Queue q;
    Stack s;
    Visited* visited = NULL;

    initQueue(&q);
    initStack(&s);

    int choice;
    while (1) {
        DisplayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                StartCrawl(&q, &visited);
                break;
            case 2:
                CrawlNext(&q, &visited, &s);
                break;
            case 3:
                Backtrack(&s);
                break;
            case 4:
                displayVisited(visited);
                break;
            case 0:
                printf("👋 Exiting crawler...\n");
                return 0;
            default:
                printf("❌ Invalid choice.\n");
        }
    }
}
