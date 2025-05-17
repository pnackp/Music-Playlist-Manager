#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "playlist.h"

Song* head = NULL;
Song* tail = NULL;
Song* current = NULL;

void addSong(char* title) {
    Song* temp = malloc(sizeof(Song)); 
    strcpy(temp->title, title); // string must use strcpy
    temp->next = NULL;
    temp->prev = NULL;

    if (head == NULL) {
        head = tail = temp;
        head->next = head;
        head->prev = head;
        current = head;
    } else {
        temp->prev = tail;
        temp->next = head;
        head->prev = temp;
        tail->next = temp;
        head = temp;
    }
}

void deleteSong(char* title) {
    if (head == NULL) return;

    Song* ptr = head;
    do {
        if (strcmp(ptr->title, title) == 0) {
            if (ptr == head && ptr == tail) { // if have only one node 
                free(ptr);
                head = tail = current = NULL; // set all to null 
                return;
            }

            if (ptr == head) { 
                head = head->next; //if ptr = head move head to next node and free ptr
                head->prev = tail;
                tail->next = head;
            } else if (ptr == tail) { // if ptr = tail move tail ->previous and set there is tail and connect head
                tail = tail->prev;
                tail->next = head;
                head->prev = tail;
            } else {
                ptr->prev->next = ptr->next; 
                ptr->next->prev = ptr->prev;
            }

            if (current == ptr) {
                current = ptr->prev;
            }

            free(ptr);
            return;
        }

        ptr = ptr->next;
    } while (ptr != head);
}

void showPlaylist() {
    if (head == NULL) {
        printf("NULL\n");
        return;
    }

    Song* ptr = head;
    int i = 0;
    do {
        printf("%d: %s\n", i++, ptr->title);
        ptr = ptr->next;
    } while (ptr != head);
}

void playCurrent() {
    if (current != NULL) {
        printf("%s\n", current->title);
    }
}

void nextSong() {
    if (current != NULL) {
        current = current->prev;
        printf("Next Music\n%s : Playing\n", current->title);
    }
}

void prevSong() {
    if (current != NULL) {
        current = current->next;
        printf("Previous Music\n%s : Playing\n", current->title);
    }
}

void clearPlaylist() {
    if (head == NULL) return;

    Song* ptr = head;
    Song* start = head;
    do {
        Song* next = ptr->next;
        free(ptr);
        ptr = next;
    } while (ptr != start);

    head = tail = current = NULL;
}

