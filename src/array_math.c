#include "array_math.h"
#include <stdlib.h>
#include <math.h>

void array_sum(double *arr1, double *arr2, double *res, int n) {
    for (int i = 0; i < n; i++) {
        res[i] = arr1[i] + arr2[i];
    }
}

void array_norm(double *arr, double *res, int n) {
    int max = array_max(arr, n);
    int min = array_min(arr, n);

    for (int i = 0; i < n; i++) {
        res[i] = (double)(arr[i] - min) / (max - min);    
    }
}

double array_max(double *arr, int n) {
    double res = *arr;
    for (double *p = arr; p-arr < n; p++) {
        res = *p > res ? *p : res;
    }
    
    return res;
}

double array_min(double *arr, int n) {
    double res = *arr;
    for (double *p = arr; p-arr < n; p++) {
        res = *p < res ? *p : res;
    }
    
    return res;
}
