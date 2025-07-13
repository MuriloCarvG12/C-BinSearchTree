#include <stdio.h>
#include "bintree.h"

int main() {



    // 2) Add some values:
    add_node(&Tree_root,  5, 0);
    add_node(&Tree_root,  3, 0);
    add_node(&Tree_root,  8, 0);
    add_node(&Tree_root,  1, 0);
    add_node(&Tree_root,  4, 0);
    add_node(&Tree_root, 10, 0);

    // 3) Print the tree (indentation shows structure):
    printf("\nPrinting tree structure:\n");
    print_tree(Tree_root, 0);

    return 0;

}
