Vector3D struct
    X dq ?
    Y dq ?
    Z dq ?
Vector3D ends

Vector2D struct
    X dq ?
    Y dq ?
Vector2D ends


PUBLIC SUM
PUBLIC GetLength

.data
   temp dq ?

.code
    SUM proc    
        LOCAL v1: Vector3D
        LOCAL result: Vector3D

        MOV rax, qword ptr [rcx]
        MOV v1.X, rax
        MOV rax, qword ptr [rcx + 8]
        MOV v1.Y, rax
        MOV rax, qword ptr [rcx + 16]
        MOV v1.Z, rax

        MOV r8, v1.X
        ADD r8, qword ptr [rdx]
        MOV r9, v1.Y
        ADD r9, qword ptr [rdx + 8]
        MOV r10, v1.Y
        ADD r10, qword ptr [rdx + 16]

        MOV result.X, r8
        MOV result.Y, r9
        MOV result.Z, r10
        LEA rax, result

        RET
    SUM endp

    GetLength proc    
        LOCAL v: Vector2D

        MOV rax, qword ptr [rcx]
        MOV v.X, rax
        MOV rax, qword ptr [rcx + 8]
        MOV v.Y, rax

        FINIT
        FLD v.X
        FLD v.X
        FMULP
        FLD v.Y
        FLD v.Y
        FMULP
        FADDP
        FSQRT
        FSTP temp
        lea rax, temp

        RET
    GetLength endp

end
