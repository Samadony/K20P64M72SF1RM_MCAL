#ifndef GPIO_H
#define GPIO_H

#include "utils.h"
#include "GPIO_Interface.h"
#include "GPIO_Cfg.h"

/*
 * APIs
 */
/**
 * @brief Initialize the GPIO based on the user pre-compilation configuration
 * @param Pointer to all pin configurations
 * @return error status
 */
PUBLIC GPIO_status_t GPIO_Initialize(const GPIO_PortsCfg_t* const GPIO_PinCfg_Ptr);

#endif //GPIO_H
