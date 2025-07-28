
/**
 *      PROJECT TREES
 *
 *   INCLUDES THE TREE NODE DECLARATION
 *   FUNCTIONS
 *          -ADD NODE
 *          -REMOVE NODE
 *          -PRINT TREE
 *          -FIND NODE
 *
 *
 * **/


#ifndef TREES_BINTREE_H
#define TREES_BINTREE_H


#include <stddef.h>
#include <malloc.h>
#include <stdio.h>

    typedef struct tree_node
    {
        int node_value;
        struct tree_node *left_node;
        struct tree_node *right_node;

        int node_height;
    } tree_node;

    extern tree_node *Tree_root;

    void user_menu(tree_node **tree);
    void add_node(tree_node **tree, int node_value, int depth);
    void remove_node(tree_node **tree, int node_value);
    void print_tree(tree_node *tree, int depth);
    tree_node *find_node(tree_node **tree, int node_value);
    void find_smallest_node(tree_node **tree, int depth);
    void find_biggest_node(tree_node **tree, int depth);
    int find_tree_depth(tree_node *tree);
    int count_nodes(tree_node *tree);
    void free_tree(tree_node **tree);
    int find_branch_height(tree_node *node_to_search);


#endif //TREES_BINTREE_H

