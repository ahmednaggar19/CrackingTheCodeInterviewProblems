#include <iostream>

using namespace std;

int countIntraSpaces(string s) {
    char c = ' ';
    int trailingSpacesCounter = 0;
    int allSpacesCounter = 0;
    for (int i = s.length() - 1; i >= 0; i--) {
        c = s[i];
        if (c != ' ') break;
        trailingSpacesCounter++;
    }
    for (int i = 0; i < s.length(); i++) {
        c = s[i];
        if (c == ' ') {
            allSpacesCounter++;
        }
    }
    return allSpacesCounter - trailingSpacesCounter;
}

string replaceSpaces(string s, int trueLength) {
    string modifiedString = "";
    string spaceReplacement = "%20";
    int counter = countIntraSpaces(s);
    for (int i = 0; i < s.length(); i++) {
        char c = s[i];
        if (modifiedString.length() == (trueLength + counter * 2)) {
            break;
        }
        if (c == ' ') {
            modifiedString.append(spaceReplacement);
        } else {
            modifiedString.push_back(c);
        }
    }
    return modifiedString;
}

int main()
{
    string s;
    getline(cin, s);
    int trueLength;
    cin >> trueLength;
    cout << replaceSpaces(s, trueLength);
    return 0;
}
