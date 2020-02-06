//-----------------------------------------------------------------------------
// \file    evmc6748_videoenc.h
// \brief   C6748 video encoder definitions and function prototypes.
//
//-----------------------------------------------------------------------------

#ifndef EVMC6748_VIDEOENC_H
#define EVMC6748_VIDEOENC_H

//-----------------------------------------------------------------------------
// Public Defines and Macros
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// Public Function Prototypes
//-----------------------------------------------------------------------------
uint32_t VIDEOENC_init(video_connector_e in_conn);
uint32_t VIDEOENC_readRegister(uint8_t in_sub_addr, uint8_t *dest_buffer);
uint32_t VIDEOENC_writeRegister(uint8_t in_sub_addr, uint8_t in_data);

#endif
