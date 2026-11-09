	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r0, r1
	ldr r0, [r0]
	movs r6, #0
	movs r1, #1
	mov r8, r1
	movs r1, #0x80
	mov ip, r1
	movs r1, #0xcb
	lsls r1, r1, #3
	adds r3, r0, r1
	ldr r1, _08192394 @ =0x0000077A
	adds r4, r0, r1
	movs r7, #0x92
	lsls r7, r7, #1
	movs r5, #5
_08192386:
	ldrh r0, [r4]
	mov r1, r8
	ands r0, r1
	cmp r0, #0
	beq _08192398
	movs r0, #1
	b _0819239A
	.align 2, 0
_08192394: .4byte 0x0000077A
_08192398:
	movs r0, #0
_0819239A:
	cmp r0, #0
	bne _081923C8
	movs r0, #0x90
	lsls r0, r0, #1
	adds r1, r3, r0
	ldrh r0, [r1]
	cmp r0, #0
	beq _081923B0
	subs r0, #1
	strh r0, [r1]
	b _081923C8
_081923B0:
	cmp r6, #1
	bgt _081923C8
	movs r0, #2
	strh r0, [r1]
	movs r1, #0x91
	lsls r1, r1, #1
	adds r2, r3, r1
	ldrh r1, [r2]
	mov r0, ip
	orrs r0, r1
	strh r0, [r2]
	adds r6, #1
_081923C8:
	adds r3, r3, r7
	adds r4, r4, r7
	subs r5, #1
	cmp r5, #0
	bge _08192386
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
