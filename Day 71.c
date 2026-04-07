#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define EMPTY -1

typedef struct {
    int size;
    int* table;
} HashTable;

HashTable* createTable(int m) {
    HashTable* ht = (HashTable*)malloc(sizeof(HashTable));
    ht->size = m;
    ht->table = (int*)malloc(m * sizeof(int));
    for (int i = 0; i < m; i++) {
        ht->table[i] = EMPTY;
    }
    return ht;
}

// Basic hash function: h'(k) = k % m
int hash(int key, int m) {
    return key % m;
}

void insert(HashTable* ht, int key) {
    int m = ht->size;
    int baseHash = hash(key, m);
    
    for (int i = 0; i < m; i++) {
        int index = (baseHash + i * i) % m;
        if (ht->table[index] == EMPTY) {
            ht->table[index] = key;
            return;
        }
    }
}

int search(HashTable* ht, int key) {
    int m = ht->size;
    int baseHash = hash(key, m);
    
    for (int i = 0; i < m; i++) {
        int index = (baseHash + i * i) % m;
        if (ht->table[index] == key) {
            return 1; // Found
        }
        if (ht->table[index] == EMPTY) {
            return 0; // Optimization: Stop if we hit an empty slot
        }
    }
    return 0; // Not found after full probe
}

int main() {
    int m, n;
    if (scanf("%d %d", &m, &n) != 2) return 0;

    HashTable* ht = createTable(m);

    for (int i = 0; i < n; i++) {
        char command[10];
        int val;
        scanf("%s %d", command, &val);

        if (strcmp(command, "INSERT") == 0) {
            insert(ht, val);
        } else if (strcmp(command, "SEARCH") == 0) {
            if (search(ht, val)) {
                printf("FOUND\n");
            } else {
                printf("NOT FOUND\n");
            }
        }
    }

    free(ht->table);
    free(ht);
    return 0;
}
