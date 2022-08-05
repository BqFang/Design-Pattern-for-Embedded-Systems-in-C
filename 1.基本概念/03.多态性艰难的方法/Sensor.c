#include <malloc.h>
#include "Sensor.h"

void Sensor_Init(Sensor* const me)
{

}

void Sensor_Cleanup(Sensor* const me)
{

}

int Sensor_getFilterFrequency(const Sensor* const me)
{
    return me->filterFrequency;
}

void Sensor_setFilterFrequency(Sensor* const me,int p_filterFrequency)
{
    me->filterFrequency = p_filterFrequency;
}

int Sensor_getUpdateFrequency(const Sensor* const me)
{
    return me->updateFrequency;
}

void Sensor_setUpdateFrequency(Sensor* const me,int p_updateFrequency)
{
    me->updateFrequency = p_updateFrequency;
}

int Sensor_getValue(const Sensor* const me)
{
    return me->value;
}

Sensor *Sensor_Create(void)
{
    Sensor* me = (Sensor*)malloc(sizeof(Sensor));
    if(me != NULL)
    {
        Sensor_Init(me);
    }
    return me;
}

void Sensor_Destroy(Sensor* const me)
{
    if(me != NULL)
    {
        Sensor_Cleanup(me);
    }

    free(me);
}

int acquireValue(Sensor* me)
{
    int *r,*w; /* 读、写地址*/
    int j;
    switch(me->whatKindOfInterface)
    {
        case MEMORYMAPPED:
            w = (int *) WRITEADDR; /* 写地址*/
            *w = WRITEMASK; /* 强制读取传感器命令 */
            for(j = 0; j < 100; j++)
            {
                /* wait loop*/
            }
            r = (int *)READADDR; /* 数据返回地址 */
            me->value = *r;
            break;
        case PORTMAPPED:
            me->value = inp(SENSORPORT); /* inp() 是特定编译器的一个接口函数 */
            break;
    } /* end switch */

    return me->value;
}