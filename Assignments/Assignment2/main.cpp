#include "queue.cpp"
#include <iomanip>

string clean_input(string);

//Bigrams with queues instead of stacks
int main(){
    //------ UI IMPLEMENTATION -----
    string input = "";

    //Gets user input
    cout << "Input: ";
    getline(cin, input);
    cout << endl;

    //Clean the input to remove spaces, punctuation and makes everything uppercase
    input = clean_input(input);

    Queue queue;
    char bigram[2];
    int result;

    do{
        for (int i = 0; i < input.size();){
            bigram[0] = {input[i]};
            bigram[1] = {input[++i]};

            try{
                if (bigram[1] == '\0'){
                    break;
                }else if (queue.enqueue(bigram) == 0){
                    cout << "Enqueued: " << bigram[0] << bigram[1] << endl;
                }

            }catch(overflow_error &err){
                cout << "Error: " << err.what() << endl << endl;
                break;
            }

        }
        break;
    }while(true);

    queue.status();
    cout << endl << endl;

    do{
        try{
            queue.dequeue(bigram);
        }catch(underflow_error &err){
            cout << "Error: " << err.what() << endl;
            break;
        }
    }while(true);

    queue.status();

    return 0;
}

/////HELPER FUNCTIONS/////

string clean_input(string input){
    // Loop through and remove whitespace, punctuation, and make lowercase
    for (int i = 0, len = input.size(); i < len; i++)
    {
        if (ispunct(input[i]) or isspace(input[i]))
        {
            input.erase(i--, 1);
            len = input.size();
        }else if (islower(input[i])){
            input[i] = toupper(input[i]);
        }
    }

    return input;
}
