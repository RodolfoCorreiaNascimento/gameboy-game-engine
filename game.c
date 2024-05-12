
/*
Data: 09 de maio de 2024
Autor: Rodolfo Correia do Nascimento
Direitos Autorais (c) 2024 Rodolfo Correia do Nascimento
Licença: MIT
Este código pode ser livremente utilizado e modificado, conforme os termos da Licença MIT.
Esta é a implementação do jogo onde é aplicada a lógica do mesmo, como movimento de objetos, mecânica e colisões, etc.
*/

#include "game.h"
#include "engine.h"
#include "mario.c"
#include "worldTile.c"
#include "tileMapSheet.c"
// ---------------- DEFINIÇÕES GLOBAIS -------------------- //
struct Object player;

// ----------------- PROTÓTIPOS ----------------------------- //
void ObjectMovement(struct Object *obj, u8 _vel_x, u8 _vel_y, u8 _x, u8 _y);
void PlayerScreenCollision(struct Object *obj, u8 _screenwidth, u8 _screenheight, u8 _tileWidth, u8 _tileDimension);

// --------- SET INITIAL SETUP ------------------ //
void StartGame() 
{
    // Create Player
    CreateSprite(&player, 160/2 + 16, 144/2 + 16, 16, 16, 8, 0, marioTileCount, marioTile);

    // Create Background
    CreateBackground(0, mapTileCount, tileMapSheet, 0, 0, worldTileWidth, worldTileHeight, worldTile);
    
}

void SetupSprites()
{

}

void UpdateGame()
{
    MoveSprite(&player, player.x, player.y);
    PlayerMovement(&player, player.x, player.y, 1, 1);
    PlayerScreenCollision(&player, 160, 144, player.spritesize, player.spritesize);
}

// --------------  MOVIMENTAÇÃO DE OBJETO -------------------- //
/*!
 * \brief Essa implementação representa a movimentação do objeto,
 *          e está pré configurada para movimentar o objeto criado com velocidades específicas em x, y.
 */
void PlayerMovement(struct Object *obj, u8 _x, u8 _y, u8 _vel_x, u8 _vel_y)

{
    obj->vel_x = _vel_x;
    obj->vel_y = _vel_y;

    obj->x = _x;
    obj->y = _y;

    if (joypad() & J_RIGHT)
    {
        obj->x+=obj->vel_x;
    }

    if (joypad() & J_LEFT)
    {
       obj->x-=obj->vel_x;
    }

    if (joypad() & J_UP)
    {
        obj->y-=obj->vel_y;
    }

    if (joypad() & J_DOWN)
    {
        obj->y+=obj->vel_y;
    }
}

// ---------------- COLISÃO DA TELA -------------------- //

/*!
 * \brief Essa implementação representa a colisão de um objeto com o tamanho da tela definida pelo desenvolvedor,
 *          e pede uma struct do tipo Object, screenwidth, screenheight, 
 *           tamanho do tile em largura e a dimensão i.e: 8x8 = 16.
 */
void PlayerScreenCollision(struct Object *obj, u8 _screenwidth, u8 _screenheight, u8 _tileWidth, u8 _tileDimension)
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