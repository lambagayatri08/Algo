#include <iostream>
#include <climits>
using namespace std;

void countSort(int arr[], int n, int pos);

void RadixSort(int arr[], int n)
{
    int max = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > max)
            max = arr[i];
    }
    for (int pos = 1; max / pos > 0; pos *= 10)
    {
        countSort(arr, n, pos);
    }
}

void countSort(int arr[], int n, int pos)
{
    int k = 10; // assuming decimal digits (0-9)
    int count[k] = {0};
    int output[n];
    for (int i = 0; i < n; i++)
    {
        ++count[(arr[i] / pos) % 10]; // to find 2 in 432/10 = 43%10=3
    }
    for (int i = 1; i < k; i++)
    {
        count[i] += count[i - 1]; // for cumulative freq
    }
    for (int i = n - 1; i >= 0; i--)
    {
        output[--count[(arr[i] / pos) % 10]] = arr[i]; // maintaing stability sort 
    }
    for (int i = 0; i < n; i++)
    {
        arr[i] = output[i];
    }
}

int main()
{
    int n;
    cout << "Enter size of array:" << endl;
    cin >> n;
    int arr[n];
    cout << "Enter elements of array:";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    RadixSort(arr, n);
    cout << "Sorted array:";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
