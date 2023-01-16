#include <stdint.h>
#ifdef __XC8__
#include <xc.h>
#endif

volatile const uint32_t
#ifdef __XC8__
__at(0x1FFFC)
#endif
crcStart __attribute__((used, section("crc_foot_start_address"))) = 0xFFFFFFFF;

