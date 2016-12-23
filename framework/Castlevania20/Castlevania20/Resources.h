#include "dxaudio.h"
#include <d3dx9.h>

#pragma region AUDIO

extern CSound *bg_lv2;
extern CSound *bg_music;
extern CSound *clear;
extern CSound *end_game;
extern CSound *game_over;
extern CSound *sound_intro;
extern CSound *boss;

#pragma endregion

#pragma region SOUND

extern CSound *get_hit;
extern CSound *get_hit_2;
extern CSound *collect_heart;
extern CSound *collect_item;
extern CSound *collect_weapon;
extern CSound *falling;
extern CSound *falling_water;
extern CSound *hit_pillar;
extern CSound *holy_water;
extern CSound *cross;
extern CSound *open_door;
extern CSound *splash_water;
extern CSound *attack;
extern CSound *clock_sound;
extern CSound *fire_proj;
extern CSound *knife;
extern CSound *rosary;

extern CSound *start_sound;
extern CSound *axe;

#pragma endregion

void initSound();
void deleteSound();
