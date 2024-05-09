/*
Data: 09 de maio de 2024
Autor: Rodolfo Correia do Nascimento
Direitos Autorais (c) 2024 Rodolfo Correia do Nascimento
Licença: MIT
Este código pode ser livremente utilizado e modificado, conforme os termos da Licença MIT.
Definições das funções relacionadas à engine.
*/

#ifndef ENGINE_H
#define ENGINE_H

#include "my_types.h"

// Protótipos das funções relacionadas à engine
void InitializeEngine();

void LoadEngineResources();

void UpdateEngine();

//void SetCameraPosition(u8 x, u8 y);

//void PlaySound(const u8 *sound);

//void StopSound();

//void PlayMusic(const u8 *music);

//void StopMusic();

void LoadSprites(u8 tile, u8 nb, u8 sprn, u8 select_tile, const u8 *data);

#endif
