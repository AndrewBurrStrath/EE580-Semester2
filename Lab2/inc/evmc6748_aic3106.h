//-----------------------------------------------------------------------------
// \file    evmc6748_aic3106.h
// \brief   C6748 aic3106 definitions and function prototypes.
//
//-----------------------------------------------------------------------------

#ifndef EVMC6748_AIC3106_H
#define EVMC6748_AIC3106_H

//-----------------------------------------------------------------------------
// Public Defines and Macros
//-----------------------------------------------------------------------------

// aic3106 register defines.
#define AIC3106_REG_PAGESELECT                  (0)
#define AIC3106_REG_RESET                       (1)
#define AIC3106_REG_CODEC_SAMPLE_SELECT         (2)


//-----------------------------------------------------------------------------
// Public Function Prototypes
//-----------------------------------------------------------------------------
uint32_t AIC3106_init(void);
uint32_t AIC3106_readRegister(uint8_t in_reg_addr, uint8_t *dest_buffer);
uint32_t AIC3106_writeRegister(uint8_t in_reg_addr, uint8_t in_data);

#endif
