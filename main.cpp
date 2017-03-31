#include <iostream>
#include <time.h>

using namespace std;

int fibonacci(int x){        //We want to print out the first x terms of fibonacci sequence

    if(x == 0){
        //cout <<0<<endl;
        return 0;
    }
    else if(x == 1){
        //cout <<1<<endl;
        return 1;
    }
    else{
        //cout<<fibonacci(x-1)+fibonacci(x-2)<<endl;
        return fibonacci(x-1)+fibonacci(x-2);   //What do we want to do for any given term?
    }
}

int newFib(int x, int* anArray){

    if(x == 0)
        return 0;
    else if(x == 1)
        return 1;

    else{

    if(anArray[x] == 0){
        anArray[x] = newFib(x-1, anArray) + newFib(x-2, anArray);
    }
    return anArray[x];
}
}


int main()
{

clock_t t1,t2;
t1=clock();
    for(int i = 0; i < 40; i++){
        int test = fibonacci(i);
        cout<<"fibonacci for "<<i<<" is "<<test<<endl;
}
t2=clock();

float diff ((float)t2-(float)t1);
float seconds = diff / CLOCKS_PER_SEC;


cout<<"With no Dynamic Programming it runs for "<<seconds<<" seconds"<<endl;

clock_t t3,t4;

t3 = clock();
    int anArray[40] = {0};  //Sets all terms to 0

    for(int k = 0; k<40; k++){
        int newTest = newFib(k, anArray);
        cout<<"fib 2.0 for "<<k<<" is "<<newTest<<endl;
    }
t4 = clock();
float newDiff ((float)t4-(float)t3);
float newSeconds = newDiff / CLOCKS_PER_SEC;

cout<<"With Dynamic Programming it runs for "<<newSeconds<<" seconds"<<endl;
return 0;
}
