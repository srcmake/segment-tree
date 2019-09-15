# Segment Trees

Segment Trees are data structures that let you easily find the
minimum, maximum, or sum over a given subrange of a larger range.

I've created a tutorial explaining how segment trees work and the 
process of building/updating/querying one [here](https://www.srcmake.com/home/segment-tree).

This repository contains a C++ class that implements a segment tree for
a minimum (Range Minimum Query) example.

Please note that I've intentionally left the code unoptimized for the 
reader to make better, as this code is meant to be easily understandable
to the viewer, not necessarily the most efficient implementation.

## File Structure

The segment tree code exists as a class in `segment-tree.hpp`. The class
is encapsulated within a namespace of `srcmake` to avoid any collisions
with another library's segment tree. 

(I've also bundled the header file with the cpp file because realistically 
when using a segment tree in an algorithm competition, we just want to be able 
to copy and paste the entire thing without worrying about eloquent file structures.)

`main.cpp` has a single main function that calls the segment-tree class with
some example queries.

## Deployment

The `makefile` will compile the project with C++14 (the version was chosen arbitrarily,
we're not really using any special language features). 

On Linux/Mac, as long as you have GCC, the following command will compile and run the project.

```
make
```

## LICENSE

This code is licensed under the MIT License. 