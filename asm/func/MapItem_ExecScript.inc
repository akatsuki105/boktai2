	push {r4, r5, r6, r7, lr}
	sub sp, #0x30
	adds r4, r0, #0
	adds r7, r2, #0
	lsls r1, r1, #0x10
	lsrs r6, r1, #0x10
	cmp r6, #0
	beq _08005DB4
	movs r1, #4
	ldrsb r1, [r4, r1]
	movs r0, #1
	rsbs r0, r0, #0
	cmp r1, r0
	beq _08005DB4
	adds r2, r1, #0
	movs r3, #0xc
	ldr r1, _08005DBC @ =0x03002BC0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	ands r0, r3
	adds r5, r2, #0
	cmp r0, #0
	beq _08005DC0
_08005DB4:
	movs r0, #1
	rsbs r0, r0, #0
	b _08005E24
	.align 2, 0
_08005DBC: .4byte 0x03002BC0
_08005DC0:
	ldrb r0, [r4, #5]
	cmp r0, #1
	bne _08005DD6
	ldr r1, [r4, #0x2c]
	movs r2, #0
	ldrsh r0, [r1, r2]
	str r0, [sp]
	movs r2, #2
	ldrsh r0, [r1, r2]
	adds r0, #0x40
	b _08005DE2
_08005DD6:
	ldr r1, [r4, #0x2c]
	movs r2, #0
	ldrsh r0, [r1, r2]
	str r0, [sp]
	movs r2, #2
	ldrsh r0, [r1, r2]
_08005DE2:
	str r0, [sp, #4]
	movs r2, #4
	ldrsh r0, [r1, r2]
	str r0, [sp, #8]
	movs r1, #0
	ldrsh r0, [r4, r1]
	str r0, [sp, #0xc]
	movs r2, #2
	ldrsh r0, [r4, r2]
	str r0, [sp, #0x10]
	add r2, sp, #0x28
	adds r4, #0x38
	add r3, sp, #0x14
	movs r1, #2
_08005DFE:
	ldm r4!, {r0}
	stm r3!, {r0}
	subs r1, #1
	cmp r1, #0
	bge _08005DFE
	str r5, [sp, #0x20]
	str r7, [sp, #0x24]
	ldr r1, _08005E2C @ =0xFFFF0000
	ldr r0, [sp, #0x28]
	ands r0, r1
	movs r1, #0xa
	orrs r0, r1
	str r0, [sp, #0x28]
	mov r0, sp
	str r0, [r2, #4]
	adds r0, r6, #0
	adds r1, r2, #0
	bl Script_ExecById
_08005E24:
	add sp, #0x30
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_08005E2C: .4byte 0xFFFF0000
