#ifndef FUNC_INIT_H
#define FUNC_INIT_H

#include "RealType.h"
#include "RungeKuttaMethod.h"

void init_parameters(
    RealType *x, RealType *x_center,
    RealType *m, RealType *rho,
    RealType *u, RealType *e,
    RealType *p, RealType *rho_u,
    bool *shock_wave_front
);

/**
 * Задает начальное распределение термодинамических величин.
 * Функция принимает также аргументы:
 * p (давление) - для расчета внутренней энергии,
 * rho (плотность) - для расчета внутренней энергии,
 * u (скорость) - для расчета полной энергии.
 */
void init_thermodynamic_parameters(RealType *internal_energy,
                                   RealType *energy,
                                   RealType *p,
                                   RealType *rho,
                                   RealType *u,
                                   RealType *u_energy,
                                   RealType *volumeFractions[],
                                   RungeKuttaMethod &kinetics
);

/**
 * Задает начальное распределение rho * energy.
 * 
 * internal_energy — внутренняя тепловая энергия
 * rho             — плотность
 * rho_e           — внутрення энергия на единицу объема.
 */
void init_rho_e(const RealType *internal_energy,
                const RealType *rho,
                RealType *rho_e
);

void init_additional_parameters(
    RealType *p_contact, RealType *u_contact,
    RealType *impulse_flow, RealType *energy_flow,
    RealType *p, RealType *u
);

void init_boundary_parameters(
    RealType *rho_bound_r, RealType *rho_bound_l,
    RealType *rho_u_bound_r, RealType *rho_u_bound_l,
    RealType *rho_e_bound_r, RealType *rho_e_bound_l,
    RealType *u_bound_r, RealType *u_bound_l,
    RealType *e_bound_r, RealType *e_bound_l,
    RealType *p_bound_r, RealType *p_bound_l
);

void init_tangents(
    RealType *rho_tg_left, RealType *rho_tg_right, RealType *rho_tg,
    RealType *rho_u_tg_left, RealType *rho_u_tg_right, RealType *rho_u_tg,
    RealType *rho_e_tg_left, RealType *rho_e_tg_right, RealType *rho_e_tg
);

void init_gamma(RealType *gamma);

void init_volume_fractions(RealType *volumeFractions[]);

#endif