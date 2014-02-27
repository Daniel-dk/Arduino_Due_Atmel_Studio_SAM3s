/*
  Copyright (c) 2011 Arduino.  All right reserved.

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
  See the GNU Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/

#include "variant.h"



#ifdef __cplusplus
extern "C" {
#endif

/*
 * Pins descriptions
 */
extern const PinDescription g_APinDescription[]=
{
  // 0 .. 14 - Digital pins
  // ----------------------
  // 0/1 - UART (Serial)
  { PIOA, PIO_PA9A_URXD0,     ID_PIOA, PIO_PERIPH_A, PIO_DEFAULT,  PIN_ATTR_DIGITAL,                 NO_ADC, NO_ADC, NOT_ON_PWM,  NOT_ON_TIMER }, // URXD // done
  { PIOA, PIO_PA10A_UTXD0,     ID_PIOA, PIO_PERIPH_A, PIO_DEFAULT,  PIN_ATTR_DIGITAL,                 NO_ADC, NO_ADC, NOT_ON_PWM,  NOT_ON_TIMER }, // UTXD // done

  // 2
  { PIOA, PIO_PA16C_PWML2,   ID_PIOA, PIO_PERIPH_C, PIO_DEFAULT, (PIN_ATTR_DIGITAL|PIN_ATTR_PWM), NO_ADC, NO_ADC, PWM_CH2,  NOT_ON_TIMER     }, // PMWL2 // DONE
  { PIOA, PIO_PA15C_PWML3,   ID_PIOA, PIO_PERIPH_C, PIO_DEFAULT, (PIN_ATTR_DIGITAL|PIN_ATTR_PWM), NO_ADC, NO_ADC, PWM_CH3,  NOT_ON_TIMER     },//  PMWL3 // DONE
  { PIOA, PIO_PA2		 ,  ID_PIOA, PIO_OUTPUT_0, PIO_DEFAULT , PIN_ATTR_DIGITAL				, NO_ADC, NO_ADC, NOT_ON_PWM,  NOT_ON_TIMER     }, // DIO DEFAULT LOW // DONE 
  { PIOA, PIO_PA7		 ,  ID_PIOA, PIO_OUTPUT_0, PIO_DEFAULT , PIN_ATTR_DIGITAL				, NO_ADC, NO_ADC, NOT_ON_PWM,  NOT_ON_TIMER     }, // DIO DEFAULT LOW // DONE 
  { PIOA, PIO_PA8		 ,  ID_PIOA, PIO_OUTPUT_0, PIO_DEFAULT , PIN_ATTR_DIGITAL				, NO_ADC, NO_ADC, NOT_ON_PWM,  NOT_ON_TIMER     }, // DIO DEFAULT LOW // DONE 
  // 7
  { PIOA, PIO_PA1B_TIOB0,   ID_PIOA, PIO_PERIPH_B, PIO_DEFAULT, (PIN_ATTR_DIGITAL|PIN_ATTR_TIMER),   NO_ADC  , NO_ADC, NOT_ON_PWM,	TC0_CHB0    }, // TIOB0 // DONE
  { PIOA, PIO_PA0B_TIOA0,   ID_PIOA, PIO_PERIPH_B, PIO_DEFAULT, (PIN_ATTR_DIGITAL|PIN_ATTR_TIMER),   NO_ADC, NO_ADC, NOT_ON_PWM,     TC0_CHA0 },   // TIOA0 // DONE
  { PIOB, PIO_PB6		,   ID_PIOB, PIO_OUTPUT_0, PIO_DEFAULT, PIN_ATTR_DIGITAL				 ,   NO_ADC, NO_ADC, NOT_ON_PWM,     NOT_ON_TIMER }, // DIO DEFAULT LOW // DONE // USED FOR JTAG TOO
  { PIOB, PIO_PB7		,   ID_PIOB, PIO_OUTPUT_0, PIO_DEFAULT, PIN_ATTR_DIGITAL				 ,   NO_ADC, NO_ADC, NOT_ON_PWM,     NOT_ON_TIMER }, // DIO DEFAULT LOW // DONE // USED FOR JTAG TOO
  
  //11 /12 - UART1 (Serial2)
  { PIOB, PIO_PB3A_UTXD1,    ID_PIOB, PIO_PERIPH_A, PIO_DEFAULT, PIN_ATTR_DIGITAL,                  NO_ADC, NO_ADC, NOT_ON_PWM,  NOT_ON_TIMER }, // TXD1 // DONE
  { PIOB, PIO_PB2A_URXD1,    ID_PIOB, PIO_PERIPH_A, PIO_DEFAULT, PIN_ATTR_DIGITAL,                  NO_ADC, NO_ADC, NOT_ON_PWM,  NOT_ON_TIMER }, // RXD1 // DONE

  // 13/14 - USART0 (Serial1)
  { PIOA, PIO_PA6A_TXD0,    ID_PIOA, PIO_PERIPH_A, PIO_DEFAULT, PIN_ATTR_DIGITAL,                  NO_ADC, NO_ADC, NOT_ON_PWM,  NOT_ON_TIMER }, // TXD0 // DONE
  { PIOA, PIO_PA5A_RXD0,    ID_PIOA, PIO_PERIPH_A, PIO_DEFAULT, PIN_ATTR_DIGITAL,                  NO_ADC, NO_ADC, NOT_ON_PWM,  NOT_ON_TIMER }, // RXD0 // DONE

  // 15/16 - TWI0
  { PIOA, PIO_PA3A_TWD0,    ID_PIOA, PIO_PERIPH_A, PIO_DEFAULT, PIN_ATTR_DIGITAL,                  NO_ADC, NO_ADC, NOT_ON_PWM,  NOT_ON_TIMER }, // TWD0 - SDA0 // done
  { PIOA, PIO_PA4A_TWCK0,   ID_PIOA, PIO_PERIPH_A, PIO_DEFAULT, PIN_ATTR_DIGITAL,                  NO_ADC, NO_ADC, NOT_ON_PWM,  NOT_ON_TIMER }, // TWCK0 - SCL0 // done

  // 17 .. 22- Analog pins
  // ----------------------
  { PIOB, PIO_PB0X1_AD4,    ID_PIOB, PIO_INPUT,    PIO_DEFAULT, PIN_ATTR_ANALOG,                   ADC0,   ADC4,   NOT_ON_PWM,  NOT_ON_TIMER }, // AD0 // DONE
  { PIOB, PIO_PB1X1_AD5,    ID_PIOB, PIO_INPUT,    PIO_DEFAULT, PIN_ATTR_ANALOG,                   ADC1,   ADC5,   NOT_ON_PWM,  NOT_ON_TIMER }, // AD1 // DONE
  { PIOA, PIO_PA17X1_AD0,    ID_PIOA, PIO_INPUT,    PIO_DEFAULT, PIN_ATTR_ANALOG,                   ADC2,   ADC0,   NOT_ON_PWM,  NOT_ON_TIMER }, // AD2 // DONE
  { PIOA, PIO_PA18X1_AD1,    ID_PIOA, PIO_INPUT,    PIO_DEFAULT, PIN_ATTR_ANALOG,                   ADC3,   ADC1,   NOT_ON_PWM,  NOT_ON_TIMER }, // AD3 // DONE
  { PIOA, PIO_PA19X1_AD2,     ID_PIOA, PIO_INPUT,    PIO_DEFAULT, PIN_ATTR_ANALOG,                   ADC4,   ADC2,   NOT_ON_PWM,  NOT_ON_TIMER }, // AD4 // DONE
  { PIOA, PIO_PA20X1_AD3,     ID_PIOA, PIO_INPUT,    PIO_DEFAULT, PIN_ATTR_ANALOG,                   ADC5,   ADC3,   NOT_ON_PWM,  NOT_ON_TIMER }, // AD5 // DONE

  // 23/24 - TWI1
  { PIOB, PIO_PB4A_TWD1,    ID_PIOB, PIO_PERIPH_B, PIO_DEFAULT, PIN_ATTR_DIGITAL,                  NO_ADC, NO_ADC, NOT_ON_PWM,  NOT_ON_TIMER }, // TWD1 - SDA1 // DONE
  { PIOB, PIO_PB5A_TWCK1,   ID_PIOB, PIO_PERIPH_B, PIO_DEFAULT, PIN_ATTR_DIGITAL,                  NO_ADC, NO_ADC, NOT_ON_PWM,  NOT_ON_TIMER }, // TWCK1 - SCL1 // DONE
	  
  // 25/26/27 - SPI
  { PIOA, PIO_PA13A_MOSI,ID_PIOA,PIO_PERIPH_A, PIO_DEFAULT, PIN_ATTR_DIGITAL,                  NO_ADC, NO_ADC, NOT_ON_PWM,  NOT_ON_TIMER }, // M0Si // done
  { PIOA, PIO_PA12A_MISO,ID_PIOA,PIO_PERIPH_A, PIO_DEFAULT, PIN_ATTR_DIGITAL,                  NO_ADC, NO_ADC, NOT_ON_PWM,  NOT_ON_TIMER }, // MISO // done
  { PIOA, PIO_PA14A_SPCK,ID_PIOA,PIO_PERIPH_A, PIO_DEFAULT, PIN_ATTR_DIGITAL,                  NO_ADC, NO_ADC, NOT_ON_PWM,  NOT_ON_TIMER }, // SPCK // done

  // 28 - SPI CS0
  { PIOA, PIO_PA11A_NPCS0, ID_PIOA,PIO_PERIPH_A,PIO_DEFAULT, PIN_ATTR_DIGITAL,                  NO_ADC, NO_ADC, NOT_ON_PWM,  NOT_ON_TIMER }, // NPCS0 // DONE

  // 29 .. 33 - "All pins" masks

  // 29 - TWI0 all pins
  { PIOA, PIO_PA3A_TWD0|PIO_PA4A_TWCK0, ID_PIOA, PIO_PERIPH_A, PIO_DEFAULT, (PIN_ATTR_DIGITAL|PIN_ATTR_COMBO), NO_ADC, NO_ADC, NOT_ON_PWM, NOT_ON_TIMER }, // DONE
  // 30 - TWI1 all pins
  { PIOB, PIO_PB4A_TWD1|PIO_PB5A_TWCK1, ID_PIOB, PIO_PERIPH_A, PIO_DEFAULT, (PIN_ATTR_DIGITAL|PIN_ATTR_COMBO), NO_ADC, NO_ADC, NOT_ON_PWM, NOT_ON_TIMER }, // DONE

  // 31 - UART (Serial) all pins ( UART0 )
  { PIOA, PIO_PA9A_URXD0|PIO_PA10A_UTXD0, ID_PIOA, PIO_PERIPH_A, PIO_DEFAULT, (PIN_ATTR_DIGITAL|PIN_ATTR_COMBO), NO_ADC, NO_ADC, NOT_ON_PWM, NOT_ON_TIMER }, // DONE
  // 32 - USART0 (Serial1) all pins
  { PIOA, PIO_PA6A_TXD0|PIO_PA5A_RXD0, ID_PIOA, PIO_PERIPH_A, PIO_DEFAULT, (PIN_ATTR_DIGITAL|PIN_ATTR_COMBO), NO_ADC, NO_ADC, NOT_ON_PWM, NOT_ON_TIMER }, // DONE
  // 33 - UART1 (Serial2) all pins
  { PIOB, PIO_PB3A_UTXD1|PIO_PB2A_URXD1, ID_PIOB, PIO_PERIPH_A, PIO_DEFAULT, (PIN_ATTR_DIGITAL|PIN_ATTR_COMBO), NO_ADC, NO_ADC, NOT_ON_PWM, NOT_ON_TIMER }, // DONE
  // END
  { NULL, 0, 0, PIO_NOT_A_PIN, PIO_DEFAULT, 0, NO_ADC, NO_ADC, NOT_ON_PWM, NOT_ON_TIMER }
} ;

