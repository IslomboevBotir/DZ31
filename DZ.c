#include<stdio.h>
#include<stdlib.h>
struct list{
	int key;
	int value;
	struct list *next;	
};

struct list *add_element(struct list *head, int val, int key){
	if (head == NULL){
		head = (struct list *)malloc(sizeof(struct list));
		head->key = key;
		head->value = val;
		head->next = NULL;
	}	
	else{
		head->next = add_element(head->next, val, key);
	}
	return head;
}

struct list *delete_element(struct list *head, int key){
	int k=0;
	if (head == NULL){
		return head;
	}
	if (head->key == key){
		if(head->next == NULL){
			head = NULL;
			return head;
		}
		else{
			head = head->next;
			k=1;
		}
	}
	if (k == 1){
		head = delete_element(head, key);
	}
	else{
		head->next = delete_element(head->next, key);
	}
	return head;
}

void show(struct list *head){
	while(head != NULL){
		printf("%d) ", head->key);
		printf("%d\n", head->value);
		head = head->next;
	}	
}

int main(void){
	int act = 0;
	int key = 0;
	struct list *head;
	head = NULL;
	int val;
	printf("+------+\n");
	printf("|Action|\n");
	printf("+------+\n");
	printf("|1|Add element|\n");
	printf("+------+\n");
	printf("|2|Deleteelement|\n");
	printf("+------+\n");
	printf("|3|Show list|\n");	
	printf("+------+\n");
	printf("|4|Exit program|\n");
	printf("+------+\n");
	while(act != 4){
		printf("Choose an action: ");
		scanf("%d", &act);
		switch(act){
			case 1:
				printf("New file: ");
				scanf("%d", &val);
				++key;
				head = add_element(head, val, key);	
			break;
			case 2:
				printf("File\'s key: ");
				scanf("%d", &val);
				head = delete_element(head, val);	
			break;
			case 3:
				show(head);	
			break;
			case 4:
				exit(0);
			break;
			default:
				printf("Unknown!\n");	
		}
	}
	return 0;
}
