#include <iostream>
#include "RungeKuttaMethod.h"

int main()
{
    // �������� � ��.
    RealType p0 = 64 * 101325;
    // ����������� � �.
    RealType t0 = 1200.00;

    RungeKuttaMethod rungeKuttaMethod(p0, t0,
                                      "Substances.txt",
                                      "Reactions.txt",
                                      "VolumeFractions.txt"
    );
}