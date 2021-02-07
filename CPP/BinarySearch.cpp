//code for binary search

#include<bits/stdc++.h>
using namespace std;

int ModifiedBinarySearch(int a[], int low,int high,int key)   //Array is sorted in ascending order
{                                                    //low,high are the bounds and key to be searched
    while(high >= low){

        int  mid = (high+low)/2;                     //Basic Testing to be done by the middle element

        if(a[low] > key || a[high] < key){           //array being sorted in ascending order
            return -1;                               // Direct elimination that the element is not in the array
        }

        else if(a[low] == key){                      //Eliminating the end cases --> improving efficiency
            return low;
        }

        else if(a[high] == key){                     //Eliminating the end cases --> improving efficiency
            return high;
        }

        else{                                        //General algorithm for binary search with increased efficiency
            if(a[mid] == key){                       //due to the reduced search span
                return mid;
            }

            else if(a[mid] > key){
                high = mid - 1;
                low++;                               //search span reduced
            }

            else if(a[mid] < key){
                low = mid + 1;
                high--;                              //search span reduced
            }
        }
    }
    return -1;                                       //we reach here when Key not found
}

int main()
{
    int num_elements,numtofind;
    cin>>num_elements;                                                        //number of elements in thw array
    int arr[num_elements];
    for(int i = 0 ;i < num_elements ;i++){
        cin>>arr[i];
    }
    cin>>numtofind;                                                           //number to search for in the array
    cout<<ModifiedBinarySearch(arr,0,num_elements-1,numtofind)<<"\n";
}
