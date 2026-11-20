	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r5, r0, #0
	ldr r0, _081C17AC @ =0x0000046D
	adds r1, r5, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _081C17B0
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _081C17B2
	.align 2, 0
_081C17AC: .4byte 0x0000046D
_081C17B0:
	movs r0, #0
_081C17B2:
	cmp r0, #0
	beq _081C17E8
	adds r0, r5, #0
	movs r1, #0
	movs r2, #0x7f
	movs r3, #0
	bl Enemy_SetEmote
	adds r0, r5, #0
	movs r1, #1
	movs r2, #0x7f
	movs r3, #0
	bl Enemy_SetEmote
	adds r0, r5, #0
	movs r1, #3
	movs r2, #0x7f
	movs r3, #0
	bl Enemy_SetEmote
	movs r0, #0x10
	movs r1, #0xc0
	lsls r1, r1, #1
	adds r2, r5, r1
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
_081C17E8:
	adds r0, r5, #0
	movs r1, #1
	bl Enemy_PlayAnim
	ldr r2, _081C1890 @ =0x00000482
	adds r2, r2, r5
	mov r8, r2
	movs r7, #0
	movs r0, #4
	strh r0, [r2]
	ldr r3, _081C1894 @ =0x00000464
	adds r0, r5, r3
	ldrh r6, [r0]
	cmp r6, #0
	bne _081C1886
	ldr r1, _081C1898 @ =0x0000046B
	adds r0, r5, r1
	movs r4, #1
	strb r4, [r0]
	adds r0, r5, #0
	movs r1, #6
	bl Enemy_PlayAnim
	ldr r2, _081C189C @ =0x00000494
	adds r1, r5, r2
	movs r0, #0x20
	strh r0, [r1]
	movs r1, #3
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r0, r5, r3
	strb r1, [r0]
	ldr r1, _081C18A0 @ =0x00000469
	adds r0, r5, r1
	strb r7, [r0]
	subs r2, #0x2a
	adds r0, r5, r2
	strb r7, [r0]
	adds r3, #0x1c
	adds r0, r5, r3
	str r6, [r0]
	adds r1, #3
	adds r0, r5, r1
	strb r4, [r0]
	ldr r2, _081C18A4 @ =GolemLink_StateBurnRecover
	movs r1, #0x13
	subs r3, #0x17
	adds r0, r5, r3
	strb r4, [r0]
	subs r3, #2
	adds r0, r5, r3
	strb r7, [r0]
	adds r3, #0xe8
	adds r0, r5, r3
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r5, r1
	str r2, [r0]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r0, r5, r2
	strh r6, [r0]
	movs r3, #0xc0
	lsls r3, r3, #1
	adds r2, r5, r3
	movs r0, #0x31
	rsbs r0, r0, #0
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	mov r0, r8
	strh r4, [r0]
	movs r2, #0x10
	subs r3, #8
	adds r1, r5, r3
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
_081C1886:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081C1890: .4byte 0x00000482
_081C1894: .4byte 0x00000464
_081C1898: .4byte 0x0000046B
_081C189C: .4byte 0x00000494
_081C18A0: .4byte 0x00000469
_081C18A4: .4byte GolemLink_StateBurnRecover
