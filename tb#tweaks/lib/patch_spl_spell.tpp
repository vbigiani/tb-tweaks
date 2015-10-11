READ_SHORT start "OPcode"  ELSE 0
PATCH_IF ("%OPcode%" = 147) BEGIN
  READ_ASCII start + 0x14 spell
  TO_UPPER spell
  SET $ok_spells(EVALUATE_BUFFER "%spell%") = 1
END
END
