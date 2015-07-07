/**
 *  stm32tpl --  STM32 C++ Template Peripheral Library
 *
 *  Copyright (c) 2010-2014 Anton B. Gusev aka AHTOXA
 *
 *  Permission is hereby granted, free of charge, to any person obtaining a copy
 *  of this software and associated documentation files (the "Software"), to deal
 *  in the Software without restriction, including without limitation the rights
 *  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 *  copies of the Software, and to permit persons to whom the Software is
 *  furnished to do so, subject to the following conditions:
 *
 *  The above copyright notice and this permission notice shall be included in
 *  all copies or substantial portions of the Software.
 *
 *  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 *  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 *  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 *  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 *  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 *  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 *  THE SOFTWARE.
 *
 *
 *  @file         : stm32_uart_driver.h
 *  @description  : STM32 USART module driver.
 *  created on    : 09.11.2010
 *
 */

#ifndef STM32TPL_STM32_UART_DRIVER_H_INCLUDED
#define STM32TPL_STM32_UART_DRIVER_H_INCLUDED

#include "stm32.h"

namespace STM32
{
namespace UART
{
typedef uint32_t Baudrate;

/**
 * define count of UART modules
 */
#if (defined RCC_APB1ENR_UART8EN)
#	define UART_COUNT 8
#elif (defined RCC_APB1ENR_UART7EN)
#	define UART_COUNT 7
#elif (defined RCC_APB2ENR_USART6EN)
#	define UART_COUNT 6
#elif (defined RCC_APB1ENR_UART5EN)
#	define UART_COUNT 5
#elif (defined RCC_APB1ENR_UART4EN)
#	define UART_COUNT 4
#elif (defined RCC_APB1ENR_USART3EN)
#	define UART_COUNT 3
#else
#	define UART_COUNT 2
#endif

/**
*  @brief enum for UART device selection
*/
enum UartNum
{
	UART_1
	,UART_2
#if (UART_COUNT > 2)
	,UART_3
#endif
#if (UART_COUNT > 3)
	,UART_4
#endif
#if (UART_COUNT > 4)
	,UART_5
#endif
#if (UART_COUNT > 5)
	,UART_6
#endif
#if (UART_COUNT > 6)
	,UART_7
#endif
#if (UART_COUNT > 7)
	,UART_8
#endif
};

/**
*  @brief enum for remap state
*/
enum Remap { REMAP_NONE, REMAP_FULL, REMAP_PARTIAL };

/**
*  @brief UART pins selection template. Used internally.
*/
template<UartNum uartNum, Remap remapped = REMAP_NONE> struct UartPins;

template<> struct UartPins<UART_1>
{
	typedef Pin<'A', 9> PinTX;
	typedef Pin<'A', 10> PinRX;
#if (defined F2xxF4xx)
	static const PinAltFunction ALT_FUNC_USARTx = ALT_FUNC_USART1;
#elif (defined STM32L0XX)
	static const PinAltFunction ALT_FUNC_USARTx = ALT_FUNC_4;
#endif
};

template<> struct UartPins<UART_1, REMAP_FULL>
{
	typedef Pin<'B', 6> PinTX;
	typedef Pin<'B', 7> PinRX;
#if (defined F2xxF4xx)
	static const PinAltFunction ALT_FUNC_USARTx = ALT_FUNC_USART1;
#elif (defined STM32L0XX)
	static const PinAltFunction ALT_FUNC_USARTx = ALT_FUNC_0;
#endif
};

template<> struct UartPins<UART_2>
{
	typedef Pin<'A', 2> PinTX;
	typedef Pin<'A', 3> PinRX;
#if (defined F2xxF4xx)
	static const PinAltFunction ALT_FUNC_USARTx = ALT_FUNC_USART2;
#elif (defined STM32L0XX)
	static const PinAltFunction ALT_FUNC_USARTx = ALT_FUNC_4;
#endif
};

template<> struct UartPins<UART_2, REMAP_FULL>
{
#if (defined STM32L0XX)
	typedef Pin<'A', 14> PinTX;
	typedef Pin<'A', 15> PinRX;
#else
	typedef Pin<'D', 5> PinTX;
	typedef Pin<'D', 6> PinRX;
#endif
#if (defined F2xxF4xx)
	static const PinAltFunction ALT_FUNC_USARTx = ALT_FUNC_USART2;
#elif (defined STM32L0XX)
	static const PinAltFunction ALT_FUNC_USARTx = ALT_FUNC_4;
#endif
};

#if (UART_COUNT > 2)
template<> struct UartPins<UART_3>
{
	typedef Pin<'B', 10> PinTX;
	typedef Pin<'B', 11> PinRX;
#if (defined F2xxF4xx)
	static const PinAltFunction ALT_FUNC_USARTx = ALT_FUNC_USART3;
#endif
};

template<> struct UartPins<UART_3, REMAP_PARTIAL>
{
	typedef Pin<'C', 10> PinTX;
	typedef Pin<'C', 11> PinRX;
#if (defined F2xxF4xx)
	static const PinAltFunction ALT_FUNC_USARTx = ALT_FUNC_USART3;
#endif
};

template<> struct UartPins<UART_3, REMAP_FULL>
{
	typedef Pin<'D', 8> PinTX;
	typedef Pin<'D', 9> PinRX;
#if (defined F2xxF4xx)
	static const PinAltFunction ALT_FUNC_USARTx = ALT_FUNC_USART3;
#endif
};
#endif

#if (UART_COUNT > 3)
template<> struct UartPins<UART_4>
{
	typedef Pin<'C', 10> PinTX;
	typedef Pin<'C', 11> PinRX;
#if (defined F2xxF4xx)
	static const PinAltFunction ALT_FUNC_USARTx = ALT_FUNC_USART4
#endif
};
#endif

#if (UART_COUNT > 4)
template<> struct UartPins<UART_5>
{
	typedef Pin<'C', 12> PinTX;
	typedef Pin<'D', 2> PinRX;
#if (defined F2xxF4xx)
	static const PinAltFunction ALT_FUNC_USARTx = ALT_FUNC_USART5
#endif
};
#endif

#if (UART_COUNT > 5)
template<> struct UartPins<UART_6>
{
	typedef Pin<'C', 6> PinTX;
	typedef Pin<'C', 7> PinRX;
#if (defined F2xxF4xx)
	static const PinAltFunction ALT_FUNC_USARTx = ALT_FUNC_USART6
#endif
};

template<> struct UartPins<UART_6, REMAP_FULL>
{
	typedef Pin<'G', 14> PinTX;
	typedef Pin<'G', 9> PinRX;
#if (defined F2xxF4xx)
	static const PinAltFunction ALT_FUNC_USARTx = ALT_FUNC_USART6
#endif
};
#endif


/**
*  UART traits template.
*/
template<UartNum uartNum> struct UartTraits;

template<> struct UartTraits<UART_1>
{
	static const IRQn USARTx_IRQn  = USART1_IRQn;
	enum
	{
		USARTx_BASE               = USART1_BASE,
#if (defined AFIO_MAPR_USART1_REMAP)
		USARTx_REMAP              = AFIO_MAPR_USART1_REMAP,
#else
		USARTx_REMAP              = 0,
#endif
		USARTx_REMAP_PARTIAL      = 0,
		BUS_FREQ                  = chip::APB2_FREQ
	};
	INLINE static void EnableClocks()  { RCC->APB2ENR |= RCC_APB2ENR_USART1EN;  __DSB(); }
	INLINE static void DisableClocks() { RCC->APB2ENR &= ~RCC_APB2ENR_USART1EN; __DSB(); }
	INLINE static void Reset()         { RCC->APB2RSTR |= RCC_APB2RSTR_USART1RST; RCC->APB2RSTR &= ~RCC_APB2RSTR_USART1RST; }
};

template<> struct UartTraits<UART_2>
{
	static const IRQn USARTx_IRQn  = USART2_IRQn;
	enum
	{
		USARTx_BASE               = USART2_BASE,
#if (defined AFIO_MAPR_USART2_REMAP)
		USARTx_REMAP              = AFIO_MAPR_USART2_REMAP,
#else
		USARTx_REMAP              = 0,
#endif
		USARTx_REMAP_PARTIAL      = 0,
		BUS_FREQ                  = chip::APB1_FREQ
	};
	INLINE static void EnableClocks()  { RCC->APB1ENR |= RCC_APB1ENR_USART2EN;  __DSB(); }
	INLINE static void DisableClocks() { RCC->APB1ENR &= ~RCC_APB1ENR_USART2EN; __DSB(); }
	INLINE static void Reset()         { RCC->APB1RSTR |= RCC_APB1RSTR_USART2RST; RCC->APB1RSTR &= ~RCC_APB1RSTR_USART2RST; }
};

#if (UART_COUNT > 2)
template<> struct UartTraits<UART_3>
{
	static const IRQn USARTx_IRQn  = USART3_IRQn;
	enum
	{
		USARTx_BASE               = USART3_BASE,
#if (defined AFIO_MAPR_USART3_REMAP)
		USARTx_REMAP              = AFIO_MAPR_USART3_REMAP,
		USARTx_REMAP_PARTIAL      = AFIO_MAPR_USART3_REMAP_0,
#else
		USARTx_REMAP              = 0,
		USARTx_REMAP_PARTIAL      = 0,
#endif
		BUS_FREQ                  = chip::APB1_FREQ
	};
	INLINE static void EnableClocks()  { RCC->APB1ENR |= RCC_APB1ENR_USART3EN;  __DSB(); }
	INLINE static void DisableClocks() { RCC->APB1ENR &= ~RCC_APB1ENR_USART3EN; __DSB(); }
	INLINE static void Reset()         { RCC->APB1RSTR |= RCC_APB1RSTR_USART3RST; RCC->APB1RSTR &= ~RCC_APB1RSTR_USART3RST; }
};
#endif

#if (UART_COUNT > 3)
template<> struct UartTraits<UART_4>
{
	static const IRQn USARTx_IRQn  = UART4_IRQn;
	enum
	{
		USARTx_BASE               = UART4_BASE,
		USARTx_REMAP              = 0,
		USARTx_REMAP_PARTIAL      = 0,
		BUS_FREQ                  = chip::APB1_FREQ
	};
	INLINE static void EnableClocks()  { RCC->APB1ENR |= RCC_APB1ENR_UART4EN;  __DSB(); }
	INLINE static void DisableClocks() { RCC->APB1ENR &= ~RCC_APB1ENR_UART4EN; __DSB(); }
	INLINE static void Reset()         { RCC->APB1RSTR |= RCC_APB1RSTR_USART4RST; RCC->APB1RSTR &= ~RCC_APB1RSTR_USART4RST; }
};
#endif

#if (UART_COUNT > 4)
template<> struct UartTraits<UART_5>
{
	static const IRQn USARTx_IRQn  = UART5_IRQn;
	enum
	{
		USARTx_BASE               = UART5_BASE,
		USARTx_REMAP              = 0,
		USARTx_REMAP_PARTIAL      = 0,
		BUS_FREQ                  = chip::APB1_FREQ
	};
	INLINE static void EnableClocks()  { RCC->APB1ENR |= RCC_APB1ENR_UART5EN;  __DSB(); }
	INLINE static void DisableClocks() { RCC->APB1ENR &= ~RCC_APB1ENR_UART5EN; __DSB(); }
	INLINE static void Reset()         { RCC->APB1RSTR |= RCC_APB1RSTR_USART5RST; RCC->APB1RSTR &= ~RCC_APB1RSTR_USART5RST; }
};
#endif

#if (UART_COUNT > 5)
template<> struct UartTraits<UART_6>
{
	static const IRQn USARTx_IRQn  = USART6_IRQn;
	enum
	{
		USARTx_BASE               = USART6_BASE,
		USARTx_REMAP              = 0,
		USARTx_REMAP_PARTIAL      = 0,
		BUS_FREQ                  = chip::APB2_FREQ
	};
	INLINE static void EnableClocks()  { RCC->APB2ENR |= RCC_APB2ENR_USART6EN;  __DSB(); }
	INLINE static void DisableClocks() { RCC->APB2ENR &= ~RCC_APB2ENR_USART6EN; __DSB(); }
	INLINE static void Reset()         { RCC->APB2RSTR |= RCC_APB2RSTR_USART6RST; RCC->APB2RSTR &= ~RCC_APB2RSTR_USART6RST; }
};
#endif

/**
 * Dummy DE pin.
 * Used as DE pin when no DE pin needed.
 */
struct DummyDE
{
	INLINE static void On() { }
	INLINE static void Off() { }
	INLINE static void Cpl() { }
	INLINE static void Mode(direction) { }
	INLINE static int Latched() { return true; }
};

/**
 * USART peripheral registers for STM32L0XX chips.
 */
#if (defined STM32L0XX)
struct USARTx_TypeDef
{
	volatile uint32_t CR1;
	volatile uint32_t CR2;
	volatile uint32_t CR3;
	volatile uint32_t BRR;
	volatile uint32_t GTPR;
	volatile uint32_t RTOR;
	volatile uint32_t RQR;
	volatile uint32_t ISR;
	volatile uint32_t ICR;
	volatile uint32_t RDR;
	volatile uint32_t TDR;
};

/**
 * USART status flags for STM32L0XX chips.
 * Defined here because of inconsistency of this names in ST headers
 */
enum : uint32_t
{
	USART_FLAG_PE     = 0x00000001UL,
	USART_FLAG_FE     = 0x00000002UL,
	USART_FLAG_NE     = 0x00000004UL,
	USART_FLAG_ORE    = 0x00000008UL,
	USART_FLAG_IDLE   = 0x00000010UL,
	USART_FLAG_RXNE   = 0x00000020UL,
	USART_FLAG_TC     = 0x00000040UL,
	USART_FLAG_TXE    = 0x00000080UL,
	USART_FLAG_LBD    = 0x00000100UL,
	USART_FLAG_CTSIF  = 0x00000200UL,
	USART_FLAG_CTS    = 0x00000400UL,
	USART_FLAG_RTOF   = 0x00000800UL,
	USART_FLAG_EOBF   = 0x00001000UL,
	USART_FLAG_ABRE   = 0x00004000UL,
	USART_FLAG_ABRF   = 0x00008000UL,
	USART_FLAG_BUSY   = 0x00010000UL,
	USART_FLAG_CMF    = 0x00020000UL,
	USART_FLAG_SBKF   = 0x00040000UL,
	USART_FLAG_RWU    = 0x00080000UL,
	USART_FLAG_WUF    = 0x00100000UL,
	USART_FLAG_TEACK  = 0x00200000UL,
	USART_FLAG_REACK  = 0x00400000UL,
};

#else

/**
 * USART peripheral registers for all other chips.
 */
struct USARTx_TypeDef
{
	volatile uint16_t SR;
	uint16_t reserved0;
	volatile uint16_t DR;
	uint16_t reserved1;
	volatile uint16_t BRR;
	uint16_t reserved2;
	volatile uint16_t CR1;
	uint16_t reserved3;
	volatile uint16_t CR2;
	uint16_t reserved4;
	volatile uint16_t CR3;
	uint16_t reserved5;
	volatile uint16_t GTPR;
	uint16_t reserved6;
};

/**
 * USART status flags for all other chips.
 * Defined here because of inconsistency of this names in ST headers
 */
enum : uint16_t
{
	USART_FLAG_PE   = 0x0001,
	USART_FLAG_FE   = 0x0002,
	USART_FLAG_NE   = 0x0004,
	USART_FLAG_ORE  = 0x0008,
	USART_FLAG_IDLE = 0x0010,
	USART_FLAG_RXNE = 0x0020,
	USART_FLAG_TC   = 0x0040,
	USART_FLAG_TXE  = 0x0080,
	USART_FLAG_LBD  = 0x0100,
	USART_FLAG_CTS  = 0x0200,
};

#endif


/**
 * USART driver
 */
template<UartNum uartNum>
class UartDriver
{
private:
	typedef UartTraits<uartNum> Traits;
public:
	static const IRQn USARTx_IRQn = Traits::USARTx_IRQn;
	enum { USARTx_BASE            = Traits::USARTx_BASE };
	enum { USARTx_REMAP           = Traits::USARTx_REMAP };
	enum { USARTx_REMAP_PARTIAL   = Traits::USARTx_REMAP_PARTIAL };
	enum { BUS_FREQ               = Traits::BUS_FREQ };

