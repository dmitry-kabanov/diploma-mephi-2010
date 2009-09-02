#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <cmath>

const long double
    DX1 = 0.272,                 // ������ ������ � ���, �
    DX2 = 0.272,                 // ������ ������ � ���, �
    DT  = 0.00272,             // ��� �� �������, �
    

    P1 = 42.06,
	P2 =  1.0,               // �������� � ���, ��

    RHO1 = 8.738,
    RHO2 = 1.0,               // ��������� � ���
    V2   = 1.0 / RHO2,        // ��������� �����

    U1   = 6.03,
    U2   = 0.0,

    U_PISTON = 3.015,    // �������� ������.

    GAMMA = 1.2,               // ���������� ��������

    R_GAS = 1.0,

    CV = R_GAS / (GAMMA - 1),      // ������������ ��� ���������� ������, �� / �

    T0 = 1.0,                     // ��������� �����������, �

    I0 = CV * T0,               // ��������� ���������� �������

    Q = 50 * R_GAS * T0,        // �������, ������������ � ���������� �������, ��

    D_C_J = sqrt((GAMMA * GAMMA - 1) * Q / 2.0 + GAMMA * P2 / RHO2) + 
        sqrt((GAMMA * GAMMA - 1) * Q / 2.0),              // �������� � ����� �������-����

    F = 1.0,                    // F = (D / D_C_J)^2

 
    ACTIVATION_ENERGY = 40.0,

    Z = 430.88,
    K = 0.5;                   // ������������ ��� ����������� ������ ������,
                               // ����� ������� ������� ��������� 
                              // � ������� ������

const int N = 4000,             // ����� �����
L = 3;

/**
 * TODO: ����������� � ����� �����������.
 */
const bool EXACT_RIEMANN_SOLVER = true;

const int CONFIG_SHOCK_WAVES                  = 1;
const int CONFIG_SHOCK_AND_RAREFACTION_WAVES  = 2;
const int CONFIG_RAREFACTION_WAVES            = 3;
const int CONFIG_VACUUM                       = 4;

const long double EPSILON = 1e-10;

const int TIMESTEPS = 30000;
const int TIMEDIVISOR = 5000;

#endif