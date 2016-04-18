.ALIASES
U_CLK           CLK(VCC=$G_DPWR GND=$G_DGND OUT=N00209 ) CN @LAB05.D-from-JK(sch_1):INS335@SOURCSTM.DigStim1.Normal(chips)
X_U1A           U1A(CLK=N00209 CLRbar=N00291 J=N00221 K=N00701 Q=Q Qbar=NOTQ VCC=$G_DPWR GND=$G_DGND ) CN
+@LAB05.D-from-JK(sch_1):INS38@EVAL.74107.Normal(chips)
U_D             D(VCC=$G_DPWR GND=$G_DGND OUT=N00221 ) CN @LAB05.D-from-JK(sch_1):INS306@SOURCSTM.DigStim1.Normal(chips)
X_U2A           U2A(A=N00221 Y=N00701 VCC=$G_DPWR GND=$G_DGND ) CN @LAB05.D-from-JK(sch_1):INS168@EVAL.7404.Normal(chips)
U_Clear_n          Clear_n(VCC=$G_DPWR GND=$G_DGND OUT=N00291 ) CN @LAB05.D-from-JK(sch_1):INS360@SOURCSTM.DigStim1.Normal(chips)
_    _(notQ=NOTQ)
_    _(Q=Q)
.ENDALIASES
