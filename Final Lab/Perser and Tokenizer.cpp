#include <iostream>
#include <fstream>
#include <istream>

using namespace std;


int index = 0;


//Variables to count items
int lineCount = 0;
int headerCount = 0;
int errorCount = 0;
int punctuationCount = 0;
int keywordCount = 0;


int tempPunctuation = 0;
int tempKeyword = 0;
string keywordList[10];
char punctuationList[10];


int mainFound = 0;

//Function to skip any front spaces
void skipFrontSpaces(string sourceCode){
    index = 0;
    int deletedSpaces = 0;
    for(int i = 0; i<sourceCode.length(); i++){
        if(sourceCode[i] == ' '){
            index = index+1;
            deletedSpaces = deletedSpaces + 1;
        }
        else if(sourceCode[i] == '\t'){
            index = index+1;
            deletedSpaces = deletedSpaces + 4;
        }
        else{
            cout << "Front Spaces Deleted: " << deletedSpaces <<endl;
            return;
        }
    }
    cout << "Spaces Deleted: " << deletedSpaces <<endl;
}



//Function to check dependencies
bool isHeader(string sourceCode){

    string header;
    ifstream ReadFile("headers.txt");

    getline(ReadFile, header);
    ReadFile.close();


    //If the first word is '#include' then check the rest of the line for header file
    if(sourceCode[index] == '#' && sourceCode[index+1] == 'i' && sourceCode[index+2] == 'n' && sourceCode[index+3] == 'c' && sourceCode[index+4] == 'l'
       && sourceCode[index+5] == 'u' && sourceCode[index+6] == 'd' && sourceCode[index+7] == 'e')
    {
        int k = 0;

        //Loop to move the index after '<' if '<' is found
        for(int i = index+8; i<sourceCode.length(); i++){
            if(sourceCode[i] == ' ' || sourceCode[i] == '\t'){
                index = i+1;
            }
            else if(sourceCode[i] == '<'){
                index = i+1;
                break;
            }
            else{
                cout<<"Error! '<' expected after '#include'"<<endl;
                errorCount = errorCount + 1;
                index = 0;
                return 0;
            }
        }



        //Loop to check the end of a header file
        for(int i=index; i<sourceCode.length();){
            if(sourceCode[i] == header[k]){
                if(sourceCode[i+1] == '>' && (header[k+1] == ',' || header[k+1] == '\0')){
                    cout<<"Header File Found!!!"<<endl;
                    headerCount = headerCount + 1;
                    index = 0;
                    return 1;
                }
                i = i+1;
                k = k+1;
                continue;
            }
            else{
                for(int p = k; p<header.length(); p++){
                    if(header[p] == ','){
                        k = p+1;
                        i = index;
                        break;
                    }
                    else if(header[p] == header.back()){
                        index = 0;
                        cout<<"No Such Header File Found!!!"<<endl;
                        errorCount = errorCount + 1;
                        return 0;
                    }
                }
            }
        }
    }
    else{
            return 0;
    }
}


//Checking Namespace
bool isNamespace(string sourceCode){
    if(sourceCode[index] == 'u' && sourceCode[index+1] == 's' && sourceCode[index+2] == 'i' && sourceCode[index+3] == 'n'
       && sourceCode[index+4] == 'g'){
        index = index+5;
        for(int i = index; i<sourceCode.length(); i++){
            if(sourceCode[i] == ' ' || sourceCode[i] == '\t'){
                index = index+1;
            }
            else{
                break;
            }
        }

        if(sourceCode[index] == 'n' && sourceCode[index+1] == 'a' && sourceCode[index+2] == 'm' && sourceCode[index+3] == 'e' &&
           sourceCode[index+4] == 's' && sourceCode[index+5] == 'p' && sourceCode[index+6] == 'a' && sourceCode[index+7] == 'c' &&
           sourceCode[index+8] == 'e'){
            index = index+9;
            for(int i = index; i<sourceCode.length(); i++){
                if(sourceCode[i] == ' ' || sourceCode[i] == '\t'){
                    index = index+1;
                }
                else{
                    break;
                }
            }


            if(sourceCode[index] == 's' && sourceCode[index+1] == 't' && sourceCode[index+2] == 'd'){
                index = index+3;
                for(int i = index; i<sourceCode.length(); i++){
                    if(sourceCode[i] == ' ' || sourceCode[i] == '\t'){
                        index = index+1;
                    }
                    else{
                        break;
                    }
                }

                if(sourceCode[index] == ';'){
                    punctuationCount = punctuationCount + 1;
                    cout<<"Namespace declaration found!"<<endl;
                    cout<<"';' found as punctuation"<<endl;
                    return 1;
                }
                else{
                    cout<<"Namespace declaration found!"<<endl;
                    cout<<"Error! Missing ';' at the end"<<endl;
                    errorCount = errorCount + 1;
                    return 1;
                }
            }
            else{
                cout<<"Error! Wrong namespace declaration."<<endl;
                errorCount = errorCount + 1;
                return 0;
            }
        }
        else{
            cout<<"Error! Wrong namespace declaration."<<endl;
            errorCount = errorCount + 1;
            return 0;
        }
    }
    else{
        return 0;
    }
}



