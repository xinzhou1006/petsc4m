/*
 * KSP/codegen/lib/petscKSPGetType/petscKSPGetType_mex.c
 *
 * Auxiliary code for mexFunction of petscKSPGetType
 *
 * C source code generated by m2c.
 * %#m2c options: codegenArgs=-args {PetscKSP} enableInline=1 presVars=None dynMem=Threshold
 *
 */

#ifdef MATLAB_MEX_FILE
#include "mex.h"
#else
#include "matrix.h"
#endif
/* Include the C header file generated by codegen in lib mode */
#include "petscKSPGetType.h"
#include "m2c.c"

/* Include declaration of some helper functions. */
#include "lib2mex_helper.c"

static void __petscKSPGetType_api(mxArray **plhs, const mxArray ** prhs) {

    emxArray_char_T      type;

    struct0_T            ksp;
    mxArray              *_sub_mx1;

    int32_T              *errCode;
    boolean_T            *toplevel;

    /* Marshall in function inputs */

    if (!mxIsStruct(prhs[0]))
        mexErrMsgIdAndTxt("petscKSPGetType:WrongInputType",
            "Input argument ksp has incorrect data type. struct is expected.");
    if (mxGetNumberOfFields(prhs[0])!=3)
        mexErrMsgIdAndTxt("petscKSPGetType:InputStructWrongFields",
            "Input argument ksp has incorrect number of fields.");
    if (mxGetNumberOfElements(prhs[0]) != 1)
        mexErrMsgIdAndTxt("petscKSPGetType:WrongSizeOfInputArg",
            "Argument ksp must contain 1 items.");

    _sub_mx1 = mxGetField(prhs[0], 0, "data");
    if (_sub_mx1==NULL)
        mexErrMsgIdAndTxt("petscKSPGetType:WrongInputStruct",
            "Input argument ksp does not have the field data.");
    if (mxGetNumberOfElements(_sub_mx1) && mxGetClassID(_sub_mx1) != mxUINT8_CLASS)
        mexErrMsgIdAndTxt("petscKSPGetType:WrongInputType",
            "Input argument ksp.data has incorrect data type. uint8 is expected.");
    *(void**)&ksp.data = mxCalloc(1, sizeof(emxArray__common));
    alias_mxArray_to_emxArray(_sub_mx1, (emxArray__common*)ksp.data, "ksp.data", 1);
    _sub_mx1 = mxGetField(prhs[0], 0, "type");
    if (_sub_mx1==NULL)
        mexErrMsgIdAndTxt("petscKSPGetType:WrongInputStruct",
            "Input argument ksp does not have the field type.");
    if (mxGetNumberOfElements(_sub_mx1) && mxGetClassID(_sub_mx1) != mxCHAR_CLASS)
        mexErrMsgIdAndTxt("petscKSPGetType:WrongInputType",
            "Input argument ksp.type has incorrect data type. char is expected.");
    if (mxGetNumberOfElements(_sub_mx1) && mxGetDimensions(_sub_mx1)[0] != 1)
        mexErrMsgIdAndTxt("petscKSPGetType:WrongSizeOfInputArg",
            "Dimension 1 of ksp.type should be equal to 1.");
    *(void**)&ksp.type = mxCalloc(1, sizeof(emxArray__common));
    alias_mxArray_to_emxArray(_sub_mx1, (emxArray__common*)ksp.type, "ksp.type", 2);
    _sub_mx1 = mxGetField(prhs[0], 0, "nitems");
    if (_sub_mx1==NULL)
        mexErrMsgIdAndTxt("petscKSPGetType:WrongInputStruct",
            "Input argument ksp does not have the field nitems.");
    if (mxGetNumberOfElements(_sub_mx1) && mxGetClassID(_sub_mx1) != mxINT32_CLASS)
        mexErrMsgIdAndTxt("petscKSPGetType:WrongInputType",
            "Input argument ksp.nitems has incorrect data type. int32 is expected.");
    if (mxGetNumberOfElements(_sub_mx1) != 1)
        mexErrMsgIdAndTxt("petscKSPGetType:WrongSizeOfInputArg",
            "Argument ksp.nitems should be a scalar.");
    ksp.nitems = *(int32_T*)mxGetData(_sub_mx1);

    /* Preallocate output variables */
    init_emxArray((emxArray__common*)&type, 2);
    {mwSize l_size[] = {1, 1};
    *(void **)&errCode = prealloc_mxArray((mxArray**)&plhs[1], mxINT32_CLASS, 2, l_size); }
    {mwSize l_size[] = {1, 1};
    *(void **)&toplevel = prealloc_mxArray((mxArray**)&plhs[2], mxLOGICAL_CLASS, 2, l_size); }

    /* Invoke the target function */
    petscKSPGetType(&ksp, &type, errCode, toplevel);

    /* Marshall out function outputs */
    plhs[0] = move_emxArray_to_mxArray((emxArray__common*)&type, mxCHAR_CLASS);

    /* Nothing to do for plhs[1] */
    /* Nothing to do for plhs[2] */

    /* Free temporary variables */
    free_emxArray((emxArray__common*)ksp.type); mxFree(ksp.type);
    free_emxArray((emxArray__common*)ksp.data); mxFree(ksp.data);

    free_emxArray((emxArray__common*)&type);
}

void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[]) {
    /* Temporary copy for mex outputs. */
    mxArray *outputs[3];
    int i;
    int nOutputs = (nlhs < 1 ? 1 : nlhs);

    if (nrhs == 1) {
        if (nlhs > 3)
            mexErrMsgIdAndTxt("petscKSPGetType:TooManyOutputArguments",
                "Too many output arguments for entry-point petscKSPGetType.\n");
        /* Call the API function. */
        __petscKSPGetType_api(outputs, prhs);
    }
    else
        mexErrMsgIdAndTxt("petscKSPGetType:WrongNumberOfInputs",
            "Incorrect number of input variables for entry-point petscKSPGetType.");

    /* Copy over outputs to the caller. */
    for (i = 0; i < nOutputs; ++i) {
        plhs[i] = outputs[i];
    }
}