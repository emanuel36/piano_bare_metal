#include "gpioLED.h"

void selectUART(int nGpio){
    switch(nGpio){
//MODULO 1
        case GPIO_8:
            GPIOPinMuxSetup(CONTROL_CONF_UART_CTSN(0), CONTROL_CONF_MUXMODE(7));
            break;
        case GPIO_9:
            GPIOPinMuxSetup(CONTROL_CONF_UART_RTSN(0), CONTROL_CONF_MUXMODE(7));        
            break;
        case GPIO_10:
            GPIOPinMuxSetup(CONTROL_CONF_UART_RXD(0), CONTROL_CONF_MUXMODE(7));
            break;
        case GPIO_11:
            GPIOPinMuxSetup(CONTROL_CONF_UART_TXD(0), CONTROL_CONF_MUXMODE(7));
            break;
//FIM MODULO 1

//MODULO 0
		  case GPIO_12:
            GPIOPinMuxSetup(CONTROL_CONF_UART_CTSN(1), CONTROL_CONF_MUXMODE(7));
				break;
		  case GPIO_13:
				GPIOPinMuxSetup(CONTROL_CONF_UART_RTSN(1), CONTROL_CONF_MUXMODE(7));
				break;
		  case GPIO_14:
            GPIOPinMuxSetup(CONTROL_CONF_UART_RXD(1), CONTROL_CONF_MUXMODE(7));
				break;
		  case GPIO_15:
            GPIOPinMuxSetup(CONTROL_CONF_UART_TXD(1), CONTROL_CONF_MUXMODE(7));			
				break;
//FIM MODULO 0

    }
}

//MODULO 1
void selectCSN(int nGpio){
    switch(nGpio){
        case GPIO_29:
            GPIOPinMuxSetup(CONTROL_CONF_GPMC_CSN(0), CONTROL_CONF_MUXMODE(7));
            break;
        case GPIO_30:
            GPIOPinMuxSetup(CONTROL_CONF_GPMC_CSN(1), CONTROL_CONF_MUXMODE(7));
            break;
        case GPIO_31:
            GPIOPinMuxSetup(CONTROL_CONF_GPMC_CSN(2), CONTROL_CONF_MUXMODE(7));
            break;
    }    
}

// MODULO 0
void selectMII(int nGpio){
	switch(nGpio){
		case 16:
			GPIOPinMuxSetup(CONTROL_CONF_MII1_TXD3, CONTROL_CONF_MUXMODE(7));
			break;
		case 17:
			GPIOPinMuxSetup(CONTROL_CONF_MII1_TXD2, CONTROL_CONF_MUXMODE(7));
			break;
		case 21:
			GPIOPinMuxSetup(CONTROL_CONF_MII1_TXD1, CONTROL_CONF_MUXMODE(7));
			break;
		case 28:
			GPIOPinMuxSetup(CONTROL_CONF_MII1_TXD0, CONTROL_CONF_MUXMODE(7));
			break;
	}
	
}


//MODULO 0
void selectXDMA(int nGpio){
	switch(nGpio){
		case 19:
			GPIOPinMuxSetup(CONTROL_CONF_XDMA_EVENT_INTR(0), CONTROL_CONF_MUXMODE(7));
			break;
		case 20:
			GPIOPinMuxSetup(CONTROL_CONF_XDMA_EVENT_INTR(1), CONTROL_CONF_MUXMODE(7));
			break;
	}
}


//MODULO 0
void selectMDIO(int nGpio){
	switch(nGpio){
		case 0:
			GPIOPinMuxSetup(CONTROL_CONF_MDIO_DATA, CONTROL_CONF_MUXMODE(7));
			break;
		case 1:
			GPIOPinMuxSetup(CONTROL_CONF_MDIO_CLK, CONTROL_CONF_MUXMODE(7));
			break;
	}
}


//MODULO 0
void selectSPI0(int nGpio){
	switch(nGpio){
		case 2:
			GPIOPinMuxSetup(CONTROL_CONF_SPI0_SCLK, CONTROL_CONF_MUXMODE(7));
			break;
		case 3:
			GPIOPinMuxSetup(CONTROL_CONF_SPI0_D0, CONTROL_CONF_MUXMODE(7));
			break;
		case 4:
			GPIOPinMuxSetup(CONTROL_CONF_SPI0_D1, CONTROL_CONF_MUXMODE(7));
			break;
		case 5:
			GPIOPinMuxSetup(CONTROL_CONF_SPI0_CS0, CONTROL_CONF_MUXMODE(7));
			break;
		case 6:
			GPIOPinMuxSetup(CONTROL_CONF_SPI0_CS1, CONTROL_CONF_MUXMODE(7));
			break;
	}
}

//MODULO 2
void selectGPMC(int nGpio){
    switch(nGpio){
        case 0:
            GPIOPinMuxSetup(CONTROL_CONF_GPMC_CSN(3), CONTROL_CONF_MUXMODE(7));
        break;

        case 1:
            GPIOPinMuxSetup(CONTROL_CONF_GPMC_CLK, CONTROL_CONF_MUXMODE(7));
        break;

        case 2:
            GPIOPinMuxSetup(CONTROL_CONF_GPMC_ADVN_ALE, CONTROL_CONF_MUXMODE(7));
        break;
        
        case 3:
            GPIOPinMuxSetup(CONTROL_CONF_GPMC_OEN_REN, CONTROL_CONF_MUXMODE(7));
        break;
        
        case 4:
            GPIOPinMuxSetup(CONTROL_CONF_GPMC_WEN, CONTROL_CONF_MUXMODE(7));
        break;
        
        case 5:
            GPIOPinMuxSetup(CONTROL_CONF_GPMC_BE0N_CLE, CONTROL_CONF_MUXMODE(7));
        break;
    }
}

