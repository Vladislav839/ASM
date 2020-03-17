686
.model flat

public _TrimAll

.data

.code


_TrimAll proc
    mov     eax, dword ptr [esp + 4] 
    mov     ecx, eax        
    push    eax             


skip_lead:                                  
    mov     dl, [ecx]       
    inc     ecx           
    cmp     dl, 32          
    je      skip_lead     
    dec     ecx             
    dec     eax            

shift_left:               
    mov     dl, [ecx]       
    inc     eax            
    inc     ecx             
    mov     [eax], dl       
    or      dl, dl          
    jnz     shift_left      
    pop     ecx             

skip_trail:
    dec     eax             
    cmp     byte ptr [eax], 32                               
    je      skip_trail                                      
    inc     eax             
    mov     byte ptr [eax], 0    
    sub     eax, ecx 
    mov     esi, ecx
    mov     ecx, eax;
    xor     ebx, ebx;
    push    ecx;
    mov     edi,esi          
    xor     ax,ax          
cycle:                  
    lodsb                
    cmp     al,' '         
    jne     miss           
    cmp     ax,'  '        
    je      next           
miss:                   
    stosb               
next:                   
    inc     ebx;
    xchg    ah,al          
    loop    cycle          
   
    mov     al,0

    pop     eax;
    inc     eax;
    ret
     
_TrimAll endp

end
