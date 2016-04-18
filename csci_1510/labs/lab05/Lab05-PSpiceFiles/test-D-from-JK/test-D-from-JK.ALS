.ALIASES
U_CLK           CLK(VCC=$G_DPWR GND=$G_DGND OUT=N00165 ) CN @LAB05.test-D-from-JK(sch_1):INS103@SOURCSTM.DigStim1.Normal(chips)
U_D             D(VCC=$G_DPWR GND=$G_DGND OUT=N00173 ) CN @LAB05.test-D-from-JK(sch_1):INS127@SOURCSTM.DigStim1.Normal(chips)
_    U1(CLEAR_N=N00944 CLK=N00165 D=N00173 NOTQ=NOTQ Q=Q ) CN @LAB05.test-D-from-JK(sch_1):INS46@LAB05.D-from-JK(sch_1)
X_U1_U1A          U1.U1A(CLK=N00165 CLRbar=N00944 J=N00173 K=U1_N00701 Q=Q Qbar=NOTQ VCC=$G_DPWR GND=$G_DGND ) CN
+@LAB05.test-D-from-JK(sch_1):INS46@LAB05.D-from-JK(sch_1):INS19@EVAL.74107.Normal(chips)
X_U1_U2A          U1.U2A(A=N00173 Y=U1_N00701 VCC=$G_DPWR GND=$G_DGND ) CN
+@LAB05.test-D-from-JK(sch_1):INS46@LAB05.D-from-JK(sch_1):INS66@EVAL.7404.Normal(chips)
_    _(U1.Clear_n=N00944)
_    _(U1.CLK=N00165)
_    _(U1.D=N00173)
_    _(U1.notQ=NOTQ)
_    _(U1.Q=Q)
U_Clear_n          Clear_n(VCC=$G_DPWR GND=$G_DGND OUT=N00944 ) CN
+@LAB05.test-D-from-JK(sch_1):INS920@SOURCSTM.DigStim1.Normal(chips)
_    _(notQ=NOTQ)
_    _(Q=Q)
.ENDALIASES
