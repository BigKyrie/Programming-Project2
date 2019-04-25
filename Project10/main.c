#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"librarystructure.h"
#include"bookoperation.h"
#include"studentoperation.h"
#include"recordoperation.h"
#include<stddef.h>

void clear(void) {
	int ch;
	while ((ch = getchar()) != EOF && ch != '\n')
	{
		continue;
	}
}

int main()
{

	printf("Choose if you are a librarian or a student(Enter the number)\n");
	printf("1.Librarian\n");
	printf("2.student\n");
	int choose1;
	int choose2;
	while (1) {
		scanf_s("%d", &choose1);
		clear();
		if (choose1 != 1 && choose1 != 2) {
			puts("Please enter the integer number 1 or 2");
		}
		else {
			break;
		}
	}
	if (choose1 == 1) {
		printf("Please enter the password of the librarian\n");     /*The librarian should enter the password:wei123*/
		char password_1[10];
		while (1) {
			gets(password_1);
			if (strcmp(password_1, "wei123") == 0) {
				break;
			}
			else {
				puts("The password is incorrect, please try one more time");
			}
		}
		while (1) {
			puts("Enter the function you want:(Enter the integer between the 1 to 5)\n");
			puts("1.list all books");
			puts("2.list all users");
			puts("3.add new books");
			puts("4.remove exsit books");
			puts("5.check the student's borrowing record");
			while (1) {
				scanf("%d", &choose2);
				clear();
				if (choose2 != 1 && choose2 != 2 && choose2 != 3 && choose2 != 4&&choose2!=5) {
					puts("Please enter the number between the integer number between 1 to 5");
				}
				else {
					break;
				}
			}
				
			if (choose2 == 1) {
				int choose;
				PtrtoBook head1;
				head1 = ReadDataBook();
				int countb=0;
				while (head1) {
					if (countb == 0) {
						printf("Booksname   ");
						printf("Author\n\n");
						countb++;
					}
					printf("%s  ", head1->booksname);
					printf("%s\n", head1->author);
					head1 = head1->Next;
				}
				puts("Then you want to:(Please enter the integer)");
				puts("1.Back to the librarian main menu");
				puts("2.Leave the System");
				while (1) {
					
					scanf("%d", &choose);
					clear();
					if (choose != 1 && choose != 2) {
						puts("Please enter the integer 1 or 2");
					}
					else {
						break;
					}
				}
				if (choose == 1) {
					continue;
				}
				else {
					break;
				}
			}

			if (choose2 == 2) {
				int choose;
				PtrtoStudents head2;
				head2 = ReadDataStudents();
				int counts=0;
				while (head2) {
					if (counts == 0) {
						printf("StudentID  ");
						printf("Studentname\n\n");
						counts++;
					}
					printf("%s  ", head2->studentID);
					printf("%s\n", head2->studentname);
					head2 = head2->Next;
				}
				puts("Then you want to:(Please enter the integer)");
				puts("1.Back to the librarian main menu");
				puts("2.Leave the System");
				while (1) {

					scanf("%d", &choose);
					clear();
					if (choose != 1 && choose != 2) {
						puts("Please enter the integer 1 or 2");
					}
					else {
						break;
					}
				}
				if (choose == 1) {
					continue;
				}
				else {
					break;
				}
			}

			if (choose2 == 3) {
				int choose;
				while (1) {
					int choose1;
					PtrtoBook head1;
					PtrtoBook head2;
					head1 = ReadDataBook();
					char booksname[30];
					char author[20];
					puts("Please enter the booksname(the book's name should be a word with no space,eg.DataStructure):");
					gets(booksname);
					puts("Please enter the author(also only a word with no space,eg.Mark):");
					gets(author);
					head2 = addnewbook(head1, booksname, author);
					Updatethebookfile(head2);
					puts("Successfully add this book!");
					puts("Still have a book to add?(Please enter the integer number please)");
					puts("1.Yes");
					puts("2.No");
					while (1) {
						scanf("%d", &choose1);
						clear();
						if (choose1 != 1 && choose1 != 2) {
							puts("Please enter the integer number 1 or 2");
						}
						else {
							break;
						}
					}
					if (choose1 == 1) {
						continue;
					}
					else {
						break;
					}
				}
				puts("Then you want to:(Please enter the integer)");
				puts("1.Back to the librarian main menu");
				puts("2.Leave the System");
				while (1) {

					scanf("%d", &choose);
					clear();
					if (choose != 1 && choose != 2) {
						puts("Please enter the integer 1 or 2");
					}
					else {
						break;
					}
				}
				if (choose == 1) {
					continue;
				}
				else {
					break;
				}
			}

			if (choose2 == 4) {
				int choose;
				while (1) {
					PtrtoBook head1;
					head1 = ReadDataBook();
					int count_4=0;
					while (head1) {
						if (count_4 == 0) {
							printf("Booksname      ");
							printf("Author\n");
							count_4++;
						}
						printf("%s  ", head1->booksname);
						printf("%s\n", head1->author);
						head1 = head1->Next;
					}
					PtrtoBook head2;
					head2 = ReadDataBook();
					char booksname[30];
					puts("Please enter the book's name that you want to remove");
					gets(booksname);
					while (strcmp(booksname,head2->booksname)!=0) {
						head2 = head2->Next;
						if (head2 == NULL) {
							puts("This book is not existing");
							break;
						}
					}
					if (head2 == NULL) {
						break;
					}
					else {
						PtrtoBook head3;
						head3 = ReadDataBook();
						removebook(head2, head3);
						puts("Successfully remove this book!");
					}
					puts("Still have a book to remove?(Please enter the integer number please)");
					puts("1.Yes");
					puts("2.No");
					while (1) {
						scanf("%d", &choose1);
						clear();
						if (choose1 != 1 && choose1 != 2) {
							puts("Please enter the integer number 1 or 2");
						}
						else {
							break;
						}
					}
					if (choose1 == 1) {
						continue;
					}
					else {
						break;
					}
				}
				puts("Then you want to:(Please enter the integer)");
				puts("1.Back to the librarian main menu");
				puts("2.Leave the System");
				while (1) {

					scanf("%d", &choose);
					clear();
					if (choose != 1 && choose != 2) {
						puts("Please enter the integer 1 or 2");
					}
					else {
						break;
					}
				}
				if (choose == 1) {
					continue;
				}
				else {
					break;
				}
			}

			if (choose2 == 5) {
				int choose;
				PtrtoRecord head_1;
				head_1 = ReadDataRecord();
				int count_5 = 0;
				while (head_1) {
					if (count_5 == 0) {
						printf("Student's ID  ");
						printf("Booksname  ");
						printf("Author\n\n");
						count_5++;
					}
					printf("%s  ", head_1->ID);
					printf("%s  ", head_1->booksname);
					printf("%s\n", head_1->author);
					head_1 = head_1->Next;
				}
				puts("Then you want to:(Please enter the integer)");
				puts("1.Back to the librarian main menu");
				puts("2.Leave the System");
				while (1) {

					scanf("%d", &choose);
					clear();
					if (choose != 1 && choose != 2) {
						puts("Please enter the integer 1 or 2");
					}
					else {
						break;
					}
				}
				if (choose == 1) {
					continue;
				}
				else {
					break;
				}
			}
		}
	
	}
	else if (choose1 == 2) {
		puts("You are:(enter the number please)");
		puts("1.I'm a registerd user(already have an account)");
		puts("2.I want to register an new account(first time use the system)");
		int choose3;
		while (1) {
			scanf_s("%d", &choose3);
			clear();
			if (choose3 != 1 && choose3 != 2) {
				puts("You should enter a integer number between 1 to 2");
			}
			else {
				break;
			}
		}
		if (choose3 == 1) {
			PtrtoStudents head_1;
			head_1 = ReadDataStudents();
			puts("Please enter your student ID and your name to get into the system");
			puts("Enter the student ID first(Only one chance to enter,take care)");
			char student_ID[30];
			gets(student_ID);
			puts("Enter your name(also one chance,name should be one word with no space, eg.Mike)");
			char studentname[30];
			gets(studentname);
			while (head_1) {
				if (strcmp(head_1->studentID, student_ID) == 0 && strcmp(head_1->studentname, studentname) == 0) {
					break;
				}
				head_1 = head_1->Next;
			}
			if (head_1 == NULL) {
				puts("Can't find this account,Please re-enter the system");
				return 0;
			}
			else {
				while (1) {
					int choose;
					puts("Successfully get into the system!");
					puts("Enter the function you want:");
					puts("1.list all books");
					puts("2.search for a book");
					puts("3.borrow a book");
					puts("4.return a book");
					int c;
					while (1) {
						scanf("%d", &c);
						clear();
						if (c != 1 && c != 2 && c != 3&&c!=4) {
							puts("Please enter a integer 1 to 3");
						}
						else {
							break;
						}
					}
					if (c == 1) {
						PtrtoBook head;
						head = ReadDataBook();
						int countsb_1 = 0;
						while (head) {
							if (countsb_1 == 0) {
								printf("Booksname  ");
								printf("Author\n\n");
								countsb_1++;
							}
							printf("%s   ", head->booksname);
							printf("%s\n", head->author);
							head = head->Next;
						}
						puts("Then you want to:(Please enter the integer)");
						puts("1.Back to the student main menu");
						puts("2.Leave the System");
						while (1) {

							scanf("%d", &choose);
							clear();
							if (choose != 1 && choose != 2) {
								puts("Please enter the integer 1 or 2");
							}
							else {
								break;
							}
						}
						if (choose == 1) {
							continue;
						}
						else {
							break;
						}
					}
					else if (c == 2) {
						puts("Enter the books'name you want to search(book's name should be one word with no space. eg.DataStructure)");
						char name[30];
						gets(name);
						PtrtoBook head;
						head = ReadDataBook();
						while (head) {
							if (strcmp(head->booksname, name) == 0) {
								break;
							}
							head = head->Next;
						}
						if (head == NULL) {
							puts("Don't have this book");
						}
						else {
							printf("We have found this book, it's author is %s\n", head->author);
						}
						puts("Then you want to:(Please enter the integer)");
						puts("1.Back to the student main menu");
						puts("2.Leave the System");
						while (1) {

							scanf("%d", &choose);
							clear();
							if (choose != 1 && choose != 2) {
								puts("Please enter the integer 1 or 2");
							}
							else {
								break;
							}
						}
						if (choose == 1) {
							continue;
						}
						else {
							break;
						}
					}
					else if (c == 3) {
						PtrtoBook head1;
						PtrtoBook head2;
						PtrtoBook head5;
						PtrtoRecord head3;
						PtrtoRecord head4;
						head5 = ReadDataBook();
						head2 = ReadDataBook();
						head1 = ReadDataBook();
						int count = 1;
						while (head1) {
							if (count == 1) {
								printf("Booksname     Author\n\n");
								count++;
							}
							printf("%s   ", head1->booksname);
							printf("%s\n", head1->author);
							head1 = head1->Next;
						}
						puts("Enter the book's name you want to borrow(book's name should be one word without any space), eg.DataStructure");
						char booksname[30];
						gets(booksname);
						while (head2) {
							if (strcmp(head2->booksname, booksname) == 0) {
								break;
							}
							head2 = head2->Next;
						}
						if (head2 == NULL) {
							puts("Sorry we don't have this book");
							continue;
						}
						else {
							removebook(head2, head5);
							head3 = ReadDataRecord();
							head4 = addnewrecord(head3, student_ID, head2->booksname,head2->author);
							Updatetherecordfile(head4);
							puts("You have successfully borrow this book,please return it on time!");
						}
						puts("Then you want to:(Please enter the integer)");
						puts("1.Back to the student main menu");
						puts("2.Leave the System");
						while (1) {

							scanf("%d", &choose);
							clear();
							if (choose != 1 && choose != 2) {
								puts("Please enter the integer 1 or 2");
							}
							else {
								break;
							}
						}
						if (choose == 1) {
							continue;
						}
						else {
							break;
						}
					}
                    
					else if (c == 4) {
						puts("Please enter the book's name you want to return(only one chance to enter,take care.The name should be a word without any space");
						char returnbook[30];
						gets(returnbook);
						PtrtoRecord head_1;
						head_1 = ReadDataRecord();
						while (head_1) {
							if (strcmp(head_1->booksname, returnbook) == 0 && strcmp(head_1->ID, student_ID)==0) {
								break;
							}
							head_1 = head_1->Next;
						}
						if (head_1 == NULL) {
							puts("You haven't borrow this book! You can't return it");
							continue;
						}
						else {
							PtrtoRecord head_2;
							PtrtoBook head_3;
							PtrtoBook head_4;
							head_4 = ReadDataBook();
							head_2 = ReadDataRecord();
							removerecord(head_1, head_2);
							head_3 = addnewbook(head_4, head_1->booksname, head_1->author);
							Updatethebookfile(head_3);
							puts("You've successfully return this book!");
						}
						puts("Then you want to:(Please enter the integer)");
						puts("1.Back to the student main menu");
						puts("2.Leave the System");
						while (1) {

							scanf("%d", &choose);
							clear();
							if (choose != 1 && choose != 2) {
								puts("Please enter the integer 1 or 2");
							}
							else {
								break;
							}
						}
						if (choose == 1) {
							continue;
						}
						else {
							break;
						}
					}
				}
			}

		}
		else if (choose3 == 2) {
			PtrtoStudents head_s;
			head_s = ReadDataStudents();
			puts("Please enter your studentID first");
			char studentID_1[20];
			gets(studentID_1);
			puts("Then enter your name please(The name should be a word without any space,eg.Mike)");
			char studentname_1[20];
			gets(studentname_1);
			while (head_s != NULL) {
				if (strcmp(head_s->studentID, studentID_1) == 0) {
					puts("This acount is already exits, to make sure for the security, please re-enter the system.");
					return 0;
				}
				head_s = head_s->Next;
			}
			PtrtoStudents head1;
			PtrtoStudents head2;
			head1 = ReadDataStudents();
			head2 = addnewstudent(head1, studentID_1, studentname_1);
			Updatethestudentfile(head2);
			while (1) {
				int choose;
				puts("Enter the function you want:");        /*New user will not have a possibility to return book*/
				puts("1.list all books");
				puts("2.search for a book");
				puts("3.borrow a book");
				int c;
				while (1) {
					scanf("%d", &c);
					clear();
					if (c != 1 && c != 2 && c != 3) {
						puts("Please enter a integer 1 to 3");
					}
					else {
						break;
					}
				}
				if (c == 1) {
					PtrtoBook head;
					head = ReadDataBook();
					int countsb_2 = 0;
					while (head) {
						if (countsb_2 == 0) {
							printf("Booksname    Author\n\n");
							countsb_2++;
						}
						printf("%s   ", head->booksname);
						printf("%s\n", head->author);
						head = head->Next;
					}
					puts("Then you want to:(Please enter the integer)");
					puts("1.Back to the student main menu");
					puts("2.Leave the System");
					while (1) {

						scanf("%d", &choose);
						clear();
						if (choose != 1 && choose != 2) {
							puts("Please enter the integer 1 or 2");
						}
						else {
							break;
						}
					}
					if (choose == 1) {
						continue;
					}
					else {
						break;
					}
				}
				else if (c == 2) {
					puts("Enter the books'name you want to search(The book's name should be a word without any space, eg.DataStructure)");
					char name[30];
					gets(name);
					PtrtoBook head;
					head = ReadDataBook();
					while (head) {
						if (strcmp(head->booksname, name) == 0) {
							break;
						}
						head = head->Next;
					}
					if (head == NULL) {
						puts("Don't have this book");
					}
					else {
						printf("We have found this book, it's author is %s\n", head->author);
					}
					puts("Then you want to:(Please enter the integer)");
					puts("1.Back to the student main menu");
					puts("2.Leave the System");
					while (1) {

						scanf("%d", &choose);
						clear();
						if (choose != 1 && choose != 2) {
							puts("Please enter the integer 1 or 2");
						}
						else {
							break;
						}
					}
					if (choose == 1) {
						continue;
					}
					else {
						break;
					}
				}
				else if (c == 3) {
					PtrtoBook head1;
					PtrtoBook head2;
					PtrtoBook head5;
					PtrtoRecord head3;
					PtrtoRecord head4;
					head5 = ReadDataBook();
					head2 = ReadDataBook();
					head1 = ReadDataBook();
					int count = 1;
					while (head1) {
						if (count == 1) {
							printf("Booksname     Author\n\n");
							count++;
						}
						printf("%s   ", head1->booksname);
						printf("%s\n", head1->author);
						head1 = head1->Next;
					}
					puts("Enter the book's name you want to borrow");
					char booksname[30];
					gets(booksname);
					while (head2) {
						if (strcmp(head2->booksname, booksname) == 0) {
							break;
						}
						head2 = head2->Next;
					}
					if (head2 == NULL) {
						puts("Sorry we don't have this book");
					}
					else {
						removebook(head2, head5);
						head3 = ReadDataRecord();
						head4 = addnewrecord(head3, studentID_1, head2->booksname, head2->author);
						Updatetherecordfile(head4);
						puts("You have successfully borrow this book,please return it on time!");
					}
					puts("Then you want to:(Please enter the integer)");
					puts("1.Back to the student main menu");
					puts("2.Leave the System");
					while (1) {

						scanf("%d", &choose);
						clear();
						if (choose != 1 && choose != 2) {
							puts("Please enter the integer 1 or 2");
						}
						else {
							break;
						}
					}
					if (choose == 1) {
						continue;
					}
					else {
						break;
					}
				}
			}

		}

	}




	return 0;
}