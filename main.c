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

	while(head != NULL) {

		OBJECT_DUMP((Object *)(LLN_VALUE(head)));

		head = LLN_NEXT(head);
	}

	return 0;
}

