	push {lr}
	bl Script_GetValue
	cmp r0, #0
	bne _08231BDA
	bl VM_GetValueSafe1
_08231BDA:
	movs r0, #0
	pop {r1}
	bx r1
