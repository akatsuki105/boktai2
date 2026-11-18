	push {r4, r5, lr}
	sub sp, #0x18
	adds r5, r0, #0
	adds r3, r1, #0
	ldrh r0, [r5, #0x1c]
	cmp r0, #0
	beq _081E12F4
	movs r1, #0
	ldrsb r1, [r3, r1]
	movs r0, #1
	rsbs r0, r0, #0
	cmp r1, r0
	beq _081E12F4
	adds r4, r1, #0
	movs r2, #0xc
	ldr r1, _081E12FC @ =0x03002BC0
	lsls r0, r4, #2
	adds r0, r0, r1
	ldr r0, [r0]
	ands r0, r2
	cmp r0, #0
	beq _081E1300
_081E12F4:
	movs r0, #1
	rsbs r0, r0, #0
	b _081E1338
	.align 2, 0
_081E12FC: .4byte 0x03002BC0
_081E1300:
	str r4, [sp]
	adds r0, r3, #0
	adds r0, #0x40
	movs r1, #0
	ldrsh r0, [r0, r1]
	str r0, [sp, #4]
	adds r0, r3, #0
	adds r0, #0x42
	movs r1, #0
	ldrsh r0, [r0, r1]
	str r0, [sp, #8]
	adds r0, r3, #0
	adds r0, #0x44
	movs r1, #0
	ldrsh r0, [r0, r1]
	str r0, [sp, #0xc]
	ldr r1, _081E1340 @ =0xFFFF0000
	ldr r0, [sp, #0x10]
	ands r0, r1
	movs r1, #4
	orrs r0, r1
	str r0, [sp, #0x10]
	add r1, sp, #0x10
	mov r0, sp
	str r0, [r1, #4]
	ldrh r0, [r5, #0x1c]
	bl VM_ExecByID
_081E1338:
	add sp, #0x18
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_081E1340: .4byte 0xFFFF0000
