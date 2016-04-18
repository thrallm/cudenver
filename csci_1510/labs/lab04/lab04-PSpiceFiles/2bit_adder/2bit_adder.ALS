.ALIASES
_    U1(CARRY_IN=N00076 X=N00113 Y=N00117 CARRY_OUT=CARRY_OUT SUM=SUM1 ) CN @LAB04.2bit_adder(sch_1):INS32@LAB04.full_adder(sch_1)
X_U1_U3A          U1.U3A(A=U1_N00148 B=U1_N00160 Y=CARRY_OUT VCC=$G_DPWR GND=$G_DGND ) CN
+@LAB04.2bit_adder(sch_1):INS32@LAB04.full_adder(sch_1):INS107@EVAL.7432.Normal(chips)
_    U1.U1(X=N00076 Y=U1_N00070 CARRY=U1_N00148 SUM=SUM1 ) CN 
+@LAB04.2bit_adder(sch_1):INS32@LAB04.full_adder(sch_1):INS30@LAB04.half_adder(sch_1)
X_U1_U1_U1A          U1.U1.U1A(A=N00076 B=U1_N00070 Y=SUM1 VCC=$G_DPWR GND=$G_DGND ) CN
+@LAB04.2bit_adder(sch_1):INS32@LAB04.full_adder(sch_1):INS30@LAB04.half_adder(sch_1):INS19@EVAL.7486.Normal(chips)
X_U1_U1_U2A          U1.U1.U2A(A=N00076 B=U1_N00070 Y=U1_N00148 VCC=$G_DPWR GND=$G_DGND ) CN
+@LAB04.2bit_adder(sch_1):INS32@LAB04.full_adder(sch_1):INS30@LAB04.half_adder(sch_1):INS539@EVAL.7408.Normal(chips)
_    _(U1.U1.CARRY=U1_N00148)
_    _(U1.U1.SUM=SUM1)
_    _(U1.U1.x=N00076)
_    _(U1.U1.y=U1_N00070)
_    U1.U2(X=N00113 Y=N00117 CARRY=U1_N00160 SUM=U1_N00070 ) CN 
+@LAB04.2bit_adder(sch_1):INS32@LAB04.full_adder(sch_1):INS50@LAB04.half_adder(sch_1)
X_U1_U2_U1A          U1.U2.U1A(A=N00113 B=N00117 Y=U1_N00070 VCC=$G_DPWR GND=$G_DGND ) CN
+@LAB04.2bit_adder(sch_1):INS32@LAB04.full_adder(sch_1):INS50@LAB04.half_adder(sch_1):INS19@EVAL.7486.Normal(chips)
X_U1_U2_U2A          U1.U2.U2A(A=N00113 B=N00117 Y=U1_N00160 VCC=$G_DPWR GND=$G_DGND ) CN
+@LAB04.2bit_adder(sch_1):INS32@LAB04.full_adder(sch_1):INS50@LAB04.half_adder(sch_1):INS539@EVAL.7408.Normal(chips)
_    _(U1.U2.CARRY=U1_N00160)
_    _(U1.U2.SUM=U1_N00070)
_    _(U1.U2.x=N00113)
_    _(U1.U2.y=N00117)
_    _(U1.CARRY_IN=N00076)
_    _(U1.CARRY_OUT=CARRY_OUT)
_    _(U1.SUM=SUM1)
_    _(U1.X=N00113)
_    _(U1.Y=N00117)
_    U2(CARRY_IN=N00121 X=N00125 Y=N00129 CARRY_OUT=N00076 SUM=SUM0 ) CN @LAB04.2bit_adder(sch_1):INS54@LAB04.full_adder(sch_1)
X_U2_U3A          U2.U3A(A=U2_N00148 B=U2_N00160 Y=N00076 VCC=$G_DPWR GND=$G_DGND ) CN
+@LAB04.2bit_adder(sch_1):INS54@LAB04.full_adder(sch_1):INS107@EVAL.7432.Normal(chips)
_    U2.U1(X=N00121 Y=U2_N00070 CARRY=U2_N00148 SUM=SUM0 ) CN 
+@LAB04.2bit_adder(sch_1):INS54@LAB04.full_adder(sch_1):INS30@LAB04.half_adder(sch_1)
X_U2_U1_U1A          U2.U1.U1A(A=N00121 B=U2_N00070 Y=SUM0 VCC=$G_DPWR GND=$G_DGND ) CN
+@LAB04.2bit_adder(sch_1):INS54@LAB04.full_adder(sch_1):INS30@LAB04.half_adder(sch_1):INS19@EVAL.7486.Normal(chips)
X_U2_U1_U2A          U2.U1.U2A(A=N00121 B=U2_N00070 Y=U2_N00148 VCC=$G_DPWR GND=$G_DGND ) CN
+@LAB04.2bit_adder(sch_1):INS54@LAB04.full_adder(sch_1):INS30@LAB04.half_adder(sch_1):INS539@EVAL.7408.Normal(chips)
_    _(U2.U1.CARRY=U2_N00148)
_    _(U2.U1.SUM=SUM0)
_    _(U2.U1.x=N00121)
_    _(U2.U1.y=U2_N00070)
_    U2.U2(X=N00125 Y=N00129 CARRY=U2_N00160 SUM=U2_N00070 ) CN 
+@LAB04.2bit_adder(sch_1):INS54@LAB04.full_adder(sch_1):INS50@LAB04.half_adder(sch_1)
X_U2_U2_U1A          U2.U2.U1A(A=N00125 B=N00129 Y=U2_N00070 VCC=$G_DPWR GND=$G_DGND ) CN
+@LAB04.2bit_adder(sch_1):INS54@LAB04.full_adder(sch_1):INS50@LAB04.half_adder(sch_1):INS19@EVAL.7486.Normal(chips)
X_U2_U2_U2A          U2.U2.U2A(A=N00125 B=N00129 Y=U2_N00160 VCC=$G_DPWR GND=$G_DGND ) CN
+@LAB04.2bit_adder(sch_1):INS54@LAB04.full_adder(sch_1):INS50@LAB04.half_adder(sch_1):INS539@EVAL.7408.Normal(chips)
_    _(U2.U2.CARRY=U2_N00160)
_    _(U2.U2.SUM=U2_N00070)
_    _(U2.U2.x=N00125)
_    _(U2.U2.y=N00129)
_    _(U2.CARRY_IN=N00121)
_    _(U2.CARRY_OUT=N00076)
_    _(U2.SUM=SUM0)
_    _(U2.X=N00125)
_    _(U2.Y=N00129)
U_X1            X1(VCC=$G_DPWR GND=$G_DGND OUT=N00113 ) CN @LAB04.2bit_adder(sch_1):INS152@SOURCSTM.DigStim1.Normal(chips)
U_Y1            Y1(VCC=$G_DPWR GND=$G_DGND OUT=N00117 ) CN @LAB04.2bit_adder(sch_1):INS176@SOURCSTM.DigStim1.Normal(chips)
U_Carry_in          Carry_in(VCC=$G_DPWR GND=$G_DGND OUT=N00121 ) CN
+@LAB04.2bit_adder(sch_1):INS200@SOURCSTM.DigStim1.Normal(chips)
U_X0            X0(VCC=$G_DPWR GND=$G_DGND OUT=N00125 ) CN @LAB04.2bit_adder(sch_1):INS224@SOURCSTM.DigStim1.Normal(chips)
U_Y0            Y0(VCC=$G_DPWR GND=$G_DGND OUT=N00129 ) CN @LAB04.2bit_adder(sch_1):INS248@SOURCSTM.DigStim1.Normal(chips)
_    _(CARRY_OUT=CARRY_OUT)
_    _(SUM0=SUM0)
_    _(SUM1=SUM1)
.ENDALIASES
