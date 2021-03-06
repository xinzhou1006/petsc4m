#include "petscSolveCRS.h"
#include "m2c.h"
#include "petsc4m.h"
#include "mpi.h"

static void b_m2c_error(void);
static void b_m2c_printf(double varargin_2, int varargin_3);
static void b_petscKSPDriver(KSP ksp, Vec b, Vec x, double rtol, int maxits, Vec
  x0, int *flag, double *relres, int *iter, emxArray_real_T *reshis, double
  *time);
static void b_petscKSPSetup(Mat Amat, const emxArray_char_T *ksptype, const
  emxArray_char_T *pctype, const emxArray_char_T *pcopt, KSP *ksp, double *time);
static void c_m2c_error(int varargin_3);
static void c_m2c_printf(double varargin_2, double varargin_3);
static void d_m2c_printf(int varargin_2, double varargin_3);
static void e_m2c_printf(void);
static void m2c_error(void);
static void m2c_printf(KSPType varargin_2, PCType varargin_3, const
  emxArray_char_T *varargin_4, int varargin_5);
static void petscKSPDriver(KSP ksp, Vec b, Vec x, Vec x0, int *flag, double
  *relres, int *iter, emxArray_real_T *reshis, double *time);
static void petscKSPSetup(Mat Amat, const emxArray_char_T *ksptype, KSP *ksp,
  double *time);
static Mat petscMatCreateAIJFromCRS(const emxArray_int32_T *row_ptr, const
  emxArray_int32_T *col_ind, const emxArray_real_T *val);
static void petscSolveHdls(Mat A, Vec b, Vec x, const emxArray_char_T *solver,
  double rtol, int maxit, const emxArray_char_T *pctype, const emxArray_char_T
  *pcopt, Vec x0, int *flag, double *relres, int *iter, emxArray_real_T *reshis,
  double times[2]);
static Vec petscVecCreateFromArray(const emxArray_real_T *arr);
static void petscVecToArray(Vec vec, emxArray_real_T *arr);
static void b_m2c_error(void)
{
  M2C_error("Petsc4m:petscOptionsInsertString:InputError",
            "The argument must be a null-terminated string.");
}

static void b_m2c_printf(double varargin_2, int varargin_3)
{
  M2C_printf("### The relative residual was %g after %d iterations.\n",
             varargin_2, varargin_3);
}

static void b_petscKSPDriver(KSP ksp, Vec b, Vec x, double rtol, int maxits, Vec
  x0, int *flag, double *relres, int *iter, emxArray_real_T *reshis, double
  *time)
{
  int val;
  double bnrm;
  PetscObject t_obj;
  MPI_Comm t_comm;
  double t;
  int b_val;
  boolean_T b2;
  double secs;
  double res;
  double b_rtol;
  double abstol;
  double dtol;
  int b_maxits;
  emxArray_char_T *side;
  PC t_pc;
  PetscReal * a;
  int na;
  int b_side;
  static const char cv6[9] = { 's', 'y', 'm', 'm', 'e', 't', 'r', 'i', 'c' };

  static const char cv7[4] = { 'l', 'e', 'f', 't' };

  static const char cv8[5] = { 'r', 'i', 'g', 'h', 't' };

  KSPType t_type;
  PCType b_t_type;
  val = (NORM_2);
  VecNorm(b, val, &bnrm);
  t_obj = (PetscObject)(ksp);
  PetscObjectGetComm(t_obj, &t_comm);
  MPI_Barrier(t_comm);
  t = MPI_Wtime();
  if (maxits == 0) {
    maxits = (PETSC_DEFAULT);
  }

  if (rtol == 0.0) {
    val = (PETSC_DEFAULT);
    rtol = val;
  }

  val = (PETSC_DEFAULT);
  b_val = (PETSC_DEFAULT);
  KSPSetTolerances(ksp, rtol, (double)val, (double)b_val, maxits);
  val = !(x0);
  b2 = !(val != 0);
  if (b2) {
    VecCopy(x0, x);
  }

  val = (PETSC_TRUE);
  KSPSetResidualHistory(ksp, NULL, maxits, val);
  KSPSetInitialGuessNonzero(ksp, (int)b2);
  KSPSolve(ksp, b, x);
  MPI_Barrier(t_comm);
  secs = MPI_Wtime();
  KSPGetConvergedReason(ksp, flag);
  KSPGetResidualNorm(ksp, &res);
  KSPGetIterationNumber(ksp, iter);
  *relres = res / bnrm;
  KSPGetTolerances(ksp, &b_rtol, &abstol, &dtol, &b_maxits);
  emxInit_char_T(&side, 2);
  if ((*flag < 0) || (*relres > b_rtol)) {
    KSPGetPC(ksp, &t_pc);
    KSPGetPCSide(ksp, &b_side);
    val = (PC_LEFT);
    b_val = (PC_RIGHT);
    if (val == b_side) {
      val = 0;
    } else if (b_val == b_side) {
      val = 1;
    } else {
      val = -1;
    }

    switch (val) {
     case 0:
      val = side->size[0] * side->size[1];
      side->size[0] = 1;
      side->size[1] = 4;
      emxEnsureCapacity((emxArray__common *)side, val, sizeof(char));
      for (val = 0; val < 4; val++) {
        side->data[val] = cv7[val];
      }
      break;

     case 1:
      val = side->size[0] * side->size[1];
      side->size[0] = 1;
      side->size[1] = 5;
      emxEnsureCapacity((emxArray__common *)side, val, sizeof(char));
      for (val = 0; val < 5; val++) {
        side->data[val] = cv8[val];
      }
      break;

     default:
      val = side->size[0] * side->size[1];
      side->size[0] = 1;
      side->size[1] = 9;
      emxEnsureCapacity((emxArray__common *)side, val, sizeof(char));
      for (val = 0; val < 9; val++) {
        side->data[val] = cv6[val];
      }
      break;
    }

    KSPGetType(ksp, &t_type);
    PCGetType(t_pc, &b_t_type);
    m2c_printf(t_type, b_t_type, side, *flag);
    b_m2c_printf(*relres, *iter);
    c_m2c_printf(b_rtol, abstol);
    d_m2c_printf(b_maxits, dtol);
    e_m2c_printf();
  }

  emxFree_char_T(&side);
  KSPGetResidualHistory(ksp, &a, &na);
  val = reshis->size[0];
  reshis->size[0] = na;
  emxEnsureCapacity((emxArray__common *)reshis, val, sizeof(double));
  for (val = 0; val < na; val++) {
    reshis->data[val] = 0.0;
  }

  memcpy(&reshis->data[0], a, na << 3);
  *time = secs - t;
}

