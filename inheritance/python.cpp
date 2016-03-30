#include <boost/python.hpp>

#include "derived.hpp"

using namespace boost::python;

BOOST_PYTHON_MODULE(inheritance)
{
    class_<Base, boost::noncopyable>("Base")
      .def("hello", &Base::hello)
      .def("bye", &Base::bye)
      ;
    class_<Derived, bases<Base> >("Derived")
      ;
}
