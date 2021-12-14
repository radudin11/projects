#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAME_SIZE 20
#define INPUT_LEN 46

typedef struct Tstudent {
    char surname[NAME_SIZE], first_name[NAME_SIZE];
    int age;
}Tstud;

Tstud* alloc_students_db(int stud_number) {
    Tstud* stud_datab= malloc(stud_number * sizeof(Tstud));
    return stud_datab;
}

void read_student(Tstud* stud_datab, int nrCrt) {
    char input[INPUT_LEN];
    fgets(input, INPUT_LEN, stdin);

    char *p = strtok(input, " ");

    strncpy(stud_datab[nrCrt].surname, p, NAME_SIZE);
    p = strtok(NULL, " ");
    
    strncpy(stud_datab[nrCrt].first_name, p, NAME_SIZE);
    p = strtok(NULL, " ");

    stud_datab[nrCrt].age = atoi(p);

    // while(p != NULL) p = strtok(NULL, "");
}

void print_student(Tstud student) {
    printf("Name: %s %s, age: %d",
        student.surname, student.first_name, student.age);
    printf("\n");
}

void print_by_age(Tstud * stud_datab, int student_number) {
    int student_id[200];

}

int main() {
    int students_number;
    printf("The number of students is: ");
    scanf("%d", &students_number);

    getc(stdin);

    Tstud* students_datab = NULL;
    students_datab = alloc_students_db(students_number);

    if (students_datab == NULL) {
        printf("Not eough memory available");
        return 1;
    }

    for (int i = 0; i < students_number; i++) {
        read_student(students_datab, i);
    }

    for (int i = 0; i < students_number; i++) {
        print_student(students_datab[i]);
    }

    char c = 0;
    while (c != 'q') {
        printf("Give a command:\ns: prints the students in alfabetic order of their surnames\n");
        printf("f: prints the students in alfabetic order of their first names\n");
        printf("a: prints the students in the order of their ages\n");
        printf("q: quit");
        c = getc(stdin);
        switch (c)
        {
        case 'f':
            order_by_firstname(students_datab);
            break;
        case 'n':
            order_by_surname(students_datab);
            break;
        case 'a':
            order_by_age(students_datab);
            break;
        default:
            printf("Unknown command");
            break;
        }
        printf("\n-----------------------------------\n");
    }

    free(students_datab);

    return 0;
}