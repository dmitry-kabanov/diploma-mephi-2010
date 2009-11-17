#ifndef FUNC_OUTPUT_H
#define FUNC_OUTPUT_H

#include <fstream>
#include "RealType.h"

void outputAsCSVFile(std::ofstream &outFile,
                     const int *cellNumbers,
                     const RealType *xCenter,
                     const RealType *p,
                     const RealType *u,
                     const RealType *rho,
                     const RealType *fullEnergy,
                     const RealType *intEnergy,
                     RealType *volumeFractions[], 
                     const bool *shockWaveVelocity
);

#endif