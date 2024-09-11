#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
	int data;
	struct Node* next;
} Node;


Node * Head = NULL;
Node * First = NULL;

int addNode(int data){
	Node * current = First;
	if(Head == NULL){
		First = (Node*)malloc(sizeof(Node));
		First->data = data;
		First->next = NULL;
		Head = First;
		//printf("Testi\n");
		return 0;
	}
	else{
		while(1){
			if(current->next==NULL){
				Node* added = (Node*)malloc(sizeof(Node));
				added->data = data;
				added->next = NULL;
				current->next = added;
				return 0;
			}else{
				current = current->next;
			}
		}
		
		
	}
	return 0;	
}
int printList(){
	if(Head == NULL){
		return 1;
	}
	Node * current = First;
	while(current->next != NULL){
		printf("Node: %d\n", current->data);
		current = current->next;
	}
	printf("Node: %d\n", current->data);
	return 0;	
}
int removeNode(int index){
	if(First == NULL){
		puts("List is empty!");
		return 1;
	}
	Node* current = First;

	if(index == 0){
		First = current->next;
		free(current);
		return 0;
	}

	for(int i = 0;i < index - 1;i++){
		if(current->next == NULL){
			printf("Index out of range\n");
			return 1;
		}
			

		current = current->next;
	}
	
	//puts("Moro");
	Node* temp = current->next->next;
	free(current->next);
	current->next = temp;
	return 0;	

}
int destroyList(){
	if(First == NULL){
		return 0;
	}

	Node* next = First->next;
	Node* current = First;
	while(current->next != NULL){
		next = current->next;
		free(current);
		current = next;
	}
	Head = NULL;
	First = NULL;
	free(current);
	return 0;
}

int printNode(int index){
	Node * current = First;
	for(int i = 0; i < index; i++){
		if(current->next != NULL){
			current = current->next;
		}else{
			puts("Index out of range!");
			return 1;
		}
	}
	printf("Value: %d\n", current->data);
	return 0;;
}

int printMenu(){
	printf("1. Add node\n2. Remove Node\n3. Print Node\n4. Print List\n5. Destroy List\n6. Exit\nEnter: ");
	return 0;
}


int main(){
	int choice = 0;
	int num = 0;
	while(choice != 6){
		printMenu();
		scanf(" %d", &choice);

		switch(choice){
			case 1:
				printf("Enter a number to add: ");
				scanf(" %d", &num);
				addNode(num);
				break;
			case 2:
				printf("Enter index to remove: ");
				scanf(" %d", &num);
				removeNode(num);
				break;
			case 3:
				printf("Enter index to print: ");
				scanf(" %d", &num);
				printNode(num);
				break;
			case 4:
				printList();
				break;
			case 5:
				if(destroyList() == 1){
					puts("Destroying list failed!");
					break;
				}else{
					puts("List destroyed succesfully!!");
					break;
				}
			case 6:
				destroyList();
				return 0;
				

		};
	}
	return 0;

	/*Node * Head = NULL;
	addNode(1);	
	addNode(2);	
	addNode(3);
	removeNode(0);
	addNode(4);
	addNode(5);
	printList();
	removeNode(1);
	printf("\n");
	printList();
	destroyList();
	printList();
	removeNode(999);

	puts("");
	addNode(1);
	addNode(2);
	printList();

	printNode(3);

	destroyList();
	destroyList();*/

	return 0;
}
