function val = PETSC_MATIS %#codegen
% Obtain PETSC constant MATIS

coder.inline('always');

val = petscGetObject('MATIS');
end
