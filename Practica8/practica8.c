
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
//Funcion con ciclo infinito
void Vram_Buffer()
{
  byte val,y=1, x;// Atributos para tile, X y Y
  //X y Y representan las coordenadas de la nametable
  while(true)
  {
    ++x;
    
    val = rand()&205; // Número aleatorio entre 0-205
     if(x>=29)
    { 
       ++y;
       x=1;
       if(y>=30)
         y=1;
    }      
    //Agregar contenido a vram buffer:
    //  dirección de lugar, objeto a imprimir y bytes a escribir
    vrambuf_put(NTADR_A(x,y), &val, 29);	
  }
}

void setup_graphics() {
  oam_clear();
  pal_all(PALETTE);
}

void main(void)
{
  setup_graphics();
   // limpia buffer vram 
  vrambuf_clear();
  // establece el controlador NMI
  set_vram_update(updbuf);
  // habiita renderizado de PPU (enciende pantalla)
  ppu_on_all();
  //función para imprimir tiles
  Vram_Buffer();
}
