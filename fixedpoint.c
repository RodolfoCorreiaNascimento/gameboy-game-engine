#include "fixedpoint.h"

// Função para criar um valor de ponto fixo 4:4
u8 criar_valor(u8 inteiro, u8 decimal) {
    return (inteiro << 4) | (decimal & 0x0F);
}

// Função para extrair a parte inteira de um valor de ponto fixo 4:4
u8 obter_inteiro(u8 valor) {
    return valor >> 4;
}

// Função para extrair a parte decimal de um valor de ponto fixo 4:4
u8 obter_decimal(u8 valor) {
    return valor & 0x0F;
}
