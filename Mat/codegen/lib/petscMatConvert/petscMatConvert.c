#include "petscMatConvert.h"
#include "m2c.h"
#include "petsc4m.h"

static void b_m2c_error(int varargin_3);
static void m2c_error(const emxArray_char_T *varargin_3);
static void b_m2c_error(int varargin_3)
{
  const char * msgid;
  const char * fmt;
  msgid = "petsc:RuntimeError";
  fmt = "MatConvert returned error code %d\n";
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
  fmt = "Incorrect data type %s. Expected Mat.\n";
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

void petscMatConvert(const struct0_T *mat_in, const emxArray_char_T *newtype,
                     int reuse, struct0_T *mat_out, int *errCode, boolean_T
                     *toplevel)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  boolean_T exitg1;
  emxArray_char_T *b_mat_in;
  static const char cv0[3] = { 'M', 'a', 't' };

  emxArray_uint8_T *data0;
  int loop_ub;
  Mat mat;
  Mat t_mat_out;
  int sizepe;
  char t0_type[3];
  static const char x2[3] = { 'M', 'a', 't' };

  char * ptr;
  p = false;
  b_p = false;
  if (mat_in->type->size[1] == 3) {
    b_p = true;
  }

  if (b_p && (!(mat_in->type->size[1] == 0))) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 3)) {
      if (!(mat_in->type->data[k] == cv0[k])) {
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
    emxInit_char_T(&b_mat_in, 2);
    k = b_mat_in->size[0] * b_mat_in->size[1];
    b_mat_in->size[0] = 1;
    b_mat_in->size[1] = mat_in->type->size[1] + 1;
    emxEnsureCapacity_char_T(b_mat_in, k);
    loop_ub = mat_in->type->size[1];
    for (k = 0; k < loop_ub; k++) {
      b_mat_in->data[b_mat_in->size[0] * k] = mat_in->type->data[mat_in->
        type->size[0] * k];
    }

    b_mat_in->data[b_mat_in->size[0] * mat_in->type->size[1]] = '\x00';
    m2c_error(b_mat_in);
    emxFree_char_T(&b_mat_in);
  }

  emxInit_uint8_T(&data0, 1);
  k = data0->size[0];
  data0->size[0] = mat_in->data->size[0];
  emxEnsureCapacity_uint8_T(data0, k);
  loop_ub = mat_in->data->size[0];
  for (k = 0; k < loop_ub; k++) {
    data0->data[k] = mat_in->data->data[k];
  }

  mat = *(Mat*)(&data0->data[0]);
  *errCode = MatConvert(mat, &newtype->data[0], reuse, &t_mat_out);
  sizepe = sizeof(Mat);
  k = data0->size[0];
  data0->size[0] = sizepe;
  emxEnsureCapacity_uint8_T(data0, k);
  for (k = 0; k < 3; k++) {
    t0_type[k] = x2[k];
  }

  k = mat_out->data->size[0];
  mat_out->data->size[0] = data0->size[0];
  emxEnsureCapacity_uint8_T(mat_out->data, k);
  loop_ub = data0->size[0];
  for (k = 0; k < loop_ub; k++) {
    mat_out->data->data[k] = data0->data[k];
  }

  emxFree_uint8_T(&data0);
  k = mat_out->type->size[0] * mat_out->type->size[1];
  mat_out->type->size[0] = 1;
  mat_out->type->size[1] = 3;
  emxEnsureCapacity_char_T(mat_out->type, k);
  for (k = 0; k < 3; k++) {
    mat_out->type->data[k] = t0_type[k];
  }

  mat_out->nitems = 1;
  ptr = (char *)(&t_mat_out);
  for (k = 1; k <= sizepe; k++) {
    mat_out->data->data[k - 1] = *(ptr);
    ptr = ptr + 1;
  }

  if (*errCode != 0) {
    b_m2c_error(*errCode);
  }

  *toplevel = true;
}

void petscMatConvert_initialize(void)
{
}

void petscMatConvert_terminate(void)
{
}
