function val = PETSC_KSP_NORM_NATURAL %#codegen
% Obtain PETSC constant KSP_NORM_NATURAL

coder.inline('always');

val = petscGetEnum('KSP_NORM_NATURAL');
end
