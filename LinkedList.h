#ifndef OBJECT_LINKED_LIST_H
#define OBJECT_LINKED_LIST_H

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

#include <stddef.h>
#include <object.h>

typedef void(*LinkedListValueDestructor)(void *value);

typedef struct LinkedListNode {
	Object 		  *lln_value;
	struct LinkedListNode *lln_next;
} LinkedListNode;

#define LLN_VALUE(lln) (lln)->lln_value
#define LLN_NEXT(lln) (lln)->lln_next

typedef struct LinkedList {
	size_t          		ll_count;
	LinkedListValueDestructor	ll_dtor;
	LinkedListNode 			*ll_chain;
} LinkedList;

#define LL_COUNT(p) (p)->ll_count
#define LL_DTOR(p)  (p)->ll_dtor
#define LL_CHAIN(p) (p)->ll_chain

#define LinkedList_FAILURE (-1)
#define LinkedList_SUCCESS (0)

int LinkedList_INIT(LinkedList *, LinkedListValueDestructor);
int LinkedList_ADD(LinkedList *, Object *);

#endif
