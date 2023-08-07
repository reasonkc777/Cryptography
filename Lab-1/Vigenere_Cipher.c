/* Write a program to demonstrate encryption and decryption of your full name using Vigenere Cipher. */
#include <stdio.h>
#include <string.h>
#include <ctype.h>
void vigenereEncrypt(char text[], char key[]) {
    int textLength = strlen(text);
    int keyLength = strlen(key);
	int i;
	for (i = 0; i < textLength; i++) {
        if (isalpha(text[i])) {
            int keyIndex = i % keyLength;
            int shift = toupper(key[keyIndex]) - 'A';

            if (islower(text[i])) {
                text[i] = ((text[i] - 'a' + shift) % 26) + 'a';
            } else if (isupper(text[i])) {
                text[i] = ((text[i] - 'A' + shift) % 26) + 'A';
            }
        }
    }
}
void vigenereDecrypt(char text[], char key[]) {
    int textLength = strlen(text);
    int keyLength = strlen(key);
	int i;
	for (i = 0; i < textLength; i++) {
        if (isalpha(text[i])) {
            int keyIndex = i % keyLength;
            int shift = toupper(key[keyIndex]) - 'A';

            if (islower(text[i])) {
                text[i] = ((text[i] - 'a' - shift + 26) % 26) + 'a';
            } else if (isupper(text[i])) {
                text[i] = ((text[i] - 'A' - shift + 26) % 26) + 'A';
            }
        }
    }
}

int main() {
    char name[] = "HUNTER"; 
    char key[] = "KILLER";       
    printf("Original Name: %s\n", name);
    vigenereEncrypt(name, key);
    printf("Encrypted Name: %s\n", name);
    vigenereDecrypt(name, key);
    printf("Decrypted Name: %s\n", name);
    return 0;
}

