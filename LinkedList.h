#ifndef OBJECT_LINKED_LIST_H
#define OBJECT_LINKED_LIST_H

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
