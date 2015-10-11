READ_SHORT (start) "OPcode" ELSE 0
PATCH_IF ("%OPcode%" = 69)  BEGIN                 //if it's non-detection
  opcode = 303
  parameter1 = 0
  parameter2 = 4
  READ_BYTE  start + 0x02 target
  READ_BYTE  start + 0x03 power
  READ_BYTE  start + 0x0c timing
  READ_BYTE  start + 0x0d resist_dispel
  READ_LONG  start + 0x0e duration
  READ_BYTE  start + 0x12 probability1
  READ_BYTE  start + 0x13 probability2
  READ_ASCII start + 0x14 resource (8)
  READ_LONG  start + 0x1c dicenumber
  READ_LONG  start + 0x20 dicesize
  READ_LONG  start + 0x24 savingthrow
  READ_LONG  start + 0x28 savebonus
  header = headcount - 1
	LPM ~%add%~
END
