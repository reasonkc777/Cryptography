#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
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

bool is_prime(unsigned long long n, int k) {
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0) return false;

    unsigned long long d = n - 1;
    int r = 0;
    while (d % 2 == 0) {
        d /= 2;
        r++;
    }

    for (int i = 0; i < k; i++) {
        unsigned long long a = 2 + rand() % (n - 3);
        unsigned long long x = mod_exp(a, d, n);
        
        if (x == 1 || x == n - 1)
            continue;
        
        for (int j = 0; j < r - 1; j++) {
            x = mod_exp(x, 2, n);
            if (x == 1) return false;
            if (x == n - 1) break;
        }
        
        if (x != n - 1) return false;
    }

    return true;
}

int main() {
    unsigned long long number;
    int k = 5; 

    printf("Enter a number: ");
    scanf("%llu", &number);

    if (is_prime(number, k)) {
        printf("%llu is probably prime.\n", number);
    } else {
        printf("%llu is not prime.\n", number);
    }

    return 0;
}
