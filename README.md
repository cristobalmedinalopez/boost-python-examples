# boost-python-examples
Testing heritage and other concepts of a c++/python wrapper using boost.pyhton

# Build
`$: make`

# Examples
- **hello_world**: a basic example of using boost.python.
  - Use:
  ```
    $: python3
    > import hello
    > hello.hello()
  ``` 

- **inheritance**: a basic example of using inheritance.
  - Use:
  ```
  $: python3
  > import inheritance
  > base = inheritance.Base()
  > derived = inheritance.Derived()
  > base.hello()
  > derived.hello()
  > base.bye()
  > derived.bye()
  ```

- **override**: an example with inheritance and overriding in the python side.
  - Use:
  ```
  $: python3
  > from pyderived import PyDerived
  > a = PyDerived()
  > a.hello()
  > a.sayhello()
 ```

- **override_difftypes**: an example with inheritance and overriding
    in the python side when parameters data types are not compatibles
    between c++ and python.
  - Use:
  ```
  $: python3
  > from pyderived import PyDerived
  > a = PyDerived()
  > a.sayhello()
  ```
