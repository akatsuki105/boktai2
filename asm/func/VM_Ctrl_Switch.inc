	push {lr}
	sub sp, #0xc
	movs r1, #0
	str r1, [sp, #8]
	add r2, sp, #4
	mov r1, sp
	bl VM_Step
	bl VM_SetPC
_08232368:
	bl VM_Ctrl_Switch_Internal
	cmp r0, #0
	bne _08232374
	movs r0, #0
	b _082323AA
_08232374:
	cmp r0, #0x63
	bne _08232390
	bl Script_GetValue
	ldr r1, [sp, #4]
	cmp r0, r1
	bne _08232368
	bl VM_GetPC
	mov r1, sp
	add r2, sp, #8
	bl VM_Step
	b _082323A0
_08232390:
	cmp r0, #0x64
	bne _08232368
	bl VM_GetPC
	mov r1, sp
	add r2, sp, #8
	bl VM_Step
_082323A0:
	ldr r0, [sp, #8]
	movs r1, #0
	movs r2, #0
	bl Script_ExecBlock
_082323AA:
	add sp, #0xc
	pop {r1}
	bx r1
