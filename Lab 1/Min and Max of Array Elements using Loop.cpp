#include <iostream>

using namespace std;

int main()
{
    int arr[10];
    for(int i = 0; i<10; i++){
        cout<<"Enter number "<<i+1<<" : ";
        cin>>arr[i];
    }

    int minNum = arr[0], maxNum = arr[0];

    for(int i = 1; i<10; i++){
        if(minNum > arr[i]){
            minNum = arr[i];
        }
        if(maxNum < arr[i]){
            maxNum = arr[i];
        }
    }

    cout<<"Minimum Value : "<<minNum<<endl;
    cout<<"Maximum Value : "<<maxNum<<endl;

    return 0;
}