static void b_petscKSPSetup(Mat Amat, const emxArray_char_T *ksptype, const
  emxArray_char_T *pctype, const emxArray_char_T *pcopt, KSP *ksp, double *time)
{
  PetscObject t_obj;
  MPI_Comm t_comm;
  KSP t_ksp;
  double t;
  boolean_T hasPC;
  boolean_T hasOpt;
  emxArray_char_T *pctype0;
  emxArray_char_T *pcopt0;
  PC t_pc;
  emxArray_char_T *ksptype0;
  int k;
  boolean_T p;
  boolean_T b_p;
  int loop_ub;
  boolean_T exitg1;
  static const char cv9[4] = { 'l', 'e', 'f', 't' };

  static const char cv10[5] = { 'r', 'i', 'g', 'h', 't' };

  double secs;
  static const char cv11[9] = { 's', 'y', 'm', 'm', 'e', 't', 'r', 'i', 'c' };

  t_obj = (PetscObject)(Amat);
  PetscObjectGetComm(t_obj, &t_comm);
  KSPCreate(t_comm, &t_ksp);
  *ksp = t_ksp;
  t_obj = (PetscObject)(t_ksp);
  PetscObjectGetComm(t_obj, &t_comm);
  MPI_Barrier(t_comm);
  t = MPI_Wtime();
  KSPSetOperators(t_ksp, Amat, Amat);
  hasPC = !(pctype->size[1] == 0);
  hasOpt = !(pcopt->size[1] == 0);
  emxInit_char_T(&pctype0, 2);
  emxInit_char_T(&pcopt0, 2);
  if (hasPC || hasOpt) {
    KSPGetPC(t_ksp, &t_pc);
    if (hasPC) {
      if (pctype->data[pctype->size[1] - 1] != '\x00') {
        k = pctype0->size[0] * pctype0->size[1];
        pctype0->size[0] = 1;
        pctype0->size[1] = pctype->size[1] + 1;
        emxEnsureCapacity((emxArray__common *)pctype0, k, sizeof(char));
        loop_ub = pctype->size[1];
        for (k = 0; k < loop_ub; k++) {
          pctype0->data[pctype0->size[0] * k] = pctype->data[pctype->size[0] * k];
        }

        pctype0->data[pctype0->size[0] * pctype->size[1]] = '\x00';
      } else {
        k = pctype0->size[0] * pctype0->size[1];
        pctype0->size[0] = 1;
        pctype0->size[1] = pctype->size[1];
        emxEnsureCapacity((emxArray__common *)pctype0, k, sizeof(char));
        loop_ub = pctype->size[0] * pctype->size[1];
        for (k = 0; k < loop_ub; k++) {
          pctype0->data[k] = pctype->data[k];
        }
      }

      PCSetType(t_pc, &pctype0->data[0]);
    }

    if (hasOpt) {
      p = false;
      b_p = false;
      if (pcopt->size[1] == 4) {
        b_p = true;
      }

      if (b_p && (!(pcopt->size[1] == 0))) {
        k = 0;
        exitg1 = false;
        while ((!exitg1) && (k < 4)) {
          if (!(pcopt->data[k] == cv9[k])) {
            b_p = false;
            exitg1 = true;
          } else {
            k++;
          }
        }
      }

      if (b_p) {
        p = true;
      }

      if (p) {
        k = (PC_LEFT);
        KSPSetPCSide(t_ksp, k);
      } else {
        p = false;
        b_p = false;
        if (pcopt->size[1] == 5) {
          b_p = true;
        }

        if (b_p && (!(pcopt->size[1] == 0))) {
          k = 0;
          exitg1 = false;
          while ((!exitg1) && (k < 5)) {
            if (!(pcopt->data[k] == cv10[k])) {
              b_p = false;
              exitg1 = true;
            } else {
              k++;
            }
          }
        }

        if (b_p) {
          p = true;
        }

        if (p) {
          k = (PC_RIGHT);
          KSPSetPCSide(t_ksp, k);
        } else {
          p = false;
          b_p = false;
          if (pcopt->size[1] == 9) {
            b_p = true;
          }

          if (b_p && (!(pcopt->size[1] == 0))) {
            k = 0;
            exitg1 = false;
            while ((!exitg1) && (k < 9)) {
              if (!(pcopt->data[k] == cv11[k])) {
                b_p = false;
                exitg1 = true;
              } else {
                k++;
              }
            }
          }

          if (b_p) {
            p = true;
          }

          if (p) {
            k = (PC_SYMMETRIC);
            KSPSetPCSide(t_ksp, k);
          } else {
            if (pcopt->data[pcopt->size[1] - 1] != '\x00') {
              k = pcopt0->size[0] * pcopt0->size[1];
              pcopt0->size[0] = 1;
              pcopt0->size[1] = pcopt->size[1] + 1;
              emxEnsureCapacity((emxArray__common *)pcopt0, k, sizeof(char));
              loop_ub = pcopt->size[1];
              for (k = 0; k < loop_ub; k++) {
                pcopt0->data[pcopt0->size[0] * k] = pcopt->data[pcopt->size[0] *
                  k];
              }

              pcopt0->data[pcopt0->size[0] * pcopt->size[1]] = '\x00';
            } else {
              k = pcopt0->size[0] * pcopt0->size[1];
              pcopt0->size[0] = 1;
              pcopt0->size[1] = pcopt->size[1];
              emxEnsureCapacity((emxArray__common *)pcopt0, k, sizeof(char));
              loop_ub = pcopt->size[0] * pcopt->size[1];
              for (k = 0; k < loop_ub; k++) {
                pcopt0->data[k] = pcopt->data[k];
              }
            }

            PCFactorSetMatSolverPackage(t_pc, &pcopt0->data[0]);
          }
        }
      }
    }
  }

  emxFree_char_T(&pcopt0);
  emxFree_char_T(&pctype0);
  emxInit_char_T(&ksptype0, 2);
  if ((!(ksptype->size[1] == 0)) && ((unsigned char)ksptype->data[ksptype->size
       [1] - 1] != 0)) {
    k = ksptype0->size[0] * ksptype0->size[1];
    ksptype0->size[0] = 1;
    ksptype0->size[1] = ksptype->size[1] + 1;
    emxEnsureCapacity((emxArray__common *)ksptype0, k, sizeof(char));
    loop_ub = ksptype->size[1];
    for (k = 0; k < loop_ub; k++) {
      ksptype0->data[ksptype0->size[0] * k] = ksptype->data[ksptype->size[0] * k];
    }

    ksptype0->data[ksptype0->size[0] * ksptype->size[1]] = '\x00';
  } else {
    k = ksptype0->size[0] * ksptype0->size[1];
    ksptype0->size[0] = 1;
    ksptype0->size[1] = ksptype->size[1];
    emxEnsureCapacity((emxArray__common *)ksptype0, k, sizeof(char));
    loop_ub = ksptype->size[0] * ksptype->size[1];
    for (k = 0; k < loop_ub; k++) {
      ksptype0->data[k] = ksptype->data[k];
    }
  }

  if (!(ksptype0->size[1] == 0)) {
    KSPSetType(t_ksp, &ksptype0->data[0]);
  }

  emxFree_char_T(&ksptype0);
  if (pcopt->size[1] == 0) {
    k = (PC_RIGHT);
    KSPSetPCSide(t_ksp, k);
  }

  KSPSetFromOptions(t_ksp);
  KSPSetUp(t_ksp);
  MPI_Barrier(t_comm);
  secs = MPI_Wtime();
  *time = secs - t;
}

