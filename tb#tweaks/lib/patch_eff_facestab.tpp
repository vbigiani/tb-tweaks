READ_LONG (start + 0x10) "OPcode" ELSE 0
PATCH_IF ("%OPcode%" = 69)  BEGIN  //if it's non-detection
  PATCH_IF (start = 0) THEN BEGIN  // EFF files
    PATCH_FAIL @21004
  END
  READ_ASCII start thisEffect (0x108)
  INSERT_BYTES start 0x108
  WRITE_EVALUATED_ASCII start ~%thisEffect%~ (0x108)
  WRITE_LONG start + 0x10 303
  WRITE_LONG start + 0x1c 0
  WRITE_LONG start + 0x20 4
END
