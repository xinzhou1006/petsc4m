#include "petscOptionsSetInt.h"
#include "mpetsc.h"
#include "m2c.h"

static void b_m2c_error(int varargin_3);
static void m2c_error(void);
static void b_m2c_error(int varargin_3)
{
  M2C_error("petsc:RuntimeError",
            "PetscOptionsSetValue returned error code %d\n", varargin_3);
}

static void m2c_error(void)
{
  M2C_error("MPETSc:petscOptionsSetInt:InputError",
            "Argument name must be a null-terminated string.");
}

void emxInitArray_char_T(emxArray_char_T **pEmxArray, int numDimensions)
{
  emxInit_char_T(pEmxArray, numDimensions);
}

void petscOptionsSetInt(const emxArray_char_T *iname, int value, int *errCode,
  boolean_T *toplevel)
{
  unsigned char t_str[20];
  char * ptr;
  char str[20];
  int i;
  *toplevel = true;
  if ((!(iname->size[1] == 0)) && (iname->data[iname->size[1] - 1] != '\x00')) {
    m2c_error();
  }

  ptr = (char *)(t_str);
  sprintf(ptr, "%d", value);
  for (i = 0; i < 20; i++) {
    str[i] = (signed char)t_str[i];
  }

  *errCode = PetscOptionsSetValue(NULL, &iname->data[0], str);
  if (*errCode != 0) {
    b_m2c_error(*errCode);
  }
}

void petscOptionsSetInt_initialize(void)
{
}

void petscOptionsSetInt_terminate(void)
{
}