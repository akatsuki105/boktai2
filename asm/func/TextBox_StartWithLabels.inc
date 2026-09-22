	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r6, r0, #0
	adds r7, r1, #0
	mov r8, r2
	mov sb, r3
	ldr r0, _08047A04 @ =0x030000C4
	ldr r5, [r0]
	cmp r5, #0
	beq _080479F4
	adds r4, r5, #0
	adds r4, #0x18
	movs r1, #0xd0
	lsls r1, r1, #1
	adds r0, r5, r1
	str r6, [r0]
	adds r0, r5, #0
	movs r1, #0
	bl TextBox_GetLine
	str r0, [r4, #0x1c]
	movs r2, #0xd2
	lsls r2, r2, #1
	adds r0, r5, r2
	mov r1, r8
	strh r1, [r0]
	movs r0, #0xd3
	lsls r0, r0, #1
	adds r2, r5, r0
	strh r7, [r2]
	lsls r0, r7, #0x10
	lsrs r0, r0, #0x10
	adds r6, r4, #0
	cmp r0, #0x20
	bls _080479A6
	movs r0, #0x20
	strh r0, [r2]
_080479A6:
	movs r4, #0
	ldrh r1, [r2]
	cmp r4, r1
	bge _080479C6
	mov r3, sb
	movs r0, #0xd4
	lsls r0, r0, #1
	adds r1, r5, r0
_080479B6:
	ldrh r0, [r3]
	strh r0, [r1]
	adds r3, #2
	adds r1, #2
	adds r4, #1
	ldrh r0, [r2]
	cmp r4, r0
	blt _080479B6
_080479C6:
	movs r1, #0xd2
	lsls r1, r1, #1
	adds r0, r5, r1
	ldrh r1, [r0]
	lsls r1, r1, #1
	movs r2, #0xd4
	lsls r2, r2, #1
	adds r0, r5, r2
	adds r0, r0, r1
	ldrh r0, [r0]
	subs r2, #0x16
	adds r1, r5, r2
	strh r0, [r1]
	adds r0, r6, #0
	bl FUN_08049640
	movs r0, #0x85
	lsls r0, r0, #2
	adds r2, r5, r0
	ldr r0, [r2]
	movs r1, #1
	orrs r0, r1
	str r0, [r2]
_080479F4:
	movs r0, #0
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_08047A04: .4byte 0x030000C4
