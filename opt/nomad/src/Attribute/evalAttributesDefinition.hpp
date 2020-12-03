//////////// THIS FILE MUST BE CREATED BY EXECUTING WriteAttributeDefinitionFile ////////////
//////////// DO NOT MODIFY THIS FILE MANUALLY ///////////////////////////////////////////////

#ifndef __NOMAD400_EVALATTRIBUTESDEFINITION__
#define __NOMAD400_EVALATTRIBUTESDEFINITION__

_definition = {
{ "BB_EXE",  "std::string",  "",  " Blackbox executable ",  " \n  \n . Blackbox executable name \n  \n . List of strings \n  \n . Required for batch mode \n  \n . Unused in library mode \n  \n . One executable can give several outputs \n  \n . Use \' or \", and \'$\', to specify names or commands with spaces \n  \n . When the \'$\' character is put in first position of a string, it is \n   considered as global and no path will be added \n  \n . Examples \n     . BB_EXE bb.exe \n     . BB_EXE \'$nice bb.exe\' \n     . BB_EXE \'$python bb.py\' \n  \n . Default: Empty string.\n\n",  "  basic blackbox blackboxes bb exe executable executables binary output outputs batch  "  , "false" , "false" , "true" },
{ "BB_OUTPUT_TYPE",  "NOMAD::BBOutputTypeList",  "OBJ",  " Type of outputs provided by the blackboxes ",  " \n  \n . Blackbox output types \n  \n . List of types for each blackbox output \n  \n . Available types \n     . OBJ       : objective value to minimize (define twice for bi-objective) \n     . PB        : constraint <= 0 treated with Progressive Barrier (PB) \n     . EB        : constraint <= 0 treated with Extreme Barrier (EB) \n     . F         : constraint <= 0 treated with Filter \n     . NOTHING   : this output is ignored \n     . EXTRA_O   : same as 'NOTHING' \n     .  -        : same as 'NOTHING' \n  \n . Equality constraints are not natively supported \n  \n . See parameters LOWER_BOUND and UPPER_BOUND for bound constraints \n  \n . Examples \n     . BB_EXE bb.exe                   # these two lines define \n     . BB_OUTPUT_TYPE OBJ EB EB        # that bb.exe outputs three values \n  \n . Default: OBJ\n\n",  "  basic bb exe blackbox blackboxs output outputs constraint constraints type types  "  , "false" , "false" , "true" } };

#endif
