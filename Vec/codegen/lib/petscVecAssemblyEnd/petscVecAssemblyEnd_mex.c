/*
 * Vec/codegen/lib/petscVecAssemblyEnd/petscVecAssemblyEnd_mex.c
 *
 * Auxiliary code for mexFunction of petscVecAssemblyEnd
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
#include "petscVecAssemblyEnd.h"
#include "m2c.c"
/* Include declaration of some helper functions. */
#include "lib2mex_helper.c"

void petscVecAssemblyEnd_api(const mxArray ** prhs, const mxArray **plhs) {

    struct0_T            vec;
    mxArray              *_sub_mx1;

    int32_T              *errCode;
    boolean_T            *toplevel;

    /* Marshall in function inputs */

    if (!mxIsStruct(prhs[0]))
        mexErrMsgIdAndTxt("petscVecAssemblyEnd:WrongInputType",
            "Input argument vec has incorrect data type. struct is expected.");
    if (mxGetNumberOfFields(prhs[0])!=3)
        mexErrMsgIdAndTxt("petscVecAssemblyEnd:InputStructWrongFields",
            "Input argument vec has incorrect number of fields.");
    if (mxGetNumberOfElements(prhs[0]) != 1)
        mexErrMsgIdAndTxt("petscVecAssemblyEnd:WrongSizeOfInputArg",
            "Argument vec must contain 1 items.");

    _sub_mx1 = mxGetField(prhs[0], 0, "data");
    if (_sub_mx1==NULL)
        mexErrMsgIdAndTxt("petscVecAssemblyEnd:WrongInputStruct",
            "Input argument vec does not have the field data.");
    if (mxGetNumberOfElements(_sub_mx1) && mxGetClassID(_sub_mx1) != mxUINT8_CLASS)
        mexErrMsgIdAndTxt("petscVecAssemblyEnd:WrongInputType",
            "Input argument vec.data has incorrect data type. uint8 is expected.");
    *(void**)&vec.data = mxCalloc(1, sizeof(emxArray__common));
    alias_mxArray_to_emxArray(_sub_mx1, (emxArray__common*)vec.data, "vec.data", 1);
    _sub_mx1 = mxGetField(prhs[0], 0, "type");
    if (_sub_mx1==NULL)
        mexErrMsgIdAndTxt("petscVecAssemblyEnd:WrongInputStruct",
            "Input argument vec does not have the field type.");
    if (mxGetNumberOfElements(_sub_mx1) && mxGetClassID(_sub_mx1) != mxCHAR_CLASS)
        mexErrMsgIdAndTxt("petscVecAssemblyEnd:WrongInputType",
            "Input argument vec.type has incorrect data type. char is expected.");
    if (mxGetNumberOfElements(_sub_mx1) && mxGetDimensions(_sub_mx1)[0] != 1)
        mexErrMsgIdAndTxt("petscVecAssemblyEnd:WrongSizeOfInputArg",
            "Dimension 1 of vec.type should be equal to 1.");
    *(void**)&vec.type = mxCalloc(1, sizeof(emxArray__common));
    alias_mxArray_to_emxArray(_sub_mx1, (emxArray__common*)vec.type, "vec.type", 2);
    _sub_mx1 = mxGetField(prhs[0], 0, "nitems");
    if (_sub_mx1==NULL)
        mexErrMsgIdAndTxt("petscVecAssemblyEnd:WrongInputStruct",
            "Input argument vec does not have the field nitems.");
    if (mxGetNumberOfElements(_sub_mx1) && mxGetClassID(_sub_mx1) != mxINT32_CLASS)
        mexErrMsgIdAndTxt("petscVecAssemblyEnd:WrongInputType",
            "Input argument vec.nitems has incorrect data type. int32 is expected.");
    if (mxGetNumberOfElements(_sub_mx1) != 1)
        mexErrMsgIdAndTxt("petscVecAssemblyEnd:WrongSizeOfInputArg",
            "Argument vec.nitems should be a scalar.");
    vec.nitems = *(int32_T*)mxGetData(_sub_mx1);

    /* Preallocate output variables */
    {mwSize l_size[] = {1, 1};
    *(void **)&errCode = prealloc_mxArray((mxArray**)&plhs[0], mxINT32_CLASS, 2, l_size); }
    {mwSize l_size[] = {1, 1};
    *(void **)&toplevel = prealloc_mxArray((mxArray**)&plhs[1], mxLOGICAL_CLASS, 2, l_size); }

    /* Invoke the target function */
    petscVecAssemblyEnd_initialize();

    petscVecAssemblyEnd(&vec, errCode, toplevel);

    petscVecAssemblyEnd_terminate();

    /* Marshall out function outputs */
    /* Nothing to do for plhs[0] */
    /* Nothing to do for plhs[1] */

    /* Free temporary variables */
    free_emxArray((emxArray__common*)vec.type); mxFree(vec.type);
    free_emxArray((emxArray__common*)vec.data); mxFree(vec.data);

}

void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[]) {
    /* Temporary copy for mex outputs. */
    mxArray *outputs[2];
    int i;
    int nOutputs = (nlhs < 1 ? 1 : nlhs);

    if (nrhs == 1) {
        if (nlhs > 2)
            mexErrMsgIdAndTxt("petscVecAssemblyEnd:TooManyOutputArguments","Too many output arguments for entry-point petscVecAssemblyEnd.");
        /* Call the API function. */
        petscVecAssemblyEnd_api(prhs, (const mxArray**)outputs);
    }
    else
        mexErrMsgIdAndTxt("petscVecAssemblyEnd:WrongNumberOfInputs","Incorrect number of input variables for entry-point petscVecAssemblyEnd.");

    /* Copy over outputs to the caller. */
    for (i = 0; i < nOutputs; ++i) {
        plhs[i] = outputs[i];
    }
}