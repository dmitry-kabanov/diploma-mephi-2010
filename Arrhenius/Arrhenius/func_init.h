#ifndef FUNC_INIT_H
#define FUNC_INIT_H

void init_parameters(
    long double *x, long double *x_center,
    long double *m, long double *rho,
    long double *u, long double *e,
    long double *p, long double *rho_u,
    bool *shock_wave_front
);

/**
 * ������ ��������� ������������� ����������������� �������.
 * ������� ��������� ����� ���������:
 * p (��������) - ��� ������� ���������� �������,
 * rho (���������) - ��� ������� ���������� �������,
 * u (��������) - ��� ������� ������ �������.
 */
void init_thermodynamic_parameters(
    long double *internal_energy, long double *energy,
    long double *temperature, long double *p, 
    long double *rho, long double *u,
    long double *rho_e
);

/**
 * ������ ��������� ������������� ���������� �������
 * 
 * w - �������� ���� ������������������� ����������� ��������
 * chemical_energy - ���������� �������
 */
void init_chemical_parameters(
    long double *w, long double *chemical_energy
);

void init_additional_parameters(
    long double *p_contact, long double *u_contact,
    long double *impulse_flow, long double *energy_flow,
    long double *p, long double *u
);

void init_boundary_parameters(
    long double *rho_bound_r, long double *rho_bound_l,
    long double *rho_u_bound_r, long double *rho_u_bound_l,
    long double *rho_e_bound_r, long double *rho_e_bound_l,
    long double *u_bound_r, long double *u_bound_l,
    long double *e_bound_r, long double *e_bound_l,
    long double *p_bound_r, long double *p_bound_l
);

void init_tangents(
    long double *rho_tg_left, long double *rho_tg_right, long double *rho_tg,
    long double *rho_u_tg_left, long double *rho_u_tg_right, long double *rho_u_tg,
    long double *rho_e_tg_left, long double *rho_e_tg_right, long double *rho_e_tg
);

#endif