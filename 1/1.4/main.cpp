#include <iostream>
#include <map>
#include <algorithm>
#include <string>

using namespace std;


string lowerCase(string s) {
    for (int i = 0; i < s.length(); i++) {
        s[i] = tolower(s[i]);
    }
    return s;
}

/**
* Assuming that palindromes ignore spaces.
*/
bool isPermutationOfPalindrome(string s) {
    s = lowerCase(s);
    map <char, int> repititions;
    for (int i = 0; i < s.length(); i++) {
        repititions[s[i]]++;
    }
    int numberOfOddRepeatedChars = 0;
    for (int i = 0; i < s.length(); i++) {
        if (repititions[s[i]] % 2 != 0 && isalpha(s[i])) {
            numberOfOddRepeatedChars++;
        }
    }
    return (numberOfOddRepeatedChars <= 1);
}

int main()
{
    string s;
    getline(cin, s);
    cout << isPermutationOfPalindrome(s);
    return 0;
}
