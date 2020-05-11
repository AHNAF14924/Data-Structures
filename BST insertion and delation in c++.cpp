#include<iostream>
using namespace std;
struct Node {
	int data;
	struct Node *left;
	struct Node *right;
}; 
struct Node* FindMin(struct Node* root)
{
	while(root->left != NULL) root = root->left;
	return root;
}
struct Node* Delete(struct Node *root, int data) {
	if(root == NULL) return root; 
	else if(data < root->data) root->left = Delete(root->left,data);
	else if (data > root->data) root->right = Delete(root->right,data);	
	else {
		if(root->left == NULL && root->right == NULL) { 
			delete root;
			root = NULL;
		}
		else if(root->left == NULL) {
			struct Node *temp = root;
			root = root->right;
			delete temp;
		}
		else if(root->right == NULL) {
			struct Node *temp = root;
			root = root->left;
			delete temp;
		}
		else { 
			struct Node *temp = FindMin(root->right);
			root->data = temp->data;
			root->right = Delete(root->right,temp->data);
		}
	}
	return root;
}
void Inorder(struct Node *root) {
	if(root == NULL) return;
 
	Inorder(root->left); 
	printf("%d ",root->data);
	Inorder(root->right);      
}
struct Node* Insert(struct Node *root,int data) {
	if(root == NULL) {
		root = new Node();
		root->data = data;
		root->left = root->right = NULL;
	}
	else if(data <= root->data)
		root->left = Insert(root->left,data);
	else 
		root->right = Insert(root->right,data);
	return root;
}

int main() {
	struct Node* root = NULL;
	root = Insert(root,12); root = Insert(root,22);
	root = Insert(root,9); root = Insert(root,6); 
	root = Insert(root,2); root = Insert(root,32);
	cout<<"Inorder: ";
	Inorder(root);
	cout<<"\n";
	root = Delete(root,12);
	cout<<"Inorder: ";
	Inorder(root);
	cout<<"\n";
}