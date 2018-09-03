#include <iostream>
#include <string>

using namespace std;

string firstLargestEvenWord(string compare)
{
    string word, largestEven;
    for(int i=0; i < compare.size(); i++)
    {
        //'.' is a delimiter
        if(compare[i]!=' ' && compare[i] != '.') word+=compare[i];

        else
        {
            if(word.size()%2 == 0 && word.size() > largestEven.size()){
                largestEven.clear();
                largestEven = word;
                word.clear();
            }
            else word.clear();
        }
    }
    return largestEven;
}

int main()
{
    string inputSentence;
    cout<<"Enter a sentence: ";
    getline(cin, inputSentence);

    cout<<endl<<"First largest even word in a sentence is: "
        <<firstLargestEvenWord(inputSentence);
}
