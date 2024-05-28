#ifndef GUARD_RANDOM_H
#define GUARD_RANDOM_H

struct PCG32
{
    u32 seed;
    u32 low;
    u32 high;
};

extern struct PCG32 gPCGRng;
extern struct PCG32 gPCGRng2;

//Returns a 16-bit pseudorandom number
u16 Random(void);
u16 Random2(void);

//Returns a 32-bit pseudorandom number
u32 Random32(struct PCG32 * PCGRng);

// The number 1103515245 comes from the example implementation of rand and srand
// in the ISO C standard.
#define ISO_RANDOMIZE1(val)(1103515245 * (val) + 24691)
#define ISO_RANDOMIZE2(val)(1103515245 * (val) + 12345)

//Sets the initial seed value of the pseudorandom number generator
void SeedRng(u32 seed);
void SeedRng2(u32 seed);

static inline u16 Random16(struct PCG32 * PCGRng)
{
    u32 result = Random32(PCGRng);
    return result ^ (result >> 16);
}

#endif // GUARD_RANDOM_H
