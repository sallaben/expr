//
//  node.c
//  expr
//
//  Created by sallaben on 10/4/17.
//

#include "node.h"

struct Node {
    Node parent;
};

Node Node_new(Node parent) {
    Node node = malloc(sizeof(Node));
    node->parent = parent;
    return node;
}

void Node_free(Node node) {
    free(node->parent);
    free(node);
}

void set_parent(Node node, Node parent) {
    node->parent = parent;
}