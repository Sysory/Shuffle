#include "array_math.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

void array_add_num(double *arr, double *res, int n, double num) {
    for (int i = 0; i < n; i++) {
        res[i] = arr[i] + num;
    }
}

void array_mul_num(double *arr, double *res, int n, double num) {
    for (int i = 0; i < n; i++) {
        res[i] = arr[i] * num;
    }
}

void array_add(double *arr1, double *arr2, double *res, int n) {
    for (int i = 0; i < n; i++) {
        res[i] = arr1[i] + arr2[i];
    }
}

double array_disp(double *arr, int n) {
    double mean = array_mean(arr, n);
    double res = 0;
    for (int i = 0; i < n; i++) {
        res += (arr[i] - mean) * (arr[i] - mean); 
    }
    res /= n;
    return res;
}

double array_quadratic_dev(double *arr, int n) {
    double disp = array_disp(arr, n);
    return sqrt(disp);
}

void array_merge(double *arr1, double *arr2, double *res, int n, double t) {
    for (int i = 0; i < n; i++) {
        res[i] = arr1[i] + t * (arr2[i] - arr1[i]);
        // res[i] = arr1[i] * (1-t) + arr2[i] * t;
        // printf("%lf\n", res[i]);
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

double array_mean(double *arr, int n) {
    double res = 0;
    for (int i = 0; i < n; i++) {
        res += arr[i];
    }

    return res / n;
}
