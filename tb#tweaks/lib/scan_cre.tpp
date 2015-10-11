PATCH_IF BYTE_AT 0x33 THEN BEGIN // EFF v1
  LPF ~FJ_CRE_EFF_V2~ END
END
READ_BYTE 0x33 "effv"  ELSE 0
READ_LONG 0x02c4 "offseteffs"  ELSE 0
READ_LONG 0x02c8 "counteffs"   ELSE 0
PATCH_IF ("%effv%" = 0) BEGIN  //effects V1, like itms or spells
  WHILE ("%counteffs%" > 0) BEGIN
    SET start = "%offseteffs%" + (("%counteffs%" - 1 ) * 0x30)
    PATCH_INCLUDE ~tb#tweaks/lib/patch_spl_%which%.tpp~
    SET "counteffs" = "%counteffs%" - 1
  END
END
PATCH_IF ("%effv%" = 1) BEGIN  //effects V2
  WHILE ("%counteffs%" > 0) BEGIN
    SET start = "%offseteffs%" + (("%counteffs%" - 1 ) * 0x108) - 8
    PATCH_INCLUDE ~tb#tweaks/lib/patch_eff_%which%.tpp~
    SET "counteffs" = "%counteffs%" - 1
  END
END
