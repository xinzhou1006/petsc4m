/*
 * Mat/codegen/lib/petscMatGetNullSpace/petscMatGetNullSpace_mex.c
 *
 * Auxiliary code for mexFunction of petscMatGetNullSpace
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
#include "petscMatGetNullSpace.h"
#include "m2c.c"

/* Include declaration of some helper functions. */
#include "lib2mex_helper.c"

static void __petscMatGetNullSpace_api(mxArray **plhs, const mxArray ** prhs) {

    struct0_T            mat;
    struct0_T            nullsp;
    mxArray              *_sub_mx1;

    int32_T              *errCode;
    boolean_T            *toplevel;

    /* Marshall in function inputs */

    if (!mxIsStruct(prhs[0]))
        mexErrMsgIdAndTxt("petscMatGetNullSpace:WrongInputType",
            "Input argument mat has incorrect data type. struct is expected.");
    if (mxGetNumberOfFields(prhs[0])!=3)
        mexErrMsgIdAndTxt("petscMatGetNullSpace:InputStructWrongFields",
            "Input argument mat has incorrect number of fields.");
    if (mxGetNumberOfElements(prhs[0]) != 1)
        mexErrMsgIdAndTxt("petscMatGetNullSpace:WrongSizeOfInputArg",
            "Argument mat must contain 1 items.");

    _sub_mx1 = mxGetField(prhs[0], 0, "data");
    if (_sub_mx1==NULL)
        mexErrMsgIdAndTxt("petscMatGetNullSpace:WrongInputStruct",
            "Input argument mat does not have the field data.");
    if (mxGetNumberOfElements(_sub_mx1) && mxGetClassID(_sub_mx1) != mxUINT8_CLASS)
        mexErrMsgIdAndTxt("petscMatGetNullSpace:WrongInputType",
            "Input argument mat.data has incorrect data type. uint8 is expected.");
    *(void**)&mat.data = mxCalloc(1, sizeof(emxArray__common));
    alias_mxArray_to_emxArray(_sub_mx1, (emxArray__common*)mat.data, "mat.data", 1);
    _sub_mx1 = mxGetField(prhs[0], 0, "type");
    if (_sub_mx1==NULL)
        mexErrMsgIdAndTxt("petscMatGetNullSpace:WrongInputStruct",
            "Input argument mat does not have the field type.");
    if (mxGetNumberOfElements(_sub_mx1) && mxGetClassID(_sub_mx1) != mxCHAR_CLASS)
        mexErrMsgIdAndTxt("petscMatGetNullSpace:WrongInputType",
            "Input argument mat.type has incorrect data type. char is expected.");
    if (mxGetNumberOfElements(_sub_mx1) && mxGetDimensions(_sub_mx1)[0] != 1)
        mexErrMsgIdAndTxt("petscMatGetNullSpace:WrongSizeOfInputArg",
            "Dimension 1 of mat.type should be equal to 1.");
    *(void**)&mat.type = mxCalloc(1, sizeof(emxArray__common));
    alias_mxArray_to_emxArray(_sub_mx1, (emxArray__common*)mat.type, "mat.type", 2);
    _sub_mx1 = mxGetField(prhs[0], 0, "nitems");
    if (_sub_mx1==NULL)
        mexErrMsgIdAndTxt("petscMatGetNullSpace:WrongInputStruct",
            "Input argument mat does not have the field nitems.");
    if (mxGetNumberOfElements(_sub_mx1) && mxGetClassID(_sub_mx1) != mxINT32_CLASS)
        mexErrMsgIdAndTxt("petscMatGetNullSpace:WrongInputType",
            "Input argument mat.nitems has incorrect data type. int32 is expected.");
    if (mxGetNumberOfElements(_sub_mx1) != 1)
        mexErrMsgIdAndTxt("petscMatGetNullSpace:WrongSizeOfInputArg",
            "Argument mat.nitems should be a scalar.");
    mat.nitems = *(int32_T*)mxGetData(_sub_mx1);

    /* Preallocate output variables */
    *(void **)&nullsp.data = mxCalloc(1, sizeof(emxArray__common));    init_emxArray((emxArray__common*)nullsp.data, 1);
    *(void **)&nullsp.type = mxCalloc(1, sizeof(emxArray__common));    init_emxArray((emxArray__common*)nullsp.type, 2);
    {mwSize l_size[] = {1, 1};
    *(void **)&errCode = prealloc_mxArray((mxArray**)&plhs[1], mxINT32_CLASS, 2, l_size); }
    {mwSize l_size[] = {1, 1};
    *(void **)&toplevel = prealloc_mxArray((mxArray**)&plhs[2], mxLOGICAL_CLASS, 2, l_size); }

    /* Invoke the target function */
    petscMatGetNullSpace(&mat, &nullsp, errCode, toplevel);

    /* Marshall out function outputs */
    {const char *_fields[] = { "data", "type", "nitems",  ""};
    int32_T _one=1;
    plhs[0] = create_struct_mxArray(1, &_one, 3, _fields);}
    mxSetFieldByNumber((mxArray*)(plhs[0]), 0, 0, move_emxArray_to_mxArray((emxArray__common*)nullsp.data, mxUINT8_CLASS));
    mxSetFieldByNumber((mxArray*)(plhs[0]), 0, 1, move_emxArray_to_mxArray((emxArray__common*)nullsp.type, mxCHAR_CLASS));
    mxSetFieldByNumber((mxArray*)(plhs[0]), 0, 2, copy_scalar_to_mxArray(&nullsp.nitems, mxINT32_CLASS));
    /* Nothing to do for plhs[1] */
    /* Nothing to do for plhs[2] */

    /* Free temporary variables */
    free_emxArray((emxArray__common*)mat.type); mxFree(mat.type);
    free_emxArray((emxArray__common*)mat.data); mxFree(mat.data);

    free_emxArray((emxArray__common*)nullsp.type); mxFree(nullsp.type);
    free_emxArray((emxArray__common*)nullsp.data); mxFree(nullsp.data);

}

void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[]) {
    /* Temporary copy for mex outputs. */
    mxArray *outputs[3];
    int i;
    int nOutputs = (nlhs < 1 ? 1 : nlhs);

    if (nrhs == 1) {
        if (nlhs > 3)
            mexErrMsgIdAndTxt("petscMatGetNullSpace:TooManyOutputArguments",
                "Too many output arguments for entry-point petscMatGetNullSpace.\n");
        /* Call the API function. */
        __petscMatGetNullSpace_api(outputs, prhs);
    }
    else
        mexErrMsgIdAndTxt("petscMatGetNullSpace:WrongNumberOfInputs",
            "Incorrect number of input variables for entry-point petscMatGetNullSpace.");

    /* Copy over outputs to the caller. */
    for (i = 0; i < nOutputs; ++i) {
        plhs[i] = outputs[i];
    }
}