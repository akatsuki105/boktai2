	push {r4, r5, r6, r7, lr}
	sub sp, #4
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r0, r1
	ldr r7, [r0]
	movs r2, #0xcb
	lsls r2, r2, #3
	adds r1, r7, r2
	ldr r4, _08190724 @ =0x00000F46
	adds r0, r7, r4
	ldrb r0, [r0]
	cmp r0, #0
	beq _0819075A
	ldr r2, _08190728 @ =0x00000F36
	adds r0, r7, r2
	movs r4, #0
	ldrsh r0, [r0, r4]
	subs r5, r0, #1
	cmp r5, #0
	blt _0819075A
	movs r3, #1
	lsls r0, r5, #3
	adds r0, r0, r5
	lsls r0, r0, #3
	adds r0, r0, r5
	lsls r2, r0, #2
	adds r0, r2, #0
	adds r0, #0x98
	adds r6, r0, r1
	movs r4, #0x91
	lsls r4, r4, #1
	adds r0, r2, r4
	adds r4, r0, r1
_08190718:
	ldrh r0, [r4]
	ands r0, r3
	cmp r0, #0
	beq _0819072C
	movs r0, #1
	b _0819072E
	.align 2, 0
_08190724: .4byte 0x00000F46
_08190728: .4byte 0x00000F36
_0819072C:
	movs r0, #0
_0819072E:
	cmp r0, #0
	bne _0819074E
	adds r0, r6, #0
	str r3, [sp]
	bl Hitbox_Unregister
	ldrh r1, [r4]
	ldr r3, [sp]
	adds r0, r3, #0
	orrs r0, r1
	strh r0, [r4]
	ldr r0, _08190764 @ =0x00000F46
	adds r1, r7, r0
	ldrb r0, [r1]
	subs r0, #1
	strb r0, [r1]
_0819074E:
	ldr r1, _08190768 @ =0xFFFFFEDC
	adds r6, r6, r1
	adds r4, r4, r1
	subs r5, #1
	cmp r5, #0
	bge _08190718
_0819075A:
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08190764: .4byte 0x00000F46
_08190768: .4byte 0xFFFFFEDC
