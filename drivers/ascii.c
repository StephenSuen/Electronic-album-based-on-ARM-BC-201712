const unsigned char ch[][16] = {

/*--  ??:     --*/
/*--  ??12;  ??????????:?x?=8x16   --0*/
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,

/*--  ??:  !  --*/
/*--  ??12;  ??????????:?x?=8x16   --1*/
0x00,0x00,0x00,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x00,0x00,0x18,0x18,0x00,0x00,

/*--  ??:  "  --*/
/*--  ??12;  ??????????:?x?=8x16   --2*/
0x00,0x12,0x36,0x24,0x48,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,

/*--  ??:  #  --*/
/*--  ??12;  ??????????:?x?=8x16   --3*/
0x00,0x00,0x00,0x24,0x24,0x24,0xFE,0x48,0x48,0x48,0xFE,0x48,0x48,0x48,0x00,0x00,

/*--  ??:  $  --*/
/*--  ??12;  ??????????:?x?=8x16   --4*/
0x00,0x00,0x10,0x38,0x54,0x54,0x50,0x30,0x18,0x14,0x14,0x54,0x54,0x38,0x10,0x10,

/*--  ??:  %  --*/
/*--  ??12;  ??????????:?x?=8x16   --5*/
0x00,0x00,0x00,0x44,0xA4,0xA8,0xA8,0xA8,0x54,0x1A,0x2A,0x2A,0x2A,0x44,0x00,0x00,

/*--  ??:  &  --*/
/*--  ??12;  ??????????:?x?=8x16   --6*/
0x00,0x00,0x00,0x30,0x48,0x48,0x48,0x50,0x6E,0xA4,0x94,0x88,0x89,0x76,0x00,0x00,

/*--  ??:  '  --*/
/*--  ??12;  ??????????:?x?=8x16   --7*/
0x00,0x60,0x60,0x20,0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,

/*--  ??:  (  --*/
/*--  ??12;  ??????????:?x?=8x16   --8*/
0x00,0x02,0x04,0x08,0x08,0x10,0x10,0x10,0x10,0x10,0x10,0x08,0x08,0x04,0x02,0x00,

/*--  ??:  )  --*/
/*--  ??12;  ??????????:?x?=8x16   --9*/
0x00,0x40,0x20,0x10,0x10,0x08,0x08,0x08,0x08,0x08,0x08,0x10,0x10,0x20,0x40,0x00,

/*--  ??:  *  --*/
/*--  ??12;  ??????????:?x?=8x16   --10*/
0x00,0x00,0x00,0x00,0x10,0x10,0xD6,0x38,0x38,0xD6,0x10,0x10,0x00,0x00,0x00,0x00,

/*--  ??:  +  --*/
/*--  ??12;  ??????????:?x?=8x16   --11*/
0x00,0x00,0x00,0x00,0x10,0x10,0x10,0x10,0xFE,0x10,0x10,0x10,0x10,0x00,0x00,0x00,

/*--  ??:  ,  --*/
/*--  ??12;  ??????????:?x?=8x16   --12*/
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x60,0x60,0x20,0xC0,

/*--  ??:  -  --*/
/*--  ??12;  ??????????:?x?=8x16   --13*/
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x7F,0x00,0x00,0x00,0x00,0x00,0x00,0x00,

/*--  ??:  .  --*/
/*--  ??12;  ??????????:?x?=8x16   --14*/
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x60,0x60,0x00,0x00,

/*--  ??:  /  --*/
/*--  ??12;  ??????????:?x?=8x16   --15*/
0x00,0x00,0x01,0x02,0x02,0x04,0x04,0x08,0x08,0x10,0x10,0x20,0x20,0x40,0x40,0x00,

/*--  ??:  0  --*/
/*--  ??12;  ??????????:?x?=8x16   --16*/
0x00,0x00,0x00,0x18,0x24,0x42,0x42,0x42,0x42,0x42,0x42,0x42,0x24,0x18,0x00,0x00,

/*--  ??:  1  --*/
/*--  ??12;  ??????????:?x?=8x16   --17*/
0x00,0x00,0x00,0x10,0x70,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x7C,0x00,0x00,

/*--  ??:  2  --*/
/*--  ??12;  ??????????:?x?=8x16   --18*/
0x00,0x00,0x00,0x3C,0x42,0x42,0x42,0x04,0x04,0x08,0x10,0x20,0x42,0x7E,0x00,0x00,

/*--  ??:  3  --*/
/*--  ??12;  ??????????:?x?=8x16   --19*/
0x00,0x00,0x00,0x3C,0x42,0x42,0x04,0x18,0x04,0x02,0x02,0x42,0x44,0x38,0x00,0x00,

/*--  ??:  4  --*/
/*--  ??12;  ??????????:?x?=8x16   --20*/
0x00,0x00,0x00,0x04,0x0C,0x14,0x24,0x24,0x44,0x44,0x7E,0x04,0x04,0x1E,0x00,0x00,

/*--  ??:  5  --*/
/*--  ??12;  ??????????:?x?=8x16   --21*/
0x00,0x00,0x00,0x7E,0x40,0x40,0x40,0x58,0x64,0x02,0x02,0x42,0x44,0x38,0x00,0x00,

/*--  ??:  6  --*/
/*--  ??12;  ??????????:?x?=8x16   --22*/
0x00,0x00,0x00,0x1C,0x24,0x40,0x40,0x58,0x64,0x42,0x42,0x42,0x24,0x18,0x00,0x00,

/*--  ??:  7  --*/
/*--  ??12;  ??????????:?x?=8x16   --23*/
0x00,0x00,0x00,0x7E,0x44,0x44,0x08,0x08,0x10,0x10,0x10,0x10,0x10,0x10,0x00,0x00,

/*--  ??:  8  --*/
/*--  ??12;  ??????????:?x?=8x16   --24*/
0x00,0x00,0x00,0x3C,0x42,0x42,0x42,0x24,0x18,0x24,0x42,0x42,0x42,0x3C,0x00,0x00,

/*--  ??:  9  --*/
/*--  ??12;  ??????????:?x?=8x16   --25*/
0x00,0x00,0x00,0x18,0x24,0x42,0x42,0x42,0x26,0x1A,0x02,0x02,0x24,0x38,0x00,0x00,

/*--  ??:  :  --*/
/*--  ??12;  ??????????:?x?=8x16   --26*/
0x00,0x00,0x00,0x00,0x00,0x00,0x18,0x18,0x00,0x00,0x00,0x00,0x18,0x18,0x00,0x00,

/*--  ??:  ;  --*/
/*--  ??12;  ??????????:?x?=8x16   --27*/
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x10,0x00,0x00,0x00,0x00,0x00,0x10,0x10,0x20,

/*--  ??:  <  --*/
/*--  ??12;  ??????????:?x?=8x16   --28*/
0x00,0x00,0x00,0x02,0x04,0x08,0x10,0x20,0x40,0x20,0x10,0x08,0x04,0x02,0x00,0x00,

/*--  ??:  =  --*/
/*--  ??12;  ??????????:?x?=8x16   --29*/
0x00,0x00,0x00,0x00,0x00,0x00,0xFE,0x00,0x00,0x00,0xFE,0x00,0x00,0x00,0x00,0x00,

/*--  ??:  >  --*/
/*--  ??12;  ??????????:?x?=8x16   --30*/
0x00,0x00,0x00,0x40,0x20,0x10,0x08,0x04,0x02,0x04,0x08,0x10,0x20,0x40,0x00,0x00,

/*--  ??:  ?  --*/
/*--  ??12;  ??????????:?x?=8x16   --31*/
0x00,0x00,0x00,0x3C,0x42,0x42,0x62,0x02,0x04,0x08,0x08,0x00,0x18,0x18,0x00,0x00,

/*--  ??:  @  --*/
/*--  ??12;  ??????????:?x?=8x16   --32*/
0x00,0x00,0x00,0x38,0x44,0x5A,0xAA,0xAA,0xAA,0xAA,0xB4,0x42,0x44,0x38,0x00,0x00,

/*--  ??:  A  --*/
/*--  ??12;  ??????????:?x?=8x16   --33*/
0x00,0x00,0x00,0x10,0x10,0x18,0x28,0x28,0x24,0x3C,0x44,0x42,0x42,0xE7,0x00,0x00,

/*--  ??:  B  --*/
/*--  ??12;  ??????????:?x?=8x16   --34*/
0x00,0x00,0x00,0xF8,0x44,0x44,0x44,0x78,0x44,0x42,0x42,0x42,0x44,0xF8,0x00,0x00,

/*--  ??:  C  --*/
/*--  ??12;  ??????????:?x?=8x16   --35*/
0x00,0x00,0x00,0x3E,0x42,0x42,0x80,0x80,0x80,0x80,0x80,0x42,0x44,0x38,0x00,0x00,

/*--  ??:  D  --*/
/*--  ??12;  ??????????:?x?=8x16   --36*/
0x00,0x00,0x00,0xF8,0x44,0x42,0x42,0x42,0x42,0x42,0x42,0x42,0x44,0xF8,0x00,0x00,

/*--  ??:  E  --*/
/*--  ??12;  ??????????:?x?=8x16   --37*/
0x00,0x00,0x00,0xFC,0x42,0x48,0x48,0x78,0x48,0x48,0x40,0x42,0x42,0xFC,0x00,0x00,

/*--  ??:  F  --*/
/*--  ??12;  ??????????:?x?=8x16   --38*/
0x00,0x00,0x00,0xFC,0x42,0x48,0x48,0x78,0x48,0x48,0x40,0x40,0x40,0xE0,0x00,0x00,

/*--  ??:  G  --*/
/*--  ??12;  ??????????:?x?=8x16   --39*/
0x00,0x00,0x00,0x3C,0x44,0x44,0x80,0x80,0x80,0x8E,0x84,0x44,0x44,0x38,0x00,0x00,

/*--  ??:  H  --*/
/*--  ??12;  ??????????:?x?=8x16   --40*/
0x00,0x00,0x00,0xE7,0x42,0x42,0x42,0x42,0x7E,0x42,0x42,0x42,0x42,0xE7,0x00,0x00,

/*--  ??:  I  --*/
/*--  ??12;  ??????????:?x?=8x16   --41*/
0x00,0x00,0x00,0x7C,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x7C,0x00,0x00,

/*--  ??:  J  --*/
/*--  ??12;  ??????????:?x?=8x16   --42*/
0x00,0x00,0x00,0x3E,0x08,0x08,0x08,0x08,0x08,0x08,0x08,0x08,0x08,0x08,0x88,0xF0,

/*--  ??:  K  --*/
/*--  ??12;  ??????????:?x?=8x16   --43*/
0x00,0x00,0x00,0xEE,0x44,0x48,0x50,0x70,0x50,0x48,0x48,0x44,0x44,0xEE,0x00,0x00,

/*--  ??:  L  --*/
/*--  ??12;  ??????????:?x?=8x16   --*/
0x00,0x00,0x00,0xE0,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x42,0xFE,0x00,0x00,

/*--  ??:  M  --*/
/*--  ??12;  ??????????:?x?=8x16   --*/
0x00,0x00,0x00,0xEE,0x6C,0x6C,0x6C,0x6C,0x54,0x54,0x54,0x54,0x54,0xD6,0x00,0x00,

/*--  ??:  N  --*/
/*--  ??12;  ??????????:?x?=8x16   --*/
0x00,0x00,0x00,0xC7,0x62,0x62,0x52,0x52,0x4A,0x4A,0x4A,0x46,0x46,0xE2,0x00,0x00,

/*--  ??:  O  --*/
/*--  ??12;  ??????????:?x?=8x16   --*/
0x00,0x00,0x00,0x38,0x44,0x82,0x82,0x82,0x82,0x82,0x82,0x82,0x44,0x38,0x00,0x00,

/*--  ??:  P  --*/
/*--  ??12;  ??????????:?x?=8x16   --*/
0x00,0x00,0x00,0xFC,0x42,0x42,0x42,0x42,0x7C,0x40,0x40,0x40,0x40,0xE0,0x00,0x00,

/*--  ??:  Q  --*/
/*--  ??12;  ??????????:?x?=8x16   --*/
0x00,0x00,0x00,0x38,0x44,0x82,0x82,0x82,0x82,0x82,0xB2,0xCA,0x4C,0x38,0x06,0x00,

/*--  ??:  R  --*/
/*--  ??12;  ??????????:?x?=8x16   --*/
0x00,0x00,0x00,0xFC,0x42,0x42,0x42,0x7C,0x48,0x48,0x44,0x44,0x42,0xE3,0x00,0x00,

/*--  ??:  S  --*/
/*--  ??12;  ??????????:?x?=8x16   --*/
0x00,0x00,0x00,0x3E,0x42,0x42,0x40,0x20,0x18,0x04,0x02,0x42,0x42,0x7C,0x00,0x00,

/*--  ??:  T  --*/
/*--  ??12;  ??????????:?x?=8x16   --*/
0x00,0x00,0x00,0xFE,0x92,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x38,0x00,0x00,

/*--  ??:  U  --*/
/*--  ??12;  ??????????:?x?=8x16   --*/
0x00,0x00,0x00,0xE7,0x42,0x42,0x42,0x42,0x42,0x42,0x42,0x42,0x42,0x3C,0x00,0x00,

/*--  ??:  V  --*/
/*--  ??12;  ??????????:?x?=8x16   --*/
0x00,0x00,0x00,0xE7,0x42,0x42,0x44,0x24,0x24,0x28,0x28,0x18,0x10,0x10,0x00,0x00,

/*--  ??:  W  --*/
/*--  ??12;  ??????????:?x?=8x16   --*/
0x00,0x00,0x00,0xD6,0x92,0x92,0x92,0x92,0xAA,0xAA,0x6C,0x44,0x44,0x44,0x00,0x00,

/*--  ??:  X  --*/
/*--  ??12;  ??????????:?x?=8x16   --*/
0x00,0x00,0x00,0xE7,0x42,0x24,0x24,0x18,0x18,0x18,0x24,0x24,0x42,0xE7,0x00,0x00,

/*--  ??:  Y  --*/
/*--  ??12;  ??????????:?x?=8x16   --*/
0x00,0x00,0x00,0xEE,0x44,0x44,0x28,0x28,0x10,0x10,0x10,0x10,0x10,0x38,0x00,0x00,

/*--  ??:  Z  --*/
/*--  ??12;  ??????????:?x?=8x16   --*/
0x00,0x00,0x00,0x7E,0x84,0x04,0x08,0x08,0x10,0x20,0x20,0x42,0x42,0xFC,0x00,0x00,

/*--  ??:  [  --*/
/*--  ??12;  ??????????:?x?=8x16   --*/
0x00,0x1E,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x1E,0x00,

/*--  ??:  \  --*/
/*--  ??12;  ??????????:?x?=8x16   --*/
0x00,0x00,0x40,0x40,0x20,0x20,0x10,0x10,0x10,0x08,0x08,0x04,0x04,0x04,0x02,0x02,

/*--  ??:  ]  --*/
/*--  ??12;  ??????????:?x?=8x16   --*/
0x00,0x78,0x08,0x08,0x08,0x08,0x08,0x08,0x08,0x08,0x08,0x08,0x08,0x08,0x78,0x00,

/*--  ??:  ^  --*/
/*--  ??12;  ??????????:?x?=8x16   --*/
0x00,0x1C,0x22,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,

/*--  ??:  _  --*/
/*--  ??12;  ??????????:?x?=8x16   --*/
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFF,

/*--  ??:  `  --*/
/*--  ??12;  ??????????:?x?=8x16   --*/
0x00,0x60,0x10,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,

/*--  ??:  a  --*/
/*--  ??12;  ??????????:?x?=8x16   --*/
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x3C,0x42,0x1E,0x22,0x42,0x42,0x3F,0x00,0x00,

/*--  ??:  b  --*/
/*--  ??12;  ??????????:?x?=8x16   --*/
0x00,0x00,0x00,0xC0,0x40,0x40,0x40,0x58,0x64,0x42,0x42,0x42,0x64,0x58,0x00,0x00,

/*--  ??:  c  --*/
/*--  ??12;  ??????????:?x?=8x16   --*/
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x1C,0x22,0x40,0x40,0x40,0x22,0x1C,0x00,0x00,

/*--  ??:  d  --*/
/*--  ??12;  ??????????:?x?=8x16   --*/
0x00,0x00,0x00,0x06,0x02,0x02,0x02,0x1E,0x22,0x42,0x42,0x42,0x26,0x1B,0x00,0x00,

/*--  ??:  e  --*/
/*--  ??12;  ??????????:?x?=8x16   --*/
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x3C,0x42,0x7E,0x40,0x40,0x42,0x3C,0x00,0x00,

/*--  ??:  f  --*/
/*--  ??12;  ??????????:?x?=8x16   --*/
0x00,0x00,0x00,0x0F,0x11,0x10,0x10,0x7E,0x10,0x10,0x10,0x10,0x10,0x7C,0x00,0x00,

/*--  ??:  g  --*/
/*--  ??12;  ??????????:?x?=8x16   --*/
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x3E,0x44,0x44,0x38,0x40,0x3C,0x42,0x42,0x3C,

/*--  ??:  h  --*/
/*--  ??12;  ??????????:?x?=8x16   --*/
0x00,0x00,0x00,0xC0,0x40,0x40,0x40,0x5C,0x62,0x42,0x42,0x42,0x42,0xE7,0x00,0x00,

/*--  ??:  i  --*/
/*--  ??12;  ??????????:?x?=8x16   --*/
0x00,0x00,0x00,0x30,0x30,0x00,0x00,0x70,0x10,0x10,0x10,0x10,0x10,0x7C,0x00,0x00,

/*--  ??:  j  --*/
/*--  ??12;  ??????????:?x?=8x16   --*/
0x00,0x00,0x00,0x0C,0x0C,0x00,0x00,0x1C,0x04,0x04,0x04,0x04,0x04,0x04,0x44,0x78,

/*--  ??:  k  --*/
/*--  ??12;  ??????????:?x?=8x16   --*/
0x00,0x00,0x00,0xC0,0x40,0x40,0x40,0x4E,0x48,0x50,0x68,0x48,0x44,0xEE,0x00,0x00,

/*--  ??:  l  --*/
/*--  ??12;  ??????????:?x?=8x16   --*/
0x00,0x00,0x00,0x70,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x7C,0x00,0x00,

/*--  ??:  m  --*/
/*--  ??12;  ??????????:?x?=8x16   --*/
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFE,0x49,0x49,0x49,0x49,0x49,0xED,0x00,0x00,

/*--  ??:  n  --*/
/*--  ??12;  ??????????:?x?=8x16   --*/
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xDC,0x62,0x42,0x42,0x42,0x42,0xE7,0x00,0x00,

/*--  ??:  o  --*/
/*--  ??12;  ??????????:?x?=8x16   --*/
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x3C,0x42,0x42,0x42,0x42,0x42,0x3C,0x00,0x00,

/*--  ??:  p  --*/
/*--  ??12;  ??????????:?x?=8x16   --*/
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xD8,0x64,0x42,0x42,0x42,0x44,0x78,0x40,0xE0,

/*--  ??:  q  --*/
/*--  ??12;  ??????????:?x?=8x16   --*/
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x1E,0x22,0x42,0x42,0x42,0x22,0x1E,0x02,0x07,

/*--  ??:  r  --*/
/*--  ??12;  ??????????:?x?=8x16   --*/
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xEE,0x32,0x20,0x20,0x20,0x20,0xF8,0x00,0x00,

/*--  ??:  s  --*/
/*--  ??12;  ??????????:?x?=8x16   --*/
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x3E,0x42,0x40,0x3C,0x02,0x42,0x7C,0x00,0x00,

/*--  ??:  t  --*/
/*--  ??12;  ??????????:?x?=8x16   --*/
0x00,0x00,0x00,0x00,0x00,0x10,0x10,0x7C,0x10,0x10,0x10,0x10,0x10,0x0C,0x00,0x00,

/*--  ??:  u  --*/
/*--  ??12;  ??????????:?x?=8x16   --*/
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xC6,0x42,0x42,0x42,0x42,0x46,0x3B,0x00,0x00,

/*--  ??:  v  --*/
/*--  ??12;  ??????????:?x?=8x16   --*/
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xE7,0x42,0x24,0x24,0x28,0x10,0x10,0x00,0x00,

/*--  ??:  w  --*/
/*--  ??12;  ??????????:?x?=8x16   --*/
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xD7,0x92,0x92,0xAA,0xAA,0x44,0x44,0x00,0x00,

/*--  ??:  x  --*/
/*--  ??12;  ??????????:?x?=8x16   --*/
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x6E,0x24,0x18,0x18,0x18,0x24,0x76,0x00,0x00,

/*--  ??:  y  --*/
/*--  ??12;  ??????????:?x?=8x16   --*/
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xE7,0x42,0x24,0x24,0x28,0x18,0x10,0x10,0xE0,

/*--  ??:  z  --*/
/*--  ??12;  ??????????:?x?=8x16   --*/
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x7E,0x44,0x08,0x10,0x10,0x22,0x7E,0x00,0x00,

/*--  ??:  {  --*/
/*--  ??12;  ??????????:?x?=8x16   --*/
0x00,0x03,0x04,0x04,0x04,0x04,0x04,0x08,0x04,0x04,0x04,0x04,0x04,0x04,0x03,0x00,

/*--  ??:  |  --*/
/*--  ??12;  ??????????:?x?=8x16   --*/
0x08,0x08,0x08,0x08,0x08,0x08,0x08,0x08,0x08,0x08,0x08,0x08,0x08,0x08,0x08,0x08,

/*--  ??:  }  --*/
/*--  ??12;  ??????????:?x?=8x16   --*/
0x00,0x60,0x10,0x10,0x10,0x10,0x10,0x08,0x10,0x10,0x10,0x10,0x10,0x10,0x60,0x00,

/*--  ??:  ~  --*/
/*--  ??12;  ??????????:?x?=8x16   --*/
0x30,0x4C,0x43,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,

};
