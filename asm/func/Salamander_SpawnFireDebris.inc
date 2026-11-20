	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0x40
	mov r8, r0
	ldr r4, _081ACB00 @ =0x0203B400
	ldr r3, _081ACB04 @ =0x030046B8
	ldr r0, [r3]
	adds r0, #1
	ldr r2, _081ACB08 @ =0x000003FF
	ands r0, r2
	lsls r1, r0, #1
	adds r1, r1, r4
	movs r5, #0xff
	ldrb r7, [r1]
	adds r0, #1
	ands r0, r2
	str r0, [r3]
	lsls r0, r0, #1
	adds r0, r0, r4
	ldrh r4, [r0]
	movs r0, #0x1f
	add r6, sp, #0x38
	ands r4, r0
	ldr r1, _081ACB0C @ =gSineTable
	adds r0, r7, #0
	adds r0, #0x40
	ands r0, r5
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r4, r0
	mov ip, r3
	cmp r0, #0
	blt _081ACB10
	asrs r2, r0, #0xc
	b _081ACB16
	.align 2, 0
_081ACB00: .4byte 0x0203B400
_081ACB04: .4byte 0x030046B8
_081ACB08: .4byte 0x000003FF
_081ACB0C: .4byte gSineTable
_081ACB10:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_081ACB16:
	movs r0, #0
	strh r2, [r6]
	strh r0, [r6, #2]
	lsls r0, r7, #1
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r4, r0
	cmp r0, #0
	blt _081ACB2E
	asrs r0, r0, #0xc
	b _081ACB34
_081ACB2E:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_081ACB34:
	movs r4, #0
	strh r0, [r6, #4]
	ldr r5, _081ACBAC @ =0x0203B400
	mov r2, ip
	ldr r1, [r2]
	adds r1, #1
	ldr r3, _081ACBB0 @ =0x000003FF
	ands r1, r3
	lsls r0, r1, #1
	adds r0, r0, r5
	ldrh r0, [r0]
	movs r2, #0x1f
	ands r0, r2
	subs r0, #0x10
	add r2, sp, #0x38
	strh r0, [r2, #2]
	adds r1, #1
	ands r1, r3
	mov r0, ip
	str r1, [r0]
	lsls r1, r1, #1
	adds r1, r1, r5
	ldrh r1, [r1]
	movs r0, #0x3f
	ands r1, r0
	adds r1, #0x14
	ldr r2, _081ACBB4 @ =0x00001C1A
	ldr r3, _081ACBB8 @ =0x0000D1B8
	movs r0, #3
	str r0, [sp]
	str r4, [sp, #4]
	movs r0, #0x31
	str r0, [sp, #8]
	str r4, [sp, #0xc]
	movs r0, #2
	str r0, [sp, #0x10]
	str r4, [sp, #0x14]
	str r4, [sp, #0x18]
	str r1, [sp, #0x1c]
	movs r0, #4
	str r0, [sp, #0x20]
	movs r0, #1
	str r0, [sp, #0x24]
	ldr r0, _081ACBBC @ =0x00200004
	str r0, [sp, #0x28]
	movs r0, #0x1e
	str r0, [sp, #0x2c]
	movs r0, #8
	str r0, [sp, #0x30]
	str r0, [sp, #0x34]
	mov r0, r8
	add r1, sp, #0x38
	bl Debris_Spawn
	add sp, #0x40
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081ACBAC: .4byte 0x0203B400
_081ACBB0: .4byte 0x000003FF
_081ACBB4: .4byte 0x00001C1A
_081ACBB8: .4byte 0x0000D1B8
_081ACBBC: .4byte 0x00200004
