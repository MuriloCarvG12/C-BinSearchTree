//
// Created by Murilo on 12/07/2025.
//


#include "bintree.h"
tree_node *Tree_root = NULL;

void add_node(tree_node **tree, int value, int depth)
{
    int current_depth = depth;
    tree_node **current_node = tree;
    if(*current_node == NULL)
    {
        printf("This node is empty! initializing it\n");
        tree_node *new_node =  malloc(sizeof(tree_node));
        new_node->node_value = value;
        new_node->right_node = NULL;
        new_node->left_node = NULL;
        *current_node = new_node;
        printf("  New leaf node with value %d added at depth %d\n", value, current_depth);
    }
    else
    {
        printf("This node is not empty! finding where to add our node\n");
        if(value == (*current_node)->node_value)
        {
            printf("this value is already in our tree!\n");
            return;
        }
        else if(value < (*current_node)->node_value)
        {
            printf("Our node value %d is smaller than %d\n", value ,(*current_node)->node_value);
            current_node = &(*current_node)->left_node;
            add_node(current_node,  value, current_depth + 1);
        }
        else
        {
            printf("Our node value %d is bigger than %d\n", value ,(*current_node)->node_value);
            current_node = &(*current_node)->right_node;
            add_node(current_node,  value, current_depth + 1);
        }
    }
}

void print_tree(tree_node *tree, int depth)
{
    tree_node *current_node = tree;

    if(current_node == NULL)
    {

        return;
    }

    else
    {

        print_tree(current_node-> right_node,  depth + 1);

        for(int i = 0; i < depth*2; i++)
        {

            printf("    ");
        }

        printf("%d", current_node->node_value);
        printf("\n");



        print_tree(current_node-> left_node,  depth + 1);

    }
}
