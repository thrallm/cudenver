.ALIASES
X_U1A           U1A(A=N00746 B=N00750 Y=SUM VCC=$G_DPWR GND=$G_DGND ) CN
+@LAB04.half_adder_demo(sch_1):INS700@EVAL.7486.Normal(chips)
X_U2A           U2A(A=N00746 B=N00750 Y=CARRY VCC=$G_DPWR GND=$G_DGND ) CN
+@LAB04.half_adder_demo(sch_1):INS722@EVAL.7408.Normal(chips)
U_X             X(VCC=$G_DPWR GND=$G_DGND OUT=N00746 ) CN @LAB04.half_adder_demo(sch_1):INS897@SOURCSTM.DigStim1.Normal(chips)
U_Y             Y(VCC=$G_DPWR GND=$G_DGND OUT=N00750 ) CN @LAB04.half_adder_demo(sch_1):INS926@SOURCSTM.DigStim1.Normal(chips)
_    _(CARRY=CARRY)
_    _(SUM=SUM)
.ENDALIASES
