/**
* @file
*
* @author  ������� ������� <kabanovdmitry@gmail.com>
* @version %I%
*
* @section DESCRIPTION
*
* ����� ������.
*/
#ifndef Piston_h__
#define Piston_h__

#include "RealType.h"

class Piston
{
public:
    Piston();
    ~Piston();
    RealType calculateVelocity(RealType f);
private:
    void readFileOfPiston(const char* filename);
    int nRows;
    RealType *pressures;
    RealType *densities;
    RealType *fractions;
};

#endif // Piston_h__