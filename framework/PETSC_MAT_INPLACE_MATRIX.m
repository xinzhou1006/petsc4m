function val = PETSC_MAT_INPLACE_MATRIX %#codegen
% Obtain PETSC constant MAT_INPLACE_MATRIX

coder.inline('always');

val = petscGetEnum('MAT_INPLACE_MATRIX');
end
