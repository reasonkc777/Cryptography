#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define P 23     
#define G 5      

unsigned long long mod_exp(unsigned long long base, unsigned long long exp, unsigned long long mod) {
    unsigned long long result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}


int mod_inverse(int a, int m) {
    int m0 = m, t, q;
    int x0 = 0, x1 = 1;

    if (m == 1) return 0;

    while (a > 1) {
        q = a / m;
        t = m;
        m = a % m;
        a = t;

        t = x0;
        x0 = x1 - q * x0;
        x1 = t;
    }

    if (x1 < 0) x1 += m0;

    return x1;
}

void elgamal_encrypt(int plaintext, int *c1, int *c2, int y, int p) {
    int k = rand() % (p - 2) + 1; 

    *c1 = mod_exp(G, k, p);
    int s = mod_exp(y, k, p);
    *c2 = (plaintext * s) % p;
}

int elgamal_decrypt(int c1, int c2, int x, int p) {
    int s = mod_exp(c1, x, p);
    int s_inv = mod_inverse(s, p);
    int plaintext = (c2 * s_inv) % p;

    return plaintext;
}

int main() {
    int x = 6; 
    int y = mod_exp(G, x, P); 

    int plaintext = 18; 

    int c1, c2;
    elgamal_encrypt(plaintext, &c1, &c2, y, P);

    printf("Original Plaintext: %d\n", plaintext);
    printf("Encrypted C1: %d\n", c1);
    printf("Encrypted C2: %d\n", c2);

    int decrypted_plaintext = elgamal_decrypt(c1, c2, x, P);
    printf("Decrypted Plaintext: %d\n", decrypted_plaintext);

    return 0;
}
