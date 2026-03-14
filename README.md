# Web Crawler Simulation using Data Structures in C

## Problem Statement
The goal of this project is to design and implement a simple web crawler simulation using the C programming language. A web crawler is a program that starts from a seed URL, visits linked pages, and builds a representation of the website structure.

The crawler processes web pages in a structured way while ensuring that duplicate URLs are not visited multiple times. It also maintains a record of all visited pages and simulates navigation through links between pages.

The implementation makes use of fundamental data structures such as Queue, Stack, and Linked List to manage URLs, track visited pages, and simulate navigation between pages.

---

## Solution Approach

### Overview
This project implements a basic crawler simulation in C that mimics the behavior of real-world search engine crawlers. The crawler begins with a seed URL, processes it, and then simulates the discovery of additional URLs.

The program maintains a queue of URLs to be visited, a linked list to store visited URLs, and a stack to manage backtracking to previous pages. By using these data structures, the crawler ensures systematic traversal and avoids visiting the same page multiple times.

The program is structured using a multi-file approach, separating declarations, implementations, and the main program for better modularity and maintainability.

---

## Data Structures Used

### Queue
The queue is used to store the list of URLs that need to be processed.

Characteristics:
- Follows FIFO (First In First Out) principle.
- Ensures URLs are processed in the order they are discovered.
- Used during the crawling process to manage pending URLs.

### Linked List
A linked list is used to maintain the history of visited URLs.

Purpose:
- Stores all URLs that have already been processed.
- Prevents duplicate visits to the same URL.
- Allows traversal to display the list of visited pages.

### Stack
The stack is used to simulate backtracking to previously visited pages.

Characteristics:
- Follows LIFO (Last In First Out) principle.
- Represents navigation back to parent pages during crawling.

---

## Functional Components

### StartCrawl()
Initializes the crawling process by accepting the seed URL and inserting it into the queue.

### ProcessURL()
Removes a URL from the queue, processes it, and checks whether it has already been visited. If it is a new URL, it is added to the visited list and simulated links are generated.

### BuildMap()
Represents the current page as a node in the website structure, simulating how pages are connected through hyperlinks.

### BacktrackToParent()
Uses the stack to simulate navigation back to the previously visited page.

### DisplayVisitedHistory()
Traverses the linked list and prints all the URLs that were visited during the crawling process.

---

## Project Structure

web-crawler/

crawler.h        - Header file containing structure definitions and function declarations  
crawler.c        - Implementation of crawler logic  
structure.c      - Implementation of Queue, Stack, and Linked List  
main.c           - Main program controlling the crawler  

This multi-file architecture improves readability, modularity, and code organization.

---

## Technologies Used

- C Programming Language
- Data Structures
  - Queue
  - Stack
  - Linked List
- GCC Compiler for compilation

---

## Key Features

- Simulation of a basic web crawling mechanism
- Uses multiple data structures for efficient URL management
- Prevents duplicate page visits
- Maintains a history of visited URLs
- Modular multi-file implementation in C

---

## Learning Outcomes

Through this project, the following concepts were practiced:

- Implementation of Queue, Stack, and Linked List in C
- Understanding how web crawlers traverse web pages
- Modular programming using header and source files
- Managing dynamic memory and structures in C
