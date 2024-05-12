#include<iostream>
using namespace std;
void BubbleSort(int Arr[],int n)
{
    for (int i=0;i<n;i++)
    {
        for (int j=0;j<n-i-1;j++)
        {
            if (Arr[j]> Arr[j+1])
            {
             swap(Arr[j],Arr[j+1]);
            }
        }
    }
}
 
int main()
{
    int Arr[] = { 64, 34, 25, 12, 22, 11, 90 };
    int n = sizeof(Arr) / sizeof(Arr[0]);
    BubbleSort(Arr, n);
    cout << "Sorted array: \n";
    int i;
    for (i = 0; i < n; i++)
        cout << " " << Arr[i];
    return 0;
}