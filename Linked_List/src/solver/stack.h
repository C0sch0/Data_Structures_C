#pragma once


typedef struct stack Stack;

typedef struct node Node;


struct node
{
  /** Siguiente nodo */
  struct node* next;
  /** Valor del nodo */
  int value;
};

typedef struct node Node;


struct stack
{
  /** Primer nodo */
  Node* first;
  /** Ultimo nodo */
  Node* last;
  /** Cantidad de nodos */
  int count;
};

typedef struct stack Stack;

Stack *stack_init();

void push(Stack* stack, int color);

int pop(Stack* stack);

void destroy(Stack *stack);
