.686
.model flat

public _LastIndexOf

.data

.code

_LastIndexOf proc
    mov edi, dword ptr [esp + 4]
    mov ecx, -1;
    xor al, al


    cld
    repne scasb

    neg ecx;
    sub ecx, 2;
    mov ebx, ecx;
    mov ecx, -1
    mov edi, dword ptr [esp + 8]

    cld
    repne scasb

    neg ecx;
    sub ecx, 2;
    mov edx, ecx;

    mov edi, dword ptr [esp + 4]
    mov esi, dword ptr [esp + 8]
    mov al, byte ptr [esi]
    mov ecx, ebx;
begin:
    jecxz not_eq
    dec ecx
    push ecx
    push edi
    add edi, ecx
    mov ecx, edx
    cld
    repe cmpsb
    jz found
 not_found:
    pop edi
    pop ecx
    mov esi, dword ptr [esp + 8]
    jmp begin
 found:
    pop edi
    pop ecx
    mov eax, ecx
    ret
 not_eq:
    mov eax, -1
    ret
    
    
_LastIndexOf endp

end
