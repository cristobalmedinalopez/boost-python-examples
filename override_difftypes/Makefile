# location of the Python header files

PYTHON_VERSION = 3.4
PYTHON_INCLUDE = /usr/include/python$(PYTHON_VERSION)
# location of the Boost Python include files and library

BOOST_INC = /usr/include
BOOST_LIB = /usr/lib

# compile mesh classes
TARGET = python
MODULE_NAME = inheritance

$(TARGET).so: $(TARGET).o
	g++ -shared -Wl,-soname,$(MODULE_NAME).so -o $(MODULE_NAME).so $(TARGET).o -lboost_python

$(TARGET).o: $(TARGET).cpp
	g++ -I$(PYTHON_INCLUDE) -c -fPIC $(TARGET).cpp -o $(TARGET).o
clean:
	rm  $(TARGET).o $(MODULE_NAME).so
