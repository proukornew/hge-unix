/*
** Haaf's Game Engine 1.8
** Copyright (C) 2003-2007, Relish Games
** hge.relishgames.com
**
** Core functions implementation: HGE splash screen
*/


#include "hge_impl.h"

#ifdef DEMO

hgeQuad dquad;
float dtime;

// this was unsigned short, but that caused byte order problems on PowerPC.
unsigned char hgelogo[]={
	0x89,0x50,0x4E,0x47,0x0D,0x0A,0x1A,0x0A,0x00,0x00,0x00,0x0D,0x49,
	0x48,0x44,0x52,0x00,0x00,0x00,0x80,0x00,0x00,0x00,0x80,0x08,0x03,
	0x00,0x00,0x00,0xF4,0xE0,0x91,0xF9,0x00,0x00,0x00,0x04,0x67,0x41,
	0x4D,0x41,0x00,0x00,0xAF,0xC8,0x37,0x05,0x8A,0xE9,0x00,0x00,0x00,
	0x19,0x74,0x45,0x58,0x74,0x53,0x6F,0x66,0x74,0x77,0x61,0x72,0x65,
	0x00,0x41,0x64,0x6F,0x62,0x65,0x20,0x49,0x6D,0x61,0x67,0x65,0x52,
	0x65,0x61,0x64,0x79,0x71,0xC9,0x65,0x3C,0x00,0x00,0x00,0x30,0x50,
	0x4C,0x54,0x45,0x8F,0x8F,0x8F,0x29,0x29,0x29,0xFF,0xFF,0xFF,0xEE,
	0xEE,0xEE,0xCE,0xCE,0xCE,0xBA,0xBA,0xBA,0x75,0x75,0x75,0xAA,0xAA,
	0xAA,0x44,0x44,0x44,0x55,0x55,0x55,0xF8,0xF8,0xF8,0xE0,0xE0,0xE0,
	0x65,0x65,0x65,0x10,0x10,0x10,0x00,0x00,0x00,0xD6,0xD6,0xD6,0x1D,
	0x53,0x76,0x99,0x00,0x00,0x08,0x30,0x49,0x44,0x41,0x54,0x78,0xDA,
	0x62,0xE0,0x1B,0x60,0x00,0x10,0x40,0x0C,0x03,0xED,0x00,0x80,0x00,
	0x1A,0x70,0x07,0x00,0x04,0xD0,0x80,0x3B,0x00,0x20,0x80,0x06,0xDC,
	0x01,0x00,0x01,0x34,0xE0,0x0E,0x00,0x08,0xA0,0x01,0x77,0x00,0x40,
	0x00,0x0D,0xB8,0x03,0x00,0x02,0x68,0xC0,0x1D,0x00,0x10,0x40,0x03,
	0xEE,0x00,0x80,0x00,0x1A,0x70,0x07,0x00,0x04,0xD0,0x80,0x3B,0x00,
	0x20,0x80,0x90,0x1D,0xC0,0xC8,0xC3,0xC0,0xCE,0xCA,0xCA,0xC2,0xC2,
	0x4F,0x33,0xC0,0xC2,0xC2,0xCA,0xCA,0xCE,0xC0,0xC3,0x88,0x64,0x29,
	0x40,0x00,0x21,0x1C,0xC0,0xC1,0xCE,0x44,0x37,0xC0,0xCE,0x01,0xB7,
	0x16,0x20,0x80,0xE0,0x0E,0x60,0x63,0x66,0x62,0x62,0x61,0x60,0xE3,
	0xE4,0xE0,0x60,0xA4,0x21,0xE0,0xE0,0xE0,0x64,0x63,0x60,0x61,0x62,
	0x62,0x66,0x83,0xD9,0x0B,0x10,0x40,0x30,0x07,0x70,0x30,0x33,0xB1,
	0x72,0xD2,0x2B,0xDE,0x39,0x59,0x99,0x98,0x61,0x61,0x00,0x10,0x40,
	0x30,0x07,0xB0,0x33,0xB1,0xF2,0xD2,0x2F,0xE5,0xF1,0xB2,0x32,0xB1,
	0x43,0x99,0x00,0x01,0x04,0x75,0x00,0x23,0x13,0x13,0x27,0x3D,0xD3,
	0x3E,0x27,0x13,0x13,0x34,0x25,0x02,0x04,0x10,0xD4,0x01,0x3C,0x4C,
	0x2C,0xF4,0xCD,0x7D,0x2C,0x4C,0x3C,0x10,0x06,0x40,0x00,0x41,0x1D,
	0xC0,0xC0,0x44,0xE7,0x02,0x01,0x6E,0x21,0x40,0x00,0x31,0xC0,0x92,
	0x00,0x1B,0x7D,0x1D,0xC0,0x06,0x4B,0x04,0x00,0x01,0x04,0x75,0x00,
	0x2B,0x7D,0x93,0x00,0x28,0x11,0xB0,0x42,0x18,0x00,0x01,0x04,0x77,
	0x00,0x07,0x7D,0x1D,0xC0,0x01,0x73,0x00,0x40,0x00,0x31,0xC0,0xD2,
	0x04,0x59,0x0E,0xE0,0x05,0x16,0x2B,0xAC,0x40,0xC0,0xC0,0xC6,0x41,
	0xB2,0x03,0xA0,0xA9,0x1E,0x20,0x80,0xE0,0x0E,0x40,0x94,0xCF,0xAC,
	0x50,0xC0,0x83,0x54,0x4B,0xC0,0xC4,0x90,0x4B,0x71,0x3E,0x1E,0x56,
	0xA4,0xD2,0x95,0x99,0x01,0x45,0x8E,0x15,0x07,0x80,0x9B,0x08,0x73,
	0x00,0x40,0x00,0x41,0x1D,0xC0,0x8F,0xE4,0x00,0x98,0x91,0x6C,0xC8,
	0xEE,0x85,0x02,0x24,0x8F,0x32,0xB2,0xA0,0x97,0xF0,0xC8,0xE9,0x18,
	0x57,0x2D,0x80,0x70,0x00,0x3F,0x84,0x01,0x10,0x40,0x64,0x3B,0x80,
	0x07,0x8B,0xE9,0x2C,0xBC,0xA4,0x3B,0x00,0x20,0x80,0xC8,0x75,0x00,
	0x0F,0x56,0xE3,0x59,0x48,0x77,0x00,0x40,0x00,0x91,0xE9,0x00,0x46,
	0x66,0xEC,0xE6,0x33,0x90,0xEC,0x00,0x80,0x00,0x22,0xD3,0x01,0xAC,
	0xB8,0x2C,0x60,0x24,0xD5,0x01,0x00,0x01,0x44,0x9E,0x03,0x18,0xE1,
	0x06,0x72,0x83,0x9A,0x37,0x8C,0x0C,0x18,0x41,0x40,0xB4,0x03,0x00,
	0x02,0x88,0x3C,0x07,0x30,0xA0,0x27,0x3B,0x44,0x92,0xE0,0x45,0x35,
	0x84,0x95,0x0D,0x15,0x60,0x38,0x00,0x20,0x80,0xC8,0x73,0x00,0x33,
	0x7A,0x88,0x23,0x9C,0xC4,0x83,0xD3,0x10,0x14,0x00,0x77,0x00,0x40,
	0x00,0x91,0xE5,0x00,0x78,0x0C,0xB0,0x23,0x19,0x88,0x1A,0x07,0x44,
	0x3B,0x00,0x20,0x80,0xC8,0x72,0x00,0x0F,0x9A,0x77,0x41,0x80,0x1B,
	0x16,0xE6,0x24,0x3A,0x00,0x20,0x80,0xC8,0x72,0x00,0x1B,0x96,0x82,
	0x11,0x96,0x2F,0x98,0x49,0x74,0x00,0x40,0x00,0x91,0xE5,0x00,0x76,
	0xF4,0x34,0x8D,0x9C,0x08,0x48,0x74,0x00,0x40,0x00,0x91,0xE5,0x00,
	0x56,0x2C,0x0E,0x60,0x23,0xD3,0x01,0x00,0x01,0x44,0x35,0x07,0xF0,
	0xA0,0xD6,0x77,0x44,0x3B,0x00,0x20,0x80,0xA8,0xE6,0x00,0x34,0x40,
	0xB4,0x03,0x00,0x02,0x68,0xC0,0x1D,0x00,0x10,0x40,0x78,0x1C,0xC0,
	0xC0,0x01,0x07,0x6C,0x64,0x3B,0x00,0xC9,0x10,0x20,0x60,0xC4,0x74,
	0x00,0x40,0x00,0xE1,0x71,0x00,0x36,0x40,0xB2,0x03,0x50,0x01,0x2B,
	0xA6,0x03,0x00,0x02,0x68,0xC0,0x1D,0x00,0x10,0x40,0x03,0xEE,0x00,
	0x80,0x00,0xA2,0x86,0x03,0xB0,0x55,0xB8,0x44,0x3B,0x00,0x20,0x80,
	0x06,0xDC,0x01,0x00,0x01,0x34,0xE0,0x0E,0x00,0x08,0x20,0x3C,0x0E,
	0x40,0x6A,0x4B,0x30,0x90,0xED,0x00,0xD4,0x06,0x09,0x0F,0xA6,0x03,
	0x00,0x02,0x88,0x1A,0x05,0x11,0x3E,0x07,0x10,0x2C,0x88,0x00,0x02,
	0x68,0xC0,0x1D,0x00,0x10,0x40,0xD4,0x70,0x00,0xB8,0x0E,0xE2,0x26,
	0xD3,0x01,0x00,0x01,0x34,0xE0,0xD5,0x31,0x40,0x00,0x0D,0xB8,0x03,
	0x00,0x02,0x68,0xC0,0x1D,0x00,0x10,0x40,0x94,0x39,0x80,0x97,0x72,
	0x07,0x00,0x04,0x10,0x65,0x6D,0x42,0x0E,0xCA,0x1D,0x00,0x10,0x40,
	0x94,0xB5,0x8A,0x39,0x31,0x5B,0xC5,0xA4,0x3A,0x00,0x20,0x80,0x28,
	0xEB,0x17,0x30,0x20,0x0F,0xFC,0x91,0xE7,0x00,0x80,0x00,0xA2,0xAC,
	0x67,0xC4,0x8D,0xD9,0x33,0x22,0xD5,0x01,0x00,0x01,0x44,0x61,0xDF,
	0x90,0x03,0x23,0x09,0x90,0xEA,0x00,0x80,0x00,0xA2,0xB0,0x77,0xCC,
	0xCC,0x88,0x1E,0x00,0xA4,0x3A,0x00,0x20,0x80,0xC8,0x73,0x00,0x07,
	0x62,0x70,0x8C,0x0D,0x75,0x7C,0x00,0xDD,0x01,0xDC,0x38,0x47,0xC9,
	0xA0,0x0E,0x00,0x08,0x20,0x6A,0x8F,0x90,0xE0,0x6F,0x0F,0x60,0x19,
	0xA0,0x00,0x08,0x20,0x72,0xC7,0x88,0x30,0x8D,0x66,0x66,0x21,0xCB,
	0x01,0x00,0x01,0x44,0xEE,0x28,0x19,0x1B,0x86,0xD1,0x6C,0xAC,0x64,
	0x39,0x00,0x20,0x80,0xC8,0x1E,0x27,0x64,0x40,0x9F,0x87,0xE2,0x23,
	0xCF,0x01,0x00,0x01,0x44,0xFE,0x48,0x29,0x0F,0xFA,0x18,0x25,0x79,
	0x0E,0x00,0x08,0x20,0xF2,0x1D,0x80,0x9C,0xF6,0xC1,0x93,0x60,0xE4,
	0x39,0x00,0x20,0x80,0xB0,0x38,0x80,0x84,0xC1,0x72,0x1E,0x36,0x50,
	0xD6,0x62,0xE3,0x24,0x7D,0xBE,0x0B,0xEE,0x00,0x80,0x00,0xA2,0xC8,
	0x01,0x14,0x00,0xB8,0x03,0x00,0x02,0x68,0xC0,0x1D,0x00,0x10,0x40,
	0x03,0xEE,0x00,0x80,0x00,0x1A,0x70,0x07,0x00,0x04,0xD0,0x80,0x3B,
	0x00,0x20,0x80,0x06,0xDC,0x01,0x00,0x01,0x34,0xE0,0x0E,0x00,0x08,
	0xA0,0x01,0x77,0x00,0x40,0x00,0x0D,0xB8,0x03,0x00,0x02,0x08,0xEA,
	0x00,0x2E,0x26,0xBA,0x03,0x2E,0x88,0xCD,0x00,0x01,0x34,0xE0,0x0E,
	0x00,0x08,0xA0,0x01,0x77,0x00,0x40,0x00,0x0D,0xB8,0x03,0x00,0x02,
	0x88,0x90,0x03,0x40,0x23,0x9D,0x3C,0xCC,0x4C,0xCC,0x3C,0xBC,0x7C,
	0x1C,0x2C,0x2C,0x1C,0x0C,0x40,0x01,0x16,0x26,0x36,0x4E,0x26,0xF0,
	0xF8,0x29,0x0B,0x90,0xE0,0x64,0x61,0x02,0x51,0x1C,0x0C,0x2C,0x10,
	0x95,0xA0,0xB6,0x01,0x58,0x98,0x99,0x83,0x8D,0x89,0x9B,0x83,0x81,
	0x90,0x03,0x00,0x02,0x10,0x62,0xE5,0x38,0x00,0xC0,0x20,0x08,0x63,
	0x6D,0x6D,0x52,0xFD,0xFF,0x73,0x8B,0xF1,0x01,0x0E,0x1C,0x23,0x23,
	0x30,0x06,0x48,0xEC,0xB8,0x25,0x87,0xAD,0x80,0x3D,0xC8,0x09,0xA1,
	0x73,0x00,0x96,0x0F,0x12,0x5A,0x02,0x2B,0x0E,0xEF,0x2B,0x8A,0x4E,
	0xB8,0xDB,0x14,0xB9,0xA6,0x00,0x5F,0x00,0x31,0xA0,0xF5,0x34,0x30,
	0x1D,0x00,0x6A,0x99,0x00,0xAD,0x05,0x35,0x46,0x98,0x80,0x16,0x30,
	0x02,0x1D,0x00,0x6C,0x11,0x82,0x9B,0x64,0xAC,0xC0,0x46,0x08,0x10,
	0xB3,0x82,0xDB,0x22,0x20,0x92,0x01,0x6C,0x10,0x84,0x05,0xA4,0x18,
	0x18,0x39,0x70,0x47,0x01,0x74,0x6A,0x05,0x20,0x80,0x88,0x71,0x00,
	0x0F,0x2F,0xCC,0x01,0x1C,0x8C,0x4C,0x7C,0x8C,0x1C,0xDC,0x20,0x37,
	0xF0,0xB0,0xB2,0x72,0x43,0x6C,0x62,0x01,0xDA,0xC4,0xCA,0xCA,0x0C,
	0x75,0x0D,0xD4,0x01,0x9C,0x40,0xAB,0x39,0x18,0xF1,0x35,0xDF,0xA1,
	0x0E,0x00,0x08,0x20,0x06,0xD4,0x29,0x27,0x2C,0x0E,0xE0,0x60,0x04,
	0x07,0x3C,0xD8,0x01,0x6C,0x7C,0x2C,0x7C,0x6C,0x8C,0x20,0x0B,0xC0,
	0x7A,0x59,0x81,0xAE,0x01,0xB6,0x0D,0x59,0x21,0x03,0x45,0x48,0x0E,
	0x80,0x74,0xE1,0x19,0xB0,0xB5,0xDE,0x99,0xD0,0xFA,0x95,0x00,0x01,
	0xC4,0x80,0xD6,0xB7,0xC5,0x92,0x06,0x18,0x58,0x99,0x60,0x0E,0x00,
	0xF2,0xF8,0x80,0xFE,0x05,0xBA,0x17,0x1A,0x05,0xA0,0x34,0xC0,0x8D,
	0xF0,0x37,0x8C,0xC5,0xC0,0xCA,0x08,0xB2,0x9B,0x8F,0x01,0x8F,0x03,
	0xA0,0x13,0xDD,0x00,0x01,0x04,0x5F,0xC4,0x82,0x27,0x0A,0x98,0xE0,
	0x0E,0x60,0x05,0x86,0x07,0x37,0x1F,0x27,0x1F,0x13,0x31,0x69,0x80,
	0x80,0x03,0xA0,0x73,0x8E,0x00,0x01,0xC4,0x00,0x5B,0x53,0x82,0xDF,
	0x01,0xD0,0x5C,0xC0,0xCD,0xC7,0xC8,0xC9,0x04,0x6E,0x24,0x83,0xD2,
	0x00,0x0B,0xDC,0x01,0x0C,0xE0,0x04,0x01,0xF5,0x37,0x91,0x21,0x00,
	0x1D,0xDC,0x00,0x08,0x20,0x06,0x3E,0xFC,0x89,0x00,0xEA,0x00,0x66,
	0x1E,0xA0,0xB5,0x2C,0xA0,0x56,0x35,0x30,0x13,0x82,0x9C,0x0B,0x6E,
	0xAC,0x83,0x1C,0xC0,0x0D,0x4A,0x0A,0x90,0x04,0x01,0x5B,0x55,0x01,
	0x62,0xF1,0x32,0x10,0x70,0x00,0x6C,0x68,0x01,0x20,0x80,0x18,0x70,
	0x76,0xB5,0x68,0x0C,0x60,0xBD,0x0E,0x80,0x00,0x82,0x0F,0xB2,0xB0,
	0xD3,0xD7,0x7E,0xF8,0xAC,0x33,0x40,0x00,0x21,0x46,0x79,0xD8,0xB8,
	0xE9,0x67,0x3D,0x37,0xA2,0xD7,0x05,0x10,0x40,0xC8,0x4B,0xC8,0x38,
	0xD9,0x59,0xB8,0x99,0x99,0xB9,0x68,0x0A,0x98,0x99,0xB9,0x59,0xD8,
	0x91,0x57,0x6D,0x01,0x04,0xD0,0x80,0x2F,0x6A,0x05,0x08,0xA0,0x01,
	0x77,0x00,0x40,0x00,0x0D,0xB8,0x03,0x00,0x02,0x68,0xC0,0x1D,0x00,
	0x10,0x40,0x03,0xEE,0x00,0x80,0x00,0x1A,0x70,0x07,0x00,0x04,0xD0,
	0x80,0x3B,0x00,0x20,0x80,0x06,0xDC,0x01,0x00,0x01,0x34,0xE0,0x0E,
	0x00,0x08,0x20,0xB8,0x03,0x18,0x91,0x17,0x30,0x62,0x55,0x09,0x6C,
	0x7E,0xC0,0x17,0x34,0x32,0xB0,0x52,0xCB,0x01,0x00,0x01,0xC4,0x80,
	0x18,0x08,0x23,0xB0,0xAE,0x96,0x95,0x09,0xC9,0x01,0xAC,0x4C,0xD4,
	0x72,0x00,0x40,0x00,0x26,0xAD,0x2D,0x05,0x60,0x18,0x84,0x91,0x42,
	0x83,0x85,0xA5,0xF7,0x3F,0xEE,0x12,0x3B,0x58,0x7F,0x0C,0xBE,0x82,
	0x9F,0xA2,0xB9,0x07,0x68,0xA5,0x17,0x89,0xD2,0x16,0x8F,0x4A,0x14,
	0x85,0xF5,0x39,0x33,0xFB,0xA8,0x36,0x98,0xF3,0xF4,0x1C,0x08,0x2C,
	0x17,0x1B,0x2A,0x31,0x95,0x53,0x7A,0xFA,0x78,0xCD,0xDF,0x86,0xBA,
	0x5F,0xB6,0x68,0x16,0xF3,0xB9,0xE7,0x92,0xA0,0xBE,0x02,0x30,0x69,
	0x06,0x2B,0x00,0x80,0x20,0x0C,0x25,0xA7,0x12,0x44,0xFF,0xFF,0xBB,
	0x39,0x17,0xD4,0x71,0x30,0xC1,0x9B,0x6F,0xB2,0x6F,0x01,0xF0,0x48,
	0xA7,0x00,0x6C,0xDD,0x9A,0x54,0x5A,0xF1,0x8E,0x44,0x90,0xC6,0xE7,
	0x46,0xFF,0xE8,0xA3,0xDC,0x50,0x0A,0xC8,0xC6,0x29,0x0A,0xB8,0x81,
	0x84,0xD2,0x58,0x34,0xAE,0x53,0x1F,0xCD,0x50,0x03,0x91,0x30,0x57,
	0xA3,0x8E,0x17,0xC6,0x8F,0x00,0x42,0x72,0x00,0x03,0x2F,0xB8,0x35,
	0x07,0x6C,0xCB,0x70,0x40,0x39,0x60,0x07,0x30,0xC2,0x65,0x40,0x0E,
	0x00,0x72,0x38,0x81,0x76,0x42,0x94,0xB1,0x31,0x71,0x22,0x38,0xA0,
	0x38,0x84,0x29,0x03,0x09,0x43,0x55,0x82,0x42,0x8B,0x97,0x05,0x2C,
	0x08,0x32,0x05,0x6E,0x10,0xCC,0x5E,0x80,0x00,0x42,0x49,0x03,0x48,
	0xD6,0x70,0xB3,0x42,0x1D,0xC0,0xC1,0x07,0xE5,0x40,0x43,0x80,0x9B,
	0x99,0x13,0x92,0x06,0xD8,0x40,0x0E,0xE0,0x80,0x24,0x1D,0x60,0x97,
	0x0C,0xC5,0x01,0x2C,0xC0,0xEE,0x1B,0x54,0x25,0x34,0xEE,0xC0,0x26,
	0x61,0x73,0x00,0x40,0x00,0xE1,0x72,0x00,0x2B,0x64,0xAE,0x1D,0xE2,
	0x00,0x30,0x07,0xAA,0x0F,0xE8,0x59,0x56,0x5E,0x54,0x07,0x30,0x02,
	0xAB,0x78,0x54,0x07,0x30,0x80,0xE2,0x1B,0xA2,0x12,0x96,0x60,0x71,
	0x39,0x00,0x20,0x80,0x70,0x39,0x80,0x8D,0x0F,0xBC,0xE6,0x06,0xE2,
	0x00,0x30,0x07,0x1A,0x02,0x1C,0x8C,0x3C,0xC0,0x96,0x2A,0x8A,0x03,
	0xB8,0x99,0x78,0xD9,0x50,0x1D,0x00,0x52,0x06,0x55,0x09,0x76,0x00,
	0x30,0xD7,0xE2,0x72,0x00,0x40,0x00,0x61,0x3A,0x80,0x93,0x1D,0xD4,
	0x03,0x63,0xE7,0x64,0x62,0x07,0x16,0x0D,0x20,0x95,0x10,0x0E,0x54,
	0x1F,0x98,0xC3,0x0A,0x77,0x00,0x1B,0x1B,0x48,0x1B,0x58,0x0F,0xB2,
	0x03,0x40,0xC2,0x10,0x95,0xC0,0x9C,0x0B,0x34,0x92,0x1B,0x2C,0x08,
	0x32,0x05,0xC3,0x01,0x00,0x01,0x84,0xEE,0x00,0x60,0x8A,0x06,0x2D,
	0xF3,0x66,0x07,0xA5,0x60,0x50,0xCE,0x04,0xA9,0x64,0x87,0x26,0x7C,
	0xB0,0x3E,0x06,0x70,0x62,0x86,0xBA,0x86,0x19,0xA8,0x98,0x0D,0x24,
	0xC4,0x8A,0xEC,0x00,0x5E,0x6E,0xF0,0xF0,0x3D,0x58,0x25,0x28,0x68,
	0xC0,0xD9,0x8B,0x97,0x05,0x6C,0x0A,0x86,0x03,0x00,0x02,0x08,0xBD,
	0x28,0x66,0xE4,0x61,0x63,0x07,0xC9,0x82,0xB2,0x3C,0x42,0x10,0x07,
	0x87,0x97,0x13,0x1C,0x02,0x7C,0x8C,0xE8,0x23,0x5C,0x1C,0x1C,0xC8,
	0x2A,0x79,0x21,0x2B,0xA8,0x38,0x38,0xB0,0x0D,0xAA,0x03,0x04,0x10,
	0xBA,0x03,0x38,0x51,0x96,0x27,0x13,0x1A,0xEA,0x62,0x46,0x4C,0xDC,
	0x91,0x0B,0x00,0x02,0x08,0xA3,0x32,0xE2,0xE5,0x20,0x65,0xA1,0x3C,
	0x76,0x5F,0x91,0x02,0x00,0x02,0x68,0xC0,0x6B,0x43,0x80,0x00,0x1A,
	0x70,0x07,0x00,0x04,0xD0,0x80,0x3B,0x00,0x20,0x80,0x06,0xDC,0x01,
	0x00,0x01,0x34,0xE0,0x0E,0x00,0x08,0xA0,0x01,0x77,0x00,0x40,0x00,
	0x0D,0xB8,0x03,0x00,0x02,0x68,0xC0,0x1D,0x00,0x10,0x40,0x03,0xEE,
	0x00,0x80,0x00,0x1A,0x70,0x07,0x00,0x04,0x18,0x00,0xED,0x0B,0x8C,
	0xD3,0x6F,0x67,0x6E,0xBE,0x00,0x00,0x00,0x00,0x49,0x45,0x4E,0x44,
	0xAE,0x42,0x60,0x82
};

