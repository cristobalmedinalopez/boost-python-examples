#include <boost/python.hpp>

#include "derived.hpp"
#include<vector>

using namespace boost::python;

class releaseGIL{
public:
    inline releaseGIL(){
        save_state = PyEval_SaveThread();
    }

    inline ~releaseGIL(){
        PyEval_RestoreThread(save_state);
    }
private:
    PyThreadState *save_state;
};

class AcquireGIL 
{
public:
    inline AcquireGIL(){
        state = PyGILState_Ensure();
    }

    inline ~AcquireGIL(){
        PyGILState_Release(state);
    }
private:
    PyGILState_STATE state;
};

class DerivedWrap : public Derived, public wrapper<Derived>
{
public:
  DerivedWrap () : Derived (){}
  //
  int hello(std::vector<char> message){
    if (override hello = this->get_override("hello")){
      boost::python::list message_;
      for (int i=0;i<message.size();i++)
	message_.append(message[i]);
      return hello(message_);
      }
      
    return Derived::hello(message);
  }

  void bye(){
    //PyThreadState *m_thread_state = PyEval_SaveThread();
    AcquireGIL lock;
    Base::bye();
    releaseGIL unlock;
    //PyEval_RestoreThread(m_thread_state);
  }
 
};

BOOST_PYTHON_MODULE(inheritance)
{
    PyEval_InitThreads();
    class_<Base, boost::noncopyable>("Base")
      .def("hello", &Base::hello)
      .def("bye", &Base::bye)
      ;
    class_<DerivedWrap, bases<Base>, boost::noncopyable >("Derived")
      .def("hello", &DerivedWrap::hello)
      .def("sayhello", &DerivedWrap::sayhello)
      ;
}
