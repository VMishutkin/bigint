%module BigInt
%{
/* Includes the header in the wrapper code */
#include "BigInt.h"
%}

%include "std_vector.i"
%include "std_string.i"

/* Parse the header file to generate wrappers */
%include "BigInt.h"
