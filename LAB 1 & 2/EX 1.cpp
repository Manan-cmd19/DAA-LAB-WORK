#include <iostream>
#include <ctime>
#include <cstdlib>
#define n 1000
void mySwap(int &x, int &y){
    int t = x;
    x = y;
    y = t;
}
int insertion_sort(int a[]){
    int c = 0;
    for(int i = 1; i < n; i++){
        int k = a[i], j = i - 1;
        while(j >= 0 && (++c, a[j] > k)){
            a[j + 1] = a[j];
            j--;
        }a[j + 1] = k;
    }return c;
}
int selection_sort(int a[]){
    int c = 0;
    for(int i = 0; i < n - 1; i++){
        int min = i;
        for(int j = i + 1; j < n; j++, c++)
            if(a[j] < a[min])
                min = j;
        mySwap(a[i], a[min]);
    }return c;
}
int bubble_sort(int a[]){
    int c = 0;
    for(int i = 0; i < n - 1; i++){
        bool swapped = false;
        for(int j = 0; j < n - i - 1; j++, c++)
            if(a[j] > a[j + 1]){
                mySwap(a[j], a[j + 1]);
                swapped = true;
            }if(!swapped) break;
    }return c;
}
void reverse_array(int a[]){
    for(int i = 0; i < n / 2; i++)
        mySwap(a[i], a[n - 1 - i]);
}
int run_sort(int (*f)(int[]), int a[], double &time_taken){
    clock_t start = clock();
    int c = f(a);
    clock_t end = clock();
    time_taken = double(end - start) / CLOCKS_PER_SEC;
    return c;
}
void test_sort(int (*f)(int[]), int a[]){
    int t[n];
    double time;
    for(int i = 0; i < n; i++)
        t[i] = a[i];
    int avg = run_sort(f, t, time);
    std::cout << "Avg: " << avg << " Time: " << time << "s";
    int best = run_sort(f, t, time);
    std::cout << " Best: " << best << " Time: " << time << "s";
    reverse_array(t);
    int worst = run_sort(f, t, time);
    std::cout << " Worst: " << worst << " Time: " << time << "s\n";
}
int main(){
    int a[n];
    std::srand(std::time(0));
    for(int i = 0; i < n; i++)
        a[i] = std::rand();
    std::cout << "Insertion Sort\n";
    test_sort(insertion_sort, a);
    std::cout << "Selection Sort\n";
    test_sort(selection_sort, a);
    std::cout << "Bubble Sort\n";
    test_sort(bubble_sort, a);
    return 0;
}