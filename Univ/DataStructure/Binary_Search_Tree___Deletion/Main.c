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
	node v = (node)malloc(sizeof(struct treenode));
	v->key=key;
	v->left = v->right = v->parent = NULL;
	return v;
}

tree createBinaryTree(void) {
	tree T = (tree)malloc(sizeof(struct btree));
	T->root = NULL;
	T->size = 0;
	return T;
}

void inorder(node v) {
   if (v != NULL) {
      inorder(v->left);
      printf("%d -> ", v->key);
      inorder(v->right);
   }
}

node search(tree T, int key) {
   node v = T->root;
   while(v != NULL){
      if(v->key > key)
         v = v->left;
      else if(v->key < key)
         v = v->right;
      else if(v->key == key)
         return v;
   }
   return NULL;
}

void insert( tree T, int key ) {
   node v, p = T->root, parent = NULL;
   while(p != NULL){
      parent = p;
      if(p->key > key)
         p = p->left;
      else if(p->key < key)
         p = p-> right;
      else
         return;
   }
   v = createNode(key);
   if(T->root ==NULL){
      T->root = v;
   }
   else if(parent->key> key)
      parent->left = v;
   else
      parent->right = v;
   v->parent = parent;
   
   T->size++;
}

void deleteByMerging(tree T, node x){
   if(T->root == NULL || x == NULL)
      return;
   node a, b, c, m, pt;
   a = x->left;
   b = x->right;
   pt = x->parent;
   if(a == NULL)
      c = b;
   else{
      c = m = a;
      while(m->right != NULL)
         m = m->right;
      m->right = b;
      if(b != NULL)
         b->parent = m;
   }
   if(T->root == x){
      if(c != NULL)
         c->parent = NULL;
      T->root = c;
   }
   else{
         if(pt->right == x)
            pt->right = c;
         else
         pt->left = c;
      if(c != NULL)
         c->parent = pt;
   }
   free(x);
   T->size--;
}
void deleteByCopying(tree T, node x){
   node a, b, m, mp, p;
   a = x->left;
   b = x->right;
   if(T->root == NULL || x == NULL)
      return;
	if(a != NULL){
      m = a;
      while(m->right != NULL)
         m = m->right;
      p = m->left;
      mp = m->parent;
      if(mp != x)
         mp->right = p;
      else
         mp->left = p;
   }
	else{
		if(b == NULL){
			 m = x;
			 mp = m->parent;
			if(mp)
				if(m == mp->left) mp->left = NULL;
			else
				mp->right = NULL;
		 }
		 else{
      	m = b;
      	while(m->left != NULL)
      	   m = m->left;
      	p = m->right;
      	mp = m->parent;
      	if(mp != x)
      	   mp->left = p;
      	else
      	   mp->right = p;
		 }
   }
   if(p != NULL)
      p->parent = mp;

   x->key = m->key;
   free(m);
   T->size--;
}
int main(void) {
    int value;
    char cmd[20];
    node v;
    tree T = createBinaryTree();
    while(1) {
   scanf("%s", cmd);
   if(strcmp(cmd, "insert")==0) { // insert at tree
      scanf("%d", &value);
      insert(T, value);
      printf("%d is inserted.\n", value);
      inorder(T->root);
   } else if(strcmp(cmd, "search")==0) { // search
      scanf("%d", &value);
      v = search(T, value);
      if(v != NULL) printf("%d is found!\n", v->key);
      else printf("Not found!\n");
   } else if(strcmp(cmd, "deleteM")==0) { // deleteByMerging
      scanf("%d", &value);
      v = search(T, value);
      if(v != NULL) {
         printf("%d is deleted by merging.\n", value);
         deleteByMerging(T, v);
         inorder(T->root);
      }
   } else if(strcmp(cmd, "deleteC")==0) { // deleteByCopying
      scanf("%d", &value);
      v = search(T, value);
      if(v != NULL) {
         printf("%d is deleted by copying.\n", value);
         deleteByCopying(T, v);
         inorder(T->root);
      }
   } else if(strcmp(cmd, "inorder")==0) { // inorder traversal
      printf("Inorder: \n");
      inorder(T->root);
      printf("\n");
   } else if(strcmp(cmd, "exit")==0)
      break;
   else
      printf("Not allowed command\n");
    }
    return 0;
}