#ifndef _DEFINE_H_
#define _DEFINE_H_


#define GAME_SCREEN_RESOLUTION_640_480_24   1000
#define GAME_SCREEN_RESOLUTION_800_600_24   1001
#define GAME_SCREEN_RESOLUTION_1024_768_24  1002

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

#endif // _DEFINE_H_