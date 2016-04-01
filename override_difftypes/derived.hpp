#include <iostream>
#include<vector>
#include "base.hpp" 

class Derived : public Base {
 public:
  Derived(){}
  virtual int hello(std::vector<std::string> messages)
  {
    std::cout << messages[0] << std::endl;
    return 2;
  }

  int sayhello()
  {
    std::vector<std::string> messages;
    messages.push_back("Hola1");
    return hello(messages);
  }
};
