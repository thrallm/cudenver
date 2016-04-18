.ALIASES
U_T             T(VCC=$G_DPWR GND=$G_DGND OUT=N00172 ) CN @LAB05.test-T-from-JK(sch_1):INS127@SOURCSTM.DigStim1.Normal(chips)
U_Clear_n          Clear_n(VCC=$G_DPWR GND=$G_DGND OUT=N00523 ) CN
+@LAB05.test-T-from-JK(sch_1):INS79@SOURCSTM.DigStim1.Normal(chips)
_    U1(CLEAR_N=N00523 CLK=N00495 T=N00172 NOTQ=NOTQ Q=Q ) CN @LAB05.test-T-from-JK(sch_1):INS46@LAB05.T-from-JK(sch_1)
X_U1_U1A          U1.U1A(CLK=N00495 CLRbar=N00523 J=N00172 K=N00172 Q=Q Qbar=NOTQ VCC=$G_DPWR GND=$G_DGND ) CN
+@LAB05.test-T-from-JK(sch_1):INS46@LAB05.T-from-JK(sch_1):INS19@EVAL.74107.Normal(chips)
_    _(U1.Clear_n=N00523)
_    _(U1.CLK=N00495)
_    _(U1.notQ=NOTQ)
_    _(U1.Q=Q)
_    _(U1.T=N00172)
U_CLK           CLK(VCC=$G_DPWR GND=$G_DGND OUT=N00495 ) CN @LAB05.test-T-from-JK(sch_1):INS103@SOURCSTM.DigStim1.Normal(chips)
_    _(notQ=NOTQ)
_    _(Q=Q)
.ENDALIASES