#ifdef __cplusplus
}
#endif

/*
 * UART objects
 */
RingBuffer rx_buffer1;
RingBuffer rx_buffer3;

UARTClass Serial(UART0, UART0_IRQn, ID_UART0, &rx_buffer1);
void serialEvent() __attribute__((weak));
void serialEvent() { }

UARTClass Serial2(UART1, UART1_IRQn, ID_UART1, &rx_buffer3);
void serialEvent2() __attribute__((weak));
void serialEvent2() { }

// IT handlers
void UART_Handler(void)
{
  Serial.IrqHandler();
}

void UART1_Handler(void)
{
	Serial2.IrqHandler();
}

// ----------------------------------------------------------------------------
/*
 * USART objects
 */
RingBuffer rx_buffer2;


USARTClass Serial1(USART0, USART0_IRQn, ID_USART0, &rx_buffer2);
void serialEvent1() __attribute__((weak));
void serialEvent1() { }

// IT handlers
void USART0_Handler(void)
{
  Serial1.IrqHandler();
}


// ----------------------------------------------------------------------------

void serialEventRun(void)
{
  if (Serial.available()) serialEvent();
  if (Serial1.available()) serialEvent1();
  if (Serial2.available()) serialEvent2();
}

// ----------------------------------------------------------------------------

