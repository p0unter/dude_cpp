#include <iostream>
#include <cstring>

using namespace std;

struct RecordType  {
    char pointer;
    char name[20];
    char surname[20];
    char telephone[20];
};

char continue_program;

struct RecordType students[10];
FILE *fp;
int record_lenght, record_number, record_position;

main() {
    fp = fopen("students.txt", "r+"); // Open the file in read and write mode.
    if (fp == NULL) {
        fp = fopen("students.txt", "w+"); // Open the file in write and read mode.
    }
    record_lenght = sizeof(students);
    while(1) {
        printf("\nEnter record number: ");
        scanf("%d", &record_number);

        students.pointer = ' ';
        memset(students.name, ' ', 20);
        memset(students.surname, ' ', 20);
        memset(students.telephone, ' ', 20);

        record_position = (record_number - 1) * record_lenght;
        fseek(fp, record_position, SEEK_SET); // Cursor set to the record position.
        fread(&students, record_lenght, 1, fp); // Read the record.
        if(students.pointer != '*') {
            printf("Name: %s\n", students.name);
            scanf("%s", students.name);

            printf("Surname: %s\n", students.surname);
            scanf("%s", students.surname);

            printf("Telephone: %s\n", students.telephone);
            scanf("%s", students.telephone);

            students.pointer = '*';
            fseek(fp, record_position, SEEK_SET);
            fwrite(&students, record_lenght, 1, fp); // Write the record.
        } else {
            printf("Record area!\n");
        }
        printf("Do you want to continue? (y/n): ");
        continue_program = getche();
        if(continue_program == 'n') {
            break;
        }
    }
}