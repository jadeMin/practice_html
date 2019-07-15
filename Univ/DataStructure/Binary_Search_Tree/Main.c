#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct treenode* node;
struct treenode {
	int key;
	node left, right, parent;
};
typedef struct btree* tree;
struct btree {
	node root;
	int size;
};
node createNode(int key) {
	node v =(node)malloc(sizeof(struct treenode));
	v->key = key;
	v->left = v->right = v->parent = NULL;
	return v;
}

tree createBinaryTree(void) {
	tree T = (tree)malloc(sizeof(struct btree));
	T->root = NULL;
	T->size = 0;
	return T;
}
node search(tree T, int key) {
	node p = T->root;
	while(p!=NULL){
		if(p->key > key)
			p = p->left;
		else if(p->key < key)
			p = p->right;
		else
			return p;
	}
	return NULL;
}


void preorder(node v) {
	if(v!=NULL){
		printf("%d ->", v->key);
		preorder(v->left);
		preorder(v->right);
	}
}
void inorder(node v) {
	if(v != NULL){
		inorder(v->left);
		printf("%d ->", v->key);
		inorder(v->right);
	}
}
void postorder(node v) {
	if(v!=NULL){
		postorder(v->left);
		postorder(v->right);
		printf("%d ->", v->key);
	}
}

void insert( tree T, int key ) {
	node v, p = T->root, parent = NULL;
	while(p!=NULL){
		parent = p;
		if(key < p->key)
			p = p->left;
		else if(key > p->key)
			p = p->right;
		else
			return;
	}
	v = createNode(key);
	if(parent == NULL)
		T-> root = v;
	else if(key <=parent -> key)
		parent->left = v;
	else
		parent->right = v;
	v->parent = parent;
	T->size++;
}


int main(void) {
	int value;
	char cmd[20];
	node v;
	tree T = createBinaryTree();
	while(1) {
		printf("\n");
		scanf("%s", cmd);
		if(strcmp(cmd, "insert")==0) { // insert at tree
			scanf("%d", &value);
			insert(T, value);
			preorder(T->root);
		} else if(strcmp(cmd, "search")==0) { // search
			scanf("%d", &value);
			v = search(T, value);
			if(v != NULL) printf("%d is found!\n", v->key);
			else printf("Not found!\n");
		} else if(strcmp(cmd, "preorder")==0) { // preorder traversal
			printf("Preorder: ");
			preorder(T->root);
			printf("\n");
		} else if(strcmp(cmd, "postorder")==0) { // postorder traversal
			printf("Postorder: ");
			postorder(T->root);
			printf("\n");
		} else if(strcmp(cmd, "inorder")==0) { // inorder traversal
			printf("Inorder: ");
			inorder(T->root);
			printf("\n");
		} else if(strcmp(cmd, "exit")==0)
			break;
		else
			printf("Not allowed command\n");
	}
	return 0;
}
