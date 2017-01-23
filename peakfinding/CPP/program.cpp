#include <stdio.h>
#include <array>

using namespace std;

template <int n>
int peak(array<int,n> arr) { 
    auto start = 0;
    auto end = n - 1;

    if(n <= 0)
    {
        return -1;
    }

    while(start <= end)
    {
      auto  mid = start + (end - start)/2;
        printf("arr[mid] %d \n",arr[mid]);
        if(start == end)
            return arr[start];

        if(mid == start && arr[mid]<arr[end]){
           return arr[end];
        }

        if(arr[mid] >= arr [mid+1] && arr[mid] >= arr[mid-1])
        {
            return arr[mid];
        }
        else if(arr[mid] < arr[mid-1])
        {
            end = mid;
        }
        else
        {
            start = mid;
        }
    }

    return -1;
}
 
int main()
{
    array<int,5> arr = {{207, 205, 204, 203, 202}};
    auto elem = peak(arr);
    printf("peak point is %d", elem);
    return 0;
}