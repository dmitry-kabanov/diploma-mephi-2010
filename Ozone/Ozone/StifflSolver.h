/**
* @file
*
* @author  ������� ������� <kabanovdmitry@gmail.com>
* @version $Id$
*
* @section DESCRIPTION
*
* ���������� ������ StifflSolver.
*/
#ifndef STIFFL_SOLVER_H
#define STIFFL_SOLVER_H

#include <iostream>
#include <fstream>
#include "RealType.h"
#include "Mixture.h"
#include "Reaction.h"
#include "Substance.h"
#include "Stiffl.h"

/**
 * ����� �������������� ������� ��� ���������� ��������. ��� �������������� 
 * ���������� ����� STIFF, �������������� ����� ����������� ������ ����.
 * ��. ������� �. �., ���������� �. �. STIFF - ��������� ��� ������� ������� 
 * ������ ���. �������� ��������� ���������� ���������� �� ����. �., 1977 �.
 */
class StifflSolver : public Stiffl
{
public:
    /**
     * ����������� ������.
     *
	 * @param NYDIM_PAR				���������� ��� 1-�� �������
	 * @param values				��������� �������� ������� ����������
	 * @param t_begin				��������� �������� �������� �������, �
	 * @param t_end					�������� ������ �������, �� �������� 
	 * ����� ������������� ������� ���, �
	 * @param t_step_begin			��������� ��� ��������������, �
     * @param fileOfSubstances      ��� ����� � ����������
     * @param fileOfReactions       ��� ����� � ���������
	 * @param fileOfMoleFractions   ��� ����� � �������� ������
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
     * ��������� �������� ������� ����� ����������� �����. �������� ���������� 
	 * � ���������������� ������.
     *
     * @param vf ��������� �� ������, � ������� �������
     * ����� �������� ������� �����.
     */
    void updateMoleFractions(RealType *vf);
	/**
	* ��������� �������� �������� ����� ����������� �����. �������� ���������� 
	* � ���������������� ������.
	*
	* @param mf ��������� �� ������, � ������� �������
	* ����� �������� �������� �����.
	*/
	void updateMassFractions(RealType *mf);
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
	RealType concOfM;
	/**
	 * �������������� IFNSH() �� Stiffl. ������ ��� ���������� ������� 
	 * ������� � �������� ��������������. 
	 *
	 * @return 0, � ������, ���� ����� ���������� ��������������, 
	 * 1, ���� �� �����-���� �������� ���������� �������������� ����������.
	 */
	virtual int IFNSH();
	/**
	 * �������������� DIFFUN() �� Stiffl. ��������� �������� ������ ������ 
	 * ������� ��� �� �������� ��������� YY[0], � ���������� �� � ������ F.
	 *
	 * @param YY ��������� ������, YY[0] �������� ������� ����������� ��������
	 * ������� ����������
	 * @param F  ������, � ������� ������������ �������� ������ ������ 
	 * ������� ���
	 * @return 0
	 */
	virtual int DIFFUN(double **YY, double *F);
	/**
	 * �������������� PEDERV() �� Stiffl. ��������� �������� �������� 
	 * ������������� ������� ���. ���������� �������� ������������ 
	 * �� ������������� ��������.
	 */
	virtual void PEDERV();
};

#endif // STIFFL_SOLVER_H