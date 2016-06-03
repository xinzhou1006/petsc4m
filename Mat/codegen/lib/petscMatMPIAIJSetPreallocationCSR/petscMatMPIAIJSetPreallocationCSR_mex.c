/*
 * Mat/codegen/lib/petscMatMPIAIJSetPreallocationCSR/petscMatMPIAIJSetPreallocationCSR_mex.c
 *
 * Auxiliary code for mexFunction of petscMatMPIAIJSetPreallocationCSR
 *
 * C source code generated by m2c.
 * %#m2c options: codegenArgs=-args {PetscMat, coder.typeof(int32(0), [inf,1]), coder.typeof(int32(0), [inf,1]), coder.typeof(0, [inf,1])} petscMatMPIAIJSetPreallocationCSR_Indexonly -args {PetscMat, coder.typeof(int32(0), [inf,1]), coder.typeof(int32(0), [inf,1])} enableInline=1 presVars=None dynMem=Threshold
 *
 */

#ifdef MATLAB_MEX_FILE
#include "mex.h"
#else
#include "matrix.h"
#endif
/* Include the C file generated by codegen in lib mode */
#include "petscMatMPIAIJSetPreallocationCSR.h"
#include "m2c.c"
/* Include declaration of some helper functions. */
#include "lib2mex_helper.c"

