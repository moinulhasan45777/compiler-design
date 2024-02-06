#include <iostream>

using namespace std;


void isNumeric(){
    string input;
    int dotCount = 0;

    cout<<"Input: ";
    getline(cin, input);


    for(int i=0; ; i++){
        if(input[i] == '\0'){
            break;
        }
        if((int)input[i] >= 48 && (int)input[i] <= 57){
            continue;
        }
        else if(input[i] == '.'){
            dotCount = dotCount + 1;
        }
        else{
            cout<<"The value is not numeric!";
            return;
        }
    }

    if(dotCount > 1){
        cout<<"The value is not numeric!";
    }
    else{
        cout<<"The value is numeric!";
    }
}

int main()
{
    isNumeric();
    return 0;
}
