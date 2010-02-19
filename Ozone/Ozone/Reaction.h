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
     * ���������� ������. ����������� ���������� ������.
     */
    ~Reaction();
	/**
	 * �������� ������ ��� �������� ���������� �������.
	 */
	void allocateMemoryForParameters();
	/**
	 * �������� ������ ��� ������� ������������� ������������� ������������.
	 *
	 * @param n ���������� ������� � �����.
	 */
	void allocateMemoryForCollisionEfficiency(int n);
	/**
	 * ��������� ��������� �������� ������ ������� ��� �������� �����������.
	 *
	 * @param t �����������, �
	 * @return ����������� �������� ��������� �������� ������ �������
	 */
	RealType calculateConstantRate(RealType t);
	/**
	 * ��������� �������� ������� ��� �������� �����������.
	 *
	 * @param YY			������ �������� ������������ ����������� �����
	 * @param t				�����������, �
	 * @param gibbsEnergies �������� ������� ������ ��� ���� ����������� �����
	 * @param nSpecies		���������� ������� � �����
	 * @return �����������	�������� �������� �������
	 */
	RealType calculateReactionRate(double *Y, RealType t, RealType *gibbsEnergies, int nSpecies);
	RealType multiplicationOfReagents;
	RealType multiplicationOfProducts;
	RealType q;
	int nMoles;
	RealType kc;
	RealType kf;
	bool withThirdBody;
	RealType reactionRate_;
	/**
     * ��� �������. ���� ����� 0, �� ������� ������� �� �����������,
     * ���� 1, �� ������� ������� �� ��������.
     */
    int typeOfReaction;
	/**
	 * ���������� ������������� ����������, ��� ������� ���������� 
	 * ��������� �������.
	 */
	int nTemperatureRanges;
    /**
     * ������ ����������� ��� ���������� �������.
     */
    RealType *temperatureLow;
    /**
     * ������� ����������� ��� ���������� �������.
     */
    RealType *temperatureHigh;
    /**
     * ���������� �������� ��������������������� ���������.
     */
    RealType *log10A;
    /**
     * ���������� ������� � ����������� � ���������������� 
     * ������ ���������.
     */
    RealType *n;
    /**
     * ������� ��������� ��� ������ �������, ���� ����-1.
     */
    RealType *activationEnergy;
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
	/**
	 * ����������� �������. ���� 0, �� ������� ���������, ���� 1,
	 * �� �����������.
	 */
	int direction;
	/**
	 * ������ ������������� ������������� ������������.
	 */
	RealType *pEff;
	/**
	 * ����, �����������, ���� �� ������������ ������������� ������������.
	 */
	bool nEff;
};

#endif