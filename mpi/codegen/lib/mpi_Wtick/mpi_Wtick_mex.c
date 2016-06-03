/*
 * mpi/codegen/lib/mpi_Wtick/mpi_Wtick_mex.c
 *
 * Auxiliary code for mexFunction of mpi_Wtick
 *
 * C source code generated by m2c.
 * %#m2c options: codegenArgs=-args {} enableInline=1 presVars=None dynMem=AllVariableSizeArrays
 *
 */

#ifdef MATLAB_MEX_FILE
#include "mex.h"
#else
#include "matrix.h"
#endif
/* Include the C file generated by codegen in lib mode */
#include "mpi_Wtick.h"
#include "m2c.c"
/* Include declaration of some helper functions. */
#include "lib2mex_helper.c"

void mpi_Wtick_api(const mxArray ** prhs, const mxArray **plhs) {

    real64_T             res;

    /* Preallocate output variables */

    /* Invoke the target function */
    mpi_Wtick_initialize();

    res = mpi_Wtick();

    mpi_Wtick_terminate();

    /* Marshall out function outputs */
    plhs[0] = copy_scalar_to_mxArray(&res, mxDOUBLE_CLASS);

}

void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[]) {
    if (nrhs == 0) {
        if (nlhs > 1)
            mexErrMsgIdAndTxt("mpi_Wtick:TooManyOutputArguments","Too many output arguments for entry-point mpi_Wtick.");
        /* Call the API function. */
        mpi_Wtick_api(prhs, (const mxArray**)plhs);
    }
    else
        mexErrMsgIdAndTxt("mpi_Wtick:WrongNumberOfInputs","Incorrect number of input variables for entry-point mpi_Wtick.");
}