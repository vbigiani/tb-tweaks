BEGIN "tb#diff"
IF ~Global("RTWMyDifficulty","global",0)~ hello
SAY @0
++ @1 DO ~SetGlobal("RTWMyDifficulty","global",1)~ + bye1
++ @2 DO ~SetGlobal("RTWMyDifficulty","global",2)~ + bye2
++ @3 DO ~SetGlobal("RTWMyDifficulty","global",3)~ + bye3
++ @4 DO ~SetGlobal("RTWMyDifficulty","global",4)~ + bye4
++ @5 DO ~SetGlobal("RTWMyDifficulty","global",5)~ + bye5
++ @6 + curiosity
END

IF ~!Global("RTWMyDifficulty","global",0)~ hello1
SAY @7
++ @1 DO ~SetGlobal("RTWMyDifficulty","global",1)~ + bye1
++ @2 DO ~SetGlobal("RTWMyDifficulty","global",2)~ + bye2
++ @3 DO ~SetGlobal("RTWMyDifficulty","global",3)~ + bye3
++ @8 DO ~SetGlobal("RTWMyDifficulty","global",4)~ + bye4
++ @5 DO ~SetGlobal("RTWMyDifficulty","global",5)~ + bye5
++ @6 + curiosity
END

IF ~~ curiosity
SAY @9
++ @1 DO ~SetGlobal("RTWMyDifficulty","global",1)~ + bye1
++ @2 DO ~SetGlobal("RTWMyDifficulty","global",2)~ + bye2
++ @3 DO ~SetGlobal("RTWMyDifficulty","global",3)~ + bye3
++ @8 DO ~SetGlobal("RTWMyDifficulty","global",4)~ + bye4
++ @5 DO ~SetGlobal("RTWMyDifficulty","global",5)~ + bye5
END

IF ~~ bye1
SAY @10
IF ~~ THEN DO ~DestroySelf()~ EXIT END

IF ~~ bye2
SAY @11
IF ~~ THEN DO ~DestroySelf()~ EXIT END

IF ~~ bye3
SAY @12
IF ~~ THEN DO ~DestroySelf()~ EXIT END

IF ~~ bye4
SAY @13
IF ~~ THEN DO ~DestroySelf()~ EXIT END

IF ~~ bye5
SAY @14
IF ~~ THEN DO ~DestroySelf()~ EXIT END



