"""
pyderived module
"""

from inheritance import Derived
import threading
import time

class PyDerived(Derived):

    def __init__(self):
        Derived.__init__(self)

    def hello(self, message):
        print(message)
        return 3

if __name__ == "__main__":
    from pyderived import PyDerived
    a = PyDerived()
    a.hello("Hola")
    threading.Thread(target=a.bye, args=()).start();
    for x in range(1,10):
        time.sleep(1)
        print ("Python")
