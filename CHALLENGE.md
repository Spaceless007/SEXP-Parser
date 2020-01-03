# Challenges: Software Developer

## Challenge 1: S-expression parser

This challenge is close to what your first mission would look like working at GHGSat. This is thus a very good way for us to assess your skills, and for you to understand the software stack we are using.

Write a simple C or C++ program which:

* parses s-expression file given as input, it shall successfully parses example.sexp as a representation-object; this object should give an easy access to the different attributes on different levels; for example, the nlohmann/JSON library allows to create an object ; This requirement is not to support any object type but at least the example object given in example.sexp; e.g. this s-expression file could be parsed into following object:

```c++
class Capture {
  string header;
  string id;
  string name;
  date timestamp;
  class capture_settings;
  class coordinates;
};
```

* print on stdout each element, its data-type and value, e.g.

```c++
Capture type:object
    header type:string value:"image-01.raw"
    id type:string value:"6zlQW000LK"
    name type:string value:"1KDVQwb"
    timestamp type:string value:"2019-10-23T11:50:04-04:00"
    capture_settings type:object value: [...]
    coordinates type:object value: [...]
```

* is built from a Makefile or CMake with x86 and ARM targets
* can run on a Raspberry Pi, or Beaglebone or ARM qemu emulator on a Linux desktop

Above items are normally listed in ascending order of complexity. It's ok not to complete all of them, make your best.

Please make your best to complete this assignment within 72h, and provide following elements with your answer:
* your source code pushed to a public repository (preferrably **not** as email attachment),
* a README.md describing how to build your project,
* some instructions how to run it on the chosen hardware or emulator environment
* a quick review how you went through this assignment: method, research, problems you faced?
* what would do to improve this software if you were given more time?
