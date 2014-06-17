#include <except.h>

jmp_buf __errorbuf;
int __errorval;

Exception DivideByZero = {2,"ZeroDivision"};
