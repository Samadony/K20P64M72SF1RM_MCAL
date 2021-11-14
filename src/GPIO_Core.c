#include <stddef.h>
#include  <stdbool.h>
#include "stdint.h"
#include "GPIO_Core.h"
#include "MK20DX256.h"

// Private Prototypes
inline PRIVATE bool Is_Direction_Valid(GPIO_Direction_t GPIO_Direction_Cpy);


//Private Definitions



//Private Functions
inline PRIVATE bool Is_Direction_Valid(GPIO_Direction_t GPIO_Direction_Cpy){
	bool lcl_status ;
	if(GPIO_DIRECTION_RANGE > GPIO_Direction_Cpy)
	{
		lcl_status = true;
	}
	else
	{
		lcl_status = false;
	}
	return lcl_status;
}

// Public Functions
PUBLIC GPIO_status_t GPIO_Initialize(const GPIO_PortsCfg_t* const GPIO_PinCfg_Ptr)
{
	GPIO_status_t lcl_gpio_status;
	uint8_t pin_iterator;

	if(NULL != GPIO_PinCfg_Ptr)
	{
		lcl_gpio_status = GPIO_OK;
		//PORTA init
		for(pin_iterator = PIN0; pin_iterator < PORTA_PIN_NUM; pin_iterator++)
		{
			if(Is_Direction_Valid(GPIO_PinCfg_Ptr->PortA_Cfg.GPIO_PinCfg[pin_iterator].GPIO_Direction))
			{
				ASSIGN_BIT(PORTA.PDDR, pin_iterator,
						GPIO_PinCfg_Ptr->PortA_Cfg.GPIO_PinCfg[pin_iterator].GPIO_Direction);
			}
			else
			{
				lcl_gpio_status = GPIO_ERROR;
			}

		}
		//PORTB
		for(pin_iterator = PIN0; pin_iterator < PORTB_PIN_NUM; pin_iterator++)
		{
			if(Is_Direction_Valid(GPIO_PinCfg_Ptr->PortB_Cfg.GPIO_PinCfg[pin_iterator].GPIO_Direction))
			{
				ASSIGN_BIT(PORTB.PDDR, pin_iterator,
					GPIO_PinCfg_Ptr->PortB_Cfg.GPIO_PinCfg[pin_iterator].GPIO_Direction);
			}
			else
			{
				lcl_gpio_status = GPIO_ERROR;
			}
		}
		//PORTC
		for(pin_iterator = PIN0; pin_iterator < PORTC_PIN_NUM; pin_iterator++)
		{
			if(Is_Direction_Valid(GPIO_PinCfg_Ptr->PortC_Cfg.GPIO_PinCfg[pin_iterator].GPIO_Direction))
			{
				ASSIGN_BIT(PORTC.PDDR, pin_iterator,
						GPIO_PinCfg_Ptr->PortC_Cfg.GPIO_PinCfg[pin_iterator].GPIO_Direction);
			}
			else
			{
				lcl_gpio_status = GPIO_ERROR;
			}
		}
		//PORTD
		for(pin_iterator = PIN0; pin_iterator < PORTD_PIN_NUM; pin_iterator++)
		{
			if(Is_Direction_Valid(GPIO_PinCfg_Ptr->PortD_Cfg.GPIO_PinCfg[pin_iterator].GPIO_Direction))
			{
				ASSIGN_BIT(PORTD.PDDR, pin_iterator,
						GPIO_PinCfg_Ptr->PortD_Cfg.GPIO_PinCfg[pin_iterator].GPIO_Direction);
			}
			else
			{
				lcl_gpio_status = GPIO_ERROR;
			}
		}
		//PORTE
		for(pin_iterator = PIN0; pin_iterator < PORTD_PIN_NUM; pin_iterator++)
		{
			if(Is_Direction_Valid(GPIO_PinCfg_Ptr->PortE_Cfg.GPIO_PinCfg[pin_iterator].GPIO_Direction))
			{
				ASSIGN_BIT(PORTE.PDDR, pin_iterator,
						GPIO_PinCfg_Ptr->PortE_Cfg.GPIO_PinCfg[pin_iterator].GPIO_Direction);
			}
			else
			{
				lcl_gpio_status = GPIO_ERROR;
			}
		}
	}
	else
	{
		lcl_gpio_status = GPIO_ERROR;
	}

	return lcl_gpio_status;
}
