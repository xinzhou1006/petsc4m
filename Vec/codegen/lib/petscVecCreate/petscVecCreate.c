#include "petscVecCreate.h"
#include "m2c.h"
#include "mpi.h"
#include "petsc4m.h"

static void b_m2c_error(int varargin_3);
static void m2c_error(const emxArray_char_T *varargin_3);
static void b_m2c_error(int varargin_3)
{
  const char * msgid;
  const char * fmt;
  msgid = "petsc:RuntimeError";
  fmt = "VecCreate returned error code %d\n";
  M2C_error(msgid, fmt, varargin_3);
}

static void m2c_error(const emxArray_char_T *varargin_3)
{
  emxArray_char_T *b_varargin_3;
  const char * msgid;
  const char * fmt;
  int i0;
  int loop_ub;
  emxInit_char_T(&b_varargin_3, 2);
  msgid = "m2c_opaque_obj:WrongInput";
  fmt = "Incorrect data type %s. Expected MPI_Comm.\n";
  i0 = b_varargin_3->size[0] * b_varargin_3->size[1];
  b_varargin_3->size[0] = 1;
  b_varargin_3->size[1] = varargin_3->size[1];
  emxEnsureCapacity_char_T(b_varargin_3, i0);
  loop_ub = varargin_3->size[0] * varargin_3->size[1];
  for (i0 = 0; i0 < loop_ub; i0++) {
    b_varargin_3->data[i0] = varargin_3->data[i0];
  }

  M2C_error(msgid, fmt, &b_varargin_3->data[0]);
  emxFree_char_T(&b_varargin_3);
}

void petscVecCreate(const struct0_T *comm, struct0_T *vec, int *errCode,
                    boolean_T *toplevel)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  boolean_T exitg1;
  emxArray_char_T *b_comm;
  static const char cv0[8] = { 'M', 'P', 'I', '_', 'C', 'o', 'm', 'm' };

  emxArray_uint8_T *data0;
  int loop_ub;
  MPI_Comm t_comm;
  Vec t_vec;
  int sizepe;
  char t1_type[3];
  static const char cv1[3] = { 'V', 'e', 'c' };

  char * ptr;
  p = false;
  b_p = false;
  if (comm->type->size[1] == 8) {
    b_p = true;
  }

  if (b_p && (!(comm->type->size[1] == 0))) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 8)) {
      if (!(comm->type->data[k] == cv0[k])) {
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

  if (!p) {
    emxInit_char_T(&b_comm, 2);
    k = b_comm->size[0] * b_comm->size[1];
    b_comm->size[0] = 1;
    b_comm->size[1] = comm->type->size[1] + 1;
    emxEnsureCapacity_char_T(b_comm, k);
    loop_ub = comm->type->size[1];
    for (k = 0; k < loop_ub; k++) {
      b_comm->data[b_comm->size[0] * k] = comm->type->data[comm->type->size[0] *
        k];
    }

    b_comm->data[b_comm->size[0] * comm->type->size[1]] = '\x00';
    m2c_error(b_comm);
    emxFree_char_T(&b_comm);
  }

  emxInit_uint8_T(&data0, 1);
  k = data0->size[0];
  data0->size[0] = comm->data->size[0];
  emxEnsureCapacity_uint8_T(data0, k);
  loop_ub = comm->data->size[0];
  for (k = 0; k < loop_ub; k++) {
    data0->data[k] = comm->data->data[k];
  }

  t_comm = *(MPI_Comm*)(&data0->data[0]);
  *errCode = VecCreate(t_comm, &t_vec);
  if (*errCode != 0) {
    b_m2c_error(*errCode);
  }

  sizepe = sizeof(Vec);
  k = data0->size[0];
  data0->size[0] = sizepe;
  emxEnsureCapacity_uint8_T(data0, k);
  for (k = 0; k < 3; k++) {
    t1_type[k] = cv1[k];
  }

  k = vec->data->size[0];
  vec->data->size[0] = data0->size[0];
  emxEnsureCapacity_uint8_T(vec->data, k);
  loop_ub = data0->size[0];
  for (k = 0; k < loop_ub; k++) {
    vec->data->data[k] = data0->data[k];
  }

  emxFree_uint8_T(&data0);
  k = vec->type->size[0] * vec->type->size[1];
  vec->type->size[0] = 1;
  vec->type->size[1] = 3;
  emxEnsureCapacity_char_T(vec->type, k);
  for (k = 0; k < 3; k++) {
    vec->type->data[k] = t1_type[k];
  }

  vec->nitems = 1;
  ptr = (char *)(&t_vec);
  for (k = 1; k <= sizepe; k++) {
    vec->data->data[k - 1] = *(ptr);
    ptr = ptr + 1;
  }

  *toplevel = true;
}

void petscVecCreate_World(struct0_T *vec, int *errCode, boolean_T *topleve)
{
  MPI_Comm obj;
  Vec t_vec;
  emxArray_uint8_T *data0;
  int sizepe;
  int i;
  char t0_type[3];
  static const char cv2[3] = { 'V', 'e', 'c' };

  int loop_ub;
  char * ptr;
  obj = PETSC_COMM_WORLD;
  *errCode = VecCreate(obj, &t_vec);
  if (*errCode != 0) {
    b_m2c_error(*errCode);
  }

  emxInit_uint8_T(&data0, 1);
  sizepe = sizeof(Vec);
  i = data0->size[0];
  data0->size[0] = sizepe;
  emxEnsureCapacity_uint8_T(data0, i);
  for (i = 0; i < 3; i++) {
    t0_type[i] = cv2[i];
  }

  i = vec->data->size[0];
  vec->data->size[0] = data0->size[0];
  emxEnsureCapacity_uint8_T(vec->data, i);
  loop_ub = data0->size[0];
  for (i = 0; i < loop_ub; i++) {
    vec->data->data[i] = data0->data[i];
  }

  emxFree_uint8_T(&data0);
  i = vec->type->size[0] * vec->type->size[1];
  vec->type->size[0] = 1;
  vec->type->size[1] = 3;
  emxEnsureCapacity_char_T(vec->type, i);
  for (i = 0; i < 3; i++) {
    vec->type->data[i] = t0_type[i];
  }

  vec->nitems = 1;
  ptr = (char *)(&t_vec);
  for (i = 1; i <= sizepe; i++) {
    vec->data->data[i - 1] = *(ptr);
    ptr = ptr + 1;
  }

  *topleve = true;
}

void petscVecCreate_initialize(void)
{
}

void petscVecCreate_terminate(void)
{
}
