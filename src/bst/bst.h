#ifndef H_BST_DEF
#define H_BST_DEF

struct _node {
    char hash[80];
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
void bst_insert(bst *bst, void *data, int nmemb, int nbytes);
int bst_contains(bst *bst, void *data);


#endif