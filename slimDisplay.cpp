
#include "musicDB.hpp"	//for the search menu

#include "slimDisplay.hpp"


/// an 8x8 font, ripped from somewhere
const uint8_t font8x8[] = {
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x3c,0x42,0xa5,0x81,0xa5,0x99,0x42,0x3c,
	0x3c,0x7e,0xdb,0xff,0xff,0xdb,0x66,0x3c,0x6c,0xfe,0xfe,0xfe,0x7c,0x38,0x10,0x00,
	0x10,0x38,0x7c,0xfe,0x7c,0x38,0x10,0x00,0x10,0x38,0x54,0xfe,0x54,0x10,0x38,0x00,
	0x10,0x38,0x7c,0xfe,0xfe,0x10,0x38,0x00,0x00,0x00,0x00,0x30,0x30,0x00,0x00,0x00,
	0xff,0xff,0xff,0xe7,0xe7,0xff,0xff,0xff,0x38,0x44,0x82,0x82,0x82,0x44,0x38,0x00,
	0xc7,0xbb,0x7d,0x7d,0x7d,0xbb,0xc7,0xff,0x0f,0x03,0x05,0x79,0x88,0x88,0x88,0x70,
	0x38,0x44,0x44,0x44,0x38,0x10,0x7c,0x10,0x30,0x28,0x24,0x24,0x28,0x20,0xe0,0xc0,
	0x3c,0x24,0x3c,0x24,0x24,0xe4,0xdc,0x18,0x10,0x54,0x38,0xee,0x38,0x54,0x10,0x00,
	0x10,0x10,0x10,0x7c,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0xff,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0xff,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0xf0,0x10,0x10,0x10,0x10,
	0x10,0x10,0x10,0x1f,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0xff,0x10,0x10,0x10,0x10,
	0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x00,0x00,0x00,0xff,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x1f,0x10,0x10,0x10,0x10,0x00,0x00,0x00,0xf0,0x10,0x10,0x10,0x10,
	0x10,0x10,0x10,0x1f,0x00,0x00,0x00,0x00,0x10,0x10,0x10,0xf0,0x00,0x00,0x00,0x00,
	0x81,0x42,0x24,0x18,0x18,0x24,0x42,0x81,0x01,0x02,0x04,0x08,0x10,0x20,0x40,0x80,
	0x80,0x40,0x20,0x10,0x08,0x04,0x02,0x01,0x00,0x10,0x10,0xff,0x10,0x10,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x20,0x20,0x20,0x20,0x00,0x00,0x20,0x00,
	0x50,0x50,0x50,0x00,0x00,0x00,0x00,0x00,0x50,0x50,0xf8,0x50,0xf8,0x50,0x50,0x00,
	0x20,0x78,0xa0,0x70,0x28,0xf0,0x20,0x00,0xc0,0xc8,0x10,0x20,0x40,0x98,0x18,0x00,
	0x40,0xa0,0x40,0xa8,0x90,0x98,0x60,0x00,0x10,0x20,0x40,0x00,0x00,0x00,0x00,0x00,
	0x10,0x20,0x40,0x40,0x40,0x20,0x10,0x00,0x40,0x20,0x10,0x10,0x10,0x20,0x40,0x00,
	0x20,0xa8,0x70,0x20,0x70,0xa8,0x20,0x00,0x00,0x20,0x20,0xf8,0x20,0x20,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x20,0x20,0x40,0x00,0x00,0x00,0x78,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x60,0x60,0x00,0x00,0x00,0x08,0x10,0x20,0x40,0x80,0x00,
	0x70,0x88,0x98,0xa8,0xc8,0x88,0x70,0x00,0x20,0x60,0xa0,0x20,0x20,0x20,0xf8,0x00,
	0x70,0x88,0x08,0x10,0x60,0x80,0xf8,0x00,0x70,0x88,0x08,0x30,0x08,0x88,0x70,0x00,
	0x10,0x30,0x50,0x90,0xf8,0x10,0x10,0x00,0xf8,0x80,0xe0,0x10,0x08,0x10,0xe0,0x00,
	0x30,0x40,0x80,0xf0,0x88,0x88,0x70,0x00,0xf8,0x88,0x10,0x20,0x20,0x20,0x20,0x00,
	0x70,0x88,0x88,0x70,0x88,0x88,0x70,0x00,0x70,0x88,0x88,0x78,0x08,0x10,0x60,0x00,
	0x00,0x00,0x20,0x00,0x00,0x20,0x00,0x00,0x00,0x00,0x20,0x00,0x00,0x20,0x20,0x40,
	0x18,0x30,0x60,0xc0,0x60,0x30,0x18,0x00,0x00,0x00,0xf8,0x00,0xf8,0x00,0x00,0x00,
	0xc0,0x60,0x30,0x18,0x30,0x60,0xc0,0x00,0x70,0x88,0x08,0x10,0x20,0x00,0x20,0x00,
	0x70,0x88,0x08,0x68,0xa8,0xa8,0x70,0x00,0x20,0x50,0x88,0x88,0xf8,0x88,0x88,0x00,
	0xf0,0x48,0x48,0x70,0x48,0x48,0xf0,0x00,0x30,0x48,0x80,0x80,0x80,0x48,0x30,0x00,
	0xe0,0x50,0x48,0x48,0x48,0x50,0xe0,0x00,0xf8,0x80,0x80,0xf0,0x80,0x80,0xf8,0x00,
	0xf8,0x80,0x80,0xf0,0x80,0x80,0x80,0x00,0x70,0x88,0x80,0xb8,0x88,0x88,0x70,0x00,
	0x88,0x88,0x88,0xf8,0x88,0x88,0x88,0x00,0x70,0x20,0x20,0x20,0x20,0x20,0x70,0x00,
	0x38,0x10,0x10,0x10,0x90,0x90,0x60,0x00,0x88,0x90,0xa0,0xc0,0xa0,0x90,0x88,0x00,
	0x80,0x80,0x80,0x80,0x80,0x80,0xf8,0x00,0x88,0xd8,0xa8,0xa8,0x88,0x88,0x88,0x00,
	0x88,0xc8,0xc8,0xa8,0x98,0x98,0x88,0x00,0x70,0x88,0x88,0x88,0x88,0x88,0x70,0x00,
	0xf0,0x88,0x88,0xf0,0x80,0x80,0x80,0x00,0x70,0x88,0x88,0x88,0xa8,0x90,0x68,0x00,
	0xf0,0x88,0x88,0xf0,0xa0,0x90,0x88,0x00,0x70,0x88,0x80,0x70,0x08,0x88,0x70,0x00,
	0xf8,0x20,0x20,0x20,0x20,0x20,0x20,0x00,0x88,0x88,0x88,0x88,0x88,0x88,0x70,0x00,
	0x88,0x88,0x88,0x88,0x50,0x50,0x20,0x00,0x88,0x88,0x88,0xa8,0xa8,0xd8,0x88,0x00,
	0x88,0x88,0x50,0x20,0x50,0x88,0x88,0x00,0x88,0x88,0x88,0x70,0x20,0x20,0x20,0x00,
	0xf8,0x08,0x10,0x20,0x40,0x80,0xf8,0x00,0x70,0x40,0x40,0x40,0x40,0x40,0x70,0x00,
	0x00,0x00,0x80,0x40,0x20,0x10,0x08,0x00,0x70,0x10,0x10,0x10,0x10,0x10,0x70,0x00,
	0x20,0x50,0x88,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xf8,0x00,
	0x40,0x20,0x10,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x70,0x08,0x78,0x88,0x78,0x00,
	0x80,0x80,0xb0,0xc8,0x88,0xc8,0xb0,0x00,0x00,0x00,0x70,0x88,0x80,0x88,0x70,0x00,
	0x08,0x08,0x68,0x98,0x88,0x98,0x68,0x00,0x00,0x00,0x70,0x88,0xf8,0x80,0x70,0x00,
	0x10,0x28,0x20,0xf8,0x20,0x20,0x20,0x00,0x00,0x00,0x68,0x98,0x98,0x68,0x08,0x70,
	0x80,0x80,0xf0,0x88,0x88,0x88,0x88,0x00,0x20,0x00,0x60,0x20,0x20,0x20,0x70,0x00,
	0x10,0x00,0x30,0x10,0x10,0x10,0x90,0x60,0x40,0x40,0x48,0x50,0x60,0x50,0x48,0x00,
	0x60,0x20,0x20,0x20,0x20,0x20,0x70,0x00,0x00,0x00,0xd0,0xa8,0xa8,0xa8,0xa8,0x00,
	0x00,0x00,0xb0,0xc8,0x88,0x88,0x88,0x00,0x00,0x00,0x70,0x88,0x88,0x88,0x70,0x00,
	0x00,0x00,0xb0,0xc8,0xc8,0xb0,0x80,0x80,0x00,0x00,0x68,0x98,0x98,0x68,0x08,0x08,
	0x00,0x00,0xb0,0xc8,0x80,0x80,0x80,0x00,0x00,0x00,0x78,0x80,0xf0,0x08,0xf0,0x00,
	0x40,0x40,0xf0,0x40,0x40,0x48,0x30,0x00,0x00,0x00,0x90,0x90,0x90,0x90,0x68,0x00,
	0x00,0x00,0x88,0x88,0x88,0x50,0x20,0x00,0x00,0x00,0x88,0xa8,0xa8,0xa8,0x50,0x00,
	0x00,0x00,0x88,0x50,0x20,0x50,0x88,0x00,0x00,0x00,0x88,0x88,0x98,0x68,0x08,0x70,
	0x00,0x00,0xf8,0x10,0x20,0x40,0xf8,0x00,0x18,0x20,0x20,0x40,0x20,0x20,0x18,0x00,
	0x20,0x20,0x20,0x00,0x20,0x20,0x20,0x00,0xc0,0x20,0x20,0x10,0x20,0x20,0xc0,0x00,
	0x40,0xa8,0x10,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x20,0x50,0xf8,0x00,0x00,0x00,
	0x70,0x88,0x80,0x80,0x88,0x70,0x20,0x60,0x90,0x00,0x00,0x90,0x90,0x90,0x68,0x00,
	0x10,0x20,0x70,0x88,0xf8,0x80,0x70,0x00,0x20,0x50,0x70,0x08,0x78,0x88,0x78,0x00,
	0x48,0x00,0x70,0x08,0x78,0x88,0x78,0x00,0x20,0x10,0x70,0x08,0x78,0x88,0x78,0x00,
	0x20,0x00,0x70,0x08,0x78,0x88,0x78,0x00,0x00,0x70,0x80,0x80,0x80,0x70,0x10,0x60,
	0x20,0x50,0x70,0x88,0xf8,0x80,0x70,0x00,0x50,0x00,0x70,0x88,0xf8,0x80,0x70,0x00,
	0x20,0x10,0x70,0x88,0xf8,0x80,0x70,0x00,0x50,0x00,0x00,0x60,0x20,0x20,0x70,0x00,
	0x20,0x50,0x00,0x60,0x20,0x20,0x70,0x00,0x40,0x20,0x00,0x60,0x20,0x20,0x70,0x00,
	0x50,0x00,0x20,0x50,0x88,0xf8,0x88,0x00,0x20,0x00,0x20,0x50,0x88,0xf8,0x88,0x00,
	0x10,0x20,0xf8,0x80,0xf0,0x80,0xf8,0x00,0x00,0x00,0x6c,0x12,0x7e,0x90,0x6e,0x00,
	0x3e,0x50,0x90,0x9c,0xf0,0x90,0x9e,0x00,0x60,0x90,0x00,0x60,0x90,0x90,0x60,0x00,
	0x90,0x00,0x00,0x60,0x90,0x90,0x60,0x00,0x40,0x20,0x00,0x60,0x90,0x90,0x60,0x00,
	0x40,0xa0,0x00,0xa0,0xa0,0xa0,0x50,0x00,0x40,0x20,0x00,0xa0,0xa0,0xa0,0x50,0x00,
	0x90,0x00,0x90,0x90,0xb0,0x50,0x10,0xe0,0x50,0x00,0x70,0x88,0x88,0x88,0x70,0x00,
	0x50,0x00,0x88,0x88,0x88,0x88,0x70,0x00,0x20,0x20,0x78,0x80,0x80,0x78,0x20,0x20,
	0x18,0x24,0x20,0xf8,0x20,0xe2,0x5c,0x00,0x88,0x50,0x20,0xf8,0x20,0xf8,0x20,0x00,
	0xc0,0xa0,0xa0,0xc8,0x9c,0x88,0x88,0x8c,0x18,0x20,0x20,0xf8,0x20,0x20,0x20,0x40,
	0x10,0x20,0x70,0x08,0x78,0x88,0x78,0x00,0x10,0x20,0x00,0x60,0x20,0x20,0x70,0x00,
	0x20,0x40,0x00,0x60,0x90,0x90,0x60,0x00,0x20,0x40,0x00,0x90,0x90,0x90,0x68,0x00,
	0x50,0xa0,0x00,0xa0,0xd0,0x90,0x90,0x00,0x28,0x50,0x00,0xc8,0xa8,0x98,0x88,0x00,
	0x00,0x70,0x08,0x78,0x88,0x78,0x00,0xf8,0x00,0x60,0x90,0x90,0x90,0x60,0x00,0xf0,
	0x20,0x00,0x20,0x40,0x80,0x88,0x70,0x00,0x00,0x00,0x00,0xf8,0x80,0x80,0x00,0x00,
	0x00,0x00,0x00,0xf8,0x08,0x08,0x00,0x00,0x84,0x88,0x90,0xa8,0x54,0x84,0x08,0x1c,
	0x84,0x88,0x90,0xa8,0x58,0xa8,0x3c,0x08,0x20,0x00,0x00,0x20,0x20,0x20,0x20,0x00,
	0x00,0x00,0x24,0x48,0x90,0x48,0x24,0x00,0x00,0x00,0x90,0x48,0x24,0x48,0x90,0x00,
	0x28,0x50,0x20,0x50,0x88,0xf8,0x88,0x00,0x28,0x50,0x70,0x08,0x78,0x88,0x78,0x00,
	0x28,0x50,0x00,0x70,0x20,0x20,0x70,0x00,0x28,0x50,0x00,0x20,0x20,0x20,0x70,0x00,
	0x28,0x50,0x00,0x70,0x88,0x88,0x70,0x00,0x50,0xa0,0x00,0x60,0x90,0x90,0x60,0x00,
	0x28,0x50,0x00,0x88,0x88,0x88,0x70,0x00,0x50,0xa0,0x00,0xa0,0xa0,0xa0,0x50,0x00,
	0xfc,0x48,0x48,0x48,0xe8,0x08,0x50,0x20,0x00,0x50,0x00,0x50,0x50,0x50,0x10,0x20,
	0xc0,0x44,0xc8,0x54,0xec,0x54,0x9e,0x04,0x10,0xa8,0x40,0x00,0x00,0x00,0x00,0x00,
	0x00,0x20,0x50,0x88,0x50,0x20,0x00,0x00,0x88,0x10,0x20,0x40,0x80,0x28,0x00,0x00,
	0x7c,0xa8,0xa8,0x68,0x28,0x28,0x28,0x00,0x38,0x40,0x30,0x48,0x48,0x30,0x08,0x70,
	0x00,0x00,0x00,0x00,0x00,0x00,0xff,0xff,0xf0,0xf0,0xf0,0xf0,0x0f,0x0f,0x0f,0x0f,
	0x00,0x00,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x3c,0x3c,0x00,0x00,0x00,0xff,0xff,0xff,0xff,0xff,0xff,0x00,0x00,
	0xc0,0xc0,0xc0,0xc0,0xc0,0xc0,0xc0,0xc0,0x0f,0x0f,0x0f,0x0f,0xf0,0xf0,0xf0,0xf0,
	0xfc,0xfc,0xfc,0xfc,0xfc,0xfc,0xfc,0xfc,0x03,0x03,0x03,0x03,0x03,0x03,0x03,0x03,
	0x3f,0x3f,0x3f,0x3f,0x3f,0x3f,0x3f,0x3f,0x11,0x22,0x44,0x88,0x11,0x22,0x44,0x88,
	0x88,0x44,0x22,0x11,0x88,0x44,0x22,0x11,0xfe,0x7c,0x38,0x10,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x10,0x38,0x7c,0xfe,0x80,0xc0,0xe0,0xf0,0xe0,0xc0,0x80,0x00,
	0x01,0x03,0x07,0x0f,0x07,0x03,0x01,0x00,0xff,0x7e,0x3c,0x18,0x18,0x3c,0x7e,0xff,
	0x81,0xc3,0xe7,0xff,0xff,0xe7,0xc3,0x81,0xf0,0xf0,0xf0,0xf0,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0xf0,0xf0,0xf0,0xf0,0x33,0x33,0xcc,0xcc,0x33,0x33,0xcc,0xcc,
	0x00,0x20,0x20,0x50,0x50,0x88,0xf8,0x00,0x20,0x20,0x70,0x20,0x70,0x20,0x20,0x00,
	0x00,0x00,0x00,0x50,0x88,0xa8,0x50,0x00,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
	0x00,0x00,0x00,0x00,0xff,0xff,0xff,0xff,0xf0,0xf0,0xf0,0xf0,0xf0,0xf0,0xf0,0xf0,
	0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,0xff,0xff,0xff,0xff,0x00,0x00,0x00,0x00,
	0x00,0x00,0x68,0x90,0x90,0x90,0x68,0x00,0x30,0x48,0x48,0x70,0x48,0x48,0x70,0xc0,
	0xf8,0x88,0x80,0x80,0x80,0x80,0x80,0x00,0xf8,0x50,0x50,0x50,0x50,0x50,0x98,0x00,
	0xf8,0x88,0x40,0x20,0x40,0x88,0xf8,0x00,0x00,0x00,0x78,0x90,0x90,0x90,0x60,0x00,
	0x00,0x50,0x50,0x50,0x50,0x68,0x80,0x80,0x00,0x50,0xa0,0x20,0x20,0x20,0x20,0x00,
	0xf8,0x20,0x70,0xa8,0xa8,0x70,0x20,0xf8,0x20,0x50,0x88,0xf8,0x88,0x50,0x20,0x00,
	0x70,0x88,0x88,0x88,0x50,0x50,0xd8,0x00,0x30,0x40,0x40,0x20,0x50,0x50,0x50,0x20,
	0x00,0x00,0x00,0x50,0xa8,0xa8,0x50,0x00,0x08,0x70,0xa8,0xa8,0xa8,0x70,0x80,0x00,
	0x38,0x40,0x80,0xf8,0x80,0x40,0x38,0x00,0x70,0x88,0x88,0x88,0x88,0x88,0x88,0x00,
	0x00,0xf8,0x00,0xf8,0x00,0xf8,0x00,0x00,0x20,0x20,0xf8,0x20,0x20,0x00,0xf8,0x00,
	0xc0,0x30,0x08,0x30,0xc0,0x00,0xf8,0x00,0x18,0x60,0x80,0x60,0x18,0x00,0xf8,0x00,
	0x10,0x28,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0xa0,0x40,
	0x00,0x20,0x00,0xf8,0x00,0x20,0x00,0x00,0x00,0x50,0xa0,0x00,0x50,0xa0,0x00,0x00,
	0x00,0x18,0x24,0x24,0x18,0x00,0x00,0x00,0x00,0x30,0x78,0x78,0x30,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x30,0x00,0x00,0x00,0x3e,0x20,0x20,0x20,0xa0,0x60,0x20,0x00,
	0xa0,0x50,0x50,0x50,0x00,0x00,0x00,0x00,0x40,0xa0,0x20,0x40,0xe0,0x00,0x00,0x00,
	0x00,0x38,0x38,0x38,0x38,0x38,0x38,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
};



