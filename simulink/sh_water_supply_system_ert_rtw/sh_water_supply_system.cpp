//
// Primary and Secondary School License - for use in teaching and meeting
// course requirements at primary and secondary schools only.  Not for
// government, commercial, university, or other organizational use.
//
// File: sh_water_supply_system.cpp
//
// Code generated for Simulink model 'sh_water_supply_system'.
//
// Model version                  : 1.70
// Simulink Coder version         : 9.1 (R2019a) 23-Nov-2018
// C/C++ source code generated on : Sat Nov  9 18:33:49 2019
//
// Target selection: ert.tlc
// Embedded hardware selection: Intel->x86-64 (Windows64)
// Code generation objectives:
//    1. Execution efficiency
//    2. RAM efficiency
// Validation result: Not run
//
#include "sh_water_supply_system.h"

// Private macros used by the generated code to access rtModel
#ifndef rtmIsMajorTimeStep
# define rtmIsMajorTimeStep(rtm)       (((rtm)->Timing.simTimeStep) == MAJOR_TIME_STEP)
#endif

#ifndef rtmIsMinorTimeStep
# define rtmIsMinorTimeStep(rtm)       (((rtm)->Timing.simTimeStep) == MINOR_TIME_STEP)
#endif

#ifndef rtmSetTPtr
# define rtmSetTPtr(rtm, val)          ((rtm)->Timing.t = (val))
#endif

// Continuous states
X rtX;

// Mass Matrices
MassMatrix rtMassMatrix;

// Block signals and states (default storage)
DW rtDW;

// Real-time model
RT_MODEL rtM_;
RT_MODEL *const rtM = &rtM_;

// private model entry point functions
extern void sh_water_supply_system_derivatives(void);

// ForcingFunction for root system: '<Root>'
void sh_water_supply_system_forcingfunction(void)
{
  NeslSimulationData *simulationData;
  real_T time;
  boolean_T tmp;
  real_T tmp_0[24];
  int_T tmp_1[7];
  NeuDiagnosticManager *diagnosticManager;
  NeuDiagnosticTree *diagnosticTree;
  int32_T tmp_2;
  char *msg;
  XDot *_rtXdot;
  _rtXdot = ((XDot *) rtM->derivs);

  // ForcingFunction for SimscapeExecutionBlock: '<S21>/STATE_1'
  simulationData = (NeslSimulationData *)rtDW.STATE_1_SimData;
  time = rtM->Timing.t[0];
  simulationData->mData->mTime.mN = 1;
  simulationData->mData->mTime.mX = &time;
  simulationData->mData->mContStates.mN = 44;
  simulationData->mData->mContStates.mX = &rtX.sh_water_supply_systemTank_Stat[0];
  simulationData->mData->mDiscStates.mN = 0;
  simulationData->mData->mDiscStates.mX = &rtDW.STATE_1_Discrete;
  simulationData->mData->mModeVector.mN = 0;
  simulationData->mData->mModeVector.mX = &rtDW.STATE_1_Modes;
  tmp = false;
  simulationData->mData->mFoundZcEvents = tmp;
  simulationData->mData->mIsMajorTimeStep = rtmIsMajorTimeStep(rtM);
  tmp = false;
  simulationData->mData->mIsSolverAssertCheck = tmp;
  simulationData->mData->mIsSolverCheckingCIC = false;
  tmp = rtsiIsSolverComputingJacobian(&rtM->solverInfo);
  simulationData->mData->mIsComputingJacobian = tmp;
  simulationData->mData->mIsEvaluatingF0 = false;
  simulationData->mData->mIsSolverRequestingReset = false;
  tmp_1[0] = 0;
  tmp_0[0] = rtDW.INPUT_2_1_1[0];
  tmp_0[1] = rtDW.INPUT_2_1_1[1];
  tmp_0[2] = rtDW.INPUT_2_1_1[2];
  tmp_0[3] = rtDW.INPUT_2_1_1[3];
  tmp_1[1] = 4;
  tmp_0[4] = rtDW.INPUT_1_1_1[0];
  tmp_0[5] = rtDW.INPUT_1_1_1[1];
  tmp_0[6] = rtDW.INPUT_1_1_1[2];
  tmp_0[7] = rtDW.INPUT_1_1_1[3];
  tmp_1[2] = 8;
  tmp_0[8] = rtDW.INPUT_4_1_1[0];
  tmp_0[9] = rtDW.INPUT_4_1_1[1];
  tmp_0[10] = rtDW.INPUT_4_1_1[2];
  tmp_0[11] = rtDW.INPUT_4_1_1[3];
  tmp_1[3] = 12;
  tmp_0[12] = rtDW.INPUT_3_1_1[0];
  tmp_0[13] = rtDW.INPUT_3_1_1[1];
  tmp_0[14] = rtDW.INPUT_3_1_1[2];
  tmp_0[15] = rtDW.INPUT_3_1_1[3];
  tmp_1[4] = 16;
  tmp_0[16] = rtDW.INPUT_6_1_1[0];
  tmp_0[17] = rtDW.INPUT_6_1_1[1];
  tmp_0[18] = rtDW.INPUT_6_1_1[2];
  tmp_0[19] = rtDW.INPUT_6_1_1[3];
  tmp_1[5] = 20;
  tmp_0[20] = rtDW.INPUT_5_1_1[0];
  tmp_0[21] = rtDW.INPUT_5_1_1[1];
  tmp_0[22] = rtDW.INPUT_5_1_1[2];
  tmp_0[23] = rtDW.INPUT_5_1_1[3];
  tmp_1[6] = 24;
  simulationData->mData->mInputValues.mN = 24;
  simulationData->mData->mInputValues.mX = &tmp_0[0];
  simulationData->mData->mInputOffsets.mN = 7;
  simulationData->mData->mInputOffsets.mX = &tmp_1[0];
  simulationData->mData->mDx.mN = 44;
  simulationData->mData->mDx.mX = &_rtXdot->sh_water_supply_systemTank_Stat[0];
  diagnosticManager = (NeuDiagnosticManager *)rtDW.STATE_1_DiagMgr;
  diagnosticTree = neu_diagnostic_manager_get_initial_tree(diagnosticManager);
  tmp_2 = ne_simulator_method((NeslSimulator *)rtDW.STATE_1_Simulator,
    NESL_SIM_FORCINGFUNCTION, simulationData, diagnosticManager);
  if (tmp_2 != 0) {
    tmp = error_buffer_is_empty(rtmGetErrorStatus(rtM));
    if (tmp) {
      msg = rtw_diagnostics_msg(diagnosticTree);
      rtmSetErrorStatus(rtM, msg);
    }
  }

  // End of ForcingFunction for SimscapeExecutionBlock: '<S21>/STATE_1'
}

