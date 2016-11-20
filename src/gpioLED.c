#include "gpioLED.h"
#include <stdlib.h>

void GPIO3_ModuleClkConfig(void){
    HWREG(SOC_CM_PER_REGS + CM_PER_GPIO3_CLKCTRL) |=
          CM_PER_GPIO3_CLKCTRL_MODULEMODE_ENABLE;

    HWREG(SOC_CM_PER_REGS + CM_PER_GPIO3_CLKCTRL) |=
          CM_PER_GPIO3_CLKCTRL_OPTFCLKEN_GPIO_3_GDBCLK;

}

void GPIO2_ModuleClkConfig(void){
    HWREG(SOC_CM_PER_REGS + CM_PER_GPIO2_CLKCTRL) |=
          CM_PER_GPIO2_CLKCTRL_MODULEMODE_ENABLE;

    HWREG(SOC_CM_PER_REGS + CM_PER_GPIO2_CLKCTRL) |=
          CM_PER_GPIO2_CLKCTRL_OPTFCLKEN_GPIO_2_GDBCLK;

}

void GPIO1_ModuleClkConfig(void){
	/* Writing to MODULEMODE field of CM_PER_GPIO1_CLKCTRL register. */  

    HWREG(SOC_CM_PER_REGS + CM_PER_GPIO1_CLKCTRL) |=
          CM_PER_GPIO1_CLKCTRL_MODULEMODE_ENABLE;
    /*
    ** Writing to OPTFCLKEN_GPIO_1_GDBCLK bit in CM_PER_GPIO1_CLKCTRL
    ** register.
    */
    HWREG(SOC_CM_PER_REGS + CM_PER_GPIO1_CLKCTRL) |=
          CM_PER_GPIO1_CLKCTRL_OPTFCLKEN_GPIO_1_GDBCLK;

}

void GPIO0_ModuleClkConfig(void){
    HWREG(SOC_CM_WKUP_REGS + CM_WKUP_GPIO0_CLKCTRL) |=
          CM_WKUP_GPIO0_CLKCTRL_MODULEMODE_ENABLE;

    HWREG(SOC_CM_WKUP_REGS + CM_WKUP_GPIO0_CLKCTRL) |=
          CM_WKUP_GPIO0_CLKCTRL_OPTFCLKEN_GPIO0_GDBCLK;
}

/*FUNCTION*-------------------------------------------------------
*
* Function Name : GPIOPinMuxSetup
* Comments      : This function does the pin multiplexing for any GPIO Pin.
*
* \param  offsetAddr   This is the offset address of the Pad Control Register
*                      corresponding to the GPIO pin. These addresses are
*                      offsets with respect to the base address of the
*                      Control Module.
* \param  padConfValue This is the value to be written to the Pad Control
*                      register whose offset address is given by 'offsetAddr'.
*
* The 'offsetAddr' and 'padConfValue' can be obtained from macros defined
* in the file 'include/armv7a/am335x/pin_mux.h'.\n
*END*-----------------------------------------------------------*/
void GPIOPinMuxSetup(unsigned int offsetAddr, unsigned int padConfValue){
        HWREG(SOC_CONTROL_REGS + offsetAddr) = (padConfValue);
        HWREG(SOC_CONTROL_REGS + offsetAddr) |= CONTROL_CONF_RXACTIVE;
        HWREG(SOC_CONTROL_REGS + offsetAddr) &= ~(CONTROL_CONF_PULLUPSEL);
        HWREG(SOC_CONTROL_REGS + offsetAddr) &= ~(CONTROL_CONF_PULLUDDISABLE);
}

/*FUNCTION*-------------------------------------------------------
*
* Function Name : SPIOModuleEnable 
* Comments      : This API is used to enable the GPIO module. When 
* the GPIO module is enabled, the clocks to the module are not gated.
*
* \param  baseAdd    The memory address of the GPIO instance being used
*END*-----------------------------------------------------------*/
void GPIOModuleEnable(unsigned int baseAdd){
    HWREG(baseAdd + GPIO_CTRL) &= ~(GPIO_CTRL_DISABLEMODULE);
}

/*FUNCTION*-------------------------------------------------------
*
* Function Name : SPIOModuleEnable 
* Comments      : This API performs the module reset of the GPIO 
* module. It also waits until the reset process is complete.
*
* \param  baseAdd    The memory address of the GPIO instance being used
*END*-----------------------------------------------------------*/
void GPIOModuleReset(unsigned int baseAdd){
    HWREG(baseAdd + GPIO_SYSCONFIG) |= (GPIO_SYSCONFIG_SOFTRESET);
}

