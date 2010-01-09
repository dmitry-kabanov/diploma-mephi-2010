/**
* @file
*
* @author  ������� ������� <kabanovdmitry@gmail.com>
* @version $Id$
*
* @section DESCRIPTION
*
* ���������� ������ Piston.
*/
#ifndef PISTON_H
#define PISTON_H

#include "RealType.h"

/**
 * ����� ������. ������������ ������ ������������� ������.
 * ��. ������ �. ��������� ������������� ���������. ����� 1.
 */
class Piston
{
public:
	/**
	 * ����������� ������ Piston.
	 *
	 * @param pInitial			��������� ��������, ��
	 * @param rhoInitial		��������� ���������, �� �-3
	 * @param fileOfPistonData	��� ����� � ���������� ������� ��� ������
	 */
	Piston(RealType pInitial, RealType rhoInitial, const char *fileOfPistonData);
	/**
	 * ���������� ������ Piston. ����������� ���������� ������.
	 */
    ~Piston();
    /**
     * ��������� �������� ������ � ����������� �� ��������
	 * ������� ���� ��������� ������������������� ��������.
     *
     * @param f ������� ���� ��������� ��������
     * @return ����� �������� �������� ������
     */
    RealType calculateVelocity(RealType f);
private:
    /**
     * ������ �� ����� � ������ fileOfPistonData ��������� ������
	 * �������� � ��������� � ����������� �� ������� ����
	 * ��������� ������������������� ��������.
     *
     * @param fileOfPistonData ��� ����� � ���������� ������� ��� ������
     */
    void readFileOfPiston(const char *fileOfPistonData);
	/**
	 * ���������� ����� � ����� � ���������� ������� ��� ������.
	 */
    int nRows_;
	/**
	 * ������ ��������.
	 */
    RealType *pressures_;
	/**
	 * ������ ����������.
	 */
    RealType *densities_;
	/**
	 * ������ ������� �����.
	 */
    RealType *fractions_;
	/**
	 * ��������� �������� � �����, ��.
	 */
	RealType pInitial_;
	/**
	 * ��������� ��������� �����, �� �-3.
	 */
	RealType rhoInitial_;
};

#endif // PISTON_H