function [x,flag,relres,iter,reshis,times] = petscSolveCRS_8args(Arows, Acols, Avals, b, solver, rtol, maxiter, pctype) %#codegen
[x,flag,relres,iter,reshis,times] = petscSolveCRS(Arows, Acols, Avals, b, solver, rtol, maxiter, pctype);
