#include <stdio.h>
#include <math.h>

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

int main() {
    unsigned long long p, g, a, b;

    printf("Enter a prime number p: ");
    scanf("%llu", &p);

    printf("Enter a primitive root g: ");
    scanf("%llu", &g);

    printf("Enter private key of A (a): ");
    scanf("%llu", &a);

    printf("Enter private key of B (b): ");
    scanf("%llu", &b);

    unsigned long long A_pub = mod_exp(g, a, p);

    unsigned long long B_pub = mod_exp(g, b, p);

    unsigned long long shared_secret_A = mod_exp(B_pub, a, p);
    unsigned long long shared_secret_B = mod_exp(A_pub, b, p);

    printf("A's public key: %llu\n", A_pub);
    printf("B's public key: %llu\n", B_pub);

    printf("A's shared secret key: %llu\n", shared_secret_A);
    printf("B's shared secret key: %llu\n", shared_secret_B);

    return 0;
}
