#include <stdio.h>
#include <stdlib.h>

int globalVar1 = 1;
int globalVar2 = 2;
int globalVar3 = 3;

void level3() {
    int localLevel3 = 30;
    printf("Address of local variable in level3: %p\n", (void*)&localLevel3);
}

void level2() {
    int localLevel2 = 40;
    printf("Address of local variable in level2: %p\n", (void*)&localLevel2);
    level3();
}

void level1() {
    int localLevel1 = 50;
    printf("Address of local variable in level1: %p\n", (void*)&localLevel1);
    level2();
}

int main() {
    printf("Address of globalVar1: %p\n", (void*)&globalVar1);
    printf("Address of globalVar2: %p\n", (void*)&globalVar2);
    printf("Address of globalVar3: %p\n", (void*)&globalVar3);

    level1();

    int* block = (int*)malloc(3 * sizeof(int));
    int* heapVar1 = &block[0];
    int* heapVar2 = &block[1];
    int* heapVar3 = &block[2];


    printf("Address of heapVar1: %p\n", (void*)heapVar1);
    printf("Address of heapVar2: %p\n", (void*)heapVar2);
    printf("Address of heapVar3: %p\n", (void*)heapVar3);

    free(block);

    return 0;
}
