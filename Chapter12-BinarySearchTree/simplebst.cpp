#include <iostream>
#include <stdlib.h>

using namespace std;

struct node {
	int key;
	struct node *left, *right;
};

struct node* newNode(int data){
  struct node* node = (struct node*)malloc(sizeof(struct node));
  node->key = data;
  node->left = NULL;
  node->right = NULL;

  return node;
}

struct node* insert(struct node *root, int key) {
	struct node *new_node = newNode(key);

	if(root == NULL) {
		return new_node;
	}
	if(root != NULL) {
		if(root->key > key)
			root->left = insert(root->left, key);
		else
			root->right = insert(root->right, key);
	}
}

struct node* minValueNode(struct node *root) {
	struct node *current = root;


	while(current->left != NULL) {
		current = current->left;
	}
	return current;
}

struct node* deleteNode(struct node* root, int key)
{
    // base case
    if (root == NULL) return root;

    // If the key to be deleted is smaller than the root's key,
    // then it lies in left subtree
    if (key < root->key)
        root->left = deleteNode(root->left, key);

    // If the key to be deleted is greater than the root's key,
    // then it lies in right subtree
    else if (key > root->key)
        root->right = deleteNode(root->right, key);

    // if key is same as root's key, then This is the node
    // to be deleted
    else
    {
        // node with only one child or no child
        if (root->left == NULL)
        {
            struct node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            struct node *temp = root->left;
            free(root);
            return temp;
        }

        // node with two children: Get the inorder successor (smallest
        // in the right subtree)
        struct node* temp = minValueNode(root->right);

        // Copy the inorder successor's content to this node
        root->key = temp->key;

        // Delete the inorder successor
        root->right = deleteNode(root->right, temp->key);
    }
    return root;
}

/*
void transplant(struct node* root, struct node* u, struct node* v) {
	if(u.parent == NULL)
		root->key = v->key;
	else if (u==u.parent.left)
		u.parent.left = v;
	else
		u.parent.right = v;
	if (v != NULL)
		v.parent = u.parent;
}
*/

void inorder(struct node *root) {
	if(root != NULL) {
		inorder(root->left);
		cout<<root->key<<" ";
		inorder(root->right);
	}
}

void preorder(struct node *root) {
	if(root != NULL) {
		cout<<root->key<<" ";
		preorder(root->left);
		preorder(root->right);
	}
}

void postorder(struct node *root) {
	if(root != NULL) {
		postorder(root->left);
		postorder(root->right);
		cout<<root->key<<" ";
	}
}

int main() {

	struct node* root = newNode(2);
	insert(root, 1);
	insert(root, 4);
	insert(root, 3);
	root = deleteNode(root, 2);
	root = deleteNode(root, 1);

	inorder(root);
	cout<<"\n";
	preorder(root);
	cout<<"\n";
	postorder(root);
	return 0;

}
