#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct tree
{
    int data;
    struct tree *leftlink;
    struct tree *rightlink;
};
struct tree *root;
void inorder(struct tree *travel);
void preorder(struct tree *travel);
void postorder(struct tree *travel);
struct tree *create()
{
    struct tree *newnode;
    newnode = (struct tree *)malloc(sizeof(struct tree));
    printf("Enter data\n");
    int x;
    scanf("%d", &x);
    if (x == -1)
        return (NULL);
    else
    {
        newnode->data = x;
        printf("Enter left child of %d\n", x);
        newnode->leftlink = create();
        printf("Enter right child of %d\n", x);
        newnode->rightlink = create();
        return (newnode);
    }
}
void main()
{

    root = create();
    printf("lets transverse in inorder..!!! \n");
    inorder(root);
    printf("\n");
    printf("lets transverse in preorder..!!! \n");
    preorder(root);
    printf("\n");
    printf("lets transverse in postorder..!!! \n");
    postorder(root);
}

void inorder(struct tree *travel)
{
    if (travel->leftlink != NULL)
        inorder(travel->leftlink);
    printf("%d ", travel->data);
    if (travel->rightlink != NULL)
        inorder(travel->rightlink);
}
void preorder(struct tree *travel)
{
    printf("%d ", travel->data);
    if (travel->leftlink != NULL)
        preorder(travel->leftlink);

    if (travel->rightlink != NULL)
        preorder(travel->rightlink);
}
void postorder(struct tree *travel)
{

    if (travel->leftlink != NULL)
        postorder(travel->leftlink);

    if (travel->rightlink != NULL)
        postorder(travel->rightlink);
    printf("%d ", travel->data);
}