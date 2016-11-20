#include "gpioLED.h"

void initGPIO(int nGpio, int modulo, int direction){
    switch(modulo){
        case MODULO_0:
            GPIO0_ModuleClkConfig();
            modulo0(nGpio);
        break;

        case MODULO_1:
            GPIO1_ModuleClkConfig();
            modulo1(nGpio);
        break;

        case MODULO_2:
            GPIO2_ModuleClkConfig();
            modulo2(nGpio);
        break;

        case MODULO_3:
            GPIO3_ModuleClkConfig();
            modulo3(nGpio);
        break;
    }
        /* Enabling the GPIO module. */
    GPIOModuleEnable(GPIO_INSTANCE_ADDRESS(modulo));

    /* Resetting the GPIO module. */
    //GPIOModuleReset(GPIO_INSTANCE_ADDRESS(modulo));

    /* Setting the GPIO pin as an output pin. */
    GPIODirModeSet(GPIO_INSTANCE_ADDRESS(modulo),
               GPIO_INSTANCE_PIN_NUMBER(nGpio),
               direction);
}

void modulo0(int nGpio){
	int num;

	switch(nGpio){
		case GPIO_0 ... GPIO_1:
		selectMDIO(nGpio);
		break;

		case GPIO_2 ... GPIO_6:
		selectSPI0(nGpio);
		break;

		case GPIO_7:
		GPIOPinMuxSetup(CONTROL_CONF_ECAP0_IN_PWM0_OUT, CONTROL_CONF_MUXMODE(7));	
		break;

		case GPIO_8 ... GPIO_11:
		num = nGpio + 4;
		GPIOPinMuxSetup(CONTROL_CONF_LCD_DATA(num), CONTROL_CONF_MUXMODE(7));
		break;

		case GPIO_12 ... GPIO_15:
		selectUART(nGpio);
		break;

		case GPIO_16 ... GPIO_17:
		selectMII(nGpio);
		break;

		case GPIO_18:
		GPIOPinMuxSetup(CONTROL_CONF_USB_DRVVBUS(0), CONTROL_CONF_MUXMODE(7));	
		break;

		case GPIO_19 ... GPIO_20:
		selectXDMA(nGpio);
		break;

		case GPIO_21:
		selectMII(nGpio);
		break;

		case GPIO_22 ... GPIO_23:
		num = nGpio - 14;
		GPIOPinMuxSetup(CONTROL_CONF_GPMC_AD(num), CONTROL_CONF_MUXMODE(7));
		break;

		case GPIO_26 ... GPIO_27:
		num = nGpio - 16;
		GPIOPinMuxSetup(CONTROL_CONF_GPMC_AD(num), CONTROL_CONF_MUXMODE(7));
		break;

		case GPIO_28:
		selectMII(nGpio);
		break;

		case GPIO_29:
		GPIOPinMuxSetup(CONTROL_CONF_RMII1_REFCLK, CONTROL_CONF_MUXMODE(7));
		break;

		case GPIO_30:
		GPIOPinMuxSetup(CONTROL_CONF_GPMC_WAIT0, CONTROL_CONF_MUXMODE(7));
		break;

		case GPIO_31:
		GPIOPinMuxSetup(CONTROL_CONF_GPMC_WPN, CONTROL_CONF_MUXMODE(7));
		break;
	}
}

void modulo1(int nGpio){
    int num;

    switch(nGpio){
    	case GPIO_0 ... GPIO_7:
    	GPIOPinMuxSetup(CONTROL_CONF_GPMC_AD(nGpio), CONTROL_CONF_MUXMODE(7));
    	break;

    	case GPIO_12 ... GPIO_15:
    	GPIOPinMuxSetup(CONTROL_CONF_GPMC_A(7), CONTROL_CONF_MUXMODE(7));
    	break;

    	case GPIO_8 ... GPIO_11:
    	selectUART(nGpio);
    	break;

    	case GPIO_16 ... GPIO_27:
    	num = nGpio - 16;
        GPIOPinMuxSetup(CONTROL_CONF_GPMC_A(num), CONTROL_CONF_MUXMODE(7));
    	break;

    	case GPIO_28:
    	GPIOPinMuxSetup(CONTROL_CONF_GPMC_BE1N, CONTROL_CONF_MUXMODE(7));
    	break;

        case GPIO_29 ... GPIO_31:
        selectCSN(nGpio);
    	break;
    } 
}

void modulo2(int nGpio){
    int num;

    switch(nGpio){
    	case GPIO_0 ... GPIO_5:
    	selectGPMC(nGpio);
    	break;

    	case GPIO_6 ... GPIO_17:
    	num = nGpio - 6;
        GPIOPinMuxSetup(CONTROL_CONF_LCD_DATA(num), CONTROL_CONF_MUXMODE(7));
    	break;

    	case GPIO_18 ... GPIO_21:
    	num = nGpio - 18;
        selectMII1RXD(nGpio);
    	break; 

    	case GPIO_22 ... GPIO_25:
    	selectLCD(nGpio);
    	break;

    	case GPIO_26 ... GPIO_31:
    	selectMMC0(nGpio);
    	break;
    }
}

void modulo3(int nGpio){
    switch(nGpio){
    	case GPIO_0 ... GPIO_4:
    	selectMII1(nGpio);
    	break;

    	case GPIO_5 ... GPIO_6:
    	selectI2C0(nGpio);
    	break;

    	case GPIO_7 ... GPIO_8:
    	GPIOPinMuxSetup(CONTROL_CONF_EMU(0), CONTROL_CONF_MUXMODE(7));
    	break;

    	case GPIO_9 ... GPIO_10:
    	selectMII1(nGpio);
    	break;

    	case GPIO_13:
    	GPIOPinMuxSetup(CONTROL_CONF_USB_DRVVBUS(1), CONTROL_CONF_MUXMODE(7));
    	break;

    	case GPIO_14 ... GPIO_21:
    	selectMCASPO(nGpio);
    	break;
    }
}