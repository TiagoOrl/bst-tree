#include "./bst/bst.h"
#include <stdio.h>

int main(int argc, char const *argv[])
{
    bst tree = bst_new();
    bst_insert(&tree, 7, (void*)"test 123", 9, sizeof(char));
    bst_insert(&tree, 13, (void*)"test 123", 9, sizeof(char));
    bst_insert(&tree, 22, (void*)"test 123", 9, sizeof(char));
    bst_insert(&tree, 18, (void*)"test 123", 9, sizeof(char));
    bst_insert(&tree, 2, (void*)"test 123", 9, sizeof(char));


    printf("contains: %i\n", bst_contains(&tree, 56));

    return 0;
}
