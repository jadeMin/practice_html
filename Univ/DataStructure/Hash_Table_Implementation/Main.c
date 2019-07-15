#include <stdio.h>
#include <string.h>

#define max_char_per_line	300
#define SIZE	131
#define KEY_LENGTH	20
#define NOTFOUND	-9999

typedef struct node_elm *node;
struct node_elm{
	char key[KEY_LENGTH];
	char isbn[20], title[200], pub[100];
	node next;
};

node H1[SIZE] = {};
node H2[SIZE] = {};
int n1 = 0, n2 = 0;
int collision1 = 0, collision2 = 0;
int r1 = 0, r2 = 0;
//key, hash함수 저장을 어떻게 했는지 - 레포트

node createNode(node key) {
  node v = (node)malloc(sizeof(struct node_elm));
  v = key;
	v->next = NULL;
  return v;
}
node insertAtHead(node head, node key){
	node new_node = createNode(key);
	new_node->next = head;
	return new_node;
}
node search(node v, char* value) {
	if(v == NULL)
		return v;
	while(v){
		if(v->key == value)
			return v;
		v = v->next;
	}
	return NULL;
}
int createHash1(char v[]){
	int i, index;
	for(i=0; i<strlen(v); i++){
		index = v[i] + index * 23;
	}
	return index % SIZE;
}

int createHash2(char v[]){
	int i, index;
	for(i=0; i<strlen(v); i++){
		index += v[i]*7;
	}
	return index % SIZE;
}

int insert_book1(node v){
	int index = createHash1(v->key);
	if(H1[index] == NULL){
		H1[index] = v;
		n1++;
		return index % SIZE;
	}
	if(H1[index] != NULL){
		H1[index] = insertAtHead(H1[index], v);
		n1++;
		collision1++;
		return index;
	}
	return -1;
}
int insert_book2(node v){
	int index = createHash2(v->key);
	if(H2[index] == NULL){
		H2[index] = v;
		n2++;
		return index % SIZE;
	}
	if(H2[index] != NULL){
		H2[index] = insertAtHead(H1[index], v);
		n2++;
		collision2++;
		return index;
	}
	return -1;
}
node find_book1(char key[]){
	int index = createHash1(key);
	return search(H1[index], key);
}

node find_book2(char key[]){
	int index = createHash2(key);
	return search(H2[index], key);
}

int main() {
	int cnt, i;
	float load_factor1, empty_slot_ratio1, collision_ratio1, average_list_length1;
	float load_factor2, empty_slot_ratio2, collision_ratio2, average_list_length2;

	char *token = NULL, line[max_char_per_line];
	char sep[] = "\"\t\n";
	FILE *in = fopen("data\ebook2014.txt","r");

	while(fgets(line, max_char_per_line, in)){
		cnt = 0;
		token = strtok(line, sep);
		node v = createNode(NULL);
		while(token != NULL){
			cnt++;
			printf("token = %s", token);
			putchar('\n');
			switch(cnt){
				case 1 : strcpy(v->key, token); strcpy(v->isbn, token); break;
				case 2 : strcpy(v->title, token); break;
				case 3 : strcpy(v->pub, token); break;
				default :;
			}
			token = strtok(NULL, sep); 
		}
		printf("%s\t%s\t%s\t%s\n", v->key, v->isbn, v->title, v->pub);	

		insert_book1(v);  
		insert_book2(v);
	}

	for(i = 0; i < SIZE; i++){
		if(H1[i] == NULL)
			r1++;
		if(H2[i] == NULL)
			r2++;
	}
	
	load_factor1 = n1 / SIZE;
	empty_slot_ratio1 = r1 / SIZE;
	collision_ratio1 = collision1 / n1;
	average_list_length1 = n1/ (SIZE - r1);

	load_factor2 = n2 / SIZE;
	empty_slot_ratio2 = r2 / SIZE;
	collision_ratio2 = collision2 / n2;
	average_list_length2 = n2 / (SIZE - r2);
	
	printf("load factor for H1 is %f\n", load_factor1);
	printf("empty slot ratio for H1 is %f\n", empty_slot_ratio1 * 100.0);
	printf("collision ration for H1 is %f\n", collision_ratio1 * 100.0);
	printf("average list length for H1 is %f\n", average_list_length1);

	printf("load factor for H2 is %f\n", load_factor2);
	printf("empty slot ratio for H2 is %f\n", empty_slot_ratio2* 100.0);
	printf("collision ration for H2 is %f\n", collision_ratio2 * 100.0);
	printf("average list length for H2 is %f\n", average_list_length2);
	
	return 0;
}

