/*
 * mpi/codegen/lib/mpi_Init/mpi_Init_mex.c
 *
 * Auxiliary code for mexFunction of mpi_Init
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
#include "mpi_Init.h"
#include "m2c.c"
/* Include declaration of some helper functions. */
#include "lib2mex_helper.c"

void mpi_Init_api(const mxArray ** prhs, const mxArray **plhs) {

    int32_T              *info;
    boolean_T            *toplevel;

    /* Preallocate output variables */
    {mwSize l_size[] = {1, 1};
    *(void **)&info = prealloc_mxArray((mxArray**)&plhs[0], mxINT32_CLASS, 2, l_size); }
    {mwSize l_size[] = {1, 1};
    *(void **)&toplevel = prealloc_mxArray((mxArray**)&plhs[1], mxLOGICAL_CLASS, 2, l_size); }

    /* Invoke the target function */
    mpi_Init_initialize();

    mpi_Init(info, toplevel);

    mpi_Init_terminate();

    /* Marshall out function outputs */
    /* Nothing to do for plhs[0] */
    /* Nothing to do for plhs[1] */

}

void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[]) {
    /* Temporary copy for mex outputs. */
    mxArray *outputs[2];
    int i;
    int nOutputs = (nlhs < 1 ? 1 : nlhs);

    if (nrhs == 0) {
        if (nlhs > 2)
            mexErrMsgIdAndTxt("mpi_Init:TooManyOutputArguments","Too many output arguments for entry-point mpi_Init.");
        /* Call the API function. */
        mpi_Init_api(prhs, (const mxArray**)outputs);
    }
    else
        mexErrMsgIdAndTxt("mpi_Init:WrongNumberOfInputs","Incorrect number of input variables for entry-point mpi_Init.");

    /* Copy over outputs to the caller. */
    for (i = 0; i < nOutputs; ++i) {
        plhs[i] = outputs[i];
    }
}