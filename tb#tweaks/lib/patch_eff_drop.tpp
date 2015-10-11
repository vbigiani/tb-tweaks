	    READ_LONG start + 0x10  "OPcode" ELSE 0
	    PATCH_IF (("%OPcode%" = 0x108)) BEGIN
	    	  WRITE_SHORT start + 0x10 0x8b
	    	  WRITE_LONG start + 0x1c 0
	    	  WRITE_LONG start + 0x20 0
	    END
