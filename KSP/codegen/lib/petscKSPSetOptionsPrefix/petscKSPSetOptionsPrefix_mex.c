/*
 * KSP/codegen/lib/petscKSPSetOptionsPrefix/petscKSPSetOptionsPrefix_mex.c
 *
 * Auxiliary code for mexFunction of petscKSPSetOptionsPrefix
 *
 * C source code generated by m2c.
 * %#m2c options: codegenArgs=-args {PetscKSP, coder.typeof(char(0), [1, inf])} enableInline=1 presVars=None dynMem=Threshold
 *
 */

#ifdef MATLAB_MEX_FILE
#include "mex.h"
#else
#include "matrix.h"
#endif
/* Include the C file generated by codegen in lib mode */
#include "petscKSPSetOptionsPrefix.h"
#include "m2c.c"
/* Include declaration of some helper functions. */
#include "lib2mex_helper.c"

void petscKSPSetOptionsPrefix_api(const mxArray ** prhs, const mxArray **plhs) {

    emxArray_char_T      prefix;

    struct0_T            ksp;
    mxArray              *_sub_mx1;

    int32_T              *errCode;
    boolean_T            *toplevel;

    /* Marshall in function inputs */

    if (!mxIsStruct(prhs[0]))
        mexErrMsgIdAndTxt("petscKSPSetOptionsPrefix:WrongInputType",
            "Input argument ksp has incorrect data type. struct is expected.");
    if (mxGetNumberOfFields(prhs[0])!=3)
        mexErrMsgIdAndTxt("petscKSPSetOptionsPrefix:InputStructWrongFields",
            "Input argument ksp has incorrect number of fields.");
    if (mxGetNumberOfElements(prhs[0]) != 1)
        mexErrMsgIdAndTxt("petscKSPSetOptionsPrefix:WrongSizeOfInputArg",
            "Argument ksp must contain 1 items.");

    _sub_mx1 = mxGetField(prhs[0], 0, "data");
    if (_sub_mx1==NULL)
        mexErrMsgIdAndTxt("petscKSPSetOptionsPrefix:WrongInputStruct",
            "Input argument ksp does not have the field data.");
    if (mxGetNumberOfElements(_sub_mx1) && mxGetClassID(_sub_mx1) != mxUINT8_CLASS)
        mexErrMsgIdAndTxt("petscKSPSetOptionsPrefix:WrongInputType",
            "Input argument ksp.data has incorrect data type. uint8 is expected.");
    *(void**)&ksp.data = mxCalloc(1, sizeof(emxArray__common));
    alias_mxArray_to_emxArray(_sub_mx1, (emxArray__common*)ksp.data, "ksp.data", 1);
    _sub_mx1 = mxGetField(prhs[0], 0, "type");
    if (_sub_mx1==NULL)
        mexErrMsgIdAndTxt("petscKSPSetOptionsPrefix:WrongInputStruct",
            "Input argument ksp does not have the field type.");
    if (mxGetNumberOfElements(_sub_mx1) && mxGetClassID(_sub_mx1) != mxCHAR_CLASS)
        mexErrMsgIdAndTxt("petscKSPSetOptionsPrefix:WrongInputType",
            "Input argument ksp.type has incorrect data type. char is expected.");
    if (mxGetNumberOfElements(_sub_mx1) && mxGetDimensions(_sub_mx1)[0] != 1)
        mexErrMsgIdAndTxt("petscKSPSetOptionsPrefix:WrongSizeOfInputArg",
            "Dimension 1 of ksp.type should be equal to 1.");
    *(void**)&ksp.type = mxCalloc(1, sizeof(emxArray__common));
    alias_mxArray_to_emxArray(_sub_mx1, (emxArray__common*)ksp.type, "ksp.type", 2);
    _sub_mx1 = mxGetField(prhs[0], 0, "nitems");
    if (_sub_mx1==NULL)
        mexErrMsgIdAndTxt("petscKSPSetOptionsPrefix:WrongInputStruct",
            "Input argument ksp does not have the field nitems.");
    if (mxGetNumberOfElements(_sub_mx1) && mxGetClassID(_sub_mx1) != mxINT32_CLASS)
        mexErrMsgIdAndTxt("petscKSPSetOptionsPrefix:WrongInputType",
            "Input argument ksp.nitems has incorrect data type. int32 is expected.");
    if (mxGetNumberOfElements(_sub_mx1) != 1)
        mexErrMsgIdAndTxt("petscKSPSetOptionsPrefix:WrongSizeOfInputArg",
            "Argument ksp.nitems should be a scalar.");
    ksp.nitems = *(int32_T*)mxGetData(_sub_mx1);
    if (mxGetNumberOfElements(prhs[1]) && mxGetClassID(prhs[1]) != mxCHAR_CLASS)
        mexErrMsgIdAndTxt("petscKSPSetOptionsPrefix:WrongInputType",
            "Input argument prefix has incorrect data type. char is expected.");
    if (mxGetNumberOfElements(prhs[1]) && mxGetDimensions(prhs[1])[0] != 1)
        mexErrMsgIdAndTxt("petscKSPSetOptionsPrefix:WrongSizeOfInputArg",
            "Dimension 1 of prefix should be equal to 1.");
    alias_mxArray_to_emxArray(prhs[1], (emxArray__common *)&prefix, "prefix", 2);

    /* Preallocate output variables */
    {mwSize l_size[] = {1, 1};
    *(void **)&errCode = prealloc_mxArray((mxArray**)&plhs[0], mxINT32_CLASS, 2, l_size); }
    {mwSize l_size[] = {1, 1};
    *(void **)&toplevel = prealloc_mxArray((mxArray**)&plhs[1], mxLOGICAL_CLASS, 2, l_size); }

    /* Invoke the target function */
    petscKSPSetOptionsPrefix_initialize();

    petscKSPSetOptionsPrefix(&ksp, &prefix, errCode, toplevel);

    petscKSPSetOptionsPrefix_terminate();

    /* Marshall out function outputs */
    /* Nothing to do for plhs[0] */
    /* Nothing to do for plhs[1] */

    /* Free temporary variables */
    free_emxArray((emxArray__common*)ksp.type); mxFree(ksp.type);
    free_emxArray((emxArray__common*)ksp.data); mxFree(ksp.data);

    free_emxArray((emxArray__common*)&prefix);
}

void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[]) {
    /* Temporary copy for mex outputs. */
    mxArray *outputs[2];
    int i;
    int nOutputs = (nlhs < 1 ? 1 : nlhs);

    if (nrhs == 2) {
        if (nlhs > 2)
            mexErrMsgIdAndTxt("petscKSPSetOptionsPrefix:TooManyOutputArguments","Too many output arguments for entry-point petscKSPSetOptionsPrefix.");
        /* Call the API function. */
        petscKSPSetOptionsPrefix_api(prhs, (const mxArray**)outputs);
    }
    else
        mexErrMsgIdAndTxt("petscKSPSetOptionsPrefix:WrongNumberOfInputs","Incorrect number of input variables for entry-point petscKSPSetOptionsPrefix.");

    /* Copy over outputs to the caller. */
    for (i = 0; i < nOutputs; ++i) {
        plhs[i] = outputs[i];
    }
}