	static IOStruct<USARTx_BASE, USARTx_TypeDef> USARTx;

	INLINE static void EnableClocks()    { Traits::EnableClocks(); }
	INLINE static void DisableClocks()   { Traits::DisableClocks(); }
	INLINE static void Enable()          { USARTx->CR1 |= USART_CR1_UE; }
	INLINE static void Disable()         { USARTx->CR1 &= ~USART_CR1_UE; }

	INLINE static void SetBaudrate(Baudrate value)   { USARTx->BRR = (BUS_FREQ + value/2) / value; }
	INLINE static Baudrate GetBaudrate()             { return BUS_FREQ / USARTx->BRR; }

#if (defined STM32L0XX)
	INLINE static uint32_t Status()                 { return USARTx->ISR; }
	INLINE static void ClearStatus(uint32_t flags)  { USARTx->ICR = flags; }
	INLINE static uint32_t ReadData()               { return USARTx->RDR; }
	INLINE static void WriteData(uint8_t data)      { USARTx->TDR = data; }
#else
	INLINE static uint16_t Status()                 { return USARTx->SR; }
	INLINE static void ClearStatus(uint32_t flags)  { USARTx->SR &= ~flags; }
	INLINE uint16_t ReadData()                      { return USARTx->DR; }
	INLINE void WriteData(uint8_t data)             { USARTx->DR = data; }
#endif

