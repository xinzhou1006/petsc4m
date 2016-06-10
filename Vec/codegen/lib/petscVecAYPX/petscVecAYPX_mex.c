/*
 * Vec/codegen/lib/petscVecAYPX/petscVecAYPX_mex.c
 *
 * Auxiliary code for mexFunction of petscVecAYPX
 *
 * C source code generated by m2c.
 * %#m2c options: codegenArgs=-args {PetscVec, 0, PetscVec} enableInline=1 presVars=None dynMem=Threshold
 *
 */

#ifdef MATLAB_MEX_FILE
#include "mex.h"
#else
#include "matrix.h"
#endif
/* Include the C header file generated by codegen in lib mode */
#include "petscVecAYPX.h"
#include "m2c.c"

/* Include declaration of some helper functions. */
#include "lib2mex_helper.c"

static void __petscVecAYPX_api(mxArray **plhs, const mxArray ** prhs) {

    struct0_T            y;
    struct0_T            x;
    mxArray              *_sub_mx1;

    real64_T             a;
    int32_T              *errCode;
    boolean_T            *toplevel;

    /* Marshall in function inputs */

    if (!mxIsStruct(prhs[0]))
        mexErrMsgIdAndTxt("petscVecAYPX:WrongInputType",
            "Input argument y has incorrect data type. struct is expected.");
    if (mxGetNumberOfFields(prhs[0])!=3)
        mexErrMsgIdAndTxt("petscVecAYPX:InputStructWrongFields",
            "Input argument y has incorrect number of fields.");
    if (mxGetNumberOfElements(prhs[0]) != 1)
        mexErrMsgIdAndTxt("petscVecAYPX:WrongSizeOfInputArg",
            "Argument y must contain 1 items.");

    _sub_mx1 = mxGetField(prhs[0], 0, "data");
    if (_sub_mx1==NULL)
        mexErrMsgIdAndTxt("petscVecAYPX:WrongInputStruct",
            "Input argument y does not have the field data.");
    if (mxGetNumberOfElements(_sub_mx1) && mxGetClassID(_sub_mx1) != mxUINT8_CLASS)
        mexErrMsgIdAndTxt("petscVecAYPX:WrongInputType",
            "Input argument y.data has incorrect data type. uint8 is expected.");
    *(void**)&y.data = mxCalloc(1, sizeof(emxArray__common));
    alias_mxArray_to_emxArray(_sub_mx1, (emxArray__common*)y.data, "y.data", 1);
    _sub_mx1 = mxGetField(prhs[0], 0, "type");
    if (_sub_mx1==NULL)
        mexErrMsgIdAndTxt("petscVecAYPX:WrongInputStruct",
            "Input argument y does not have the field type.");
    if (mxGetNumberOfElements(_sub_mx1) && mxGetClassID(_sub_mx1) != mxCHAR_CLASS)
        mexErrMsgIdAndTxt("petscVecAYPX:WrongInputType",
            "Input argument y.type has incorrect data type. char is expected.");
    if (mxGetNumberOfElements(_sub_mx1) && mxGetDimensions(_sub_mx1)[0] != 1)
        mexErrMsgIdAndTxt("petscVecAYPX:WrongSizeOfInputArg",
            "Dimension 1 of y.type should be equal to 1.");
    *(void**)&y.type = mxCalloc(1, sizeof(emxArray__common));
    alias_mxArray_to_emxArray(_sub_mx1, (emxArray__common*)y.type, "y.type", 2);
    _sub_mx1 = mxGetField(prhs[0], 0, "nitems");
    if (_sub_mx1==NULL)
        mexErrMsgIdAndTxt("petscVecAYPX:WrongInputStruct",
            "Input argument y does not have the field nitems.");
    if (mxGetNumberOfElements(_sub_mx1) && mxGetClassID(_sub_mx1) != mxINT32_CLASS)
        mexErrMsgIdAndTxt("petscVecAYPX:WrongInputType",
            "Input argument y.nitems has incorrect data type. int32 is expected.");
    if (mxGetNumberOfElements(_sub_mx1) != 1)
        mexErrMsgIdAndTxt("petscVecAYPX:WrongSizeOfInputArg",
            "Argument y.nitems should be a scalar.");
    y.nitems = *(int32_T*)mxGetData(_sub_mx1);
    if (mxGetNumberOfElements(prhs[1]) && mxGetClassID(prhs[1]) != mxDOUBLE_CLASS)
        mexErrMsgIdAndTxt("petscVecAYPX:WrongInputType",
            "Input argument a has incorrect data type; double is expected.");
    if (mxGetNumberOfElements(prhs[1]) != 1)
        mexErrMsgIdAndTxt("petscVecAYPX:WrongSizeOfInputArg",
            "Argument a should be a scalar.");
    a = *(real64_T*)mxGetData(prhs[1]);

    if (!mxIsStruct(prhs[2]))
        mexErrMsgIdAndTxt("petscVecAYPX:WrongInputType",
            "Input argument x has incorrect data type. struct is expected.");
    if (mxGetNumberOfFields(prhs[2])!=3)
        mexErrMsgIdAndTxt("petscVecAYPX:InputStructWrongFields",
            "Input argument x has incorrect number of fields.");
    if (mxGetNumberOfElements(prhs[2]) != 1)
        mexErrMsgIdAndTxt("petscVecAYPX:WrongSizeOfInputArg",
            "Argument x must contain 1 items.");

    _sub_mx1 = mxGetField(prhs[2], 0, "data");
    if (_sub_mx1==NULL)
        mexErrMsgIdAndTxt("petscVecAYPX:WrongInputStruct",
            "Input argument x does not have the field data.");
    if (mxGetNumberOfElements(_sub_mx1) && mxGetClassID(_sub_mx1) != mxUINT8_CLASS)
        mexErrMsgIdAndTxt("petscVecAYPX:WrongInputType",
            "Input argument x.data has incorrect data type. uint8 is expected.");
    *(void**)&x.data = mxCalloc(1, sizeof(emxArray__common));
    alias_mxArray_to_emxArray(_sub_mx1, (emxArray__common*)x.data, "x.data", 1);
    _sub_mx1 = mxGetField(prhs[2], 0, "type");
    if (_sub_mx1==NULL)
        mexErrMsgIdAndTxt("petscVecAYPX:WrongInputStruct",
            "Input argument x does not have the field type.");
    if (mxGetNumberOfElements(_sub_mx1) && mxGetClassID(_sub_mx1) != mxCHAR_CLASS)
        mexErrMsgIdAndTxt("petscVecAYPX:WrongInputType",
            "Input argument x.type has incorrect data type. char is expected.");
    if (mxGetNumberOfElements(_sub_mx1) && mxGetDimensions(_sub_mx1)[0] != 1)
        mexErrMsgIdAndTxt("petscVecAYPX:WrongSizeOfInputArg",
            "Dimension 1 of x.type should be equal to 1.");
    *(void**)&x.type = mxCalloc(1, sizeof(emxArray__common));
    alias_mxArray_to_emxArray(_sub_mx1, (emxArray__common*)x.type, "x.type", 2);
    _sub_mx1 = mxGetField(prhs[2], 0, "nitems");
    if (_sub_mx1==NULL)
        mexErrMsgIdAndTxt("petscVecAYPX:WrongInputStruct",
            "Input argument x does not have the field nitems.");
    if (mxGetNumberOfElements(_sub_mx1) && mxGetClassID(_sub_mx1) != mxINT32_CLASS)
        mexErrMsgIdAndTxt("petscVecAYPX:WrongInputType",
            "Input argument x.nitems has incorrect data type. int32 is expected.");
    if (mxGetNumberOfElements(_sub_mx1) != 1)
        mexErrMsgIdAndTxt("petscVecAYPX:WrongSizeOfInputArg",
            "Argument x.nitems should be a scalar.");
    x.nitems = *(int32_T*)mxGetData(_sub_mx1);

    /* Preallocate output variables */
    {mwSize l_size[] = {1, 1};
    *(void **)&errCode = prealloc_mxArray((mxArray**)&plhs[0], mxINT32_CLASS, 2, l_size); }
    {mwSize l_size[] = {1, 1};
    *(void **)&toplevel = prealloc_mxArray((mxArray**)&plhs[1], mxLOGICAL_CLASS, 2, l_size); }

    /* Invoke the target function */
    petscVecAYPX(&y, a, &x, errCode, toplevel);

    /* Marshall out function outputs */
    /* Nothing to do for plhs[0] */
    /* Nothing to do for plhs[1] */

    /* Free temporary variables */
    free_emxArray((emxArray__common*)y.type); mxFree(y.type);
    free_emxArray((emxArray__common*)y.data); mxFree(y.data);

    free_emxArray((emxArray__common*)x.type); mxFree(x.type);
    free_emxArray((emxArray__common*)x.data); mxFree(x.data);

}

void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[]) {
    /* Temporary copy for mex outputs. */
    mxArray *outputs[2];
    int i;
    int nOutputs = (nlhs < 1 ? 1 : nlhs);

    if (nrhs == 3) {
        if (nlhs > 2)
            mexErrMsgIdAndTxt("petscVecAYPX:TooManyOutputArguments",
                "Too many output arguments for entry-point petscVecAYPX.\n");
        /* Call the API function. */
        __petscVecAYPX_api(outputs, prhs);
    }
    else
        mexErrMsgIdAndTxt("petscVecAYPX:WrongNumberOfInputs",
            "Incorrect number of input variables for entry-point petscVecAYPX.");

    /* Copy over outputs to the caller. */
    for (i = 0; i < nOutputs; ++i) {
        plhs[i] = outputs[i];
    }
}