// MassMatrix for root system: '<Root>'
void sh_water_supply_system_massmatrix(void)
{
  NeslSimulationData *simulationData;
  real_T time;
  boolean_T tmp;
  real_T tmp_0[24];
  int_T tmp_1[7];
  real_T *tmp_2;
  NeuDiagnosticManager *diagnosticManager;
  NeuDiagnosticTree *diagnosticTree;
  int32_T tmp_3;
  char *msg;

  // MassMatrix for SimscapeExecutionBlock: '<S21>/STATE_1'
  simulationData = (NeslSimulationData *)rtDW.STATE_1_SimData;
  time = rtM->Timing.t[0];
  simulationData->mData->mTime.mN = 1;
  simulationData->mData->mTime.mX = &time;
  simulationData->mData->mContStates.mN = 44;
  simulationData->mData->mContStates.mX = &rtX.sh_water_supply_systemTank_Stat[0];
  simulationData->mData->mDiscStates.mN = 0;
  simulationData->mData->mDiscStates.mX = &rtDW.STATE_1_Discrete;
  simulationData->mData->mModeVector.mN = 0;
  simulationData->mData->mModeVector.mX = &rtDW.STATE_1_Modes;
  tmp = false;
  simulationData->mData->mFoundZcEvents = tmp;
  simulationData->mData->mIsMajorTimeStep = rtmIsMajorTimeStep(rtM);
  tmp = false;
  simulationData->mData->mIsSolverAssertCheck = tmp;
  simulationData->mData->mIsSolverCheckingCIC = false;
  tmp = rtsiIsSolverComputingJacobian(&rtM->solverInfo);
  simulationData->mData->mIsComputingJacobian = tmp;
  simulationData->mData->mIsEvaluatingF0 = false;
  simulationData->mData->mIsSolverRequestingReset = false;
  tmp_1[0] = 0;
  tmp_0[0] = rtDW.INPUT_2_1_1[0];
  tmp_0[1] = rtDW.INPUT_2_1_1[1];
  tmp_0[2] = rtDW.INPUT_2_1_1[2];
  tmp_0[3] = rtDW.INPUT_2_1_1[3];
  tmp_1[1] = 4;
  tmp_0[4] = rtDW.INPUT_1_1_1[0];
  tmp_0[5] = rtDW.INPUT_1_1_1[1];
  tmp_0[6] = rtDW.INPUT_1_1_1[2];
  tmp_0[7] = rtDW.INPUT_1_1_1[3];
  tmp_1[2] = 8;
  tmp_0[8] = rtDW.INPUT_4_1_1[0];
  tmp_0[9] = rtDW.INPUT_4_1_1[1];
  tmp_0[10] = rtDW.INPUT_4_1_1[2];
  tmp_0[11] = rtDW.INPUT_4_1_1[3];
  tmp_1[3] = 12;
  tmp_0[12] = rtDW.INPUT_3_1_1[0];
  tmp_0[13] = rtDW.INPUT_3_1_1[1];
  tmp_0[14] = rtDW.INPUT_3_1_1[2];
  tmp_0[15] = rtDW.INPUT_3_1_1[3];
  tmp_1[4] = 16;
  tmp_0[16] = rtDW.INPUT_6_1_1[0];
  tmp_0[17] = rtDW.INPUT_6_1_1[1];
  tmp_0[18] = rtDW.INPUT_6_1_1[2];
  tmp_0[19] = rtDW.INPUT_6_1_1[3];
  tmp_1[5] = 20;
  tmp_0[20] = rtDW.INPUT_5_1_1[0];
  tmp_0[21] = rtDW.INPUT_5_1_1[1];
  tmp_0[22] = rtDW.INPUT_5_1_1[2];
  tmp_0[23] = rtDW.INPUT_5_1_1[3];
  tmp_1[6] = 24;
  simulationData->mData->mInputValues.mN = 24;
  simulationData->mData->mInputValues.mX = &tmp_0[0];
  simulationData->mData->mInputOffsets.mN = 7;
  simulationData->mData->mInputOffsets.mX = &tmp_1[0];
  tmp_2 = rtMassMatrix.pr;
  tmp_2 = double_pointer_shift(tmp_2, rtDW.STATE_1_MASS_MATRIX_PR);
  simulationData->mData->mMassMatrixPr.mN = 4;
  simulationData->mData->mMassMatrixPr.mX = tmp_2;
  diagnosticManager = (NeuDiagnosticManager *)rtDW.STATE_1_DiagMgr;
  diagnosticTree = neu_diagnostic_manager_get_initial_tree(diagnosticManager);
  tmp_3 = ne_simulator_method((NeslSimulator *)rtDW.STATE_1_Simulator,
    NESL_SIM_MASSMATRIX, simulationData, diagnosticManager);
  if (tmp_3 != 0) {
    tmp = error_buffer_is_empty(rtmGetErrorStatus(rtM));
    if (tmp) {
      msg = rtw_diagnostics_msg(diagnosticTree);
      rtmSetErrorStatus(rtM, msg);
    }
  }

  // End of MassMatrix for SimscapeExecutionBlock: '<S21>/STATE_1'
}

void local_evaluateMassMatrix(RTWSolverInfo *si, real_T *Mdest )
{
  // Refresh global mass matrix
  sh_water_supply_system_massmatrix();

  // Copy the mass matrix from system to the destination, if needed.
  if (Mdest != rtsiGetSolverMassMatrixPr(si)) {
    real_T *Msrc = rtsiGetSolverMassMatrixPr(si);
    int_T nzmax = rtsiGetSolverMassMatrixNzMax(si);
    (void) memcpy(Mdest, Msrc,
                  (uint_T)nzmax*sizeof(real_T));
  }
}

// Simplified version of numjac.cpp, for use with RTW.
void local_numjac( RTWSolverInfo *si, real_T *y, const real_T *Fty, real_T *fac,
                  real_T *dFdy )
{
  // constants
  real_T THRESH = 1e-6;
  real_T EPS = 2.2e-16;                // utGetEps();
  real_T BL = std::pow(EPS, 0.75);
  real_T BU = std::pow(EPS, 0.25);
  real_T FACMIN = std::pow(EPS, 0.78);
  real_T FACMAX = 0.1;
  int_T nx = 44;
  real_T *x = rtsiGetContStates(si);
  real_T del;
  real_T difmax;
  real_T FdelRowmax;
  real_T temp;
  real_T Fdiff;
  real_T maybe;
  real_T xscale;
  real_T fscale;
  real_T *p;
  int_T rowmax;
  int_T i,j;
  if (x != y)
    (void) memcpy(x, y,
                  (uint_T)nx*sizeof(real_T));
  rtsiSetSolverComputingJacobian(si,true);
  for (p = dFdy, j = 0; j < nx; j++, p += nx) {
    // Select an increment del for a difference approximation to
    // column j of dFdy.  The vector fac accounts for experience
    // gained in previous calls to numjac.
    xscale = std::abs(x[j]);
    if (xscale < THRESH)
      xscale = THRESH;
    temp = (x[j] + fac[j]*xscale);
    del = temp - y[j];
    while (del == 0.0) {
      if (fac[j] < FACMAX) {
        fac[j] *= 100.0;
        if (fac[j] > FACMAX)
          fac[j] = FACMAX;
        temp = (x[j] + fac[j]*xscale);
        del = temp - x[j];
      } else {
        del = THRESH;                  // thresh is nonzero
        break;
      }
    }

    // Keep del pointing into region.
    if (Fty[j] >= 0.0)
      del = std::abs(del);
    else
      del = -std::abs(del);

    // Form a difference approximation to column j of dFdy.
    temp = x[j];
    x[j] += del;
    sh_water_supply_system_step();
    rtsiSetdX(si,p);
    sh_water_supply_system_forcingfunction();
    x[j] = temp;
    difmax = 0.0;
    rowmax = 0;
    FdelRowmax = p[0];
    temp = 1.0 / del;
    for (i = 0; i < nx; i++) {
      Fdiff = p[i] - Fty[i];
      maybe = std::abs(Fdiff);
      if (maybe > difmax) {
        difmax = maybe;
        rowmax = i;
        FdelRowmax = p[i];
      }

      p[i] = temp * Fdiff;
    }

    // Adjust fac for next call to numjac.
    if (((FdelRowmax != 0.0) && (Fty[rowmax] != 0.0)) || (difmax == 0.0)) {
      fscale = std::abs(FdelRowmax);
      if (fscale < std::abs(Fty[rowmax]))
        fscale = std::abs(Fty[rowmax]);
      if (difmax <= BL*fscale) {
        // The difference is small, so increase the increment.
        fac[j] *= 10.0;
        if (fac[j] > FACMAX)
          fac[j] = FACMAX;
      } else if (difmax > BU*fscale) {
        // The difference is large, so reduce the increment.
        fac[j] *= 0.1;
        if (fac[j] < FACMIN)
          fac[j] = FACMIN;
      }
    }
  }

  rtsiSetSolverComputingJacobian(si,false);
}                                      // end local_numjac

