	push {r4, r5, r6, lr}
	sub sp, #0x24
	adds r6, r0, #0
	adds r5, r1, #0
	adds r0, r5, #0
	bl Entity5DA5Elem_ConsumeStateEntered
	cmp r0, #0
	beq _08008BF0
	ldr r0, [r5, #0x60]
	movs r1, #1
	orrs r0, r1
	str r0, [r5, #0x60]
	ldrb r0, [r5]
	lsls r1, r0
	ldrh r0, [r6, #0x1c]
	bics r0, r1
	movs r3, #0
	strh r0, [r6, #0x1c]
	ldr r1, _08008BF8 @ =0x085AA690
	ldrb r0, [r5]
	lsls r0, r0, #1
	adds r0, r0, r1
	ldrh r0, [r0]
	ldrh r1, [r6, #0x3c]
	adds r0, r0, r1
	lsls r0, r0, #0x10
	ldr r4, _08008BFC @ =0xFFFF0000
	movs r2, #0x80
	lsls r2, r2, #1
	adds r1, r2, #0
	ldrh r2, [r6, #0x3e]
	adds r1, r1, r2
	lsls r1, r1, #0x10
	lsrs r0, r0, #0x10
	orrs r0, r1
	str r0, [sp, #0x1c]
	adds r2, r6, #0
	adds r2, #0x40
	ldr r1, _08008C00 @ =0x085AA698
	ldrb r0, [r5]
	lsls r0, r0, #1
	adds r0, r0, r1
	ldrh r0, [r0]
	ldrh r2, [r2]
	adds r0, r0, r2
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, [sp, #0x20]
	ands r1, r4
	orrs r1, r0
	str r1, [sp, #0x20]
	ldr r2, _08008C04 @ =0x00002001
	str r3, [sp]
	str r3, [sp, #4]
	str r3, [sp, #8]
	str r3, [sp, #0xc]
	movs r0, #4
	str r0, [sp, #0x10]
	movs r0, #2
	str r0, [sp, #0x14]
	add r0, sp, #0x1c
	str r0, [sp, #0x18]
	movs r0, #1
	movs r1, #2
	movs r3, #0x40
	bl FUN_08015ce0
_08008BF0:
	add sp, #0x24
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08008BF8: .4byte 0x085AA690
_08008BFC: .4byte 0xFFFF0000
_08008C00: .4byte 0x085AA698
_08008C04: .4byte 0x00002001
