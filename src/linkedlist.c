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

#include <stdlib.h>

#include <linkedlist.h>

LinkedListNode *LinkedListNode_Create(void *value, LinkedListNode *prev,
	LinkedListNode *next)
{
	LinkedListNode *node = malloc(sizeof(LinkedListNode));
	LLN_VALUE(node) = value;
	LLN_PREV(node) = prev;
	LLN_NEXT(node) = next;	

	return node;
}

int LinkedList_INIT(LinkedList *ll, LinkedListValueDestructor dtor)
{
	LL_HEAD(ll) = NULL;
	LL_TAIL(ll) = NULL;
	LL_COUNT(ll) = 0;
	LL_DTOR(ll) = dtor;

	return LinkedList_SUCCESS;
}

int LinkedList_ADD(LinkedList *ll, void *value)
{
	LinkedListNode *node = LinkedListNode_Create(value, ll->ll_tail, 
							NULL);

	if(LL_TAIL(ll) != NULL) 
	{
		LL_TAIL(ll)->lln_next = node;

	}
	else
	{
		LL_HEAD(ll) = node;
	}

	LL_COUNT(ll) += 1;

	LL_TAIL(ll) = node;

	return LinkedList_SUCCESS;
}

int LinkedList_TERM(LinkedList *ll)
{
	LinkedListNode *head = LL_HEAD(ll);

	while(head != NULL) 
	{
		LinkedListNode *next = LLN_NEXT(head);

		LL_DTOR(ll)(LLN_VALUE(head));

		free(head);

		head = next;
	}


	return LinkedList_SUCCESS;
}

int LinkedList_SEARCH(LinkedList *ll, void **out, void *valueToBeSearchedFor, 
	int(*callback)(void *, void *))
{
	int returnValue = LinkedList_FAILURE;
	*out = NULL;

	LinkedListNode *head = LL_HEAD(ll);

	while(head != NULL) 
	{	
		if(callback(valueToBeSearchedFor, LLN_VALUE(head)))
		{
			*out = LLN_VALUE(head);
			returnValue = LinkedList_SUCCESS;
			break;
		}

		head = LLN_NEXT(head);
	}

	return returnValue;
}
