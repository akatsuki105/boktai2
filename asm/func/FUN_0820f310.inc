	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	mov ip, r0
	ldr r0, [r0, #0x18]
	adds r0, #0x20
	mov r1, ip
	str r0, [r1, #0x18]
	movs r3, #0x28
	add r3, ip
	mov sb, r3
	movs r7, #0
	movs r6, #0xd5
	lsls r6, r6, #2
	add r6, ip
	str r6, [sp]
	ldr r0, _0820F384 @ =0x00000356
	add r0, ip
	str r0, [sp, #4]
	ldr r1, _0820F388 @ =0x085AF0B0
	mov r8, r1
	movs r3, #0xd6
	lsls r3, r3, #2
	add r3, ip
	mov sl, r3
_0820F348:
	ldr r6, [sp]
	movs r0, #0
	ldrsh r2, [r6, r0]
	mov r1, r8
	movs r4, #0
	ldrsb r4, [r1, r4]
	ldr r3, [sp, #4]
	movs r6, #0
	ldrsh r1, [r3, r6]
	mov r0, r8
	movs r3, #1
	ldrsb r3, [r0, r3]
	mov r6, sl
	movs r0, #0
	ldrsh r5, [r6, r0]
	mov r6, sb
	adds r6, #0x8c
	ldr r0, [r6]
	adds r2, r2, r4
	adds r1, r1, r3
	strh r2, [r0]
	strh r1, [r0, #2]
	strh r5, [r0, #4]
	mov r1, ip
	ldr r0, [r1, #0x18]
	cmp r0, #0
	blt _0820F38C
	asrs r1, r0, #5
	b _0820F392
	.align 2, 0
_0820F384: .4byte 0x00000356
_0820F388: .4byte 0x085AF0B0
_0820F38C:
	rsbs r0, r0, #0
	asrs r0, r0, #5
	rsbs r1, r0, #0
_0820F392:
	lsls r0, r7, #5
	adds r0, r1, r0
	movs r2, #8
	subs r2, r2, r7
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	ldr r3, _0820F3B4 @ =0x085B0A08
	adds r0, r0, r3
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r2, r0
	cmp r0, #0
	blt _0820F3B8
	asrs r2, r0, #0xd
	b _0820F3BE
	.align 2, 0
_0820F3B4: .4byte 0x085B0A08
_0820F3B8:
	rsbs r0, r0, #0
	asrs r0, r0, #0xd
	rsbs r2, r0, #0
_0820F3BE:
	ldr r1, [r6]
	ldrh r0, [r1]
	adds r0, r0, r2
	strh r0, [r1]
	movs r3, #0x94
	add sb, r3
	movs r6, #2
	add r8, r6
	adds r7, #1
	cmp r7, #4
	ble _0820F348
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
