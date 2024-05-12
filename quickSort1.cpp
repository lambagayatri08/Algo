#include<iostream>
#include<algorithm>
using namespace std;

int Partition(int a[], int lb, int ub)
{
    int Pivot = a[lb];
    int start = lb;
    int end = ub;
    while (start < end)
    {
        while (a[start] <= Pivot)
        {
            start++;
        }
        while (a[end] > Pivot)
        {
            end--;
        }
        if (start < end)
        {
            swap(a[start], a[end]);
        }
    }
    swap(a[lb], a[end]);
    return end;
}

void QuickSort(int a[], int lb, int ub)
{
    if (lb < ub)
    {
        int loc = Partition(a, lb, ub);
        QuickSort(a, lb, loc - 1);
        QuickSort(a, loc + 1, ub);
    }
}

int main(){
    int n;
    cout << "Enter size of array: " << endl;
    cin >> n;
    int a[n];
    cout << "Enter elements of array: ";
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    QuickSort(a, 0, n - 1);
    cout << "Sorted array: ";
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;

    return 0;
}
