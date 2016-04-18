.ALIASES
_    U1(X=N00462 Y=N00070 CARRY=N00148 SUM=SUM ) CN @LAB04.full_adder(sch_1):INS30@LAB04.half_adder(sch_1)
X_U1_U1A          U1.U1A(A=N00462 B=N00070 Y=SUM VCC=$G_DPWR GND=$G_DGND ) CN
+@LAB04.full_adder(sch_1):INS30@LAB04.half_adder(sch_1):INS19@EVAL.7486.Normal(chips)
X_U1_U2A          U1.U2A(A=N00462 B=N00070 Y=N00148 VCC=$G_DPWR GND=$G_DGND ) CN
+@LAB04.full_adder(sch_1):INS30@LAB04.half_adder(sch_1):INS539@EVAL.7408.Normal(chips)
_    _(U1.CARRY=N00148)
_    _(U1.SUM=SUM)
_    _(U1.x=N00462)
_    _(U1.y=N00070)
_    U2(X=N00460 Y=N00259 CARRY=N00160 SUM=N00070 ) CN @LAB04.full_adder(sch_1):INS50@LAB04.half_adder(sch_1)
X_U2_U1A          U2.U1A(A=N00460 B=N00259 Y=N00070 VCC=$G_DPWR GND=$G_DGND ) CN
+@LAB04.full_adder(sch_1):INS50@LAB04.half_adder(sch_1):INS19@EVAL.7486.Normal(chips)
X_U2_U2A          U2.U2A(A=N00460 B=N00259 Y=N00160 VCC=$G_DPWR GND=$G_DGND ) CN
+@LAB04.full_adder(sch_1):INS50@LAB04.half_adder(sch_1):INS539@EVAL.7408.Normal(chips)
_    _(U2.CARRY=N00160)
_    _(U2.SUM=N00070)
_    _(U2.x=N00460)
_    _(U2.y=N00259)
X_U3A           U3A(A=N00148 B=N00160 Y=CARRY_OUT VCC=$G_DPWR GND=$G_DGND ) CN
+@LAB04.full_adder(sch_1):INS107@EVAL.7432.Normal(chips)
U_Carry_in          Carry_in(VCC=$G_DPWR GND=$G_DGND OUT=N00462 ) CN
+@LAB04.full_adder(sch_1):INS187@SOURCSTM.DigStim1.Normal(chips)
U_X             X(VCC=$G_DPWR GND=$G_DGND OUT=N00460 ) CN @LAB04.full_adder(sch_1):INS211@SOURCSTM.DigStim1.Normal(chips)
U_Y             Y(VCC=$G_DPWR GND=$G_DGND OUT=N00259 ) CN @LAB04.full_adder(sch_1):INS235@SOURCSTM.DigStim1.Normal(chips)
_    _(CARRY_OUT=CARRY_OUT)
_    _(SUM=SUM)
.ENDALIASES
