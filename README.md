# Lawicel Protocol

This Project implements the Lawicel Protocol found in the [CAN232 Website](http://www.can232.com/docs/can232_v3.pdf).

# Getting Started
The Lawicel Class requires 3 Adapters in order to work:
- SerialAdapter -> Implements the SerialInterface Class
- CANAdapter -> Implements the CANInterface Class
- NVMAdapter -> Implements the NVMInterface Class

Each implementation must be written by the user, depending on the hardware and use-case in which the library will be used. 

For example, using the Espressif ESP32 Microcontroller:
- Serial Adapter: uses the UART Peripheral
- CAN Adapter: uses the SJA1000 CAN Controller of the Processor
- NVM Adapter: uses the persistent memory capability of the Processor

Once the Adapters are implemented, these must be instanced and passed to the Lawicel Instance as arguments:

```cpp
static SerialAdapter gSerialAdapter; /**< Serial Adapter Instance */
static CANAdapter gSja1000Adapter;   /**< CAN Adapter Instance */
static NVMAdapter gFlashAdapter;     /**< NVM Adapter Instance */

/** Lawicel Protocol Instance */
static Lawicel gProtocolLawicel(gSerialAdapter, gSja1000Adapter, gFlashAdapter);
```

A basic Arduino program would then look like this:
```cpp
void setup()
{
    if (!gProtocolLawicel.begin())
    {
        // Handle Error
    }
}

void loop()
{
    gProtocolLawicel.executeCycle();
}
```

# Changes to the Protocol

All the specified Commands specified in the Document are implemented and work as described. In addition to these, one command was added to get the current configuration of the system:

**D[CR]** 
Display System Information 
Returns: Dwxyz[CR]
* D: Display Settings Command
* w: Auto-start Status. 0=Deactivated, 1=Normal, 2=Listen Only
* x: CAN Baudrate. Follows same numeration as Sn[CR] Command
* y: Timestamp Status: 0=Deactivated, 1=Activated
* z: Channel Status. 0=Closed, 1=Normal, 2=Listen Only
* [CR]: Command Termination
