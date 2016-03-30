#include <boost/python.hpp>

#include "hello.hpp"

BOOST_PYTHON_MODULE(hello)
{
    using namespace boost::python;
    def("hello", hello);
}
