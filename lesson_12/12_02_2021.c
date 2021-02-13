#include <stdio.h>
#include <math.h>

#define N_MAX 100000

double absolute(double);
int factorial(int);
double power(double, int);

double f(double, int);

double sinus(double, double);

double absolute(double x) {
    if (x < 0) {
        x = -x;
    }
    return x;
}

int factorial(int n) {
    if (n == 0) {
        return 1;
    }
    if (n < 0) {
        return -1;
    }
    if (n == 1) {
        return 1;
    }
    int res = 1;
    for (int i = 1; i <= n; i++) {
        res *= i;
    }
    return res;
}

double power(double x, int n) {
    if (n == 0) {
        return 1.;
    }
    double res = 1.;
    for (int i = 0; i < n; i++) {
        res *= x;
    }
    return res;
}

double f(double x, int n) {
    return (power(-1, n) * power(x, 2 * n + 1)) / factorial(2 * n + 1);
}

double sinus(double x, double epsilon) {
    if(x == 0) {
        return 0.;
    }
    double current = 0., result = 0., result_latter = 0., error = 42.;
    int n = 0;

    while (error > epsilon) {
        current = f(x, n);
        result += current;
        error = absolute(result - result_latter);
        result_latter = result;
        n++;
        if (n > N_MAX) {
            printf("N_MAX reached! The answer may be inaccurate!\n");
            break;
        }
    }
    printf("n = %d\n", n);
    return result;
}

void main() {
    double x = -1, eps = 0.0001;
    printf ("DIY sin(x) = %lf\n", sinus(x, eps));
    printf ("math.h sin(x) = %lf\n", sin(x));
}