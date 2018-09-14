#include "stack.h"
#include <stdlib.h>
#include <stdio.h>


Stack *stack_init()
{
  Stack* stack = malloc(sizeof(Stack));
  stack -> first = NULL;
  stack -> last = NULL;
  stack -> count = 0;
  return stack;
}


Node* node_init(int value)
{
  Node* node = malloc(sizeof(Node));
  node -> value = value;
  node -> next = NULL;
  return node;
}

void push(Stack* stack, int color)
{
  Node* node = node_init(color);
  if (stack -> last)
    {
      stack -> last -> next = node;
      stack -> last = node;
      /** printf("Pushed" ); */
    }
  else
    {
     stack -> first = node;
     stack -> last = node;
    }
    stack -> count += 1;
}


int pop(Stack* stack)
{
  // Color a retornar
  int color;
  // Vemos si el stack esta vacio, retornando -1 en ese caso
  if (stack -> count == 0){
    color = -1;
    return color;
  }


  // Vemos si tiene solo un elemento
  if (stack -> count == 1)
  {
    color = stack -> first -> value;
    free(stack -> first);
    stack -> first = NULL;
    stack -> last = NULL;
    stack -> count = 0;
    return color;
  }


  if (stack -> last) {
    Node* current = stack -> first;
    for (int i = 0; i < stack -> count; i++) {
      if (i < stack -> count - 2) {
        current = current -> next;
      }
      else{
        Node* eliminar = current -> next;
        color = eliminar -> value;
        stack -> last = current;
        stack -> count -= 1;
        free(eliminar);
        return color;
      }
      }
  }
return -2;
}


/** Libera los nodos recursivamente */
void iterative_destroy(Node* node, int largo)
{
  while(largo  > 0)
  {
    largo -= 1;
    Node* siguiente = node -> next;
    free(node);
    node = siguiente;
  }
}

void destroy(Stack *stack)
{
Node* actual = stack -> first;
iterative_destroy(actual, stack -> count);
free(stack);
  /* Aqui agrega tu código */
}


/* A continuación puedes crear cualquier función adicional que ayude en la
  implementación de tu programa */
