/**
* @file
*
* @author  ������� ������� <kabanovdmitry@gmail.com>
* @version $Id$
*
* @section DESCRIPTION
*
* ��������� ����� Output.
*/
#ifndef OUTPUT_H
#define OUTPUT_H

#include <fstream>
#include <vector>
#include <string>
#include "GodunovKolganMethod.h"
#include "Mixture.h"

/**
 * ����� ������ � ����.
 */
class Output
{
public:
	/**
	 * ����������� ������.
	 *
	 * @param mix		������� �����
	 * @param format	������ ��������� �����
	 * @param path		���� � �������� �������� ������
	 */
	Output(const Mixture &mix, const std::string &format, std::string path);
	/**
	 * ���������� ������.
	 */
	~Output();
	/**
	 * ������� ������ � ����.
	 *
	 * @param timeStep	��������� ��� 
	 * @param gkm		������, ������ �������� ��������� � ����
	 */
	void plotData(int timeStep, GodunovKolganMethod &gkm);
	/**
	 * ������� ��������� �������� ������ � ����.
	 *
	 * @param outFile �������� ����.
	 */
	void writeDataLabels(std::ofstream &outFile);

private:
	std::vector<std::string> names_;
	std::string format_;
	std::string delimiter_;
	std::string path_;
};

#endif // OUTPUT_H
