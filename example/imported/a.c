#include <emscripten.h>


extern int EMSCRIPTEN_KEEPALIVE fuck(char *ptr) {
  return (int)*ptr;
}
