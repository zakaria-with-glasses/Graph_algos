#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int data;
	struct Node* next;
} Node;

void print_list(Node* head){
	Node* curr = head;
	
	while(curr){
		printf("%d->", curr->data);
		curr = curr->next;
	}
	printf("\n");
}

Node* insert_end(Node* head, int data){
	Node* new = (Node*)malloc(sizeof(Node*));
	if(new == NULL){
		printf("Couldn't Allocate Mem...!");
		exit(1);
	}
	new->data = data;
	Node* curr = head;
	while(curr->next) curr = curr->next;
	curr->next = new;

	return new;
}


Node* delete_pos(int pos); // will be leaving this one empty for now since we don't need it
		

int main(){
	int v;
	printf("Enter the number of vertices in your graph:");
	scanf("%d", &v);
	// after scanning we want to initiat a list that can hold exactly v addresses that are the individual heads of each
	// linked list.
	// let's cross fingers for this one :)
	
	Node** adj_list = (Node**)malloc((sizeof(Node**)) * v);
	if(adj_list == NULL){
		printf("Couldn't Allocate Mem...!");
		return 1;
	}
	
	for(size_t k =0; k<v; k++){
		Node* a = (Node* )malloc(sizeof(Node*));
		if(a == NULL){
			printf("Couldn't Allocate Mem...!");
			return 1;
		}
		a->data = k+1;
		adj_list[k] = a;
	}
	while(true){

		int a,b;
		printf("Enter and edge in the graph from node 0 to node %d: ", v-1);
		scanf("%d %d", &a, &b);

		if (a < 0 || b < 0 || b > v-1 || a > v-1 ) break;
		// we want to do something similar, when the user imputs the graph nodes. essentially we want something like this
		// a+1 -> b+1 , this to be pushed in the dedicated element which will be at position [a] of the list
		// let's cross fingers again for this one
		//
		// inspired from: https://stackoverflow.com/questions/45427322/convert-ascii-code-to-string-in-c
		insert_end(adj_list[a], b+1);// first iteration SIGSEV???? why
		insert_end(adj_list[b], a+1);
	}

	for(size_t i=0; i<v; i++){
		print_list(adj_list[i]);
	}
	return 0;
}
