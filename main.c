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
    add_node(&Tree_root, 50, 0);
    add_node(&Tree_root, 57, 0);


    // 3) Print the tree (indentation shows structure):
    printf("\nPrinting tree structure:\n");
    print_tree(Tree_root, 0);

    find_node(&Tree_root, 4, 0);
    find_smallest_node(&Tree_root, 0);
    find_biggest_node(&Tree_root, 0);

    printf("the depth of the tree is %d\n",find_tree_depth(Tree_root));
    printf("the amount of nodes in the tree is %d\n",count_nodes(Tree_root));
    remove_node(&Tree_root, 3);
    print_tree(Tree_root, 0);
    free_tree(&Tree_root);
    printf("\nPrinting tree structure:\n");
    print_tree(Tree_root, 0);

    return 0;

}
