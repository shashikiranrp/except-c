#ifndef EXCEPT_H
#define EXCEPT_H

#include <setjmp.h>

#ifdef __cplusplus
#error "don't reinvent the wheel :-)"
#endif

typedef struct {
  int value;
  char* name;
}Exception;

extern jmp_buf __errorbuf;
extern int __errorval;

#define _try if(!(__errorval = setjmp(__errorbuf)))

#define _raise(__ex) longjmp(__errorbuf,__ex.value)

#define _catch else 

#define _match(__ex) if(__errorval == __ex.value)
 
#define try _try

#define raise(ex) (_raise(ex))

#define catch _catch

#define match(ex) _match(ex)
#endif

