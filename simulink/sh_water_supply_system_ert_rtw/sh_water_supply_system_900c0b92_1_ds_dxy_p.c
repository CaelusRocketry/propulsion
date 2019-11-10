/* Simscape target specific file.
 * This file is generated for the Simscape network associated with the solver block 'sh_water_supply_system/Solver Configuration'.
 */

#include "ne_ds.h"
#include "sh_water_supply_system_900c0b92_1_ds_dxy_p.h"
#include "sh_water_supply_system_900c0b92_1_ds_sys_struct.h"
#include "sh_water_supply_system_900c0b92_1_ds_externals.h"
#include "sh_water_supply_system_900c0b92_1_ds_external_struct.h"
#include "ssc_ml_fun.h"

int32_T sh_water_supply_system_900c0b92_1_ds_dxy_p(const NeDynamicSystem *sys,
  const NeDynamicSystemInput *t1, NeDsMethodOutput *t2)
{
  PmSparsityPattern out;
  (void)t1;
  out = t2->mDXY_P;
  out.mNumCol = 44ULL;
  out.mNumRow = 4ULL;
  out.mJc[0] = 0;
  out.mJc[1] = 1;
  out.mJc[2] = 2;
  out.mJc[3] = 3;
  out.mJc[4] = 4;
  out.mJc[5] = 4;
  out.mJc[6] = 4;
  out.mJc[7] = 4;
  out.mJc[8] = 4;
  out.mJc[9] = 4;
  out.mJc[10] = 4;
  out.mJc[11] = 4;
  out.mJc[12] = 4;
  out.mJc[13] = 4;
  out.mJc[14] = 4;
  out.mJc[15] = 4;
  out.mJc[16] = 4;
  out.mJc[17] = 4;
  out.mJc[18] = 4;
  out.mJc[19] = 4;
  out.mJc[20] = 4;
  out.mJc[21] = 4;
  out.mJc[22] = 4;
  out.mJc[23] = 4;
  out.mJc[24] = 4;
  out.mJc[25] = 4;
  out.mJc[26] = 4;
  out.mJc[27] = 4;
  out.mJc[28] = 4;
  out.mJc[29] = 4;
  out.mJc[30] = 4;
  out.mJc[31] = 4;
  out.mJc[32] = 4;
  out.mJc[33] = 4;
  out.mJc[34] = 4;
  out.mJc[35] = 4;
  out.mJc[36] = 4;
  out.mJc[37] = 4;
  out.mJc[38] = 4;
  out.mJc[39] = 4;
  out.mJc[40] = 4;
  out.mJc[41] = 4;
  out.mJc[42] = 4;
  out.mJc[43] = 4;
  out.mJc[44] = 4;
  out.mIr[0] = 0;
  out.mIr[1] = 1;
  out.mIr[2] = 2;
  out.mIr[3] = 3;
  (void)sys;
  (void)t2;
  return 0;
}
