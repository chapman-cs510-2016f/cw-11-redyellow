#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

//define a new NULL stack and return.
STACK new_stack() {
    STACK new = NULL;
    return new;
}

/*
push one value into the stack
1. allocate memory for pushing value,type is STACK;
2. set the value of the new stack with val;
3. set the head of the new stack with pointer s, which means s is new's head.
4. reset the address of with new, which means move s to the new pushed stack.
*/
void push_stack(STACK *s, SVALUE val) {
    STACK new = (STACK) malloc(sizeof(struct stack));
    new->data = val;
    new->head = *s;
    *s = new;
}

/*
pop one value from stack
1. define temporay variable val and temp STACK;
2. if s point to NULL, set val with -1;
3. otherwise, set data that s pointed right now to val, set temp with the address of s, then set the new address of s with its header address, free the memory that temp point.
*/
SVALUE pop_stack(STACK *s) {
    SVALUE val;
    STACK temp;
    if (*s == NULL) {
      val = -1;
    }
    else {
      val = (*s)->data;
      temp = (*s);
      *s = (*s)->head;
      free(temp);
    }
    return val;
}

// Printer for svalue
void print_svalue(SVALUE val){
	printf("%d ", val);
}


/* Printer for stack
print each element from upper to buttom
*/
void print_stack(STACK s){
	STACK temp;
	temp=s;

	while (s->head != NULL){
		print_svalue((s->data));
		s=s->head;
	}
	print_svalue((s->data));
	printf("\n");

	s=temp;
}
