	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r7, r1, #0
	ldrb r0, [r7, #5]
	cmp r0, #0
	beq _08017210
	movs r0, #0
	strb r0, [r7, #5]
	ldr r0, [r7, #0x2c]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r7, #0x2c]
_08017210:
	ldrb r0, [r7, #7]
	cmp r0, #3
	bne _08017228
	ldr r0, [r7, #0xc]
	cmp r0, #3
	bhi _08017222
	ldrh r0, [r7, #0x1a]
	adds r0, #0x40
	b _08017238
_08017222:
	ldrh r0, [r7, #0x1a]
	subs r0, #4
	b _08017238
_08017228:
	ldr r0, [r7, #0xc]
	cmp r0, #4
	bhi _08017234
	ldrh r0, [r7, #0x1a]
	adds r0, #0x40
	b _08017238
_08017234:
	ldrh r0, [r7, #0x1a]
	subs r0, #8
_08017238:
	strh r0, [r7, #0x1a]
	adds r0, r7, #0
	bl ItemIconPopup_ProjectPos
	ldrb r0, [r7, #7]
	cmp r0, #3
	bne _080172A8
	ldr r0, [r7, #0xc]
	cmp r0, #3
	bls _0801728C
	ldr r0, _0801729C @ =0x0203B400
	mov r8, r0
	ldr r4, _080172A0 @ =0x030046B8
	ldr r1, [r4]
	adds r1, #1
	ldr r6, _080172A4 @ =0x000003FF
	ands r1, r6
	str r1, [r4]
	lsls r0, r1, #1
	add r0, r8
	ldrh r2, [r0]
	adds r3, r7, #0
	adds r3, #0x44
	ldrh r0, [r3]
	subs r0, #1
	movs r5, #3
	ands r2, r5
	adds r0, r0, r2
	strh r0, [r3]
	adds r1, #1
	ands r1, r6
	str r1, [r4]
	lsls r1, r1, #1
	add r1, r8
	ldrh r1, [r1]
	adds r2, r7, #0
	adds r2, #0x46
	ldrh r0, [r2]
	subs r0, #1
	ands r1, r5
	adds r0, r0, r1
	strh r0, [r2]
_0801728C:
	ldrb r0, [r7, #7]
	cmp r0, #3
	bne _080172A8
	ldr r0, [r7, #0xc]
	cmp r0, #8
	bls _080172BC
	b _080172AE
	.align 2, 0
_0801729C: .4byte 0x0203B400
_080172A0: .4byte 0x030046B8
_080172A4: .4byte 0x000003FF
_080172A8:
	ldr r0, [r7, #0xc]
	cmp r0, #7
	bls _080172BC
_080172AE:
	movs r0, #4
	movs r1, #0
	strb r0, [r7, #4]
	movs r0, #1
	strb r0, [r7, #5]
	str r1, [r7, #0xc]
	b _080172C0
_080172BC:
	adds r0, #1
	str r0, [r7, #0xc]
_080172C0:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
