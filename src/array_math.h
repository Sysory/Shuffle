#ifndef SRC_ARRAY_MATH_H
#define SRC_ARRAY_MATH_H

void array_add(double *arr1, double *arr2, double *res, int n);
void array_norm(double *arr, double *res, int n);
void array_merge(double *arr1, double *arr2, double *res, int n, double t);
double array_max(double *arr, int n);
double array_min(double *arr, int n);
double array_mean(double *arr, int n);
double array_quadratic_dev(double *arr, int n);
double array_disp(double *arr, int n);

void array_mul_num(double *arr, double *res, int n, double num);
void array_add_num(double *arr, double *res, int n, double num);

#endif  // SRC_ARRAY_MATH_H
