#include <stdio.h>

unsigned int eulerPhi(unsigned int n) {
    unsigned int result = n; 

    for (unsigned int p = 2; p * p <= n; ++p) {
        if (n % p == 0) {
            while (n % p == 0) {
                n /= p;
            }
            result -= result / p;
        }
    }
    
    
    if (n > 1) {
        result -= result / n;
    }
    
    return result;
}

int main() {
    unsigned int n;

    printf("Enter a positive integer: ");
    scanf("%u", &n);

    if (n <= 0) {
        printf("Please enter a positive integer.\n");
    } else {
        unsigned int phi = eulerPhi(n);
        printf("Euler's Totient Function phi(%u) = %u\n", n, phi);
    }

    return 0;
}
