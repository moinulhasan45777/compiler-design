#include <iostream>
#include <fstream>
using namespace std;


//Function for checking if the Identifier name is valid
bool isValidIdentifier(string input_string){

    //String for storing all the keywords as a single string from a text file
    string file_string;
    int index = 0;   //Tracking the index of the input string
    int i = 0;
    int indexHelper=0;



    //Ignoring the spaces present at the front of the Identifier
    for(int z = 0; z<input_string.length(); z++){
        if(input_string[z] == ' '){
            i = i+1;
        }
        else{
            indexHelper = 0;
            break;
        }
        indexHelper = -1;
    }

    if(indexHelper == -1){
        cout<<"No Variable Name Detected!!!"<<endl;
        return 0;
    }

    index = i;
    indexHelper = i;






    ifstream ReadFile("ds.txt");        //Opening the file
    getline(ReadFile, file_string);     //Reading and Storing the file contents in file_string variable

    ReadFile.close();                   //Closing the opened file






    //Iterating through every character of file_string variable
    for(int l = 0; l < file_string.length(); l++){

        //Checking if the characters of file_string and input_string matches with each other
        if(file_string[l] == input_string[index]){

            //Checking whether the index of the input_string reached the last index while matching with the file_string
            if(index == input_string.length()-1){
                cout<<"Variable name cannot be a keyword!"<<endl;
                return 0;
            }

            //If last index have not reached then, add 1 to the previous index value
            else{
                index = index+1;
            }

        }

        //If the character does not match make index = 0
        else{
            index = i;
        }
    }






    int camelCase = 0, snakeCase = 0;

    //Checking if the first character is a number
    if((int)input_string[indexHelper] >= 48 && (int)input_string[indexHelper] <= 57){
        cout<<"The first character cannot be a number!"<<endl;
        return 0;
    }


    //Checking if the first character is small letter
    if((int)input_string[indexHelper] >= 97 && (int)input_string[indexHelper] <= 122)
        camelCase = 2;

    //If not small character then, Checking if the first character is underscore
    else if(input_string[indexHelper] == '_'){
        camelCase = 3;
    }

    else
        camelCase = 0;






    //Iterating through the whole string
    for(; i<input_string.length(); i++){

        //Checking if the string has any special character e.g $,%,@,#,!,*,%.
        if(((int)input_string[i] >= 33 && (int)input_string[i] <= 47) || ((int)input_string[i] >= 58 && (int)input_string[i] <= 64)
           || ((int)input_string[i] >= 91 && (int)input_string[i] <= 94) || ((int)input_string[i] >= 123 && (int)input_string[i] <= 128) && (int)input_string[i] != '_' ){

                cout<<"Variable name cannot contain any special character! (E.G !,@,#,$,&,*,^)"<<endl;
                return 0;
        }

        //Checking if the string has any spaces.
        else if(input_string[i] == ' '){                               //Checking
            cout<<"Variable name cannot contain any spaces !"<<endl;
            return 0;
        }

        //Checking if the identifier name is in snake case
        else if(input_string[indexHelper] != '_' && input_string[i] == '_' && i != indexHelper){
            snakeCase = 1;
        }

        //Checking if the identifier name is in camel case
        else if((int)input_string[i] >= 65 && (int)input_string[i] <= 90 && i != indexHelper && camelCase == 2 && snakeCase==0){
            camelCase = 1;
        }
    }






    //Printing the outputs for the conditions mentioned below

    /* "camelCase = 0" means the identifier name is not camel case.
       "camelCase = 1" means the identifier name is camel case.
       "camelCase = 2" means the identifier name's first character is small letter.
       "camelCase = 3" means the identifier name's first character is underscore.

       "snakeCase = 0" means the identifier name is snake case.
       "snakeCase = 1" means the identifier name is snake case.
    */

    if(camelCase == 1){
        cout<<"The Variable name is in camel_case which is conventional!"<<endl;
        return 1;
    }

    else if(camelCase == 2){
        if(snakeCase == 1){
            cout<<"The Variable name is in snake_case which is conventional!"<<endl;
            return 1;
        }
        else{
            cout<<"The Variable name is in a conventional format!"<<endl;
            return 1;
        }

    }

    else if(camelCase == 3){
        cout<<"The Variable name is in a conventional format!"<<endl;
        return 1;
    }

    else{

        if(snakeCase == 1){
            cout<<"The Variable name is in snake_case which is conventional!"<<endl;
            return 1;
        }
        else{
            cout<<"The Variable name is in an unconventional format!"<<endl;
            return 1;
        }

    }
}


//Driver Function
int main()
{
    //Variable for storing the input
    string input_string;

    //Taking the input from user
    cout<<"Enter a Variable Name: ";
    getline(cin, input_string);

    //Calling the isValidIndentifier() function and printing the boolean return value
    cout<<isValidIdentifier(input_string);

    return 0;
}
