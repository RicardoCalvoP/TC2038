#include "filesFunctions.h"
#include <iostream>
using namespace std;

int main()
{
  system("cls");
  // Transmission files to compare
  string transmission_files[2] = {
      "../TestDocuments/transmission1.txt",
      "../TestDocuments/transmission2.txt"};

  // Files with malicious code
  string mcode_files[3] = {
      "../TestDocuments/mcode1.txt",
      "../TestDocuments/mcode2.txt",
      "../TestDocuments/mcode3.txt"};
  search_for_coincidences(transmission_files, mcode_files);
  return 0;
}