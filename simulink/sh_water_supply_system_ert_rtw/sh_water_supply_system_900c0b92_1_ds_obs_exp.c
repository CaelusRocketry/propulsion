/* Simscape target specific file.
 * This file is generated for the Simscape network associated with the solver block 'sh_water_supply_system/Solver Configuration'.
 */

#include "ne_ds.h"
#include "sh_water_supply_system_900c0b92_1_ds_obs_exp.h"
#include "sh_water_supply_system_900c0b92_1_ds_sys_struct.h"
#include "sh_water_supply_system_900c0b92_1_ds_externals.h"
#include "sh_water_supply_system_900c0b92_1_ds_external_struct.h"
#include "ssc_ml_fun.h"

int32_T sh_water_supply_system_900c0b92_1_ds_obs_exp(const NeDynamicSystem *sys,
  const NeDynamicSystemInput *t1, NeDsMethodOutput *t2)
{
  PmRealVector out;
  real_T t0[219];
  int32_T b;
  static real_T _cg_const_1[219] = { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.2, 0.0, 0.0, 100.0, 0.0,
    0.2, 0.0, 0.0, 100.0, 0.0, 0.2, 0.0, 0.0, 100.0, 0.0, 0.2, 0.0, 0.0, 0.0,
    0.0 };

  (void)t1;
  out = t2->mOBS_EXP;
  for (b = 0; b < 219; b++) {
    t0[b] = _cg_const_1[b];
  }

  for (b = 0; b < 219; b++) {
    out.mX[b] = t0[b];
  }

  (void)sys;
  (void)t2;
  return 0;
}
