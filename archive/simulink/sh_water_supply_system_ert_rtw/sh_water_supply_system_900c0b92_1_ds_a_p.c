/* Simscape target specific file.
 * This file is generated for the Simscape network associated with the solver block 'sh_water_supply_system/Solver Configuration'.
 */

#include "ne_ds.h"
#include "sh_water_supply_system_900c0b92_1_ds_a_p.h"
#include "sh_water_supply_system_900c0b92_1_ds_sys_struct.h"
#include "sh_water_supply_system_900c0b92_1_ds_externals.h"
#include "sh_water_supply_system_900c0b92_1_ds_external_struct.h"
#include "ssc_ml_fun.h"

int32_T sh_water_supply_system_900c0b92_1_ds_a_p(const NeDynamicSystem *sys,
  const NeDynamicSystemInput *t1, NeDsMethodOutput *t2)
{
  PmSparsityPattern out;
  (void)t1;
  out = t2->mA_P;
  out.mNumCol = 44ULL;
  out.mNumRow = 44ULL;
  out.mJc[0] = 0;
  out.mJc[1] = 0;
  out.mJc[2] = 0;
  out.mJc[3] = 0;
  out.mJc[4] = 0;
  out.mJc[5] = 3;
  out.mJc[6] = 5;
  out.mJc[7] = 8;
  out.mJc[8] = 10;
  out.mJc[9] = 12;
  out.mJc[10] = 14;
  out.mJc[11] = 17;
  out.mJc[12] = 19;
  out.mJc[13] = 21;
  out.mJc[14] = 23;
  out.mJc[15] = 26;
  out.mJc[16] = 29;
  out.mJc[17] = 31;
  out.mJc[18] = 33;
  out.mJc[19] = 35;
  out.mJc[20] = 36;
  out.mJc[21] = 39;
  out.mJc[22] = 41;
  out.mJc[23] = 43;
  out.mJc[24] = 45;
  out.mJc[25] = 47;
  out.mJc[26] = 48;
  out.mJc[27] = 49;
  out.mJc[28] = 50;
  out.mJc[29] = 53;
  out.mJc[30] = 55;
  out.mJc[31] = 57;
  out.mJc[32] = 59;
  out.mJc[33] = 61;
  out.mJc[34] = 62;
  out.mJc[35] = 63;
  out.mJc[36] = 64;
  out.mJc[37] = 67;
  out.mJc[38] = 69;
  out.mJc[39] = 71;
  out.mJc[40] = 73;
  out.mJc[41] = 75;
  out.mJc[42] = 76;
  out.mJc[43] = 77;
  out.mJc[44] = 78;
  out.mIr[0] = 4;
  out.mIr[1] = 11;
  out.mIr[2] = 13;
  out.mIr[3] = 4;
  out.mIr[4] = 10;
  out.mIr[5] = 4;
  out.mIr[6] = 6;
  out.mIr[7] = 7;
  out.mIr[8] = 4;
  out.mIr[9] = 5;
  out.mIr[10] = 40;
  out.mIr[11] = 43;
  out.mIr[12] = 40;
  out.mIr[13] = 43;
  out.mIr[14] = 6;
  out.mIr[15] = 20;
  out.mIr[16] = 22;
  out.mIr[17] = 6;
  out.mIr[18] = 29;
  out.mIr[19] = 41;
  out.mIr[20] = 43;
  out.mIr[21] = 41;
  out.mIr[22] = 43;
  out.mIr[23] = 7;
  out.mIr[24] = 8;
  out.mIr[25] = 9;
  out.mIr[26] = 8;
  out.mIr[27] = 31;
  out.mIr[28] = 33;
  out.mIr[29] = 8;
  out.mIr[30] = 30;
  out.mIr[31] = 42;
  out.mIr[32] = 43;
  out.mIr[33] = 42;
  out.mIr[34] = 43;
  out.mIr[35] = 9;
  out.mIr[36] = 11;
  out.mIr[37] = 13;
  out.mIr[38] = 15;
  out.mIr[39] = 11;
  out.mIr[40] = 12;
  out.mIr[41] = 11;
  out.mIr[42] = 16;
  out.mIr[43] = 13;
  out.mIr[44] = 14;
  out.mIr[45] = 13;
  out.mIr[46] = 18;
  out.mIr[47] = 15;
  out.mIr[48] = 17;
  out.mIr[49] = 19;
  out.mIr[50] = 20;
  out.mIr[51] = 22;
  out.mIr[52] = 24;
  out.mIr[53] = 20;
  out.mIr[54] = 21;
  out.mIr[55] = 20;
  out.mIr[56] = 25;
  out.mIr[57] = 22;
  out.mIr[58] = 23;
  out.mIr[59] = 22;
  out.mIr[60] = 27;
  out.mIr[61] = 24;
  out.mIr[62] = 26;
  out.mIr[63] = 28;
  out.mIr[64] = 31;
  out.mIr[65] = 33;
  out.mIr[66] = 35;
  out.mIr[67] = 31;
  out.mIr[68] = 32;
  out.mIr[69] = 31;
  out.mIr[70] = 36;
  out.mIr[71] = 33;
  out.mIr[72] = 34;
  out.mIr[73] = 33;
  out.mIr[74] = 38;
  out.mIr[75] = 35;
  out.mIr[76] = 37;
  out.mIr[77] = 39;
  (void)sys;
  (void)t2;
  return 0;
}
