#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "node.h"
#include "tree.h"

//Author: Jarod Stagner
//Date: 02/08/2024

void help(){
        printf("Incorrect Usage\nHere are the valid ways to run this program:\n./Project0 [filename]\n");
        printf("./Project0\n./Project0 < [filename]\nThis program is designed to take in multiple words and then create a ternary tree with them\n");
        printf("The program will make 3 output files of the different orderings: InOrder, PreOrder, and PostOrder\n");
}

int main(int argc, char** argv) {

        FILE *file;
        char buffer[100];

        if(argc > 2){//if invalid

                help();
                return EXIT_FAILURE;

        }else if(argc == 2){//if file input

                file = fopen(argv[1],"r");

        }else{//if stdin

                file = fopen("tempfile.txt", "w+");

                while (fgets(buffer, sizeof(buffer),stdin) != NULL){
                        fputs(buffer, file);
                }

                fseek(file, 0, SEEK_SET);

        }

        if(file == NULL){
                printf("Problem with given file... exiting\n");
                return EXIT_FAILURE;
        }
        fseek(file, 0, SEEK_END);
        if(ftell(file) == 0){
                fclose(file);
                printf("Given file is empty... exiting\n");
                return EXIT_FAILURE;
        }else{
                fseek(file, 0, SEEK_SET);
        }

        struct Node *root = buildTree(file);
        fclose(file);

        file = fopen("output.InOrder.txt", "w");
        fprintf(file,"InOrder:\n");
        printInOrder(root, file, 0);
        fclose(file);

        file = fopen("output.PreOrder.txt", "w");
        fprintf(file,"PreOrder:\n");
        printPreOrder(root, file, 0);
        fclose(file);

        file = fopen("output.PostOrder.txt", "w");
        fprintf(file,"PostOrder:\n");
        printPostOrder(root, file, 0);
        fclose(file);

        freeTree(root);

        return;
}
