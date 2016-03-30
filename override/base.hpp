class Base {
 public:
  Base(){}
  virtual char const* hello()
  {
    return "hello from Base";
  }
    
  char const* bye()
  {
    return "bye!";
  }
 
};


