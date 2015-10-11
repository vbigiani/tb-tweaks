APPEND player1
	IF ~Global("RTWMyDifficulty","global",0)~ hello
	SAY @0
	++ @1 DO ~SetGlobal("RTWMyDifficulty","global",1)~ EXIT
	++ @2 DO ~SetGlobal("RTWMyDifficulty","global",2)~ EXIT
	++ @3 DO ~SetGlobal("RTWMyDifficulty","global",3)~ EXIT
	++ @4 DO ~SetGlobal("RTWMyDifficulty","global",4)~ EXIT
	++ @5 DO ~SetGlobal("RTWMyDifficulty","global",5)~ EXIT
	END
END