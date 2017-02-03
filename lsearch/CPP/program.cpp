
#include<iostream>
using namespace std;

// int version
int lsearch(int key, int array[], int size){
    for(int i=0; i<size; i++){
        if(array[i]==key){
            return i;
        }
    }
    return -1;
}

// generic version
void* lsearchGeneric(void* key, void* base, int n, int elemSize){
    //base = base address of the array.
    //n = number of elements
    //elemsize = size of a element in the array
    for(int i=0; i<n; i++){
        
        void* elemAddr = (char*)base + i*elemSize;
        if(memcmp(key,elemAddr,elemSize)==0){
            return elemAddr;
            
        }
    }

    return NULL;
}
//generic version with functionpointer version
void* lsearchFunctionPointer(void* key, void* base, int n, int elemSize,int (*cmpfn)(void*, void*)){
     for(int i=0; i<n; i++){
        void* elemAddr = (char*)base + i*elemSize;
        if(cmpfn(key,elemAddr) == 0){
            return elemAddr;
        }
    }
   return NULL;
}

int intCmp(void *elem1, void *elem2){
    int *ip1 = (int*)elem1;
    int *ip2 = (int*)elem2;

    return *ip1 - *ip2;
}

int main()
{
    int size = 5;
    int array[] = {1000, 2, 3, 7, 5};

    int number = 7;

    //int *found = (int*)lsearchGeneric(&number, array, 5, sizeof(int));// size of int is 4
    int *found = (int*)lsearchFunctionPointer(&number, array, 5, sizeof(int),intCmp);
    cout << *found << endl;
    return 0;
}