static void c_m2c_error(int varargin_3)
{
  M2C_error("petsc:RuntimeError",
            "PetscOptionsInsertString returned error code %d\n", varargin_3);
}

static void c_m2c_printf(double varargin_2, double varargin_3)
{
  M2C_printf("### The relative and absolute tolerances were %g and %g.\n",
             varargin_2, varargin_3);
}

static void d_m2c_printf(int varargin_2, double varargin_3)
{
  M2C_printf("### The divergence and max-iter tolerances were %d and %g.\n",
             varargin_2, varargin_3);
}

static void e_m2c_printf(void)
{
  M2C_printf("### For explanation of the flag, see http://www.mcs.anl.gov/petsc/petsc-current/docs/manualpages/KSP/KSPConvergedReason.html.\n");
}

static void m2c_error(void)
{
  M2C_error("runtime:Error", "Output array y is too small.");
}

static void m2c_printf(KSPType varargin_2, PCType varargin_3, const
  emxArray_char_T *varargin_4, int varargin_5)
{
  emxArray_char_T *b_varargin_4;
  int i2;
  int loop_ub;
  emxInit_char_T(&b_varargin_4, 2);
  i2 = b_varargin_4->size[0] * b_varargin_4->size[1];
  b_varargin_4->size[0] = 1;
  b_varargin_4->size[1] = varargin_4->size[1];
  emxEnsureCapacity((emxArray__common *)b_varargin_4, i2, sizeof(char));
  loop_ub = varargin_4->size[0] * varargin_4->size[1];
  for (i2 = 0; i2 < loop_ub; i2++) {
    b_varargin_4->data[i2] = varargin_4->data[i2];
  }

  M2C_printf("### %s with %s as %s preconditioner stopped with flag %d.\n",
             varargin_2, varargin_3, &b_varargin_4->data[0], varargin_5);
  emxFree_char_T(&b_varargin_4);
}

static void petscKSPDriver(KSP ksp, Vec b, Vec x, Vec x0, int *flag, double
  *relres, int *iter, emxArray_real_T *reshis, double *time)
{
  int val;
  double bnrm;
  PetscObject t_obj;
  MPI_Comm t_comm;
  double t;
  int maxits;
  int b_val;
  int c_val;
  boolean_T b0;
  double secs;
  double res;
  double rtol;
  double abstol;
  double dtol;
  emxArray_char_T *side;
  PC t_pc;
  PetscReal * a;
  int na;
  static const char cv0[9] = { 's', 'y', 'm', 'm', 'e', 't', 'r', 'i', 'c' };

  static const char cv1[4] = { 'l', 'e', 'f', 't' };

  static const char cv2[5] = { 'r', 'i', 'g', 'h', 't' };

  KSPType t_type;
  PCType b_t_type;
  val = (NORM_2);
  VecNorm(b, val, &bnrm);
  t_obj = (PetscObject)(ksp);
  PetscObjectGetComm(t_obj, &t_comm);
  MPI_Barrier(t_comm);
  t = MPI_Wtime();
  maxits = (PETSC_DEFAULT);
  val = (PETSC_DEFAULT);
  b_val = (PETSC_DEFAULT);
  c_val = (PETSC_DEFAULT);
  KSPSetTolerances(ksp, (double)val, (double)b_val, (double)c_val, maxits);
  c_val = !(x0);
  b0 = !(c_val != 0);
  if (b0) {
    VecCopy(x0, x);
  }

  val = (PETSC_TRUE);
  KSPSetResidualHistory(ksp, NULL, maxits, val);
  KSPSetInitialGuessNonzero(ksp, (int)b0);
  KSPSolve(ksp, b, x);
  MPI_Barrier(t_comm);
  secs = MPI_Wtime();
  KSPGetConvergedReason(ksp, flag);
  KSPGetResidualNorm(ksp, &res);
  KSPGetIterationNumber(ksp, iter);
  *relres = res / bnrm;
  KSPGetTolerances(ksp, &rtol, &abstol, &dtol, &maxits);
  emxInit_char_T(&side, 2);
  if ((*flag < 0) || (*relres > rtol)) {
    KSPGetPC(ksp, &t_pc);
    KSPGetPCSide(ksp, &c_val);
    val = (PC_LEFT);
    b_val = (PC_RIGHT);
    if (val == c_val) {
      c_val = 0;
    } else if (b_val == c_val) {
      c_val = 1;
    } else {
      c_val = -1;
    }

    switch (c_val) {
     case 0:
      c_val = side->size[0] * side->size[1];
      side->size[0] = 1;
      side->size[1] = 4;
      emxEnsureCapacity((emxArray__common *)side, c_val, sizeof(char));
      for (c_val = 0; c_val < 4; c_val++) {
        side->data[c_val] = cv1[c_val];
      }
      break;

     case 1:
      c_val = side->size[0] * side->size[1];
      side->size[0] = 1;
      side->size[1] = 5;
      emxEnsureCapacity((emxArray__common *)side, c_val, sizeof(char));
      for (c_val = 0; c_val < 5; c_val++) {
        side->data[c_val] = cv2[c_val];
      }
      break;

     default:
      c_val = side->size[0] * side->size[1];
      side->size[0] = 1;
      side->size[1] = 9;
      emxEnsureCapacity((emxArray__common *)side, c_val, sizeof(char));
      for (c_val = 0; c_val < 9; c_val++) {
        side->data[c_val] = cv0[c_val];
      }
      break;
    }

    KSPGetType(ksp, &t_type);
    PCGetType(t_pc, &b_t_type);
    m2c_printf(t_type, b_t_type, side, *flag);
    b_m2c_printf(*relres, *iter);
    c_m2c_printf(rtol, abstol);
    d_m2c_printf(maxits, dtol);
    e_m2c_printf();
  }

  emxFree_char_T(&side);
  KSPGetResidualHistory(ksp, &a, &na);
  c_val = reshis->size[0];
  reshis->size[0] = na;
  emxEnsureCapacity((emxArray__common *)reshis, c_val, sizeof(double));
  for (c_val = 0; c_val < na; c_val++) {
    reshis->data[c_val] = 0.0;
  }

  memcpy(&reshis->data[0], a, na << 3);
  *time = secs - t;
}

