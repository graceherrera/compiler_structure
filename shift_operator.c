#include <stdint.h>

uint32_t decode3(uint8_t *data)
{
  uint32_t codepoint =
  (((uint32_t) data[0]) & 0xF) << 12)|
  (((uint32_t) data[1]) & 0x3F) << 6)|
  (((uint32_t) data[2]) & 0x3F) << 0);

  return codepoint;
}
