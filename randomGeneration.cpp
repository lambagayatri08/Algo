#include <vector>
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void selectionSort(vector<int>& nums){
    for(int i = 0 ; i < nums.size() ; i++){
        int min_idx = i;
        for(int j = i + 1 ; j < nums.size() ; j++){
            if (nums[j] < nums[min_idx])
            {
                min_idx = j;
            }
            
        }
        swap(nums[min_idx],nums[i]);
    }
}

void insertionSort(vector<int>& nums){
    for (int i = 1 ; i < nums.size();i++){
        int key = nums[i];
        int j = i - 1;

        while (j >=0 && nums[j]  > key)
        {
            nums[j+1] = nums[j];
            j--;
        }
        nums[j+1] = key;    
    }
}

void BubbleSort(vector<int>& nums){
    for( int i = 0 ; i < nums.size() ; i++){
        for(int j = 0 ; j < nums.size()-i-1;j++ ){
            if(nums[j] > nums[j+1]){
                swap(nums[j],nums[j+1]);
            }
        }
    }
}

int main(){
    int size = 1000;
    vector<int>arr(size);
    srand(time(NULL));

    for (int i = 0; i < size; i++)
    {
        arr.push_back(rand()%100);
    }

    insertionSort(arr);
    for(auto it : arr){
        cout<<it<<" "; 
    }
    
}