static void petscKSPSetup(Mat Amat, const emxArray_char_T *ksptype, KSP *ksp,
  double *time)
{
  PetscObject t_obj;
  MPI_Comm t_comm;
  KSP t_ksp;
  double t;
  emxArray_char_T *ksptype0;
  int val;
  int loop_ub;
  double secs;
  t_obj = (PetscObject)(Amat);
  PetscObjectGetComm(t_obj, &t_comm);
  KSPCreate(t_comm, &t_ksp);
  *ksp = t_ksp;
  t_obj = (PetscObject)(t_ksp);
  PetscObjectGetComm(t_obj, &t_comm);
  MPI_Barrier(t_comm);
  t = MPI_Wtime();
  KSPSetOperators(t_ksp, Amat, Amat);
  emxInit_char_T(&ksptype0, 2);
  if ((!(ksptype->size[1] == 0)) && ((unsigned char)ksptype->data[ksptype->size
       [1] - 1] != 0)) {
    val = ksptype0->size[0] * ksptype0->size[1];
    ksptype0->size[0] = 1;
    ksptype0->size[1] = ksptype->size[1] + 1;
    emxEnsureCapacity((emxArray__common *)ksptype0, val, sizeof(char));
    loop_ub = ksptype->size[1];
    for (val = 0; val < loop_ub; val++) {
      ksptype0->data[ksptype0->size[0] * val] = ksptype->data[ksptype->size[0] *
        val];
    }

    ksptype0->data[ksptype0->size[0] * ksptype->size[1]] = '\x00';
  } else {
    val = ksptype0->size[0] * ksptype0->size[1];
    ksptype0->size[0] = 1;
    ksptype0->size[1] = ksptype->size[1];
    emxEnsureCapacity((emxArray__common *)ksptype0, val, sizeof(char));
    loop_ub = ksptype->size[0] * ksptype->size[1];
    for (val = 0; val < loop_ub; val++) {
      ksptype0->data[val] = ksptype->data[val];
    }
  }

  if (!(ksptype0->size[1] == 0)) {
    KSPSetType(t_ksp, &ksptype0->data[0]);
  }

  emxFree_char_T(&ksptype0);
  val = (PC_RIGHT);
  KSPSetPCSide(t_ksp, val);
  KSPSetFromOptions(t_ksp);
  KSPSetUp(t_ksp);
  MPI_Barrier(t_comm);
  secs = MPI_Wtime();
  *time = secs - t;
}

static Mat petscMatCreateAIJFromCRS(const emxArray_int32_T *row_ptr, const
  emxArray_int32_T *col_ind, const emxArray_real_T *val)
{
  Mat mat;
  emxArray_int32_T *nnz;
  int n;
  int i0;
  int i;
  int b_val;
  Mat t_mat;
  emxArray_int32_T *jidx;
  emxArray_real_T *rowval;
  int i1;
  int type;
  int iroa;
  emxInit_int32_T(&nnz, 1);
  n = row_ptr->size[0] - 1;
  i0 = nnz->size[0];
  nnz->size[0] = n;
  emxEnsureCapacity((emxArray__common *)nnz, i0, sizeof(int));
  for (i = 1; i <= n; i++) {
    nnz->data[i - 1] = row_ptr->data[i] - row_ptr->data[i - 1];
  }

  b_val = (PETSC_DEFAULT);
  MatCreateSeqAIJ(PETSC_COMM_SELF, n, n, b_val, &nnz->data[0], &t_mat);
  mat = t_mat;
  i = 0;
  emxInit_int32_T(&jidx, 1);
  emxInit_real_T(&rowval, 1);
  while (i + 1 <= n) {
    if (row_ptr->data[i] > row_ptr->data[i + 1] - 1) {
      i0 = 0;
      i1 = 0;
    } else {
      i0 = row_ptr->data[i] - 1;
      i1 = row_ptr->data[i + 1] - 1;
    }

    b_val = jidx->size[0];
    jidx->size[0] = i1 - i0;
    emxEnsureCapacity((emxArray__common *)jidx, b_val, sizeof(int));
    b_val = i1 - i0;
    for (i1 = 0; i1 < b_val; i1++) {
      jidx->data[i1] = col_ind->data[i0 + i1] - 1;
    }

    if (row_ptr->data[i] > row_ptr->data[i + 1] - 1) {
      i0 = 0;
      i1 = 0;
    } else {
      i0 = row_ptr->data[i] - 1;
      i1 = row_ptr->data[i + 1] - 1;
    }

    b_val = rowval->size[0];
    rowval->size[0] = i1 - i0;
    emxEnsureCapacity((emxArray__common *)rowval, b_val, sizeof(double));
    b_val = i1 - i0;
    for (i1 = 0; i1 < b_val; i1++) {
      rowval->data[i1] = val->data[i0 + i1];
    }

    iroa = (INSERT_VALUES);
    MatSetValues(t_mat, 1, &i, nnz->data[i], &jidx->data[0], &rowval->data[0],
                 iroa);
    i++;
  }

  emxFree_real_T(&rowval);
  emxFree_int32_T(&jidx);
  emxFree_int32_T(&nnz);
  type = (MAT_FINAL_ASSEMBLY);
  MatAssemblyBegin(t_mat, type);
  type = (MAT_FINAL_ASSEMBLY);
  MatAssemblyEnd(t_mat, type);
  return mat;
}

