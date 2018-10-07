
DATA SEGMENT
	Chsl1	DD	13
	Chsl2	dd	2.72
	Chsl3	dq	-7.85
	Chsl4	dq	-4
	var1	dd	2048
	var2	dq	-2048
	12var	dd	345
	kjsdkf	db	231
	adsfasdfasfafa	dd	345
	var3	dd	12121212121212121212
DATA ENDS
	
	
	
CODE SEGMENT
	
	Ftst	
	Fadd st(3) ,st(0)
	Fsub ES:Chsl1[edi*4]
	Fsub ES:Chsl1[edi]
	Fsub ES:[edi]
	Fsubp  st(3) ,st(0)
	Fxch st(8)
	Fsub CS:var[edi*4]
	Fsub DS:Chsl1[edi*4]
	Fsub ES:Chsl1[ebp*4]
	Fsub SS:Chsl1[ebp*4]
	Fsub DS:Chsl1[ebp*4]
	
	Fsub CS:var2[edi*4]
	Fsub DS:Chsl1[edi*4]
	Fsub ES:Chsl2[ebx*8]
	Fsub SS:Chsl3[ebp*8]
	Fsub DS:Chsl4[ebp*4]
	
	Fsub SS:Chsl2[eax*2]
	Fsubp  st(5) ,st(0)
	FXch st(3)
	Fsubp  st(0) ,st(0)
	
	Fsub ES:Chsl3[ebx*8]
	Fsubp  st(2) ,st(0)
	Fxch st(6)
	Fxch st(0)
	
	Fsub DS:Chsl4[esi*8]
	Fsubp  st(2) ,st(0)
	Fxch st(5)
	
CODE ENDS
END