/***************************************************************************************************
BSD 3-Clause License


Copyright (c) 2023, NewTec GmbH - www.newtec.de
All rights reserved.


Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:


1. Redistributions of source code must retain the above copyright notice, this
   list of conditions and the following disclaimer.


2. Redistributions in binary form must reproduce the above copyright notice,
   this list of conditions and the following disclaimer in the documentation
   and/or other materials provided with the distribution.


3. Neither the name of the copyright holder nor the names of its
   contributors may be used to endorse or promote products derived from
   this software without specific prior written permission.


THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
***************************************************************************************************/
/**
@addtogroup Interfaces
@{
@file       NVMInterface.cpp

NVM Interface for Lawicel Protocol


***************************************************************************************************/
/* INCLUDES ***************************************************************************************/
#include "NVMInterface.h"

/* C-Interface ************************************************************************************/
extern "C"
{
}

/* CONSTANTS **************************************************************************************/

/**
 *  Key Definition (Addresses) to be read by NVM Adapter for initialization
 */
const char *NVMInterface::INIT_SERIAL_BAUD = "SerialBaud"; /**< Initial Serial Baudrate*/
const char *NVMInterface::INIT_TIMESTAMP = "ToggleTime";   /**< Initial State of Timestamp*/
const char *NVMInterface::INIT_AUTO_START = "AutoStart";   /**< Initial State of Autostart*/
const char *NVMInterface::INIT_CAN_BAUD = "CanBaud";       /**< Initial CAN Baudrate*/
const char *NVMInterface::INIT_FILTER_MODE = "FilterMode"; /**< Initial Filter Mode*/
const char *NVMInterface::INIT_FILTER_ACN = "FilterACn";   /**< Initial Filter Address*/
const char *NVMInterface::INIT_FILTER_AMN = "FilterAMn";   /**< Initial Filter Mask*/

/* MACROS *****************************************************************************************/

/* TYPES ******************************************************************************************/

/* PROTOTYPES *************************************************************************************/

/* VARIABLES **************************************************************************************/

/* PUBLIC METHODES ********************************************************************************/

/* EXTERNAL FUNCTIONS *****************************************************************************/

/* INTERNAL FUNCTIONS *****************************************************************************/

/** @} */