/**
 * @file
 *
 * @author  ������� ������� <kabanovdmitry@gmail.com>
 * @version %I%
 *
 * @section DESCRIPTION
 *
 * ����� �������� ��� �������� ��� ��������� �������.
 */
#ifndef SUBSTANCE_H
#define SUBSTANCE_H

#include <string>
#include "RealType.h"

class Substance
{
public:
    /**
     * ����������� ������.
     */
    Substance();
    /**
     * ���������� ������.
     */
    ~Substance();
    /**
     * �������� ��������.
     */
    std::string nameOfSubstance;
    /**
     * ��������� ����������� �������, ���/����.
     */
    RealType enthalpyOfFormation;
    /**
     * ������������ ���� �������, ��/�����.
     */
    RealType molecularWeight;
    /**
     * ���������� ���������������� ������������� ����������.
     */
    int nTemperatureRanges;
    /**
     * ������ ������� ������������� ����������, �.
     */
    RealType *temperatureLow;
    /**
     * ������� ������� ������������� ����������, �.
     */
    RealType *temperatureHigh;
    /**
     * ������������ ��� �������������� ������������ ����������������� �������.
     */
    RealType **a;
    /**
     * �������� ������ ��� ������������� ����������.
     * 
     * @param n ���������� ������������� ����������.
     */
    void allocateMemoryForTemperatureRanges(int n);
};

#endif