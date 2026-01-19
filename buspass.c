#include <stdio.h>
#include <string.h>

#define MAX 5

struct Student {
    int roll;
    char name[30];
};

struct Student cq[MAX];
int front = -1, rear = -1;

int isFull() {
    return (front == (rear + 1) % MAX);
}


int isEmpty() {
    return (front == -1);
}


void enqueue() {
    struct Student s;

    if (isFull()) {
        printf("\nQueue is full! Cannot add more students.\n");
        return;
    }

    printf("Enter Roll Number: ");
    scanf("%d", &s.roll);
    printf("Enter Name: ");
    scanf("%s", s.name);

    if (front == -1)
        front = 0;

    rear = (rear + 1) % MAX;
    cq[rear] = s;

    printf("Student added successfully.\n");
}


void dequeue() {
    if (isEmpty()) {
        printf("\nNo students waiting for bus pass.\n");
        return;
    }

    printf("\nBus Pass Distributed to:\n");
    printf("Roll No: %d\nName: %s\n", cq[front].roll, cq[front].name);

    if (front == rear) {
        front = rear = -1;
    } else {
        front = (front + 1) % MAX;
    }
}


void display() 
{
    int i;

    if (isEmpty()) {
        printf("\nNo students in queue.\n");
        return;
    }

    printf("\nWaiting Students:\n");
    i = front;
    while (1) {
        printf("Roll No: %d | Name: %s\n", cq[i].roll, cq[i].name);
        if (i == rear)
            break;
        i = (i + 1) % MAX;
    }
}

int main() {
    int choice;

    do {
        printf("\n--- Bus Pass Distribution System ---\n");
        printf("1. Add Student\n");
        printf("2. Distribute Bus Pass\n");
        printf("3. Show Waiting Students\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: enqueue(); break;
            case 2: dequeue(); break;
            case 3: display(); break;
            case 4: printf("Exiting program.\n"); break;
            default: printf("Invalid choice!\n");
        }
    } while (choice != 4);

    return 0;
}
