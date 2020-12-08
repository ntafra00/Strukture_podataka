#include <stdio.h>
#include <stdlib.h>

typedef struct tree_node *Bst_ptr;

struct tree_node
{
    int data;
    Bst_ptr left;
    Bst_ptr right;
};

Bst_ptr insertion(int, Bst_ptr);     // funkcija koja unosi element u BST
Bst_ptr newNode(int);                // funkcija koja stvara novi node
Bst_ptr find(int, Bst_ptr);          // funkcija koja pronalazi element u BST
int inorder(Bst_ptr);                // funckija koja ispisuje BST na inorder nacin
int preorder(Bst_ptr);               // funkcija koja ispisuje BST na preorder nacin
int postorder(Bst_ptr);              // funkcija koja ispisuje BST na postorder nacin
Bst_ptr deleteElement(int, Bst_ptr); // funkcija koja brise element iz BST-a
Bst_ptr findMin(Bst_ptr);            // funkcija koja trazi minimalan clan
Bst_ptr deleteAll(Bst_ptr);          // funkcija koja brise kompletan sadrzaj stabla

int main()
{
    Bst_ptr root = NULL;
    Bst_ptr temp;
    char choice;
    int answer = 0;

    root = insertion(10, root);
    root = insertion(20, root);
    root = insertion(8, root);
    root = insertion(6, root);
    root = insertion(30, root);
    root = insertion(15, root);
    root = insertion(9, root);

    printf("Na koji nacin zelite ispisati BST: p - preorder, i - inorder, t - postorder: ");
    scanf(" %c", &choice);

    if (choice == 'p')
    {
        preorder(root);
    }
    else if (choice == 'i')
    {
        inorder(root);
    }
    else
    {
        postorder(root);
    }

    root = deleteElement(20, root);

    root = deleteAll(root);

    return 0;
}

Bst_ptr insertion(int value, Bst_ptr root_ref)
{
    if (root_ref == NULL)
    {
        return newNode(value);
    }
    else if (root_ref->data >= value)
    {
        root_ref->left = insertion(value, root_ref->left);
    }
    else
    {
        root_ref->right = insertion(value, root_ref->right);
    }

    return root_ref;
}

Bst_ptr newNode(int value)
{
    Bst_ptr new;

    new = (Bst_ptr)malloc(sizeof(struct tree_node));

    if (new == NULL)
    {
        printf("Problem with allocated memory.");
        return NULL;
    }

    new->data = value;
    new->left = NULL;
    new->right = NULL;

    return new;
}

Bst_ptr find(int value, Bst_ptr root_ref)
{
    if (root_ref == NULL)
    {
        return root_ref;
    }
    else if (root_ref->data == value)
    {
        return root_ref;
    }
    else if (root_ref->data >= value)
    {
        return find(value, root_ref->left);
    }
    else
    {
        return find(value, root_ref->right);
    }
}

int inorder(Bst_ptr root_ref)
{
    if (root_ref != NULL)
    {
        inorder(root_ref->left);
        printf("%d \n", root_ref->data);
        inorder(root_ref->right);
    }

    return 0;
}

int preorder(Bst_ptr root_ref)
{

    if (root_ref != NULL)
    {
        printf("%d\n", root_ref->data);
        preorder(root_ref->left);
        preorder(root_ref->right);
    }
    return 0;
}

int postorder(Bst_ptr root_ref)
{
    if (root_ref != NULL)
    {
        postorder(root_ref->left);
        postorder(root_ref->right);
        printf("%d\n", root_ref->data);
    }

    return 0;
}

Bst_ptr findMin(Bst_ptr root)
{
    while (root->left != NULL)
    {
        root = root->left;
    }

    return root;
}

Bst_ptr deleteElement(int value, Bst_ptr root)
{
    Bst_ptr child, temp;

    if (root == NULL)
    {
        return root;
    }
    else if (root->data > value)
    {
        root->left = deleteElement(value, root->left);
    }
    else if (root->data < value)
    {
        root->right = deleteElement(value, root->right);
    }
    else
    {
        //case 1: 0 children
        if (root->left == NULL && root->right == NULL)
        {
            free(root);
            root = NULL;
        }

        // case 2: 1 child
        else if (root->left == NULL)
        {
            temp = root;
            root = root->right;
            free(temp);
        }
        else if (root->right == NULL)
        {
            temp = root;
            root = root->left;
            free(temp);
        }

        //case 3: 2 children
        else
        {
            temp = findMin(root->right);
            root->data = temp->data;
            root->right = deleteElement(temp->data, root->right);
        }
    }

    return root;
}

Bst_ptr deleteAll(Bst_ptr root)
{
    if (root != NULL)
    {
        root->left = deleteAll(root->left);
        root->right = deleteAll(root->right);
        free(root);
    }

    return NULL;
}