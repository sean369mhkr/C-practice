#include "func.h"
#include <string.h>
int main(int argc, char *argv[])
{
	
	int val;
	printf("number of node: ");
	scanf_s("%d",&num);
	ptr = malloc(num * sizeof(Node));
	if (ptr == NULL) {
		// 無法取得記憶體空間
		fprintf(stderr, "Error: unable to allocate required memory\n");
		return 1;
	}

	for (int i = 0; i < num; i++) {
		printf("node %d value:", i+1);
		scanf_s("%d", &val);
		ptr[i].data = val;
		if (i == num - 1)
			ptr[i].next = NULL;
		else
			ptr[i].next = &ptr[i + 1];
	}
	setvbuf(stdin, NULL, _IOFBF, 512);
	while (1) {
		printf("a:add node  d:delete node  i:insert node  p:print node  s:search node  z:exit\n");
		choose=getchar();
		choose=tolower(choose);
		if (choose == 122) break;
		switch (choose) {
		case 'a':
			add_node();
			break;
		case 'd':
			delete_node();
			break;
		case 'i':
			insert_node();
			break;
		case 'p':
			pr_node();
			break;
		case 's':
			search_node();
			break;
		default:
			printf("wrong input\n");
			break;
		}
		setvbuf(stdin, NULL,_IOFBF, 512);
	}
	
	printf("number of node : %d\n", num);
	//system("PAUSE");
	return 0;
}



