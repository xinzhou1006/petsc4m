#include "petscPCGetOptionsPrefix.h"
#include "m2c.h"
#include "petsc4m.h"

static void b_m2c_error(int varargin_3);
static void m2c_error(const emxArray_char_T *varargin_3);
static void b_m2c_error(int varargin_3)
{
  const char * msgid;
  const char * fmt;
  msgid = "petsc:RuntimeError";
  fmt = "PCGetOptionsPrefix returned error code %d\n";
  M2C_error(msgid, fmt, varargin_3);
}

static void m2c_error(const emxArray_char_T *varargin_3)
{
  emxArray_char_T *b_varargin_3;
  const char * msgid;
  const char * fmt;
  int i1;
  int loop_ub;
  emxInit_char_T(&b_varargin_3, 2);
  msgid = "m2c_opaque_obj:WrongInput";
  fmt = "Incorrect data type %s. Expected PC.\n";
  i1 = b_varargin_3->size[0] * b_varargin_3->size[1];
  b_varargin_3->size[0] = 1;
  b_varargin_3->size[1] = varargin_3->size[1];
  emxEnsureCapacity_char_T(b_varargin_3, i1);
  loop_ub = varargin_3->size[0] * varargin_3->size[1];
  for (i1 = 0; i1 < loop_ub; i1++) {
    b_varargin_3->data[i1] = varargin_3->data[i1];
  }

  M2C_error(msgid, fmt, &b_varargin_3->data[0]);
  emxFree_char_T(&b_varargin_3);
}

void petscPCGetOptionsPrefix(const struct0_T *pc, emxArray_char_T *str, int
  *errCode, boolean_T *toplevel)
{
  boolean_T p;
  boolean_T b_p;
  int noprefx;
  boolean_T exitg1;
  emxArray_char_T *b_pc;
  static const char cv0[2] = { 'P', 'C' };

  emxArray_uint8_T *data;
  int i0;
  PC t_pc;
  const char * str0;
  emxArray_uint8_T *str1;
  p = false;
  b_p = false;
  if (pc->type->size[1] == 2) {
    b_p = true;
  }

  if (b_p && (!(pc->type->size[1] == 0))) {
    noprefx = 0;
    exitg1 = false;
    while ((!exitg1) && (noprefx < 2)) {
      if (!(pc->type->data[noprefx] == cv0[noprefx])) {
        b_p = false;
        exitg1 = true;
      } else {
        noprefx++;
      }
    }
  }

  if (b_p) {
    p = true;
  }

  if (!p) {
    emxInit_char_T(&b_pc, 2);
    i0 = b_pc->size[0] * b_pc->size[1];
    b_pc->size[0] = 1;
    b_pc->size[1] = pc->type->size[1] + 1;
    emxEnsureCapacity_char_T(b_pc, i0);
    noprefx = pc->type->size[1];
    for (i0 = 0; i0 < noprefx; i0++) {
      b_pc->data[b_pc->size[0] * i0] = pc->type->data[pc->type->size[0] * i0];
    }

    b_pc->data[b_pc->size[0] * pc->type->size[1]] = '\x00';
    m2c_error(b_pc);
    emxFree_char_T(&b_pc);
  }

  emxInit_uint8_T(&data, 1);
  i0 = data->size[0];
  data->size[0] = pc->data->size[0];
  emxEnsureCapacity_uint8_T(data, i0);
  noprefx = pc->data->size[0];
  for (i0 = 0; i0 < noprefx; i0++) {
    data->data[i0] = pc->data->data[i0];
  }

  t_pc = *(PC*)(&data->data[0]);
  *errCode = PCGetOptionsPrefix(t_pc, &str0);
  emxFree_uint8_T(&data);
  if (*errCode != 0) {
    b_m2c_error(*errCode);
  }

  noprefx = !(str0);
  emxInit_uint8_T(&str1, 2);
  if (!(noprefx != 0)) {
    noprefx = strlen(str0) + 1;
    i0 = str1->size[0] * str1->size[1];
    str1->size[0] = 1;
    str1->size[1] = noprefx;
    emxEnsureCapacity_uint8_T(str1, i0);
    for (i0 = 0; i0 < noprefx; i0++) {
      str1->data[i0] = 0;
    }

    memcpy(&str1->data[0], str0, noprefx);
  } else {
    i0 = str1->size[0] * str1->size[1];
    str1->size[0] = 1;
    str1->size[1] = 0;
    emxEnsureCapacity_uint8_T(str1, i0);
  }

  i0 = str->size[0] * str->size[1];
  str->size[0] = 1;
  str->size[1] = str1->size[1];
  emxEnsureCapacity_char_T(str, i0);
  noprefx = str1->size[1];
  for (i0 = 0; i0 < noprefx; i0++) {
    str->data[i0] = (signed char)str1->data[i0];
  }

  emxFree_uint8_T(&str1);
  *toplevel = true;
}

void petscPCGetOptionsPrefix_initialize(void)
{
}

void petscPCGetOptionsPrefix_terminate(void)
{
}
