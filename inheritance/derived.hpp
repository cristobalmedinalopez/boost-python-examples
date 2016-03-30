#include "base.hpp" 

class Derived : public Base {
 public:

  char const* hello()
  {
    return "hello from Derived";
  }
};