static void petscSolveHdls(Mat A, Vec b, Vec x, const emxArray_char_T *solver,
  double rtol, int maxit, const emxArray_char_T *pctype, const emxArray_char_T
  *pcopt, Vec x0, int *flag, double *relres, int *iter, emxArray_real_T *reshis,
  double times[2])
{
  KSP ksp;
  double time_setup;
  double time_solve;
  KSP t_ksp;
  b_petscKSPSetup(A, solver, pctype, pcopt, &ksp, &time_setup);
  b_petscKSPDriver(ksp, b, x, rtol, maxit, x0, flag, relres, iter, reshis,
                   &time_solve);
  times[0] = time_setup;
  times[1] = time_solve;
  t_ksp = ksp;
  KSPDestroy(&t_ksp);
}

static Vec petscVecCreateFromArray(const emxArray_real_T *arr)
{
  Vec vec;
  emxArray_int32_T *y;
  int n;
  Vec t_vec;
  int b_n;
  int k;
  emxArray_int32_T *idx;
  int yk;
  int iroa;
  emxInit_int32_T(&y, 2);
  n = arr->size[0];
  VecCreateSeq(PETSC_COMM_SELF, n, &t_vec);
  vec = t_vec;
  if (n - 1 < 0) {
    b_n = 0;
  } else {
    b_n = n;
  }

  k = y->size[0] * y->size[1];
  y->size[0] = 1;
  y->size[1] = b_n;
  emxEnsureCapacity((emxArray__common *)y, k, sizeof(int));
  if (b_n > 0) {
    y->data[0] = 0;
    yk = 0;
    for (k = 2; k <= b_n; k++) {
      yk++;
      y->data[k - 1] = yk;
    }
  }

  emxInit_int32_T(&idx, 1);
  k = idx->size[0];
  idx->size[0] = y->size[1];
  emxEnsureCapacity((emxArray__common *)idx, k, sizeof(int));
  yk = y->size[1];
  for (k = 0; k < yk; k++) {
    idx->data[k] = y->data[y->size[0] * k];
  }

  emxFree_int32_T(&y);
  iroa = (INSERT_VALUES);
  VecSetValues(t_vec, n, &idx->data[0], &arr->data[0], iroa);
  VecAssemblyBegin(t_vec);
  VecAssemblyEnd(t_vec);
  emxFree_int32_T(&idx);
  return vec;
}

static void petscVecToArray(Vec vec, emxArray_real_T *arr)
{
  emxArray_int32_T *y;
  int n;
  int k;
  int b_n;
  emxArray_int32_T *idx;
  int yk;
  emxInit_int32_T(&y, 2);
  VecGetLocalSize(vec, &n);
  k = arr->size[0];
  arr->size[0] = n;
  emxEnsureCapacity((emxArray__common *)arr, k, sizeof(double));
  if (n - 1 < 0) {
    b_n = 0;
  } else {
    b_n = n;
  }

  k = y->size[0] * y->size[1];
  y->size[0] = 1;
  y->size[1] = b_n;
  emxEnsureCapacity((emxArray__common *)y, k, sizeof(int));
  if (b_n > 0) {
    y->data[0] = 0;
    yk = 0;
    for (k = 2; k <= b_n; k++) {
      yk++;
      y->data[k - 1] = yk;
    }
  }

  emxInit_int32_T(&idx, 1);
  k = idx->size[0];
  idx->size[0] = y->size[1];
  emxEnsureCapacity((emxArray__common *)idx, k, sizeof(int));
  yk = y->size[1];
  for (k = 0; k < yk; k++) {
    idx->data[k] = y->data[y->size[0] * k];
  }

  emxFree_int32_T(&y);
  if (arr->size[0] < n) {
    m2c_error();
  }

  VecGetValues(vec, n, &idx->data[0], &arr->data[0]);
  emxFree_int32_T(&idx);
}

void petscSolveCRS(int *flag, double *relres, int *iter, double times[2])
{
  int i;
  *flag = -1;
  *relres = 1.7976931348623157E+308;
  *iter = 0;
  for (i = 0; i < 2; i++) {
    times[i] = 0.0;
  }
}

void petscSolveCRS_10args(const emxArray_int32_T *Arows, const emxArray_int32_T *
  Acols, const emxArray_real_T *Avals, const emxArray_real_T *b, const
  emxArray_char_T *solver, double rtol, int maxiter, const emxArray_char_T
  *pctype, const emxArray_char_T *solpack, const emxArray_real_T *x0,
  emxArray_real_T *x, int *flag, double *relres, int *iter, emxArray_real_T
  *reshis, double times[2])
{
  Mat AMat;
  Vec bVec;
  Vec x0Vec;
  Vec xVec;
  Vec t_vec_out;
  Mat t_mat;
  Vec t_vec;
  AMat = petscMatCreateAIJFromCRS(Arows, Acols, Avals);
  bVec = petscVecCreateFromArray(b);
  if (x0->size[0] == 0) {
    x0Vec = NULL;
    VecDuplicate(bVec, &t_vec_out);
    xVec = t_vec_out;
  } else {
    x0Vec = petscVecCreateFromArray(x0);
    xVec = x0Vec;
  }

  petscSolveHdls(AMat, bVec, xVec, solver, rtol, maxiter, pctype, solpack, x0Vec,
                 flag, relres, iter, reshis, times);
  t_mat = AMat;
  MatDestroy(&t_mat);
  t_vec = bVec;
  VecDestroy(&t_vec);
  petscVecToArray(xVec, x);
  t_vec = xVec;
  VecDestroy(&t_vec);
}

