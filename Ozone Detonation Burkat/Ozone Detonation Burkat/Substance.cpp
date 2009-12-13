/**
* @file
*
* @author  ������� ������� <kabanovdmitry@gmail.com>
* @version %I%
*
* @section DESCRIPTION
*
* ���������� ������ Substance.
*/
#include "Substance.h"

Substance::Substance()
{
    nameOfSubstance     = "";
    enthalpyOfFormation = 0.0;
    molecularWeight     = 0.0;
    nTemperatureRanges  = 0;
}

void Substance::allocateMemoryForTemperatureRanges(int n)
{
    temperatureLow  = new RealType[n];
    temperatureHigh = new RealType[n];
    a               = new RealType*[n];
    for (int i = 0; i < n; i++) {
        a[i] = new RealType[8];
    }
}

Substance::~Substance()
{
    delete [] temperatureLow;
    delete [] temperatureHigh;
    delete [] a;
}