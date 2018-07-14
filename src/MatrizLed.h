/*
 *     A library for controling Leds with a MAX7219/MAX7221
 *    Copyright (c) 2007 Eberhard Fahle
 * 
 *    Permission is hereby granted, free of charge, to any person
 *    obtaining a copy of this software and associated documentation
 *    files (the "Software"), to deal in the Software without
 *    restriction, including without limitation the rights to use,
 *    copy, modify, merge, publish, distribute, sublicense, and/or sell
 *    copies of the Software, and to permit persons to whom the
 *    Software is furnished to do so, subject to the following
 *    conditions:
 * 
 *    This permission notice shall be included in all copies or 
 *    substantial portions of the Software.
 * 
 *    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 *    EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
 *    OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 *    NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
 *    HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
 *    WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 *    FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
 *    OTHER DEALINGS IN THE SOFTWARE.
 */

// https://xantorohara.github.io/led-matrix-editor/#0033333f33331e0c|003f66663e66663f|003c66030303663c|001f36666666361f|007f46161e16467f|000f06161e16467f|007c66730303663c|003333333f333333|001e0c0c0c0c0c1e|001e333330303078|006766361e366667|007f66460606060f|0063636b7f7f7763|006363737b6f6763|001c36636363361c|000f06063e66663f|00381e3b3333331e|006766363e66663f|001e33380e07331e|001e0c0c0c0c2d3f|003f333333333333|000c1e3333333333|0063777f6b636363|0063361c1c366363|001e0c0c1e333333|007f664c1831637f|0000000000000000|006e333e301e0000|003b66663e060607|001e3303331e0000|006e33333e303038|001e033f331e0000|000f06060f06361c|1f303e33336e0000|006766666e360607|001e0c0c0c0e000c|1e33333030300030|0067361e36660607|001e0c0c0c0c0c0e|00636b7f7f330000|00333333331f0000|001e3333331e0000|0f063e66663b0000|78303e33336e0000|000f06666e3b0000|001f301e033e0000|00182c0c0c3e0c08|006e333333330000|000c1e3333330000|00367f7f6b630000|0063361c36630000|1f303e3333330000|003f260c193f0000

#ifndef MatrizLed_h
#define MatrizLed_h

#include <avr/pgmspace.h>
//#include "caracteres.h"
#if (ARDUINO >= 100)
#include <Arduino.h>
#else
#include <WProgram.h>
#endif


const static byte tablaCaracteresMayuscula [] PROGMEM  = {
B00000000, B11111100, B11111110, B00010010, B00010010, B11111110, B11111100, B00000000,
B00000000, B11111110, B11111110, B10010010, B10010010, B11111110, B01101100, B00000000,
B00000000, B01111100, B11111110, B10000010, B10000010, B11000110, B01000100, B00000000,
B00000000, B11111110, B11111110, B10000010, B10000010, B11111110, B01111100, B00000000,
B00000000, B11111110, B11111110, B10010010, B10010010, B10010010, B10000010, B00000000,
B00000000, B11111110, B11111110, B00010010, B00010010, B00010010, B00000010, B00000000,
B00000000, B01111100, B11111110, B10000010, B10100010, B11100110, B01100100, B00000000,
B00000000, B11111110, B11111110, B00010000, B00010000, B11111110, B11111110, B00000000,
B00000000, B00000000, B10000010, B11111110, B11111110, B10000010, B00000000, B00000000,
B00000000, B01100000, B11100000, B10000010, B11111110, B01111110, B00000010, B00000000,
B00000000, B11111110, B11111110, B00111000, B01101100, B11000110, B10000010, B00000000,
B00000000, B11111110, B11111110, B10000000, B10000000, B10000000, B10000000, B00000000,
B00000000, B11111110, B11111110, B00001100, B00011000, B00001100, B11111110, B11111110,
B00000000, B11111110, B11111110, B00001100, B00011000, B00110000, B11111110, B11111110,
B00000000, B01111100, B11111110, B10000010, B10000010, B11111110, B01111100, B00000000,
B00000000, B11111110, B11111110, B00100010, B00100010, B00111110, B00011100, B00000000,
B00000000, B00111100, B01111110, B01000010, B01100010, B11111110, B10111100, B00000000,
B00000000, B11111110, B11111110, B00110010, B01110010, B11011110, B10001100, B00000000,
B00000000, B01001100, B11011110, B10010010, B10010010, B11110110, B01100100, B00000000,
B00000000, B00000110, B00000010, B11111110, B11111110, B00000010, B00000110, B00000000,
B00000000, B01111110, B11111110, B10000000, B10000000, B11111110, B11111110, B00000000,
B00000000, B00111110, B01111110, B11000000, B11000000, B01111110, B00111110, B00000000,
B00000000, B11111110, B11111110, B01100000, B00110000, B01100000, B11111110, B11111110,
B00000000, B11000110, B11101110, B00111000, B00010000, B00111000, B11101110, B11000110,
B00000000, B00001110, B00011110, B11110000, B11110000, B00011110, B00001110, B00000000,
B00000000, B11000010, B11100010, B10110010, B10011010, B10001110, B10000110, B00000000
};

