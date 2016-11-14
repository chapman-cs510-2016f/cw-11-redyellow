#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

// Define a new NULL stack pointer and return it
// Constructor that initializes an empty stack pointer
STACK new_stack() {
    STACK new = NULL;
    return new;
}

/* Add one more element
 * Setter for pushing a value onto the stack
    1. Allocate memory for a new stack and return the address of the new stack (what function malloc() does);
    2. Set the value in the new stack to "val";
    3. Set the head of the new stack to s;
       It means the new stack is now pointing to the next stack, which was the first stack before;
    4. Reset address s to address new, which means s is pointing to the newly pushed stack.
 */
void push_stack(STACK *s, SVALUE val) { 
    // Use STACK *s instead of just STACK s because we do want to change the address in pointer s, not the address in the copy of s
    STACK new = (STACK) malloc(sizeof(struct stack));
    new->data = val;
    new->head = *s;
    *s = new;
}

/*
 * Remove the first element and return the value in the removed stack
 * Getter for popping a value off the stack
    1. Define temporay variable SVALUE (int) val and STACK temp;
    2. Check whether s points to NULL.  If yes, it means s is already the head in the very bottom stack.  Set "val" to -1;
    3. Otherwise, set "val" equal to the data value in the first stack that we are trying to remove now;
    4. Set "temp" to address s, which is like making a copy of address s;
    4. Set the address in s to the head address first stack, so now s is pointing to the second stack;
    5. Free the memory of the address in temp, which is the first stack;
    6. Return the value in the deleted stack.
 */
SVALUE pop_stack(STACK *s) {
    // Use STACK *s instead of just STACK s for the same reason in push_stack
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
void print_svalue(SVALUE val) {
	printf("%d", val);
}

/* Printer for stack
 * Print each element from up to bottom
*/
void print_stack(STACK s) {
	while (s->head != NULL) {
		print_svalue(s->data);
        printf("\t");
		s = s->head;
	}
	print_svalue(s->data);
	printf("\n");
}

/* Slightly different, but also works
 * Printer for stack
 * No need to do "print_svalue(s->data)" again after while loop, but would leave an unused tab at the end of the line

void print_stack(STACK s) {
	while (s != NULL) {
		print_svalue(s->data);
        printf("\t");
		s = s->head;
	}
	puts("");
}
*/
