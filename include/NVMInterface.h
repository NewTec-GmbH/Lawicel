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
@ingroup Lawicel
@{
@file       NVMInterface.h

NVM Interface for Lawicel Protocol

***************************************************************************************************/
#ifndef NVM_INTERFACE_H
#define NVM_INTERFACE_H

/* INCLUDES ***************************************************************************************/

#include <WString.h>
#include <cstdint>

/* C-Interface ************************************************************************************/
extern "C"
{
}

/* FORWARD DECLARATIONS ***************************************************************************/

/**
 *  Interface of the Lawicel Protocol to the NVM of the board. Defines the Methods to save and fetch  
 *  the initial parameters of the system.
 */
class NVMInterface
{
public:
    /* CONSTANTS ******************************************************************************/

    /**
     *  Key Definition (Addresses) to be read by NVM Adapter for initialization
     */
   static const char *INIT_SERIAL_BAUD; /**< Initial Serial Baudrate*/
   static const char *INIT_TIMESTAMP;   /**< Initial State of Timestamp*/
   static const char *INIT_AUTO_START;  /**< Initial State of Autostart*/
   static const char *INIT_CAN_BAUD;    /**< Initial CAN Baudrate*/
   static const char *INIT_FILTER_MODE; /**< Initial Filter Mode*/
   static const char *INIT_FILTER_ACN;  /**< Initial Filter Address*/
   static const char *INIT_FILTER_AMN;  /**< Initial Filter Mask*/

    /* TYPES **********************************************************************************/

    /**
     *  Default destructor deletes instance of the class.
     */
    virtual ~NVMInterface()
    {
    }

    /**
     *  Configures and starts the NVM Controller to use the user values.
     * 
     *  @return success
     */
    virtual bool begin() = 0;

    /**
     *  Stops the NVM Module without destroying the instance.
     * 
     *  @return success
     */
    virtual bool end() = 0;

    /**
     *  Save Data in NVM
     * 
     *  @param[in] name Key of Parameter to save
     *  @param[in] value Integer to save
     *  @return success
     */
    virtual bool save(const String &name, int32_t value) = 0;

    /**
     *  Save String in NVM
     * 
     *  @param[in] name Key of Parameter to save
     *  @param[in] value String to save
     *  @return success
     */
    virtual bool save(const String &name, const String &value) = 0;

    /**
     *  Read Data from NVM
     * 
     *  @param[in] name Key of Parameter to retrieve
     *  @return Integer corresponding to the Key, if existent. Zero otherwise
     */
    virtual uint32_t readInt(const String &name) = 0;

    /**
     *  Read String from NVM
     * 
     *  @param[in] name Key of Parameter to retrieve
     *  @return String corresponding to the Key, if existent. Empty String otherwise
     */
    virtual String readString(const String &name) = 0;

    /**
     *  Delete all NVM Entries.
     * 
     *  @return success
     */
    virtual bool clearEntries() = 0;

protected:
   /**
    *  Default constructor creates instance of the class using default values.
    */
   NVMInterface()
   {
   }

private:
};

/* INLINE FUNCTIONS ***************************************************************************/

/* PROTOTYPES *********************************************************************************/

#endif /* NVM_INTERFACE_H */

/** @} */