#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "crawler.h"

// Simulated extraction of links from a file
void simulateExtractLinks(char* current, Queue* q, Visited** visited) {
    FILE* file = fopen("links.txt", "r");
    if (!file) {
        printf("⚠️ Cannot open links.txt! Make sure it exists.\n");
        return;
    }

    char page[MAX_URL_LEN], link[MAX_URL_LEN];
    while (fscanf(file, "%s %s", page, link) == 2) {
        if (strcmp(page, current) == 0 && !DuplicateCheck(*visited, link)) {
            enqueue(q, link);
            addVisited(visited, link);
            printf("✅ Found new link: %s\n", link);
        }
    }
    fclose(file);
}

// Start Crawl
void StartCrawl(Queue* q, Visited** visited) {
    char seed[MAX_URL_LEN];
    printf("Enter Seed URL: ");
    scanf("%s", seed);

    enqueue(q, seed);
    addVisited(visited, seed);
    printf("🌱 Starting crawl at: %s\n", seed);
}

// Crawl Next URL
void CrawlNext(Queue* q, Visited** visited, Stack* s) {
    int MAX_DEPTH = 4;  // You can change this

    if (!DepthLimitControl(s, MAX_DEPTH))
        return;

    if (isQueueEmpty(q)) {
        printf("⚠️ No URLs to crawl.\n");
        return;
    }

    char* current = dequeue(q);
    printf("\n🌐 Visiting: %s\n", current);

    push(s, current);

    simulateExtractLinks(current, q, visited);
}

// Backtrack
void Backtrack(Stack* s) {
    if (isStackEmpty(s)) {
        printf("⚠️ No previous pages.\n");
        return;
    }
    char* page = pop(s);
    printf("↩️ Backtracked to: %s\n", page);
}

// Menu
void DisplayMenu() {
    printf("\n============ WEB CRAWLER SIMULATOR ============\n");
    printf("1. Start Crawl\n");
    printf("2. Crawl Next URL\n");
    printf("3. Backtrack\n");
    printf("4. Display Crawled URLs\n");
    printf("0. Exit\n");
    printf("===============================================\n");
    printf("Enter your choice: ");
}
