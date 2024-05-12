#include<iostream>
using namespace std;

void InsertionSort(int Arr[], int n)
{
    int i, j, temp;
    for (i = 1; i < n; i++)
    {
        temp = Arr[i];
        j = i - 1;
        while (j >= 0 && Arr[j] > temp)
        {
            Arr[j + 1] = Arr[j];
            j--;
        }
        Arr[j + 1] = temp;
    }
}

int main()
{
    int n;
    cout << "Enter size of array: " << endl;
    cin >> n;
    int Arr[n];
    cout << "Enter elements of array: ";
    for (int i = 0; i < n; i++)
    {
        cin >> Arr[i];
    }
    InsertionSort(Arr, n);
    cout << "Sorted array: ";
    for (int i = 0; i < n; i++)
    {
        cout << Arr[i] << " ";
    }
    cout << endl;

    return 0;
}