/*FUNCTION*-------------------------------------------------------
*
* Function Name : GPIODirModeSet
* Comments      : This API configures the direction of a specified 
* GPIO pin as being either input or output.
*
* \param  baseAdd       The memory address of the GPIO instance being used
* \param  pinNumber     The number of the pin in the GPIO instance
* \param  pinDirection  The required direction for the GPIO pin
*
* 'pinNumber' can take one of the following values:
* (0 <= pinNumber <= 31)\n
*
* 'pinDirection' can take one of the following values:
* - GPIO_DIR_INPUT - to configure the pin as an input pin\n
* - GPIO_DIR_OUTPUT - to configure the pin as an output pin\n
*END*-----------------------------------------------------------*/
void GPIODirModeSet(unsigned int baseAdd,
                            unsigned int pinNumber,
                            unsigned int pinDirection) {
    /* Checking if pin is required to be an output pin. */
    if(DIR_OUTPUT == pinDirection){
        HWREG(baseAdd + GPIO_OE) &= ~(1 << pinNumber);
    }else{
        HWREG(baseAdd + GPIO_OE) |= (1 << pinNumber);
    }
}

/*FUNCTION*-------------------------------------------------------
*
* Function Name : GPIOPinWrite
* Comments      : This API drives an output GPIO pin to a logic 
* HIGH or a logic LOW state.
*
* \param  baseAdd     The memory address of the GPIO instance being used
* \param  pinNumber   The number of the pin in the GPIO instance
* \param  pinValue    This specifies whether a logic HIGH or a logic LOW
*                     should be driven on the output pin
*
* 'pinNumber' can take one of the following values:
* (0 <= pinNumber <= 31)\n
*
* 'pinValue' can take one of the following values:
* - GPIO_PIN_LOW - indicating to drive a logic LOW(logic 0) on the pin.
* - GPIO_PIN_HIGH - indicating to drive a logic HIGH(logic 1) on the pin.
*END*-----------------------------------------------------------*/
void GPIOPinWrite(unsigned int baseAdd, unsigned int pinNumber, unsigned int pinValue){
    if(PIN_HIGH == pinValue){
        HWREG(baseAdd + GPIO_SETDATAOUT) = (1 << pinNumber);
    }else{
        HWREG(baseAdd + GPIO_CLEARDATAOUT) = (1 << pinNumber);
    }
}

int getPinValue(int nGpio, int modulo){
    int *address = (int*)(GPIO_INSTANCE_ADDRESS(modulo) + GPIO_DATAIN);
    int value = *address;
    return (value & (1 << nGpio));
}

void playNota(unsigned int nGpio, unsigned int modulo, int frequencia){
    int i = 0x4AF;
    while(i){
      GPIOHigh(nGpio, modulo);
      Delay(frequencia);
      GPIOLow(nGpio, modulo);
      Delay(frequencia);
      i--;
    }
}

void GPIOHigh(unsigned int nGpio, unsigned int modulo){
    GPIOPinWrite(GPIO_INSTANCE_ADDRESS(modulo), GPIO_INSTANCE_PIN_NUMBER(nGpio), PIN_HIGH);     
}

void GPIOLow(int unsigned nGpio, unsigned int modulo){
    GPIOPinWrite(GPIO_INSTANCE_ADDRESS(modulo), GPIO_INSTANCE_PIN_NUMBER(nGpio), PIN_LOW); 
}

void blink(unsigned int nGpio, unsigned int modulo){
  GPIOHigh(nGpio, modulo);
  Delay(0xFFFFFF);
  GPIOLow(nGpio, modulo);
  Delay(0xFFFFFF); 
}

Nota* insertLista(Nota* l, unsigned int LED, unsigned int frequencia){
	Nota* newList = (Nota*)malloc(sizeof(Nota));
	newList->led = LED;
	newList->frequencia_nota = frequencia;
	newList->next = l;
	return newList;
}

Nota* inverteLista(Nota* l){
	Nota* aux = NULL;
	while(l != NULL){
		aux = insertLista(aux, l->led, l->frequencia_nota);
		l = l->next;
	}
	return aux;
}

void playMusicSaved(Nota* notas_saved){
	notas_saved = inverteLista(notas_saved);
	if(notas_saved == NULL){
		GPIOHigh(BUZZER, MODULO_2);
		exit(0);
	}
	while(notas_saved != NULL){
		GPIOHigh(notas_saved->led, MODULO_2);
		playNota(BUZZER, MODULO_2, notas_saved->frequencia_nota);
		GPIOLow(notas_saved->led, MODULO_2);
		Nota* aux = notas_saved;
		notas_saved = notas_saved->next;
		free(aux);
	}
}

void Delay(int count){
  while(count--);
    asm("nop");
}
