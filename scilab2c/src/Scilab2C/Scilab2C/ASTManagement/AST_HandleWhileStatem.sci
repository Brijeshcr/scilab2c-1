function [FileInfo,SharedInfo] = AST_HandleWhileStatem(FileInfo,SharedInfo)
// -----------------------------------------------------------------
//#RNU_RES_B
// Handles the WhileStatements tag of the AST.
//
//   txt=['While'
//        '  WhileExpression:'
//        '    '+string(W.expression)
//        '  WhileStatements:'
//        '    '+objectlist2string(W.statements)
//        'EndWhile']
//
//#RNU_RES_E
// Input data:
// //NUT: add description here
//
// Output data:
// //NUT: add description here
//
// Status:
// 20-Jan-2008 -- Edoardo Nutricato: Author.
// 20-Jan-2008 -- Rubby Nutricato: Minor Changes.
// 
// Copyright 2007 Raffaele Nutricato.
// Contact: raffaele.nutricato@tiscali.it
// -----------------------------------------------------------------

//#RNU_RES_B

//NUT: accertati che l'epilogo e il prologo del while siano effettivamente differenti o se 
//NUT: si puo' avere un solo file utilizzato sia per il prologo che per l'epilogo.

//NUT: da sistemare senza le global
//#RNU_RES_E
global SCI2CSTACK 
global StackPosition;
global STACKDEDUG


// ------------------------------
// --- Check input arguments. ---
// ------------------------------
SCI2CNInArgCheck(argn(2),2,2);

// -----------------------
// --- Initialization. ---
// -----------------------
nxtscifunname   = SharedInfo.NextSCIFunName;
nxtscifunnumber = SharedInfo.NextSCIFunNumber;
ReportFileName  = FileInfo.Funct(nxtscifunnumber).ReportFileName;
CPass1WhileProlFileName = FileInfo.Funct(nxtscifunnumber).CPass1WhileProlFileName(SharedInfo.While.Level);
PrintStepInfo('Handling WhileStatements',FileInfo.Funct(nxtscifunnumber).ReportFileName,'file');
// ---------------------------
// --- End Initialization. ---
// ---------------------------

//#RNU_RES_B
// -----------------------------------------------
// --- Resume the correct name while CPass1V1. ---
// -----------------------------------------------
//#RNU_RES_E
tmpfilename = FileInfo.Funct(nxtscifunnumber).CPass1FileName;
FileInfo.Funct(nxtscifunnumber).CPass1FileName = FileInfo.Funct(nxtscifunnumber).CPass1WhileProlFileName(SharedInfo.While.Level);
FileInfo.Funct(nxtscifunnumber).CPass1WhileProlFileName(SharedInfo.While.Level) = tmpfilename;
CPass1WhileProlFileName = FileInfo.Funct(nxtscifunnumber).CPass1WhileProlFileName(SharedInfo.While.Level);
PrintStringInfo('   Redirecting C code to: '+FileInfo.Funct(nxtscifunnumber).CPass1FileName,FileInfo.Funct(nxtscifunnumber).ReportFileName,'file');

//#RNU_RES_B
// ------------------------
// --- Generate C code. ---
// ------------------------
//#RNU_RES_E
if(SharedInfo.WhileExpr.CondVar == '')
   //#RNU_RES_B
   // It means that we are handling something like while(a) or while(1)
   // The while condition variable is generated by the HandleEndGenFun.
   //#RNU_RES_E

   // --- Pop the name of the condition variable or number. ---  
   Pop1 = AST_PopASTStack();

   [ArgName,ArgScope] = AST_ExtractNameAndScope(Pop1);
   if (length(ArgName) == 0)
      PrintStringInfo(' ',ReportFileName,'both','y');
      PrintStringInfo('SCI2CERROR: Expected while(variable) or while(number).','','stdout','y');
      PrintStringInfo('SCI2CERROR: Expected a variable or number in the AST while expression.','','stdout','y');
      PrintStringInfo('SCI2CERROR: Report this error to raffaele.nutricato@tiscali.it.','','stdout','y');
      PrintStringInfo(' ',ReportFileName,'both','y');
      SCI2Cerror(' ');
      SCI2Cerror('Expected a conditional variable in the while expression');
   end
   
   SharedInfo.WhileExpr.CondVar = ArgName;
   //#RNU_RES_B
   // --- Repush strings into the AST stack. ---
   //#RNU_RES_E

   AST_PushASTStack(Pop1);

elseif (SharedInfo.WhileExpr.DimCondVar > 0)
   SCI2CerrorFile('Cannot manage while with matrix conditions',ReportFileName);
end
SharedInfo = C_WhileExpression(FileInfo,SharedInfo);

// --------------------------
// --- Update SharedInfo. ---
// --------------------------
// Signal the exit from a while expression.
SharedInfo.WhileExpr.OnExec        = SharedInfo.WhileExpr.OnExec - 1;
SharedInfo.WhileExpr.CondVar       = '';
SharedInfo.WhileExpr.DimCondVar    = -1;
SharedInfo.WhileExpr.AssignmentFun = 0; //NUT: siamo sicuri che serva?

// -------------------------------
// --- Delete temporary files. ---
// -------------------------------
SCI2Cmdelete(CPass1WhileProlFileName);

endfunction
