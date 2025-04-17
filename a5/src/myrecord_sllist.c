/**
 * -------------------------------------
 * @file  myrecord_sllist.c
 * file description
 * -------------------------------------
 * @author Giuseppe Akbari, 169057752, akba7752@mylaurier.ca
 *
 * @version 2025-02-08
 *
 * -------------------------------------
 */

/*
 * your program signature
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "myrecord_sllist.h"

NODE* sll_search(SLL *sllp, char *name) {
	// your code
	NODE *r = { 0 };
	NODE *np = sllp->start;
	while (np != NULL) {
		if (strcmp(np->data.name, name) == 0) {
			r = np;
			break;
		} else {
			np = np->next;
		}
	}
	return r;
}

void sll_insert(SLL *sllp, char *name, float score) {
// your code
	NODE *current = sllp->start;
	NODE *previous = NULL;
	while (current != NULL) {
		if (strcmp(current->data.name, name) >= 0) {
			break;
		}
		previous = current;
		current = current->next;

	}
	NODE *node = (NODE*) malloc(sizeof(NODE));
	node->data.score = score;
	strcpy(node->data.name, name);
	node->next = NULL;
	if (sllp->length == 0) {
		sllp->start = node;
	} else if (current == NULL) {
		previous->next = node;
	} else if (previous == NULL) {
		node->next = current;
		sllp->start = node;
	} else {
		node->next = current;
		previous->next = node;
	}
	sllp->length++;

	return;

}

int sll_delete(SLL *sllp, char *name) {
	// your code
	NODE *current = sllp->start;
	NODE *previous = NULL;
	int i = 0;
	while (current != NULL) {
		if (strcmp(current->data.name, name) == 0) {
			int i = 1;
			if (previous == NULL) {
				sllp->start = current->next;
			} else if (current->next == NULL) {
				previous->next = NULL;
			} else {
				previous->next = current->next;
			}
			free(current);
			break;
		}
		previous = current;
		current = current->next;
	}

	return i;
}

void sll_clean(SLL *sllp) {
	NODE *temp, *ptr = sllp->start;
	while (ptr != NULL) {
		temp = ptr;
		ptr = ptr->next;
		free(temp);
	}
	sllp->start = NULL;
	sllp->length = 0;
}
