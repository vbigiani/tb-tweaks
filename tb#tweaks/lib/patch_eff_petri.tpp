READ_LONG start + 0x10  "OPcode"  ELSE 0
READ_LONG start + 0x20  param2    ELSE 0
PATCH_IF (("%OPcode%" = 0x65) AND ("%param2%"=0x86)) BEGIN  //if immunity to petri
		WRITE_SHORT start + 0x10  0xce
		WRITE_LONG start + 0x1c 0
		WRITE_ASCII start + 0x30 "tb#petri"
END
PATCH_IF ("%OPcode%" = 0x2b) BEGIN                 //if it's stone to flesh
			WRITE_SHORT start + 0x10 0x92        //OPcode=cast spell
			WRITE_LONG start + 0x1c 0x0a   //parameter1=10
			WRITE_LONG start + 0x20 0   //parameter2=0
			WRITE_ASCII start + 0x30 "tb#depet"   //Actual spell, a more friendly one :-)
END
PATCH_IF ("%OPcode%" = 0x86) BEGIN
		WRITE_SHORT start + 0x10 0x92
		WRITE_LONG start + 0x1c 0x0a
		WRITE_LONG start + 0x20 0
		WRITE_ASCII start + 0x30 "tb#petri"
END
