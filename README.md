# boost-python-examples
Testing heritage and other concepts of a c++/python wrapper using boost.pyhton

# Build
`$: make"

# Examples
- hello_world
A basic example of using boost.python.
  - Use:
    ```
    $: python3
    > import hello
    > hello.hello()
    ``` 

- inheritance
A basic example of using inheritance.
  -Use:
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

