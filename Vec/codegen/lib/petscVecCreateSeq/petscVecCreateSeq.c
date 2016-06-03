#include "petscVecCreateSeq.h"
#include "m2c.h"
#include "mpetsc.h"

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
  fmt = "VecCreateSeq returned error code %d\n";
  M2C_error(msgid, fmt, varargin_3);
}

void emxDestroy_struct0_T(struct0_T emxArray)
{
  emxFreeStruct_struct0_T(&emxArray);
}

void emxInit_struct0_T(struct0_T *pStruct)
{
  emxInitStruct_struct0_T(pStruct);
}

void petscVecCreateSeq(int n, struct0_T *vec, int *errCode, boolean_T *toplevel)
{
  emxArray_uint8_T *data0;
  MPI_Comm obj;
  Vec t_vec;
  int sizepe;
  int i;
  char t0_type[3];
  static const char cv0[3] = { 'V', 'e', 'c' };

  int loop_ub;
  char * ptr;
  emxInit_uint8_T(&data0, 1);
  obj = PETSC_COMM_SELF;
  *errCode = VecCreateSeq(obj, n, &t_vec);
  *toplevel = true;
  sizepe = sizeof(Vec);
  i = data0->size[0];
  data0->size[0] = sizepe;
  emxEnsureCapacity((emxArray__common *)data0, i, (int)sizeof(unsigned char));
  for (i = 0; i < 3; i++) {
    t0_type[i] = cv0[i];
  }

  i = vec->data->size[0];
  vec->data->size[0] = data0->size[0];
  emxEnsureCapacity((emxArray__common *)vec->data, i, (int)sizeof(unsigned char));
  loop_ub = data0->size[0];
  for (i = 0; i < loop_ub; i++) {
    vec->data->data[i] = data0->data[i];
  }

  emxFree_uint8_T(&data0);
  vec->type.size[0] = 1;
  vec->type.size[1] = 3;
  for (i = 0; i < 3; i++) {
    vec->type.data[i] = t0_type[i];
  }

  vec->nitems = 1;
  ptr = (char *)(&t_vec);
  for (i = 1; i <= sizepe; i++) {
    vec->data->data[i - 1] = *(ptr);
    ptr = M2C_OFFSET_PTR(ptr, 1);
  }

  if (*errCode != 0) {
    m2c_error(*errCode);
  }
}

void petscVecCreateSeq_initialize(void)
{
}

void petscVecCreateSeq_terminate(void)
{
}
