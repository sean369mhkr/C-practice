#include "func.h"

void pr_node() {
	Node *go = ptr;
	while (go != NULL) {
		printf("address=%p, ", go); //印出節點的位址 
		printf("data=%d ", go->data); //印出節點的資料 
		printf("next=%p\n", go->next); //印出下一個節點位址 
		go = go->next;  //將ptr指向下一個節點 
	}
}

void add_node() {
	Node *go = ptr;
	Node *a;
	int n_data;
	a = malloc(sizeof(Node));
	printf("Add new Node : ");
	scanf_s("%d", &n_data);

	for (int i = 0; i < num - 1; i++) {
		go = go->next;
	}
	go->next = a;
	a->data = n_data;
	a->next = NULL;
	num++;
}

void insert_node() {
	int val, place;
	Node *go = ptr;
	Node *a,*b;
	a = malloc(sizeof(Node));
	printf("Insert value : ");
	scanf_s("%d", &val);
	printf("Insert place : ");
	scanf_s("%d", &place);
	if (place <= 0) {
		printf("can't be less than 1\n");
	}
	else if (place == 1) {
		a->data = val;
		a->next = ptr;
		ptr = a;
		num++;
	}
	else {
		if (place > num) {
			place = num + 1;
		}
		for (int i = 0; i < place - 2; i++) {
			go = go->next;
		}
		b = go->next;
		go->next = a;
		a->data = val;
		a->next = b;
		num++;
	}
	
}

void delete_node() {
	int place;
	Node *go = ptr;
	Node *b;
	printf("Delete place : ");
	scanf_s("%d", &place);
	if (place <= 0) {
		printf("can't be less than 1\n");
	}
	else if (place == 1) {
		ptr = go->next;
		num--;
	}
	else {
		if (place > num) {
			printf("Null place\n");
		}
		else {
			for (int i = 0; i < place - 2; i++) {
				go = go->next;
			}
			b = go;
			go = go->next;
			b->next = go->next;
			//free(go);
			num--;
		}
	}
}

void search_node() {
	Node *go = ptr;
	int val, place=1, ex=0;
	printf("Search value : ");
	scanf_s("%d", &val);
	while (go != NULL) {
		if (go->data == val) {
			printf("%d is at %d place\n", val, place);
			ex = 1;
			break;
		}
		go = go->next;  //將ptr指向下一個節點 
		place++;
	}
	if (ex == 0) printf("%d doesn't exist\n", val);
}



