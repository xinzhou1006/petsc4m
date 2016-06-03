/*
 * sys/codegen/lib/petscSplitOwnership/petscSplitOwnership_mex.c
 *
 * Auxiliary code for mexFunction of petscSplitOwnership
 *
 * C source code generated by m2c.
 * %#m2c options: codegenArgs=-args {MPI_Comm, int32(0), int32(0)} enableInline=1 presVars=None dynMem=Threshold
 *
 */

#ifdef MATLAB_MEX_FILE
#include "mex.h"
#else
#include "matrix.h"
#endif
/* Include the C file generated by codegen in lib mode */
#include "petscSplitOwnership.h"
#include "m2c.c"
/* Include declaration of some helper functions. */
#include "lib2mex_helper.c"

void petscSplitOwnership_api(const mxArray ** prhs, const mxArray **plhs) {

    struct0_T            comm;
    mxArray              *_sub_mx1;

    int32_T              *n;
    int32_T              *N;
    int32_T              *errCode;
    boolean_T            *toplevel;

    /* Marshall in function inputs */

    if (!mxIsStruct(prhs[0]))
        mexErrMsgIdAndTxt("petscSplitOwnership:WrongInputType",
            "Input argument comm has incorrect data type. struct is expected.");
    if (mxGetNumberOfFields(prhs[0])!=3)
        mexErrMsgIdAndTxt("petscSplitOwnership:InputStructWrongFields",
            "Input argument comm has incorrect number of fields.");
    if (mxGetNumberOfElements(prhs[0]) != 1)
        mexErrMsgIdAndTxt("petscSplitOwnership:WrongSizeOfInputArg",
            "Argument comm must contain 1 items.");

    _sub_mx1 = mxGetField(prhs[0], 0, "data");
    if (_sub_mx1==NULL)
        mexErrMsgIdAndTxt("petscSplitOwnership:WrongInputStruct",
            "Input argument comm does not have the field data.");
    if (mxGetNumberOfElements(_sub_mx1) && mxGetClassID(_sub_mx1) != mxUINT8_CLASS)
        mexErrMsgIdAndTxt("petscSplitOwnership:WrongInputType",
            "Input argument comm.data has incorrect data type. uint8 is expected.");
    *(void**)&comm.data = mxCalloc(1, sizeof(emxArray__common));
    alias_mxArray_to_emxArray(_sub_mx1, (emxArray__common*)comm.data, "comm.data", 1);
    _sub_mx1 = mxGetField(prhs[0], 0, "type");
    if (_sub_mx1==NULL)
        mexErrMsgIdAndTxt("petscSplitOwnership:WrongInputStruct",
            "Input argument comm does not have the field type.");
    if (mxGetNumberOfElements(_sub_mx1) && mxGetClassID(_sub_mx1) != mxCHAR_CLASS)
        mexErrMsgIdAndTxt("petscSplitOwnership:WrongInputType",
            "Input argument comm.type has incorrect data type. char is expected.");
    if (mxGetNumberOfElements(_sub_mx1) && mxGetDimensions(_sub_mx1)[0] != 1)
        mexErrMsgIdAndTxt("petscSplitOwnership:WrongSizeOfInputArg",
            "Dimension 1 of comm.type should be equal to 1.");
    *(void**)&comm.type = mxCalloc(1, sizeof(emxArray__common));
    alias_mxArray_to_emxArray(_sub_mx1, (emxArray__common*)comm.type, "comm.type", 2);
    _sub_mx1 = mxGetField(prhs[0], 0, "nitems");
    if (_sub_mx1==NULL)
        mexErrMsgIdAndTxt("petscSplitOwnership:WrongInputStruct",
            "Input argument comm does not have the field nitems.");
    if (mxGetNumberOfElements(_sub_mx1) && mxGetClassID(_sub_mx1) != mxINT32_CLASS)
        mexErrMsgIdAndTxt("petscSplitOwnership:WrongInputType",
            "Input argument comm.nitems has incorrect data type. int32 is expected.");
    if (mxGetNumberOfElements(_sub_mx1) != 1)
        mexErrMsgIdAndTxt("petscSplitOwnership:WrongSizeOfInputArg",
            "Argument comm.nitems should be a scalar.");
    comm.nitems = *(int32_T*)mxGetData(_sub_mx1);
    plhs[0] = mxDuplicateArray(prhs[1]);
    if (mxGetNumberOfElements(plhs[0]) && mxGetClassID(plhs[0]) != mxINT32_CLASS)
        mexErrMsgIdAndTxt("petscSplitOwnership:WrongInputType",
            "Input argument n has incorrect data type. int32 is expected.");
    if (mxGetNumberOfElements(plhs[0]) != 1)
        mexErrMsgIdAndTxt("petscSplitOwnership:WrongSizeOfInputArg",
            "Argument n should be a scalar.");
    n = (int32_T*)mxGetData(plhs[0]);
    plhs[1] = mxDuplicateArray(prhs[2]);
    if (mxGetNumberOfElements(plhs[1]) && mxGetClassID(plhs[1]) != mxINT32_CLASS)
        mexErrMsgIdAndTxt("petscSplitOwnership:WrongInputType",
            "Input argument N has incorrect data type. int32 is expected.");
    if (mxGetNumberOfElements(plhs[1]) != 1)
        mexErrMsgIdAndTxt("petscSplitOwnership:WrongSizeOfInputArg",
            "Argument N should be a scalar.");
    N = (int32_T*)mxGetData(plhs[1]);

    /* Preallocate output variables */
    {mwSize l_size[] = {1, 1};
    *(void **)&errCode = prealloc_mxArray((mxArray**)&plhs[2], mxINT32_CLASS, 2, l_size); }
    {mwSize l_size[] = {1, 1};
    *(void **)&toplevel = prealloc_mxArray((mxArray**)&plhs[3], mxLOGICAL_CLASS, 2, l_size); }

    /* Invoke the target function */
    petscSplitOwnership_initialize();

    petscSplitOwnership(&comm, n, N, errCode, toplevel);

    petscSplitOwnership_terminate();

    /* Marshall out function outputs */
    /* Nothing to do for plhs[0] */
    /* Nothing to do for plhs[1] */
    /* Nothing to do for plhs[2] */
    /* Nothing to do for plhs[3] */

    /* Free temporary variables */
    free_emxArray((emxArray__common*)comm.type); mxFree(comm.type);
    free_emxArray((emxArray__common*)comm.data); mxFree(comm.data);

}

void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[]) {
    /* Temporary copy for mex outputs. */
    mxArray *outputs[4];
    int i;
    int nOutputs = (nlhs < 1 ? 1 : nlhs);

    if (nrhs == 3) {
        if (nlhs > 4)
            mexErrMsgIdAndTxt("petscSplitOwnership:TooManyOutputArguments","Too many output arguments for entry-point petscSplitOwnership.");
        /* Call the API function. */
        petscSplitOwnership_api(prhs, (const mxArray**)outputs);
    }
    else
        mexErrMsgIdAndTxt("petscSplitOwnership:WrongNumberOfInputs","Incorrect number of input variables for entry-point petscSplitOwnership.");

    /* Copy over outputs to the caller. */
    for (i = 0; i < nOutputs; ++i) {
        plhs[i] = outputs[i];
    }
}