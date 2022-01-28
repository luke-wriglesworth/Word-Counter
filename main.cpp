#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

// Checks if a word is found in a vector and returns true if it is.
// Otherwise returns false.
bool isFound(vector<string> v, string word)
{
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] == word)
        {
            return true;
        }
    }
    return false;    
}

// Will print all the words and the corresponding word count for each one
void printReport(vector<string> v, vector<int> counts)
{
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << ": " << counts[i] << endl;
    }
}

int main()
{
    string word;
    ifstream file;
    file.open("data.txt");
    
    vector<string> words;
    vector<string> unique_words;
    vector<int> counts;

    while (file >> word)
    {
        // Creates vectors of unique and not unique words. 
        // The counts vector is also initialized with zeros.
        words.push_back(word);
        counts.push_back(0);

        if (!isFound(unique_words,word))
        {
            unique_words.push_back(word);
        }
    }

    // For every word in the non-unique list, the word will be compared with the 
    // unique list and a count of one will be added to the counts vector in the 
    // corresponding location every time the words are equal.
    for (int not_unique_index = 0; not_unique_index < words.size(); not_unique_index++)
    {
        for (int unique_index = 0; unique_index < unique_words.size(); unique_index++)
        {
            if (words[not_unique_index] == unique_words[unique_index])
            {
                counts[unique_index]++;
            }
        }
    }

    file.close();
    printReport(unique_words, counts);
    
    return 0;
}