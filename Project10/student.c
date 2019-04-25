#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"librarystructure.h"
#include"bookoperation.h"
#include"studentoperation.h"
#include"recordoperation.h"
#include<stddef.h>

PtrtoStudents addnewstudent(PtrtoStudents List, char*studentID, char*studentname) {
	PtrtoStudents temp;
	temp = (PtrtoStudents)malloc(sizeof(struct Students));
	strcpy(temp->studentID, studentID);
	strcpy(temp->studentname, studentname);
	temp->Next = List;
	return temp;
}

void Updatethestudentfile(PtrtoStudents List) {
	FILE *fp;
	if ((fp = fopen("student.txt", "w")) == NULL) {
		fprintf("stdout", "Can't open the file\n");
		exit(EXIT_FAILURE);
	}

	while (List) {
		fprintf(fp, "%s  ", List->studentID);
		fprintf(fp, "%s\n", List->studentname);
		List = List->Next;
	}

	fclose(fp);
}

PtrtoStudents ReadDataStudents(void) {
	PtrtoStudents head;
	PtrtoStudents rear;
	PtrtoStudents p1;
	head = NULL;


	FILE *fp;
	if ((fp = fopen("student.txt", "r")) == NULL) {
		fprintf(stdout, "Can't open the file.\n");
		exit(EXIT_FAILURE);
	}
	int n = 0;
	char words[30];
	char studentID[20];
	rewind(fp);
	while (fscanf(fp, "%s", words) == 1) {
		if (n % 2 == 0) {
			strcpy(studentID, words);
			n++;
		}
		else {
			p1 = (PtrtoStudents)malloc(sizeof(struct Students));
			strcpy(p1->studentname, words);
			strcpy(p1->studentID, studentID);
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
	fclose(fp);
	return head;

}

