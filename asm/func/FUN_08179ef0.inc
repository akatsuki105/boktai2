	push {r4, lr}
	sub sp, #0xc
	adds r1, r0, #0
	movs r2, #0xe6
	lsls r2, r2, #1
	adds r0, r1, r2
	ldr r0, [r0]
	ldr r2, _08179F30 @ =0x00000FA8
	adds r4, r0, r2
	ldrh r0, [r4]
	cmp r0, #0
	beq _08179F28
	ldrh r0, [r1]
	str r0, [sp]
	ldr r1, _08179F34 @ =0xFFFF0000
	ldr r0, [sp, #4]
	ands r0, r1
	movs r1, #1
	orrs r0, r1
	str r0, [sp, #4]
	add r1, sp, #4
	mov r0, sp
	str r0, [r1, #4]
	ldrh r0, [r4]
	bl VM_ExecByID
	movs r0, #0
	strh r0, [r4]
_08179F28:
	add sp, #0xc
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08179F30: .4byte 0x00000FA8
_08179F34: .4byte 0xFFFF0000
