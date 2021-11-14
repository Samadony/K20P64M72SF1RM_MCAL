/*
 * utils.h
 *
 *  Created on: Nov 12, 2021
 *      Author: woraelsa
 */

#ifndef INC_UTILS_H_
#define INC_UTILS_H_

#define PUBLIC		extern
#define PRIVATE		static

//utilities

// Bitwise operations
//Write
//Bitwise
#define SET_BIT(Reg, Bit_Num)					(Reg |= (1 << Bit_Num))
#define CLR_BIT(Reg, Bit_Num)					(Reg &= ~(1 << Bit_Num))
#define TGL_BIT(Reg, Bit_Num)					(Reg ^= (1 << Bit_Num))
#define ASSIGN_BIT(Reg, Bit_Num, Bit_Value)		Bit_Value ? \
												SET_BIT(Reg, Bit_Num) : \
												CLR_BIT(Reg, Bit_Num)

//Read
#define GET_BIT(Reg, Bit_NUM)					(Reg & (1 << Bit_NUM))
#endif //INC_UTILS_H_
