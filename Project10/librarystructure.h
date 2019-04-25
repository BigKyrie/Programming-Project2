typedef struct Book *PtrtoBook;
typedef struct Students *PtrtoStudents;
typedef struct Record *PtrtoRecord;


struct Book {
	char booksname[30];
	char author[20];
	PtrtoBook Next;
};

struct Students {
	char studentname[20];
	char studentID[20];
	PtrtoStudents Next;
};

struct Record {
	char ID[20];
	char booksname[30];
	char author[20];
	PtrtoRecord Next;
};
typedef struct Book *PtrtoBook;
typedef struct Students *PtrtoStudents;
typedef struct Record *PtrtoRecord;