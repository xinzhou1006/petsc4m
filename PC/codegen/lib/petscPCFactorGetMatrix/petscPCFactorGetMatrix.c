#include "petscPCFactorGetMatrix.h"
#include "m2c.h"
#include "petsc4m.h"

static void b_m2c_error(int varargin_3);
static void m2c_error(const emxArray_char_T *varargin_3);
static void b_m2c_error(int varargin_3)
{
  const char * msgid;
  const char * fmt;
  msgid = "petsc:RuntimeError";
  fmt = "PCFactorGetMatrix returned error code %d\n";
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
  fmt = "Incorrect data type %s. Expected PC.\n";
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

void petscPCFactorGetMatrix(const struct0_T *pc, struct0_T *mat, int *errCode,
  boolean_T *toplevel)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  boolean_T exitg1;
  emxArray_char_T *b_pc;
  static const char cv0[2] = { 'P', 'C' };

  emxArray_uint8_T *data0;
  int loop_ub;
  PC c_pc;
  Mat t_mat;
  int sizepe;
  char t0_type[3];
  static const char cv1[3] = { 'M', 'a', 't' };

  char * ptr;
  p = false;
  b_p = false;
  if (pc->type->size[1] == 2) {
    b_p = true;
  }

  if (b_p && (!(pc->type->size[1] == 0))) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 2)) {
      if (!(pc->type->data[k] == cv0[k])) {
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
    emxInit_char_T(&b_pc, 2);
    k = b_pc->size[0] * b_pc->size[1];
    b_pc->size[0] = 1;
    b_pc->size[1] = pc->type->size[1] + 1;
    emxEnsureCapacity_char_T(b_pc, k);
    loop_ub = pc->type->size[1];
    for (k = 0; k < loop_ub; k++) {
      b_pc->data[b_pc->size[0] * k] = pc->type->data[pc->type->size[0] * k];
    }

    b_pc->data[b_pc->size[0] * pc->type->size[1]] = '\x00';
    m2c_error(b_pc);
    emxFree_char_T(&b_pc);
  }

  emxInit_uint8_T(&data0, 1);
  k = data0->size[0];
  data0->size[0] = pc->data->size[0];
  emxEnsureCapacity_uint8_T(data0, k);
  loop_ub = pc->data->size[0];
  for (k = 0; k < loop_ub; k++) {
    data0->data[k] = pc->data->data[k];
  }

  c_pc = *(PC*)(&data0->data[0]);
  *errCode = PCFactorGetMatrix(c_pc, &t_mat);
  sizepe = sizeof(Mat);
  k = data0->size[0];
  data0->size[0] = sizepe;
  emxEnsureCapacity_uint8_T(data0, k);
  for (k = 0; k < 3; k++) {
    t0_type[k] = cv1[k];
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
    mat->type->data[k] = t0_type[k];
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

void petscPCFactorGetMatrix_initialize(void)
{
}

void petscPCFactorGetMatrix_terminate(void)
{
}
