	push {r4, lr}
	sub sp, #0x28
	adds r3, r0, #0
	adds r4, r1, #0
	ldrh r0, [r3, #0x1a]
	cmp r0, #0
	beq _08008B5C
	str r2, [sp]
	cmp r4, #1
	bne _08008B12
	str r4, [sp, #4]
	ldrh r1, [r3, #0x1c]
	movs r0, #0xf
	ands r0, r1
	cmp r0, #0xf
	beq _08008B28
	movs r0, #0
	str r0, [sp, #8]
	b _08008B2A
_08008B12:
	cmp r4, #0
	bne _08008B2A
	str r4, [sp, #4]
	ldrh r1, [r3, #0x1c]
	movs r0, #0xf
	ands r0, r1
	cmp r0, #0
	bne _08008B28
	movs r0, #1
	str r0, [sp, #8]
	b _08008B2A
_08008B28:
	str r4, [sp, #8]
_08008B2A:
	ldrh r0, [r3, #0x38]
	asrs r0, r2
	movs r1, #1
	ands r0, r1
	str r0, [sp, #0xc]
	ldr r0, [r3, #0x24]
	str r0, [sp, #0x10]
	ldr r0, [r3, #0x28]
	str r0, [sp, #0x14]
	ldr r0, [r3, #0x2c]
	str r0, [sp, #0x18]
	ldr r0, [r3, #0x30]
	str r0, [sp, #0x1c]
	ldr r1, _08008B64 @ =0xFFFF0000
	ldr r0, [sp, #0x20]
	ands r0, r1
	movs r1, #8
	orrs r0, r1
	str r0, [sp, #0x20]
	add r1, sp, #0x20
	mov r0, sp
	str r0, [r1, #4]
	ldrh r0, [r3, #0x1a]
	bl VM_ExecByID
_08008B5C:
	add sp, #0x28
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08008B64: .4byte 0xFFFF0000
