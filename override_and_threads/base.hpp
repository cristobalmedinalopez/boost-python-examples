#include <iostream>
#include <vector>

class Base {
 public:
  Base(){}
  virtual int hello(std::vector<char> message)
  {
    for(int i=0; i<message.size(); ++i)
      std::cout << message[i] << ' ';
    return 1;
  }
    
  virtual void bye()
  {
    char test[] = "Hello";
    std::vector<char> message(test, test + sizeof(test)/sizeof(*test));
    for (int i=3; i>0; i--){
      sleep(1);
      hello(message);
      std::cout << i << std::endl;
    }
    std::cout << "bye!" << std::endl;
  }
 
};


