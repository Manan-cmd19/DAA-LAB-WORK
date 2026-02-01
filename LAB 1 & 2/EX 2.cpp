#include <iostream>
#include <ctime>
#include <cstdlib>
#define n 1000
using namespace std;

void mySwap(int &a, int &b)
{
    int t = a;
    a = b;
    b = t;
}

void merge_sort(int a[], int l, int r, int &c)
{
    if (l >= r)
        return;

    int m = (l + r) / 2;
    merge_sort(a, l, m, c);
    merge_sort(a, m + 1, r, c);

    int *t = new int[r - l + 1];
    int i = l, j = m + 1, k = 0;

    while (i <= m && j <= r)
    {
        c++;
        t[k++] = (a[i] <= a[j]) ? a[i++] : a[j++];
    }
    while (i <= m)
        t[k++] = a[i++];
    while (j <= r)
        t[k++] = a[j++];

    for (i = l, k = 0; i <= r; i++)
        a[i] = t[k++];

    delete[] t;
}

void quick_sort(int a[], int l, int r, int &c)
{
    if (l >= r)
        return;

    int i = l - 1;
    for (int j = l; j < r; j++)
    {
        c++;
        if (a[j] <= a[r])
            mySwap(a[++i], a[j]);
    }
    mySwap(a[i + 1], a[r]);

    quick_sort(a, l, i, c);
    quick_sort(a, i + 2, r, c);
}

void reverse_array(int a[])
{
    for (int i = 0; i < n / 2; i++)
        mySwap(a[i], a[n - 1 - i]);
}

int main()
{
    int a[n], t[n], c;

    srand(time(0));
    for (int i = 0; i < n; i++)
        a[i] = rand();

    cout << "Merge Sort ->" << endl;

    for (int i = 0; i < n; i++)
        t[i] = a[i];
    c = 0;
    merge_sort(t, 0, n - 1, c);
    cout << "Avg:" << c << " Best:" << c;

    reverse_array(t);
    c = 0;
    merge_sort(t, 0, n - 1, c);
    cout << " Worst:" << c << endl;

    cout << "Quick Sort ->" << endl;

    for (int i = 0; i < n; i++)
        t[i] = a[i];
    c = 0;
    quick_sort(t, 0, n - 1, c);
    cout << "Avg:" << c << " Best:" << c;

    reverse_array(t);
    c = 0;
    quick_sort(t, 0, n - 1, c);
    cout << " Worst:" << c << endl;
}
