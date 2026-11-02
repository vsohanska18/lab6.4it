#include <iostream>
#include <iomanip>
#include <time.h>
#include <cmath>
using namespace std;

void input_array(double a[], int n);
void print_array(double a[], int n);
int count_greater(double a[], int n, double C);
double product_after_max_abs(double a[], int n);
void rearrange_array(double a[], int n);

#ifndef UNIT_TEST
int main(){
    int n, result;
    double C, product;
    cout << "n = "; cin >> n;
    double* a = new double[n];
    cout << "C = "; cin >> C;

    input_array(a, n);
    print_array(a, n);
    result = count_greater(a, n, C);
    cout << "Кількість елементів, більших за C: " << result << endl;
    product = product_after_max_abs(a, n);
    cout << "Добуток елементів після найбільшого за модулем: " << product << endl;
    rearrange_array(a, n);
    cout << "Масив після перестановки:" << endl;
    print_array(a, n);

    delete[] a;
    return 0;
}
#endif

void input_array(double a[], int n){
    for(int i=0; i<n; i++){
        cout << "a[" << i << "] = "; cin >> a[i];
    }
}
void print_array(double a[], int n){
    for(int i=0; i<n; i++){
        cout << setw(4) << a[i];
    }
    cout << endl;
}
int count_greater(double a[], int n, double C){
    int count = 0;
    for(int i = 0; i < n; i++){
        if (a[i] > C)
            count++;
    }
    return count;
}
double product_after_max_abs(double a[], int n){
    int max_index = 0;
    double product = 1;
    for(int i=1; i<n; i++){
        if(fabs(a[i]) > fabs(a[max_index])){
            max_index = i;
        }
    }
    for(int i=max_index+1; i<n; i++){
        product *= a[i];
    }
    return product;
}
void rearrange_array(double a[], int n){
    double* temp = new double[n];
    int k = 0;
    for(int i = 0; i < n; i++){
        if(a[i] < 0){
            temp[k] = a[i];
            k++;
        }
    }
    for(int i = 0; i < n; i++){
        if(a[i] >= 0){
            temp[k] = a[i];
            k++;
        } 
    }
    for(int i = 0; i < n; i++){
        a[i] = temp[i];
    }
    delete[] temp;
}