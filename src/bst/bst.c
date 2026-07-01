#include "bst.h"
#include <stdlib.h>
#include <string.h>

static node* create_node(int key, void* data, int nmemb, int nbytes) {
    node* new_node = (node*) calloc(1, sizeof(node));
    
    if (new_node == NULL)
        return NULL;

    new_node->size = nmemb * nbytes;
    new_node->key = key;
    new_node->left = NULL;
    new_node->right = NULL;
    new_node->parent = NULL;
    new_node->data = calloc(nmemb, nbytes);

    memcpy(new_node->data, data, nmemb * nbytes);

    return new_node;
}


static void free_node(node* node) {
    free(node->data);
    free(node);
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

    // only one node in tree
    if (found->parent == NULL)
    {
        bst->root = NULL;
        bst->size = 0;
        free_node(found);
        return true;
    }


    // leaf node
    if (found->left == NULL && found->right == NULL) {
        node* parent_found = found->parent;

        if (parent_found->left == found)
            parent_found->left = NULL;

        if (parent_found->right == found)
            parent_found->right = NULL;

        free_node(found);
        return true;
    }

    // one child
    
}


void bst_insert(bst *bst, int key, void *data, int nmemb, int nbytes) {

    node* new_node = create_node(key, data, nmemb, nbytes);
    node* it = bst->root;
    node* parent = NULL;    // the parent of the new node to be inserted

    if (bst->root == NULL) {
        bst->root = new_node;
        return;
    }

    while (it != NULL) {
        parent = it;

        if (key == it->key)
            return;

        if (key < it->key)
            it = it->left;
        
        else
            it = it->right;
    }

    if (key < parent->key)
        parent->left = new_node;

    else
        parent->right = new_node;

    new_node->parent = parent;

    bst->size++;
}