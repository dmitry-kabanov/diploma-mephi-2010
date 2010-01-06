/**
* @file
*
* @author  ������� ������� <kabanovdmitry@gmail.com>
* @version %I%
*
* @section DESCRIPTION
*
* ����� �������������� ������� ��� ���������� ��������.
*/
#ifndef RUNGE_KUTTA_METHOD_H
#define RUNGE_KUTTA_METHOD_H

#include <iostream>
#include <fstream>
#include "RealType.h"
#include "Mixture.h"
#include "Reaction.h"
#include "Substance.h"
#include "Stiffl.h"

class StifflSolver : public Stiffl
{
public:
    /**
     * ����������� ������.
     *
     * @param fileOfSubstances      ��� ����� � ����������
     * @param fileOfReactions       ��� ����� � ���������
     */
	StifflSolver(int NYDIM_PAR, double *values, double t_begin, double t_end,
					 double t_step_begin,
					 const char *fileOfSubstances,
                     const char *fileOfReactions,
                     const char *fileOfMoleFractions);
    /**
     * ���������� ������.
     */
    ~StifflSolver();
    /**
    * ���������� �������������� ������� ���.
    *
    * @param aFullTime ��������� ��������, �� ������� 
    * ������������ ��������������.
    */
    void performIntegration(RealType aFullTime);
    /**
     * ��������� �������� ������� ����� ����������� �����.
     *
     * @param vf ��������� �� ������, � ������� �������
     * ����� �������� ������� �����.
     */
    void updateMoleFractions(RealType *vf);
    /**
     * ���������� �������� �������� � �����.
     *
     * @return �������� � �����, ��
     */
    RealType getPressure();
    /**
     * ����� �����.
     */
    Mixture *mixture;
    /**
     * ���������� ������ �����.
     *
     * @return ��������� �� ������ ������ Mixture.
     */
    Mixture *getMixture();

private:
    /**
     * ��������� �������� �������� ������� �� O3 ��� �������� �����������
     * � �������.
     *
     * @param concOfO   ������������ O, ������� / ��**3
     * @param concOfO3  ������������ O3, ������� / ��**3
     * @param concOfO2  ������������ O2, ������� / ��**3
     * @return          �������� �������� ������� ������������ O3,
     * ������� / (��**3 * �)
     */
    RealType rightSideForO3(RealType concOfO, 
                            RealType concOfO3,
                            RealType concOfO2);
    /**
    * ��������� �������� �������� ������� �� O ��� �������� �����������
    * � �������.
    *
    * @param concOfO   ������������ O, ������� / ��**3
    * @param concOfO3  ������������ O3, ������� / ��**3
    * @param concOfO2  ������������ O2, ������� / ��**3
    * @return          �������� �������� ������� ������������ O,
    * ������� / (��**3 * �)
    */
    RealType rightSideForO(RealType concOfO, 
                           RealType concOfO3, 
                           RealType concOfO2);
    /**
    * ��������� �������� �������� ������� �� O2 ��� �������� �����������
    * � �������.
    *
    * @param concOfO   ������������ O, ������� / ��**3
    * @param concOfO3  ������������ O3, ������� / ��**3
    * @param concOfO2  ������������ O2, ������� / ��**3
    * @return          �������� �������� ������� ������������ O2,
    * ������� / (��**3 * �)
    */
    RealType rightSideForO2(RealType concOfO, 
                            RealType concOfO3, 
                            RealType concOfO2);
    /**
     * ��������� ��������� �������� ������ �������.
     *
     * @param i  ���������� ����� ������� � ������� �������
     * @return   �������� ��������� �������� ������ �������.
     */
    RealType calculateRateForForwardReaction(int i);
    /**
    * ��������� ��������� �������� �������� �������.
    *
    * @param i  ���������� ����� ������� � ������� �������
    * @param kf ��������� �������� ������ �������
    * @return   �������� ��������� �������� �������� �������.
    */
    RealType calculateRateForBackReaction(int i, RealType kf);
    /**
     * ���������� ��������� ����� ��������������.
     */
    int fullTime;
    /**
     * ���������� ��������� �����, ����� ������� ���������� ����� � ����.
     */
    int timeStepForOutput;
    /**
     * �����, �
     */
    RealType time;
    /**
     * �������� ����.
     */
    std::ofstream outputFile;
    /**
     * ������� ���������� ������� � ����.
     */
    void printToFile();
    /**
     * ������� ��������� � ����.
     */
    void printHeadingToFile();
    /**
     * ���������� �������� � ����� ��������������.
     */
    int nIterations;
	RealType k1f;
	RealType k2f;
	RealType k3f;
	RealType k1r;
	RealType k2r;
	RealType k3r;
	virtual int IFNSH();
	virtual int DIFFUN(double **YY, double *F);
	virtual void PEDERV();
};

#endif