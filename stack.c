#include <stdio.h>
#include <stdlib.h>

#define MAX 5 // Define the maximum size of the stack

// Structure to represent a stack
struct Stack {
    int arr[MAX];
    int top;
};

// Function to initialize the stack
void initStack(struct Stack* stack) {
    stack->top = -1; // Stack is empty initially
}

// Function to check if the stack is full
int isFull(struct Stack* stack) {
    return stack->top == MAX - 1;
}

// Function to check if the stack is empty
int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

// Function to push an element onto the stack
void push(struct Stack* stack, int value) {
    if (isFull(stack)) {
        printf("Stack Overflow! Unable to push %d\n", value);
    } else {
        stack->arr[++stack->top] = value;
        printf("%d pushed onto the stack\n", value);
    }
}

// Function to pop an element from the stack
int pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack Underflow! No element to pop\n");
        return -1; // Return -1 if stack is empty
    } else {
        int poppedValue = stack->arr[stack->top--];
        printf("%d popped from the stack\n", poppedValue);
        return poppedValue;
    }
}

// Function to peek the top element of the stack
int peek(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty! No element to peek\n");
        return -1;
    } else {
        return stack->arr[stack->top];
    }
}

// Main function to demonstrate stack operations
int main() {
    struct Stack stack;
    initStack(&stack);

    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);

    printf("Top element is %d\n", peek(&stack));

    pop(&stack);
    pop(&stack);

    printf("Top element is now %d\n", peek(&stack));

    return 0;
}

