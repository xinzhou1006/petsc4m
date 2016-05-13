function [flag,relres,iter] = mptCG(A, b, x, rtol, maxit, pctype, pcprefix, varargin)
% Solves a SPD linear system using preconditioned conjugate gradient.
%
% Syntax:
%    mptCG(A_hdl, b_hdl)
%    mptCG(A_hdl, b_hdl, x_hdl)
%    mptCG(A_hdl, b_hdl, x_hdl, rtol)
%    mptCG(A_hdl, b_hdl, x_hdl, rtol, maxit)
%    mptCG(A_hdl, b_hdl, x_hdl, rtol, maxit, pctype)
%    mptCG(A_hdl, b_hdl, x_hdl, rtol, maxit, pctype, pcprefix)
%    mptCG(A_hdl, b_hdl, x_hdl, rtol, maxit, pctype, pcprefix, x0_hdl)
%    mptCG(A_hdl, b_hdl, x_hdl, rtol, maxit, pctype, pcprefix, x0_hdl, resvec_hdl)
%
%    [flag, reslres, iter] = mptCG(A_hdl, b_hdl, x_hdl, ...)
%
%    The handles are PetscMat or PetscVec objects.
%
% Description:
%    mptCG(A_hdl, b_hdl) solves the linear system without preconditioners,
%    using the default tolerances or those that have been set previously in
%    the option databases. A_hdl is a PetscMat object, and b_hdl is a
%    PetscVec object. The solution is stored into b. The CG can be
%    controlled using the options database for KSPCG.
%
%    mptCG(A_hdl, b_hdl, x_hdl) solves the linear system and saves the
%    result into x.
%
%    mptCG(A_hdl, b_hdl, x_hdl, rtol) uses the given relative tolerarance.
%
%    mptCG(A_hdl, b_hdl, x_hdl, rtol, maxit) solves with the given relative
%    tolerances and maximum iteration count.
%
%    mptCG(A_hdl, b_hdl, x_hdl, rtol, maxit, pctype) uses the
%    specified preconditioner. The preconditioner can be controlled by
%    the PETSc option database.
%
%    mptCG(A_hdl, b_hdl, x_hdl, rtol, maxit, pctype, pcprefix) specifies
%    the prefix for the options in the PETSc option database.
%
%    mptCG(A_hdl, b_hdl, x_hdl, rtol, maxit, pctype, pcprefix, x0_handle)
%    usee x0 for the initial guess. x0 can be the same as x.
%
%    mptCG(A_hdl, b_hdl, x_hdl, rtol, maxit, pctype, pcprefix, x0_handle, resvec_hdl)
%    also computes the residual vector and saves it into resvec.
%
% See also: mptMINRES, mptGMRES, mptBCGS, mptTFQMR, mptQMRCGS,
%           mptKSPSetup, mptKSPSolve, mptKSPCleanup
%
% PETSC: http://www.mcs.anl.gov/petsc/petsc-current/docs/manualpages/KSP/KSPCG.html

%#codegen

% Setup KSP
if nargin<2; x = b; end
if nargin<3; rtol = PETSC_DEFAULT; end
if nargin<4; maxit = PETSC_DEFAULT; end
if nargin<5; pctype = PETSC_PCNONE; end
if nargin<6; pcprefix = ''; end

ksp = mptKSPSetup(A, PETSC_KSPCG, pctype, pcprefix);

[flag,relres,iter] = mptKSPSolve(ksp, b, x, rtol, maxit, varargin{:});

mptKSPCleanup(ksp);

end