void petscSolveCRS_11args(const emxArray_int32_T *Arows, const emxArray_int32_T *
  Acols, const emxArray_real_T *Avals, const emxArray_real_T *b, const
  emxArray_char_T *solver, double rtol, int maxiter, const emxArray_char_T
  *pctype, const emxArray_char_T *solpack, const emxArray_real_T *x0, const
  emxArray_char_T *opts, emxArray_real_T *x, int *flag, double *relres, int
  *iter, emxArray_real_T *reshis, double times[2])
{
  emxArray_char_T *varargin_11;
  int errCode;
  int loop_ub;
  Mat AMat;
  Vec bVec;
  Vec x0Vec;
  Vec xVec;
  Vec t_vec_out;
  KSP ksp;
  double time_setup;
  double time_solve;
  KSP t_ksp;
  Mat t_mat;
  Vec t_vec;
  emxInit_char_T(&varargin_11, 2);
  errCode = varargin_11->size[0] * varargin_11->size[1];
  varargin_11->size[0] = 1;
  varargin_11->size[1] = opts->size[1];
  emxEnsureCapacity((emxArray__common *)varargin_11, errCode, sizeof(char));
  loop_ub = opts->size[0] * opts->size[1];
  for (errCode = 0; errCode < loop_ub; errCode++) {
    varargin_11->data[errCode] = opts->data[errCode];
  }

  AMat = petscMatCreateAIJFromCRS(Arows, Acols, Avals);
  bVec = petscVecCreateFromArray(b);
  if (x0->size[0] == 0) {
    x0Vec = NULL;
    VecDuplicate(bVec, &t_vec_out);
    xVec = t_vec_out;
  } else {
    x0Vec = petscVecCreateFromArray(x0);
    xVec = x0Vec;
  }

  if (!(opts->size[1] == 0)) {
    if (opts->data[opts->size[1] - 1] != '\x00') {
      errCode = varargin_11->size[0] * varargin_11->size[1];
      varargin_11->size[0] = 1;
      varargin_11->size[1] = opts->size[1] + 1;
      emxEnsureCapacity((emxArray__common *)varargin_11, errCode, sizeof(char));
      loop_ub = opts->size[1];
      for (errCode = 0; errCode < loop_ub; errCode++) {
        varargin_11->data[varargin_11->size[0] * errCode] = opts->data
          [opts->size[0] * errCode];
      }

      varargin_11->data[varargin_11->size[0] * opts->size[1]] = '\x00';
    }

    if ((!(varargin_11->size[1] == 0)) && (varargin_11->data[varargin_11->size[1]
         - 1] != '\x00')) {
      b_m2c_error();
    }

    errCode = PetscOptionsInsertString(NULL, &varargin_11->data[0]);
    if (errCode != 0) {
      c_m2c_error(errCode);
    }
  }

  emxFree_char_T(&varargin_11);
  b_petscKSPSetup(AMat, solver, pctype, solpack, &ksp, &time_setup);
  b_petscKSPDriver(ksp, bVec, xVec, rtol, maxiter, x0Vec, flag, relres, iter,
                   reshis, &time_solve);
  t_ksp = ksp;
  KSPDestroy(&t_ksp);
  t_mat = AMat;
  MatDestroy(&t_mat);
  t_vec = bVec;
  VecDestroy(&t_vec);
  petscVecToArray(xVec, x);
  t_vec = xVec;
  VecDestroy(&t_vec);
  times[0] = time_setup;
  times[1] = time_solve;
}

void petscSolveCRS_4args(const emxArray_int32_T *Arows, const emxArray_int32_T
  *Acols, const emxArray_real_T *Avals, const emxArray_real_T *b,
  emxArray_real_T *x, int *flag, double *relres, int *iter, emxArray_real_T
  *reshis, double times[2])
{
  Mat AMat;
  Vec bVec;
  Vec t_vec_out;
  PetscObject t_obj;
  MPI_Comm t_comm;
  KSP t_ksp;
  double t;
  int val;
  double secs;
  double time_solve;
  Mat t_mat;
  Vec t_vec;
  AMat = petscMatCreateAIJFromCRS(Arows, Acols, Avals);
  bVec = petscVecCreateFromArray(b);
  VecDuplicate(bVec, &t_vec_out);
  t_obj = (PetscObject)(AMat);
  PetscObjectGetComm(t_obj, &t_comm);
  KSPCreate(t_comm, &t_ksp);
  t_obj = (PetscObject)(t_ksp);
  PetscObjectGetComm(t_obj, &t_comm);
  MPI_Barrier(t_comm);
  t = MPI_Wtime();
  KSPSetOperators(t_ksp, AMat, AMat);
  val = (PC_RIGHT);
  KSPSetPCSide(t_ksp, val);
  KSPSetFromOptions(t_ksp);
  KSPSetUp(t_ksp);
  MPI_Barrier(t_comm);
  secs = MPI_Wtime();
  petscKSPDriver(t_ksp, bVec, t_vec_out, NULL, flag, relres, iter, reshis,
                 &time_solve);
  KSPDestroy(&t_ksp);
  t_mat = AMat;
  MatDestroy(&t_mat);
  t_vec = bVec;
  VecDestroy(&t_vec);
  petscVecToArray(t_vec_out, x);
  t_vec = t_vec_out;
  VecDestroy(&t_vec);
  times[0] = secs - t;
  times[1] = time_solve;
}

void petscSolveCRS_5args(const emxArray_int32_T *Arows, const emxArray_int32_T
  *Acols, const emxArray_real_T *Avals, const emxArray_real_T *b, const
  emxArray_char_T *solver, emxArray_real_T *x, int *flag, double *relres, int
  *iter, emxArray_real_T *reshis, double times[2])
{
  Mat AMat;
  Vec bVec;
  Vec t_vec_out;
  KSP ksp;
  double time_setup;
  double time_solve;
  KSP t_ksp;
  Mat t_mat;
  Vec t_vec;
  AMat = petscMatCreateAIJFromCRS(Arows, Acols, Avals);
  bVec = petscVecCreateFromArray(b);
  VecDuplicate(bVec, &t_vec_out);
  petscKSPSetup(AMat, solver, &ksp, &time_setup);
  petscKSPDriver(ksp, bVec, t_vec_out, NULL, flag, relres, iter, reshis,
                 &time_solve);
  t_ksp = ksp;
  KSPDestroy(&t_ksp);
  t_mat = AMat;
  MatDestroy(&t_mat);
  t_vec = bVec;
  VecDestroy(&t_vec);
  petscVecToArray(t_vec_out, x);
  t_vec = t_vec_out;
  VecDestroy(&t_vec);
  times[0] = time_setup;
  times[1] = time_solve;
}

