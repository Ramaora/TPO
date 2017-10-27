#include "MyLPC1769.h"
#include "port.h"
#include "ssp.h"
#include "InfotronicKit.h"

/*********************************************************************//**
 * @brief 		Setup clock rate for SSP device
 * @param[in] 	SSPx	SSP peripheral definition, should be:
 * 						- LPC_SSP0: SSP0 peripheral
 * 						- LPC_SSP1: SSP1 peripheral
 * @param[in]	target_clock : clock of SSP (Hz)
 * @return 		None
 ***********************************************************************/
void setSSPclock (LPC_SSP *SSPx, uint32_t target_clock)
{
    uint32_t prescale, cr0_div, cmp_clk, ssp_clk=25000000;

    /* The SSP clock is derived from the (main system oscillator / 2),
       so compute the best divider from that clock */

	/* Find closest divider to get at or under the target frequency.
	   Use smallest prescale possible and rely on the divider to get
	   the closest target frequency */
	cr0_div = 0;
	cmp_clk = 0xFFFFFFFF;
	prescale = 2;
	while (cmp_clk > target_clock)
	{
		cmp_clk = ssp_clk / ((cr0_div + 1) * prescale);
		if (cmp_clk > target_clock)
		{
			cr0_div++;
			if (cr0_div > 0xFF)
			{
				cr0_div = 0;
				prescale += 2;
			}
		}
	}

    /* Write computed prescaler and divider back to register */
    SSPx->CR0 &= (~SSP_CR0_SCR(0xFF)) & SSP_CR0_BITMASK;
    SSPx->CR0 |= (SSP_CR0_SCR(cr0_div)) & SSP_CR0_BITMASK;
    SSPx->CPSR = prescale & SSP_CPSR_BITMASK;
}


/********************************************************************//**
 * @brief		Initializes the SSPx peripheral according to the specified
*               parameters in the SSP_ConfigStruct.
 * @param[in]	SSPx	SSP peripheral selected, should be:
 * 				 		- LPC_SSP0: SSP0 peripheral
 * 						- LPC_SSP1: SSP1 peripheral
 * @param[in]	SSP_ConfigStruct Pointer to a SSP_CFG_Type structure
*                    that contains the configuration information for the
*                    specified SSP peripheral.
 * @return 		None
 *********************************************************************/
void SSP_Init(LPC_SSP *SSPx, SSP_CFG_Type *SSP_ConfigStruct)
{
	uint32_t tmp;
	SetPinSel(MISO,2);
	SetPinSel(MOSI,2);
	SetPinSel(SCK,2);

	if (SSPx == (&SSP1))
	{
		PCONP |= (1<<10);
		PCLKSEL0 &= ~(0x03<<20); //SystemClock/4
	}
	/* Configure SSP, interrupt is disable, LoopBack mode is disable,
	 * SSP is disable, Slave output is disable as default
	 */
	tmp = ((SSP_ConfigStruct->CPHA) | (SSP_ConfigStruct->CPOL) \
		| (SSP_ConfigStruct->FrameFormat) | (SSP_ConfigStruct->Databit))
		& SSP_CR0_BITMASK;
	// write back to SSP control register
	SSPx->CR0 = tmp;

	tmp = SSP_ConfigStruct->Mode & SSP_CR1_BITMASK;
	// Write back to CR1
	SSPx->CR1 = tmp;

	// Set clock rate for SSP peripheral
	setSSPclock(SSPx, SSP_ConfigStruct->ClockRate);
}


/*****************************************************************************//**
* @brief		Get data size bit selected
* @param[in]	SSPx pointer to LPC_SSP_TypeDef structure, should be:
* 				- LPC_SSP0: SSP0 peripheral
* 				- LPC_SSP1: SSP1 peripheral
* @return		Data size, could be:
*				- SSP_DATABIT_4: 4 bit transfer
*				- SSP_DATABIT_5: 5 bit transfer
*				...
*				- SSP_DATABIT_16: 16 bit transfer
*******************************************************************************/
uint8_t SSP_GetDataSize(LPC_SSP* SSPx)
{
	return (SSPx->CR0 & (0xF));
}