//
// This function updates continuous states using the ODE14x fixed-step
// solver algorithm
//
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  // Solver Matrices
  static int_T rt_ODE14x_N[4] = { 12, 8, 6, 4 };

  time_T t0 = rtsiGetT(si);
  time_T t1 = t0;
  time_T h = rtsiGetStepSize(si);
  real_T *x1 = rtsiGetContStates(si);
  int_T order = rtsiGetSolverExtrapolationOrder(si);
  int_T numIter = rtsiGetSolverNumberNewtonIterations(si);
  ODE14X_IntgData *id = (ODE14X_IntgData *)rtsiGetSolverData(si);
  real_T *x0 = id->x0;
  real_T *f0 = id->f0;
  real_T *x1start = id->x1start;
  real_T *f1 = id->f1;
  real_T *Delta = id->Delta;
  real_T *E = id->E;
  real_T *fac = id->fac;
  real_T *dfdx = id->DFDX;
  real_T *W = id->W;
  int_T *pivots = id->pivots;
  real_T *xtmp = id->xtmp;
  real_T *ztmp = id->ztmp;
  int_T *Mpattern_ir = rtsiGetSolverMassMatrixIr(si);
  int_T *Mpattern_jc = rtsiGetSolverMassMatrixJc(si);
  real_T *M = id->M;
  int_T col,row,rowidx;
  int_T *N = &(rt_ODE14x_N[0]);
  int_T i,j,k,iter;
  int_T nx = 44;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  // Save the state values at time t in y, we'll use x as ynew.
  (void) memcpy(x0, x1,
                (uint_T)nx*sizeof(real_T));

  // Assumes that rtsiSetT and ModelOutputs are up-to-date
  if (id->isFirstStep) {
    local_evaluateMassMatrix(si,M );
    id->isFirstStep = false;
  }

  // f0 = f(t,y)
  rtsiSetdX(si, f0);
  sh_water_supply_system_forcingfunction();
  local_numjac(si,x0,f0,fac,dfdx );
  for (j = 0; j < order; j++) {
    real_T *p;
    real_T hN = h/N[j];

    // Get the iteration matrix and solution at t0

    // [L,U] = lu(M - hN*J)
    (void) memcpy(W, dfdx,
                  (uint_T)nx*nx*sizeof(real_T));
    for (p = W, i = 0; i < nx*nx; i++, p++) {
      *p *= (-hN);
    }

    for (col = 0, p = W; col < nx; col++, p += nx) {
      for (rowidx = Mpattern_jc[col]; rowidx < Mpattern_jc[col+1]; rowidx++) {
        real_T m_row_col = M[rowidx];
        row = Mpattern_ir[rowidx];
        p[row] += m_row_col;
      }
    }

    rt_lu_real(W, nx,
               pivots);

    // First Newton's iteration at t0.
    // rhs = hN*f0
    for (i = 0; i < nx; i++) {
      Delta[i] = hN*f0[i];
    }

    // Delta = (U \ (L \ rhs))
    rt_ForwardSubstitutionRR_Dbl(W, Delta,
      f1, nx,
      1, pivots,
      1);
    rt_BackwardSubstitutionRR_Dbl(W+nx*nx-1, f1+nx-1,
      Delta, nx,
      1, 0);

    // ytmp = y0 + Delta
    // ztmp = (ytmp-y0)/h

    (void) memcpy(x1, x0,
                  (uint_T)nx*sizeof(real_T));
    for (i = 0; i < nx; i++) {
      x1[i] += Delta[i];
      ztmp[i] = Delta[i]/hN;
    }

    // Additional Newton's iterations, if desired.
    // for iter = 2:NewtIter
    // rhs = hN*feval(odefun,tn,ytmp,extraArgs{:}) - M*(ytmp - yn);
    // if statedepM   % only for state dep. Mdel ~= 0
    // Mdel = M - feval(massfun,tn,ytmp);
    // rhs = rhs + Mdel*ztmp*h;
    // end
    // Delta = ( U \ ( L \ rhs ) );
    // ytmp = ytmp + Delta;
    // ztmp = (ytmp - yn)/h
    // end

    rtsiSetT(si, t0);
    rtsiSetdX(si, f1);
    for (iter = 1; iter < numIter; iter++) {
      sh_water_supply_system_step();
      sh_water_supply_system_forcingfunction();
      for (i = 0; i < nx; i++) {
        Delta[i] = hN*f1[i];
        xtmp[i] = x1[i] - x0[i];
      }

      // rhs = hN*f(tn,ytmp) - M*(ytmp-yn)
      for (col = 0; col < nx; col++) {
        for (rowidx = Mpattern_jc[col]; rowidx < Mpattern_jc[col+1]; rowidx++) {
          real_T m_row_col = M[rowidx];
          row = Mpattern_ir[rowidx];
          Delta[row] -= m_row_col*xtmp[col];
        }
      }

      rt_ForwardSubstitutionRR_Dbl(W, Delta,
        f1, nx,
        1, pivots,
        1);
      rt_BackwardSubstitutionRR_Dbl(W+nx*nx-1, f1+nx-1,
        Delta, nx,
        1, 0);

      // ytmp = ytmp + delta
      // ztmp = (ytmp - yn)/h

      for (i = 0; i < nx; i++) {
        x1[i] += Delta[i];
        ztmp[i] = (x1[i] - x0[i])/hN;
      }
    }

    // Steps from t0+hN to t1 -- subintegration of N(j) steps for extrapolation
    // ttmp = t0;
    // for i = 2:N(j)
    // ttmp = ttmp + hN
    // ytmp0 = ytmp;
    // for iter = 1:NewtIter
    // rhs = (ytmp0 - ytmp) + hN*feval(odefun,ttmp,ytmp,extraArgs{:});
    // Delta = ( U \ ( L \ rhs ) );
    // ytmp = ytmp + Delta;
    // end
    // end

    for (k = 1; k < N[j]; k++) {
      t1 = t0 + k*hN;
      (void) memcpy(x1start, x1,
                    (uint_T)nx*sizeof(real_T));
      rtsiSetT(si, t1);
      rtsiSetdX(si, f1);
      for (iter = 0; iter < numIter; iter++) {
        sh_water_supply_system_step();
        sh_water_supply_system_forcingfunction();
        if (iter == 0) {
          for (i = 0; i < nx; i++) {
            Delta[i] = hN*f1[i];
          }
        } else {
          for (i = 0; i < nx; i++) {
            Delta[i] = hN*f1[i];
            xtmp[i] = (x1[i]-x1start[i]);
          }

          // rhs = hN*f(tn,ytmp) - M*(ytmp-yn)
          for (col = 0; col < nx; col++) {
            for (rowidx = Mpattern_jc[col]; rowidx < Mpattern_jc[col+1]; rowidx
                 ++) {
              real_T m_row_col = M[rowidx];
              row = Mpattern_ir[rowidx];
              Delta[row] -= m_row_col*xtmp[col];
            }
          }
        }

        rt_ForwardSubstitutionRR_Dbl(W, Delta,
          f1, nx,
          1, pivots,
          1);
        rt_BackwardSubstitutionRR_Dbl(W+nx*nx-1, f1+nx-1,
          Delta, nx,
          1, 0);

        // ytmp = ytmp + Delta
        // ztmp = (ytmp - ytmp0)/h

        for (i = 0; i < nx; i++) {
          x1[i] += Delta[i];
          ztmp[i] = (x1[i] - x1start[i])/hN;
        }
      }
    }

    // Extrapolate to order j
    // E(:,j) = ytmp
    // for k = j:-1:2
    // coef = N(k-1)/(N(j) - N(k-1))
    // E(:,k-1) = E(:,k) + coef*( E(:,k) - E(:,k-1) )
    // end

    (void) memcpy(&(E[nx*j]), x1,
                  (uint_T)nx*sizeof(real_T));
    for (k = j; k > 0; k--) {
      real_T coef = (real_T)(N[k-1]) / (N[j]-N[k-1]);
      for (i = 0; i < nx; i++) {
        x1[i] = E[nx*k+i] + coef*(E[nx*k+i] - E[nx*(k-1)+i]);
      }

      (void) memcpy(&(E[nx*(k-1)]), x1,
                    (uint_T)nx*sizeof(real_T));
    }
  }

  // x1 = E(:,1);
  (void) memcpy(x1, E,
                (uint_T)nx*sizeof(real_T));

  // t1 = t0 + h;
  rtsiSetT(si,rtsiGetSolverStopTime(si));
  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

