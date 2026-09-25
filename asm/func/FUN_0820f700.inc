	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x10
	adds r6, r0, #0
	ldr r0, [r6, #0x18]
	adds r0, #0x20
	str r0, [r6, #0x18]
	adds r7, r6, #0
	adds r7, #0x28
	movs r0, #0
	mov sb, r0
	ldr r1, _0820F754 @ =0x085AF0D8
	mov sl, r1
	movs r2, #0
	str r2, [sp, #0xc]
	movs r3, #0xb4
	adds r3, r3, r6
	mov r8, r3
_0820F72A:
	mov r4, sb
	cmp r4, #0
	bne _0820F764
	ldr r0, _0820F758 @ =0x085AF0E2
	ldrh r1, [r0]
	ldr r5, _0820F75C @ =0x00000366
	adds r0, r6, r5
	ldrb r2, [r0]
	ldr r3, _0820F760 @ =0x00000367
	adds r0, r6, r3
	ldrb r3, [r0]
	movs r0, #1
	str r0, [sp]
	str r4, [sp, #4]
	movs r0, #5
	str r0, [sp, #8]
	adds r0, r7, #0
	bl FUN_08055b5c
	b _0820F782
	.align 2, 0
_0820F754: .4byte 0x085AF0D8
_0820F758: .4byte 0x085AF0E2
_0820F75C: .4byte 0x00000366
_0820F760: .4byte 0x00000367
_0820F764:
	ldr r0, _0820F7CC @ =0x085AF0E2
	ldr r4, [sp, #0xc]
	adds r0, r4, r0
	ldrh r1, [r0]
	movs r0, #1
	str r0, [sp]
	movs r0, #0
	str r0, [sp, #4]
	movs r0, #5
	str r0, [sp, #8]
	adds r0, r7, #0
	movs r2, #1
	movs r3, #0
	bl FUN_08055b5c
_0820F782:
	adds r0, r7, #0
	bl FUN_08055c04
	movs r5, #0xd5
	lsls r5, r5, #2
	adds r0, r6, r5
	movs r1, #0
	ldrsh r2, [r0, r1]
	mov r3, sl
	ldrb r3, [r3]
	lsls r3, r3, #0x18
	asrs r3, r3, #0x18
	mov ip, r3
	ldr r4, _0820F7D0 @ =0x00000356
	adds r0, r6, r4
	movs r5, #0
	ldrsh r1, [r0, r5]
	mov r0, sl
	movs r3, #1
	ldrsb r3, [r0, r3]
	adds r4, #2
	adds r0, r6, r4
	movs r5, #0
	ldrsh r4, [r0, r5]
	mov r5, r8
	ldr r0, [r5]
	add r2, ip
	adds r1, r1, r3
	strh r2, [r0]
	strh r1, [r0, #2]
	strh r4, [r0, #4]
	ldr r0, [r6, #0x18]
	mov r4, r8
	cmp r0, #0
	blt _0820F7D4
	asrs r1, r0, #5
	b _0820F7DA
	.align 2, 0
_0820F7CC: .4byte 0x085AF0E2
_0820F7D0: .4byte 0x00000356
_0820F7D4:
	rsbs r0, r0, #0
	asrs r0, r0, #5
	rsbs r1, r0, #0
_0820F7DA:
	mov r2, sb
	lsls r0, r2, #5
	adds r0, r1, r0
	movs r2, #8
	mov r3, sb
	subs r2, r2, r3
	ldr r3, _0820F800 @ =0x085B0A08
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r3
	movs r5, #0
	ldrsh r0, [r0, r5]
	muls r0, r2, r0
	cmp r0, #0
	blt _0820F804
	asrs r2, r0, #0xd
	b _0820F80A
	.align 2, 0
_0820F800: .4byte 0x085B0A08
_0820F804:
	rsbs r0, r0, #0
	asrs r0, r0, #0xd
	rsbs r2, r0, #0
_0820F80A:
	ldr r1, [r4]
	ldrh r0, [r1, #2]
	adds r0, r0, r2
	strh r0, [r1, #2]
	movs r0, #0x94
	add r8, r0
	adds r7, #0x94
	movs r1, #2
	add sl, r1
	ldr r2, [sp, #0xc]
	adds r2, #2
	str r2, [sp, #0xc]
	movs r3, #1
	add sb, r3
	mov r4, sb
	cmp r4, #4
	bgt _0820F82E
	b _0820F72A
_0820F82E:
	add sp, #0x10
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