const static byte tablaCaracteresMinuscula [] PROGMEM  = {
B00000000, B01000000, B11101000, B10101000, B10101000, B11111000, B11110000, B00000000,
B00000000, B11111110, B11111110, B10010000, B10010000, B11110000, B01100000, B00000000,
B00000000, B01110000, B11111000, B10001000, B10001000, B11011000, B01010000, B00000000,
B00000000, B01100000, B11110000, B10010000, B10010000, B11111110, B11111110, B00000000,
B00000000, B01110000, B11111000, B10101000, B10101000, B10111000, B00110000, B00000000,
B00000000, B00100000, B11111100, B11111110, B00100010, B00100110, B00000100, B00000000,
B00000000, B00011000, B10111100, B10100100, B10100100, B11111100, B01111100, B00000000,
B00000000, B11111110, B11111110, B00010000, B00010000, B11110000, B11100000, B00000000,
B00000000, B00000000, B10000000, B11110100, B11110100, B10000000, B00000000, B00000000,
B00000000, B01100000, B11100000, B10000000, B11111010, B01111010, B00000000, B00000000,
B00000000, B11111110, B11111110, B00100000, B01110000, B11011000, B10001000, B00000000,
B00000000, B00000000, B00000000, B11111110, B11111110, B00000000, B00000000, B00000000,
B00000000, B11111000, B11111000, B00110000, B11100000, B00110000, B11111000, B11111000,
B00000000, B11111000, B11111000, B00011000, B00011000, B11111000, B11110000, B00000000,
B00000000, B01110000, B11111000, B10001000, B10001000, B11111000, B01110000, B00000000,
B00000000, B11111100, B11111100, B00100100, B00100100, B00111100, B00011000, B00000000,
B00000000, B00011000, B00111100, B00100100, B11111100, B11111100, B10000000, B11000000,
B00000000, B11111000, B11111000, B00001000, B00001000, B00111000, B00110000, B00000000,
B00000000, B10010000, B10101000, B10101000, B10101000, B10101000, B01001000, B00000000,
B00000000, B00010000, B00010000, B11111100, B11111100, B00010000, B00010000, B00000000,
B00000000, B01111000, B11111000, B10000000, B10000000, B11111000, B11111000, B00000000,
B00000000, B00110000, B01110000, B11000000, B11000000, B01110000, B00110000, B00000000,
B00000000, B01111000, B11111000, B10000000, B11110000, B10000000, B11111000, B01111000,
B00000000, B10001000, B11011000, B01110000, B01110000, B11011000, B10001000, B00000000,
B00000000, B00011000, B10111000, B10100000, B10100000, B11111000, B01111000, B00000000,
B00000000, B00000000, B11001000, B11101000, B10111000, B10011000, B00000000, B00000000
};

