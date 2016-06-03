#include "petscMatGetInfo.h"
#include "m2c.h"
#include "mpetsc.h"

static void b_m2c_error(int varargin_3);
static void c_m2c_error(unsigned int varargin_4);
static void emxFreeStruct_struct0_T(struct0_T *pStruct);
static void emxInitStruct_struct0_T(struct0_T *pStruct);
static void m2c_error(const emxArray_char_T *varargin_3);
static void b_m2c_error(int varargin_3)
{
  const char * msgid;
  const char * fmt;
  msgid = "petsc:RuntimeError";
  fmt = "petscMatGetInfo returned error code %d\n";
  M2C_error(msgid, fmt, varargin_3);
}

static void c_m2c_error(unsigned int varargin_4)
{
  const char * msgid;
  const char * fmt;
  msgid = "petscMatGetInfo:WrongSize";
  fmt = "There are %d fields in PetscMatInfo but %d fields in MatInfo.";
  M2C_error(msgid, fmt, 10, varargin_4);
}

static void emxFreeStruct_struct0_T(struct0_T *pStruct)
{
  emxFree_uint8_T(&pStruct->data);
  emxFree_char_T(&pStruct->type);
}

static void emxInitStruct_struct0_T(struct0_T *pStruct)
{
  emxInit_uint8_T(&pStruct->data, 1);
  emxInit_char_T(&pStruct->type, 2);
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
  emxEnsureCapacity((emxArray__common *)b_varargin_3, i0, (int)sizeof(char));
  loop_ub = varargin_3->size[0] * varargin_3->size[1];
  for (i0 = 0; i0 < loop_ub; i0++) {
    b_varargin_3->data[i0] = varargin_3->data[i0];
  }

  M2C_error(msgid, fmt, &b_varargin_3->data[0]);
  emxFree_char_T(&b_varargin_3);
}

void emxDestroy_struct0_T(struct0_T emxArray)
{
  emxFreeStruct_struct0_T(&emxArray);
}

void emxInit_struct0_T(struct0_T *pStruct)
{
  emxInitStruct_struct0_T(pStruct);
}

void petscMatGetInfo(const struct0_T *mat, int flag, MPetscMatInfo *info, int
                     *errCode, boolean_T *toplevel)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  int exitg2;
  boolean_T exitg1;
  emxArray_char_T *b_mat;
  static const char cv0[3] = { 'M', 'a', 't' };

  emxArray_uint8_T *data;
  int loop_ub;
  Mat t_mat;
  MatInfo t_info;
  unsigned int nbytes;
  p = false;
  b_p = false;
  k = 0;
  do {
    exitg2 = 0;
    if (k < 2) {
      if (mat->type->size[k] != 1 + (k << 1)) {
        exitg2 = 1;
      } else {
        k++;
      }
    } else {
      b_p = true;
      exitg2 = 1;
    }
  } while (exitg2 == 0);

  if (b_p && (!(mat->type->size[1] == 0))) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 3)) {
      if (!(mat->type->data[k] == cv0[k])) {
        b_p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  if (!b_p) {
  } else {
    p = true;
  }

  if (!p) {
    emxInit_char_T(&b_mat, 2);
    k = b_mat->size[0] * b_mat->size[1];
    b_mat->size[0] = 1;
    b_mat->size[1] = mat->type->size[1] + 1;
    emxEnsureCapacity((emxArray__common *)b_mat, k, (int)sizeof(char));
    loop_ub = mat->type->size[1];
    for (k = 0; k < loop_ub; k++) {
      b_mat->data[b_mat->size[0] * k] = mat->type->data[mat->type->size[0] * k];
    }

    b_mat->data[b_mat->size[0] * mat->type->size[1]] = '\x00';
    m2c_error(b_mat);
    emxFree_char_T(&b_mat);
  }

  emxInit_uint8_T(&data, 1);
  k = data->size[0];
  data->size[0] = mat->data->size[0];
  emxEnsureCapacity((emxArray__common *)data, k, (int)sizeof(unsigned char));
  loop_ub = mat->data->size[0];
  for (k = 0; k < loop_ub; k++) {
    data->data[k] = mat->data->data[k];
  }

  t_mat = *(Mat*)(&data->data[0]);
  *errCode = MatGetInfo(t_mat, flag, &t_info);
  *toplevel = true;
  emxFree_uint8_T(&data);
  if (*errCode != 0) {
    b_m2c_error(*errCode);
  }

  nbytes = sizeof(t_info);
  if (80U < nbytes) {
    p = (M2C_DEBUG);
    if (p) {
      c_m2c_error(nbytes >> 3U);
    }
  }

  memcpy(info, &t_info, nbytes);
}

void petscMatGetInfo_Local(const struct0_T *mat, MPetscMatInfo *info, int
  *errCode)
{
  boolean_T p;
  boolean_T b_p;
  int flag;
  int exitg2;
  boolean_T exitg1;
  emxArray_char_T *b_mat;
  static const char cv1[3] = { 'M', 'a', 't' };

  emxArray_uint8_T *data;
  int loop_ub;
  Mat t_mat;
  MatInfo t_info;
  unsigned int nbytes;
  p = false;
  b_p = false;
  flag = 0;
  do {
    exitg2 = 0;
    if (flag < 2) {
      if (mat->type->size[flag] != 1 + (flag << 1)) {
        exitg2 = 1;
      } else {
        flag++;
      }
    } else {
      b_p = true;
      exitg2 = 1;
    }
  } while (exitg2 == 0);

  if (b_p && (!(mat->type->size[1] == 0))) {
    flag = 0;
    exitg1 = false;
    while ((!exitg1) && (flag < 3)) {
      if (!(mat->type->data[flag] == cv1[flag])) {
        b_p = false;
        exitg1 = true;
      } else {
        flag++;
      }
    }
  }

  if (!b_p) {
  } else {
    p = true;
  }

  if (!p) {
    emxInit_char_T(&b_mat, 2);
    flag = b_mat->size[0] * b_mat->size[1];
    b_mat->size[0] = 1;
    b_mat->size[1] = mat->type->size[1] + 1;
    emxEnsureCapacity((emxArray__common *)b_mat, flag, (int)sizeof(char));
    loop_ub = mat->type->size[1];
    for (flag = 0; flag < loop_ub; flag++) {
      b_mat->data[b_mat->size[0] * flag] = mat->type->data[mat->type->size[0] *
        flag];
    }

    b_mat->data[b_mat->size[0] * mat->type->size[1]] = '\x00';
    m2c_error(b_mat);
    emxFree_char_T(&b_mat);
  }

  emxInit_uint8_T(&data, 1);
  flag = data->size[0];
  data->size[0] = mat->data->size[0];
  emxEnsureCapacity((emxArray__common *)data, flag, (int)sizeof(unsigned char));
  loop_ub = mat->data->size[0];
  for (flag = 0; flag < loop_ub; flag++) {
    data->data[flag] = mat->data->data[flag];
  }

  t_mat = *(Mat*)(&data->data[0]);
  flag = (MAT_LOCAL);
  *errCode = MatGetInfo(t_mat, flag, &t_info);
  emxFree_uint8_T(&data);
  if (*errCode != 0) {
    p = (M2C_DEBUG);
    if (p) {
      b_m2c_error(*errCode);
    }
  }

  nbytes = sizeof(t_info);
  if (80U < nbytes) {
    p = (M2C_DEBUG);
    if (p) {
      c_m2c_error(nbytes >> 3U);
    }
  }

  memcpy(info, &t_info, nbytes);
}

void petscMatGetInfo_initialize(void)
{
}

void petscMatGetInfo_terminate(void)
{
}
