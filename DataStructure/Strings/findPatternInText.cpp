#include <bits/stdc++.h>
using namespace std;

bool areSame(int a[], int b[])
{
    for (int i = 0; i < 256; i++)
    {
        if (a[i] != b[i])
        {
            return false;
        }
    }
    return true;
}

bool findPatternInText(string pat, string text)
{
    int textCount[256] = {0}, patternCount[256] = {0};

    for (int i = 0; i < pat.length(); i++)
    {
        textCount[text[i]]++;
        patternCount[pat[i]]++;
    }
    for (int i = pat.length(); i < text.length(); i++)
    {
        if (areSame(textCount, patternCount))
        {
            return true;
        }
        textCount[text[i]]++;
        textCount[text[i - pat.length()]]--;
    }
    return false;
}

int main()
{

    string text, pattern;
    cin >> text >> pattern;
    cout << findPatternInText(pattern, text);

    return 0;
}
