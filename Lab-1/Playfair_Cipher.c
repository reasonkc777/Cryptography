#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define SIZE 5 


void generatePlayfairMatrix(char key[], char matrix[SIZE][SIZE]) {
    int i, j, k = 0;
    char alphabet[26] = "ABCDEFGHIKLMNOPQRSTUVWXYZ"; 
    
    
    int used[26] = {0};
    
    
    for (i = 0; i < strlen(key); i++) {
        if (!used[toupper(key[i]) - 'A']) {
            matrix[k / SIZE][k % SIZE] = toupper(key[i]);
            used[toupper(key[i]) - 'A'] = 1;
            k++;
        }
    }
    
    
    for (i = 0; i < 26; i++) {
        if (!used[i]) {
            matrix[k / SIZE][k % SIZE] = alphabet[i];
            k++;
        }
    }
}


void findPositions(char matrix[SIZE][SIZE], char letter, int *row, int *col) {
    int i, j;
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            if (matrix[i][j] == letter) {
                *row = i;
                *col = j;
                return;
            }
        }
    }
}


void encrypt(char matrix[SIZE][SIZE], char message[], char encrypted[]) {
    int i, row1, col1, row2, col2;
    for (i = 0; i < strlen(message); i += 2) {
        findPositions(matrix, toupper(message[i]), &row1, &col1);
        findPositions(matrix, toupper(message[i + 1]), &row2, &col2);
        
        if (row1 == row2) { 
            encrypted[i] = matrix[row1][(col1 + 1) % SIZE];
            encrypted[i + 1] = matrix[row2][(col2 + 1) % SIZE];
        } else if (col1 == col2) { 
            encrypted[i] = matrix[(row1 + 1) % SIZE][col1];
            encrypted[i + 1] = matrix[(row2 + 1) % SIZE][col2];
        } else { 
            encrypted[i] = matrix[row1][col2];
            encrypted[i + 1] = matrix[row2][col1];
        }
    }
    encrypted[i] = '\0';
}


void decrypt(char matrix[SIZE][SIZE], char encrypted[], char decrypted[]) {
    int i, row1, col1, row2, col2;
    for (i = 0; i < strlen(encrypted); i += 2) {
        findPositions(matrix, toupper(encrypted[i]), &row1, &col1);
        findPositions(matrix, toupper(encrypted[i + 1]), &row2, &col2);
        
        if (row1 == row2) { 
            decrypted[i] = matrix[row1][(col1 - 1 + SIZE) % SIZE];
            decrypted[i + 1] = matrix[row2][(col2 - 1 + SIZE) % SIZE];
        } else if (col1 == col2) { 
            decrypted[i] = matrix[(row1 - 1 + SIZE) % SIZE][col1];
            decrypted[i + 1] = matrix[(row2 - 1 + SIZE) % SIZE][col2];
        } else { // Rectangle
            decrypted[i] = matrix[row1][col2];
            decrypted[i + 1] = matrix[row2][col1];
        }
    }
    decrypted[i] = '\0';
}

int main() {
    char key[] = "AIRBUS"; 
    char matrix[SIZE][SIZE];
    generatePlayfairMatrix(key, matrix);
    
    char fullName[] = "NISHCHALKC"; 
    char encryptedFullName[50];
    char decryptedFullName[50];
    
    encrypt(matrix, fullName, encryptedFullName);
    printf("Encrypted Full Name: %s\n", encryptedFullName);
    
    decrypt(matrix, encryptedFullName, decryptedFullName);
    printf("Decrypted Full Name: %s\n", decryptedFullName);
    
    return 0;
}
