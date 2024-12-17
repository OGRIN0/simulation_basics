#include "lcgrand.h"

#define MODLUS 2147483647
#define MULT1 24112
#define MULT2 26143

static long zrng[] = {
    0,
    1973272912,  281629770,   20006270,    1280689831, 2091835177,
    591439757,   18920591,    327162470,   1708343773, 1476152346,
};

float lcgrand(int stream) {
    long zi, lowprd, hi31;
    zi = zrng[stream];
    lowprd = (zi & 65535) * MULT1;
    hi31 = (zi >> 16) * MULT1 + (lowprd >> 16);
    zi = ((zi & 65535) * MULT2 + (hi31 >> 16)) & MODLUS;
    zrng[stream] = zi;
    return ((zi >> 7 | 1) / 16777216.0);
}
void lcgrandst(long zset, int stream) { zrng[stream] = zset; }
long lcgrandgt(int stream) { return zrng[stream]; }
