#include <stdio.h>
#define MAX(x,y,z) (((x)>(y))?(((x)>(z))?(x):(z)):(((y)>(z))?(y):(z)))
#define MIN(x,y,z)  (((x)<(y))?(((x)<(z))?(x):(z)):(((y)>(z))?(y):(z)))
#define SETBIT(mask, bit) ((mask) |= (1 << (bit)))
#define CLEARBIT(mask, bit) ((mask) &= ~(1 << (bit)))
#define INVERSEBIT(mask, bit) ((mask) ^= (1 << (bit)))
#define CHECKBIT(mask, bit) (((mask) >> (bit)) & 1)
#define SWAP(a, b) do { (a) ^= (b); (b) ^= (a); (a) ^= (b); } while(0)

int main(){
    int x = 5,y=6,z=9;
    printf("%d",MAX(x, y, z));
    printf("%d",MIN(x, y, z));
    int mask = 3;
    SETBIT(mask, 2);
    CLEARBIT(mask, 2);
    INVERSEBIT(mask, 2);
    printf("%d",CHECKBIT(mask, 2));
    SWAP(x, y);
    printf("%d %d",x,y);
}