#ifdef __cplusplus
extern "C" {
#endif

void __libc_init_array(void);

void init( void )
{
  SystemInit();

  // Set Systick to 1ms interval, common to all SAM3 variants
  if (SysTick_Config(SystemCoreClock / 1000))
  {
    // Capture error
    while (true);
  }

  // Disable watchdog
  WDT_Disable(WDT);

  // Initialize C library
  __libc_init_array();

  // Disable pull-up on every pin
  for (int i = 0; i < PINS_COUNT; i++)
	  digitalWrite(i, LOW);

  // Enable parallel access on PIO output data registers
  PIOA->PIO_OWER = 0xFFFFFFFF;
  PIOB->PIO_OWER = 0xFFFFFFFF;

  // Initialize Serial port U(S)ART pins
  PIO_Configure(
    g_APinDescription[PINS_UART].pPort,
    g_APinDescription[PINS_UART].ulPinType,
    g_APinDescription[PINS_UART].ulPin,
    g_APinDescription[PINS_UART].ulPinConfiguration);
  digitalWrite(0, HIGH); // Enable pullup for RX0

  PIO_Configure(
    g_APinDescription[PINS_USART0].pPort,
    g_APinDescription[PINS_USART0].ulPinType,
    g_APinDescription[PINS_USART0].ulPin,
    g_APinDescription[PINS_USART0].ulPinConfiguration);
  PIO_Configure(
    g_APinDescription[PINS_UART1].pPort,
    g_APinDescription[PINS_UART1].ulPinType,
    g_APinDescription[PINS_UART1].ulPin,
    g_APinDescription[PINS_UART1].ulPinConfiguration);

  // Initialize Analog Controller
  pmc_enable_periph_clk(ID_ADC);
  adc_init(ADC, SystemCoreClock, ADC_FREQ_MAX, ADC_STARTUP_FAST);
  adc_configure_timing(ADC, 0, ADC_SETTLING_TIME_3, 1);
  adc_configure_trigger(ADC, ADC_TRIG_SW, 0); // Disable hardware trigger.
  adc_disable_interrupt(ADC, 0xFFFFFFFF); // Disable all ADC interrupts.
  adc_disable_all_channel(ADC);

  // Initialize analogOutput module
   analogOutputInit();
}

#ifdef __cplusplus
}
#endif

