/**
 * -------------------------------------
 * @file  dllist.h
 * file description
 * -------------------------------------
 * @author Giuseppe Akbari, 169057752, akba7752@mylaurier.ca
 *
 * @version 2025-02-08
 *
 * -------------------------------------
 */
#ifndef DLLIST_H_
#define DLLIST_H_

/*
 * your program signature
 */

#ifndef DLL_H
#define DLL_H

typedef struct node {
	char data;
	struct node *prev;
	struct node *next;
} NODE;

typedef struct dllist {
	int length;
	NODE *start;
	NODE *end;
} DLL;

NODE* dll_node(char value);
void dll_insert_start(DLL *dllp, NODE *np);
void dll_insert_end(DLL *dllp, NODE *np);
void dll_delete_start(DLL *dllp);
void dll_delete_end(DLL *dllp);
void dll_clean(DLL *dllp);

#endif

#endif /* DLLIST_H_ */