// Model step function
void sh_water_supply_system_step(void)
{
  if (rtmIsMajorTimeStep(rtM)) {
    // set solver stop time
    rtsiSetSolverStopTime(&rtM->solverInfo,((rtM->Timing.clockTick0+1)*
      rtM->Timing.stepSize0));
  }                                    // end MajorTimeStep

  // Update absolute time of base rate at minor time step
  if (rtmIsMinorTimeStep(rtM)) {
    rtM->Timing.t[0] = rtsiGetT(&rtM->solverInfo);
  }

  {
    NeslSimulationData *simulationData;
    real_T time;
    boolean_T tmp;
    real_T tmp_0[24];
    int_T tmp_1[7];
    NeuDiagnosticManager *diagnosticManager;
    NeuDiagnosticTree *diagnosticTree;
    int32_T tmp_2;
    char *msg;
    real_T time_0;
    real_T tmp_3[68];
    int_T tmp_4[8];
    real_T rtb_OUTPUT_1_0[4];
    real_T time_tmp;
    boolean_T tmp_5;

    // SimscapeInputBlock: '<S21>/INPUT_2_1_1' incorporates:
    //   Constant: '<S1>/Speed Pump 1'

    rtDW.INPUT_2_1_1[0] = 178.02358370342159;
    rtDW.INPUT_2_1_1[1] = 0.0;
    rtDW.INPUT_2_1_1[2] = 0.0;
    if (rtmIsMajorTimeStep(rtM)) {
      rtDW.INPUT_2_1_1_Discrete[0] = !(rtDW.INPUT_2_1_1[0] ==
        rtDW.INPUT_2_1_1_Discrete[1]);
      rtDW.INPUT_2_1_1_Discrete[1] = rtDW.INPUT_2_1_1[0];
    }

    rtDW.INPUT_2_1_1[0] = rtDW.INPUT_2_1_1_Discrete[1];
    rtDW.INPUT_2_1_1[3] = rtDW.INPUT_2_1_1_Discrete[0];

    // End of SimscapeInputBlock: '<S21>/INPUT_2_1_1'

    // SimscapeInputBlock: '<S21>/INPUT_1_1_1' incorporates:
    //   Constant: '<S1>/Speed Pump 2'

    rtDW.INPUT_1_1_1[0] = 178.02358370342159;
    rtDW.INPUT_1_1_1[1] = 0.0;
    rtDW.INPUT_1_1_1[2] = 0.0;
    if (rtmIsMajorTimeStep(rtM)) {
      rtDW.INPUT_1_1_1_Discrete[0] = !(rtDW.INPUT_1_1_1[0] ==
        rtDW.INPUT_1_1_1_Discrete[1]);
      rtDW.INPUT_1_1_1_Discrete[1] = rtDW.INPUT_1_1_1[0];
    }

    rtDW.INPUT_1_1_1[0] = rtDW.INPUT_1_1_1_Discrete[1];
    rtDW.INPUT_1_1_1[3] = rtDW.INPUT_1_1_1_Discrete[0];

    // End of SimscapeInputBlock: '<S21>/INPUT_1_1_1'

    // SimscapeInputBlock: '<S21>/INPUT_4_1_1' incorporates:
    //   Constant: '<S2>/Speed Pump 1'

    rtDW.INPUT_4_1_1[0] = 178.02358370342159;
    rtDW.INPUT_4_1_1[1] = 0.0;
    rtDW.INPUT_4_1_1[2] = 0.0;
    if (rtmIsMajorTimeStep(rtM)) {
      rtDW.INPUT_4_1_1_Discrete[0] = !(rtDW.INPUT_4_1_1[0] ==
        rtDW.INPUT_4_1_1_Discrete[1]);
      rtDW.INPUT_4_1_1_Discrete[1] = rtDW.INPUT_4_1_1[0];
    }

    rtDW.INPUT_4_1_1[0] = rtDW.INPUT_4_1_1_Discrete[1];
    rtDW.INPUT_4_1_1[3] = rtDW.INPUT_4_1_1_Discrete[0];

    // End of SimscapeInputBlock: '<S21>/INPUT_4_1_1'

    // SimscapeInputBlock: '<S21>/INPUT_3_1_1' incorporates:
    //   Constant: '<S2>/Speed Pump 2'

    rtDW.INPUT_3_1_1[0] = 178.02358370342159;
    rtDW.INPUT_3_1_1[1] = 0.0;
    rtDW.INPUT_3_1_1[2] = 0.0;
    if (rtmIsMajorTimeStep(rtM)) {
      rtDW.INPUT_3_1_1_Discrete[0] = !(rtDW.INPUT_3_1_1[0] ==
        rtDW.INPUT_3_1_1_Discrete[1]);
      rtDW.INPUT_3_1_1_Discrete[1] = rtDW.INPUT_3_1_1[0];
    }

    rtDW.INPUT_3_1_1[0] = rtDW.INPUT_3_1_1_Discrete[1];
    rtDW.INPUT_3_1_1[3] = rtDW.INPUT_3_1_1_Discrete[0];

    // End of SimscapeInputBlock: '<S21>/INPUT_3_1_1'

    // SimscapeInputBlock: '<S21>/INPUT_6_1_1' incorporates:
    //   Constant: '<S3>/Speed Pump 1'

    rtDW.INPUT_6_1_1[0] = 178.02358370342159;
    rtDW.INPUT_6_1_1[1] = 0.0;
    rtDW.INPUT_6_1_1[2] = 0.0;
    if (rtmIsMajorTimeStep(rtM)) {
      rtDW.INPUT_6_1_1_Discrete[0] = !(rtDW.INPUT_6_1_1[0] ==
        rtDW.INPUT_6_1_1_Discrete[1]);
      rtDW.INPUT_6_1_1_Discrete[1] = rtDW.INPUT_6_1_1[0];
    }

    rtDW.INPUT_6_1_1[0] = rtDW.INPUT_6_1_1_Discrete[1];
    rtDW.INPUT_6_1_1[3] = rtDW.INPUT_6_1_1_Discrete[0];

    // End of SimscapeInputBlock: '<S21>/INPUT_6_1_1'

    // SimscapeInputBlock: '<S21>/INPUT_5_1_1' incorporates:
    //   Constant: '<S3>/Speed Pump 2'

    rtDW.INPUT_5_1_1[0] = 178.02358370342159;
    rtDW.INPUT_5_1_1[1] = 0.0;
    rtDW.INPUT_5_1_1[2] = 0.0;
    if (rtmIsMajorTimeStep(rtM)) {
      rtDW.INPUT_5_1_1_Discrete[0] = !(rtDW.INPUT_5_1_1[0] ==
        rtDW.INPUT_5_1_1_Discrete[1]);
      rtDW.INPUT_5_1_1_Discrete[1] = rtDW.INPUT_5_1_1[0];
    }

    rtDW.INPUT_5_1_1[0] = rtDW.INPUT_5_1_1_Discrete[1];
    rtDW.INPUT_5_1_1[3] = rtDW.INPUT_5_1_1_Discrete[0];

    // End of SimscapeInputBlock: '<S21>/INPUT_5_1_1'

    // SimscapeExecutionBlock: '<S21>/STATE_1' incorporates:
    //   SimscapeExecutionBlock: '<S21>/OUTPUT_1_0'

    simulationData = (NeslSimulationData *)rtDW.STATE_1_SimData;
    time_tmp = rtM->Timing.t[0];
    time = time_tmp;
    simulationData->mData->mTime.mN = 1;
    simulationData->mData->mTime.mX = &time;
    simulationData->mData->mContStates.mN = 44;
    simulationData->mData->mContStates.mX =
      &rtX.sh_water_supply_systemTank_Stat[0];
    simulationData->mData->mDiscStates.mN = 0;
    simulationData->mData->mDiscStates.mX = &rtDW.STATE_1_Discrete;
    simulationData->mData->mModeVector.mN = 0;
    simulationData->mData->mModeVector.mX = &rtDW.STATE_1_Modes;
    tmp = false;
    simulationData->mData->mFoundZcEvents = tmp;
    tmp_5 = rtmIsMajorTimeStep(rtM);
    simulationData->mData->mIsMajorTimeStep = tmp_5;
    tmp = false;
    simulationData->mData->mIsSolverAssertCheck = tmp;
    simulationData->mData->mIsSolverCheckingCIC = false;
    tmp = rtsiIsSolverComputingJacobian(&rtM->solverInfo);
    simulationData->mData->mIsComputingJacobian = tmp;
    simulationData->mData->mIsEvaluatingF0 = false;
    simulationData->mData->mIsSolverRequestingReset = false;
    tmp_1[0] = 0;
    tmp_0[0] = rtDW.INPUT_2_1_1[0];
    tmp_0[1] = rtDW.INPUT_2_1_1[1];
    tmp_0[2] = rtDW.INPUT_2_1_1[2];
    tmp_0[3] = rtDW.INPUT_2_1_1[3];
    tmp_1[1] = 4;
    tmp_0[4] = rtDW.INPUT_1_1_1[0];
    tmp_0[5] = rtDW.INPUT_1_1_1[1];
    tmp_0[6] = rtDW.INPUT_1_1_1[2];
    tmp_0[7] = rtDW.INPUT_1_1_1[3];
    tmp_1[2] = 8;
    tmp_0[8] = rtDW.INPUT_4_1_1[0];
    tmp_0[9] = rtDW.INPUT_4_1_1[1];
    tmp_0[10] = rtDW.INPUT_4_1_1[2];
    tmp_0[11] = rtDW.INPUT_4_1_1[3];
    tmp_1[3] = 12;
    tmp_0[12] = rtDW.INPUT_3_1_1[0];
    tmp_0[13] = rtDW.INPUT_3_1_1[1];
    tmp_0[14] = rtDW.INPUT_3_1_1[2];
    tmp_0[15] = rtDW.INPUT_3_1_1[3];
    tmp_1[4] = 16;
    tmp_0[16] = rtDW.INPUT_6_1_1[0];
    tmp_0[17] = rtDW.INPUT_6_1_1[1];
    tmp_0[18] = rtDW.INPUT_6_1_1[2];
    tmp_0[19] = rtDW.INPUT_6_1_1[3];
    tmp_1[5] = 20;
    tmp_0[20] = rtDW.INPUT_5_1_1[0];
    tmp_0[21] = rtDW.INPUT_5_1_1[1];
    tmp_0[22] = rtDW.INPUT_5_1_1[2];
    tmp_0[23] = rtDW.INPUT_5_1_1[3];
    tmp_1[6] = 24;
    simulationData->mData->mInputValues.mN = 24;
    simulationData->mData->mInputValues.mX = &tmp_0[0];
    simulationData->mData->mInputOffsets.mN = 7;
    simulationData->mData->mInputOffsets.mX = &tmp_1[0];
    simulationData->mData->mOutputs.mN = 44;
    simulationData->mData->mOutputs.mX = &rtDW.STATE_1[0];
    simulationData->mData->mSampleHits.mN = 0;
    simulationData->mData->mSampleHits.mX = NULL;
    simulationData->mData->mIsFundamentalSampleHit = false;
    simulationData->mData->mTolerances.mN = 0;
    simulationData->mData->mTolerances.mX = NULL;
    simulationData->mData->mCstateHasChanged = false;
    diagnosticManager = (NeuDiagnosticManager *)rtDW.STATE_1_DiagMgr;
    diagnosticTree = neu_diagnostic_manager_get_initial_tree(diagnosticManager);
    tmp_2 = ne_simulator_method((NeslSimulator *)rtDW.STATE_1_Simulator,
      NESL_SIM_OUTPUTS, simulationData, diagnosticManager);
    if (tmp_2 != 0) {
      tmp = error_buffer_is_empty(rtmGetErrorStatus(rtM));
      if (tmp) {
        msg = rtw_diagnostics_msg(diagnosticTree);
        rtmSetErrorStatus(rtM, msg);
      }
    }

    // End of SimscapeExecutionBlock: '<S21>/STATE_1'

    // SimscapeExecutionBlock: '<S21>/OUTPUT_1_0'
    simulationData = (NeslSimulationData *)rtDW.OUTPUT_1_0_SimData;
    time_0 = time_tmp;
    simulationData->mData->mTime.mN = 1;
    simulationData->mData->mTime.mX = &time_0;
    simulationData->mData->mContStates.mN = 0;
    simulationData->mData->mContStates.mX = NULL;
    simulationData->mData->mDiscStates.mN = 0;
    simulationData->mData->mDiscStates.mX = &rtDW.OUTPUT_1_0_Discrete;
    simulationData->mData->mModeVector.mN = 0;
    simulationData->mData->mModeVector.mX = &rtDW.OUTPUT_1_0_Modes;
    tmp = false;
    simulationData->mData->mFoundZcEvents = tmp;
    simulationData->mData->mIsMajorTimeStep = tmp_5;
    tmp = false;
    simulationData->mData->mIsSolverAssertCheck = tmp;
    simulationData->mData->mIsSolverCheckingCIC = false;
    simulationData->mData->mIsComputingJacobian = false;
    simulationData->mData->mIsEvaluatingF0 = false;
    simulationData->mData->mIsSolverRequestingReset = false;
    tmp_4[0] = 0;
    tmp_3[0] = rtDW.INPUT_2_1_1[0];
    tmp_3[1] = rtDW.INPUT_2_1_1[1];
    tmp_3[2] = rtDW.INPUT_2_1_1[2];
    tmp_3[3] = rtDW.INPUT_2_1_1[3];
    tmp_4[1] = 4;
    tmp_3[4] = rtDW.INPUT_1_1_1[0];
    tmp_3[5] = rtDW.INPUT_1_1_1[1];
    tmp_3[6] = rtDW.INPUT_1_1_1[2];
    tmp_3[7] = rtDW.INPUT_1_1_1[3];
    tmp_4[2] = 8;
    tmp_3[8] = rtDW.INPUT_4_1_1[0];
    tmp_3[9] = rtDW.INPUT_4_1_1[1];
    tmp_3[10] = rtDW.INPUT_4_1_1[2];
    tmp_3[11] = rtDW.INPUT_4_1_1[3];
    tmp_4[3] = 12;
    tmp_3[12] = rtDW.INPUT_3_1_1[0];
    tmp_3[13] = rtDW.INPUT_3_1_1[1];
    tmp_3[14] = rtDW.INPUT_3_1_1[2];
    tmp_3[15] = rtDW.INPUT_3_1_1[3];
    tmp_4[4] = 16;
    tmp_3[16] = rtDW.INPUT_6_1_1[0];
    tmp_3[17] = rtDW.INPUT_6_1_1[1];
    tmp_3[18] = rtDW.INPUT_6_1_1[2];
    tmp_3[19] = rtDW.INPUT_6_1_1[3];
    tmp_4[5] = 20;
    tmp_3[20] = rtDW.INPUT_5_1_1[0];
    tmp_3[21] = rtDW.INPUT_5_1_1[1];
    tmp_3[22] = rtDW.INPUT_5_1_1[2];
    tmp_3[23] = rtDW.INPUT_5_1_1[3];
    tmp_4[6] = 24;
    memcpy(&tmp_3[24], &rtDW.STATE_1[0], 44U * sizeof(real_T));
    tmp_4[7] = 68;
    simulationData->mData->mInputValues.mN = 68;
    simulationData->mData->mInputValues.mX = &tmp_3[0];
    simulationData->mData->mInputOffsets.mN = 8;
    simulationData->mData->mInputOffsets.mX = &tmp_4[0];
    simulationData->mData->mOutputs.mN = 4;
    simulationData->mData->mOutputs.mX = &rtb_OUTPUT_1_0[0];
    simulationData->mData->mSampleHits.mN = 0;
    simulationData->mData->mSampleHits.mX = NULL;
    simulationData->mData->mIsFundamentalSampleHit = false;
    simulationData->mData->mTolerances.mN = 0;
    simulationData->mData->mTolerances.mX = NULL;
    simulationData->mData->mCstateHasChanged = false;
    diagnosticManager = (NeuDiagnosticManager *)rtDW.OUTPUT_1_0_DiagMgr;
    diagnosticTree = neu_diagnostic_manager_get_initial_tree(diagnosticManager);
    tmp_2 = ne_simulator_method((NeslSimulator *)rtDW.OUTPUT_1_0_Simulator,
      NESL_SIM_OUTPUTS, simulationData, diagnosticManager);
    if (tmp_2 != 0) {
      tmp = error_buffer_is_empty(rtmGetErrorStatus(rtM));
      if (tmp) {
        msg = rtw_diagnostics_msg(diagnosticTree);
        rtmSetErrorStatus(rtM, msg);
      }
    }
  }

  if (rtmIsMajorTimeStep(rtM)) {
    NeslSimulationData *simulationData;
    real_T time;
    boolean_T tmp;
    real_T tmp_0[24];
    int_T tmp_1[7];
    NeuDiagnosticManager *diagnosticManager;
    NeuDiagnosticTree *diagnosticTree;
    int32_T tmp_2;
    char *msg;

    // Update for SimscapeExecutionBlock: '<S21>/STATE_1'
    simulationData = (NeslSimulationData *)rtDW.STATE_1_SimData;
    time = rtM->Timing.t[0];
    simulationData->mData->mTime.mN = 1;
    simulationData->mData->mTime.mX = &time;
    simulationData->mData->mContStates.mN = 44;
    simulationData->mData->mContStates.mX =
      &rtX.sh_water_supply_systemTank_Stat[0];
    simulationData->mData->mDiscStates.mN = 0;
    simulationData->mData->mDiscStates.mX = &rtDW.STATE_1_Discrete;
    simulationData->mData->mModeVector.mN = 0;
    simulationData->mData->mModeVector.mX = &rtDW.STATE_1_Modes;
    tmp = false;
    simulationData->mData->mFoundZcEvents = tmp;
    simulationData->mData->mIsMajorTimeStep = rtmIsMajorTimeStep(rtM);
    tmp = false;
    simulationData->mData->mIsSolverAssertCheck = tmp;
    simulationData->mData->mIsSolverCheckingCIC = false;
    tmp = rtsiIsSolverComputingJacobian(&rtM->solverInfo);
    simulationData->mData->mIsComputingJacobian = tmp;
    simulationData->mData->mIsEvaluatingF0 = false;
    simulationData->mData->mIsSolverRequestingReset = false;
    tmp_1[0] = 0;
    tmp_0[0] = rtDW.INPUT_2_1_1[0];
    tmp_0[1] = rtDW.INPUT_2_1_1[1];
    tmp_0[2] = rtDW.INPUT_2_1_1[2];
    tmp_0[3] = rtDW.INPUT_2_1_1[3];
    tmp_1[1] = 4;
    tmp_0[4] = rtDW.INPUT_1_1_1[0];
    tmp_0[5] = rtDW.INPUT_1_1_1[1];
    tmp_0[6] = rtDW.INPUT_1_1_1[2];
    tmp_0[7] = rtDW.INPUT_1_1_1[3];
    tmp_1[2] = 8;
    tmp_0[8] = rtDW.INPUT_4_1_1[0];
    tmp_0[9] = rtDW.INPUT_4_1_1[1];
    tmp_0[10] = rtDW.INPUT_4_1_1[2];
    tmp_0[11] = rtDW.INPUT_4_1_1[3];
    tmp_1[3] = 12;
    tmp_0[12] = rtDW.INPUT_3_1_1[0];
    tmp_0[13] = rtDW.INPUT_3_1_1[1];
    tmp_0[14] = rtDW.INPUT_3_1_1[2];
    tmp_0[15] = rtDW.INPUT_3_1_1[3];
    tmp_1[4] = 16;
    tmp_0[16] = rtDW.INPUT_6_1_1[0];
    tmp_0[17] = rtDW.INPUT_6_1_1[1];
    tmp_0[18] = rtDW.INPUT_6_1_1[2];
    tmp_0[19] = rtDW.INPUT_6_1_1[3];
    tmp_1[5] = 20;
    tmp_0[20] = rtDW.INPUT_5_1_1[0];
    tmp_0[21] = rtDW.INPUT_5_1_1[1];
    tmp_0[22] = rtDW.INPUT_5_1_1[2];
    tmp_0[23] = rtDW.INPUT_5_1_1[3];
    tmp_1[6] = 24;
    simulationData->mData->mInputValues.mN = 24;
    simulationData->mData->mInputValues.mX = &tmp_0[0];
    simulationData->mData->mInputOffsets.mN = 7;
    simulationData->mData->mInputOffsets.mX = &tmp_1[0];
    diagnosticManager = (NeuDiagnosticManager *)rtDW.STATE_1_DiagMgr;
    diagnosticTree = neu_diagnostic_manager_get_initial_tree(diagnosticManager);
    tmp_2 = ne_simulator_method((NeslSimulator *)rtDW.STATE_1_Simulator,
      NESL_SIM_UPDATE, simulationData, diagnosticManager);
    if (tmp_2 != 0) {
      tmp = error_buffer_is_empty(rtmGetErrorStatus(rtM));
      if (tmp) {
        msg = rtw_diagnostics_msg(diagnosticTree);
        rtmSetErrorStatus(rtM, msg);
      }
    }

    // End of Update for SimscapeExecutionBlock: '<S21>/STATE_1'
  }                                    // end MajorTimeStep

  if (rtmIsMajorTimeStep(rtM)) {
    rt_ertODEUpdateContinuousStates(&rtM->solverInfo);

    // Update absolute time for base rate
    // The "clockTick0" counts the number of times the code of this task has
    //  been executed. The absolute time is the multiplication of "clockTick0"
    //  and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
    //  overflow during the application lifespan selected.

    ++rtM->Timing.clockTick0;
    rtM->Timing.t[0] = rtsiGetSolverStopTime(&rtM->solverInfo);

    {
      // Update absolute timer for sample time: [4.0s, 0.0s]
      // The "clockTick1" counts the number of times the code of this task has
      //  been executed. The resolution of this integer timer is 4.0, which is the step size
      //  of the task. Size of "clockTick1" ensures timer will not overflow during the
      //  application lifespan selected.

      rtM->Timing.clockTick1++;
    }
  }                                    // end MajorTimeStep
}

