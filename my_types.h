/*
Data: 09 de maio de 2024
Autor: Rodolfo Correia do Nascimento
Direitos Autorais (c) 2024 Rodolfo Correia do Nascimento
Licença: MIT
Este código pode ser livremente utilizado e modificado, conforme os termos da Licença MIT.
Definição de tipos de variáveis personalizadas para o jogo.
*/

#ifndef MY_TYPES_H
#define MY_TYPES_H

// Macro para definir o valor máximo da parte inteira e da parte decimal
#define MAX_INTEIRO 0xF0 // 4 bits para a parte inteira
#define MAX_DECIMAL 0x0F // 4 bits para a parte decimal

// -------- DEFINIR TIPOS DE VARIAVEIS -------------- //

typedef unsigned int            u32;
typedef unsigned short          u16;
typedef unsigned char           u8;

typedef signed int              s32;
typedef signed short            s16;
typedef signed char             s8;

typedef volatile unsigned int   vu32;
typedef volatile unsigned short vu16;
typedef volatile unsigned char  vu8;

typedef volatile signed int     vs32;
typedef volatile signed short   vs16;
typedef volatile signed char    vs8;

#endif