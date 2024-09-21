#include <iostream>
#include <string>
using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) 
    {
        string S;
        cin >> S;
        int consonants = 0, vowels = 0, digits = 0;

        for (char c : S) 
        {
            if (isdigit(c)) 
            {
                digits++;
            } 
            else if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') 
            {
                vowels++;
            } 
            else 
            {
                consonants++;
            }
        }

        int boxes = (consonants + 2) / 3 + (vowels + 1) / 2 + digits;

        cout << boxes << endl;
    }
    return 0;
}
