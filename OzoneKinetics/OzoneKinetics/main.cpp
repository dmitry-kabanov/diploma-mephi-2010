#include "real_t.h"

int main()
{
    /**
     * ������������ ������� O.
     */
    real_t concOfO;
    /**
     * ������������ ������� O2.
     */
    real_t concOfO2;
    /**
     * ������������ ������� O3.
     */
    real_t concOfO3;
    /**
     * ��� ��������������.
     */
    real_t h;

    // ���������� �������������� � �����.
    for (i = 0; i < TIME; i++) {
        k1 = rightSideForO(t, concOfO, concOfO3);
        q1 = rightSideForO3(t, concOfO, concOfO3);

        k2 = rightSideForO(t + h / 2.0, 
            concOfO + h * k1 / 2.0, 
            concOfO3 + h * q1 / 2.0);
        q2 = rightSideForO3(t + h / 2.0, 
            concOfO + h * k1 / 2.0, 
            concOfO3 + h * q1 / 2.0);

        k3 = rightSideForO(t + h / 2.0, 
            concOfO + h * k2 / 2.0, 
            concOfO3 + h * q2 / 2.0);
        q3 = rightSideForO3(t + h / 2.0, 
            concOfO + h * k2 / 2.0, 
            concOfO3 + h * q2 / 2.0);

        k4 = rightSideForO(t + h, concOfO + h * k3, concOfO3 + h * q3);
        q4 = rightSideForO3(t + h, concOfO + h * k3, concOfO3 + h * q3);

        concOfO  = concOfO + h * 
            (k1 + 2 * k2 + 2 * k3 + k4) / 6.0;
        concOfO3 = concOfO3 + h * 
            (q1 + 2 * q2 + 2 * q3 + q4) / 6.0;