void petscMatMPIAIJSetPreallocationCSR_api(const mxArray ** prhs, const mxArray **plhs) {

    emxArray_int32_T     ix;
    emxArray_int32_T     jx;
    emxArray_real_T      vs;

    struct0_T            mat;
    mxArray              *_sub_mx1;

    int32_T              *errCode;
    boolean_T            *toplevel;

    /* Marshall in function inputs */

    if (!mxIsStruct(prhs[0]))
        mexErrMsgIdAndTxt("petscMatMPIAIJSetPreallocationCSR:WrongInputType",
            "Input argument mat has incorrect data type. struct is expected.");
    if (mxGetNumberOfFields(prhs[0])!=3)
        mexErrMsgIdAndTxt("petscMatMPIAIJSetPreallocationCSR:InputStructWrongFields",
            "Input argument mat has incorrect number of fields.");
    if (mxGetNumberOfElements(prhs[0]) != 1)
        mexErrMsgIdAndTxt("petscMatMPIAIJSetPreallocationCSR:WrongSizeOfInputArg",
            "Argument mat must contain 1 items.");

    _sub_mx1 = mxGetField(prhs[0], 0, "data");
    if (_sub_mx1==NULL)
        mexErrMsgIdAndTxt("petscMatMPIAIJSetPreallocationCSR:WrongInputStruct",
            "Input argument mat does not have the field data.");
    if (mxGetNumberOfElements(_sub_mx1) && mxGetClassID(_sub_mx1) != mxUINT8_CLASS)
        mexErrMsgIdAndTxt("petscMatMPIAIJSetPreallocationCSR:WrongInputType",
            "Input argument mat.data has incorrect data type. uint8 is expected.");
    *(void**)&mat.data = mxCalloc(1, sizeof(emxArray__common));
    alias_mxArray_to_emxArray(_sub_mx1, (emxArray__common*)mat.data, "mat.data", 1);
    _sub_mx1 = mxGetField(prhs[0], 0, "type");
    if (_sub_mx1==NULL)
        mexErrMsgIdAndTxt("petscMatMPIAIJSetPreallocationCSR:WrongInputStruct",
            "Input argument mat does not have the field type.");
    if (mxGetNumberOfElements(_sub_mx1) && mxGetClassID(_sub_mx1) != mxCHAR_CLASS)
        mexErrMsgIdAndTxt("petscMatMPIAIJSetPreallocationCSR:WrongInputType",
            "Input argument mat.type has incorrect data type. char is expected.");
    if (mxGetNumberOfElements(_sub_mx1) && mxGetDimensions(_sub_mx1)[0] != 1)
        mexErrMsgIdAndTxt("petscMatMPIAIJSetPreallocationCSR:WrongSizeOfInputArg",
            "Dimension 1 of mat.type should be equal to 1.");
    *(void**)&mat.type = mxCalloc(1, sizeof(emxArray__common));
    alias_mxArray_to_emxArray(_sub_mx1, (emxArray__common*)mat.type, "mat.type", 2);
    _sub_mx1 = mxGetField(prhs[0], 0, "nitems");
    if (_sub_mx1==NULL)
        mexErrMsgIdAndTxt("petscMatMPIAIJSetPreallocationCSR:WrongInputStruct",
            "Input argument mat does not have the field nitems.");
    if (mxGetNumberOfElements(_sub_mx1) && mxGetClassID(_sub_mx1) != mxINT32_CLASS)
        mexErrMsgIdAndTxt("petscMatMPIAIJSetPreallocationCSR:WrongInputType",
            "Input argument mat.nitems has incorrect data type. int32 is expected.");
    if (mxGetNumberOfElements(_sub_mx1) != 1)
        mexErrMsgIdAndTxt("petscMatMPIAIJSetPreallocationCSR:WrongSizeOfInputArg",
            "Argument mat.nitems should be a scalar.");
    mat.nitems = *(int32_T*)mxGetData(_sub_mx1);
    if (mxGetNumberOfElements(prhs[1]) && mxGetClassID(prhs[1]) != mxINT32_CLASS)
        mexErrMsgIdAndTxt("petscMatMPIAIJSetPreallocationCSR:WrongInputType",
            "Input argument ix has incorrect data type. int32 is expected.");
    alias_mxArray_to_emxArray(prhs[1], (emxArray__common *)&ix, "ix", 1);
    if (mxGetNumberOfElements(prhs[2]) && mxGetClassID(prhs[2]) != mxINT32_CLASS)
        mexErrMsgIdAndTxt("petscMatMPIAIJSetPreallocationCSR:WrongInputType",
            "Input argument jx has incorrect data type. int32 is expected.");
    alias_mxArray_to_emxArray(prhs[2], (emxArray__common *)&jx, "jx", 1);
    if (mxGetNumberOfElements(prhs[3]) && mxGetClassID(prhs[3]) != mxDOUBLE_CLASS)
        mexErrMsgIdAndTxt("petscMatMPIAIJSetPreallocationCSR:WrongInputType",
            "Input argument vs has incorrect data type. double is expected.");
    alias_mxArray_to_emxArray(prhs[3], (emxArray__common *)&vs, "vs", 1);

    /* Preallocate output variables */
    {mwSize l_size[] = {1, 1};
    *(void **)&errCode = prealloc_mxArray((mxArray**)&plhs[0], mxINT32_CLASS, 2, l_size); }
    {mwSize l_size[] = {1, 1};
    *(void **)&toplevel = prealloc_mxArray((mxArray**)&plhs[1], mxLOGICAL_CLASS, 2, l_size); }

    /* Invoke the target function */
    petscMatMPIAIJSetPreallocationCSR_initialize();

    petscMatMPIAIJSetPreallocationCSR(&mat, &ix, &jx, &vs, errCode, toplevel);

    petscMatMPIAIJSetPreallocationCSR_terminate();

    /* Marshall out function outputs */
    /* Nothing to do for plhs[0] */
    /* Nothing to do for plhs[1] */

    /* Free temporary variables */
    free_emxArray((emxArray__common*)mat.type); mxFree(mat.type);
    free_emxArray((emxArray__common*)mat.data); mxFree(mat.data);

    free_emxArray((emxArray__common*)&ix);
    free_emxArray((emxArray__common*)&jx);
    free_emxArray((emxArray__common*)&vs);
}
void petscMatMPIAIJSetPreallocationCSR_Indexonly_api(const mxArray ** prhs, const mxArray **plhs) {

    emxArray_int32_T     ix;
    emxArray_int32_T     jx;

    struct0_T            mat;
    mxArray              *_sub_mx1;

    int32_T              *errCode;
    boolean_T            *toplevel;

    /* Marshall in function inputs */

    if (!mxIsStruct(prhs[0]))
        mexErrMsgIdAndTxt("petscMatMPIAIJSetPreallocationCSR_Indexonly:WrongInputType",
            "Input argument mat has incorrect data type. struct is expected.");
    if (mxGetNumberOfFields(prhs[0])!=3)
        mexErrMsgIdAndTxt("petscMatMPIAIJSetPreallocationCSR_Indexonly:InputStructWrongFields",
            "Input argument mat has incorrect number of fields.");
    if (mxGetNumberOfElements(prhs[0]) != 1)
        mexErrMsgIdAndTxt("petscMatMPIAIJSetPreallocationCSR_Indexonly:WrongSizeOfInputArg",
            "Argument mat must contain 1 items.");

    _sub_mx1 = mxGetField(prhs[0], 0, "data");
    if (_sub_mx1==NULL)
        mexErrMsgIdAndTxt("petscMatMPIAIJSetPreallocationCSR_Indexonly:WrongInputStruct",
            "Input argument mat does not have the field data.");
    if (mxGetNumberOfElements(_sub_mx1) && mxGetClassID(_sub_mx1) != mxUINT8_CLASS)
        mexErrMsgIdAndTxt("petscMatMPIAIJSetPreallocationCSR_Indexonly:WrongInputType",
            "Input argument mat.data has incorrect data type. uint8 is expected.");
    *(void**)&mat.data = mxCalloc(1, sizeof(emxArray__common));
    alias_mxArray_to_emxArray(_sub_mx1, (emxArray__common*)mat.data, "mat.data", 1);
    _sub_mx1 = mxGetField(prhs[0], 0, "type");
    if (_sub_mx1==NULL)
        mexErrMsgIdAndTxt("petscMatMPIAIJSetPreallocationCSR_Indexonly:WrongInputStruct",
            "Input argument mat does not have the field type.");
    if (mxGetNumberOfElements(_sub_mx1) && mxGetClassID(_sub_mx1) != mxCHAR_CLASS)
        mexErrMsgIdAndTxt("petscMatMPIAIJSetPreallocationCSR_Indexonly:WrongInputType",
            "Input argument mat.type has incorrect data type. char is expected.");
    if (mxGetNumberOfElements(_sub_mx1) && mxGetDimensions(_sub_mx1)[0] != 1)
        mexErrMsgIdAndTxt("petscMatMPIAIJSetPreallocationCSR_Indexonly:WrongSizeOfInputArg",
            "Dimension 1 of mat.type should be equal to 1.");
    *(void**)&mat.type = mxCalloc(1, sizeof(emxArray__common));
    alias_mxArray_to_emxArray(_sub_mx1, (emxArray__common*)mat.type, "mat.type", 2);
    _sub_mx1 = mxGetField(prhs[0], 0, "nitems");
    if (_sub_mx1==NULL)
        mexErrMsgIdAndTxt("petscMatMPIAIJSetPreallocationCSR_Indexonly:WrongInputStruct",
            "Input argument mat does not have the field nitems.");
    if (mxGetNumberOfElements(_sub_mx1) && mxGetClassID(_sub_mx1) != mxINT32_CLASS)
        mexErrMsgIdAndTxt("petscMatMPIAIJSetPreallocationCSR_Indexonly:WrongInputType",
            "Input argument mat.nitems has incorrect data type. int32 is expected.");
    if (mxGetNumberOfElements(_sub_mx1) != 1)
        mexErrMsgIdAndTxt("petscMatMPIAIJSetPreallocationCSR_Indexonly:WrongSizeOfInputArg",
            "Argument mat.nitems should be a scalar.");
    mat.nitems = *(int32_T*)mxGetData(_sub_mx1);
    if (mxGetNumberOfElements(prhs[1]) && mxGetClassID(prhs[1]) != mxINT32_CLASS)
        mexErrMsgIdAndTxt("petscMatMPIAIJSetPreallocationCSR_Indexonly:WrongInputType",
            "Input argument ix has incorrect data type. int32 is expected.");
    alias_mxArray_to_emxArray(prhs[1], (emxArray__common *)&ix, "ix", 1);
    if (mxGetNumberOfElements(prhs[2]) && mxGetClassID(prhs[2]) != mxINT32_CLASS)
        mexErrMsgIdAndTxt("petscMatMPIAIJSetPreallocationCSR_Indexonly:WrongInputType",
            "Input argument jx has incorrect data type. int32 is expected.");
    alias_mxArray_to_emxArray(prhs[2], (emxArray__common *)&jx, "jx", 1);

    /* Preallocate output variables */
    {mwSize l_size[] = {1, 1};
    *(void **)&errCode = prealloc_mxArray((mxArray**)&plhs[0], mxINT32_CLASS, 2, l_size); }
    {mwSize l_size[] = {1, 1};
    *(void **)&toplevel = prealloc_mxArray((mxArray**)&plhs[1], mxLOGICAL_CLASS, 2, l_size); }

    /* Invoke the target function */
    petscMatMPIAIJSetPreallocationCSR_initialize();

    petscMatMPIAIJSetPreallocationCSR_Indexonly(&mat, &ix, &jx, errCode, toplevel);

    petscMatMPIAIJSetPreallocationCSR_terminate();

    /* Marshall out function outputs */
    /* Nothing to do for plhs[0] */
    /* Nothing to do for plhs[1] */

    /* Free temporary variables */
    free_emxArray((emxArray__common*)mat.type); mxFree(mat.type);
    free_emxArray((emxArray__common*)mat.data); mxFree(mat.data);

    free_emxArray((emxArray__common*)&ix);
    free_emxArray((emxArray__common*)&jx);
}

