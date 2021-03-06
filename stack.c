//
//  stack.c
//  expr
//
//  Created by sallaben on 10/9/17.
//

#include "stack.h"

/*
 * Stack struct definition
 */
struct Stack {
    int list[64];
    int size;
};

/*
 * Allocate and initialize a new instance of a stack (with a limit of 64 integers).
 */
Stack Stack_new() {
    Stack stack = malloc(sizeof(struct Stack));
    stack->size = 0;
    return stack;
}

/*
 * Adds a new integer to the top of the stack
 */
void Stack_push(Stack stack, int i) {
    Stack_shift_right(stack);
    stack->list[0] = i;
    stack->size++;
}

/*
 * Returns and removes the current top integer of the stack
 */
int Stack_pop(Stack stack) {
    int i = stack->list[0];
    Stack_shift_left(stack);
    stack->size--;
    return i;
}

/*
 * Returns the current top integer of the stack
 */
int Stack_peek(Stack stack) {
    if(stack->size > 0) {
        return stack->list[0];
    } else {
        return -1;
    }
}

/*
 * Returns the current integer size of the stack
 */
int Stack_size(Stack stack) {
    return stack->size;
}

/*
 * Prints the given stack in order, distinguishing the top element with [brackets]
 */
void Stack_print(Stack stack) {
    int size = Stack_size(stack);
    printf("\n\nPrinting Stack of size %d", size);
    if(size > 0) {
        for(int i = 0; i < size; i++) {
            if(i == 0) {
                printf("\n[%c] (%d)", stack->list[0], stack->list[0]);
            } else {
                printf("\n%c (%d)", stack->list[i], stack->list[i]);
            }
        }
    } else {
        printf("\nNothing to print!");
    }
}

/*
 * "Shifts" the given stack 1 space to the left, removing space left behind from Stack_pop()
 */
bool Stack_shift_left(Stack stack) {
    if(stack->size <= 0) {
        return false;
    }
    for(int i = 1; i < stack->size; i++) {
        stack->list[i - 1] = stack->list[i];
    }
    return true;
}

/*
 * "Shifts" the given stack 1 space to the right, creating space for the new integer given by Stack_push()
 */
bool Stack_shift_right(Stack stack) {
    if(stack->size >= 64) {
        return false;
    }
    for(int i = stack->size; i > 0; i--) {
        stack->list[i] = stack->list[i - 1];
    }
    return true;
}

/*
 * Frees the Stack from memory
 */
void Stack_free(Stack stack) {
    free(stack);
}
