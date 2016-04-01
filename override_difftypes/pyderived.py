"""
pyderived module
"""

from inheritance import Derived

class PyDerived(Derived):

    def __init__(self):
        Derived.__init__(self)

    def hello(self, messages):
        print(messages[0])
        return 3