//MODULO 2
void selectMII1RXD(int nGpio){
    switch(nGpio){
        case 18:
            GPIOPinMuxSetup(CONTROL_CONF_MII1_RXD3, CONTROL_CONF_MUXMODE(7));
        break;

        case 19:
            GPIOPinMuxSetup(CONTROL_CONF_MII1_RXD2, CONTROL_CONF_MUXMODE(7));
        break;

        case 20:
            GPIOPinMuxSetup(CONTROL_CONF_MII1_RXD1, CONTROL_CONF_MUXMODE(7));
        break;
        
        case 21:
            GPIOPinMuxSetup(CONTROL_CONF_MII1_RXD0, CONTROL_CONF_MUXMODE(7));
        break;
    }
}

//MODULO 2
void selectLCD(int nGpio){
    switch(nGpio){
        case 22:
            GPIOPinMuxSetup(CONTROL_CONF_LCD_VSYNC, CONTROL_CONF_MUXMODE(7));
        break;

        case 23:
            GPIOPinMuxSetup(CONTROL_CONF_LCD_HSYNC, CONTROL_CONF_MUXMODE(7));
        break;

        case 24:
            GPIOPinMuxSetup(CONTROL_CONF_LCD_PCLK, CONTROL_CONF_MUXMODE(7));
        break;

        case 25:
            GPIOPinMuxSetup(CONTROL_CONF_LCD_AC_BIAS_EN, CONTROL_CONF_MUXMODE(7));
        break;
    }
}

//MODULO 2
void selectMMC0(int nGpio){
    switch(nGpio){
        case 26:
            GPIOPinMuxSetup(CONTROL_CONF_MMC0_DAT3 , CONTROL_CONF_MUXMODE(7));
        break;

        case 27:
            GPIOPinMuxSetup(CONTROL_CONF_MMC0_DAT2 , CONTROL_CONF_MUXMODE(7));
        break;

        case 28:
            GPIOPinMuxSetup(CONTROL_CONF_MMC0_DAT1, CONTROL_CONF_MUXMODE(7));
        break;
        
        case 29:
            GPIOPinMuxSetup(CONTROL_CONF_MMC0_DAT0 , CONTROL_CONF_MUXMODE(7));
        break;
        
        case 30:
            GPIOPinMuxSetup(CONTROL_CONF_MMC0_CLK, CONTROL_CONF_MUXMODE(7));
        break;
        
        case 31:
            GPIOPinMuxSetup(CONTROL_CONF_MMC0_CMD, CONTROL_CONF_MUXMODE(7));
        break;
    }
}

//MODULO 3
void selectMII1(int nGpio){
    switch(nGpio){
        case 0:
            GPIOPinMuxSetup(CONTROL_CONF_MII1_COL, CONTROL_CONF_MUXMODE(7));
        break;

        case 1:
            GPIOPinMuxSetup(CONTROL_CONF_MII1_CRS , CONTROL_CONF_MUXMODE(7));
        break;

        case 2:
            GPIOPinMuxSetup(CONTROL_CONF_MII1_RXERR, CONTROL_CONF_MUXMODE(7));
        break;
        
        case 3:
            GPIOPinMuxSetup(CONTROL_CONF_MII1_TXEN, CONTROL_CONF_MUXMODE(7));
        break;
        
        case 4:
            GPIOPinMuxSetup(CONTROL_CONF_MII1_RXDV, CONTROL_CONF_MUXMODE(7));
        break;

        case 9:
            GPIOPinMuxSetup(CONTROL_CONF_MII1_TXCLK, CONTROL_CONF_MUXMODE(7));
        break;

        case 10:
            GPIOPinMuxSetup(CONTROL_CONF_MII1_RXCLK, CONTROL_CONF_MUXMODE(7));
        break;
    }
}

//MODULO 3
void selectI2C0(int nGpio){
    switch(nGpio){
        case 7:
            GPIOPinMuxSetup(CONTROL_CONF_I2C0_SDA, CONTROL_CONF_MUXMODE(7));
        break;

        case 8:
            GPIOPinMuxSetup(CONTROL_CONF_I2C0_SCL, CONTROL_CONF_MUXMODE(7));
        break;

    }
}

//MODULO 3
void selectMCASPO(int nGpio){
    switch(nGpio){
        case 14:
            GPIOPinMuxSetup(CONTROL_CONF_MCASP0_ACLKX, CONTROL_CONF_MUXMODE(7));
        break;

        case 15:
            GPIOPinMuxSetup( CONTROL_CONF_MCASP0_FSX, CONTROL_CONF_MUXMODE(7));
        break;

        case 16:
            GPIOPinMuxSetup(CONTROL_CONF_MCASP0_AXR0, CONTROL_CONF_MUXMODE(7));
        break;
        
        case 17:
            GPIOPinMuxSetup(CONTROL_CONF_MCASP0_AHCLKR, CONTROL_CONF_MUXMODE(7));
        break;
        
        case 18:
            GPIOPinMuxSetup(CONTROL_CONF_MCASP0_ACLKR, CONTROL_CONF_MUXMODE(7));
        break;

        case 19:
            GPIOPinMuxSetup(CONTROL_CONF_MCASP0_FSR, CONTROL_CONF_MUXMODE(7));
        break;

        case 20:
            GPIOPinMuxSetup(CONTROL_CONF_MCASP0_AXR1, CONTROL_CONF_MUXMODE(7));
        break;

        case 21:
            GPIOPinMuxSetup(CONTROL_CONF_MCASP0_AHCLKX, CONTROL_CONF_MUXMODE(7));
        break;
    }
}