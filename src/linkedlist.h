/**
 * Copyright (c) 2016 Ryan McCullagh <me@ryanmccullagh.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */
#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stddef.h>

typedef void(*LinkedListValueDestructor)(void *value);

typedef struct LinkedListNode {
	void 		      *lln_value;
	struct LinkedListNode *lln_prev;
	struct LinkedListNode *lln_next;
} LinkedListNode;

#define LLN_VALUE(lln) (lln)->lln_value
#define LLN_PREV(lln) (lln)->lln_prev
#define LLN_NEXT(lln) (lln)->lln_next

typedef struct LinkedList {
	size_t          		ll_count;
	LinkedListValueDestructor	ll_dtor;
	LinkedListNode 			*ll_head;
	LinkedListNode			*ll_tail;
} LinkedList;

#define LL_COUNT(p) (p)->ll_count
#define LL_DTOR(p)  (p)->ll_dtor
#define LL_HEAD(p) (p)->ll_head
#define LL_TAIL(p) (p)->ll_tail

#define LinkedList_FAILURE (-1)
#define LinkedList_SUCCESS (0)

extern LinkedListNode *LinkedListNode_Create(void *, LinkedListNode *,
	LinkedListNode *);
extern int LinkedList_INIT(LinkedList *, LinkedListValueDestructor);
extern int LinkedList_ADD(LinkedList *, void *);
extern int LinkedList_TERM(LinkedList *);
extern int LinkedList_SEARCH(LinkedList *, void **, void *, 
	int(* )(void *, void *));

#define LinkedList_COUNT(l) LL_COUNT(l)

#endif /* LINKED_LIST_H */

