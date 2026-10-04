#ifndef DSA_RECURSION_H
#define DSA_RECURSION_H

#include <stddef.h>

long long factorial(int n);
long long fibonacci(int n);
void tower_of_hanoi(int n, char from_rod, char to_rod, char aux_rod);
int gcd(int a, int b);
double power(double base, int exp);
void string_reverse(char *str, int start, int end);
long long combinations(int n, int r);

#endif
