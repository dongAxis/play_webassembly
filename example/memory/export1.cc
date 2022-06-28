#include <stdio.h>

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

int g_int = 42;
double g_double = 3.1415926;
char str[] = "hello world";

EM_PORT_API(int*) get_int_ptr(int *ptr) {
    g_int = *ptr;
    return &g_int;
}

EM_PORT_API(double *) __attribute__((noinline)) get_double_ptr() {
    return &g_double;
}

extern int fuck(char  *ptr);

EM_PORT_API(char *) get_char_str(char  *ptr) {
    fuck(ptr);
    __builtin_memcpy(str, ptr, 100);
    get_double_ptr();
    get_int_ptr((int *)ptr);
    return str;
}

EM_PORT_API(void) print_data() {
    printf("C{g_int: %d}\n", g_int);
    printf("C{g_double: %lf}\n", g_double);
}
