#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"librarystructure.h"
#include"bookoperation.h"
#include"studentoperation.h"
#include"recordoperation.h"
#include<stddef.h>

void removerecord(PtrtoRecord remove, PtrtoRecord List) {
	FILE *fp;
	if ((fp = fopen("record.txt", "w")) == NULL) {
		fprintf("stdout", "Can't open the file\n");
		exit(EXIT_FAILURE);
	}
	while (List) {
		if (strcmp(remove->booksname, List->booksname) == 0) {
			List = List->Next;
		}
		else {
			fprintf(fp, "%s  ", List->ID);
			fprintf(fp, "%s  ", List->booksname);
			fprintf(fp, "%s\n", List->author);
			List = List->Next;
		}
	}
	fclose(fp);
}

PtrtoRecord addnewrecord(PtrtoRecord List, char*studentID, char*booksname, char*author) {
	PtrtoRecord temp;
	temp = (PtrtoRecord)malloc(sizeof(struct Record));
	strcpy(temp->ID, studentID);
	strcpy(temp->booksname, booksname);
	strcpy(temp->author, author);
	temp->Next = List;
	return temp;
}

void Updatetherecordfile(PtrtoRecord List) {
	FILE *fp;
	if ((fp = fopen("record.txt", "w")) == NULL) {
		fprintf("stdout", "Can't open the file\n");
		exit(EXIT_FAILURE);
	}

	while (List) {
		fprintf(fp, "%s  ", List->ID);
		fprintf(fp, "%s  ", List->booksname);
		fprintf(fp, "  %s\n", List->author);
		List = List->Next;
	}

	fclose(fp);
}

PtrtoRecord ReadDataRecord(void)
{
	PtrtoRecord head;
	PtrtoRecord rear;
	PtrtoRecord p1;
	head = NULL;


	FILE *fp;
	if ((fp = fopen("record.txt", "r")) == NULL) {
		fprintf(stdout, "Can't open the file.\n");
		exit(EXIT_FAILURE);
	}
	int n = 0;
	char words[30];
	char ID[30];
	char booksname[20];
	rewind(fp);
	while (fscanf(fp, "%s", words) == 1) {
		if (n % 3 == 0) {
			strcpy(ID, words);
			n++;
		}
		else if (n % 3 == 1) {
			strcpy(booksname, words);
			n++;
		}
		else {
			p1 = (PtrtoRecord)malloc(sizeof(struct Record));
			strcpy(p1->author, words);
			strcpy(p1->booksname, booksname);
			strcpy(p1->ID, ID);
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