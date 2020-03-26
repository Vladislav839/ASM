.686
.model flat
option casemap: none

public _IntegrateCotan

.data?
	a qword ?
	b qword ?
	h qword ?
	tmp qword ?
	n dword ?
	i dword ?
	two dword ?

.code

_IntegrateCotan proc
	FINIT; 
	FILD dword ptr [esp + 4]; 
	FISTP n
	;--------------считаем а
	FLDPI;
	FLD1;
	FLD1;
	FADDP;
	FLD1;
	FLD1;
	FADDP;
	FADDP;
	FDIVP;
	FSTP a;
	; ----------считаем b
	FLDPI;
	FLD1;
	FLD1;
	FADDP;
	FDIVP;
	FSTP b
	;---------- считаем h
	FLD b;
	FLD a;
	FSUBP;
	FILD n;
	FDIVP;
	FSTP h;
	;------------загрузим двойку
	FLD1;
	FLD1;
	FADDP;
	FISTP two;
	;-------считаем сумму из формулы
	FLDZ;
	mov ecx, dword ptr[esp + 4]
	sub ecx, 1;
	mov i, 1;
begin:
    FLD1;
	FILD i;
	FLD h;
	FMULP;
	FLD a;
	FADDP;
	FPTAN;
	FSTP tmp;
	FDIVP;
	FADDP;
	inc i;
	loop begin
	FILD two;
	FMULP;
	FLD1;
	FLD a;
	FPTAN;
	FSTP tmp;
	FDIVP;
	FADDP;
	FLD h;
	FMULP;
	FILD two;
	FDIV;
	RET
_IntegrateCotan endp


end
