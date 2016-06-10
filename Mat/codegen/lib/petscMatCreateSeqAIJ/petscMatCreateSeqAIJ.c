#include "petscMatCreateSeqAIJ.h"
#include "m2c.h"
#include "mpetsc.h"
#include "mpi.h"

static void emxFreeStruct_struct0_T(struct0_T *pStruct);
static void emxInitStruct_struct0_T(struct0_T *pStruct);
static void m2c_error(int varargin_3);

static void emxFreeStruct_struct0_T(struct0_T *pStruct)
{
  emxFree_uint8_T(&pStruct->data);
}

static void emxInitStruct_struct0_T(struct0_T *pStruct)
{
  emxInit_uint8_T(&pStruct->data, 1);
  pStruct->type.size[0] = 0;
  pStruct->type.size[1] = 0;
}

static void m2c_error(int varargin_3)
{
  const char * msgid;
  const char * fmt;
  msgid = "petsc:RuntimeError";
  fmt = "MatCreateSeqAIJ returned error code %d\n";
  M2C_error(msgid, fmt, varargin_3);
}

void emxDestroy_struct0_T(struct0_T emxArray)
{
  emxFreeStruct_struct0_T(&emxArray);
}

void emxInitArray_int32_T(emxArray_int32_T **pEmxArray, int numDimensions)
{
  emxInit_int32_T(pEmxArray, numDimensions);
}

void emxInit_struct0_T(struct0_T *pStruct)
{
  emxInitStruct_struct0_T(pStruct);
}

void petscMatCreateSeqAIJ(int m, int n, int nz, const emxArray_int32_T *nnz,
  struct0_T *mat, int *errCode, boolean_T *toplevel)
{
  emxArray_uint8_T *data0;
  MPI_Comm obj;
  Mat t_mat;
  int sizepe;
  int i;
  char t1_type[3];
  static const char cv0[3] = { 'M', 'a', 't' };

  int loop_ub;
  char * ptr;
  emxInit_uint8_T(&data0, 1);
  obj = PETSC_COMM_SELF;
  *errCode = MatCreateSeqAIJ(obj, m, n, nz, &nnz->data[0], &t_mat);
  *toplevel = true;
  sizepe = sizeof(Mat);
  i = data0->size[0];
  data0->size[0] = sizepe;
  emxEnsureCapacity((emxArray__common *)data0, i, (int)sizeof(unsigned char));
  for (i = 0; i < 3; i++) {
    t1_type[i] = cv0[i];
  }

  i = mat->data->size[0];
  mat->data->size[0] = data0->size[0];
  emxEnsureCapacity((emxArray__common *)mat->data, i, (int)sizeof(unsigned char));
  loop_ub = data0->size[0];
  for (i = 0; i < loop_ub; i++) {
    mat->data->data[i] = data0->data[i];
  }

  emxFree_uint8_T(&data0);
  mat->type.size[0] = 1;
  mat->type.size[1] = 3;
  for (i = 0; i < 3; i++) {
    mat->type.data[i] = t1_type[i];
  }

  mat->nitems = 1;
  ptr = (char *)(&t_mat);
  for (i = 1; i <= sizepe; i++) {
    mat->data->data[i - 1] = *(ptr);
    ptr = M2C_OFFSET_PTR(ptr, 1);
  }

  if (*errCode != 0) {
    m2c_error(*errCode);
  }
}

void petscMatCreateSeqAIJ_FixedRows(int m, int n, int nz, struct0_T *mat, int
  *errCode, boolean_T *topleve)
{
  emxArray_uint8_T *data0;
  MPI_Comm obj;
  PetscInt * nnz;
  Mat t_mat;
  int b_errCode;
  int sizepe;
  int i;
  char t0_type[3];
  static const char cv1[3] = { 'M', 'a', 't' };

  int loop_ub;
  char * ptr;
  emxInit_uint8_T(&data0, 1);
  obj = PETSC_COMM_SELF;
  nnz = NULL;
  b_errCode = MatCreateSeqAIJ(obj, m, n, nz, nnz, &t_mat);
  sizepe = sizeof(Mat);
  i = data0->size[0];
  data0->size[0] = sizepe;
  emxEnsureCapacity((emxArray__common *)data0, i, (int)sizeof(unsigned char));
  for (i = 0; i < 3; i++) {
    t0_type[i] = cv1[i];
  }

  i = mat->data->size[0];
  mat->data->size[0] = data0->size[0];
  emxEnsureCapacity((emxArray__common *)mat->data, i, (int)sizeof(unsigned char));
  loop_ub = data0->size[0];
  for (i = 0; i < loop_ub; i++) {
    mat->data->data[i] = data0->data[i];
  }

  emxFree_uint8_T(&data0);
  mat->type.size[0] = 1;
  mat->type.size[1] = 3;
  for (i = 0; i < 3; i++) {
    mat->type.data[i] = t0_type[i];
  }

  mat->nitems = 1;
  ptr = (char *)(&t_mat);
  for (i = 1; i <= sizepe; i++) {
    mat->data->data[i - 1] = *(ptr);
    ptr = M2C_OFFSET_PTR(ptr, 1);
  }

  if (b_errCode != 0) {
    m2c_error(b_errCode);
  }

  *errCode = b_errCode;
  *topleve = true;
}

void petscMatCreateSeqAIJ_initialize(void)
{
}

void petscMatCreateSeqAIJ_terminate(void)
{
}
