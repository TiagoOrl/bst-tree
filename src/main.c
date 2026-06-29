#include "./bst/bst.h"
#include <stdio.h>

int main(int argc, char const *argv[])
{
    bst tree = bst_new();
    bst_insert(&tree, (void*)"test 123", 10, sizeof(char));
    bst_insert(&tree, (void*)"test 123", 15, sizeof(char));
    bst_insert(&tree, (void*)"test 123", 6, sizeof(char));
    return 0;
}
