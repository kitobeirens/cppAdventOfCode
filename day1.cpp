#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int main() {
  ifstream inputFile("input.txt");
  if (!inputFile.is_open()) {
    cerr << "Error opening file\n";
    return 1;
  }
  string line;
  int currentNumber = 50;
  int count = 0;

  while (getline(inputFile, line)) {
    char dir = line[0];
    int num = stoi(line.substr(1));
    if (dir == 'R') {
      currentNumber = currentNumber + num;
      while (currentNumber > 99) {
        currentNumber = currentNumber - 100;
        count++;
      }
    }
    if (dir == 'L') {
      currentNumber = currentNumber - num;
      while (currentNumber < 0) {
        currentNumber = currentNumber + 100;
        count++;
      }
    }
  }
  cout << "count: " << count << '\n';
  inputFile.close();
  return 0;
}