//--------------------------- Utility functions -----------------------------


// text entry system for T9 keyboards, handle keypress 'key' for current string 'text'
void keyPress(char key, string *text, bool *newSymbol)
{
	const char *t9List[] = { "", " ", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
	int nr = key - '0';

	if( (nr >= 0) && (nr <= 9) )
	{
		const char *c = t9List[nr];

		if( *newSymbol )
		{
			(*text) += c[0];
			*newSymbol = false;
		}
		else
		{
			//check if current char in text matches any of chrList[nr],
			int cursor = text->size()-1;
			bool sameT9 = false;
			int len = strlen(c);
			int idx;
			for(idx=0; c[idx] != 0; idx++)
				if( c[idx] == (*text)[cursor] )
				{
					sameT9 = true;
					break;
				}
				if( sameT9 )	(*text)[cursor] = c[ (idx+1) % len ];	// if so, goto next in chrList.
				else			(*text)[cursor] = c[0];				//else, goto first in chrList
		}
	}
}



//--------------------------- Implementation of external interface -----------


void slimDisplay::draw(char transition)
{
	uint8_t param	=  0;		//number of lines for scrolling ???

	netBuffer buf(packet);
	buf.write( (uint16_t)0 );	//offset, if ~640 for squeezebox transporter..
	buf.write( (uint8_t)transition );	//transition ('c'=constant,'R'=right,'L'=left,'U','D')
	buf.write( param );			//no idea what this is..
	assert( buf.idx == 4);

	//convert uint8 to binary data:
	//char *screen = buf.data + buf.idx;
	for(int x=0; x< screenWidth; x++)
	{
		for(int y=0; y< screenHeight; y+=8)
		{
			char bin = 0;
			for(int b=0; b < 8; b++)
			{
				bin = (bin<<1) | (screen[ (y+b) * screenWidth + x]!=0);
			}
			buf.write( &bin, 1);
		}
	}

	slimConnection->send("grfe", sizeof(packet), packet);
}



void slimDisplay::putChar(char c, bool send)
{
	//an glyph is 8x8 pixels:
	const uint8_t *glyph = &font8x8[c * 8];
	int p;      //pixel bit
	int gbit;   //glyph index
	//int pbit;   //pixel index
	int bcount = 0;

	db_printf(15,"printing %c at %3i, %2i\t",c, pos.x, pos.y);

	for(int x = pos.x; x<pos.x + 8; x++)
	{
		gbit = x-pos.x;
		for(int y = 0; y < 8; y++)
		{
			p = ( glyph[y] & (128>>gbit));
			screen[ (y+pos.y)*screenWidth + x ] = (p!=0);
			/*pbit = (y&7)^7;
			if( p ) {
				int offset = (x<<2) + ( (y+pos.y)>>3);
				//bitBuf[offset] |= (1<<pbit);
				bcount++;
			}*/
		}
	}

	// Update cursor:
	pos.x += 8;
	if(pos.x > 320-8)
	{
		pos.x  = 0;
		pos.y += 8;
	}
	if(pos.y > 32-8)
		pos.y = 0;

	db_printf(15,": %2i pixels\n", bcount);
	if(send) draw();
}



void slimDisplay::print(const char *msg, bool send)
{
	while( *msg != 0)
		putChar(*(msg++) );
	if(send) draw();
}


//--------------------------- Menu system ------------------------------------


//--------------------- while playing screen -------------------

void slimPlayingMenu::draw(void)
{
	char elapsed[10], header[80], songInfo[80];
	// Get song info:
	int elapsed_ms = display->slimConnection->status.songMSec;

	std::string group = display->slimConnection->state.currentGroup;
	const playList *list = display->slimConnection->ipc->getList( display->slimConnection->state.uuid );
	int songNr    = list->currentItem;
	int listSize  = list->items.size();
	musicFile song;
	if( listSize > 0) song =  list->items[ list->currentItem ] ;

	// Prepare strings to display:
	int secTot = elapsed_ms/1000;
	int sec = secTot % 60;
	int min = (secTot-sec) / 60;
	sprintf(elapsed, " %02i:%02i", min, sec);
	sprintf(header,  "Now Playing (%i of %i)", songNr+1, listSize);
	sprintf(songInfo,"%s (%s)", song.title.c_str(), song.artist.c_str() );

	//re-draw the entire screen:
	display->cls();
	display->gotoxy(0,0);
	display->print(header);

	display->gotoxy( 320 - strlen(elapsed)*8  ,0);
	display->print(elapsed);

	display->gotoxy(0,8);
	display->print( songInfo );
	display->draw();
}


bool slimPlayingMenu::command(commands_e cmd)
{
	bool handled = true;
	switch(cmd)
	{
	case cmd_left:
		if( parent != NULL) {
			display->slimConnection->setMenu( parent );
			parent->currentItem = 0;	//scroll to our current position.
		} else
			handled = false;
		break;
	case cmd_playing:
		//TODO: toggle between playing screens.
		break;

	case cmd_down:
	case cmd_up:
		if( playListBrowser != NULL)
			display->slimConnection->setMenu( playListBrowser );
		//re-send the command, so the playlist browser responds to it:
		handled = playListBrowser->command(cmd);
		break;
	default:
		handled = false;
	}
	return handled;
}


//--------------------- search menu -------------------

bool slimSearchMenu::command(commands_e cmd)
{
	//on key-change: pop last query, add a new one.
	//on new key, push_back a new query, with new match.

	//on right-arrow: show list of current matches
	//on right-arrow: show list of further dbField's to sort on.

	const char *key = commandsStr[cmd];
	bool handled = false;

	if( (cmd==cmd_left) && (menuCursor == 0) && (match.size() < 2) && (!newSymbol) )
	{
		if( mode == textEntry)
			display->slimConnection->setMenu( parent );
		else
			mode = textEntry;
		handled = true;
	} else {
		switch(mode)
		{
		case textEntry:
			if( cmd == cmd_left )
			{
				if( !newSymbol )
					match.resize( match.size() -1);
				newSymbol = false;
			}
			else if( cmd == cmd_right )
			{
				if( newSymbol )	//search with this criterion
				{
					dbField field = query.back().getField();
					query.pop_back();			//replace the query
					query.push_back( dbQuery(db, field, match.c_str() ) );
					resultCursor = 0;
					mode = browseResults;		//show results
				}
				else
					newSymbol = true;	//start a new character
			} else {
				keyPress( *key, &match, &newSymbol );
			}
			break;
		case fieldSelect:
			break;	//make this a sub-menu of browseResults.
		case browseResults:
			handled = true;
			if( cmd == cmd_left )
				mode = textEntry;
			else if( cmd == cmd_down )
				resultCursor = util::min<int>( resultCursor+1, query.back().uSize()-1 );
			else if( cmd == cmd_up)
				resultCursor = util::max<int>( resultCursor-1, 0 );
			else if( cmd == cmd_add ) {
				std::vector<musicFile> entries = makeEntries(db, query.back(), resultCursor );
				ipc->addToGroup( display->slimConnection->currentGroup(),  entries);
			} else if( cmd == cmd_play )  {
				std::vector<musicFile> entries = makeEntries(db, query.back(), resultCursor );
				//only clear playlist if we really have something new:
				if( entries.size() > 0)
				{
					ipc->setGroup( display->slimConnection->currentGroup(),  entries);
					//and start playing:
					ipc->seekList( display->slimConnection->currentGroup(), 0, SEEK_SET );
				}
			} else {
				handled = false;
			}
			break;
		default:
			handled = false;
		} // switch (menu mode)

	} //if (still in this menu)
	return handled;
}



void slimSearchMenu::draw(void)
{
	display->cls();
	char title[80];
	switch(mode)
	{
	case textEntry:
		{
			sprintf(title, "text entry for %s", dbFieldStr[query.back().getField()]);

			display->gotoxy(0,0);
			display->print( title );
			display->gotoxy(9,10);
			display->print(  match.c_str() );
			//Print cursor
			int x0 = 9 + 8*(match.size() + newSymbol);
			for(int dx = -8; dx < 0; dx++)
				display->putPixel( x0 + dx, 10+8, 1);
			break;
		}
	case fieldSelect:
		break;
	case browseResults:
		{
			dbQuery *result = &query.back();
			dbField field   = result->getField();
			sprintf(title, "%s `%s*' (%lli matches)", dbFieldStr[field], match.c_str(), (LLU)result->uCount(resultCursor) );
			display->gotoxy(0,0);
			display->print( title );

			sprintf(title, "%i of %llu", resultCursor+1, (LLU)result->uSize() );
			display->gotoxy( 320 - 8*strlen(title), 0 );
			display->print( title );

			display->gotoxy(20, 8);
			//int offset = resultCursor;
			dbEntry res = (*db)[ result->uIndex(resultCursor) ];
			string val = res.getField(field);
			display->print( val.c_str() );
			break;
		}
	}
	display->draw();
}


//--------------------- file browser menu -------------------



void slimBrowseMenu::draw(void)
{
	char title[80];
	display->cls();

	sprintf(title,"Music Folder: %s", lastPath().c_str() );
	display->gotoxy(0,0);
	display->print( title );

	sprintf(title,"%i of %llu", itemsPos+1, (LLU)items.size() );
	display->gotoxy( 320-8*strlen(title) , 0);
	display->print( title );

	display->gotoxy(20, 8);
	if( items.size() > 0)
		display->print( items[itemsPos].c_str() );
	else
		display->print( "<empty>" );
	display->draw();
}


// process a user-control-command
bool slimBrowseMenu::command(commands_e cmd)
{
	bool handled = true;
	int newPos;
	string url;
	if( items.size() > 0)
		url = path::join(fullPath(), items[itemsPos]);
	else
		url = fullPath();

	switch(cmd)
	{
	case cmd_up:
		newPos = util::clip<int>(itemsPos-1, 0, items.size()-1 );
		//draw();
		itemsPos = newPos;
		break;
	case cmd_down:
		newPos = util::clip<int>(itemsPos+1, 0, items.size()-1 );
		//draw();
		itemsPos = newPos;
		break;
	case cmd_left:
		if( subDirs.size() == 0)
			display->slimConnection->setMenu( parentScreen );
		else {
			string dir = subDirs.back();
			subDirs.pop_back();
			items = path::listdir( fullPath() );
			//find dir in files:
			itemsPos = 0;
			for(size_t i=0; i< items.size(); i++)
				if( dir == items[i] )
					itemsPos = i;
		}
		break;
	case cmd_right:
		if( path::isdir( url  )  )
		{
			subDirs.push_back( items[itemsPos] );
			items = path::listdir( fullPath() );
			itemsPos = 0;
		}
		//TODO: display a file info menu in case it's not a directory??
		break;
	case cmd_add:
		//Add current file or dir to the end of the playlist
		{
			std::vector<musicFile> entries = makeEntries( url );
			ipc->addToGroup( display->slimConnection->currentGroup(),  entries);
			break;
		}
	case cmd_play:
		//Replace the playlist, and issue a 'play' command to ipc
		{
			std::vector<musicFile> entries = makeEntries( url );
			//only clear playlist if we really have something new:
			if( entries.size() > 0)
			{
				ipc->setGroup( display->slimConnection->currentGroup(),  entries);
				//and start playing:
				ipc->seekList( display->slimConnection->currentGroup(), 0, SEEK_SET );
			}
			break;
		}
	default:
		handled = false;
	}
	return handled;
}
