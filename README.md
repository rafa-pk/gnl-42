# What are static variables?

## In short:
Static variables have the property of being initialised once and not being destroyed when the value is returned. For instance, if an int variable is initialised with value 0, itterated once and returned, whenever called again, the function will itterate from the last value given. It will live until the program ends.

## Function call:
static dataType	variableName;

## Global static variables
Global static variables are quite unusual. They are declared outside the function, at the global scope, and are limited to the file they are defined in. This means it cannot be accessed outside the current translation unit — C source file.

## Important notice:
Static variables are initialized at 0 by default, even if not done explicitly. They have to be initialized using constant literals.

# Static vs. Local variables

## Local variables
- Local to the function or block
- Exist only during the function's execution
- Reinitializes each time function is called
- Stored in the stack

## Static variables
- Local to the function or block
- Exists throughout the program's execution
- Initializes only once
- Stored in the data segment