void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[]) {
    /* Temporary copy for mex outputs. */
    mxArray *outputs[2];
    int i;
    int nOutputs = (nlhs < 1 ? 1 : nlhs);

    if (nrhs == 4) {
        if (nlhs > 2)
            mexErrMsgIdAndTxt("petscMatMPIAIJSetPreallocationCSR:TooManyOutputArguments","Too many output arguments for entry-point petscMatMPIAIJSetPreallocationCSR.");
        /* Call the API function. */
        petscMatMPIAIJSetPreallocationCSR_api(prhs, (const mxArray**)outputs);
    }
    else if (nrhs == 3) {
        if (nlhs > 2)
            mexErrMsgIdAndTxt("petscMatMPIAIJSetPreallocationCSR_Indexonly:TooManyOutputArguments","Too many output arguments for entry-point petscMatMPIAIJSetPreallocationCSR_Indexonly.");
        /* Call the API function. */
        petscMatMPIAIJSetPreallocationCSR_Indexonly_api(prhs, (const mxArray**)outputs);
    }
    else
        mexErrMsgIdAndTxt("petscMatMPIAIJSetPreallocationCSR:WrongNumberOfInputs","Incorrect number of input variables for entry-point petscMatMPIAIJSetPreallocationCSR.");

    /* Copy over outputs to the caller. */
    for (i = 0; i < nOutputs; ++i) {
        plhs[i] = outputs[i];
    }
}