#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>

#include "array_math.h"

#define N 20

void init(double *, int);
void test_distrib(double *arr, int n, int iters, void (*func)(double *, int));
void shuffle(double *, int);
void output(double *, int);
void swap(double *, int, int);
int max(int a, int b);

int main(void) {
    srand(time(NULL));

    double arr[N];
    test_distrib(arr, N, 1000000, shuffle);
    // double norm[N];

    // init(arr,N);
    // shuffle(arr, N);
    
    // array_norm(arr, norm, N);

    // output(norm, N);
    return 0;
}

void output(double *arr, int n) {
    for (int i=0; i<n; i++) {
        printf("%.2lf ", arr[i]);
    }
}

int max(int a, int b) {
    return a > b? a : b;
}

void shuffle(double *arr, int n) {
    int c = 0;
    for (int i=0; i<n-1; )  {
        int offset = n-1-i;

        for (int j=0; j<=i; j++) {
            if (rand()%2) {
                swap(arr, j, j+offset);
            }
        }
        c++;
        i += max((int)(n-1-i) * 0.02, 1);
    }
    // printf("%d\n", c);
}

void test_distrib(double *arr, int n, int iters, void (*func)(double *, int)) {
    int i = 0;
    double *res = calloc(n, sizeof(*res));
    memset(res, n, sizeof(*res));
    while (i++ < iters) {
        init(arr, n);
        func(arr, n);
        array_norm(arr, arr, n);

        array_add(res, arr, res, n);
    }

    array_mul_num(res, res, n, (double)1/iters);
    printf("dispersion = %.3lf\n", array_disp(arr, n));
    output(res, n);
    free(res);
}

void swap(double *arr, int a, int b) {
    int tmp = arr[a];
    arr[a] = arr[b];
    arr[b] = tmp;
}

void init(double *arr, int n) {
    for (double *p = arr; p-arr < n; p++) {
        *p = p-arr;
    }
}
