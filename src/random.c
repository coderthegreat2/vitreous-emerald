#include "global.h"
#include "random.h"

EWRAM_DATA static u8 sUnknown = 0;
EWRAM_DATA static u32 sRandCount = 0;

// IWRAM common
struct PCG32 gPCGRng;
struct PCG32 gPCGRng2;

u16 Random(void)
{
    sRandCount++;
    return Random16(&gPCGRng);
}

void SeedRng(u32 seed)
{
    gPCGRng.seed = seed;
    gPCGRng.low = seed;
    gPCGRng.high = seed;
    sUnknown = 0;
}

void SeedRng2(u32 seed)
{
    gPCGRng2.seed = seed;
    gPCGRng2.low = seed;
    gPCGRng2.high = seed;
}

u16 Random2(void)
{
    return Random16(&gPCGRng2);
}
