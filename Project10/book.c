#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"librarystructure.h"
#include"bookoperation.h"
#include"studentoperation.h"
#include"recordoperation.h"
#include<stddef.h>

void removebook(PtrtoBook remove, PtrtoBook List) {
	FILE *fp;
	if ((fp = fopen("book.txt", "w")) == NULL) {
		fprintf("stdout", "Can't open the file\n");
		exit(EXIT_FAILURE);
	}
	while (List) {
		if (strcmp(remove->booksname, List->booksname) == 0) {
			List = List->Next;
		}
		else {
			fprintf(fp, "%s  ", List->booksname);
			fprintf(fp, "%s\n", List->author);
			List = List->Next;
		}
	}
	fclose(fp);
}

PtrtoBook addnewbook(PtrtoBook List, char *booksname, char *author) {
	PtrtoBook temp;
	temp = (PtrtoBook)malloc(sizeof(struct Book));
	strcpy(temp->booksname, booksname);
	strcpy(temp->author, author);
	temp->Next = List;
	return temp;
}

void Updatethebookfile(PtrtoBook List) {
	FILE *fp;
	if ((fp = fopen("book.txt", "w")) == NULL) {
		fprintf("stdout", "Can't open the file\n");
		exit(EXIT_FAILURE);
	}

	while (List) {
		fprintf(fp, "%s  ", List->booksname);
		fprintf(fp, "%s\n", List->author);
		List = List->Next;
	}

	fclose(fp);
}

PtrtoBook ReadDataBook(void) {
	PtrtoBook head;
	PtrtoBook rear;
	PtrtoBook p1;
	head = NULL;


	FILE *fp;
	if ((fp = fopen("book.txt", "r")) == NULL) {
		fprintf(stdout, "Can't open the file.\n");
		exit(EXIT_FAILURE);
	}
	int n = 0;
	char words[30];
	char booksname[30];
	rewind(fp);
	while (fscanf(fp, "%s", words) == 1) {
		if (n % 2 == 0) {
			strcpy(booksname, words);
			n++;
		}
		else {
			p1 = (PtrtoBook)malloc(sizeof(struct Book));
			strcpy(p1->author, words);
			strcpy(p1->booksname, booksname);
			n++;
			if (head == NULL) {
				head = p1;
				rear = p1;
			}
			else {
				rear->Next = p1;
				rear = p1;
			}
			rear->Next = NULL;
		}
	}

	return head;
	fclose(fp);
}