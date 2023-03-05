#include "Escenario1.h"
//#resource "Sprites.chr"

#include <stdlib.h>
#include <string.h>

#include <stdlib.h>
#include <string.h>

// include NESLIB header
#include "neslib.h"

// include CC65 NES Header (PPU)
#include <nes.h>

// link the pattern table into CHR ROM
//#link "chr_generic.s"

// BCD arithmetic support
#include "bcd.h"
//#link "bcd.c"

// VRAM update buffer
#include "vrambuf.h"
//#link "vrambuf.c"

/*{pal:"nes",layout:"nes"}*/
const char PALETTE[32] = { 
   0x31,		// Color de la pantalla

  0x07,0x17,0x37,0x30,	// Paleta de fondo 0
  0x0F,0x16,0x37,0x00,	// Paleta de fondo 1
  0x2D,0x31,0x30,0x00,	// Paleta de fondo 2
  0x0B,0x1B,0x2B,0x00,  // Paleta de fondo 3

  0x0F,0x36,0x2A,0xFF,	// paleta de sprite 0
  0x2B,0x30,0x30,0x00,	// paleta de sprite 1
  0x30,0x30,0x30,0x00,	// paleta de sprite 2
  0x0D,0x27,0x2A	// paleta de sprite 3
};

// setup PPU and tables
void setup_graphics() {
  // clear sprites
  oam_clear();
  // set palette colors
  pal_all(PALETTE);
}

void main(void)
{
  int x=0;	//coordenadas de x
  int dx=1;	//velocidad en x
  setup_graphics();

  vram_adr(NAMETABLE_A); //se localiza en la dirección de la Nametable A
  vram_unrle(Escenario1); //Se carga el fondo o escena
  
  vram_adr(NTADR_A(2,2));//se localiza en parte superior
  vram_write("Hola mundo", 12);//imprime texto
  
  vram_adr(NTADR_A(2,22));//se localiza en parte inferior
  vram_write("Hola mundo", 12);//imprime texto
  
  vram_adr(NTADR_A(0,4));//se localiza en coordenadas de la Nametable A
  vram_fill(0x89, 32);// rellena con tiles la cantidad escrita.
  
  oam_spr(0, 35, 0xa0, 0, 0); //sprite 0
  ppu_on_all();
  
  while(1) {
    x += dx;
    split(x,0); // desplazamiento de pantalla
    // Cambio de dircción cuando se llegue al segundo nametable
    if (x >= 256) dx = -1;
    if (x == 0) dx = 1;
    
  }
}