void petscSolveCRS_6args(const emxArray_int32_T *Arows, const emxArray_int32_T
  *Acols, const emxArray_real_T *Avals, const emxArray_real_T *b, const
  emxArray_char_T *solver, double rtol, emxArray_real_T *x, int *flag, double
  *relres, int *iter, emxArray_real_T *reshis, double times[2])
{
  Mat AMat;
  Vec bVec;
  Vec obj;
  Vec t_vec_out;
  KSP ksp;
  double time_setup;
  double b_rtol;
  int val;
  double bnrm;
  PetscObject t_obj;
  MPI_Comm t_comm;
  double t;
  int maxits;
  int b_val;
  boolean_T b1;
  double secs;
  double res;
  double abstol;
  double dtol;
  emxArray_char_T *side;
  PC t_pc;
  PetscReal * a;
  int na;
  int b_side;
  KSP t_ksp;
  Mat t_mat;
  Vec t_vec;
  static const char cv3[9] = { 's', 'y', 'm', 'm', 'e', 't', 'r', 'i', 'c' };

  static const char cv4[4] = { 'l', 'e', 'f', 't' };

  static const char cv5[5] = { 'r', 'i', 'g', 'h', 't' };

  KSPType t_type;
  PCType b_t_type;
  AMat = petscMatCreateAIJFromCRS(Arows, Acols, Avals);
  bVec = petscVecCreateFromArray(b);
  obj = NULL;
  VecDuplicate(bVec, &t_vec_out);
  petscKSPSetup(AMat, solver, &ksp, &time_setup);
  b_rtol = rtol;
  val = (NORM_2);
  VecNorm(bVec, val, &bnrm);
  t_obj = (PetscObject)(ksp);
  PetscObjectGetComm(t_obj, &t_comm);
  MPI_Barrier(t_comm);
  t = MPI_Wtime();
  maxits = (PETSC_DEFAULT);
  if (rtol == 0.0) {
    val = (PETSC_DEFAULT);
    b_rtol = val;
  }

  val = (PETSC_DEFAULT);
  b_val = (PETSC_DEFAULT);
  KSPSetTolerances(ksp, b_rtol, (double)val, (double)b_val, maxits);
  val = !(obj);
  b1 = !(val != 0);
  if (b1) {
    VecCopy(obj, t_vec_out);
  }

  val = (PETSC_TRUE);
  KSPSetResidualHistory(ksp, NULL, maxits, val);
  KSPSetInitialGuessNonzero(ksp, (int)b1);
  KSPSolve(ksp, bVec, t_vec_out);
  MPI_Barrier(t_comm);
  secs = MPI_Wtime();
  KSPGetConvergedReason(ksp, flag);
  KSPGetResidualNorm(ksp, &res);
  KSPGetIterationNumber(ksp, iter);
  *relres = res / bnrm;
  KSPGetTolerances(ksp, &b_rtol, &abstol, &dtol, &maxits);
  emxInit_char_T(&side, 2);
  if ((*flag < 0) || (*relres > b_rtol)) {
    KSPGetPC(ksp, &t_pc);
    KSPGetPCSide(ksp, &b_side);
    val = (PC_LEFT);
    b_val = (PC_RIGHT);
    if (val == b_side) {
      val = 0;
    } else if (b_val == b_side) {
      val = 1;
    } else {
      val = -1;
    }

    switch (val) {
     case 0:
      val = side->size[0] * side->size[1];
      side->size[0] = 1;
      side->size[1] = 4;
      emxEnsureCapacity((emxArray__common *)side, val, sizeof(char));
      for (val = 0; val < 4; val++) {
        side->data[val] = cv4[val];
      }
      break;

     case 1:
      val = side->size[0] * side->size[1];
      side->size[0] = 1;
      side->size[1] = 5;
      emxEnsureCapacity((emxArray__common *)side, val, sizeof(char));
      for (val = 0; val < 5; val++) {
        side->data[val] = cv5[val];
      }
      break;

     default:
      val = side->size[0] * side->size[1];
      side->size[0] = 1;
      side->size[1] = 9;
      emxEnsureCapacity((emxArray__common *)side, val, sizeof(char));
      for (val = 0; val < 9; val++) {
        side->data[val] = cv3[val];
      }
      break;
    }

    KSPGetType(ksp, &t_type);
    PCGetType(t_pc, &b_t_type);
    m2c_printf(t_type, b_t_type, side, *flag);
    b_m2c_printf(*relres, *iter);
    c_m2c_printf(b_rtol, abstol);
    d_m2c_printf(maxits, dtol);
    e_m2c_printf();
  }

  emxFree_char_T(&side);
  KSPGetResidualHistory(ksp, &a, &na);
  val = reshis->size[0];
  reshis->size[0] = na;
  emxEnsureCapacity((emxArray__common *)reshis, val, sizeof(double));
  for (val = 0; val < na; val++) {
    reshis->data[val] = 0.0;
  }

  memcpy(&reshis->data[0], a, na << 3);
  t_ksp = ksp;
  KSPDestroy(&t_ksp);
  t_mat = AMat;
  MatDestroy(&t_mat);
  t_vec = bVec;
  VecDestroy(&t_vec);
  petscVecToArray(t_vec_out, x);
  t_vec = t_vec_out;
  VecDestroy(&t_vec);
  times[0] = time_setup;
  times[1] = secs - t;
}

void petscSolveCRS_7args(const emxArray_int32_T *Arows, const emxArray_int32_T
  *Acols, const emxArray_real_T *Avals, const emxArray_real_T *b, const
  emxArray_char_T *solver, double rtol, int maxiter, emxArray_real_T *x, int
  *flag, double *relres, int *iter, emxArray_real_T *reshis, double times[2])
{
  Mat AMat;
  Vec bVec;
  Vec t_vec_out;
  KSP ksp;
  double time_setup;
  double time_solve;
  KSP t_ksp;
  Mat t_mat;
  Vec t_vec;
  AMat = petscMatCreateAIJFromCRS(Arows, Acols, Avals);
  bVec = petscVecCreateFromArray(b);
  VecDuplicate(bVec, &t_vec_out);
  petscKSPSetup(AMat, solver, &ksp, &time_setup);
  b_petscKSPDriver(ksp, bVec, t_vec_out, rtol, maxiter, NULL, flag, relres, iter,
                   reshis, &time_solve);
  t_ksp = ksp;
  KSPDestroy(&t_ksp);
  t_mat = AMat;
  MatDestroy(&t_mat);
  t_vec = bVec;
  VecDestroy(&t_vec);
  petscVecToArray(t_vec_out, x);
  t_vec = t_vec_out;
  VecDestroy(&t_vec);
  times[0] = time_setup;
  times[1] = time_solve;
}

