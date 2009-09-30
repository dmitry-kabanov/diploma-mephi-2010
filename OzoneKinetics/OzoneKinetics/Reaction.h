/**
 * @file
 *
 * @author  ������� ������� <kabanovdmitry@gmail.com>
 * @version %I%
 *
 * @section DESCRIPTION
 *
 * ����� ������� ��� �������� ���������� ���������� �������.
 */
#ifndef REACTION_H
#define REACTION_H

#include <string>
#include "RealType.h"

class Reaction
{
public:
    /**
     * ����������� ������.
     */
    Reaction();
    /**
     * ���������� ������.
     */
    ~Reaction();
    /**
     * ��� �������. ���� ����� 0, �� ������� ������� �� �����������,
     * ���� 1, �� ������� ������� �� ��������.
     */
    int typeOfReaction;
    /**
     * ������ ����������� ��� ���������� �������.
     */
    RealType temperatureLow;
    /**
     * ������� ����������� ��� ���������� �������.
     */
    RealType temperatureHigh;
    /**
     * ���������� �������� ��������������������� ���������.
     */
    RealType log10A;
    /**
     * �����-�� ���������� ��������.
     */
    RealType n;
    /**
     * ������� ��������� ��� ������ �������.
     */
    RealType activationEnergy;
    /**
     * ������� �������.
     */
    std::string nameOfReaction;
    /**
     * ������ �������� ������� � ������ �������.
     */
    int *reagents;
    /**
     * ���������� �������� ������� � ������ �������.
     */
    int nReagents;
    /**
     * ������ ��������� � ������ �������.
     */
    int *products;
    /**
     * ���������� ��������� � ������ �������.
     */
    int nProducts;
};

#endif