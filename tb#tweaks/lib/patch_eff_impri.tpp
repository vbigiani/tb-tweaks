READ_LONG start + 0x10  "OPcode"  ELSE 0
READ_LONG start + 0x20  param2    ELSE 0
PATCH_IF (("%OPcode%" = 0x65) AND ("%param2%"=0xd3)) BEGIN  //if immunity to impri
		WRITE_SHORT start + 0x10  0xce
		WRITE_LONG start + 0x20 0
		WRITE_ASCII start + 0x30 "tb#impri"
END
PATCH_IF ("%OPcode%" = 0xd3) BEGIN
		WRITE_SHORT start + 0x10 0x92
		WRITE_LONG start + 0x1c 0x0a
		WRITE_LONG start + 0x20 0
		WRITE_ASCII start + 0x30 "tb#impri"
END
