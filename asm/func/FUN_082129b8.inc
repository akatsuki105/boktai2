	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	movs r1, #0x94
	adds r1, r1, r0
	mov sl, r1
	movs r2, #0x83
	lsls r2, r2, #3
	adds r3, r0, r2
	movs r4, #0
	ldrsh r2, [r3, r4]
	cmp r2, #1
	beq _08212A08
	cmp r2, #1
	bgt _082129E0
	cmp r2, #0
	beq _082129E6
	b _08212B58
_082129E0:
	cmp r2, #2
	beq _08212AB8
	b _08212B58
_082129E6:
	ldr r4, _08212A04 @ =0x0000041A
	adds r1, r0, r4
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x1d
	bgt _082129FA
	b _08212B58
_082129FA:
	movs r0, #1
	strh r0, [r3]
	strh r2, [r1]
	b _08212B58
	.align 2, 0
_08212A04: .4byte 0x0000041A
_08212A08:
	ldr r2, _08212AB0 @ =0x0000041A
	adds r1, r0, r2
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	movs r4, #0
	ldrsh r1, [r1, r4]
	movs r0, #0x1e
	subs r0, r0, r1
	mov r8, r0
	movs r0, #0
	mov sb, r0
_08212A20:
	mov r1, sb
	lsls r5, r1, #1
	movs r4, #0xd0
	lsls r4, r4, #2
	add r4, sl
	adds r4, r4, r5
	ldrh r1, [r4]
	movs r0, #0x1f
	ands r0, r1
	mov r2, r8
	muls r2, r0, r2
	adds r0, r2, #0
	movs r1, #0x1e
	bl Div
	adds r6, r0, #0
	ldrh r1, [r4]
	movs r0, #0xf8
	lsls r0, r0, #2
	ands r0, r1
	mov r1, r8
	muls r1, r0, r1
	adds r0, r1, #0
	movs r1, #0x1e
	bl Div
	adds r7, r0, #0
	ldrh r1, [r4]
	movs r0, #0xf8
	lsls r0, r0, #7
	ands r0, r1
	mov r2, r8
	muls r2, r0, r2
	adds r0, r2, #0
	movs r1, #0x1e
	bl Div
	adds r1, r0, #0
	movs r0, #0xc0
	lsls r0, r0, #2
	add r0, sl
	adds r0, r0, r5
	movs r4, #0x1f
	ands r6, r4
	movs r2, #0xf8
	lsls r2, r2, #2
	ands r7, r2
	orrs r6, r7
	movs r4, #0xf8
	lsls r4, r4, #7
	ands r1, r4
	orrs r6, r1
	strh r6, [r0]
	movs r0, #1
	add sb, r0
	mov r1, sb
	cmp r1, #0x1f
	ble _08212A20
	ldr r3, _08212AB4 @ =0x00000386
	add r3, sl
	movs r2, #0
	ldrsh r0, [r3, r2]
	cmp r0, #0x1d
	ble _08212B58
	movs r0, #0xe1
	lsls r0, r0, #2
	add r0, sl
	movs r2, #0
	movs r1, #2
	strh r1, [r0]
	strh r2, [r3]
	b _08212B58
	.align 2, 0
_08212AB0: .4byte 0x0000041A
_08212AB4: .4byte 0x00000386
_08212AB8:
	ldr r4, _08212B68 @ =0x0000041A
	adds r1, r0, r4
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	movs r2, #0
	ldrsh r0, [r1, r2]
	mov r8, r0
	movs r4, #0
	mov sb, r4
_08212ACC:
	mov r0, sb
	lsls r5, r0, #1
	movs r4, #0xd0
	lsls r4, r4, #2
	add r4, sl
	adds r4, r4, r5
	ldrh r1, [r4]
	movs r0, #0x1f
	ands r0, r1
	mov r1, r8
	muls r1, r0, r1
	adds r0, r1, #0
	movs r1, #0x1e
	bl Div
	adds r6, r0, #0
	ldrh r1, [r4]
	movs r0, #0xf8
	lsls r0, r0, #2
	ands r0, r1
	mov r2, r8
	muls r2, r0, r2
	adds r0, r2, #0
	movs r1, #0x1e
	bl Div
	adds r7, r0, #0
	ldrh r1, [r4]
	movs r0, #0xf8
	lsls r0, r0, #7
	ands r0, r1
	mov r4, r8
	muls r4, r0, r4
	adds r0, r4, #0
	movs r1, #0x1e
	bl Div
	adds r1, r0, #0
	movs r0, #0xc0
	lsls r0, r0, #2
	add r0, sl
	adds r0, r0, r5
	movs r2, #0x1f
	ands r6, r2
	movs r4, #0xf8
	lsls r4, r4, #2
	ands r7, r4
	orrs r6, r7
	movs r2, #0xf8
	lsls r2, r2, #7
	ands r1, r2
	orrs r6, r1
	strh r6, [r0]
	movs r4, #1
	add sb, r4
	mov r0, sb
	cmp r0, #0x1f
	ble _08212ACC
	ldr r2, _08212B6C @ =0x00000386
	add r2, sl
	movs r1, #0
	ldrsh r0, [r2, r1]
	cmp r0, #0x1d
	ble _08212B58
	movs r1, #0xe1
	lsls r1, r1, #2
	add r1, sl
	movs r0, #0
	strh r0, [r1]
	strh r0, [r2]
_08212B58:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08212B68: .4byte 0x0000041A
_08212B6C: .4byte 0x00000386
