#include "dsa/recursion.h"
#include <stdio.h>

long long factorial(int n) {
    if (n <= 1) return 1;
    return n * factorial(n -1);
}

long long fibonacci(int n) {
    if (n <= 0) return 0;
    if (n == 1) return 1;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

void tower_of_hanoi(int n, char from_rod, char to_rod, char aux_rod) {
    if (n == 1) {
        printf("Move disk 1 from %c to %c\n", from_rod, to_rod);
        return;
    }
    tower_of_hanoi(n - 1, from_rod, aux_rod, to_rod);
    printf("Move disk %d from %c to %c\n", n, from_rod, to_rod);
    tower_of_hanoi(n - 1, aux_rod, to_rod, from_rod);
}

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

double power(double base, int exp) {
    if (exp == 0) return 1.0;
    if (exp < 0) return 1.0 / power(base, -exp);
    double half = power(base, exp / 2);
    if (exp % 2 == 0) return half * half;
    return base * half * half;
}
 void string_reverse(char *str, int start, int end) {
     if (start >= end) return;
     char temp = str[start];
     str[start] = str[end];
     str[end] = temp;
     string_reverse(str, start + 1, end - 1);
 }

long long combinations(int n, int r) {
    if (r == 0 || r == n) return 1;
    return combinations(n -1, r - 1) + combinations(n - 1, r);
    }