void DInit() {
	int x=pHGE->System_GetState(HGE_SCREENWIDTH)/2;
	int y=pHGE->System_GetState(HGE_SCREENHEIGHT)/2;
	
	dquad.tex=pHGE->Texture_Load((char *)hgelogo, sizeof(hgelogo));
	dquad.blend=BLEND_DEFAULT;

	for(int i=0; i<4; i++) {
		dquad.v[i].z=0.5f;
		dquad.v[i].col=0xFFFFFFFF;
	}

	dquad.v[0].tx=0.0f; dquad.v[0].ty=0.0f;
	dquad.v[1].tx=1.0f; dquad.v[1].ty=0.0f;
	dquad.v[2].tx=1.0f; dquad.v[2].ty=1.0f;
	dquad.v[3].tx=0.0f; dquad.v[3].ty=1.0f;

	dquad.v[0].x=x-64.0f; dquad.v[0].y=y-64.0f;
	dquad.v[1].x=x+64.0f; dquad.v[1].y=y-64.0f;
	dquad.v[2].x=x+64.0f; dquad.v[2].y=y+64.0f;
	dquad.v[3].x=x-64.0f; dquad.v[3].y=y+64.0f;

	dtime=0.0f;
}

void DDone() {
	pHGE->Texture_Free(dquad.tex);
}

bool DFrame() {
	BYTE alpha;
	DWORD col;

	dtime+=pHGE->Timer_GetDelta();

	if(dtime<0.25) alpha=(BYTE)((dtime*4)*0xFF);
	else if(dtime<1.0) alpha=0xFF;
	else if(dtime<1.25) alpha=(BYTE)((1.0f-(dtime-1.0f)*4)*0xFF);
	else return true;

	col=0xFFFFFF | (alpha<<24);
	dquad.v[0].col=col;
	dquad.v[1].col=col;
	dquad.v[2].col=col;
	dquad.v[3].col=col;

	pHGE->Gfx_BeginScene();
	pHGE->Gfx_Clear(0);
	pHGE->Gfx_RenderQuad(&dquad);
	pHGE->Gfx_EndScene();

	return false;
}

#endif