const static byte tablaNumeros [] PROGMEM  = {
B00000000, B01111100, B11111110, B10010010, B10001010, B11111110, B01111100, B00000000,
B00000000, B10000000, B10001000, B11111110, B11111110, B10000000, B10000000, B00000000,
B00000000, B11000100, B11100110, B10100010, B10010010, B10011110, B10001100, B00000000,
B00000000, B01000100, B11000110, B10010010, B10010010, B11111110, B01101100, B00000000,
B00000000, B00110000, B00101000, B00100100, B11111110, B11111110, B00100000, B00000000,
B00000000, B01001110, B11001110, B10001010, B10001010, B11111010, B01110010, B00000000,
B00000000, B01111100, B11111110, B10010010, B10010010, B11110110, B01100100, B00000000,
B00000000, B00000110, B00000110, B11100010, B11111010, B00011110, B00000110, B00000000,
B00000000, B01101100, B11111110, B10010010, B10010010, B11111110, B01101100, B00000000,
B00000000, B01001100, B11011110, B10010010, B10010010, B11111110, B01111100, B00000000
};

const static byte tablaSimbolosPuntuacion1 [] PROGMEM  = {
    0, 0, 0, 0, 0, 0, 0, 0,
};

class MatrizLed {
    private :
        /* The array for shifting the data to the devices */
        byte spidata[16];
        /* Send out a single command to the device */
        void spiTransfer(int addr, byte opcode, byte data);

        /* We keep track of the led-status for all 8 devices in this array */
        byte status[64];
        /* Data is shifted out of this pin*/
        int SPI_MOSI;
        /* The clock is signaled on this pin */
        int SPI_CLK;
        /* This one is driven LOW for chip selectzion */
        int SPI_CS;
        /* The maximum number of devices we use */
        int maxDevices;

    public:
        /* 
         * Create a new controler 
         * Params :
         * dataPin		pin on the Arduino where data gets shifted out
         * clockPin		pin for the clock
         * csPin		pin for selecting the device 
         * numDevices	maximum number of devices that can be controled
         */
        MatrizLed(int dataPin, int clkPin, int csPin, int numDevices=1);



        void begin();
        void escribirCaracter(char, int);
        void escribirFrase(const char*, int);
        void escribirFraseScroll(const char*, unsigned long);
        void borrar();

        /*
         * Gets the number of devices attached to this MatrizLed.
         * Returns :
         * int	the number of devices on this MatrizLed
         */
        int getDeviceCount();

        /* 
         * Set the shutdown (power saving) mode for the device
         * Params :
         * addr	The address of the display to control
         * status	If true the device goes into power-down mode. Set to false
         *		for normal operation.
         */
        void shutdown(int addr, bool status);

        /* 
         * Set the number of digits (or rows) to be displayed.
         * See datasheet for sideeffects of the scanlimit on the brightness
         * of the display.
         * Params :
         * addr	address of the display to control
         * limit	number of digits to be displayed (1..8)
         */
        void setScanLimit(int addr, int limit);

        /* 
         * Set the brightness of the display.
         * Params:
         * addr		the address of the display to control
         * intensity	the brightness of the display. (0..15)
         */
        void setIntensity(int addr, int intensity);

        /* 
         * Switch all Leds on the display off. 
         * Params:
         * addr	address of the display to control
         */
        void clearDisplay(int addr);

        /* 
         * Set the status of a single Led.
         * Params :
         * addr	address of the display 
         * row	the row of the Led (0..7)
         * col	the column of the Led (0..7)
         * state	If true the led is switched on, 
         *		if false it is switched off
         */
        void setLed(int addr, int row, int col, boolean state);

        /* 
         * Set all 8 Led's in a row to a new state
         * Params:
         * addr	address of the display
         * row	row which is to be set (0..7)
         * value	each bit set to 1 will light up the
         *		corresponding Led.
         */
        void setRow(int addr, int row, byte value);

        /* 
         * Set all 8 Led's in a column to a new state
         * Params:
         * addr	address of the display
         * col	column which is to be set (0..7)
         * value	each bit set to 1 will light up the
         *		corresponding Led.
         */
        void setColumn(int addr, int col, byte value);



};

#endif	//MatrizLed.h



