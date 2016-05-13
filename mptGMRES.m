function [flag,relres,iter] = mptGMRES(A, b, x, restart, rtol, maxit, ...
    pctype, pcprefix, varargin)
% Solves a linear system using the restarted GMRES method.
%
% Syntax:
%    mptGMRES(A_hdl, b_hdl)
%    mptGMRES(A_hdl, b_hdl, x_hdl)
%    mptGMRES(A_hdl, b_hdl, x_hdl, restart)
%    mptGMRES(A_hdl, b_hdl, x_hdl, restart, rtol)
%    mptGMRES(A_hdl, b_hdl, x_hdl, restart, rtol, maxit)
%    mptGMRES(A_hdl, b_hdl, x_hdl, restart, rtol, maxit, pctype)
%    mptGMRES(A_hdl, b_hdl, x_hdl, restart, rtol, maxit, pctype, pcprefix)
%    mptGMRES(A_hdl, b_hdl, x_hdl, restart, rtol, maxit, pctype, pcprefix, x0_hdl)
%    mptGMRES(A_hdl, b_hdl, x_hdl, restart, rtol, maxit, pctype, pcprefix, x0_hdl, resvec_hdl)
%
%    [flag, reslres, iter] = mptGMRES(A_hdl, b_hdl, x_hdl, ...)
%
%    The handles are PetscMat or PetscVec objects.
%
% Description:
%    mptGMRES(A_hdl, b_hdl) solves the linear system without preconditioners,
%    using the default tolerances or those that have been set previously in
%    the option databases. A_hdl is a PetscMat object, and b_hdl is a
%    PetscVec object. The solution is stored into b. The QMRCGS can be
%    controlled using the options database for KSPQMRCGS.
%
%    mptGMRES(A_hdl, b_hdl, x_hdl) solves the linear system and saves the
%    result into x.
%
%    mptGMRES(A_hdl, b_hdl, x_hdl, restart) uses the given restart value.
%
%    mptGMRES(A_hdl, b_hdl, x_hdl, restart, rtol) uses the given relative tolerarance.
%
%    mptGMRES(A_hdl, b_hdl, x_hdl, restart, rtol, maxit) solves with the given relative
%    tolerances and maximum iteration count.
%
%    mptGMRES(A_hdl, b_hdl, x_hdl, restart, rtol, maxit, pctype) uses the
%    specified preconditioner. The preconditioner can be controlled by
%    the PETSc option database.
%
%    mptGMRES(A_hdl, b_hdl, x_hdl, restart, rtol, maxit, pctype, pcprefix) specifies
%    the prefix for the options in the PETSc option database.
%
%    mptGMRES(A_hdl, b_hdl, x_hdl, restart, rtol, maxit, pctype, pcprefix, x0_handle)
%    usee x0 for the initial guess. x0 can be the same as x.
%
%    mptGMRES(A_hdl, b_hdl, x_hdl, restart, rtol, maxit, pctype, pcprefix, x0_handle, resvec_hdl)
%    also computes the residual vector and saves it into resvec.
%
% See also: mptCG, mptMINRES, mptBCGS, mptTFQMR, mptQMRCGS,
%           mptKSPSetup, mptKSPSolve, mptKSPCleanup
%
% PETSC: http://www.mcs.anl.gov/petsc/petsc-current/docs/manualpages/KSP/KSPGMRES.html

%#codegen

% Setup KSP
if nargin<3; x = b; end
if nargin<4; restart = PETSC_DEFAULT; end
if nargin<4; rtol = PETSC_DEFAULT; end
if nargin<5; maxit = PETSC_DEFAULT; end
if nargin<6; pctype = PETSC_PCNONE; end
if nargin<7; pcprefix = ''; end

petscOptionsSetValue(PETSC_NULL, '-ksp_gmres_restart', num2str(restart));

ksp = mptKSPSetup(A, PETSC_KSPGMRES, pctype, pcprefix);

[flag,relres,iter] = mptKSPSolve(ksp, b, x, rtol, maxit, varargin{:});

mptKSPCleanup(ksp);

end