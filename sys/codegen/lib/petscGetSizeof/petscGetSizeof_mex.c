/*
 * sys/codegen/lib/petscGetSizeof/petscGetSizeof_mex.c
 *
 * Auxiliary code for mexFunction of petscGetSizeof
 *
 * C source code generated by m2c.
 * %#m2c options: codegenArgs=-args {coder.typeof(char(0),[1,inf])} enableInline=1 presVars=None dynMem=AllVariableSizeArrays
 *
 */

#ifdef MATLAB_MEX_FILE
#include "mex.h"
#else
#include "matrix.h"
#endif
/* Include the C header file generated by codegen in lib mode */
#include "petscGetSizeof.h"
#include "m2c.c"

/* Include declaration of some helper functions. */
#include "lib2mex_helper.c"

static void __petscGetSizeof_api(mxArray **plhs, const mxArray ** prhs) {

    emxArray_char_T      name;

    int32_T              *sz;
    boolean_T            *toplevel;

    /* Marshall in function inputs */
    if (mxGetNumberOfElements(prhs[0]) && mxGetClassID(prhs[0]) != mxCHAR_CLASS)
        mexErrMsgIdAndTxt("petscGetSizeof:WrongInputType",
            "Input argument name has incorrect data type; char is expected.");
    if (mxGetNumberOfElements(prhs[0]) && mxGetDimensions(prhs[0])[0] != 1)
        mexErrMsgIdAndTxt("petscGetSizeof:WrongSizeOfInputArg",
            "Dimension 1 of name should be equal to 1.");
    alias_mxArray_to_emxArray(prhs[0], (emxArray__common *)&name, "name", 2);

    /* Preallocate output variables */
    {mwSize l_size[] = {1, 1};
    *(void **)&sz = prealloc_mxArray((mxArray**)&plhs[0], mxINT32_CLASS, 2, l_size); }
    {mwSize l_size[] = {1, 1};
    *(void **)&toplevel = prealloc_mxArray((mxArray**)&plhs[1], mxLOGICAL_CLASS, 2, l_size); }

    /* Invoke the target function */
    petscGetSizeof(&name, sz, toplevel);

    /* Marshall out function outputs */
    /* Nothing to do for plhs[0] */
    /* Nothing to do for plhs[1] */

    /* Free temporary variables */
    free_emxArray((emxArray__common*)&name);
}

void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[]) {
    /* Temporary copy for mex outputs. */
    mxArray *outputs[2];
    int i;
    int nOutputs = (nlhs < 1 ? 1 : nlhs);

    if (nrhs == 1) {
        if (nlhs > 2)
            mexErrMsgIdAndTxt("petscGetSizeof:TooManyOutputArguments",
                "Too many output arguments for entry-point petscGetSizeof.\n");
        /* Call the API function. */
        __petscGetSizeof_api(outputs, prhs);
    }
    else
        mexErrMsgIdAndTxt("petscGetSizeof:WrongNumberOfInputs",
            "Incorrect number of input variables for entry-point petscGetSizeof.");

    /* Copy over outputs to the caller. */
    for (i = 0; i < nOutputs; ++i) {
        plhs[i] = outputs[i];
    }
}