#include <stdlib.h>
#include <string.h>
#include "neslib.h"
#include <nes.h>
//#link "chr_generic.s"
#include "bcd.h"
//#link "bcd.c"
#include "vrambuf.h"
//#link "vrambuf.c"

//#link "musica.s"
//#link "famitone2.s"
void __fastcall__ famitone_update(void);
extern char musica_music_data[];


/*{pal:"nes",layout:"nes"}*/
const char PALETTE[32] = { 
  0x03,			

  0x11,0x30,0x27,0x0,	
  0x1c,0x20,0x2c,0x0,	
  0x00,0x10,0x20,0x0,	
  0x06,0x16,0x26,0x0,   

  0x16,0x35,0x24,0x0,	
  0x00,0x37,0x25,0x0,	
  0x0d,0x2d,0x3a,0x0,	
  0x0d,0x27,0x2a	
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
  vram_adr(NTADR_A(2,2));
  vram_write("HOLA MUNDO!", 12);
  
  // inicializar sistema de música 
  famitone_init(musica_music_data);
  // establecer llamada a función de música por NMI
  nmi_set_callback(famitone_update);
  // reproducir música
  music_play(0);
  
  ppu_on_all();
  // infinite loop
  while(1) {
  }
}
