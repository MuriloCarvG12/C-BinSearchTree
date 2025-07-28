
//
// Created by Murilo on 12/07/2025.
//


#include "bintree.h"
tree_node *Tree_root = NULL;


void user_menu(tree_node **tree)
{
    int current_option = 0;
    int node_value = 0;
    int tree_depth = 0;
    int tree_nodes = 0;
    int node_balance = 0;
    tree_node *node_to_search;
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
                printf("-- 10 - find the tree height --\n");
                printf("-- 20 - Close the program --\n");
                scanf("%d", &current_option);
                break;
            case 1:
                printf("Please Inform the value of the new node\n");
                scanf("%d", &node_value);
                add_node(&(*tree), node_value, 0);
                current_option = 0;
                break;
            case 2:
                printf("Please Inform the value of the node to be deleted\n");
                scanf("%d", &node_value);
                remove_node(&(*tree), node_value);
                current_option = 0;
                break;
            case 3:
                print_tree((*tree), 0);
                current_option = 0;
                break;
            case 4:
                printf("Please Inform the value of the node to be searched for\n");
                scanf("%d", &node_value);
                find_node(&(*tree), node_value);
                current_option = 0;
                break;
            case 5:
                find_smallest_node(&(*tree), 0);
                current_option = 0;
                break;
            case 6:
                find_biggest_node(&(*tree), 0);
                current_option = 0;
                break;
            case 7:
                tree_depth = find_tree_depth((*tree));
                printf("The depth of the tree is %d\n", tree_depth);
                current_option = 0;
                break;
            case 8:
                tree_nodes = count_nodes((*tree));
                printf("The amount of nodes in the tree is %d\n", tree_nodes);
                current_option = 0;
                break;
            case 9:
                free_tree(&(*tree));
                current_option = 0;
                break;
            case 10:
                printf("Please Inform the value of the node to be searched for\n");
                scanf("%d", &node_value);
                node_to_search = find_node(&(*tree), node_value);
                node_balance = find_branch_height(&node_to_search);
                printf("%d\n", node_balance);
                break;
            case 20:
                current_option = 20;
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
        new_node->node_height = depth;
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

tree_node *find_node(tree_node **tree, int node_value)
{
    tree_node **current_node = tree;

    printf("searching for node with value %d\n",node_value);

    if(*current_node == NULL)
    {
        printf("The node with value %d is not in our tree\n", node_value);
        return (tree_node *) NULL;
    }
    else if(node_value < (*current_node)->node_value)
    {
        printf("current node checked has value %d, bigger than the node we are searching for! Going to the left\n", (*current_node)->node_value);
        current_node = &(*current_node)->left_node;
        return find_node(current_node,  node_value);
    }
    else if(node_value > (*current_node)->node_value)
    {
        printf("current node checked has value %d, smaller than the node we are searching for! Going to the right\n", (*current_node)->node_value);
        current_node = &(*current_node)->right_node;
        return find_node(current_node,  node_value);
    }
    else
    {

        return *current_node;
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

int find_branch_height(tree_node *node_to_search)
{

    int left;
    int right;

    if(&(*node_to_search) ==  NULL)
    {
        return 0;
    }

    printf("current node we have is %d\n", (node_to_search)->node_value);

    left = find_branch_height((node_to_search)->left_node);
    right = find_branch_height( (node_to_search)->right_node);

    return 1 + (left > right ? left : right);
};

int find_node_balance(int node_value)
{
    int left, right, balance = 0;
    tree_node *node_to_search;
    node_to_search = find_node(&(Tree_root), 80);
    left = find_branch_height(node_to_search->left_node);
    right = find_branch_height(node_to_search->right_node);
    balance = right - left;
    if(balance == 0)
    {
        printf("This Node is balanced!\n");
    }
    else if(balance < 0)
    {
        printf("This Node is unbalanced on the left branch!\n");
    }
    else
    {
        printf("This right is unbalanced on the right branch!\n");
    }
    return balance;


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

//Note: its called right_rotate because the lft_ndoe is now going where its father node was, if we try to think about it a little we can see that the left_node is moving to the right

tree_node *right_node_rotate(tree_node *node)
{
    tree_node *current_node = node;
    tree_node *left_node = current_node->left_node;
    tree_node *aux_node = left_node->right_node;

    left_node->right_node = current_node;
    current_node->left_node = aux_node;

    return left_node;
}

tree_node *left_node_rotate(tree_node *node)
{
    tree_node *current_node = node;
    tree_node *right_node = current_node->right_node;
    tree_node *aux_node = right_node->left_node;

    right_node->left_node = current_node;
    right_node->right_node = aux_node;


    return right_node;

}