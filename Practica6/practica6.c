// 0 = horizontal mirroring
// 1 = vertical mirroring
#define NES_MIRRORING 0

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


// setup PPU and tables
void setup_graphics() {
  // clear sprites
  oam_clear();
  // set palette colors
  pal_all(PALETTE);
}

void main(void)
{
  setup_graphics();
  // draw message  
  vram_adr(NTADR_A(2,0));
  vram_write("Nametable A Fila 0", 19);
  vram_adr(NTADR_A(2,1));
  vram_write("Nametable A Fila 1", 19);
  vram_adr(NTADR_A(2,2));
  vram_write("Nametable A Fila 2", 18);
  vram_adr(NTADR_A(2,12));
  vram_write("Nametable A Fila 12", 19);
  vram_adr(NTADR_A(2,22));
  vram_write("Nametable A Fila 22", 19);
  vram_adr(NTADR_A(2,29));
  vram_write("Nametable A Fila 29", 19);
  
  vram_adr(NTADR_C(2,0));
  vram_write("Nametable C Fila 0", 19);
  vram_adr(NTADR_C(2,1));
  vram_write("Nametable C Fila 1", 18);
  vram_adr(NTADR_C(2,2));
  vram_write("Nametable C Fila 2", 18);
  vram_adr(NTADR_C(2,12));
  vram_write("Nametable C Fila 12", 19);
  vram_adr(NTADR_C(2,22));
  vram_write("Nametable C Fila 22", 19);
  vram_adr(NTADR_C(2,29));
  vram_write("Nametable C Fila 29", 19);
  
  // enable rendering
  ppu_on_all();
  // infinite loop
  while(1) {
    int x,y;
    ++y;
    scroll(x, y);
    ppu_wait_frame();
    
    if (y==479)
      y=0;

  }
}
