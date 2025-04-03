#include <iostream>
using namespace std;

void isComment(){
    string s;
    cout<<"Input: ";
    getline(cin, s);

    for(int i=0; ; i++){
        if(s[i] == '\\0'){
            break;
        }
        else if(s[i] == '/' && s[i+1] == '/'){
            cout<<"It is a single line comment!";
            return;
        }
        else if(s[i] == '/' && s[i+1] == '*'){
            cout<<"It is a multi line comment!";
            return;
        }
    }
    cout<<"It's not a comment!";
}

int main()
{
    isComment();
    return 0;
}
