READ_SHORT (start) "OPcode" ELSE 0
PATCH_IF ("%OPcode%" = 0x108)  BEGIN                 //if it's drop weapons in panic
			WRITE_SHORT (start) 0x8b        //OPcode=display string
			WRITE_LONG (4 +start) 0   //parameter1=strref
			WRITE_LONG (8 + start) 0   //parameter2=0
END
