# Js: JSON I/O

Methods for parsing and writing JSON data from C++,
and converting between arbitrary recursive container structures.

This library provides an abstraction of values described by the JSON standard.
It abstracts away the details of how the parsing and serialization are performed, in order to allow the implementation to change without affecting clients. It also adheres to the coding standards of this repository, providing a more consistent interface for developers.

The top-level entrypoints are in ``js/json``

No Python bindings are provided by this library. Use the Python standard
library 'json' module when working with json data in Python.
