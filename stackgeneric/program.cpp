
#include<iostream>
#include "stack.h"
using namespace std;


int main()
{
    int top;

    int x = 10;
    Stack s;
    StackNew(&s, sizeof(int));
   
    StackPush(&s, &x);
    StackPop(&s, &top);
    cout << top << endl;
    return 0;
}   