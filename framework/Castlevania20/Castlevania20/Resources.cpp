#include "Resources.h"

#pragma region AUDIO

CSound *lv1_bg;
CSound *lv2_bg;
CSound *clear;
CSound *end_game;
CSound *game_over;
CSound *sound_intro;
CSound *boss;

#pragma endregion

#pragma region SOUND

CSound *get_hit;
CSound *get_hit_2;
CSound *collect_heart;
CSound *collect_item;
CSound *collect_weapon;
CSound *falling;
CSound *falling_water;
CSound *hit_pillar;
CSound *holy_water;
CSound *cross;
CSound *open_door;
CSound *splash_water;
CSound *attack;
CSound *clock_sound;
CSound *fire_proj;
CSound *knife;
CSound *rosary;

CSound *start_sound;
CSound *axe;

CSound *bg_music;
#pragma endregion

void initSound()
{
	lv1_bg = LoadSound(L"resource\\music\\lv1_bg.wav");
	lv2_bg = LoadSound(L"resource\\music\\lv2_bg.wav");
	clear = LoadSound(L"resource\\music\\clear.wav");
	end_game = LoadSound(L"resource\\music\\end_game.wav");
	game_over = LoadSound(L"resource\\music\\game_over.wav");
	sound_intro = LoadSound(L"resource\\music\\intro.wav");
	boss = LoadSound(L"resource\\music\\boss.wav");

	//bg_music = LoadSound(L"resource\\music\\lv1_bg.wav");

	//get_hit = LoadSound(L"resource\\sound\\get_hit.wav");
	//get_hit_2 = LoadSound(L"resource\\sound\\get_hit_2.wav");
	//collect_heart = LoadSound(L"resource\\sound\\collect_heart.wav");
	//collect_item = LoadSound(L"resource\\sound\\collect_item.wav");
	//collect_weapon = LoadSound(L"resource\\sound\\collect_weapon.wav");
	//falling = LoadSound(L"resource\\sound\\falling.wav");
	//falling_water = LoadSound(L"resource\\sound\\falling_water.wav");
	//cross = LoadSound(L"resource\\sound\\cross.wav");
	//open_door = LoadSound(L"resource\\sound\\open_door.wav");
	//splash_water = LoadSound(L"resource\\sound\\splash_water.wav");
	//attack = LoadSound(L"resource\\sound\\attack.wav");
	//clock_sound = LoadSound(L"resource\\sound\\clock.wav");
	//hit_pillar = LoadSound(L"resource\\sound\\hit_pillar.wav");
	//fire_proj = LoadSound(L"resource\\sound\\fire_proj.wav");
	//knife = LoadSound(L"resource\\sound\\knife.wav");
	//holy_water = LoadSound(L"resource\\sound\\holy_water.wav");
	//rosary = LoadSound(L"resource\\sound\\rosary.wav");

	//start_sound = LoadSound(L"resource\\sound\\start.wav");
	//axe = LoadSound(L"resource\\sound\\axe.wav");
}

void deleteSound()
{
	StopSound(lv1_bg);
	StopSound(lv2_bg);
	StopSound(clear);
	StopSound(end_game);
	StopSound(game_over);
	StopSound(sound_intro);
	StopSound(boss);

	delete lv1_bg;
	delete lv2_bg;
	delete clear;
	delete end_game;
	delete game_over;
	delete sound_intro;
	delete boss;

	StopSound(get_hit);
	StopSound(get_hit_2);
	StopSound(collect_heart);
	StopSound(collect_item);
	StopSound(collect_weapon);
	StopSound(falling);
	StopSound(falling_water);
	StopSound(cross);
	StopSound(open_door);
	StopSound(splash_water);
	StopSound(attack);
	StopSound(clock_sound);
	StopSound(hit_pillar);
	StopSound(knife);
	StopSound(holy_water);
	StopSound(rosary);

	delete get_hit;
	delete get_hit_2;
	delete collect_heart;
	delete collect_item;
	delete collect_weapon;
	delete falling;
	delete falling_water;
	delete cross;
	delete open_door;
	delete splash_water;
	delete attack;
	delete clock_sound;
	delete hit_pillar;
	delete knife;
	delete holy_water;
	delete rosary;
}
