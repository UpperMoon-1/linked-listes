/**
 * -------------------------------------
 * @file  myrecord_sllist.h
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

#ifndef SLL_H
#define SLL_H

typedef struct {
	char name[20];
	float score;
} RECORD;

typedef struct node {
	RECORD data;
	struct node *next;
} NODE;

typedef struct sllist {
	int length;
	NODE *start;
} SLL;

NODE* sll_search(SLL *sllp, char *name);
void sll_insert(SLL *sllp, char *name, float score);
int sll_delete(SLL *sllp, char *name);
void sll_clean(SLL *sllp);

#endif /* MYRECORD_SLLIST_H_ */
