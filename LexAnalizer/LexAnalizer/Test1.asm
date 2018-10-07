DATA SEGMENT
	Chsl1	DD	13
	Chsl2	dd	2.72
	Chsl3	dq	-7.85
	Chsl4	dq	-4
DATA ENDS
	
CODE SEGMENT
	
	Ftst	
	Fsub ES:Chl1[edi*4]
	Fsbp  st(3) ,st(0)
	Fxch st(4)
	
	Fsub DS:Chsl2[eax*2]
	Fsubp  st(5) ,st(0)
	Fch st(3)
	
	Fsub ES:Chsl3[ebx*8]
	Fsubp  st(2) ,st(0)
	Fxch st(6)
	
	Fsub DS:Chsl4[esi*8]
	Fsubp  st(2) ,st(0)
	Fxch st(5)
	
CODE ENDS
END