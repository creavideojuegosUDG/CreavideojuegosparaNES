
//#resource "Sprites.chr"

#include <stdlib.h>
#include <string.h>

#include <stdlib.h>
#include <string.h>
#include "neslib.h"
#include <nes.h>
// link the pattern table into CHR ROM
//#link "chr_generic.s"
#include "bcd.h"
//#link "bcd.c"
#include "vrambuf.h"
//#link "vrambuf.c"

//-----OPCION 1-----//
//#define code 0x80
//#define pal 0
//const unsigned char name[]={\
//        0,      0,      (code)+0,   pal, \
//        8,      0,      (code)+1,   pal, \
//        16,      0,      (code)+2,   pal, \
//        0,      8,      (code)+3,   pal, \
//        8,      8,      (code)+4,   pal, \
//        16,      8,      (code)+5,   pal, \
//        0,      16,      (code)+6,   pal, \
//        8,      16,      (code)+7,   pal, \
//        16,      16,      (code)+8,   pal, \
//        128};
//-----FIN OPCION 1-----//
//-----OPCION 2-----//
#define DEF_METASPRITE_2x2(name,code,pal)\
const unsigned char name[]={\
        0,      0,      (code)+0,   pal, \
        8,      0,      (code)+1,   pal, \
        16,      0,      (code)+2,   pal, \
        0,      8,      (code)+3,   pal, \
        8,      8,      (code)+4,   pal, \
        16,      8,      (code)+5,   pal, \
        0,      16,      (code)+6,   pal, \
        8,      16,      (code)+7,   pal, \
        16,      16,      (code)+8,   pal, \
        128};


DEF_METASPRITE_2x2(playerEstatico, 0x80, 0);
DEF_METASPRITE_2x2(playerSalto, 0x89, 0);
DEF_METASPRITE_2x2(playerAtaca, 0x92, 0);


//-----FIN OPCION 2-----//
/*{pal:"nes",layout:"nes"}*/
const char PALETTE[32] = { 
  0x03,			// color de fondo

  0x11,0x30,0x27,0x0,	// paleta fondo 0
  0x1c,0x20,0x2c,0x0,	// paleta fondo 1
  0x00,0x10,0x20,0x0,	// paleta fondo 2
  0x06,0x16,0x26,0x0,   // paleta fondo 3

  0x16,0x35,0x24,0x0,	// paleta sprite 0
  0x00,0x37,0x25,0x0,	// paleta sprite 1
  0x0d,0x2d,0x3a,0x0,	// paleta sprite 2
  0x0d,0x27,0x2a	// paleta sprite 3
};

void setup_graphics() {
  oam_clear();
  pal_all(PALETTE);
}

void main(void)
{
  setup_graphics();
  vram_adr(NTADR_A(2,2));
  vram_write("HELLO, WORLD!", 12);
  ppu_on_all();
  

  while(1) {
    oam_meta_spr_pal(110, 100, 2,playerEstatico);
    oam_meta_spr_pal(132, 132, 2,playerSalto);
    oam_meta_spr_pal(154, 154, 2,playerAtaca);
    
    ppu_wait_nmi();

  }
}
