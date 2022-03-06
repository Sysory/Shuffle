#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>

#include "array_math.h"

#define N 256
#define ENABLE_PROGRESS 1

void init(double *arr, int n);
void test_distrib(double *arr, int n, int iters, void (*func)(double *, int));
void shuffle_fast(double *arr, int n);
void shuffle(double *arr, int n);
void output(double *arr, int n);
void swap(double *arr, int a, int b);
int max(int a, int b);

int main(void) {
    srand(time(NULL));

    double arr[N];
    test_distrib(arr, N, 10000, shuffle_fast);
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

void shuffle_fast(double *arr, int n) {
    for (int i = n-1; i > 1; i--) {
        int a = i;
        int b = rand() % i;
        // printf("swap %d and %d ", a, b);
        swap(arr, a, b);
    }
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
}

void test_distrib(double *arr, int n, int iters, void (*func)(double *, int)) {
    int i = 0;
    double *res = calloc(n, sizeof(*res));
    memset(res, n, sizeof(*res));
    while (i++ < iters) {
        if (ENABLE_PROGRESS) {
            printf("\033[1J-=\033[38;2;%d;%d;%dm %.3lf%% \033[0m=-\n", 
                (int)((double)i/iters*100*4)%255,
                (int)((double)i/iters*100*8)%255,
                (int)((double)i/iters*100*12)%255,
                (double)i/iters*100);
        }
        init(arr, n);
        func(arr, n);
        array_norm(arr, arr, n);

        array_add(res, arr, res, n);
    }

    array_mul_num(res, res, n, (double)1/iters);
    printf("dispersion = %.3lf\n", array_disp(res, n));
    printf("quadratic diveance = %.3lf\n", array_quadratic_dev(res, n));
    printf("mean diveance = %.3lf\n", array_mean_div(res, n));
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
