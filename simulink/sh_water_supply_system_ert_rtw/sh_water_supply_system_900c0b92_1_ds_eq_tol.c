/* Simscape target specific file.
 * This file is generated for the Simscape network associated with the solver block 'sh_water_supply_system/Solver Configuration'.
 */

#include "ne_ds.h"
#include "sh_water_supply_system_900c0b92_1_ds_eq_tol.h"
#include "sh_water_supply_system_900c0b92_1_ds_sys_struct.h"
#include "sh_water_supply_system_900c0b92_1_ds_externals.h"
#include "sh_water_supply_system_900c0b92_1_ds_external_struct.h"
#include "ssc_ml_fun.h"

int32_T sh_water_supply_system_900c0b92_1_ds_eq_tol(const NeDynamicSystem *sys,
  const NeDynamicSystemInput *t1, NeDsMethodOutput *t2)
{
  PmRealVector out;
  (void)t1;
  out = t2->mEQ_TOL;
  out.mX[0] = 1.0E-9;
  out.mX[1] = 1.0E-9;
  out.mX[2] = 1.0E-9;
  out.mX[3] = 1.0E-9;
  out.mX[4] = 1.0E-9;
  out.mX[5] = 1.0E-9;
  out.mX[6] = 1.0E-9;
  out.mX[7] = 1.0E-9;
  out.mX[8] = 1.0E-9;
  out.mX[9] = 1.0E-9;
  out.mX[10] = 1.0E-9;
  out.mX[11] = 1.0E-9;
  out.mX[12] = 1.0E-9;
  out.mX[13] = 1.0E-9;
  out.mX[14] = 1.0E-9;
  out.mX[15] = 1.0E-9;
  out.mX[16] = 1.0E-9;
  out.mX[17] = 1.0E-9;
  out.mX[18] = 1.0E-9;
  out.mX[19] = 1.0E-9;
  out.mX[20] = 1.0E-9;
  out.mX[21] = 1.0E-9;
  out.mX[22] = 1.0E-9;
  out.mX[23] = 1.0E-9;
  out.mX[24] = 1.0E-9;
  out.mX[25] = 1.0E-9;
  out.mX[26] = 1.0E-9;
  out.mX[27] = 1.0E-9;
  out.mX[28] = 1.0E-9;
  out.mX[29] = 1.0E-9;
  out.mX[30] = 1.0E-9;
  out.mX[31] = 1.0E-9;
  out.mX[32] = 1.0E-9;
  out.mX[33] = 1.0E-9;
  out.mX[34] = 1.0E-9;
  out.mX[35] = 1.0E-9;
  out.mX[36] = 1.0E-9;
  out.mX[37] = 1.0E-9;
  out.mX[38] = 1.0E-9;
  out.mX[39] = 1.0E-9;
  out.mX[40] = 1.0E-9;
  out.mX[41] = 1.0E-9;
  out.mX[42] = 1.0E-9;
  out.mX[43] = 1.0E-9;
  (void)sys;
  (void)t2;
  return 0;
}
