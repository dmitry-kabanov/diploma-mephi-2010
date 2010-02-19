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
     */
	StifflSolver(int NYDIM_PAR, 
		double *values,
		double t_begin,
		double t_end,
		double t_step_begin);
    /**
     * ���������� ������.
     */
    ~StifflSolver();
    /**
    * ���������� �������������� ������� ���.
    *
	* @param mix       �����, � ������� ���������� ���������� �������
    * @param aFullTime ��������� ��������, �� ������� 
    * ������������ ��������������
    */
    void performIntegration(Mixture &mix, RealType aFullTime);
    /**
     * ����� �����.
     */
    Mixture *mixture;

private:
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
	RealType kf;
	RealType kr;
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