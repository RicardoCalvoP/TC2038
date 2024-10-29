// Ricardo Alfredo Calvo Pérez - A01028889
// Finding longest substring using dynamic programming
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

// Function to find the longest common substring between two strings
string find_longest_common_substring(const string &str1, const string &str2)
{
  int string1_length = str1.size();
  int string2_length = str2.size();
  int max_length = 0;
  int end_index = 0;

  // DP table to store lengths of common substrings
  vector<vector<int>> dp(string1_length + 1, vector<int>(string2_length + 1, 0));

  for (int i = 1; i <= string1_length; i++)
  {
    for (int j = 1; j <= string2_length; j++)
    {
      if (str1[i - 1] == str2[j - 1])
      {
        dp[i][j] = dp[i - 1][j - 1] + 1;
        if (dp[i][j] > max_length)
        {
          max_length = dp[i][j];
          end_index = i; // Store the ending index of the longest substring
        }
      }
    }
  }

  // Extract the longest common substring
  if (max_length == 0)
    return ""; // No common substring found
  cout << "Longest common substring: " << str1.substr(end_index - max_length, max_length) << " at: " << end_index - max_length + 1 << " : " << end_index + 1 << endl;
  return str1.substr(end_index - max_length, max_length);
}