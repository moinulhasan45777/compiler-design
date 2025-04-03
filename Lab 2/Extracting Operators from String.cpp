#include <iostream>
using namespace std;

void isOperator(){
    string input;
    int operatorCount = 1;
    cout<<"Input: ";
    getline(cin, input);

    for(int i=0; ; i++){
        if(input[i] == '\0'){
            return;
        }

        switch(input[i]){
            case '+':
                cout<<"operator"<<operatorCount<<": "<<input[i]<<endl;
                operatorCount = operatorCount + 1;
                break;
            case '-':
                cout<<"operator"<<operatorCount<<": "<<input[i]<<endl;
                operatorCount = operatorCount + 1;
                break;
            case '*':
                cout<<"operator"<<operatorCount<<": "<<input[i]<<endl;
                operatorCount = operatorCount + 1;
                break;
            case '/':
                cout<<"operator"<<operatorCount<<": "<<input[i]<<endl;
                operatorCount = operatorCount + 1;
                break;
            case '%':
                cout<<"operator"<<operatorCount<<": "<<input[i]<<endl;
                operatorCount = operatorCount + 1;
                break;
            case '=':
                cout<<"operator"<<operatorCount<<": "<<input[i]<<endl;
                operatorCount = operatorCount + 1;
                break;
            default:
                break;
        }
    }
}

int main()
{
    isOperator();
    return 0;
}
