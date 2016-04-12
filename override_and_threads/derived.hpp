#include <iostream>
#include <vector>
#include "base.hpp" 

class Derived : public Base {
 public:
  Derived(){}
  virtual int hello(std::vector<char> &message)
  {
   for(int i=0; i<message.size(); ++i)
      std::cout << message[i] << ' ';
    return 2;
  }

  int sayhello()
  {
    char test[] = "Hello";
    std::vector<char> message(test, test + sizeof(test)/sizeof(*test));
    return hello(message);
  }
};
