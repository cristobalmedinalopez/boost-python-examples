#include <boost/python.hpp>

#include "derived.hpp"

using namespace boost::python;

class DerivedWrap : public Derived, public wrapper<Derived>
{
public:
  DerivedWrap () : Derived (){}

  char const* hello(){
    if (override hello = this->get_override("hello"))
      return hello();
    return Derived::hello();
  }

  char const* default_hello() { return this->Derived::hello(); }
};

BOOST_PYTHON_MODULE(inheritance)
{
    class_<Base, boost::noncopyable>("Base")
      .def("hello", &Base::hello)
      .def("bye", &Base::bye)
      ;
    class_<DerivedWrap, bases<Base>, boost::noncopyable >("Derived")
      .def("hello", &Derived::hello, &DerivedWrap::default_hello)
      .def("sayhello", &Derived::sayhello)
      ;
}