//Checking Identifier
bool isIdentifier(string input_string){

    string file_string;

    int indexID = 0;   //Tracking the index of the input string

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

    indexID = i;

    indexHelper = i;




    ifstream ReadFile("ds.txt");        //Opening the file

    getline(ReadFile, file_string);     //Reading and Storing the file contents in file_string variable

    ReadFile.close();                   //Closing the opened file




    //Iterating through every character of file_string variable

    for(int l = 0; l < file_string.length(); l++){

        //Checking if the characters of file_string and input_string matches with each other

        if(file_string[l] == input_string[indexID]){

            //Checking whether the index of the input_string reached the last index while matching with the file_string

            if(indexID == input_string.length()-1){

                cout<<"Invalid Identifier! Identifier cannot be a keyword!"<<endl;
                return 0;

            }

            //If last index have not reached then, add 1 to the previous index value

            else{

                indexID = indexID+1;

            }

        }

        //If the character does not match make index = 0

        else{

            indexID = i;

        }

    }




    int camelCase = 0, snakeCase = 0;

    //Checking if the first character is a number

    if((int)input_string[indexHelper] >= 48 && (int)input_string[indexHelper] <= 57){

        cout<<"Invalid Identifier! The first character cannot be a number!"<<endl;

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

                cout<<"Invalid Identifier! Identifier cannot contain any special character! (E.G !,@,#,$,&,*,^)"<<endl;

                return 0;

        }

        //Checking if the string has any spaces.

        else if(input_string[i] == ' '){                               //Checking

            cout<<"Variable name cannot contain any spaces!"<<endl;

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


//Checking Keyword
bool isKeyword(char tempArray[], int tempIndex){
    string keywords;
    int subIndex = 0;

    ifstream ReadFile("keyword.txt");

    getline(ReadFile, keywords);
    ReadFile.close();



    for(int i = 0; i<keywords.length(); i++){
        if(tempArray[subIndex] == keywords[i]){
            if((tempIndex-subIndex == 1) && keywords[i+1] == ','){
                return true;
            }

            else if((tempIndex - subIndex > 1) && keywords[i+1] == ','){
                i = i+2;
                subIndex = 0;
                continue;
            }

            else if((tempIndex - subIndex == 1) && keywords[i+1] != ','){
                subIndex = 0;
                while(keywords[i] != ','){
                    i = i+1;
                }
                continue;
            }
            else{
                subIndex = subIndex + 1;
            }

        }
        else{
            subIndex = 0;
            while(keywords[i] != ','){
                i = i+1;
            }
        }
    }
    return false;
}



//Find main function
void findMain(string sourceCode){

    if(mainFound == 1 && sourceCode[index] != '{'){
        errorCount = errorCount + 1;
        cout<<"Error! Expected '{' after main()"<<endl;
    }
    else if(mainFound == 1 && sourceCode[index] == '{'){
        punctuationList[tempPunctuation] = '{';
        tempPunctuation = tempPunctuation + 1;
        mainFound = 2;
    }

    if(sourceCode[index] == 'i' && sourceCode[index+1] == 'n' && sourceCode[index+2] == 't'){
        index = index+3;
        keywordList[tempKeyword] = "int";
        tempKeyword = tempKeyword + 1;
        keywordCount = keywordCount + 1;

        for(int i = index; i<sourceCode.length(); i++){
            if(sourceCode[i] == ' ' || sourceCode[i] == '/t'){
                continue;
            }
            index = i;

            if(sourceCode[index] == 'm' && sourceCode[index+1] == 'a' && sourceCode[index+2] == 'i' && sourceCode[index+3] == 'n' &&
               sourceCode[index+4] == '(' && sourceCode[index+5] == ')'){

                mainFound = 1;

                index = index+6;
                keywordList[tempKeyword] = "main";
                tempKeyword = tempKeyword+1;
                keywordCount = keywordCount + 1;

                punctuationList[tempPunctuation] = '(';
                tempPunctuation = tempPunctuation + 1;
                punctuationCount = punctuationCount + 2;
                punctuationList[tempPunctuation] = ')';
                tempPunctuation = tempPunctuation + 1;


                for(int k = index; k<sourceCode.length(); k++){
                    if(sourceCode[k] == ' ' || sourceCode[k] == '\t'){
                        continue;
                    }
                    index = k;
                    if(sourceCode[k] == '{'){
                        punctuationList[tempPunctuation] = '{';
                        tempPunctuation = tempPunctuation + 1;
                        mainFound = 2;
                    }
                    else{
                        return;
                    }
                }
            }
        }
    }

    else
        return;

}





//Tokenize String -----------------------------------------------------------------------------------------
void tokenizeString(string sourceCode){
    char tempArray[100];
    int tempIndex = 0;
    tempKeyword = 0;
    tempPunctuation = 0;
    string tempString = "";

    for(int i = index; i<sourceCode.length(); i++){
        string tempString = "";

        if(sourceCode[i] != ' ' && sourceCode[i] != '/t'){
            tempArray[tempIndex] = sourceCode[i];
            tempIndex = tempIndex+1;
        }
        else if(tempIndex > 0){

            for(int z = 0; z<tempIndex; z++){
                tempString = tempString + tempArray[z];
            }

            if(isKeyword(tempArray,tempIndex)){
                keywordList[tempKeyword] = tempArray[0];
                for(int z = 1; z<tempIndex; z++){
                    keywordList[tempKeyword] = keywordList[tempKeyword] + tempArray[z];
                }
                tempKeyword = tempKeyword+1;
                tempIndex = 0;
            }

            else if(isIdentifier(tempString)){

            }
        }
    }
}



int main()
{
    int pivot = 0;
    string sourceCode;
    ifstream ReadFile("sourceCode.txt");

    while(getline(ReadFile, sourceCode)){

        if(sourceCode.length() == 0)
            continue;


        tempKeyword = 0;
        tempPunctuation = 0;
        for(int i = 0; i<10; i++){
            keywordList[i] = "$";
            punctuationList[i] = '$';
        }

        lineCount = lineCount+1;
        cout<< lineCount<<"|";
        cout<<sourceCode<<endl;

        skipFrontSpaces(sourceCode);

        if(isHeader(sourceCode)){
            cout<<"\n\n"<<endl;
            continue;
        }

        if(isNamespace(sourceCode)){
            cout<<"\n\n"<<endl;
            continue;
        }

        if(mainFound != 2){

            findMain(sourceCode);

            cout<<"Keywords Found: ";
            for(int i = 0; i<10; i++){
                if(keywordList[i] != "$"){
                    cout<<keywordList[i];
                }
                else
                    break;

                if(i+1 < 10 && keywordList[i+1] != "$")
                    cout<<", ";

            }

            cout<<endl;

            cout<<"Punctuation Found: ";
            for(int i = 0; i<10; i++){
                if(punctuationList[i] != '$'){
                    cout<<punctuationList[i];
                }
                else
                    break;

                if(i+1 < 10 && punctuationList[i+1] != '$')
                    cout<<"     ";
            }
        }
        else{
            tokenizeString(sourceCode);

            cout<<"Keywords Found: ";
            for(int i = 0; i<10; i++){
                if(keywordList[i] != "$"){
                    cout<<keywordList[i];
                }
                else
                    break;

                if(i+1 < 10 && keywordList[i+1] != "$")
                    cout<<", ";

            }

            cout<<endl;

            cout<<"Punctuation Found: ";
            for(int i = 0; i<10; i++){
                if(punctuationList[i] != '$'){
                    cout<<punctuationList[i];
                }
                else
                    break;

                if(i+1 < 10 && punctuationList[i+1] != '$')
                    cout<<"     ";
            }
        }

        cout<<"\n\n"<<endl;
    }

    ReadFile.close();

    cout<<"\n\n\nHeader File Count : "<< headerCount<<endl;
    cout<<"Punctuation Count: "<<punctuationCount<<endl;
    cout<<"Keyword Count: "<<keywordCount<<endl;
    cout<<"Errors: "<< errorCount<<endl;
}
