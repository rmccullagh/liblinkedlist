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

#include <object.h>
#include <stdlib.h>

#include "LinkedList.h"

int LinkedList_INIT(LinkedList *ll, LinkedListValueDestructor dtor)
{
	LL_CHAIN(ll) = NULL;
	LL_COUNT(ll) = 0;
	LL_DTOR(ll) = dtor;

	return LinkedList_SUCCESS;
}

int LinkedList_ADD(LinkedList *ll, void *value)
{
	int returnValue = LinkedList_SUCCESS;

	if(LL_CHAIN(ll) == NULL) 
	{
		LL_CHAIN(ll) = malloc(sizeof(LinkedListNode));
			
		if(LL_CHAIN(ll) == NULL) 
		{
			returnValue = LinkedList_FAILURE;
			goto finish;
		}

		LLN_VALUE(LL_CHAIN(ll)) = value;
		LLN_NEXT(LL_CHAIN(ll)) = NULL;
		LL_COUNT(ll)++;
	}

	else 
	{
		LinkedListNode *prev = LL_CHAIN(ll);

		LinkedListNode *next = malloc(sizeof(LinkedListNode));

		if(next == NULL) 
		{
			returnValue = LinkedList_FAILURE;
			goto finish;
		}

		LLN_VALUE(next) = value;
		LLN_NEXT(next) = prev;
		LL_CHAIN(ll) = next;
		LL_COUNT(ll)++;
	}

	finish:
		return returnValue;
}

int LinkedList_TERM(LinkedList *ll)
{
	LinkedListNode *head = LL_CHAIN(ll);

	while(head != NULL) 
	{
		LinkedListNode *next = LLN_NEXT(head);

		LL_DTOR(ll)(LLN_VALUE(head));

		free(head);

		head = next;
	}


	return LinkedList_SUCCESS;
}

int LinkedList_ELEMENT_AT(LinkedList *ll, size_t index, void **out)
{
	int returnValue = LinkedList_FAILURE;
	size_t position = 0;

	*out = NULL;

	LinkedListNode *head = LL_CHAIN(ll);


	while(head != NULL) 
	{	
		if(position == index) 
		{
			*out = LLN_VALUE(head);
			returnValue = LinkedList_SUCCESS;
			break;
		}

		head = LLN_NEXT(head);

		position++;
	}

	return returnValue;
}

int LinkedList_SEARCH(LinkedList *ll, void **out, void *valueToBeSearchedFor, int(*callback)(void *, void *))
{
	int returnValue = LinkedList_FAILURE;
	*out = NULL;

	LinkedListNode *head = LL_CHAIN(ll);

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
