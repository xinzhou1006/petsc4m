/*
 * sys/codegen/lib/petscOptionsGetReal/petscOptionsGetReal_mex.c
 *
 * Auxiliary code for mexFunction of petscOptionsGetReal
 *
 * C source code generated by m2c.
 * %#m2c options: codegenArgs=-args {coder.typeof(char(0), [1,inf]), coder.typeof(char(0), [1,inf])} enableInline=1 presVars=None dynMem=Threshold
 *
 */

#ifdef MATLAB_MEX_FILE
#include "mex.h"
#else
#include "matrix.h"
#endif
/* Include the C header file generated by codegen in lib mode */
#include "petscOptionsGetReal.h"
#include "m2c.c"

/* Include declaration of some helper functions. */
#include "lib2mex_helper.c"

static void __petscOptionsGetReal_api(mxArray **plhs, const mxArray ** prhs) {

    emxArray_char_T      pre;
    emxArray_char_T      name;

    real64_T             *value;
    int32_T              *found;
    int32_T              *errCode;
    boolean_T            *toplevel;

    /* Marshall in function inputs */
    if (mxGetNumberOfElements(prhs[0]) && mxGetClassID(prhs[0]) != mxCHAR_CLASS)
        mexErrMsgIdAndTxt("petscOptionsGetReal:WrongInputType",
            "Input argument pre has incorrect data type; char is expected.");
    if (mxGetNumberOfElements(prhs[0]) && mxGetDimensions(prhs[0])[0] != 1)
        mexErrMsgIdAndTxt("petscOptionsGetReal:WrongSizeOfInputArg",
            "Dimension 1 of pre should be equal to 1.");
    alias_mxArray_to_emxArray(prhs[0], (emxArray__common *)&pre, "pre", 2);
    if (mxGetNumberOfElements(prhs[1]) && mxGetClassID(prhs[1]) != mxCHAR_CLASS)
        mexErrMsgIdAndTxt("petscOptionsGetReal:WrongInputType",
            "Input argument name has incorrect data type; char is expected.");
    if (mxGetNumberOfElements(prhs[1]) && mxGetDimensions(prhs[1])[0] != 1)
        mexErrMsgIdAndTxt("petscOptionsGetReal:WrongSizeOfInputArg",
            "Dimension 1 of name should be equal to 1.");
    alias_mxArray_to_emxArray(prhs[1], (emxArray__common *)&name, "name", 2);

    /* Preallocate output variables */
    {mwSize l_size[] = {1, 1};
    *(void **)&value = prealloc_mxArray((mxArray**)&plhs[0], mxDOUBLE_CLASS, 2, l_size); }
    {mwSize l_size[] = {1, 1};
    *(void **)&found = prealloc_mxArray((mxArray**)&plhs[1], mxINT32_CLASS, 2, l_size); }
    {mwSize l_size[] = {1, 1};
    *(void **)&errCode = prealloc_mxArray((mxArray**)&plhs[2], mxINT32_CLASS, 2, l_size); }
    {mwSize l_size[] = {1, 1};
    *(void **)&toplevel = prealloc_mxArray((mxArray**)&plhs[3], mxLOGICAL_CLASS, 2, l_size); }

    /* Invoke the target function */
    petscOptionsGetReal(&pre, &name, value, found, errCode, toplevel);

    /* Marshall out function outputs */
    /* Nothing to do for plhs[0] */
    /* Nothing to do for plhs[1] */
    /* Nothing to do for plhs[2] */
    /* Nothing to do for plhs[3] */

    /* Free temporary variables */
    free_emxArray((emxArray__common*)&pre);
    free_emxArray((emxArray__common*)&name);
}

void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[]) {
    /* Temporary copy for mex outputs. */
    mxArray *outputs[4];
    int i;
    int nOutputs = (nlhs < 1 ? 1 : nlhs);

    if (nrhs == 2) {
        if (nlhs > 4)
            mexErrMsgIdAndTxt("petscOptionsGetReal:TooManyOutputArguments",
                "Too many output arguments for entry-point petscOptionsGetReal.\n");
        /* Call the API function. */
        __petscOptionsGetReal_api(outputs, prhs);
    }
    else
        mexErrMsgIdAndTxt("petscOptionsGetReal:WrongNumberOfInputs",
            "Incorrect number of input variables for entry-point petscOptionsGetReal.");

    /* Copy over outputs to the caller. */
    for (i = 0; i < nOutputs; ++i) {
        plhs[i] = outputs[i];
    }
}