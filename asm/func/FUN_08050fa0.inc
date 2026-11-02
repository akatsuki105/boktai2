	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	mov ip, r1
	mov r8, r2
	ldrb r0, [r1, #1]
	cmp r0, #0
	beq _0805101C
	movs r3, #0
	strb r3, [r1, #1]
	strb r3, [r1, #4]
	mov r7, ip
	adds r7, #0x50
	mov r2, ip
	adds r2, #0x6c
	movs r1, #3
	mov r0, r8
	ands r1, r0
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r0, #0x50
	strh r0, [r2]
	movs r0, #0x90
	strh r0, [r2, #2]
	strh r3, [r2, #4]
	mov r1, ip
	ldrb r0, [r1, #4]
	cmp r0, #0
	beq _08051012
	ldr r6, _080510B0 @ =0x0203B400
	ldr r3, _080510B4 @ =0x030046B8
	ldr r1, [r3]
	adds r1, #1
	ldr r5, _080510B8 @ =0x000003FF
	ands r1, r5
	str r1, [r3]
	lsls r0, r1, #1
	adds r0, r0, r6
	ldrh r2, [r0]
	ldrh r0, [r7, #0x1c]
	subs r0, #1
	movs r4, #3
	ands r2, r4
	adds r0, r0, r2
	strh r0, [r7, #0x1c]
	adds r1, #1
	ands r1, r5
	str r1, [r3]
	lsls r1, r1, #1
	adds r1, r1, r6
	ldrh r1, [r1]
	ldrh r0, [r7, #0x1e]
	subs r0, #1
	ands r1, r4
	adds r0, r0, r1
	strh r0, [r7, #0x1e]
_08051012:
	mov r2, ip
	ldr r0, [r2, #0x6c]
	ldr r1, [r2, #0x70]
	str r0, [r2, #0x40]
	str r1, [r2, #0x44]
_0805101C:
	mov r1, ip
	ldrb r0, [r1, #3]
	cmp r0, #0
	beq _080510BC
	strh r0, [r1, #0x34]
	ldrb r0, [r1, #2]
	mov r7, ip
	adds r7, #0x50
	strh r0, [r7, #0x10]
	ldr r0, [r1, #0x24]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	mov r2, ip
	str r0, [r2, #0x24]
	ldr r0, [r2, #0x50]
	ands r0, r1
	str r0, [r2, #0x50]
	ldrb r0, [r2, #4]
	cmp r0, #0
	beq _080510CE
	subs r0, #1
	strb r0, [r2, #4]
	adds r2, #0x6c
	movs r1, #3
	mov r0, r8
	ands r1, r0
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r0, #0x50
	strh r0, [r2]
	movs r0, #0x90
	strh r0, [r2, #2]
	movs r0, #0
	strh r0, [r2, #4]
	mov r1, ip
	ldrb r0, [r1, #4]
	cmp r0, #0
	beq _080510A2
	ldr r6, _080510B0 @ =0x0203B400
	ldr r3, _080510B4 @ =0x030046B8
	ldr r1, [r3]
	adds r1, #1
	ldr r5, _080510B8 @ =0x000003FF
	ands r1, r5
	str r1, [r3]
	lsls r0, r1, #1
	adds r0, r0, r6
	ldrh r2, [r0]
	ldrh r0, [r7, #0x1c]
	subs r0, #1
	movs r4, #3
	ands r2, r4
	adds r0, r0, r2
	strh r0, [r7, #0x1c]
	adds r1, #1
	ands r1, r5
	str r1, [r3]
	lsls r1, r1, #1
	adds r1, r1, r6
	ldrh r1, [r1]
	ldrh r0, [r7, #0x1e]
	subs r0, #1
	ands r1, r4
	adds r0, r0, r1
	strh r0, [r7, #0x1e]
_080510A2:
	mov r2, ip
	ldr r0, [r2, #0x6c]
	ldr r1, [r2, #0x70]
	str r0, [r2, #0x40]
	str r1, [r2, #0x44]
	b _080510CE
	.align 2, 0
_080510B0: .4byte 0x0203B400
_080510B4: .4byte 0x030046B8
_080510B8: .4byte 0x000003FF
_080510BC:
	mov r1, ip
	ldr r0, [r1, #0x24]
	movs r1, #1
	orrs r0, r1
	mov r2, ip
	str r0, [r2, #0x24]
	ldr r0, [r2, #0x50]
	orrs r0, r1
	str r0, [r2, #0x50]
_080510CE:
	mov r1, ip
	ldr r0, [r1, #8]
	adds r0, #1
	str r0, [r1, #8]
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
