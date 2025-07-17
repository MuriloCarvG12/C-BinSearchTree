//
// Created by Murilo on 12/07/2025.
//


#include "bintree.h"
tree_node *Tree_root = NULL;


void user_menu(tree_node **tree)
{
    int current_option = 0;
    while(current_option != 20)
    {
        switch(current_option)
        {
            case 0:
                printf("--Binary Search Tree Project--\n");
                printf("-- Select an option --\n");
                printf("-- 1 - Add tree node --\n");
                printf("-- 2 - Remove tree node --\n");
                printf("-- 3 - Print Tree --\n");
                printf("-- 4 - Search for a node --\n");
                printf("-- 5 - Search for the smallest Node --\n");
                printf("-- 6 - Search for the biggest Node --\n");
                printf("-- 7 - Find Tree Depth --\n");
                printf("-- 8 - Count all the tree Nodes --\n");
                printf("-- 9 - Free the tree --\n");
                printf("-- 20 - Close the program --\n");
                scanf("%d", &current_option);
                break;
        }
    }

}

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

void find_node(tree_node **tree, int node_value, int depth)
{
    tree_node **current_node = tree;
    printf("current depth of the tree %d\n", depth);
    printf("searching for node with value %d\n",node_value);

    if(*current_node == NULL)
    {
        printf("The node with value %d is not in our tree\n", node_value);
        return;
    }
    else if(node_value < (*current_node)->node_value)
    {
        printf("current node checked has value %d, bigger than the node we are searching for! Going to the left\n", (*current_node)->node_value);
        current_node = &(*current_node)->left_node;
        find_node(current_node,  node_value, depth + 1);
    }
    else if(node_value > (*current_node)->node_value)
    {
        printf("current node checked has value %d, smaller than the node we are searching for! Going to the right\n", (*current_node)->node_value);
        current_node = &(*current_node)->right_node;
        find_node(current_node,  node_value, depth + 1);
    }
    else
    {
        printf("Node found! at depth %d\n", depth);
    }
}

void find_smallest_node(tree_node **tree, int depth)
{
    tree_node **current_node = tree;
    if((*current_node)->left_node == NULL)
    {
        printf("the smallest node in our tree has the value %d and is in the depth %d\n", (*current_node)->node_value, depth);
        return;
    }
    else
    {
        current_node = &(*current_node)->left_node;
        find_smallest_node(current_node, depth + 1);
    }
}

void find_biggest_node(tree_node **tree, int depth)
{
    tree_node **current_node = tree;
    if((*current_node)->right_node == NULL)
    {
        printf("the biggest node in our tree has the value %d and is in the depth %d\n", (*current_node)->node_value, depth);
        return;
    }
    else
    {
        current_node = &(*current_node)->right_node;
        find_biggest_node(current_node, depth + 1);
    }
}

int find_tree_depth(tree_node *tree)
{
    int depth;
    tree_node *current_node = tree;
    if(current_node == NULL)
    {
       return 0;
    }
    int depth_r = find_tree_depth(current_node->right_node);
    int depth_l =find_tree_depth(current_node->left_node);
    if(depth_l > depth_r)
    {
        depth = depth_l;
    }
    else
    {
        depth = depth_r;
    }

    return depth + 1;
}

int count_nodes(tree_node *tree)
{
    int number_of_nodes = 0;
    tree_node *current_node = tree;
    if(current_node == NULL)
    {
        return 0;
    }

    number_of_nodes += count_nodes((*current_node).left_node);
    number_of_nodes += count_nodes((*current_node).right_node);

    return number_of_nodes + 1;
}

void remove_node(tree_node **tree, int node_value)
{
    tree_node **current_node = tree;
    if((*current_node)->node_value != node_value)
    {
        while((*current_node)->node_value != node_value)
        {
            if((*current_node) == NULL)
            {
                printf("This node is not in the list!\n");
                return;
            }

            if(node_value < (*current_node)->node_value)
            {
                current_node =  &((*current_node)->left_node);
            }
            else if(node_value > (*current_node)->node_value)
            {
                current_node =  &((*current_node)->right_node);
            }

        }

        printf("found node, %d\n", (*current_node)->node_value);
    }

    if((*current_node)->right_node == NULL &&  (*current_node)->left_node == NULL)
    {
        free((*current_node));
        *current_node = NULL;
    }
    else if((*current_node)->right_node == NULL ||  (*current_node)->left_node == NULL)
    {

        tree_node *child = (*current_node)->right_node == NULL ? (*current_node)->left_node : (*current_node)->right_node;
        free((*current_node));
        *current_node = child;
    }

    else if((*current_node)->right_node != NULL &&  (*current_node)->left_node != NULL)
    {
        tree_node *r_child = (*current_node)->right_node;
        tree_node *l_child = (*current_node)->left_node;
        free((*current_node));
        *current_node = r_child;
        while((*current_node)->left_node != NULL)
        {
            current_node =  &((*current_node)->left_node);
        }

        (*current_node)->left_node = l_child;


    }
}

void free_tree(tree_node **tree)
{
    if (*tree == NULL)
        return;

    free_tree(&(*tree)->left_node);
    free_tree(&(*tree)->right_node);

    free(*tree);
    *tree = NULL;
}