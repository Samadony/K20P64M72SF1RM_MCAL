

#include "unity.h"
#include "utils.h"
#include "stdint.h"
#include "stddef.h"
#include "GPIO_Core.h"
#include "MK20DX256.h"
/*%
 Goal:
 Initialize GPIO module to the pre-compile parameters

 Test steps:
 Arrange:
 - Initialize the TestPin to Output with PP mode

 Act:
 - Call GPIO_Initialize(const GPIO_PinCfg_t* const GPIO_PinCfg_t) to init the
 pins

 Assert:
 - All pins direction shall be : GPIO_INPUT
 - All Pins Mode shall be : GPIO_HI_MODE
 -  GPIO_Initialize(const GPIO_PinCfg_t* const GPIO_PinCfg_t) return status
 shall be GPIO_OK
 %*/

// Import configurations implicitly (subject of test)
extern GPIO_PortsCfg_t GPIO_PortsCfg;

void setUp(void)
{
	uint8_t iterator;
	//Arrange
	// Initialize directions of each port to be as opposed of expected
	//PORTA
	for(iterator = PIN0 ; iterator < PORTA_PIN_NUM; iterator++)
	{
		ASSIGN_BIT(PORTA.PDDR, iterator,
				(~(GET_BIT(GPIO_PortsCfg.PortA_Cfg.GPIO_PinCfg[iterator].GPIO_Direction,
						0))));
	}
	//PORTB
	for(iterator = PIN0 ; iterator < PORTB_PIN_NUM; iterator++)
	{
		ASSIGN_BIT(PORTB.PDDR, iterator,
				(~(GET_BIT(GPIO_PortsCfg.PortB_Cfg.GPIO_PinCfg[iterator].GPIO_Direction,
						0))));
	}
	//PORTC
	for(iterator = PIN0 ; iterator < PORTC_PIN_NUM; iterator++)
	{
		ASSIGN_BIT(PORTC.PDDR, iterator,
				(~(GET_BIT(GPIO_PortsCfg.PortC_Cfg.GPIO_PinCfg[iterator].GPIO_Direction,
						0))));
	}
	//PORTD
	for(iterator = PIN0 ; iterator < PORTD_PIN_NUM; iterator++)
	{
		ASSIGN_BIT(PORTD.PDDR, iterator,
				(~(GET_BIT(GPIO_PortsCfg.PortD_Cfg.GPIO_PinCfg[iterator].GPIO_Direction,
						0))));
	}
	//PORTE
	for(iterator = PIN0 ; iterator < PORTE_PIN_NUM; iterator++)
	{
		ASSIGN_BIT(PORTE.PDDR, iterator,
				(~(GET_BIT(GPIO_PortsCfg.PortE_Cfg.GPIO_PinCfg[iterator].GPIO_Direction,
						0))));
	}


}

void tearDown(void)
{
	//do nothing
}
/*
 Goal:
 Initialize The GPIO module based on CT configurations

 Test steps:
 Arrange:
 - Set the register bits to the opposite of whats expected

 Act:
 - Call GPIO_init with NULL pointer passed aas an argument
 Act:
 - Call GPIO initialize to assign the initial the pins according to the CT params

 Assert:
 - Assert per each port`s pin


 */

void testInit_TheCFGList_Equal(void)
{
    uint8_t iterator;
    GPIO_Direction_t lcl_gpio_dir;
    GPIO_status_t lcl_InitStatus;

    //Positive happy scenarios
    // Act
    lcl_InitStatus = GPIO_Initialize(&GPIO_PortsCfg);
    // Assert
    TEST_ASSERT_EQUAL(GPIO_OK, lcl_InitStatus);
    // Assert all pins including boundaries
    //PortA Assertion
    for(iterator = PIN0 ; iterator < PORTA_PIN_NUM; iterator++)
    {
    	TEST_ASSERT_BITS_MESSAGE((1 << iterator) ,
		(GET_BIT(GPIO_PortsCfg.PortA_Cfg.GPIO_PinCfg[iterator].GPIO_Direction,0)<<iterator),
		PORTA.PDDR,"PortA Assertion");
    }
    //PortB Assertion
    for(iterator = PIN0 ; iterator < PORTB_PIN_NUM; iterator++)
    {
    	TEST_ASSERT_BITS_MESSAGE((1 << iterator) ,
		(GET_BIT(GPIO_PortsCfg.PortB_Cfg.GPIO_PinCfg[iterator].GPIO_Direction,0)<<iterator),
		PORTB.PDDR,"PortB Assertion");
    }
    //PortC Assertion
    for(iterator = PIN0 ; iterator < PORTC_PIN_NUM; iterator++)
    {
    	TEST_ASSERT_BITS_MESSAGE((1 << iterator),
		(GET_BIT(GPIO_PortsCfg.PortC_Cfg.GPIO_PinCfg[iterator].GPIO_Direction,0)<<iterator),
		PORTC.PDDR,"PortC Assertion");
    }
    //PortD Assertion
    for(iterator = PIN0 ; iterator < PORTD_PIN_NUM; iterator++)
    {
    	TEST_ASSERT_BITS_MESSAGE((1 << iterator),
		(GET_BIT(GPIO_PortsCfg.PortD_Cfg.GPIO_PinCfg[iterator].GPIO_Direction,0)<<iterator),
		PORTD.PDDR,"PortD Assertion");
    }
    //PortE Assertion
    for(iterator = PIN0 ; iterator < PORTE_PIN_NUM; iterator++)
    {
    	TEST_ASSERT_BITS_MESSAGE((1 << iterator),
		(GET_BIT(GPIO_PortsCfg.PortE_Cfg.GPIO_PinCfg[iterator].GPIO_Direction,0)<<iterator),
		PORTE.PDDR,"PortE Assertion");
    }

    //Negative scenarios
    // Act
    lcl_InitStatus = GPIO_Initialize(NULL);
    // Assert
    TEST_ASSERT_EQUAL(GPIO_ERROR, lcl_InitStatus);

    // Arrange
    for(iterator = PIN0 ; iterator < PORTA_PIN_NUM ; iterator++)
    {
    	 GPIO_PortsCfg.PortA_Cfg.GPIO_PinCfg[iterator].GPIO_Direction = GPIO_DIRECTION_RANGE;
    }
    for(iterator = PIN0 ; iterator < PORTB_PIN_NUM ; iterator++)
    {
    	 GPIO_PortsCfg.PortB_Cfg.GPIO_PinCfg[iterator].GPIO_Direction = GPIO_DIRECTION_RANGE;
    }
    for(iterator = PIN0 ; iterator < PORTC_PIN_NUM ; iterator++)
    {
    	 GPIO_PortsCfg.PortC_Cfg.GPIO_PinCfg[iterator].GPIO_Direction = GPIO_DIRECTION_RANGE;
    }
    for(iterator = PIN0 ; iterator < PORTD_PIN_NUM ; iterator++)
    {
    	 GPIO_PortsCfg.PortD_Cfg.GPIO_PinCfg[iterator].GPIO_Direction = GPIO_DIRECTION_RANGE;
    }
    for(iterator = PIN0 ; iterator < PORTE_PIN_NUM ; iterator++)
    {
    	 GPIO_PortsCfg.PortE_Cfg.GPIO_PinCfg[iterator].GPIO_Direction = GPIO_DIRECTION_RANGE;
    }
    // Act
     lcl_InitStatus = GPIO_Initialize(&GPIO_PortsCfg);
    // Assert
     TEST_ASSERT_EQUAL(GPIO_ERROR, lcl_InitStatus);
}

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(testInit_TheCFGList_Equal);
    return UNITY_END();
}
