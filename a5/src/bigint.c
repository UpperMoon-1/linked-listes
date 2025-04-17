/**
 * -------------------------------------
 * @file  bigint.c
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
#include "bigint.h"

BIGINT bigint(char *p) {
	BIGINT bn = { 0 };
	if (p == NULL)
		return bn;
	else if (!(*p >= '0' && *p <= '9')) { // not begin with digits
		return bn;
	} else if (*p == '0' && *(p + 1) == '\0') { // just "0"
		dll_insert_end(&bn, dll_node(*p - '0'));
		return bn;
	} else {
		while (*p) {
			if (*p >= '0' && *p <= '9') {
				dll_insert_end(&bn, dll_node(*p - '0'));
			} else {
				dll_clean(&bn);
				break;
			}
			p++;
		}
		return bn;
	}
}

BIGINT bigint_add(BIGINT op1, BIGINT op2) {
// your code
	BIGINT sum = bigint(NULL);
	NODE *p1 = op1.end;
	NODE *p2 = op2.end;
	int c = 0;
	int a;
	int b;
	int s;
	while (p1 || p2) {
		a = 0;
		b = 0;
		if (p1) {
			a = p1->data;
			p1 = p1->prev;
		}
		if (p2) {
			b = p2->data;
			p2 = p2->prev;
		}
		c += a + b;
		if (c < 10) {
			dll_insert_start(&sum, dll_node(c));
			c = 0;
		} else {
			dll_insert_start(&sum, dll_node(c - 10));
			c = 1;
		}

		//c = 0;

	}
	if (c == 1) {
		dll_insert_start(&sum, dll_node(c));
	}
	return sum;
}

BIGINT bigint_fibonacci(int n) {
// your code
	BIGINT f1 = bigint("0");
	BIGINT f2 = bigint("1");
	BIGINT temp = bigint(NULL);
	if (n == 0) {
		return f1;
	} else if (n == 1) {
		return f2;
	} else {
		int i = 0;
		for (i = 2; i <= n; i++) {
			temp = f2;
			f2 = bigint_add(f1, f2);
			//dll_insert_start(&f2, bigint_add(f1, f2));
			//f2 = f1 + f2
			f1 = temp;
		}
		return f2;
	}
}
