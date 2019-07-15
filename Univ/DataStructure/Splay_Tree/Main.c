#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct treenode* node;
typedef struct Tree* tree;
struct treenode{
	int key;
	node left,right,parent;
};
struct Tree{
	node root;
	int size;
};

tree createTree(){
	tree T=(tree)malloc(sizeof(struct Tree));
	T->root=NULL;
	T->size=0;
	return T;
}
node createNode(int key){
	node v=(node)malloc(sizeof(struct treenode));
	v->parent=v->right=v->left=NULL;
	v->key=key;
	return v;
}
void inorder(node v){
	if(v!=NULL){
		inorder(v->left);
		printf("%d -> ", v->key);
		inorder(v->right);	
	}
}
void preorder(node v){
	if(v!=NULL){
		printf("%d -> ", v->key);
		preorder(v->left);
		preorder(v->right);	
	}
}

void leftrotate(node x){
	if(x->parent==NULL) return;
	node p=x->parent,l=x->left, g=p->parent;
	//l-p relation
	p->right=l; if(l) l->parent=p; 
	//p-x relation
	x->left=p; p->parent=x;
	//x-g relation
	if(g){
		if(g->right==p) g->right=x;
		else g->left=x;
	}
	x->parent=g;

}


void rightrotate(node x){
	if(x->parent==NULL) return;
	node p=x->parent,l=x->right, g=p->parent;
	//l-p relation
	p->left=l; if(l) l->parent=p; 
	//p-x relation
	x->right=p; p->parent=x;
	//x-g relation
	if(g){
		if(g->right==p) g->right=x;
		else g->left=x;
	}
	x->parent=g;
}

node splay(node x){
	if(x==NULL) return NULL;
	node p;
	while(x->parent!=NULL){
		p= x->parent;
		if(p->left == x) rightrotate(x);
		else if(p->right == x) leftrotate(x);
	}
	return x;	
}
void insert( tree t, int key ) {
	node v, p = t->root, parent = NULL;
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
		t-> root = v;
	else if(key <=parent -> key)
		parent->left = v;
	else
		parent->right = v;
	v->parent = parent;
	t->size++;
	t->root = splay(v);
}

node search(tree t,int key) {
	node p = t->root;
	node x = NULL;
	while(p!=NULL){
		if(p->key > key)
			p = p->left;
		else if(p->key < key)
			p = p->right;
		else{
			t->root = splay(p);
			return p;
		}
	}
	return NULL;
}

void deleteNode(tree t,node x){
	node L, R, m;
	t->root = splay(x);
	L = x->left, R = x->right;
	free(x);
	if(L){
		L->parent = NULL;
		m = L;
		while(m->right) m = m->right;
		t->root = splay(m);
		m->right = R;
		if(R)
			R->parent = m;
	}
	else{
		t->root = R;
		if(R) R->parent = NULL;
	}
}


int main(void) {
    int value;
    char cmd[20];
    node v;
    tree T = createTree();
    while(1) {
	scanf("%s", cmd);
	if(strcmp(cmd, "in")==0) { // insert at tree
		scanf("%d", &value);
		insert(T, value);
		printf("inorder:\n"); inorder(T->root);printf("\n");
		printf("preorder:\n"); preorder(T->root);printf("\n");
	} else if(strcmp(cmd, "find")==0) { // search
		scanf("%d", &value);
		v = search(T, value);
		if(v != NULL) printf("%d is found!\n", v->key);
		else printf("Not found!\n");
		printf("inorder:\n"); inorder(T->root);printf("\n");
		printf("preorder:\n"); preorder(T->root);printf("\n");
	} else if(strcmp(cmd, "del")==0) {
		scanf("%d", &value);
		v = search(T, value);
		if(v != NULL) {
			printf("%d is deleted.\n", value);
			deleteNode(T, v);
			printf("inorder:\n"); inorder(T->root); printf("\n");
			printf("preorder:\n"); preorder(T->root); printf("\n"); 
		}
	} else if(strcmp(cmd, "inorder")==0) { 
		printf("Inorder: \n");
		inorder(T->root);
		printf("\n");
	} else if(strcmp(cmd, "exit")==0) {
		break;
	} else
		printf("Not allowed command\n");
    }
    return 0;
}