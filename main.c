#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE  100

typedef struct ContactList {
	char name[20];
	char number[20];	
	char email[30];
	void *next;
} list;

list *head = NULL;

int printMenu() {
	printf("\n\n\n\n*****************MAIN MENU*********************\n\n\n\n");
	printf("Options\n");

	printf("1: Add Contact\n");
	printf("2: Remove Contact\n");
	printf("3: See all Contacts\n");
	printf("4: Quit\n");
	int opt; 
	scanf("%d", &opt);
	return opt;
}

list *add() {

	char name[20]; 
	char number[20]; 
	char email[30]; 
	
	list *current = head;
	list *new = malloc(sizeof(list));
	printf("Name:");
	scanf("%s", name);
	printf("\n");
	printf("Phone Number:");
	scanf("%s", number);
	printf("\n");
	printf("Email:");
	scanf("%s", email);
	printf("\n");

	if(head == NULL) {
		memmove(new->name, name, 20);
		memmove(new->number, number, 20);
		memmove(new->email, email, 30);
		head = new;	
		new->next = NULL;
	}
	else {
		memmove(new->name, name, 20);
		memmove(new->number, number, 20);
		memmove(new->email, email, 30);
		new->next = head; 
		head = new;
	}
	return new;
}

void printList() {

	list *current = head;
	int count = 1;
	while(current != NULL)  {
		printf("%d\n", count);
		printf("\n\n\nName %s \nPhone Number %s \nEmail %s \n\n\n", current->name, current->number, current->email);
		current = current->next;
		count++;

	}



}
int removeContact() {
	list *current = head;
	list *prev = head;
	char name[20];	
	printf("Name to Remove\n");
	scanf("%s", name);
	while(current != NULL) {
		printf(".%s. : .%s.\n", current->name, name);
		if(!strcmp(current->name,  name )) {
			printf("REMOVING\n");
			if(current == head) {
				head = current->next; 
				return 0; 
			}
			prev->next = current->next;

			free(current->name);
			free(current->email);
			free(current->number);

			free(current);
			current = NULL;
		}
		prev = current; 
		current = current->next;
	}

	return 0;
}
int main(void) {
	int opt; 	
	while (1) {
		opt = printMenu();

		if(opt == 1) {
			list *new = add();
			printList();
		}
		if(opt == 2) {
			removeContact();

			printList();
		}
		if(opt == 3) {
			printList();
		}

		if(opt == 4)  {
			return 0;
		}
	}
		
	


}
