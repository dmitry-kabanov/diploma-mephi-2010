/**
* @file
*
* @author  ������� ������� <kabanovdmitry@gmail.com>
* @version $Id$
*
* @section DESCRIPTION
*
* ��������� ����� GodunovKolganMethod.
*/
#ifndef GODUNOVKOLGANMETHOD_H
#define GODUNOVKOLGANMETHOD_H

#include <vector>
#include "Config.h"
#include "Piston.h"
#include "RealType.h"

class StifflSolver;

/**
 * ������������ ����� �������� ������� ��������� ������� ��������
 * ������� ��������-�������.
 */
class GodunovKolganMethod
{
public:
	/**
	 * ����������� ������.
	 *
	 * @param config ������������ ���������
	 */
	GodunovKolganMethod(const Config &config);
	/**
	 * ���������� ������. ����������� ������, ���������� � �������
	 * ��������� new.
	 */
	~GodunovKolganMethod();
	/**
	 * ����������� ������� ��������� ������� ��������
	 * ��������� � ����������� ���������� ��������.
	 */
	void run();

private:
	/**
	 * �������������� ��� ���������������� ��������, 
	 * � ����� ������ ������� �����.
	 */
	void init_();

	/**
	 * ������ ���� ��������� ��������� ������,
	 * ��������������� ������� ���������� �����.
	 */
	void resizeAllVectors();

	const Config *config_;
	// ������ ������� �����.
	std::vector<int> cells_numbers;

	RealType shock_wave_velocity;
	RealType delta_mass;
	Piston piston;
	std::vector<RealType> x;
	std::vector<RealType> x_center;
	std::vector<RealType> m;
	std::vector<RealType> rho;
	std::vector<RealType> u;
	std::vector<RealType> p;
	RealType **volumeFractions;
	
	std::vector<RealType> internal_energy;
	std::vector<RealType> u_energy;
	std::vector<RealType> e;
	std::vector<RealType> temperature;
	std::vector<RealType> gamma;
	std::vector<RealType> p_contact;
	std::vector<RealType> u_contact;
	std::vector<RealType> delta_impulse;
	std::vector<RealType> delta_energy;
	
	std::vector<RealType> rho_bound_r;
	std::vector<RealType> rho_bound_l;
	std::vector<RealType> u_bound_r;
	std::vector<RealType> u_bound_l;
	std::vector<RealType> e_bound_r;
	std::vector<RealType> e_bound_l;
	std::vector<RealType> p_bound_r;
	std::vector<RealType> p_bound_l;
	std::vector<RealType> rho_u_bound_r;
	std::vector<RealType> rho_u_bound_l;
	std::vector<RealType> rho_e_bound_r;
	std::vector<RealType> rho_e_bound_l;

	std::vector<RealType> rho_tg_left;
	std::vector<RealType> rho_tg_right;
	std::vector<RealType> rho_tg;
	std::vector<RealType> rho_u_tg_left;
	std::vector<RealType> rho_u_tg_right;
	std::vector<RealType> rho_u_tg;
	std::vector<RealType> rho_e_tg_left;
	std::vector<RealType> rho_e_tg_right;
	std::vector<RealType> rho_e_tg;

	std::vector<RealType> rho_u;
	std::vector<RealType> rho_e;
	
	// ������ ������ ������ � ������ ������� �����.
	// ���� �������� �������� ����� true - �� ������� ���� ������ 
	// ��������� ����� ������� �����.
	// ���� �������� �������� ����� false - �� ���.
	bool *shock_wave_front;

	StifflSolver *kinetics;

};

#endif // GODUNOVKOLGANMETHOD_H
