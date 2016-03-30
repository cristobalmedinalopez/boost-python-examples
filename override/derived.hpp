#include "base.hpp" 

class Derived : public Base {
 public:
  Derived(){}
  virtual char const* hello()
  {
    return "hello from Derived";
  }

   char const* sayhello()
  {
    return hello();
  }
};
