/**
 * @file rand_otm.h
 * @brief biblioteka koja deklarise funkcije generisanja pseudoslucajnih
 * brojeva
 * @author Anja Tanovic
 * @version 1.0
 */

#ifndef RAND_OTM_H_
#define RAND_OTM_H_

#include "logic_utils.h"

/**
 * InitRand - funkcija koja vrsi inicijalizaciju pocetnog stanja generatora
 * @param seed - ulazna promenljiva tipa unsigned int, seed
 * @return - Nema povratnu vrednost
 */
void InitRand(unsigned int seed);

/**
 * SetDirection - funkcija koja vrsi postavljanje orijentacije
 * @param dir - ulazna promenljiva tipa unsigned char, 0 za desno, 1 za levo
 * @return - Nema povratnu vrednost
 */
void SetDirection(unsigned char dir);

/**
 * Rand - funkcija koja vrsi generisanje 16-bitnog pseudoslucajnog broja
 * @return - generisana 16-bitna vrednost tipa unsigned int
 */
unsigned int Rand();

/**
 * RandRange - funkcija koja vrsi generisanje 16-bitnog pseudoslucajnog broja
 * iz intervala min-max
 * @param min - ulazna promenljiva tipa unsigned int, minimalna vrednost broja
 * @param max - ulazna promenljiva tipa unsigned int, maksimalna vrednost broja
 * @return - generisana 16-bitna vrednost tipa unsigned int
 */
unsigned int RandRange(unsigned int min, unsigned int max);

/**
 * GetLSB - funkcija koja izdvaja LSB iz trenutnog stanja registra
 * @param state - ulazna promenljiva tipa unsigned int, trenutno stanje registra
 * @return - izdvojena vrednost LSB
 */
unsigned char GetLSB(unsigned int state);

/**
 * GetMSB - funkcija koja izdvaja MSB iz trenutnog stanja registra
 * @param state - ulazna promenljiva tipa unsigned int, trenutno stanje registra
 * @return - izdvojena vrednost MSB
 */
unsigned char GetMSB(unsigned int state);

/**
 * ShiftAndToggle - funkcija koja vrsi generisanje novog stanja
 * na osnovu LSB bita u slucaju desne orijentacije, ili MSB bita u slucaju leve orijentacije
 * @param state - ulazna promenljiva tipa unsigned int,trenutno stanje registra
 * @param bit - ulazna promenljiva tipa unsigned char, MSB ili LSB (zavisno od orijentacije)
 * @return - generisana 16-bitna vrednost tipa unsigned int
 */
unsigned int ShiftAndToggle(unsigned int state, unsigned char bit);

#endif /* RAND_OTM_H_ */
