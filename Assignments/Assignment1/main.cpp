#include "stackA.h"
#include "stackA.cpp"

#include "stackB.cpp"
#include "stackB.h"

#include <iostream>
#include <iomanip>
#include <algorithm>
#include <string>

using std::cout, std::cin, std::endl, std::ispunct, std::isupper, std::tolower, std::string;

string clean_input(string);

int main(){
    StackA stackA;
    StackB stackB;
    string input;
    char bigram[2];
    bool flag = true;

    cout << "Input text: ";
    getline(cin, input);

    input = clean_input(input);
    cout << "Cleaned Input: " << input << endl << endl;

    cout << "----- IMPLEMENTATION A -----" << endl;
    
    // Attempts to push onto stack
    while(true) {
        for (int i = 0; i < input.size();){
            try{
                bigram[0] = input[i];
                bigram[1] = input[++i];

                if (bigram[1] == '\0'){
                    break;
                }else if (stackA.push(bigram) == 0){
                    cout << "Pushed: " << bigram[0] << bigram[1] << endl; 
                }
            }catch(overflow_error &error){
                cout << error.what() << endl;
                break;
            }
        }
        break;
    }

    stackA.status();

    while(true){
        try{
            stackA.pop(bigram);
        }catch(underflow_error &error){
            cout << error.what() << endl;
            break;
        }
    }

    cout << endl << "----- IMPLEMENTATION B -----" << endl;

     // Attempts to push onto stack
     // Make stack object a and b 
    while(true) {
        for (int i = 0; i < input.size();){
            try{
                bigram[0] = input[i];
                bigram[1] = input[++i];

                if (bigram[1] == '\0'){
                    break;
                }else if (stackB.push(bigram) == 0){
                    cout << "Pushed: " << bigram[0] << bigram[1] << endl; 
                }
            }catch(overflow_error &error){
                cout << error.what() << endl;
                break;
            }
        }
        break;
    }

    stackB.status();

    while(true){
        try{
            stackB.pop(bigram);
        }catch(underflow_error &error){
            cout << error.what() << endl;
            break;
        }
    }

    return 0;
}

/////

string clean_input(string input){
    // Loop through and remove whitespace, punctuation, and make lowercase
    for (int i = 0, len = input.size(); i < len; i++)
    {
        if (ispunct(input[i]) or isspace(input[i]))
        {
            input.erase(i--, 1);
            len = input.size();
        }else if (isupper(input[i])){
            input[i] = tolower(input[i]);
        }
    }

    return input;
}