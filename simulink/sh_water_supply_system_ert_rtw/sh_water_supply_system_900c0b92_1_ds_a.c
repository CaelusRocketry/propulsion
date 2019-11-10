/* Simscape target specific file.
 * This file is generated for the Simscape network associated with the solver block 'sh_water_supply_system/Solver Configuration'.
 */

#include "ne_ds.h"
#include "sh_water_supply_system_900c0b92_1_ds_a.h"
#include "sh_water_supply_system_900c0b92_1_ds_sys_struct.h"
#include "sh_water_supply_system_900c0b92_1_ds_externals.h"
#include "sh_water_supply_system_900c0b92_1_ds_external_struct.h"
#include "ssc_ml_fun.h"

int32_T sh_water_supply_system_900c0b92_1_ds_a(const NeDynamicSystem *sys, const
  NeDynamicSystemInput *t1, NeDsMethodOutput *t2)
{
  PmRealVector out;
  (void)t1;
  out = t2->mA;
  out.mX[0] = 1.0;
  out.mX[1] = -1.0;
  out.mX[2] = -1.0;
  out.mX[3] = -1.0;
  out.mX[4] = 1.0;
  out.mX[5] = -1.0;
  out.mX[6] = -1.0;
  out.mX[7] = 1.0;
  out.mX[8] = -1.0;
  out.mX[9] = 1.0;
  out.mX[10] = -0.00032758374447023795;
  out.mX[11] = 2.472831219846182E-8;
  out.mX[12] = -0.00032758374447023795;
  out.mX[13] = 2.472831219846182E-8;
  out.mX[14] = 1.0;
  out.mX[15] = -1.0;
  out.mX[16] = -1.0;
  out.mX[17] = -1.0;
  out.mX[18] = 1.0;
  out.mX[19] = -0.000378261126104075;
  out.mX[20] = 2.472831219846182E-8;
  out.mX[21] = -0.000378261126104075;
  out.mX[22] = 2.472831219846182E-8;
  out.mX[23] = -1.0;
  out.mX[24] = -1.0;
  out.mX[25] = 1.0;
  out.mX[26] = 1.0;
  out.mX[27] = -1.0;
  out.mX[28] = -1.0;
  out.mX[29] = -1.0;
  out.mX[30] = 1.0;
  out.mX[31] = -0.00040856871242804434;
  out.mX[32] = 2.472831219846182E-8;
  out.mX[33] = -0.00040856871242804434;
  out.mX[34] = 2.472831219846182E-8;
  out.mX[35] = -1.0;
  out.mX[36] = 1.0;
  out.mX[37] = 1.0;
  out.mX[38] = -1.0;
  out.mX[39] = -1.0;
  out.mX[40] = 1.0;
  out.mX[41] = 1.0;
  out.mX[42] = 1.0;
  out.mX[43] = -1.0;
  out.mX[44] = 1.0;
  out.mX[45] = 1.0;
  out.mX[46] = 1.0;
  out.mX[47] = 1.0;
  out.mX[48] = 1.0;
  out.mX[49] = 1.0;
  out.mX[50] = 1.0;
  out.mX[51] = 1.0;
  out.mX[52] = -1.0;
  out.mX[53] = -1.0;
  out.mX[54] = 1.0;
  out.mX[55] = 1.0;
  out.mX[56] = 1.0;
  out.mX[57] = -1.0;
  out.mX[58] = 1.0;
  out.mX[59] = 1.0;
  out.mX[60] = 1.0;
  out.mX[61] = 1.0;
  out.mX[62] = 1.0;
  out.mX[63] = 1.0;
  out.mX[64] = 1.0;
  out.mX[65] = 1.0;
  out.mX[66] = -1.0;
  out.mX[67] = -1.0;
  out.mX[68] = 1.0;
  out.mX[69] = 1.0;
  out.mX[70] = 1.0;
  out.mX[71] = -1.0;
  out.mX[72] = 1.0;
  out.mX[73] = 1.0;
  out.mX[74] = 1.0;
  out.mX[75] = 1.0;
  out.mX[76] = 1.0;
  out.mX[77] = 1.0;
  (void)sys;
  (void)t2;
  return 0;
}
