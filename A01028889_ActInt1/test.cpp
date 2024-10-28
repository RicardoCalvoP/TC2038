#include <iostream>
#include <string>
#include <vector>
using namespace std;

string preprocess(const string &s)
{
  string transformed = "#";
  for (char c : s)
  {
    transformed += c;
    transformed += '#';
  }
  return transformed;
}

void longestPalindrome(const string &s)
{
  string transformed = preprocess(s);
  int n = transformed.size();
  vector<int> p(n, 0); // Array to hold palindrome radius at each center
  int center = 0, right = 0;
  int maxLen = 0, maxCenter = 0;

  for (int i = 0; i < n; i++)
  {
    int mirror = 2 * center - i;

    if (i < right)
    {
      p[i] = min(right - i, p[mirror]);
    }

    // Expand around center `i`
    while (i + p[i] + 1 < n && i - p[i] - 1 >= 0 && transformed[i + p[i] + 1] == transformed[i - p[i] - 1])
    {
      p[i]++;
    }

    // Update center and right boundary if the palindrome expands beyond `right`
    if (i + p[i] > right)
    {
      center = i;
      right = i + p[i];
    }

    // Track the longest palindrome
    if (p[i] > maxLen)
    {
      maxLen = p[i];
      maxCenter = i;
    }
  }

  // Calculate the start position and length of the longest palindrome in the original string
  int start = (maxCenter - maxLen) / 2;
  int length = maxLen;

  // Print the result directly from this function
  cout << "Longest palindrome: " << s.substr(start, length) << " at position "
       << start << " : " << start + length - 1 << endl;
}

int main()
{
  string input = "ABCD123AEA3221DCAED1";
  longestPalindrome(input);
  return 0;
}