/*****************************************************************************//**
* @brief		Fills each SSP_InitStruct member with its default value:
* 				- CPHA = SSP_CPHA_FIRST
* 				- CPOL = SSP_CPOL_HI
* 				- ClockRate = 1000000
* 				- Databit = SSP_DATABIT_8
* 				- Mode = SSP_MASTER_MODE
* 				- FrameFormat = SSP_FRAME_SSP
* @param[in]	SSP_InitStruct Pointer to a SSP_CFG_Type structure
*                    which will be initialized.
* @return		None
*******************************************************************************/
void SSP_ConfigStructInit(SSP_CFG_Type *SSP_InitStruct)
{
	SSP_InitStruct->CPHA = SSP_CPHA_FIRST;
	SSP_InitStruct->CPOL = SSP_CPOL_HI;
	SSP_InitStruct->ClockRate = 1000000;
	SSP_InitStruct->Databit = SSP_DATABIT_8;
	SSP_InitStruct->Mode = SSP_MASTER_MODE;
	SSP_InitStruct->FrameFormat = SSP_FRAME_SPI;
}


/*********************************************************************//**
 * @brief		Enable or disable SSP peripheral's operation
 * @param[in]	SSPx	SSP peripheral, should be:
 * 				- LPC_SSP0: SSP0 peripheral
 * 				- LPC_SSP1: SSP1 peripheral
 * @param[in]	NewState New State of SSPx peripheral's operation
 * @return 		none
 **********************************************************************/
void SSP_Cmd(LPC_SSP* SSPx, uint8_t NewState)
{

	if (NewState == 1)
	{
		SSPx->CR1 |= SSP_CR1_SSP_EN;
	}
	else
	{
		SSPx->CR1 &= (~SSP_CR1_SSP_EN) & SSP_CR1_BITMASK;
	}
}

/*********************************************************************//**
 * @brief		Enable or disable Loop Back mode function in SSP peripheral
 * @param[in]	SSPx	SSP peripheral selected, should be:
 *  					- LPC_SSP0: SSP0 peripheral
 * 						- LPC_SSP1: SSP1 peripheral
 * @param[in]	NewState	New State of Loop Back mode, should be:
 * 							- ENABLE: Enable this function
 * 							- DISABLE: Disable this function
 * @return 		None
 **********************************************************************/
void SSP_LoopBackCmd(LPC_SSP* SSPx, uint8_t NewState)
{

	if (NewState == 1)
	{
		SSPx->CR1 |= SSP_CR1_LBM_EN;
	}
	else
	{
		SSPx->CR1 &= (~SSP_CR1_LBM_EN) & SSP_CR1_BITMASK;
	}
}

/*********************************************************************//**
 * @brief		Enable or disable Slave Output function in SSP peripheral
 * @param[in]	SSPx	SSP peripheral selected, should be:
 * 						- LPC_SSP0: SSP0 peripheral
 * 						- LPC_SSP1: SSP1 peripheral
 * @param[in]	NewState	New State of Slave Output function, should be:
 * 							- ENABLE: Slave Output in normal operation
 * 							- DISABLE: Slave Output is disabled. This blocks
 * 							SSP controller from driving the transmit data
 * 							line (MISO)
 * Note: 		This function is available when SSP peripheral in Slave mode
 * @return 		None
 **********************************************************************/
void SSP_SlaveOutputCmd(LPC_SSP* SSPx, uint8_t NewState)
{

	if (NewState == 1)
	{
		SSPx->CR1 &= (~SSP_CR1_SO_DISABLE) & SSP_CR1_BITMASK;
	}
	else
	{
		SSPx->CR1 |= SSP_CR1_SO_DISABLE;
	}
}



/*********************************************************************//**
 * @brief		Transmit a single data through SSPx peripheral
 * @param[in]	SSPx	SSP peripheral selected, should be:
 * 						- LPC_SSP0: SSP0 peripheral
 * 						- LPC_SSP1: SSP1 peripheral
 * @param[in]	Data	Data to transmit (must be 16 or 8-bit long,
 * 						this depend on SSP data bit number configured)
 * @return 		none
 **********************************************************************/
void SSP_SendData(LPC_SSP* SSPx, uint16_t Data)
{
	SSPx->DR = SSP_DR_BITMASK(Data);
}



/*********************************************************************//**
 * @brief		Receive a single data from SSPx peripheral
 * @param[in]	SSPx	SSP peripheral selected, should be
 * 						- LPC_SSP0: SSP0 peripheral
 * 						- LPC_SSP1: SSP1 peripheral
 * @return 		Data received (16-bit long)
 **********************************************************************/
