#include "petscVecNorm.h"
#include "m2c.h"
#include "petsc4m.h"

static void b_m2c_error(int varargin_3);
static void m2c_error(const emxArray_char_T *varargin_3);
static void b_m2c_error(int varargin_3)
{
  const char * msgid;
  const char * fmt;
  msgid = "petsc:RuntimeError";
  fmt = "VecNorm returned error code %d\n";
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
  fmt = "Incorrect data type %s. Expected Vec.\n";
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

void petscVecNorm(const struct0_T *x, int type, double nrm[2], int *errCode,
                  boolean_T *toplevel)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  boolean_T exitg1;
  emxArray_char_T *b_x;
  static const char cv1[3] = { 'V', 'e', 'c' };

  emxArray_uint8_T *data;
  int loop_ub;
  Vec vec;
  p = false;
  b_p = false;
  if (x->type->size[1] == 3) {
    b_p = true;
  }

  if (b_p && (!(x->type->size[1] == 0))) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 3)) {
      if (!(x->type->data[k] == cv1[k])) {
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
    emxInit_char_T(&b_x, 2);
    k = b_x->size[0] * b_x->size[1];
    b_x->size[0] = 1;
    b_x->size[1] = x->type->size[1] + 1;
    emxEnsureCapacity_char_T(b_x, k);
    loop_ub = x->type->size[1];
    for (k = 0; k < loop_ub; k++) {
      b_x->data[b_x->size[0] * k] = x->type->data[x->type->size[0] * k];
    }

    b_x->data[b_x->size[0] * x->type->size[1]] = '\x00';
    m2c_error(b_x);
    emxFree_char_T(&b_x);
  }

  emxInit_uint8_T(&data, 1);
  k = data->size[0];
  data->size[0] = x->data->size[0];
  emxEnsureCapacity_uint8_T(data, k);
  loop_ub = x->data->size[0];
  for (k = 0; k < loop_ub; k++) {
    data->data[k] = x->data->data[k];
  }

  vec = *(Vec*)(&data->data[0]);
  *errCode = VecNorm(vec, type, nrm);
  *toplevel = true;
  emxFree_uint8_T(&data);
  if (*errCode != 0) {
    b_m2c_error(*errCode);
  }
}

void petscVecNorm_2args(const struct0_T *x, int type, double *nrm, int *errCode,
  boolean_T *toplevel)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  boolean_T exitg1;
  emxArray_char_T *b_x;
  static const char cv0[3] = { 'V', 'e', 'c' };

  emxArray_uint8_T *data;
  int loop_ub;
  Vec vec;
  p = false;
  b_p = false;
  if (x->type->size[1] == 3) {
    b_p = true;
  }

  if (b_p && (!(x->type->size[1] == 0))) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 3)) {
      if (!(x->type->data[k] == cv0[k])) {
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
    emxInit_char_T(&b_x, 2);
    k = b_x->size[0] * b_x->size[1];
    b_x->size[0] = 1;
    b_x->size[1] = x->type->size[1] + 1;
    emxEnsureCapacity_char_T(b_x, k);
    loop_ub = x->type->size[1];
    for (k = 0; k < loop_ub; k++) {
      b_x->data[b_x->size[0] * k] = x->type->data[x->type->size[0] * k];
    }

    b_x->data[b_x->size[0] * x->type->size[1]] = '\x00';
    m2c_error(b_x);
    emxFree_char_T(&b_x);
  }

  emxInit_uint8_T(&data, 1);
  k = data->size[0];
  data->size[0] = x->data->size[0];
  emxEnsureCapacity_uint8_T(data, k);
  loop_ub = x->data->size[0];
  for (k = 0; k < loop_ub; k++) {
    data->data[k] = x->data->data[k];
  }

  vec = *(Vec*)(&data->data[0]);
  *errCode = VecNorm(vec, type, nrm);
  emxFree_uint8_T(&data);
  if (*errCode != 0) {
    b_m2c_error(*errCode);
  }

  *toplevel = true;
}

void petscVecNorm_initialize(void)
{
}

void petscVecNorm_terminate(void)
{
}
