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

#include <linkedlist.h>

static void dtor(void *value)
{
	objectDestroy((Object *)value);
}

static void opdtor(void *value)
{

}

static void addhandler(void)
{

}

typedef struct binaryop {
	unsigned char op;
	void(*handler)(void);
} binaryop;


int main(void)
{
	LinkedList operatorstack;
	LinkedList_INIT(&operatorstack, opdtor);

	LinkedList outputqueue;
	LinkedList_INIT(&outputqueue, dtor);

	// Shunting-yard algorithm
	LinkedList_ADD(&outputqueue, newLong(3));
	LinkedList_ADD(&operatorstack, &((binaryop){
		.op = 0x2b, .handler = addhandler
	}));

	LinkedList_ADD(&outputqueue, newLong(4));

	LinkedListNode *outputqueuetail = outputqueue.ll_head;

	while(outputqueuetail != NULL) {
		objectEcho(outputqueuetail->lln_value);
		outputqueuetail = outputqueuetail->lln_next;
	}

	LinkedList_TERM(&operatorstack);
	LinkedList_TERM(&outputqueue);

	return 0;
}
