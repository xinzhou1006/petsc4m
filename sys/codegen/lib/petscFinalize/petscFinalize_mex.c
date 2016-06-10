/*
 * sys/codegen/lib/petscFinalize/petscFinalize_mex.c
 *
 * Auxiliary code for mexFunction of petscFinalize
 *
 * C source code generated by m2c.
 * %#m2c options: codegenArgs=-args {} enableInline=1 presVars=None dynMem=Threshold
 *
 */

#ifdef MATLAB_MEX_FILE
#include "mex.h"
#else
#include "matrix.h"
#endif
/* Include the C header file generated by codegen in lib mode */
#include "petscFinalize.h"
#include "m2c.c"

/* Include declaration of some helper functions. */
#include "lib2mex_helper.c"

static void __petscFinalize_api(mxArray **plhs, const mxArray ** prhs) {

    int32_T              *errCode;
    boolean_T            *toplevel;

    /* Preallocate output variables */
    {mwSize l_size[] = {1, 1};
    *(void **)&errCode = prealloc_mxArray((mxArray**)&plhs[0], mxINT32_CLASS, 2, l_size); }
    {mwSize l_size[] = {1, 1};
    *(void **)&toplevel = prealloc_mxArray((mxArray**)&plhs[1], mxLOGICAL_CLASS, 2, l_size); }

    /* Invoke the target function */
    petscFinalize(errCode, toplevel);

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
            mexErrMsgIdAndTxt("petscFinalize:TooManyOutputArguments",
                "Too many output arguments for entry-point petscFinalize.\n");
        /* Call the API function. */
        __petscFinalize_api(outputs, prhs);
    }
    else
        mexErrMsgIdAndTxt("petscFinalize:WrongNumberOfInputs",
            "Incorrect number of input variables for entry-point petscFinalize.");

    /* Copy over outputs to the caller. */
    for (i = 0; i < nOutputs; ++i) {
        plhs[i] = outputs[i];
    }
}