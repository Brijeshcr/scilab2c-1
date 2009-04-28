function PrintStringInfo(str, filename, outputtype, ennewline)
// function PrintStringInfo(str,filename,outputtype,ennewline)
// -----------------------------------------------------------------
// #RNU_RES_B
// Prints a string into a file or on the stdout or on both.
//
// Input data:
// filename: optional parameter, that specifies the output file.
//           If filename is '' or it is not provided to the function,
//           the string will be printed on the stdout.
// outputtype: 'file' -> prints only on file.
//             'stdout' -> prints only on the stdout.
//             'both' -> prints on both file and stdout.
//             Default is 'stdout'.
// ennewline: optional (default = 'y'); If y adds a newline character
//            at the end of the input string.
//
// Output data:
// ---
// #RNU_RES_E
//
// Status:
// 02-Jan-2006 -- Nutricato Raffaele: Author.
// 02-Jan-2006 -- Nutricato Raffaele: TEST OK.
// 02-May-2006 -- Nutricato Raffaele: Added ennewline.
//
// Copyright 2007 Raffaele Nutricato.
// Contact: raffaele.nutricato@tiscali.it
// -----------------------------------------------------------------

// ------------------------------
// --- Check input arguments. ---
// ------------------------------
SCI2CNInArgCheck(argn(2),0,4);

   if argn(2) < 4
      ennewline = 'y';
      if argn(2) < 3
 	       outputtype = 'stdout';
         if argn(2) < 2
  	         filename = '';
            if argn(2) < 1
               str = '';
            end
         end
      end
   end

   if (length(filename) == 0) then 
      outputtype = 'stdout'; // Prints only on the stdout.
   end

   if (outputtype=='both') | (outputtype=='stdout')
      disp(str)
   end

   if (outputtype=='both') | (outputtype=='file')
      if (ennewline=='y')
         filenamefprintf(filename,'y',str);
      else
         filenamefprintf(filename,'n',str);
      end
   end
   
endfunction