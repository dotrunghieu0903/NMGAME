#ifndef _DEFINE_H_
#define _DEFINE_H_


#define GAME_SCREEN_RESOLUTION_640_480_24   1000
#define GAME_SCREEN_RESOLUTION_800_600_24   1001
#define GAME_SCREEN_RESOLUTION_1024_768_24  1002
#define GAME_SCREEN_RESOLUTION_256_224_24	1003


#define _FPS 40
const ULONG MAX_FPS_COUNT = 40;

#define VK_F 0x0046
#define VK_W 0x0057

#ifndef max
#define max(a,b)            (((a) > (b)) ? (a) : (b))
#endif

#ifndef min
#define min(a,b)            (((a) < (b)) ? (a) : (b))
#endif

#define STAGE1_TXT "resource\\stage1.txt"
#define STAGE1_PNG "resource\\stage1.png"
#define STAGE2_TXT "resource\\stage2.txt"
#define STAGE2_PNG "resource\\stage2.png"

#define SIMON_SPEED 0.2f
#define SIMON_WIDTH 60
#define SIMON_HEIGHT 66
#define SIMON_SPRITE "simon.png"

#define TILE_WITHD 32

#endif // _DEFINE_H_