	struct RxInterrupt
	{
		static void Enable()    { USARTx->CR1 |= USART_CR1_RXNEIE; }
		static void Disable()   { USARTx->CR1 &= ~USART_CR1_RXNEIE; }
		static bool IsEnabled() { return USARTx->CR1 & USART_CR1_RXNEIE; }
		static bool Fired()     { return Status() & USART_FLAG_RXNE; }
	};

	struct TxInterrupt
	{
		static void Enable()    { USARTx->CR1 |= USART_CR1_TXEIE; }
		static void Disable()   { USARTx->CR1 &= ~USART_CR1_TXEIE; }
		static bool IsEnabled() { return USARTx->CR1 & USART_CR1_TXEIE; }
		static bool Fired()     { return Status() & USART_FLAG_TXE; }
	};

	struct TcInterrupt
	{
		static void Enable()    { USARTx->CR1 |= USART_CR1_TCIE; }
		static void Disable()   { USARTx->CR1 &= ~USART_CR1_TCIE; }
		static bool IsEnabled() { return USARTx->CR1 & USART_CR1_TCIE; }
		static bool Fired()     { return Status() & USART_FLAG_TC; }
		static void Clear()     { ClearStatus(USART_FLAG_TC); }
	};

public:
	INLINE operator uint8_t() { return ReadData(); }
};


} // namespace UART
} // namespace STM32


#endif // STM32TPL_STM32_UART_DRIVER_H_INCLUDED
