#include <iostream>
#include <string>

using namespace std;

string largestEven(string compare)
{
    string word, maxEven;
    for(int i=0;i<compare.size();i++)
    {
        if(compare[i]!=' ') word+=compare[i];
        else
        {
            if (word.size()==maxEven.size()) word.clear();
            else if (word.size()<maxEven.size()) word.clear();
            else
            {
                if(word.size()>maxEven.size())
                {
                    maxEven.clear();
                    maxEven=word;
                    word.clear();
                }
            }
        }

    }
    return maxEven;
}

int main()
{
    string words, largest;
    cout<<"Enter a sentence: ";
    getline(cin, words);

    largest=largestEven(words);
    cout<<endl<<"largest is: "<<largest;
}
