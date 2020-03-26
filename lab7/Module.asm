.686
.model flat

public _TrimAll
public _IsWhitespace@1

.data

.code

_IsWhitespace@1 proc
    mov bl, byte ptr [esp + 1]
    cmp bl, ' '
    jne end_
    mov eax, 1
    end_:
    mov eax, 0
    ret 1
_IsWhitespace@1 endp

_TrimAll proc
    enter 0, 0 
    mov     ebx, dword ptr [ebp + 08h] 
    mov     ecx, ebx        
    push    ebx             


skip_lead:                              
    mov     dl, [ecx]       
    inc     ecx           
    cmp     dl, 32    
    je      skip_lead     
    dec     ecx             
    dec     ebx            

shift_left:               
    mov     dl, [ecx]       
    inc     ebx            
    inc     ecx             
    mov     [ebx], dl       
    or      dl, dl          
    jnz     shift_left      
    pop     ecx             

skip_trail:
    dec     ebx             
    cmp     byte ptr [ebx], 32                               
    je      skip_trail                                      
    inc     ebx             
    mov     byte ptr [ebx], 0    
    sub     ebx, ecx 
    mov     esi, ecx
    mov     ecx, ebx;
    push    ecx;
    mov     edi,esi          
    xor     bx,bx          
cycle:                  
    lodsb                
    cmp     bl,' '         
    jne     miss           
    cmp     bx,'  '        
     je     next           
miss:                   
    stosb               
next:                   
    xchg    bh,bl          
    loop    cycle          
   
    mov     bl,0

    pop     eax;
    inc     eax;
    leave
    ret
     
_TrimAll endp

end
