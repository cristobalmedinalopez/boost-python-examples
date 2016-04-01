#include <iostream>
#include<vector>

class Base {
 public:
  Base(){}
  virtual int hello(std::vector<std::string> messages)
  {
    std::cout << messages[0] << std::endl;
    return 1;
  }
    
  char const* bye()
  {
    return "bye!";
  }
 
};


