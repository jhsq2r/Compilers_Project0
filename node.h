#ifndef NODE_H
#define NODE_H

struct Node {
        char* data;
        struct Node *left;
        struct Node *middle;
        struct Node *right;
};

#endif
