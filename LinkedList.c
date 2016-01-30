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

int LinkedList_ADD(LinkedList *ll, Object *value)
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
	}

	finish:
		return returnValue;
}

	
