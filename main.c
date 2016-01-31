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

#include <stdio.h>
#include <stdlib.h>
#include <object.h>

#include "LinkedList.h"


static void dtor(void *value)
{
	objectDestroy((Object *)value);
}

int main(void)
{
	LinkedList ll;
	LinkedList_INIT(&ll, dtor);

	LinkedList_ADD(&ll, newString("McCullagh"));
	LinkedList_ADD(&ll, newString("Ryan"));

	LinkedListNode *head = LL_CHAIN(&ll);
	
	fprintf(stdout, "Node Count: %zu\n", LL_COUNT(&ll));

	while(head != NULL) 
	{
		OBJECT_DUMP((Object *)(LLN_VALUE(head)));

		head = LLN_NEXT(head);
	}


	Object *first;
	int status;

	status = LinkedList_ELEMENT_AT(&ll, -1, (void **)&first);
	
	if(status == LinkedList_SUCCESS) 
	{
		OBJECT_DUMP(first);
	}

	LinkedList_TERM(&ll);

	return 0;
}
