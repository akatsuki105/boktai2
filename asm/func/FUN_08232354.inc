	push {lr}
	sub sp, #0xc
	movs r1, #0
	str r1, [sp, #8]
	add r2, sp, #4
	mov r1, sp
	bl VM_Step
	bl FUN_08231504
_08232368:
	bl FUN_0823155c
	cmp r0, #0
	bne _08232374
	movs r0, #0
	b _082323AA
_08232374:
	cmp r0, #0x63
	bne _08232390
	bl fetch_082316e4
	ldr r1, [sp, #4]
	cmp r0, r1
	bne _08232368
	bl FUN_082316bc
	mov r1, sp
	add r2, sp, #8
	bl VM_Step
	b _082323A0
_08232390:
	cmp r0, #0x64
	bne _08232368
	bl FUN_082316bc
	mov r1, sp
	add r2, sp, #8
	bl VM_Step
_082323A0:
	ldr r0, [sp, #8]
	movs r1, #0
	movs r2, #0
	bl FUN_08231ad0
_082323AA:
	add sp, #0xc
	pop {r1}
	bx r1
