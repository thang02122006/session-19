#include <stdio.h>
#include <string.h>

struct Student {
    int id;
    char name[50];
    int age;
    char phoneNumber[15];
};

void deleteStudent(int studentId, struct Student students[], int *currentLength) {
    int found = 0;
    int indexToDelete = -1;

    for (int i = 0; i < *currentLength; i++) {
        if (students[i].id == studentId) {
            found = 1;
            indexToDelete = i;
            break;
        }
    }

    if (found) {
        for (int i = indexToDelete; i < *currentLength - 1; i++) {
            students[i] = students[i + 1];
        }
        (*currentLength)--;
        printf("Sinh vien co id %d da duoc xoa.\n", studentId);
    } else {
        printf("Khong tim thay sinh vien voi id %d.\n", studentId);
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
    int studentIdToDelete;

    printf("Danh sach sinh vien ban dau:\n");
    printStudents(students, currentLength);

    printf("\nNhap id sinh vien muon xoa: ");
    scanf("%d", &studentIdToDelete);

    deleteStudent(studentIdToDelete, students, &currentLength);

    printf("\nDanh sach sinh vien sau khi xoa:\n");
    printStudents(students, currentLength);

    return 0;
}

