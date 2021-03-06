function [n, errCode, toplevel] = petscVecGetSize(vec)
%Returns the global number of elements of the vector.
%
%[n, errCode] = petscVecGetSize(vec)
%  	vec   - the vector
%   n     - the number of elements
%
%  SEE ALSO: petscVecSetSizes, petscVecGetLocalSize
%
% PETSc C interface:
%   PetscErrorCode VecGetSize(Vec vec,PetscInt *n)
% http://www.mcs.anl.gov/petsc/petsc-current/docs/manualpages/Vec/VecGetSize.html

%#codegen -args {PetscVec}

errCode = int32(-1);

if ~isempty(coder.target)
    t_vec = PetscVec(vec);

    n = int32(0);
    errCode = coder.ceval('VecGetSize', t_vec, coder.wref(n));

    toplevel = nargout>2;
    if errCode && (toplevel || m2c_debug)
        m2c_error('petsc:RuntimeError', 'VecGetSize returned error code %d\n', errCode)
    end
end
end

function test %#ok<DEFNU>
%!test
%! x = rand(10,1);
%!
%! vec_x = petscVecCreateFromArray(x);
%! [n, errCode] = petscVecGetSize(vec_x);
%!
%! assert(errCode == 0 && n == 10);
end
