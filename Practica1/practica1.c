//Librerias
#include <stdlib.h>
#include <string.h>

#include <stdlib.h>
#include <string.h>

// incluir cabecera NESLIB 
#include "neslib.h"

// incluir CC65 cabecera NES(PPU)
#include <nes.h>

// link the pattern table into CHR ROM
//#link "chr_generic.s"

// BCD soporte operaciones aritmeticas
#include "bcd.h"
//#link "bcd.c"

// VRAM actualizacion de buffer
#include "vrambuf.h"
//#link "vrambuf.c"

/*{pal:"nes",layout:"nes"}*/

//-------------OPCIÓN 1-------------
/* SE PUEDE ESCOGER UNA DE LAS DOS PALETAS

const char PALETTE[5] = { 
  0x1B,			// screen color

  0x04,0x30,0x27,0x00,	// background palette 0
}; */

/*
const char PALETTE[32] = { 
  0x1B,			// color de la pantalla

  0x04,0x30,0x27,0x00,	// paleta fondo 0
  0x1C,0x20,0x2C,0x00,	// paleta fondo 1
  0x00,0x10,0x20,0x00,	// paleta fondo 2
  0x06,0x16,0x26,0x00,   // paleta fondo 3

  0x16,0x35,0x24,0x00,	// paleta sprite 0
  0x00,0x37,0x25,0x00,	// paleta sprite 1
  0x0D,0x2D,0x3A,0x00,	// paleta sprite 2
  0x0D,0x27,0x2A	// paleta sprite 3
};


// configuracion de PPU y tablas
void setup_graphics() {
  // limpiar sprites
  oam_clear();
  // establecer paleta de colores
  pal_all(PALETTE);
}

void main(void)
{
  setup_graphics();
  // escribir mensaje  
  vram_adr(NTADR_A(2,2));
  vram_write("HELLO, WORLD!", 12);
  // habilitar renderizado
  ppu_on_all();
  // ciclo infinito
  while(1) {
  }
}
*/ 
//-------------OPCIÓN 2-------------//
void main(void) {

  // definir paleta de colores
  pal_col(0,0x1b);	// establece la pantalla en verde
  pal_col(1,0x04);	// morado
  pal_col(2,0x30);	// blanco
  pal_col(3,0x27);	// amarillo

  // Escribe texto en la nametable
  vram_adr(NTADR_A(2,2));		// establece dirección de memoria
  vram_write("HELLO, WORLD!", 13);	// escribe bytes en la video RAM

  // Habilita renderizado de PPU (enciende pantalla)
  ppu_on_all();

  // bucle infinito
  while (1) ;
}

//
