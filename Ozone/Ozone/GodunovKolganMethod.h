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
class Output;

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

	int *getCellNumbers() { return &cells_numbers[0]; }
	RealType *getX() { return &x[0]; }
	RealType *getXCenter() { return &x_center[0]; }
	RealType *getP() { return &p[0]; }
	RealType *getU() { return &u[0]; }
	RealType *getRho() { return &rho[0]; }
	RealType *getFullEnergy() { return &e[0]; }
	RealType *getIntEnergy() { return &u_energy[0]; }
	RealType **getMoleFractions() { return volumeFractions; }
	bool *getShockWaveFront() { return shock_wave_front; }
	int getMeshSize() const { return config_->getMeshSize(); }

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

	/**
	 * ��������� ���������� �������� f �� �������� ������.
	 * ��� ��� � ������ ���������������� ������������ �������� ������������
	 * ���������������� ������� ������ ������, �� ���������� ����� ����������
	 * ������� �� �������� ������ �� ��������� �� ��������� � ������ ������.
	 *
	 * @param f_left			�������� f � ������ ����� �� �������
	 * @param f					�������� f � ������� ������
	 * @param f_right			�������� f � ������ ������ �� �������
	 * @param x_center_left		���������� ������ ������ ����� �� �������
	 * @param x_center			���������� ������ ������� ������
	 * @param x_center_right	���������� ������ ������ ������ �� �������
	 * @param x_bound_l			���������� ����� ������� ������� ������
	 * @param x_bound_r			���������� ������ ������� ������� ������
	 * @return					���������� �������� f
	 */
	RealType calc_delta(RealType f_left,
		RealType f,
		RealType f_right,
		RealType x_center_left,
		RealType x_center,
		RealType x_center_right,
		RealType x_bound_l,
		RealType x_bound_r);

	/**
	 * ������������ ������ ����� � ������ �� ������ ���������� ������� �����.
	 * ���� ������ ����� �� ������ ���������� ����� ������ ������ 
	 * ������ �� ������, �� ������ ����� ������� �������, � ������ ������
	 * ������������ �� ��������� �� ��� �������.
	 */
	void modifyShockWaveFront_();

	const Config *config_;
	// ������ ������� �����.
	std::vector<int> cells_numbers;

	RealType shock_wave_velocity;
	RealType delta_mass;
	Piston *piston;
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
	std::vector<RealType> deltaTemperature;
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

	std::vector<RealType> rho_delta;
	std::vector<RealType> rho_u_delta;
	std::vector<RealType> rho_e_delta;

	std::vector<RealType> rho_u;
	std::vector<RealType> rho_e;
	
	// ������ ������ ������ � ������ ������� �����.
	// ���� �������� �������� ����� true - �� ������� ���� ������ 
	// ��������� ����� ������� �����.
	// ���� �������� �������� ����� false - �� ���.
	bool *shock_wave_front;

	StifflSolver *kinetics;
	Output *plotter_;
	int frontCellNumber_;
	/**
	 * ��� �� �������, �.
	 */
	RealType dt;
	/**
	 * ������ ���������� �����.
	 */
	int meshSize_;

};

#endif // GODUNOVKOLGANMETHOD_H
