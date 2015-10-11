      READ_SHORT start "OPcode"  ELSE 0
      READ_LONG start + 8 "param2"  ELSE 0
      PATCH_IF ("%OPcode%" = 0xd3) BEGIN                 //if it's imprisonment
      	    WRITE_SHORT start 0x92        //OPcode=cast spell
      	    WRITE_LONG (4 +start) 0x0a   //parameter1=10
      	    WRITE_LONG (8 + start) 0   //parameter2=0
      	    WRITE_ASCII (0x14 + start) "tb#impri"   //Actual spell, a more friendly one :-)
      END
      PATCH_IF (("%OPcode%" = 0x65) AND ("%param2%" = 0xd3)) BEGIN  //if it's protect from impr
      	    WRITE_SHORT (start) 0xce        //OPcode=protect from spell
      	    WRITE_LONG (4 +start) 0  //parameter1=strref
      	    WRITE_LONG (8 + start) 0   //parameter2=0
      	    WRITE_ASCII (0x14 + start) "tb#impri"   //Spell to be protected from
      END
