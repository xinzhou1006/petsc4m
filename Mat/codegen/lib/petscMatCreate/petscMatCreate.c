#include "petscMatCreate.h"
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
  fmt = "MatCreate returned error code %d\n";
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

void petscMatCreate(const struct0_T *comm, struct0_T *mat, int *errCode,
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
  Mat t_mat;
  int sizepe;
  char t1_type[3];
  static const char cv1[3] = { 'M', 'a', 't' };

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
  *errCode = MatCreate(t_comm, &t_mat);
  sizepe = sizeof(Mat);
  k = data0->size[0];
  data0->size[0] = sizepe;
  emxEnsureCapacity_uint8_T(data0, k);
  for (k = 0; k < 3; k++) {
    t1_type[k] = cv1[k];
  }

  k = mat->data->size[0];
  mat->data->size[0] = data0->size[0];
  emxEnsureCapacity_uint8_T(mat->data, k);
  loop_ub = data0->size[0];
  for (k = 0; k < loop_ub; k++) {
    mat->data->data[k] = data0->data[k];
  }

  emxFree_uint8_T(&data0);
  k = mat->type->size[0] * mat->type->size[1];
  mat->type->size[0] = 1;
  mat->type->size[1] = 3;
  emxEnsureCapacity_char_T(mat->type, k);
  for (k = 0; k < 3; k++) {
    mat->type->data[k] = t1_type[k];
  }

  mat->nitems = 1;
  ptr = (char *)(&t_mat);
  for (k = 1; k <= sizepe; k++) {
    mat->data->data[k - 1] = *(ptr);
    ptr = ptr + 1;
  }

  if (*errCode != 0) {
    b_m2c_error(*errCode);
  }

  *toplevel = true;
}

void petscMatCreate_World(struct0_T *mat, int *errCode, boolean_T *topleve)
{
  emxArray_uint8_T *data0;
  MPI_Comm obj;
  Mat t_mat;
  int sizepe;
  int i;
  char t0_type[3];
  static const char cv2[3] = { 'M', 'a', 't' };

  int loop_ub;
  char * ptr;
  emxInit_uint8_T(&data0, 1);
  obj = PETSC_COMM_WORLD;
  *errCode = MatCreate(obj, &t_mat);
  sizepe = sizeof(Mat);
  i = data0->size[0];
  data0->size[0] = sizepe;
  emxEnsureCapacity_uint8_T(data0, i);
  for (i = 0; i < 3; i++) {
    t0_type[i] = cv2[i];
  }

  i = mat->data->size[0];
  mat->data->size[0] = data0->size[0];
  emxEnsureCapacity_uint8_T(mat->data, i);
  loop_ub = data0->size[0];
  for (i = 0; i < loop_ub; i++) {
    mat->data->data[i] = data0->data[i];
  }

  emxFree_uint8_T(&data0);
  i = mat->type->size[0] * mat->type->size[1];
  mat->type->size[0] = 1;
  mat->type->size[1] = 3;
  emxEnsureCapacity_char_T(mat->type, i);
  for (i = 0; i < 3; i++) {
    mat->type->data[i] = t0_type[i];
  }

  mat->nitems = 1;
  ptr = (char *)(&t_mat);
  for (i = 1; i <= sizepe; i++) {
    mat->data->data[i - 1] = *(ptr);
    ptr = ptr + 1;
  }

  if (*errCode != 0) {
    b_m2c_error(*errCode);
  }

  *topleve = true;
}

void petscMatCreate_initialize(void)
{
}

void petscMatCreate_terminate(void)
{
}
