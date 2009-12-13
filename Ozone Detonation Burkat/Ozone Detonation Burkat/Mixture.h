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
     * @param fileOfSubstances      ��� ����� �� ���������� �������
     * @param fileOfReactions       ��� ����� � ����������� �������
     * @param fileOfMoleFractions   ��� ����� � ���������� ������� �����
     */
    Mixture(const char *fileOfSubstances,
            const char *fileOfReactions,
            const char *fileOfMoleFractions);
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
     * �������� ���� ����������� �����.
     */
    RealType *volumeFractions;
    /**
     * �������� ���� ����������� �����.
     */
    RealType *y_;
    /**
     * ��������� ��������� ��������� �� ����������� 298.15 � 
     * �� ����������� t ��� i-�� ��������.
     *
     * @param i ���������� ����� �������� � ������� �������
     * @param t �����������, �
     * @return ����������� ���������� ���������, ��/�����
     */
    RealType calculateSubstanceEnthalpy(int i, RealType t);
    /**
     * ��������� �������� �������� ��� i-�� �������� 
     * ��� ����������� t.
     *
     * @param i ���������� ����� �������� � ������� �������
     * @param t �����������, �
     * @return ����������� �������� ��������, �� ��-1 �-1
     */
    RealType calculateSubstanceEntropy(int i, RealType t);
    /**
     * ��������� ������� ������ ��� i-�� ��������
     * ��� ����������� t.
     *
     * @param i ���������� ����� �������� � ������� �������.
     * @param t �����������, �
     * @return ����������� �������� ������� ������, �� ��-1.
     */
    RealType calculateSubstanceGibbsEnergy(int i, RealType t);
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
     * ����������� ����� � ������ ���� ��������������, �. 
     * ��������������� ����������.
     */
    RealType oldTemperature;
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
    RealType *previousConcentrations;
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
    RealType getOldTemperature();
    RealType getTemperature();
    /**
     * ��������� ����������� ��� �������� ������� �����.
     *
     * @return �����������, �
     */
    RealType calculateTemperature();
    RealType calculateInitialTemperature();
    /**
    * ������������� ����������������� ��������� ����� 
    * �� �������� ���������� �������, ��������� � ������� �����
    * �����������.
     *
     * @param internalEnergy ���������� �������, �� ��-1
     * @param density        ���������, �� �-3
     * @param x              ������ ������� ����� ����������� �����
     */
    void setStateWithURhoX(RealType internalEnergy, 
        RealType density, 
        RealType* x);
    /**
     * ������������� ����������������� ��������� ����� 
     * �� �������� �����������, �������� � ������� �����
     * �����������.
     *
     * @param t  �����������, �
     * @param p  ��������, ��
     * @param vf ������ ������� ����� ����������� �����
     */
    void setStateWithTPX(RealType t, RealType p, RealType *x);
    RealType calculatePressure();
    RealType calculateOldPressure();
    RealType calculateMixtureCp(RealType t);
    RealType calculateMixtureEnthalpy(RealType t);
    RealType calculateSubstanceCp(int i, RealType t);
    /**
     * ������������� ������������ ����������� ����� 
     * ��� �������� ����������� � ���������.
     *
     * @param t       �����������, �
     * @param density ���������, �� �-3
     */
    void setConcentrations(RealType t, RealType density);
    /**
     * ������������� �������� ���� ����������� �����.
     *
     * @param fractions �������� ����
     */
    void setVolumeFractions(const RealType *fractions);
    /**
     * ���������� ������������ ��� �����.
     */
    RealType getMolecularWeight();
};

#endif