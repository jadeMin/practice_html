#include<stdio.h>

int G[1000][1000];
int n,m,time=1;
int visited[1000],pre[1000],post[1000];


void DFS(int v){
	int w;
	visited[v] = 1;
	printf("%d ",v);
	pre[v] = time++;
	for(w=0;w<n;w++){
		if(v !=w && G[v][w] == 1 && visited[w] == 0){
			DFS(w);
		}
	}
	post[v] = time++;
}

void print_interval(void){
	int v;
	for(v=0;v<n;v++){
		printf("[%3d, %3d] ", pre[v], post[v]);
	}
	printf("\n");

}
void addEdge(int a, int b){
	G[a][b] = 1;
	G[b][a] = 1;
}
void main(){
	int v, node1, node2;
	scanf("%d %d", &n, &m);
	for(int i=0;i<m;i++){
		scanf("%d %d", &node1, &node2);
		addEdge(node1,node2);
	}
	for(v=0;v<n;v++){
		visited[v]=0;
		pre[v]=post[v]=0;
	}
	for(v=0;v<n;v++){
		if(visited[v]==0)
			DFS(v);
		printf("\n");
	}
	print_interval();
}



