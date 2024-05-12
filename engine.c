/*
Data: 09 de maio de 2024
Autor: Rodolfo Correia do Nascimento
Direitos Autorais (c) 2024 Rodolfo Correia do Nascimento
Licença: MIT
Este código pode ser livremente utilizado e modificado, conforme os termos da Licença MIT.
Definições das funções relacionadas à engine.
*/

#include "engine.h"
#include <gb/gb.h>

// Definições das funções relacionadas à engine

// Definições globais da engine, se necessário
// ------------------------- INITIALIZE ENGINE ------------------------------ //
/*!
 * \brief Essa implementação inicia a Engine do game boy,
 */
void InitializeEngine() 
{
    // Inicializa a engine do jogo

    // --------- SET DISPLAY ON AND SHOW SPRITE ------------ //
    SHOW_BKG;
    SHOW_WIN;
    SHOW_SPRITES;
    DISPLAY_ON;
}

// ------------------------- LOAD ENGINE REOURCES ------------------------------ //
/*!
 * \brief Essa implementação Carrega os recursos da Engine do game boy,
 */
void LoadEngineResources()
{
    // Carrega recursos da engine
}

// ------------------------- UPDATE ENGINE ------------------------------ //
/*!
 * \brief Essa implementação Atualiza a Engine do game boy,
 */
void UpdateEngine()
{
    // Atualiza a engine do jogo
}

// --------- COPY TILES TO VRAM ------------------- //

/*!
 * \brief Essa implementação copia os dados do tile para a VRAM do game boy,
 *          recebe os argumentos: tile, nb(numberOfTiles), sprite number - range 0 to 255, tile, pointeiro para os dados do tile .
 */
void LoadSprites(u8 tile, u8 nb, u8 sprn, u8 select_tile, const u8 *data)
{
    u8 _tile        = tile;
    u8 _nb          = nb;
    const u8 *_data = data;

    u8 _sprn              = sprn;
    u8 _select_tile       = select_tile;

    set_sprite_data(_tile, _nb, _data);
    set_sprite_tile(sprn, select_tile);
}

// --------------  MOVIMENTAÇÃO DE OBJETO -------------------- //
/*!
 * \brief Essa implementação representa a movimentação do objeto,
 *          e está pré configurada para movimentar o objeto criado com velocidades específicas em x, y.
 */
void ObjectMovement(Object *obj, u8 _x, u8 _y, u8 _vel_x, u8 _vel_y)
{
    obj->vel_x = _vel_x;
    obj->vel_y = _vel_y;

    obj->x = _x;
    obj->y = _y;

    if (joypad() & J_RIGHT)
    {
        //obj->x+=obj->vel_x;
        scroll_bkg(1, 0);
    }

    if (joypad() & J_LEFT)
    {
       //obj->x-=obj->vel_x;
       scroll_bkg(-1, 0);
    }

    if (joypad() & J_UP)
    {
        obj->y-=obj->vel_y;
    }

    if (joypad() & J_DOWN)
    {
        obj->y+=obj->vel_y;
    }

    if (joypad() & J_A)
    {
        AddForce(obj, 10);
    }
}

// ---------------- COLISÃO DA TELA -------------------- //

/*!
 * \brief Essa implementação representa a colisão de um objeto com o tamanho da tela definida pelo desenvolvedor,
 *          e pede uma struct do tipo Object, screenwidth, screenheight, 
 *           tamanho do tile em largura e a dimensão i.e: 8x8 = 16.
 */
void ObjectScreenCollision(Object *obj, u8 _screenwidth, u8 _screenheight, u8 _tileWidth, u8 _tileDimension)
{
    u8 screenwidth = _screenwidth;
    u8 screenheight = _screenheight;
    u8 tileWidth = _tileWidth;
    u8 tileDimension = _tileDimension;

    // ------- RIGHT SCREEN CHECK --------- //
    if (obj->x >= screenwidth)
    {
        obj->x = screenwidth;
    }

    // -------- LEFT SCREEN CHECK --------- //
    if (obj->x <= tileWidth)
    {
        obj->x = tileWidth;
    }

    // -------- TOP SCREEN CHECK --------- //
    if (obj->y <= tileDimension)
    {
        obj->y = tileDimension;
    }

    // -------- BOTTOM SCREEN CHECK ----- //
    if (obj->y >= screenheight + tileWidth)
    {
        obj->y = screenheight + tileWidth;
    }
}

// ------------------------- SET CAMERA POSITION ------------------------------ //
/*!
 * \brief Essa implementação posiciona a camera dentro do jogo,
 *          recebe, coordenadas x e y.
 */
void SetCameraPosition(u8 x, u8 y) 
{

}

// ------------------------- PLAY SOUND ------------------------------ //
/*!
 * \brief Essa implementação toca um som, i.e: um som de pulo, um som de tiro;
 */
void PlaySound(const u8 *sound)
{

}

// ------------------------- STOP SOUND ------------------------------ //
/*!
 * \brief Essa implementação para de executar o som.
 */
void StopSound()
{

}

// ------------------------- PLAY MUSIC ------------------------------ //
/*!
 * \brief Essa implementação Toca uma música.
 */
void PlayMusic(const u8 *music)
{

}

// ------------------------- STOP MUSIC ------------------------------ //
/*!
 * \brief Essa implementação para de executar a música.
 */
void StopMusic()
{

} 

void performantdelay(u8 numloops){
    u8 i;
    for(i = 0; i < numloops; i++){
        wait_vbl_done();
    }     
}

/*!
 * \brief Essa implementação ajusta os tiles formando o meta sprite.
 */
void MoveSprite(Object *obj, u8 x, u8 y)
{
    move_sprite(obj->spriteids[0], x, y);
    move_sprite(obj->spriteids[1], x + obj->spritesize, y);
    move_sprite(obj->spriteids[2], x, y + obj->spritesize);
    move_sprite(obj->spriteids[3], x + obj->spritesize, y + obj->spritesize);
}

/*!
 * \brief Essa implementação cria um sprite do tipo meta sprite.
 */
void CreateSprite(Object *obj, u8 _x, u8 _y, u8 _width, u8 _height, u8 _spritesize, u8 _mass, u8 _firstTile, u8 _nbTiles, const u8 *_tileData)
{
    
    obj->spritesize = _spritesize;
    obj->x = _x;
    obj->y = _y;
    obj->width = _width;
    obj->height = _height;
    obj->mass = _mass;

    set_sprite_tile(0, 0);
    obj->spriteids[0] = 0;

    set_sprite_tile(1, 1);
    obj->spriteids[1] = 1;

    set_sprite_tile(2, 2);
    obj->spriteids[2] = 2;

    set_sprite_tile(3, 3);
    obj->spriteids[3] = 3;

    set_sprite_data(_firstTile, _nbTiles, _tileData);
    
    MoveSprite(obj, obj->x, obj->y);
}

/*!
 * \brief Essa implementação cria um background.
 */
void CreateBackground(u8 _firstTile, u8 _tileCount, const u8 *_tileData, u8 _xPos, u8 _yPos, u8 _tileWidth, u8 _tileHeight, const u8 *_mapTileData)
{
    set_bkg_data(_firstTile, _tileCount, _tileData);
    set_bkg_tiles(_xPos, _yPos, _tileWidth, _tileHeight, _mapTileData);
}
