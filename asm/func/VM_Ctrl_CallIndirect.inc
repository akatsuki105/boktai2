	push {r4, r5, r6, lr}
	sub sp, #0x50
	bl Script_GetValue
	adds r6, r0, #0
	bl VM_GetPC
	adds r3, r0, #0
	movs r4, #0
	add r5, sp, #0x48
	b _08232472
_08232466:
	lsls r0, r4, #2
	mov r2, sp
	adds r1, r2, r0
	ldr r0, [sp, #0x44]
	str r0, [r1]
	adds r4, #1
_08232472:
	cmp r3, #0
	beq _08232488
	add r1, sp, #0x40
	add r2, sp, #0x44
	adds r0, r3, #0
	bl VM_Step
	adds r3, r0, #0
	ldr r0, [sp, #0x40]
	cmp r0, #0
	bne _08232466
_08232488:
	lsls r1, r4, #0x10
	lsrs r1, r1, #0x10
	ldr r2, _082324AC @ =0xFFFF0000
	ldr r0, [sp, #0x48]
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #0x48]
	mov r0, sp
	str r0, [r5, #4]
	adds r0, r6, #0
	adds r1, r5, #0
	bl Script_ExecById
	add sp, #0x50
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_082324AC: .4byte 0xFFFF0000
