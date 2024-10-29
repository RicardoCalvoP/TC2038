// Ricardo Alfredo Calvo Pérez - A01028889
// This code finds the longest palindromic substring in a given string using Manacher's Algorithm.
// It preprocesses the string to handle palindromes, then expands around each character

#include <iostream>
#include <string>
#include <vector>
using namespace std;

string preprocess_string(string transmission_content)
{
  string processed_string = "#";
  for (char c : transmission_content)
  {
    processed_string += c;
    processed_string += '#';
  }
  return processed_string;
}

void find_inner_palindrome(const string &transmission_content)
{
  string processed_string = preprocess_string(transmission_content);
  int processed_length = processed_string.size();
  vector<int> palindrome_radius(processed_length, 0);
  int current_center = 0, right_boundary = 0;
  int max_palindrome_length = 0, max_palindrome_center = 0;

  for (int index = 0; index < processed_length; index++)
  {
    int mirror_index = 2 * current_center - index;

    if (index < right_boundary)
    {
      palindrome_radius[index] = min(right_boundary - index, palindrome_radius[mirror_index]);
    }

    while (index + palindrome_radius[index] + 1 < processed_length &&
           index - palindrome_radius[index] - 1 >= 0 &&
           processed_string[index + palindrome_radius[index] + 1] == processed_string[index - palindrome_radius[index] - 1])
    {
      palindrome_radius[index]++;
    }

    if (index + palindrome_radius[index] > right_boundary)
    {
      current_center = index;
      right_boundary = index + palindrome_radius[index];
    }

    if (palindrome_radius[index] > max_palindrome_length)
    {
      max_palindrome_length = palindrome_radius[index];
      max_palindrome_center = index;
    }
  }

  int start_position = (max_palindrome_center - max_palindrome_length) / 2;
  int palindrome_length = max_palindrome_length;

  cout << "Longest palindrome: " << transmission_content.substr(start_position, palindrome_length)
       << " at position " << start_position + 1 << " : " << start_position + palindrome_length << endl;
}
