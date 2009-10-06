/**
* @file
*
* @author  ������� ������� <kabanovdmitry@gmail.com>
* @version %I%
*
* @section DESCRIPTION
*
* ����� �����.
*/
#ifndef MIXTURE_H
#define MIXTURE_H

#include "RealType.h"

class Substance;
class Reaction;

class Mixture
{
public:
    /**
     * ����������� ������.
     *
     * @param p0                    ��������� ��������, ��
     * @param t0                    ��������� �����������, �
     * @param fileOfSubstances      ��� ����� �� ���������� �������
     * @param fileOfReactions       ��� ����� � ����������� �������
     * @param fileOfVolumeFractions ��� ����� � ��������� ������ �����
     */
    Mixture(RealType p0, RealType t0,
            const char *fileOfSubstances,
            const char *fileOfReactions,
            const char *fileOfVolumeFractions);
    /**
     * ���������� ������.
     */
    ~Mixture();
    /**
     * ������ �� ����� filename �������� � �� ��������.
     *
     * @param filename ��� ����� � ����������
     */
    void readFileOfSubstances(const char *filename);
    /**
     * ������ �� ����� filename ������� � �� ���������.
     *
     * @param filename ��� ����� � ���������
     */
    void readFileOfReactions(const char *filename);
    /**
     * ������ �� ����� filename ����� ������� � �� �������� ����.
     */
    void readFileOfVolumeFractions(const char *filename);
    /**
     * �������� ���� �������.
     */
    RealType *volumeFractions;
    /**
     * ��������� ��������� ��������� �� ����������� 298.15 � 
     * �� ����������� t ��� i-�� ��������.
     *
     * @param i ���������� ����� �������� � ������� �������
     * @param t �����������, �
     * @return ����������� ���������� ���������, ��/�����
     */
    RealType calculateEnthalpy(int i, RealType t);
    /**
     * ��������� ������� ������ ��� i-�� ��������
     * ��� ����������� t.
     *
     * @param i ���������� ����� �������� � ������� �������.
     * @return ����������� �������� ������� ������, �� / ����.
     */
    RealType Mixture::calculateGibbsEnergy(int i);
    /**
     * ��������� ��������� ������������ ��� �����
     * ��� ����������� t.
     *
     * @param t �����������, �
     * @return ����������� �������� ������������, �� / (��**3 * �)
     */
    RealType calculateCp(RealType t);
    /**
     * ������ �������.
     */
    Substance **substances;
    /**
     * ������ �������.
     */
    Reaction *reactions;
    /**
     * ����������� �����, �.
     */
    RealType temperature;
    /**
     * ������ ������� �������.
     */
    RealType fullEnergy;
    /**
     * ���������� �������.
     */
    int nSubstances;
    /**
     * ���������� �������.
     */
    int nReactions;
    /**
     * �������� � ���� ������ ��� ������� �������.
     */
    void allocateMemoryForSubstances();
    /**
     * �������� � ���� ������ ��� ������� �������.
     */
    void allocateMemoryForReactions();
    /**
     * ��������� ������ ���������.
     */
    void fillReagents();
    /**
     * ��������� ������ ��������� �������.
     */
    void fillProducts();
    /**
     * ������������� ������� ����������, �� / (���� * �).
     */
    static const RealType R_J_OVER_MOL_K;
    /**
     * ������������� ������� ����������, �� / (����� * �).
     */
    static const RealType R_J_OVER_KMOL_K;
    /**
     * ��������� ���������, �� / �.
     */
    static const RealType K_BOLTZMANN;
    /**
    * ����� ��������, 1 / ����.
    */
    static const RealType AVOGADRO_NUMBER;
    /**
     * ������ ������������ �������.
     */
    RealType *concentrations;
    /**
     * ������ ��������� ������������.
     */
    RealType *initialConcentrations;
    /**
     * �������� � ���� ������ ��� ������� ������������ ������� � �����.
     */
    void allocateMemoryForConcentrations();
    /**
     * ��������� ������������ ��� ����� � �� / �����.
     */
    RealType calculateMolecularWeight();
    /**
     *  ��������� ��������� ������������ ��� ����� � �� / �����.
     */
    void calculateInitialMolecularWeight();
    /**
     * ������������ ��� �����, �� / �����.
     */
    RealType molecularWeight;
    /**
     * ��������� ������������ ���, �� / �����.
     */
    RealType initialMolecularWeight;
    /**
     * ��������� ������ ������� ������� � �� / ��.
     *
     * @param pressure �������� � �������, ��
     * @param volume   �������� ����� �������, �**3 / ��
     * @return ���������� ������� �������, �� / ��
     */
    RealType calculateFullEnergy(RealType pressure, RealType volume);
    /**
     * ��������� ��������� ������������ �������.
     */
    /**
     * ��������� ����������������� ������������ ��� ��������������� �������� 
     * � ��������� ��� ���� ������� � �����.
     */
    void sumPolynomialCoeffs(RealType t);
    /**
     * ��������� ������������ ��� ��������������� �������� ��������.
     */
    RealType sumThermCoeffs[8];
    /**
     * �������� �����, ��.
     */
    RealType pressure;
    /**
     * �������� ����� �����, �**3 / ��.
     */
    RealType volume;
    /**
     * ��������� ����������� ��� �������� ������� �����.
     *
     * @return �����������, �
     */
    RealType calculateTemperature();
};

#endif