#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 11

int h1(int key) {
    int x = (key + 7) * (key + 7);
    x = x / 16;
    x = x + key;
    x = x % TABLE_SIZE;
    return x;
}

void insertLinearProbing(int table[], int key) {
    int homeSlot = h1(key);
    int currentSlot = homeSlot;
    while (table[currentSlot] != -1) {
        currentSlot = (currentSlot + 1) % TABLE_SIZE;
        if (currentSlot == homeSlot) {
            printf("Hash table is full!\n");
            return;
        }
    }
    table[currentSlot] = key;
}

void printHashTable(int table[]) {
    printf("Slot\tContents\n");
    for (int i = 0; i < TABLE_SIZE; ++i) {
        if (table[i] == -1) {
            printf("%d\t \n", i);
        } else {
            printf("%d\t%d\n", i, table[i]);
        }
    }
}

int main() {
    int table[TABLE_SIZE];
    for (int i = 0; i < TABLE_SIZE; ++i) {
        table[i] = -1; // Initialize hash table with -1 indicating empty slots
    }

    int keys[] = {43, 23, 1, 0, 15, 31, 4, 7, 11, 3};
    int numKeys = sizeof(keys) / sizeof(keys[0]);

    for (int i = 0; i < numKeys; ++i) {
        insertLinearProbing(table, keys[i]);
    }

    printHashTable(table);

    return 0;
}
