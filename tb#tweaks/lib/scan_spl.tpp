READ_ASCII 0 signature (4)
PATCH_IF ~%signature%~ STRING_EQUAL ~SPL ~ THEN BEGIN
  header_length = 0x28
  SPRINT add_header ~ADD_SPELL_EFFECT~
  SPRINT add_global ~ADD_SPELL_CFEFFECT~
END ELSE PATCH_IF  ~%signature%~ STRING_EQUAL ~ITM ~ THEN BEGIN
  header_length = 0x38
  SPRINT add_header ~ADD_ITEM_EFFECT~
  SPRINT add_global ~ADD_ITEM_EQEFFECT~
END ELSE BEGIN
  INNER_ACTION BEGIN
    FAIL ~Malformed file signature "%signature%": %SOURCE_FILE%~
  END
END
READ_LONG 0x64 "headoffset"  ELSE 0
READ_SHORT 0x68 "headcount"  ELSE 0
READ_LONG 0x6a "effectsoffset"  ELSE 0
SPRINT ~add~ ~%add_header%~
WHILE ("%headcount%" > 0) BEGIN
   READ_SHORT ("%headoffset%" + (("%headcount%" - 1 ) * header_length) + 0x1e) "count"  ELSE 0
   READ_SHORT ("%headoffset%" + (("%headcount%" - 1 ) * header_length) + 0x20) "effectsindex"  ELSE 0
   WHILE ("%count%" >0) BEGIN
      SET start = "%effectsoffset%" + (("%effectsindex%" + "%count%" - 1 )* 0x30)
      PATCH_INCLUDE ~tb#tweaks/lib/patch_spl_%which%.tpp~
      SET "count" = ("%count%" -1)
   END
   SET "headcount" = "%headcount%" - 1
END
SPRINT ~add~ ~%add_global%~
   READ_SHORT 0x70 "count"  ELSE 0
   WHILE ("%count%" >0) BEGIN
      SET start = "%effectsoffset%" + (("%count%" - 1 )* 0x30)
      PATCH_INCLUDE ~tb#tweaks/lib/patch_spl_%which%.tpp~
      SET "count" = ("%count%" -1)
   END
