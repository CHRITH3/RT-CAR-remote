//
// Created by CHRIT on 25-7-16.
//

#include "Delay.h"
#include "main.h"

static uint32_t g_fac_us = 0;            /* us 延时倍乘数 */
/**
* @brief    初始化延时函数
* @param    无
* @retval   无
*/
void delay_init()
{
    g_fac_us = HAL_RCC_GetHCLKFreq() / 1000000;   //获取MCU的主频
}
/**
* @brief    us延时函数
* @param    nus:要延时的us数
* @note     nus取值范围：0 ~ (2^32 / fac_us)(fac_us一般等于系统主频)
* @retval   无
*/
void delay_us(uint32_t nus)
{
    uint32_t ticks;
    uint32_t told,tnow,tcnt = 0;
    uint32_t reload = SysTick->LOAD;    /*LOAD的值*/
    ticks = nus * g_fac_us;             /*需要的节拍数*/

    told = SysTick->VAL;                /*刚进入时的计数器值*/
    while(1)
    {
        tnow = SysTick->VAL;
        if(tnow != told)
        {
            if(tnow < told)
                tcnt += told - tnow; /*注意一下SYSTICK是一个递减的计数器*/
            else
                tcnt += reload - tnow + told;/*防止VAL减到0重装载了还没延时完*/
            told = tnow;
            if(tcnt >= ticks)
                break;            /*时间超过/等于要延时的时间，则退出*/
        }
    }
}
