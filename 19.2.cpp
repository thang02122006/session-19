#include <stdio.h>
#include <string.h>
struct Student {
    int id;
    char name[50];
    int age;
    char phoneNumber[15];
};
void sortStudents(struct Student students[], int currentLength) {
    struct Student temp;
    for (int i = 0; i < currentLength - 1; i++) {
        for (int j = i + 1; j < currentLength; j++) {
            if (strcmp(students[i].name, students[j].name) > 0) {
                temp = students[i];
                students[i] = students[j];
                students[j] = temp;
            }
        }
    }
}
void printStudents(struct Student students[], int currentLength) {
    for (int i = 0; i < currentLength; i++) {
        printf("ID: %d, Name: %s, Age: %d, Phone: %s\n", students[i].id, students[i].name, students[i].age, students[i].phoneNumber);
    }
}
int main() {
   struct Student students[5] = {
        {1, "tran van thang", 18, "034567890"},
        {2, "tran kim chi", 19, "032376511"},
        {3, "le kim cham", 20, "093452455"},
        {4, "pham viet minh", 20, "045312356"},
        {5, "hoang lan anh", 23, "0912345678"}
    };
    int currentLength = 5;
    printf("Danh sach sinh vien ban dau:\n");
    printStudents(students, currentLength);
    sortStudents(students, currentLength);
    printf("\nDanh sach sinh vien sau khi sap xep theo ten:\n");
    printStudents(students, currentLength);

    return 0;
}

