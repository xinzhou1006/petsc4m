/*
 * Vec/codegen/lib/petscVecGetOwnershipRange/petscVecGetOwnershipRange_mex.c
 *
 * Auxiliary code for mexFunction of petscVecGetOwnershipRange
 *
 * C source code generated by m2c.
 * %#m2c options: codegenArgs=-args {PetscVec} enableInline=1 presVars=None dynMem=Threshold
 *
 */

#ifdef MATLAB_MEX_FILE
#include "mex.h"
#else
#include "matrix.h"
#endif
/* Include the C file generated by codegen in lib mode */
#include "petscVecGetOwnershipRange.h"
#include "m2c.c"
/* Include declaration of some helper functions. */
#include "lib2mex_helper.c"

void petscVecGetOwnershipRange_api(const mxArray ** prhs, const mxArray **plhs) {

    struct0_T            vec;
    mxArray              *_sub_mx1;

    int32_T              *first_row;
    int32_T              *last_row;
    int32_T              *errCode;
    boolean_T            *toplevel;

    /* Marshall in function inputs */

    if (!mxIsStruct(prhs[0]))
        mexErrMsgIdAndTxt("petscVecGetOwnershipRange:WrongInputType",
            "Input argument vec has incorrect data type. struct is expected.");
    if (mxGetNumberOfFields(prhs[0])!=3)
        mexErrMsgIdAndTxt("petscVecGetOwnershipRange:InputStructWrongFields",
            "Input argument vec has incorrect number of fields.");
    if (mxGetNumberOfElements(prhs[0]) != 1)
        mexErrMsgIdAndTxt("petscVecGetOwnershipRange:WrongSizeOfInputArg",
            "Argument vec must contain 1 items.");

    _sub_mx1 = mxGetField(prhs[0], 0, "data");
    if (_sub_mx1==NULL)
        mexErrMsgIdAndTxt("petscVecGetOwnershipRange:WrongInputStruct",
            "Input argument vec does not have the field data.");
    if (mxGetNumberOfElements(_sub_mx1) && mxGetClassID(_sub_mx1) != mxUINT8_CLASS)
        mexErrMsgIdAndTxt("petscVecGetOwnershipRange:WrongInputType",
            "Input argument vec.data has incorrect data type. uint8 is expected.");
    *(void**)&vec.data = mxCalloc(1, sizeof(emxArray__common));
    alias_mxArray_to_emxArray(_sub_mx1, (emxArray__common*)vec.data, "vec.data", 1);
    _sub_mx1 = mxGetField(prhs[0], 0, "type");
    if (_sub_mx1==NULL)
        mexErrMsgIdAndTxt("petscVecGetOwnershipRange:WrongInputStruct",
            "Input argument vec does not have the field type.");
    if (mxGetNumberOfElements(_sub_mx1) && mxGetClassID(_sub_mx1) != mxCHAR_CLASS)
        mexErrMsgIdAndTxt("petscVecGetOwnershipRange:WrongInputType",
            "Input argument vec.type has incorrect data type. char is expected.");
    if (mxGetNumberOfElements(_sub_mx1) && mxGetDimensions(_sub_mx1)[0] != 1)
        mexErrMsgIdAndTxt("petscVecGetOwnershipRange:WrongSizeOfInputArg",
            "Dimension 1 of vec.type should be equal to 1.");
    *(void**)&vec.type = mxCalloc(1, sizeof(emxArray__common));
    alias_mxArray_to_emxArray(_sub_mx1, (emxArray__common*)vec.type, "vec.type", 2);
    _sub_mx1 = mxGetField(prhs[0], 0, "nitems");
    if (_sub_mx1==NULL)
        mexErrMsgIdAndTxt("petscVecGetOwnershipRange:WrongInputStruct",
            "Input argument vec does not have the field nitems.");
    if (mxGetNumberOfElements(_sub_mx1) && mxGetClassID(_sub_mx1) != mxINT32_CLASS)
        mexErrMsgIdAndTxt("petscVecGetOwnershipRange:WrongInputType",
            "Input argument vec.nitems has incorrect data type. int32 is expected.");
    if (mxGetNumberOfElements(_sub_mx1) != 1)
        mexErrMsgIdAndTxt("petscVecGetOwnershipRange:WrongSizeOfInputArg",
            "Argument vec.nitems should be a scalar.");
    vec.nitems = *(int32_T*)mxGetData(_sub_mx1);

    /* Preallocate output variables */
    {mwSize l_size[] = {1, 1};
    *(void **)&first_row = prealloc_mxArray((mxArray**)&plhs[0], mxINT32_CLASS, 2, l_size); }
    {mwSize l_size[] = {1, 1};
    *(void **)&last_row = prealloc_mxArray((mxArray**)&plhs[1], mxINT32_CLASS, 2, l_size); }
    {mwSize l_size[] = {1, 1};
    *(void **)&errCode = prealloc_mxArray((mxArray**)&plhs[2], mxINT32_CLASS, 2, l_size); }
    {mwSize l_size[] = {1, 1};
    *(void **)&toplevel = prealloc_mxArray((mxArray**)&plhs[3], mxLOGICAL_CLASS, 2, l_size); }

    /* Invoke the target function */
    petscVecGetOwnershipRange_initialize();

    petscVecGetOwnershipRange(&vec, first_row, last_row, errCode, toplevel);

    petscVecGetOwnershipRange_terminate();

    /* Marshall out function outputs */
    /* Nothing to do for plhs[0] */
    /* Nothing to do for plhs[1] */
    /* Nothing to do for plhs[2] */
    /* Nothing to do for plhs[3] */

    /* Free temporary variables */
    free_emxArray((emxArray__common*)vec.type); mxFree(vec.type);
    free_emxArray((emxArray__common*)vec.data); mxFree(vec.data);

}

void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[]) {
    /* Temporary copy for mex outputs. */
    mxArray *outputs[4];
    int i;
    int nOutputs = (nlhs < 1 ? 1 : nlhs);

    if (nrhs == 1) {
        if (nlhs > 4)
            mexErrMsgIdAndTxt("petscVecGetOwnershipRange:TooManyOutputArguments","Too many output arguments for entry-point petscVecGetOwnershipRange.");
        /* Call the API function. */
        petscVecGetOwnershipRange_api(prhs, (const mxArray**)outputs);
    }
    else
        mexErrMsgIdAndTxt("petscVecGetOwnershipRange:WrongNumberOfInputs","Incorrect number of input variables for entry-point petscVecGetOwnershipRange.");

    /* Copy over outputs to the caller. */
    for (i = 0; i < nOutputs; ++i) {
        plhs[i] = outputs[i];
    }
}