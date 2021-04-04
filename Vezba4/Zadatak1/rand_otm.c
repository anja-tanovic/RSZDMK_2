/**
 * @file rand_otm.c
 * @brief biblioteka koja definise funkcije generisanja pseudoslucajnih
 * brojeva
 * @author Anja Tanovic
 * @version 1.0
 */

#include "rand_otm.h"

//Makroi za selektovanje orijentacije LFSR registra
#define RIGHT 0
#define LEFT 1

//promenljiva koja oznacava orijentaciju LFSR registra
unsigned char direction = RIGHT;

//promenljiva koja oznacava trenutno stanje LFSR registra
unsigned int current_state;

void InitRand(unsigned int seed)
{
	current_state = seed;
}

/*****************************************************************************/

void SetDirection(unsigned char dir)
{
	direction = dir;
}

/*****************************************************************************/

unsigned int Rand()
{
	unsigned char bit = 0;

	switch (direction)
	{
		case RIGHT:
			bit = GetLSB(current_state);
			break;
		case LEFT:
			bit = GetMSB(current_state);
			break;
	}

	unsigned int new_state = ShiftAndToggle(current_state, bit);

	current_state = new_state;
	return new_state;
}

/*****************************************************************************/

unsigned int RandRange(unsigned int min, unsigned int max)
{
	unsigned int new_state = Rand() % (max - min + 1) + min;
	return new_state;
}

/*****************************************************************************/

unsigned char GetLSB(unsigned int state)
{
	unsigned char lsb = CheckBit(state,0);
	return lsb;
}

/*****************************************************************************/

unsigned char GetMSB(unsigned int state)
{
	unsigned char msb = CheckBit(state,15);
	return msb;
}

/*****************************************************************************/

unsigned int ShiftAndToggle(unsigned int state, unsigned char bit)
{
	//biti koji su unutar XOR operacije
	unsigned char bit1;
	unsigned char bit2;
	unsigned char bit3;

	//biti koji se menjaju u narednom stanju
	unsigned char bit_a;
	unsigned char bit_b;
	unsigned char bit_c;

	unsigned int new_state = current_state; //da bi imao inicijalnu vrednost za slucaj da nije ni jedan od case ispunjen

	switch (direction)
	{
		case RIGHT:
			// u ovom slucaju bit je LSB

			bit1 = CheckBit(state,14);
			bit2 = CheckBit(state,13);
			bit3 = CheckBit(state,11);

			bit_a = bit1 ^ bit;
			bit_b = bit2 ^ bit;
			bit_c = bit3 ^ bit;

			//postavljanje nove vrednosti na 15., 13., 12., i 10. mesto
			new_state = ShiftRight(state,1);

			if (bit == 0)
				new_state = ClearBit(new_state,15);
			else
				new_state = SetBit(new_state,15);

			if (bit_a == 0)
				new_state = ClearBit(new_state,13);
			else
				new_state = SetBit(new_state,13);

			if (bit_b == 0)
				new_state = ClearBit(new_state,12);
			else
				new_state = SetBit(new_state,12);

			if (bit_c == 0)
				new_state = ClearBit(new_state,10);
			else
				new_state = SetBit(new_state,10);

			break;
		case LEFT:
			// u ovom slucaju bit je MSB

			bit1 = CheckBit(state,1);
			bit2 = CheckBit(state,2);
			bit3 = CheckBit(state,4);

			bit_a = bit1 ^ bit;
			bit_b = bit2 ^ bit;
			bit_c = bit3 ^ bit;

			//postavljanje nove vrednosti na 5., 3., 2., i 0. mesto
			new_state = ShiftRight(state,1);

			if (bit == 0)
				new_state = ClearBit(new_state,0);
			else
				new_state = SetBit(new_state,0);

			if (bit_a == 0)
				new_state = ClearBit(new_state,2);
			else
				new_state = SetBit(new_state,2);

			if (bit_b == 0)
				new_state = ClearBit(new_state,3);
			else
				new_state = SetBit(new_state,3);

			if (bit_c == 0)
				new_state = ClearBit(new_state,5);
			else
				new_state = SetBit(new_state,5);

			break;
	}

	return new_state;
}


