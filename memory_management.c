#include <stdio.h>
#include <stdlib.h>

// Global variables
int globalVar1 = 1;
int globalVar2 = 1;
int globalVar3 = 1;

// Function to demonstrate the call stack
void level3() {
    int localLevel3 = 30;
    printf("Address of local variable in level3: %p\n", (void*)&localLevel3);
}

void level2() {
    int localLevel2 = 30;
    printf("Address of local variable in level2: %p\n", (void*)&localLevel2);
    level3();
}

void level1() {
    int localLevel1 = 30;
    printf("Address of local variable in level1: %p\n", (void*)&localLevel1);
    level2();
}

int main() {
    // Print addresses of global variables
    printf("Address of globalVar1: %p\n", (void*)&globalVar1);
    printf("Address of globalVar2: %p\n", (void*)&globalVar2);
    printf("Address of globalVar3: %p\n", (void*)&globalVar3);

    // Demonstrate the function call stack
    level1();

    // Dynamically allocate memory using malloc
    int *heapVar1 = (int*)malloc(sizeof(int));
    int *heapVar2 = (int*)malloc(sizeof(int));
    int *heapVar3 = (int*)malloc(sizeof(int));

    // Print addresses of allocated heap memory
    printf("Address of heapVar1: %p\n", (void*)heapVar1);
    printf("Address of heapVar2: %p\n", (void*)heapVar2);
    printf("Address of heapVar3: %p\n", (void*)heapVar3);

    // Free allocated memory
    free(heapVar1);
    free(heapVar2);
    free(heapVar3);

    return 0;
}
