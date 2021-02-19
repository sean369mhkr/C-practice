#pragma once
#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node *next;
};
typedef struct node Node;
Node *ptr;
void pr_node();
void add_node();
void insert_node();
void delete_node();
void search_node();
int num;
char choose;