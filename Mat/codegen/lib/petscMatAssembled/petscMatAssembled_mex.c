/*
 * Mat/codegen/lib/petscMatAssembled/petscMatAssembled_mex.c
 *
 * Auxiliary code for mexFunction of petscMatAssembled
 *
 * C source code generated by m2c.
 * %#m2c options: codegenArgs=-args {PetscMat} enableInline=1 presVars=None dynMem=Threshold
 *
 */

#ifdef MATLAB_MEX_FILE
#include "mex.h"
#else
#include "matrix.h"
#endif
/* Include the C header file generated by codegen in lib mode */
#include "petscMatAssembled.h"
#include "m2c.c"

/* Include declaration of some helper functions. */
#include "lib2mex_helper.c"

static void __petscMatAssembled_api(mxArray **plhs, const mxArray ** prhs) {

    struct0_T            mat;
    mxArray              *_sub_mx1;

    int32_T              *assembled;
    int32_T              *errCode;
    boolean_T            *toplevel;

    /* Marshall in function inputs */

    if (!mxIsStruct(prhs[0]))
        mexErrMsgIdAndTxt("petscMatAssembled:WrongInputType",
            "Input argument mat has incorrect data type. struct is expected.");
    if (mxGetNumberOfFields(prhs[0])!=3)
        mexErrMsgIdAndTxt("petscMatAssembled:InputStructWrongFields",
            "Input argument mat has incorrect number of fields.");
    if (mxGetNumberOfElements(prhs[0]) != 1)
        mexErrMsgIdAndTxt("petscMatAssembled:WrongSizeOfInputArg",
            "Argument mat must contain 1 items.");

    _sub_mx1 = mxGetField(prhs[0], 0, "data");
    if (_sub_mx1==NULL)
        mexErrMsgIdAndTxt("petscMatAssembled:WrongInputStruct",
            "Input argument mat does not have the field data.");
    if (mxGetNumberOfElements(_sub_mx1) && mxGetClassID(_sub_mx1) != mxUINT8_CLASS)
        mexErrMsgIdAndTxt("petscMatAssembled:WrongInputType",
            "Input argument mat.data has incorrect data type. uint8 is expected.");
    *(void**)&mat.data = mxCalloc(1, sizeof(emxArray__common));
    alias_mxArray_to_emxArray(_sub_mx1, (emxArray__common*)mat.data, "mat.data", 1);
    _sub_mx1 = mxGetField(prhs[0], 0, "type");
    if (_sub_mx1==NULL)
        mexErrMsgIdAndTxt("petscMatAssembled:WrongInputStruct",
            "Input argument mat does not have the field type.");
    if (mxGetNumberOfElements(_sub_mx1) && mxGetClassID(_sub_mx1) != mxCHAR_CLASS)
        mexErrMsgIdAndTxt("petscMatAssembled:WrongInputType",
            "Input argument mat.type has incorrect data type. char is expected.");
    if (mxGetNumberOfElements(_sub_mx1) && mxGetDimensions(_sub_mx1)[0] != 1)
        mexErrMsgIdAndTxt("petscMatAssembled:WrongSizeOfInputArg",
            "Dimension 1 of mat.type should be equal to 1.");
    *(void**)&mat.type = mxCalloc(1, sizeof(emxArray__common));
    alias_mxArray_to_emxArray(_sub_mx1, (emxArray__common*)mat.type, "mat.type", 2);
    _sub_mx1 = mxGetField(prhs[0], 0, "nitems");
    if (_sub_mx1==NULL)
        mexErrMsgIdAndTxt("petscMatAssembled:WrongInputStruct",
            "Input argument mat does not have the field nitems.");
    if (mxGetNumberOfElements(_sub_mx1) && mxGetClassID(_sub_mx1) != mxINT32_CLASS)
        mexErrMsgIdAndTxt("petscMatAssembled:WrongInputType",
            "Input argument mat.nitems has incorrect data type. int32 is expected.");
    if (mxGetNumberOfElements(_sub_mx1) != 1)
        mexErrMsgIdAndTxt("petscMatAssembled:WrongSizeOfInputArg",
            "Argument mat.nitems should be a scalar.");
    mat.nitems = *(int32_T*)mxGetData(_sub_mx1);

    /* Preallocate output variables */
    {mwSize l_size[] = {1, 1};
    *(void **)&assembled = prealloc_mxArray((mxArray**)&plhs[0], mxINT32_CLASS, 2, l_size); }
    {mwSize l_size[] = {1, 1};
    *(void **)&errCode = prealloc_mxArray((mxArray**)&plhs[1], mxINT32_CLASS, 2, l_size); }
    {mwSize l_size[] = {1, 1};
    *(void **)&toplevel = prealloc_mxArray((mxArray**)&plhs[2], mxLOGICAL_CLASS, 2, l_size); }

    /* Invoke the target function */
    petscMatAssembled(&mat, assembled, errCode, toplevel);

    /* Marshall out function outputs */
    /* Nothing to do for plhs[0] */
    /* Nothing to do for plhs[1] */
    /* Nothing to do for plhs[2] */

    /* Free temporary variables */
    free_emxArray((emxArray__common*)mat.type); mxFree(mat.type);
    free_emxArray((emxArray__common*)mat.data); mxFree(mat.data);

}

void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[]) {
    /* Temporary copy for mex outputs. */
    mxArray *outputs[3];
    int i;
    int nOutputs = (nlhs < 1 ? 1 : nlhs);

    if (nrhs == 1) {
        if (nlhs > 3)
            mexErrMsgIdAndTxt("petscMatAssembled:TooManyOutputArguments",
                "Too many output arguments for entry-point petscMatAssembled.\n");
        /* Call the API function. */
        __petscMatAssembled_api(outputs, prhs);
    }
    else
        mexErrMsgIdAndTxt("petscMatAssembled:WrongNumberOfInputs",
            "Incorrect number of input variables for entry-point petscMatAssembled.");

    /* Copy over outputs to the caller. */
    for (i = 0; i < nOutputs; ++i) {
        plhs[i] = outputs[i];
    }
}