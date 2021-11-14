/*
 * GPIO_Interface.h
 *
 *  Created on: Nov 12, 2021
 *      Author: woraelsa
 *
 * GPIO module to control pins to do the following
 * - Configure ports/pins from a predefined configuration structure:
 *  	- Configure pin direction (input/output)
 *  	- Configure pin mode (PU, PD and PP)
 * - Control Pin/Port Output
 * 		- Control Pins individually
 * 			- Set pin (set level low or high)
 * 			- Clear pin (clear level, low or high)
 * 			- Toggle pin just toggle
 *  	- Control Ports as a whole
 *  		- Set Port
 *			- Clear Port
 *			- Toggle Port
 * - Read Pin/Port Input
 * 		- Read a pin`s value range: high to low
 * 		- Read a port`s value range: 0 to ((1 << PORT_NUM_PINS) - 1))
 * 		  Example: PORT pins numbers = 8
 * 		  MIN value = 0x00 (all low)
 * 		  MAX value = 0xFF (all high)
 * */

#ifndef INC_GPIO_INTERFACE_H_
#define INC_GPIO_INTERFACE_H_

// Define Max Number of Pins
#define PIN0			0
#define PIN1			1
#define PIN2			2
#define PIN3			3
#define PIN4			4
#define PIN5			5
#define PIN6			6
#define PIN7			7
#define PIN8			8
#define PIN9			9
#define PIN10			10
#define PIN11			11
#define PIN12			12
#define PIN13			13
#define PIN14			14
#define PIN15			15
#define PIN16			16
#define PIN17			17
#define PIN18			18
#define PIN19			19
#define PIN20			20
#define PIN21			21
#define PIN22			22
#define PIN23			23
#define PIN24			24
#define PIN25			25
#define PIN26			26
#define PIN27			27
#define PIN28			28
#define PIN29			29
#define PIN30			30
#define PIN31			31


// PortA
#define PORTA_PIN_NUM		8U
#define GPIO_PORTA_PIN0		(1 << PIN0)
#define GPIO_PORTA_PIN1		(1 << PIN1)
#define GPIO_PORTA_PIN2		(1 << PIN2)
#define GPIO_PORTA_PIN3		(1 << PIN3)
#define GPIO_PORTA_PIN4		(1 << PIN4)
#define GPIO_PORTA_PIN5		(1 << PIN5)
#define GPIO_PORTA_PIN6		(1 << PIN6)
#define GPIO_PORTA_PIN7		(1 << PIN7)
// PortB
#define PORTB_PIN_NUM		8U
#define GPIO_PORTB_PIN0		(1 << PIN0)
#define GPIO_PORTB_PIN1		(1 << PIN1)
#define GPIO_PORTB_PIN2		(1 << PIN2)
#define GPIO_PORTB_PIN3		(1 << PIN3)
#define GPIO_PORTB_PIN4		(1 << PIN4)
#define GPIO_PORTB_PIN5		(1 << PIN5)
#define GPIO_PORTB_PIN6		(1 << PIN6)
#define GPIO_PORTB_PIN7		(1 << PIN7)
// PortC
#define PORTC_PIN_NUM		32U
#define GPIO_PORTC_PIN0		(1 << PIN0)
#define GPIO_PORTC_PIN1		(1 << PIN1)
#define GPIO_PORTC_PIN2		(1 << PIN2)
#define GPIO_PORTC_PIN3		(1 << PIN3)
#define GPIO_PORTC_PIN4		(1 << PIN4)
#define GPIO_PORTC_PIN5		(1 << PIN5)
#define GPIO_PORTC_PIN6		(1 << PIN6)
#define GPIO_PORTC_PIN7		(1 << PIN7)
#define GPIO_PORTC_PIN8		(1 << PIN8)
#define GPIO_PORTC_PIN9		(1 << PIN9)
#define GPIO_PORTC_PIN10	(1 << PIN10)
#define GPIO_PORTC_PIN11	(1 << PIN11)
#define GPIO_PORTC_PIN12	(1 << PIN12)
#define GPIO_PORTC_PIN13	(1 << PIN13)
#define GPIO_PORTC_PIN14	(1 << PIN14)
#define GPIO_PORTC_PIN15	(1 << PIN15)
#define GPIO_PORTC_PIN16	(1 << PIN16)
#define GPIO_PORTC_PIN17	(1 << PIN17)
#define GPIO_PORTC_PIN18	(1 << PIN18)
#define GPIO_PORTC_PIN19	(1 << PIN19)
#define GPIO_PORTC_PIN20	(1 << PIN20)
#define GPIO_PORTC_PIN21	(1 << PIN21)
#define GPIO_PORTC_PIN22	(1 << PIN22)
#define GPIO_PORTC_PIN23	(1 << PIN23)
#define GPIO_PORTC_PIN24	(1 << PIN24)
#define GPIO_PORTC_PIN25	(1 << PIN25)
#define GPIO_PORTC_PIN26	(1 << PIN26)
#define GPIO_PORTC_PIN27	(1 << PIN27)
#define GPIO_PORTC_PIN28	(1 << PIN28)
#define GPIO_PORTC_PIN29	(1 << PIN29)
#define GPIO_PORTC_PIN30	(1 << PIN30)
#define GPIO_PORTC_PIN31	(1 << PIN31)
//PortD
#define PORTD_PIN_NUM		8U
#define GPIO_PORTD_PIN0		(1 << PIN0)
#define GPIO_PORTD_PIN1		(1 << PIN1)
#define GPIO_PORTD_PIN2		(1 << PIN2)
#define GPIO_PORTD_PIN3		(1 << PIN3)
#define GPIO_PORTD_PIN4		(1 << PIN4)
#define GPIO_PORTD_PIN5		(1 << PIN5)
#define GPIO_PORTD_PIN6		(1 << PIN6)
#define GPIO_PORTD_PIN7		(1 << PIN7)
//PortE
#define PORTE_PIN_NUM		8U
#define GPIO_PORTE_PIN0		(1 << PIN0)
#define GPIO_PORTE_PIN1		(1 << PIN1)
#define GPIO_PORTE_PIN2		(1 << PIN2)
#define GPIO_PORTE_PIN3		(1 << PIN3)
#define GPIO_PORTE_PIN4		(1 << PIN4)
#define GPIO_PORTE_PIN5		(1 << PIN5)
#define GPIO_PORTE_PIN6		(1 << PIN6)
#define GPIO_PORTE_PIN7		(1 << PIN7)


typedef enum {
	GPIO_OK = 0,
	GPIO_ERROR,
	GPIO_STATUS_NUM
}GPIO_status_t;

typedef enum{
	GPIO_PU_MODE = 0x00,
	GPIO_PD_MODE = 0x01,
	GPIO_PP_MODE = 0x02,
	GPIO_HI_MODE = 0x03,
	GPIO_MODES_NUM
}GPIO_Mode_t;

typedef enum{
	GPIO_DIRECTION_INPUT = 0x00,
	GPIO_DIRECTION_OUTPUT = 0x01,
	GPIO_DIRECTION_RANGE = 0x02
}GPIO_Direction_t;

#define LOW_LVL		0x00U
#define HIGH_LVL	0x01U

typedef enum{
	GPIO_OUTPUT_LOW = LOW_LVL,
	GPIO_OUTPUT_HIGH = HIGH_LVL,
	GPIO_OUTPUT_RANGE = 0x02
}GPIO_Output_lvl_t;


#endif /* INC_GPIO_INTERFACE_H_ */
