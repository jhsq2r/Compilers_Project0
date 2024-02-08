#ifndef TREE_H
#define TREE_H

#include "node.h"

struct Node* buildTree(FILE *file);
void printPreOrder(struct Node* root, FILE *file, int level);
void printInOrder(struct Node* root, FILE *file, int level);
void printPostOrder(struct Node* root, FILE *file, int level);
void freeTree(struct Node* root);

#endif