uint16_t SSP_ReceiveData(LPC_SSP* SSPx)
{
	return ((uint16_t) (SSP_DR_BITMASK(SSPx->DR)));
}

/*********************************************************************//**
 * @brief 		SSP Read write data function
 * @param[in]	SSPx 	Pointer to SSP peripheral, should be
 * 						- LPC_SSP0: SSP0 peripheral
 * 						- LPC_SSP1: SSP1 peripheral
 * @param[in]	dataCfg	Pointer to a SSP_DATA_SETUP_Type structure that
 * 						contains specified information about transmit
 * 						data configuration.
 * @param[in]	xfType	Transfer type, should be:
 * 						- SSP_TRANSFER_POLLING: Polling mode
 * 						- SSP_TRANSFER_INTERRUPT: Interrupt mode
 * @return 		Actual Data length has been transferred in polling mode.
 * 				In interrupt mode, always return (0)
 * 				Return (-1) if error.
 * Note: This function can be used in both master and slave mode.
 ***********************************************************************/
uint32_t SSP_ReadWrite (LPC_SSP*SSPx, SSP_DATA_SETUP_Type *dataCfg)
{
	uint8_t *rdata8;
    uint8_t *wdata8;
	uint16_t *rdata16;
    uint16_t *wdata16;
    uint32_t stat;
    uint32_t tmp;
    uint32_t dataword;

    dataCfg->rx_cnt = 0;
    dataCfg->tx_cnt = 0;
    dataCfg->status = 0;


	/* Clear all remaining data in RX FIFO */
	while (SSPx->SR & SSP_SR_RNE){
		tmp = (uint32_t) SSP_ReceiveData(SSPx);
	}

	// Clear status
	SSPx->ICR = SSP_ICR_BITMASK;
	if(SSP_GetDataSize(SSPx)>8)
		dataword = 1;
	else dataword = 0;
	if (dataword == 0){
		rdata8 = (uint8_t *)dataCfg->rx_data;
		wdata8 = (uint8_t *)dataCfg->tx_data;
	} else {
		rdata16 = (uint16_t *)dataCfg->rx_data;
		wdata16 = (uint16_t *)dataCfg->tx_data;
	}
	while ((dataCfg->tx_cnt != dataCfg->length) || (dataCfg->rx_cnt != dataCfg->length)){
		if ((SSPx->SR & SSP_SR_TNF) && (dataCfg->tx_cnt != dataCfg->length)){
			// Write data to buffer
			if(dataCfg->tx_data == NULL){
				if (dataword == 0){
					SSP_SendData(SSPx, 0xFF);
					dataCfg->tx_cnt++;
				} else {
					SSP_SendData(SSPx, 0xFFFF);
					dataCfg->tx_cnt += 2;
				}
			} else {
				if (dataword == 0){
					SSP_SendData(SSPx, *wdata8);
					wdata8++;
					dataCfg->tx_cnt++;
				} else {
					SSP_SendData(SSPx, *wdata16);
					wdata16++;
					dataCfg->tx_cnt += 2;
				}
			}
		}
			// Check overrun error
		if ((stat = SSPx->RIS) & SSP_RIS_ROR){
			// save status and return
			dataCfg->status = stat | SSP_STAT_ERROR;
			return (0);
		}
			// Check for any data available in RX FIFO
		while ((SSPx->SR & SSP_SR_RNE) && (dataCfg->rx_cnt != dataCfg->length)){
			// Read data from SSP data
			tmp = SSP_ReceiveData(SSPx);
				// Store data to destination
			if (dataCfg->rx_data != NULL)
			{
				if (dataword == 0){
					*(rdata8) = (uint8_t) tmp;
					rdata8++;
				} else {
					*(rdata16) = (uint16_t) tmp;
						rdata16++;
				}
			}
			// Increase counter
			if (dataword == 0){
				dataCfg->rx_cnt++;
			} else {
				dataCfg->rx_cnt += 2;
			}
		}
	}

	// save status
	dataCfg->status = SSP_STAT_DONE;

	if (dataCfg->tx_data != NULL){
		return dataCfg->tx_cnt;
	} else if (dataCfg->rx_data != NULL){
		return dataCfg->rx_cnt;
	} else {
		return (0);
	}

	return (0);
}
