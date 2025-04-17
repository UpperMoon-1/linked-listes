/**
 * -------------------------------------
 * @file  dllist.c
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
#include "dllist.h"

NODE* dll_node(char data) {
// your code
	NODE *np = (NODE*) malloc(sizeof(NODE));
	if (np == NULL) {
		printf("malloc fails");
		return NULL;
	} else {
		np->data = data;
		np->prev = NULL;
		np->next = NULL;
		return np;

	}
}

void dll_insert_start(DLL *dllp, NODE *np) {
// your code

	if (dllp->start == NULL) {
		np->prev = NULL;
		np->next = NULL;
		dllp->start = np;
		dllp->end = np;
	} else {
		np->next = dllp->start;
		np->prev = NULL;
		dllp->start->prev = np;
		dllp->start = np;
	}
	dllp->length++;

}

void dll_insert_end(DLL *dllp, NODE *np) {

	if (dllp->start == NULL) {
		np->prev = NULL;
		np->next = NULL;
		dllp->start = np;
		dllp->end = np;
	} else {
		np->next = NULL;
		np->prev = dllp->end;
		dllp->end->next = np;
		dllp->end = np;
	}
	dllp->length++;

// your code
}

void dll_delete_start(DLL *dllp) {

	if (dllp->start != NULL && dllp->length == 1) {
		dllp->length--;
		NODE *del = dllp->start;
		dllp->start = NULL;
		dllp->end = NULL;

		free(del);

	} else if (dllp->start != NULL && dllp->length > 1) {
		dllp->length--;
		NODE *del = dllp->start;
		NODE *nf = dllp->start->next;
		dllp->start = nf;
		nf->prev = NULL;
		free(del);

	}

// your code
}

void dll_delete_end(DLL *dllp) {
// your code

	if (dllp->start != NULL && dllp->length == 1) { //good
		dllp->length--;
		NODE *temp = dllp->start;
		dllp->start = NULL;
		dllp->end = NULL;
		free(temp);
	} else if (dllp->start != NULL && dllp->length > 1) {
		dllp->length--;
		NODE *del = dllp->end;
		NODE *temp = dllp->end->prev;
		dllp->end = temp;
		temp->next = NULL;
		free(del);
	}

}

void dll_clean(DLL *dllp) {
// your code

	NODE *temp, *ptr = dllp->start;
	while (ptr != NULL) {
		temp = ptr;
		ptr = ptr->next;
		free(temp);
	}
	dllp->start = NULL;
	dllp->end = NULL;
	dllp->length = 0;

}
