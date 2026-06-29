#include "bst.h"
#include <stdlib.h>
#include <string.h>

static node* create_node(void* data, int nmemb, int nbytes) {
    node* new_node = (node*) calloc(1, sizeof(node));
    new_node->size = nmemb;
    new_node->left = NULL;
    new_node->right = NULL;
    new_node->data = calloc(nmemb, nbytes);

    memcpy(new_node->data, data, nmemb * nbytes);

    return new_node;
}


bst bst_new() {
    bst bst = {
        .min = 0,
        .max = 0,
        .size = 0,
        .root = NULL
    };

    return bst;
}


void bst_insert(bst *bst, void *data, int nmemb, int nbytes) {

    node* new_node = create_node(data, nmemb, nbytes);
    node* it = bst->root;
    node* to_insert = NULL;

    if (bst->root == NULL) {
        bst->root = new_node;
        return;
    }

    while (it != NULL) {
        to_insert = it;

        if (nmemb <= it->size)
            it = it->left;
        
        else
            it = it->right;
    }

    if (nmemb <= to_insert->size)
        to_insert->left = new_node;

    else
        to_insert->right = new_node;

    bst->size++;
}