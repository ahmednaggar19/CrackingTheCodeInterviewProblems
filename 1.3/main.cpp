#include <iostream>

using namespace std;

int countIntraSpaces(string s, int trueLength) {
   int spacesCounter = 0;
   for (int i = 0; i < trueLength; i++) {
        if (s[i] == ' ') spacesCounter++;
   }
   return spacesCounter;
}

string replaceSpaces(string s, int trueLength) {
    string modifiedString = "";
    string spaceReplacement = "%20";
    int counter = countIntraSpaces(s, trueLength);
    int lastIndex = trueLength + counter * 2;
    for (int i = trueLength - 1; i  >= 0; i--) {
        if (s[i] == ' ') {
            s[lastIndex - 1] = '0';
            s[lastIndex - 2] = '2';
            s[lastIndex - 3] = '%';
            lastIndex -= 3;
        } else {
            s[lastIndex - 1] = s[i];
            lastIndex--;
        }
    }
    return s;
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
