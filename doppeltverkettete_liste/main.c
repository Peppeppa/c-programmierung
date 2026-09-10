#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

struct Node {
  int value;
  struct Node *prev;
  struct Node *next;
};

struct List {

  struct Node *first;
  struct Node *last;
  int size;
};

int list_push_back(struct List *list, int value) {
  struct Node *newNode;
  newNode = malloc(sizeof(struct Node));

  if (newNode == NULL) {
    return 1;
  }

  newNode->value = value;
  newNode->next = NULL;

  if (list->first == NULL) {
    newNode->prev = NULL;

    list->first = newNode;
    list->last = newNode;
  } else {
    newNode->prev = list->last;

    list->first->next = newNode;
    list->last = newNode;
  }
  list->size++;
  return 0;
}

int list_push_front(struct List *list, int value) {
  struct Node *newNode;
  newNode = malloc(sizeof(struct Node));

  if (newNode == NULL) {
    return 1;
  }

  newNode->value = value;
  newNode->next = NULL;
  newNode->prev = NULL;

  if (list->first == NULL) {

    list->first = newNode;
    list->last = newNode;
  } else {
    list->first->prev = newNode;
    newNode->next = list->first;
    list->first = newNode;
  }
  list->size++;
  return 0;
}

// struct Node *list_pop_front(struct List *list){
//  doch nur den wert statt der gesamten node zurueckgeben
//  es wird eine int fuer die value erzeugt und uebergeben, die funktion packt
//  dort das ergebnis rein und der int rueckgabewert ist dann wirklich nur 1
//  oder 0
int list_pop_front(struct List *list, int *value) {

  if (list->first == NULL) {
    return 1;
  }

  struct Node *oldFirst = list->first;
  *value = oldFirst->value;

  if (list->first->next == NULL) {
    list->last = NULL;
    list->first = NULL;
  }
  else{
    list->first = list->first->next;
    list->first->prev = NULL;
  }

  list->size--;
  free(oldFirst);
  return 0;
}

int main(void) {

  struct List liste;

  liste.first = NULL;
  liste.last = NULL;
  liste.size = 0;

  if (list_push_back(&liste, 0) != 0) {
    return 1;
  }
  if (list_push_back(&liste, 10) != 0) {

    return 1;
  }

  struct Node *current = liste.first;

  while (current != NULL) {
    printf("%d\n", current->value);
    current = current->next;
  }

  return 0;

  return 0;
}
