#include <iostream>
#include <conio.h>
#include <cstring>
using namespace std;

main() {
    char name[20], fatherName[20], search[20];
    int choice, birthDate, flag;

    char temp;

    cout << "1.\t Add Student" << endl;
    cout << "2.\t Search Student" << endl;
    cin >> choice;

    switch (choice) {
        case 1:
            FILE *fp;
            fp = fopen("students.txt", "w");

            if(fp == NULL) {
                printf("The file was not created.");
            } else {
                while(1) {
                    printf("\nStudent Name: ");
                    scanf("%s", name);

                    printf("Father Name: ");
                    scanf("%s", fatherName);

                    printf("Birth of year: ");
                    scanf("%d", &birthDate);

                    fprintf(fp, "%s\t %s\t %d\n", name, fatherName, &birthDate);

                    printf("Will a new record be added? (Y / N): ");
                    temp = getche();

                    if (temp == 'H') {
                        break;
                    }
                }
            }

            fclose(fp);
            break;
        
        case 2:
            cout << "Whose record should come?";
            scanf("%s", search);

            while(fscanf(fp, "%s %s %d", name, fatherName, &birthDate) != EOF) {
                if(strcmp(name, search) == 0) {
                    printf("%s\t %s\t %d \n", name, fatherName, &birthDate);
                    flag = 1;
                }
            }
            if (flag == 0) {
                cout << "Record not found." << endl;
            }
            break;

        default:
            break;
    }
}