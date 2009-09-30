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
     * �������� ���� �������.???????????????????
     */
    RealType volumeFractions[3];
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
     * @param t �����������, �
     * @return ����������� �������� ������� ������.
     */
    RealType Mixture::GibbsCalc_ext(int i, RealType Tloc);
    /**
     * ��������� ������������ ��� ���������� �������� ��� �������� 
     * � ������� i ��� ����������� t.
     *
     * @param i ���������� ����� �������� � ������� �������
     * @param t �����������, �
     * @return ����������� �������� ������������, ��/(�����*�)
     */
    RealType calculateCp(int i, RealType t);
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
     * ������������� ������� ����������, ��/(����*�).
     */
    static const RealType R_J_OVER_MOL_K;
    /**
     * ������������� ������� ����������, ��/(�����*�).
     */
    static const RealType R_J_OVER_KMOL_K;
    /**
     * ��������� ���������, ��/�.
     */
    static const RealType K_BOLTZMANN;
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
     * ����� ��������, 1/����.
     */
    static const RealType AVOGADRO_NUMBER;
    /**
     * ��������� ������������ ��� ����� � ��/�����.
     */
    RealType calculateMolecularWeight();
    /**
     *  ��������� ��������� ������������ ��� ����� � ��/�����.
     */
    void calculateInitialMolecularWeight();
    /**
     * ������������ ��� �����, ��/�����.
     */
    RealType molecularWeight;
    /**
     * ��������� ������������ ���, ��/�����.
     */
    RealType initialMolecularWeight;
    /**
     * ��������� ������ ������� ������� � ��/��.
     *
     * @param pressure �������� � �������, ��
     * @param volume   �������� ����� �������, �**3/��
     * @return ���������� ������� �������, ��/��
     */
    RealType calculateFullEnergy(RealType pressure, RealType volume);
    /**
     * ��������� ��������� ������������ �������.
     */
    RealType calculateCpOfMixture();
    void POLIN_conc(RealType T);
    RealType sum_therm[8];
    /**
     * �������� �����, ��.
     */
    RealType pressure;
    RealType volume;
    RealType calculateFullEnthalpy(RealType p, RealType v);
    /**
     * ��������� ����������� ��� �������� ������� �����.
     *
     * @return �����������, �
     */
    RealType calculateTemperature();
    RealType calculateMixtureEnthalpyOfFormation();
    RealType calculateMixtureEnthalpy(RealType t);
    RealType calculateMixtureCp(RealType t);
    RealType calculateEntropy(int i);
    RealType calculateMixtureVolume();
};

#endif