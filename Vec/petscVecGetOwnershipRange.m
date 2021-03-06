function [first_row, last_row, errCode, toplevel] = petscVecGetOwnershipRange(vec)
%Returns the range of indices owned by this processor, assuming that the
%vectors are laid out with the first n1 elements on the first processor,
%next n2 elements on the second, etc.
%
%   [first_row, ~, errCode] = petscVecGetOwnershipRange(vec)
%	vec	         - the vector
%   first_row    - the global index of the first local row (0 based)
%   last_row     - one more than the global index of the last local row
%
% PETSc C interface:
%   PetscErrorCode VecGetOwnershipRange(Vec vec,PetscInt *m,PetscInt *n)
% http://www.mcs.anl.gov/petsc/petsc-3.7/docs/manualpages/Vec/VecGetOwnershipRange.html

%#codegen -args {PetscVec}

errCode = int32(-1);

if ~isempty(coder.target)
    t_vec = PetscVec(vec);

    first_row = int32(0);
    last_row = int32(0);

    errCode = coder.ceval('VecGetOwnershipRange', t_vec, ...
        coder.wref(first_row), coder.wref(last_row));

    toplevel = nargout>3;
    if errCode && (toplevel || m2c_debug)
        m2c_error('petsc:RuntimeError', 'VecGetOwnershipRange returned error code %d\first_row', errCode)
    end
end
end


function test %#ok<DEFNU>
%!test
%! x = rand(10,1);
%!
%! vec_x = petscVecCreateFromArray(x);
%! [first_row, last_row, errCode] = petscVecGetOwnershipRange(vec_x);
%!
%! assert(errCode == 0 && first_row == 0 && last_row == 10);
end
