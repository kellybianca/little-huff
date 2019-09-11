# Test installation and compilation using CUnit

To use the CUnit testing framework in this project, we need to install the libraries. In the Ubuntu:

```
$ sudo apt-get install libcunit1 libcunit1-doc libcunit1-dev 
```

And include in the test file:

```
#include <CUnit/CUnit.h> 
```

To make sure everything is working fine, you should add the –lcunit flag to the gcc command:

```
$ gcc file.c -o file -lcunit
```
