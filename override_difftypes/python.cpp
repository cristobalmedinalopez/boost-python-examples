#include <boost/python.hpp>

#include "derived.hpp"
#include<vector>

using namespace boost::python;

class DerivedWrap : public Derived, public wrapper<Derived>
{
public:
  DerivedWrap () : Derived (){}
  //
  int hello(std::vector<std::string> messages){
    if (override hello = this->get_override("hello")){
      boost::python::list messages_;
      messages_.append(messages[0]);
      return hello(messages_);
    }
      
    return Derived::hello(messages);
  }
  
};

BOOST_PYTHON_MODULE(inheritance)
{
    class_<Base, boost::noncopyable>("Base")
      .def("hello", &Base::hello)
      .def("bye", &Base::bye)
      ;
    class_<DerivedWrap, bases<Base>, boost::noncopyable >("Derived")
      .def("hello", &DerivedWrap::hello)
      .def("sayhello", &DerivedWrap::sayhello)
      ;
}
