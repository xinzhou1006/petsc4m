function val = PETSC_PCGASM %#codegen
% Obtain PETSC constant PCGASM

coder.inline('always');

val = petscGetObject('PCGASM');
end
