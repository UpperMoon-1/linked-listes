/**
 * -------------------------------------
 * @file  bigint.h
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

#ifndef BIGINT_H
#define BIGINT_H
#include "dllist.h"

typedef struct bigint {
	int length;
	NODE *start;
	NODE *end;
} BIGINT;
BIGINT bigint(char *digitstr);
BIGINT bigint_add(BIGINT oprand1, BIGINT oprand2);
BIGINT bigint_fibonacci(int n);

#endif
//BIGINT_H_
