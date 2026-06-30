#ifndef H_BST_DEF
#define H_BST_DEF

#include <stdbool.h>

struct _node {
    int key;
    void * data;
    int size;
    int height;
    struct _node *left;
    struct _node *right;
};

typedef struct _node node;

struct _bst {
    node * root;
    int max;
    int min;
    int size;
};
typedef struct _bst bst;



bst bst_new();
void bst_insert(bst *bst, int key, void *data, int nmemb, int nbytes);
bool bst_remove(bst* bst, int key);
bool bst_contains(bst *bst, int key);


#endif