// Derivatives for root system: '<Root>'
void sh_water_supply_system_derivatives(void)
{
  NeslSimulationData *simulationData;
  real_T time;
  boolean_T tmp;
  real_T tmp_0[24];
  int_T tmp_1[7];
  NeuDiagnosticManager *diagnosticManager;
  NeuDiagnosticTree *diagnosticTree;
  int32_T tmp_2;
  char *msg;
  XDot *_rtXdot;
  _rtXdot = ((XDot *) rtM->derivs);

  // Derivatives for SimscapeExecutionBlock: '<S21>/STATE_1'
  simulationData = (NeslSimulationData *)rtDW.STATE_1_SimData;
  time = rtM->Timing.t[0];
  simulationData->mData->mTime.mN = 1;
  simulationData->mData->mTime.mX = &time;
  simulationData->mData->mContStates.mN = 44;
  simulationData->mData->mContStates.mX = &rtX.sh_water_supply_systemTank_Stat[0];
  simulationData->mData->mDiscStates.mN = 0;
  simulationData->mData->mDiscStates.mX = &rtDW.STATE_1_Discrete;
  simulationData->mData->mModeVector.mN = 0;
  simulationData->mData->mModeVector.mX = &rtDW.STATE_1_Modes;
  tmp = false;
  simulationData->mData->mFoundZcEvents = tmp;
  simulationData->mData->mIsMajorTimeStep = rtmIsMajorTimeStep(rtM);
  tmp = false;
  simulationData->mData->mIsSolverAssertCheck = tmp;
  simulationData->mData->mIsSolverCheckingCIC = false;
  tmp = rtsiIsSolverComputingJacobian(&rtM->solverInfo);
  simulationData->mData->mIsComputingJacobian = tmp;
  simulationData->mData->mIsEvaluatingF0 = false;
  simulationData->mData->mIsSolverRequestingReset = false;
  tmp_1[0] = 0;
  tmp_0[0] = rtDW.INPUT_2_1_1[0];
  tmp_0[1] = rtDW.INPUT_2_1_1[1];
  tmp_0[2] = rtDW.INPUT_2_1_1[2];
  tmp_0[3] = rtDW.INPUT_2_1_1[3];
  tmp_1[1] = 4;
  tmp_0[4] = rtDW.INPUT_1_1_1[0];
  tmp_0[5] = rtDW.INPUT_1_1_1[1];
  tmp_0[6] = rtDW.INPUT_1_1_1[2];
  tmp_0[7] = rtDW.INPUT_1_1_1[3];
  tmp_1[2] = 8;
  tmp_0[8] = rtDW.INPUT_4_1_1[0];
  tmp_0[9] = rtDW.INPUT_4_1_1[1];
  tmp_0[10] = rtDW.INPUT_4_1_1[2];
  tmp_0[11] = rtDW.INPUT_4_1_1[3];
  tmp_1[3] = 12;
  tmp_0[12] = rtDW.INPUT_3_1_1[0];
  tmp_0[13] = rtDW.INPUT_3_1_1[1];
  tmp_0[14] = rtDW.INPUT_3_1_1[2];
  tmp_0[15] = rtDW.INPUT_3_1_1[3];
  tmp_1[4] = 16;
  tmp_0[16] = rtDW.INPUT_6_1_1[0];
  tmp_0[17] = rtDW.INPUT_6_1_1[1];
  tmp_0[18] = rtDW.INPUT_6_1_1[2];
  tmp_0[19] = rtDW.INPUT_6_1_1[3];
  tmp_1[5] = 20;
  tmp_0[20] = rtDW.INPUT_5_1_1[0];
  tmp_0[21] = rtDW.INPUT_5_1_1[1];
  tmp_0[22] = rtDW.INPUT_5_1_1[2];
  tmp_0[23] = rtDW.INPUT_5_1_1[3];
  tmp_1[6] = 24;
  simulationData->mData->mInputValues.mN = 24;
  simulationData->mData->mInputValues.mX = &tmp_0[0];
  simulationData->mData->mInputOffsets.mN = 7;
  simulationData->mData->mInputOffsets.mX = &tmp_1[0];
  simulationData->mData->mDx.mN = 44;
  simulationData->mData->mDx.mX = &_rtXdot->sh_water_supply_systemTank_Stat[0];
  diagnosticManager = (NeuDiagnosticManager *)rtDW.STATE_1_DiagMgr;
  diagnosticTree = neu_diagnostic_manager_get_initial_tree(diagnosticManager);
  tmp_2 = ne_simulator_method((NeslSimulator *)rtDW.STATE_1_Simulator,
    NESL_SIM_DERIVATIVES, simulationData, diagnosticManager);
  if (tmp_2 != 0) {
    tmp = error_buffer_is_empty(rtmGetErrorStatus(rtM));
    if (tmp) {
      msg = rtw_diagnostics_msg(diagnosticTree);
      rtmSetErrorStatus(rtM, msg);
    }
  }

  // End of Derivatives for SimscapeExecutionBlock: '<S21>/STATE_1'
}

