#include <stdio.h>
#include <emscripten.h>
#include <wasi/api.h>

#ifndef EM_PORT_API
#	if defined(__EMSCRIPTEN__)
#		include <emscripten.h>
#		if defined(__cplusplus)
#			define EM_PORT_API(rettype) extern "C" rettype EMSCRIPTEN_KEEPALIVE
#		else
#			define EM_PORT_API(rettype) rettype EMSCRIPTEN_KEEPALIVE
#		endif
#	else
#		if defined(__cplusplus)
#			define EM_PORT_API(rettype) extern "C" rettype
#		else
#			define EM_PORT_API(rettype) rettype
#		endif
#	endif
#endif

//#define EM_IMPORT(NAME) __attribute__((import_module("env"), import_name(#NAME)))
EM_PORT_API(int) fuck(char  *ptr) __attribute__((import_module("bar")));

EM_PORT_API(void) __attribute__((import_module("bar"))) foo(void);
EM_PORT_API(void) call(char  *ptr) {
  foo();
  fuck(ptr);
}
