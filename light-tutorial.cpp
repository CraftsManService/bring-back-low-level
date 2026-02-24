#include <iostream>
#include <string>

typedef std::string string;

int main() {
  std::cout<<"Hello C++!\n";
  int response;
  while(!std::cin >> response) {
    std::cout<<"Invalid INPUT!\n";
  }

}
