function [mat, errCode, toplevel] = petscMatDestroy(mat)
%Frees space taken by a matrix.
%
%  [mat, errCode] = petscMatDestroy(mat)
%
%  SEE ALSO: petscVecCreateSeq, petscVecCreateMPI, petscAssembleMat, petscVecDestroy
%
% PETSc C interface:
%   PetscErrorCode MatDestroy(Mat *A)
% http://www.mcs.anl.gov/petsc/petsc-current/docs/manualpages/Mat/MatDestroy.html

%#codegen -args {PetscMat}

errCode = int32(-1);

if ~isempty(coder.target)
    t_mat = PetscMat(mat);
    
    errCode = coder.ceval('MatDestroy', coder.ref(t_mat));

    toplevel = nargout>2;
    if errCode && (toplevel || m2c_debug)
        m2c_error('petsc:RuntimeError', 'MatDestroy returned error code %d\n', errCode)
    end

    mat = PetscMat(t_mat, toplevel);
end
end