// Model initialize function
void sh_water_supply_system_initialize(void)
{
  // Registration code
  {
    // Setup solver object
    rtsiSetSimTimeStepPtr(&rtM->solverInfo, &rtM->Timing.simTimeStep);
    rtsiSetTPtr(&rtM->solverInfo, &rtmGetTPtr(rtM));
    rtsiSetStepSizePtr(&rtM->solverInfo, &rtM->Timing.stepSize0);
    rtsiSetdXPtr(&rtM->solverInfo, &rtM->derivs);
    rtsiSetContStatesPtr(&rtM->solverInfo, (real_T **) &rtM->contStates);
    rtsiSetNumContStatesPtr(&rtM->solverInfo, &rtM->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&rtM->solverInfo,
      &rtM->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&rtM->solverInfo,
      &rtM->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&rtM->solverInfo,
      &rtM->periodicContStateRanges);
    rtsiSetErrorStatusPtr(&rtM->solverInfo, (&rtmGetErrorStatus(rtM)));
    rtsiSetSolverMassMatrixIr(&rtM->solverInfo, rtMassMatrix.ir);
    rtsiSetSolverMassMatrixJc(&rtM->solverInfo, rtMassMatrix.jc);
    rtsiSetSolverMassMatrixPr(&rtM->solverInfo, rtMassMatrix.pr);
    rtsiSetRTModelPtr(&rtM->solverInfo, rtM);
  }

  rtsiSetSimTimeStep(&rtM->solverInfo, MAJOR_TIME_STEP);
  rtM->intgData.x0 = rtM->odeX0;
  rtM->intgData.f0 = rtM->odeF0;
  rtM->intgData.x1start = rtM->odeX1START;
  rtM->intgData.f1 = rtM->odeF1;
  rtM->intgData.Delta = rtM->odeDELTA;
  rtM->intgData.E = rtM->odeE;
  rtM->intgData.fac = rtM->odeFAC;

  // initialize
  {
    int_T i;
    real_T *f = rtM->intgData.fac;
    for (i = 0; i < (int_T)(sizeof(rtM->odeFAC)/sizeof(real_T)); i++) {
      f[i] = 1.5e-8;
    }
  }

  rtM->intgData.DFDX = rtM->odeDFDX;
  rtM->intgData.W = rtM->odeW;
  rtM->intgData.pivots = rtM->odePIVOTS;
  rtM->intgData.xtmp = rtM->odeXTMP;
  rtM->intgData.ztmp = rtM->odeZTMP;
  rtM->intgData.M = rtM->odeMASSMATRIX_M;
  rtM->intgData.isFirstStep = true;
  rtsiSetSolverExtrapolationOrder(&rtM->solverInfo, 4);
  rtsiSetSolverNumberNewtonIterations(&rtM->solverInfo, 1);
  rtM->contStates = ((X *) &rtX);
  rtM->massMatrixType = ((ssMatrixType)1);
  rtM->massMatrixNzMax = (4);
  rtM->massMatrixIr = (rtMassMatrix.ir);
  rtM->massMatrixJc = (rtMassMatrix.jc);
  rtM->massMatrixPr = (rtMassMatrix.pr);
  rtsiSetSolverMassMatrixType(&rtM->solverInfo, (ssMatrixType)1);
  rtsiSetSolverMassMatrixNzMax(&rtM->solverInfo, 4);
  rtsiSetSolverData(&rtM->solverInfo, (void *)&rtM->intgData);
  rtsiSetSolverName(&rtM->solverInfo,"ode14x");
  rtmSetTPtr(rtM, &rtM->Timing.tArray[0]);
  rtM->Timing.stepSize0 = 4.0;

  // Root-level init GlobalMassMatrixPr offset
  {
    rtDW.STATE_1_MASS_MATRIX_PR = 0;   // '<S21>/STATE_1'
  }

  {
    NeslSimulator *tmp;
    boolean_T tmp_0;
    NeuDiagnosticManager *diagnosticManager;
    NeModelParameters modelParameters;
    real_T tmp_1;
    NeuDiagnosticTree *diagnosticTree;
    int32_T tmp_2;
    char *msg;
    NeslSimulationData *simulationData;
    real_T time;
    NeModelParameters modelParameters_0;
    real_T time_0;
    NeParameterBundle expl_temp;
    real_T time_tmp;
    boolean_T tmp_3;

    // Start for SimscapeExecutionBlock: '<S21>/STATE_1' incorporates:
    //   SimscapeExecutionBlock: '<S21>/OUTPUT_1_0'

    tmp = nesl_lease_simulator("sh_water_supply_system/Solver Configuration_1",
      0, 0);
    rtDW.STATE_1_Simulator = (void *)tmp;
    tmp_0 = pointer_is_null(rtDW.STATE_1_Simulator);
    if (tmp_0) {
      sh_water_supply_system_900c0b92_1_gateway();
      tmp = nesl_lease_simulator("sh_water_supply_system/Solver Configuration_1",
        0, 0);
      rtDW.STATE_1_Simulator = (void *)tmp;
    }

    simulationData = nesl_create_simulation_data();
    rtDW.STATE_1_SimData = (void *)simulationData;
    diagnosticManager = rtw_create_diagnostics();
    rtDW.STATE_1_DiagMgr = (void *)diagnosticManager;
    modelParameters.mSolverType = NE_SOLVER_TYPE_DAE;
    modelParameters.mSolverTolerance = 0.001;
    modelParameters.mVariableStepSolver = false;
    modelParameters.mFixedStepSize = 0.001;
    modelParameters.mStartTime = 0.0;
    modelParameters.mLoadInitialState = false;
    modelParameters.mUseSimState = false;
    modelParameters.mLinTrimCompile = false;
    modelParameters.mLoggingMode = SSC_LOGGING_ALL;
    modelParameters.mRTWModifiedTimeStamp = 4.95225209E+8;
    tmp_1 = 0.001;
    modelParameters.mSolverTolerance = tmp_1;
    tmp_1 = 4.0;
    modelParameters.mFixedStepSize = tmp_1;
    tmp_0 = false;
    modelParameters.mVariableStepSolver = tmp_0;
    diagnosticManager = (NeuDiagnosticManager *)rtDW.STATE_1_DiagMgr;
    diagnosticTree = neu_diagnostic_manager_get_initial_tree(diagnosticManager);
    tmp_2 = nesl_initialize_simulator((NeslSimulator *)rtDW.STATE_1_Simulator,
      &modelParameters, diagnosticManager);
    if (tmp_2 != 0) {
      tmp_0 = error_buffer_is_empty(rtmGetErrorStatus(rtM));
      if (tmp_0) {
        msg = rtw_diagnostics_msg(diagnosticTree);
        rtmSetErrorStatus(rtM, msg);
      }
    }

    expl_temp.mRealParameters.mN = 0;
    expl_temp.mRealParameters.mX = NULL;
    expl_temp.mLogicalParameters.mN = 0;
    expl_temp.mLogicalParameters.mX = NULL;
    expl_temp.mIntegerParameters.mN = 0;
    expl_temp.mIntegerParameters.mX = NULL;
    expl_temp.mIndexParameters.mN = 0;
    expl_temp.mIndexParameters.mX = NULL;
    nesl_simulator_set_rtps((NeslSimulator *)rtDW.STATE_1_Simulator, expl_temp);
    simulationData = (NeslSimulationData *)rtDW.STATE_1_SimData;
    time_tmp = rtM->Timing.t[0];
    time = time_tmp;
    simulationData->mData->mTime.mN = 1;
    simulationData->mData->mTime.mX = &time;
    simulationData->mData->mContStates.mN = 44;
    simulationData->mData->mContStates.mX =
      &rtX.sh_water_supply_systemTank_Stat[0];
    simulationData->mData->mDiscStates.mN = 0;
    simulationData->mData->mDiscStates.mX = &rtDW.STATE_1_Discrete;
    simulationData->mData->mModeVector.mN = 0;
    simulationData->mData->mModeVector.mX = &rtDW.STATE_1_Modes;
    tmp_0 = false;
    simulationData->mData->mFoundZcEvents = tmp_0;
    tmp_3 = rtmIsMajorTimeStep(rtM);
    simulationData->mData->mIsMajorTimeStep = tmp_3;
    tmp_0 = false;
    simulationData->mData->mIsSolverAssertCheck = tmp_0;
    simulationData->mData->mIsSolverCheckingCIC = false;
    tmp_0 = rtsiIsSolverComputingJacobian(&rtM->solverInfo);
    simulationData->mData->mIsComputingJacobian = tmp_0;
    simulationData->mData->mIsEvaluatingF0 = false;
    simulationData->mData->mIsSolverRequestingReset = false;
    diagnosticManager = (NeuDiagnosticManager *)rtDW.STATE_1_DiagMgr;
    diagnosticTree = neu_diagnostic_manager_get_initial_tree(diagnosticManager);
    tmp_2 = ne_simulator_method((NeslSimulator *)rtDW.STATE_1_Simulator,
      NESL_SIM_INITIALIZEONCE, simulationData, diagnosticManager);
    if (tmp_2 != 0) {
      tmp_0 = error_buffer_is_empty(rtmGetErrorStatus(rtM));
      if (tmp_0) {
        msg = rtw_diagnostics_msg(diagnosticTree);
        rtmSetErrorStatus(rtM, msg);
      }
    }

    // End of Start for SimscapeExecutionBlock: '<S21>/STATE_1'

    // Start for SimscapeExecutionBlock: '<S21>/OUTPUT_1_0'
    tmp = nesl_lease_simulator("sh_water_supply_system/Solver Configuration_1",
      1, 0);
    rtDW.OUTPUT_1_0_Simulator = (void *)tmp;
    tmp_0 = pointer_is_null(rtDW.OUTPUT_1_0_Simulator);
    if (tmp_0) {
      sh_water_supply_system_900c0b92_1_gateway();
      tmp = nesl_lease_simulator("sh_water_supply_system/Solver Configuration_1",
        1, 0);
      rtDW.OUTPUT_1_0_Simulator = (void *)tmp;
    }

    simulationData = nesl_create_simulation_data();
    rtDW.OUTPUT_1_0_SimData = (void *)simulationData;
    diagnosticManager = rtw_create_diagnostics();
    rtDW.OUTPUT_1_0_DiagMgr = (void *)diagnosticManager;
    modelParameters_0.mSolverType = NE_SOLVER_TYPE_DAE;
    modelParameters_0.mSolverTolerance = 0.001;
    modelParameters_0.mVariableStepSolver = false;
    modelParameters_0.mFixedStepSize = 0.001;
    modelParameters_0.mStartTime = 0.0;
    modelParameters_0.mLoadInitialState = false;
    modelParameters_0.mUseSimState = false;
    modelParameters_0.mLinTrimCompile = false;
    modelParameters_0.mLoggingMode = SSC_LOGGING_ALL;
    modelParameters_0.mRTWModifiedTimeStamp = 4.95225209E+8;
    tmp_1 = 0.001;
    modelParameters_0.mSolverTolerance = tmp_1;
    tmp_1 = 4.0;
    modelParameters_0.mFixedStepSize = tmp_1;
    tmp_0 = false;
    modelParameters_0.mVariableStepSolver = tmp_0;
    diagnosticManager = (NeuDiagnosticManager *)rtDW.OUTPUT_1_0_DiagMgr;
    diagnosticTree = neu_diagnostic_manager_get_initial_tree(diagnosticManager);
    tmp_2 = nesl_initialize_simulator((NeslSimulator *)rtDW.OUTPUT_1_0_Simulator,
      &modelParameters_0, diagnosticManager);
    if (tmp_2 != 0) {
      tmp_0 = error_buffer_is_empty(rtmGetErrorStatus(rtM));
      if (tmp_0) {
        msg = rtw_diagnostics_msg(diagnosticTree);
        rtmSetErrorStatus(rtM, msg);
      }
    }

    simulationData = (NeslSimulationData *)rtDW.OUTPUT_1_0_SimData;
    time_0 = time_tmp;
    simulationData->mData->mTime.mN = 1;
    simulationData->mData->mTime.mX = &time_0;
    simulationData->mData->mContStates.mN = 0;
    simulationData->mData->mContStates.mX = NULL;
    simulationData->mData->mDiscStates.mN = 0;
    simulationData->mData->mDiscStates.mX = &rtDW.OUTPUT_1_0_Discrete;
    simulationData->mData->mModeVector.mN = 0;
    simulationData->mData->mModeVector.mX = &rtDW.OUTPUT_1_0_Modes;
    tmp_0 = false;
    simulationData->mData->mFoundZcEvents = tmp_0;
    simulationData->mData->mIsMajorTimeStep = tmp_3;
    tmp_0 = false;
    simulationData->mData->mIsSolverAssertCheck = tmp_0;
    simulationData->mData->mIsSolverCheckingCIC = false;
    simulationData->mData->mIsComputingJacobian = false;
    simulationData->mData->mIsEvaluatingF0 = false;
    simulationData->mData->mIsSolverRequestingReset = false;
    diagnosticManager = (NeuDiagnosticManager *)rtDW.OUTPUT_1_0_DiagMgr;
    diagnosticTree = neu_diagnostic_manager_get_initial_tree(diagnosticManager);
    tmp_2 = ne_simulator_method((NeslSimulator *)rtDW.OUTPUT_1_0_Simulator,
      NESL_SIM_INITIALIZEONCE, simulationData, diagnosticManager);
    if (tmp_2 != 0) {
      tmp_0 = error_buffer_is_empty(rtmGetErrorStatus(rtM));
      if (tmp_0) {
        msg = rtw_diagnostics_msg(diagnosticTree);
        rtmSetErrorStatus(rtM, msg);
      }
    }

    // InitializeConditions for SimscapeExecutionBlock: '<S21>/STATE_1'
    tmp_0 = false;
    if (tmp_0) {
      tmp_2 = strcmp("ode14x", rtsiGetSolverName(&rtM->solverInfo));
      if (tmp_2 != 0) {
        msg = solver_mismatch_message("ode14x", rtsiGetSolverName
          (&rtM->solverInfo));
        rtmSetErrorStatus(rtM, msg);
      }
    }

    // End of InitializeConditions for SimscapeExecutionBlock: '<S21>/STATE_1'

    // Root-level InitSystemMatrices
    {
      static int_T modelMassMatrixIr[4] = { 0, 1, 2, 3 };

      static int_T modelMassMatrixJc[45] = { 0, 1, 2, 3, 4, 4, 4, 4, 4, 4, 4, 4,
        4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
        4, 4, 4, 4, 4, 4, 4, 4, 4 };

      static real_T modelMassMatrixPr[4] = { 1.0, 1.0, 1.0, 1.0 };

      (void) memcpy(rtMassMatrix.ir, modelMassMatrixIr,
                    4*sizeof(int_T));
      (void) memcpy(rtMassMatrix.jc, modelMassMatrixJc,
                    45*sizeof(int_T));
      (void) memcpy(rtMassMatrix.pr, modelMassMatrixPr,
                    4*sizeof(real_T));
    }
  }
}

//
// File trailer for generated code.
//
// [EOF]
//
