#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX_LENGTH 101
#define ALPHABET_SIZE 27
#define CASE 'a'

// Define struct

// First, we define a Trie_Node structure with only the necessary information
// For further implementations, each node should have not only the biggest
// priority word, but also the word and priority of the word it was created
// with
// Trie node
struct Trie_Node
{
     struct Trie_Node *children[ALPHABET_SIZE];
     bool is_end;
     char longest_word[MAX_LENGTH];
     int longest_int;
};



typedef struct Trie_Node Trie;

// Headers here
void insert(Trie* trieTree, char* word, int freq, int length);
void destroy_all(Trie* trieTree);
char* suggest(Trie* trieTree, char* word, int length);
Trie *trie_init();
