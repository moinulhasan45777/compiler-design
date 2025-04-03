#include <iostream>

using namespace std;

int main()
{
    char firstName[20];
    char lastName[20];
    for(int i = 0; i < 20; i++){
        firstName[i] = '$';
        lastName[i] = '$';
    }

    cout<<"First Name : ";
    gets(firstName);

    cout<<"Last Name : ";
    gets(lastName);


    for(int i = 0; i<20; i++){
        if((((int)firstName[i] >= 65 && (int)firstName[i] <= 90) || ((int)firstName[i] >= 97 && (int)firstName[i] <= 122)) && firstName[i] != '$'){
            cout<<firstName[i];
        }
    }

    cout<<" ";

    for(int i = 0; i<20; i++){
        if((((int)lastName[i] >= 65 && (int)lastName[i] <= 90) || ((int)lastName[i] >= 97 && (int)lastName[i] <= 122)) && lastName[i] != '$'){
            cout<<lastName[i];
        }
    }
    return 0;
}
