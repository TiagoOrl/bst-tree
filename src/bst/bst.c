#include "bst.h"
#include <stdlib.h>
#include <string.h>

static node* create_node(int key, void* data, int nmemb, int nbytes) {
    node* new_node = (node*) calloc(1, sizeof(node));
    new_node->size = nmemb * nbytes;
    new_node->key = key;
    new_node->left = NULL;
    new_node->right = NULL;
    new_node->data = calloc(nmemb, nbytes);

    memcpy(new_node->data, data, nmemb * nbytes);

    return new_node;
}


node* find_parent(bst* bst, int key) {
    node *it = bst->root;

    while (it != NULL) {
        if (it->left->key == key || it->right->key == key)
            return it;
        
        if (key < it->key)
            it = it->left;

        else 
            it = it->right;
    }

    return NULL;
}


static node* find_node(bst* bst, int key) {
    node *it = bst->root;
    while (it != NULL) {
        if (it->key == key)
            return it;
        
        if (key < it->key)
            it = it->left;

        else 
            it = it->right;
    }

    return NULL;
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


bool bst_contains(bst *bst, int key) {
    node* it = bst->root;

    if (find_node(bst, key) != NULL)
        return true;

    return false;
}


bool bst_remove(bst* bst, int key) {
    node* found = find_node(bst, key);

    if (found == NULL)
        return false;
    
    
}


void bst_insert(bst *bst, int key, void *data, int nmemb, int nbytes) {

    node* new_node = create_node(key, data, nmemb, nbytes);
    node* it = bst->root;
    node* to_insert = NULL;

    if (bst->root == NULL) {
        bst->root = new_node;
        return;
    }

    while (it != NULL) {
        to_insert = it;

        if (key < it->key)
            it = it->left;
        
        else
            it = it->right;
    }

    if (key < to_insert->key)
        to_insert->left = new_node;

    else
        to_insert->right = new_node;

    bst->size++;
}