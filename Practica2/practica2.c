
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
  0x03,			// screen color

  0x11,0x30,0x27,0x0,	// background palette 0
  0x1c,0x20,0x2c,0x0,	// background palette 1
  0x00,0x10,0x20,0x0,	// background palette 2
  0x06,0x16,0x26,0x0,   // background palette 3

  0x16,0x35,0x24,0x0,	// sprite palette 0
  0x00,0x37,0x25,0x0,	// sprite palette 1
  0x0d,0x2d,0x3a,0x0,	// sprite palette 2
  0x0d,0x27,0x2a	// sprite palette 3
};

void setup_graphics() {
  oam_clear();
  pal_all(PALETTE);
}

void main(void)
{
  char oam_id;	// sprite ID

  setup_graphics(); // establecer gráficos
  vram_adr(NTADR_A(2,2)); // dirección para frase
  vram_write("HELLO, WORLD!", 12); // Frase a imprimir
  
  // encender pantalla
  ppu_on_all();
  // bucle infinito
  while(1) {
    oam_id = 0; // Empezar con OAMid/sprite 0
    
    oam_id = oam_spr(100, 100, 0x80, 1, oam_id);
    oam_id = oam_spr(108, 100, 0x81, 1, oam_id);
    oam_id = oam_spr(116, 100, 0x82, 1, oam_id);
    oam_id = oam_spr(100, 108, 0x83, 1, oam_id);
    oam_id = oam_spr(108, 108, 0x84, 1, oam_id);
    oam_id = oam_spr(116, 108, 0x85, 1, oam_id);
    oam_id = oam_spr(100, 116, 0x86, 1, oam_id);
    oam_id = oam_spr(108, 116, 0x87, 1, oam_id);
    oam_id = oam_spr(116, 116, 0x88, 1, oam_id);
    
    oam_id = oam_spr(104, 100, 0x80, 2, oam_id);
    oam_id = oam_spr(112, 100, 0x81, 2, oam_id);
    oam_id = oam_spr(120, 100, 0x82, 2, oam_id);
    oam_id = oam_spr(104, 108, 0x83, 2, oam_id);
    oam_id = oam_spr(112, 108, 0x84, 2, oam_id);
    oam_id = oam_spr(120, 108, 0x85, 2, oam_id);
    oam_id = oam_spr(104, 116, 0x86, 2, oam_id);
    oam_id = oam_spr(112, 116, 0x87, 2, oam_id);
    oam_id = oam_spr(120, 116, 0x88, 2, oam_id);

  
    if (oam_id != 0) oam_hide_rest(oam_id);
  }
}
