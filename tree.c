#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "tree.h"

struct Node* insertNode(struct Node* root, char* data){
        if (root == NULL){
                //make new node
                struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
                if (newNode != NULL){
                        newNode->data = strdup(data);
                        newNode->left = NULL;
                        newNode->right = NULL;
                        newNode->middle = NULL;
                        return newNode;
                }
        }else{
                int compare = strncmp(data,root->data, 1);
                //printf("For root: %s \n", root->data);
                if(compare < 0){
                        //insert left
                        //printf("inserting %s left\n", data);
                        root->left = insertNode(root->left, data);
                }else if(compare > 0){
                        //insert right
                        //printf("inserting %s right\n", data);
                        root->right=insertNode(root->right, data);
                }else{
                        //insert middle
                        //printf("inserting %s middle\n", data);
                        root->middle = insertNode(root->middle, data);
                }
        }
        return root;
}

void freeTree(struct Node* root){
        if(root != NULL){
                freeTree(root->left);
                freeTree(root->middle);
                freeTree(root->right);
                free(root->data);
                free(root);
        }
}

void printInOrder(struct Node* root, FILE *file, int level){
        if(root != NULL){
                printInOrder(root->left, file, level+1);
                fprintf(file,"Level: %d || %s\n", level, root->data);
                printInOrder(root->middle, file, level+1);
                printInOrder(root->right, file, level+1);
        }
}

void printPostOrder(struct Node* root, FILE *file, int level){
        if(root != NULL){
                printPostOrder(root->left, file, level+1);
                printPostOrder(root->middle, file, level+1);
                printPostOrder(root->right, file, level+1);
                fprintf(file,"Level: %d || %s\n", level, root->data);
        }
}

void printPreOrder(struct Node* root, FILE *file, int level){
        if(root != NULL){
                fprintf(file,"Level: %d || %s\n", level, root->data);
                printPreOrder(root->left, file, level+1);
                printPreOrder(root->middle, file, level+1);
                printPreOrder(root->right, file, level+1);
        }
}


struct Node* buildTree(FILE *file){

        struct Node* root = NULL;
        int ch;
        int index = 0;
        char word[256];

        while ((ch = fgetc(file)) != EOF){
                if (ch == ' ' || ch == '\n' || ch == '\t') {
                        word[index] = '\0';
                        if (index > 0) {
                                root = insertNode(root, word);
                        }
                        index = 0; // Reset index for the next string
                } else {
                        word[index++] = ch;
                }
        }

        return root;
}
