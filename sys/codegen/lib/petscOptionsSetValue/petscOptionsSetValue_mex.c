/*
 * sys/codegen/lib/petscOptionsSetValue/petscOptionsSetValue_mex.c
 *
 * Auxiliary code for mexFunction of petscOptionsSetValue
 *
 * C source code generated by m2c.
 * %#m2c options:7cc619a861a838387ac4013cef1fba81
 *
 */

#include "mex.h"
#if !defined(MATLAB_MEX_FILE) && defined(printf)
#undef printf
#endif
/* Include the C header file generated by codegen in lib mode */
#include "petscOptionsSetValue.h"
#include "m2c.c"

/* Include declaration of some helper functions. */
#include "lib2mex_helper.c"


static void __petscOptionsSetValue_api(mxArray **plhs, const mxArray ** prhs) {
    emxArray_char_T      iname;
    emxArray_char_T      value;
    int32_T             *errCode;
    boolean_T           *toplevel;

    /* Marshall in inputs and preallocate outputs */
    if (mxGetNumberOfElements(prhs[0]) && mxGetClassID(prhs[0]) != mxCHAR_CLASS)
        mexErrMsgIdAndTxt("petscOptionsSetValue:WrongInputType",
            "Input argument iname has incorrect data type; char is expected.");
    if (mxGetNumberOfElements(prhs[0]) && mxGetDimensions(prhs[0])[0] != 1) 
        mexErrMsgIdAndTxt("petscOptionsSetValue:WrongSizeOfInputArg",
            "Dimension 1 of iname should equal 1.");
    alias_mxArray_to_emxArray(prhs[0], (emxArray__common *)(&iname), "iname", 2);

    if (mxGetNumberOfElements(prhs[1]) && mxGetClassID(prhs[1]) != mxCHAR_CLASS)
        mexErrMsgIdAndTxt("petscOptionsSetValue:WrongInputType",
            "Input argument value has incorrect data type; char is expected.");
    if (mxGetNumberOfElements(prhs[1]) && mxGetDimensions(prhs[1])[0] != 1) 
        mexErrMsgIdAndTxt("petscOptionsSetValue:WrongSizeOfInputArg",
            "Dimension 1 of value should equal 1.");
    alias_mxArray_to_emxArray(prhs[1], (emxArray__common *)(&value), "value", 2);

    errCode = mxMalloc(sizeof(int32_T));

    toplevel = mxMalloc(sizeof(boolean_T));

    /* Invoke the target function */
    petscOptionsSetValue(&iname, &value, errCode, toplevel);

    /* Deallocate input and marshall out function outputs */
    free_emxArray((emxArray__common*)(&iname));
    free_emxArray((emxArray__common*)(&value));
    plhs[0] = move_scalar_to_mxArray(errCode, mxINT32_CLASS);
    plhs[1] = move_scalar_to_mxArray(toplevel, mxLOGICAL_CLASS);

}


void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[]) {
    /* Temporary copy for mex outputs. */
    mxArray *outputs[2] = {NULL, NULL};
    int i;
    int nOutputs = (nlhs < 1 ? 1 : nlhs);

    if (nrhs == 2) {
        if (nlhs > 2)
            mexErrMsgIdAndTxt("petscOptionsSetValue:TooManyOutputArguments",
                "Too many output arguments for entry-point petscOptionsSetValue.\n");
        /* Call the API function. */
        __petscOptionsSetValue_api(outputs, prhs);
    }
    else
        mexErrMsgIdAndTxt("petscOptionsSetValue:WrongNumberOfInputs",
            "Incorrect number of input variables for entry-point petscOptionsSetValue.");

    /* Copy over outputs to the caller. */
    for (i = 0; i < nOutputs; ++i) {
        plhs[i] = outputs[i];
    }
}
