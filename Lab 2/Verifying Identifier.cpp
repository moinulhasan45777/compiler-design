#include <iostream>
using namespace std;

void isIdentifier(){
    string input;

    cout<<"Input: ";
    getline(cin, input);

    if(((int)input[0] >= 65 && (int)input[0] <= 90 ) || ((int)input[0] >= 97 && (int)input[0] <= 122) || input[0] == '_'){
        for(int i = 1; ; i++){
            if(input[i] == '\0'){
                break;
            }
            else if(((int)input[0] >= 65 && (int)input[0] <= 90 ) || ((int)input[0] >= 97 && (int)input[0] <= 122) || input[0] == '_' || ((int)input[0] >= 48 && (int)input[0] <= 57)){
                continue;
            }
            else{
                cout<<"It's not an Identifier!!!";
                return;
            }
        }
        cout<<"It's an Identifier!!!";
    }
    else{
        cout<<"It's not an Identifier!!!";
    }
}

int main()
{
    isIdentifier();
    return 0;
}
