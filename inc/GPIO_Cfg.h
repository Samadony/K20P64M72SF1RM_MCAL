/*
 * GPIO_cfg.h
 *
 *  Created on: Nov 12, 2021
 *      Author: woraelsa
 */

#ifndef INC_GPIO_CFG_H_
#define INC_GPIO_CFG_H_

#include "GPIO_Interface.h"

// Definitions
#define GPIO_NUM_OF_PORTS	5U
#define PORTA_IDX			0
#define PORTB_IDX			1
#define PORTC_IDX			2
#define PORTD_IDX			3
#define PORTE_IDX			4

// Types
typedef struct {
	GPIO_Mode_t GPIO_PinMode;
	GPIO_Direction_t GPIO_Direction;
}GPIO_PinCfg_t;

typedef struct{
	GPIO_PinCfg_t GPIO_PinCfg[PORTA_PIN_NUM];
}PortA_Cfg_t;

typedef struct{
	GPIO_PinCfg_t GPIO_PinCfg[PORTB_PIN_NUM];
}PortB_Cfg_t;

typedef struct{
	GPIO_PinCfg_t GPIO_PinCfg[PORTC_PIN_NUM];
}PortC_Cfg_t;

typedef struct{
	GPIO_PinCfg_t GPIO_PinCfg[PORTD_PIN_NUM];
}PortD_Cfg_t;

typedef struct{
	GPIO_PinCfg_t GPIO_PinCfg[PORTE_PIN_NUM];
}PortE_Cfg_t;

typedef struct{
	PortA_Cfg_t PortA_Cfg;
	PortB_Cfg_t PortB_Cfg;
	PortC_Cfg_t PortC_Cfg;
	PortD_Cfg_t PortD_Cfg;
	PortE_Cfg_t PortE_Cfg;
}GPIO_PortsCfg_t;

#endif /* INC_GPIO_CFG_H_ */
