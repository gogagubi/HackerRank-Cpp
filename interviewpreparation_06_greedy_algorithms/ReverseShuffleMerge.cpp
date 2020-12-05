#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    string reverseShuffleMerge(string s) {
        const int n = s.length();
        const int alphaSize = 26;
        const int bufferLength = n / 2;

        int counts[alphaSize] = {0};
        for (int i = 0; i < n; i++) counts[s[i] - 'a']++;

        int required[alphaSize] = {0};
        for (int i = 0; i < alphaSize; i++) required[i] = counts[i] / 2;

        int used[alphaSize] = {0};
        int ind = 0;

        char buffer[bufferLength];
        for (int i = n - 1; i >= 0; i--) {
            char curr = s[i];
            int ascii = curr - 'a';

            if (used[ascii] < required[ascii]) {
                while (ind > 0 && curr < buffer[ind - 1]
                       && used[buffer[ind - 1] - 'a'] + counts[buffer[ind - 1] - 'a']
                          > required[buffer[ind - 1] - 'a']) {
                    used[buffer[ind - 1] - 'a']--;
                    ind--;
                }

                buffer[ind++] = curr;
                used[curr - 'a']++;
            }

            counts[ascii]--;
        }

        string result(buffer, bufferLength);
        return result;
    }
};


int main() {

    if (true) {
        Solution *o = new Solution();
        string s = "abab";
        string result = o->reverseShuffleMerge(s);
        cout << "Result " << result << " Correct: " << (result == "ab") << endl;
    }

    if (true) {
        Solution *o = new Solution();
        string s = "eggegg";
        string result = o->reverseShuffleMerge(s);
        cout << "Result " << result << " Correct: " << (result == "egg") << endl;
    }

    if (true) {
        Solution *o = new Solution();
        string s = "abcdefgabcdefg";
        string result = o->reverseShuffleMerge(s);
        cout << "Result " << result << " Correct: " << (result == "agfedcb") << endl;
    }

    if (true) {
        Solution *o = new Solution();
        string s = "djjcddjggbiigjhfghehhbgdigjicafgjcehhfgifadihiajgciagicdahcbajjbhifjiaajigdgdfhdiijjgaiejgegbbiigida";
        string result = o->reverseShuffleMerge(s);
        cout << "Result " << result << " Correct: " << (result == "aaaaabccigicgjihidfiejfijgidgbhhehgfhjgiibggjddjjd")
             << endl;
    }

    if (true) {
        Solution *o = new Solution();
        string s = "sbcnzxqnrygkocahxjebvueaawwcythjdrhvizqsshgtwdolmillxpshxpxqrywkivceufclhydhshrklkphajbftuapiocjlcthfirhgaohfysqjolssbzhbovdstbyqdpnjbpfmgqrzfctcwcrztvgbegunarvecseoulabaonguckqbtrvuagreyclyjytpvozqdnhldlnsocenuzksawirgsbjobpldjdlrxbricrauuksbmecvvwagnnacaqghmjpzrlsvlpbbcuaddgvlhvuvkxexjcfhxrodmcwlrzyyiksuksshhonahsyzbbprwuitmoyoqurtqsaslevgvpfbzkkhgcnpjdpseuiylluvdetsqssbrxpiclxxvosuqipsqvvwsezhl";

        string result = o->reverseShuffleMerge(s);
        cout << "Result " << result << " Correct: " << (result ==
                                                        "aaaaaavvcembskuabxddlpbbsgiaskucosdlhndqzovpjlcyerauvrbcugnbluescevrnubgvtzrcwccfzrqgmfpbjnpdqybtsdvobhzsslojqsyfhoghrifhtclcoiputjhpklkrhsdyhlcuevikwyrqxpxhspxllimlowtghssqzivhrjtywweuvejxokgyrnqxzns")
             << endl;
    }

    return 0;
}