void petscSolveCRS_8args(const emxArray_int32_T *Arows, const emxArray_int32_T
  *Acols, const emxArray_real_T *Avals, const emxArray_real_T *b, const
  emxArray_char_T *solver, double rtol, int maxiter, const emxArray_char_T
  *pctype, emxArray_real_T *x, int *flag, double *relres, int *iter,
  emxArray_real_T *reshis, double times[2])
{
  Mat AMat;
  Vec bVec;
  Vec t_vec_out;
  PetscObject t_obj;
  MPI_Comm t_comm;
  KSP t_ksp;
  double t;
  boolean_T hasPC;
  emxArray_char_T *ksptype0;
  PC t_pc;
  int val;
  emxArray_char_T *pctype0;
  int loop_ub;
  double secs;
  double time_solve;
  Mat t_mat;
  Vec t_vec;
  AMat = petscMatCreateAIJFromCRS(Arows, Acols, Avals);
  bVec = petscVecCreateFromArray(b);
  VecDuplicate(bVec, &t_vec_out);
  t_obj = (PetscObject)(AMat);
  PetscObjectGetComm(t_obj, &t_comm);
  KSPCreate(t_comm, &t_ksp);
  t_obj = (PetscObject)(t_ksp);
  PetscObjectGetComm(t_obj, &t_comm);
  MPI_Barrier(t_comm);
  t = MPI_Wtime();
  KSPSetOperators(t_ksp, AMat, AMat);
  hasPC = !(pctype->size[1] == 0);
  if (hasPC) {
    KSPGetPC(t_ksp, &t_pc);
    emxInit_char_T(&pctype0, 2);
    if (pctype->data[pctype->size[1] - 1] != '\x00') {
      val = pctype0->size[0] * pctype0->size[1];
      pctype0->size[0] = 1;
      pctype0->size[1] = pctype->size[1] + 1;
      emxEnsureCapacity((emxArray__common *)pctype0, val, sizeof(char));
      loop_ub = pctype->size[1];
      for (val = 0; val < loop_ub; val++) {
        pctype0->data[pctype0->size[0] * val] = pctype->data[pctype->size[0] *
          val];
      }

      pctype0->data[pctype0->size[0] * pctype->size[1]] = '\x00';
    } else {
      val = pctype0->size[0] * pctype0->size[1];
      pctype0->size[0] = 1;
      pctype0->size[1] = pctype->size[1];
      emxEnsureCapacity((emxArray__common *)pctype0, val, sizeof(char));
      loop_ub = pctype->size[0] * pctype->size[1];
      for (val = 0; val < loop_ub; val++) {
        pctype0->data[val] = pctype->data[val];
      }
    }

    PCSetType(t_pc, &pctype0->data[0]);
    emxFree_char_T(&pctype0);
  }

  emxInit_char_T(&ksptype0, 2);
  if ((!(solver->size[1] == 0)) && ((unsigned char)solver->data[solver->size[1]
       - 1] != 0)) {
    val = ksptype0->size[0] * ksptype0->size[1];
    ksptype0->size[0] = 1;
    ksptype0->size[1] = solver->size[1] + 1;
    emxEnsureCapacity((emxArray__common *)ksptype0, val, sizeof(char));
    loop_ub = solver->size[1];
    for (val = 0; val < loop_ub; val++) {
      ksptype0->data[ksptype0->size[0] * val] = solver->data[solver->size[0] *
        val];
    }

    ksptype0->data[ksptype0->size[0] * solver->size[1]] = '\x00';
  } else {
    val = ksptype0->size[0] * ksptype0->size[1];
    ksptype0->size[0] = 1;
    ksptype0->size[1] = solver->size[1];
    emxEnsureCapacity((emxArray__common *)ksptype0, val, sizeof(char));
    loop_ub = solver->size[0] * solver->size[1];
    for (val = 0; val < loop_ub; val++) {
      ksptype0->data[val] = solver->data[val];
    }
  }

  if (!(ksptype0->size[1] == 0)) {
    KSPSetType(t_ksp, &ksptype0->data[0]);
  }

  emxFree_char_T(&ksptype0);
  val = (PC_RIGHT);
  KSPSetPCSide(t_ksp, val);
  KSPSetFromOptions(t_ksp);
  KSPSetUp(t_ksp);
  MPI_Barrier(t_comm);
  secs = MPI_Wtime();
  b_petscKSPDriver(t_ksp, bVec, t_vec_out, rtol, maxiter, NULL, flag, relres,
                   iter, reshis, &time_solve);
  KSPDestroy(&t_ksp);
  t_mat = AMat;
  MatDestroy(&t_mat);
  t_vec = bVec;
  VecDestroy(&t_vec);
  petscVecToArray(t_vec_out, x);
  t_vec = t_vec_out;
  VecDestroy(&t_vec);
  times[0] = secs - t;
  times[1] = time_solve;
}

void petscSolveCRS_9args(const emxArray_int32_T *Arows, const emxArray_int32_T
  *Acols, const emxArray_real_T *Avals, const emxArray_real_T *b, const
  emxArray_char_T *solver, double rtol, int maxiter, const emxArray_char_T
  *pctype, const emxArray_char_T *solpack, emxArray_real_T *x, int *flag, double
  *relres, int *iter, emxArray_real_T *reshis, double times[2])
{
  Mat AMat;
  Vec bVec;
  Vec t_vec_out;
  Mat t_mat;
  Vec t_vec;
  AMat = petscMatCreateAIJFromCRS(Arows, Acols, Avals);
  bVec = petscVecCreateFromArray(b);
  VecDuplicate(bVec, &t_vec_out);
  petscSolveHdls(AMat, bVec, t_vec_out, solver, rtol, maxiter, pctype, solpack,
                 NULL, flag, relres, iter, reshis, times);
  t_mat = AMat;
  MatDestroy(&t_mat);
  t_vec = bVec;
  VecDestroy(&t_vec);
  petscVecToArray(t_vec_out, x);
  t_vec = t_vec_out;
  VecDestroy(&t_vec);
}

void petscSolveCRS_initialize(void)
{
}

void petscSolveCRS_terminate(void)
{
}
