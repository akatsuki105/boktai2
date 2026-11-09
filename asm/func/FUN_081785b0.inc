	push {r4, r5, r6, r7, lr}
	sub sp, #4
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r0, r1
	ldr r7, [r0]
	movs r0, #0xcb
	lsls r0, r0, #3
	adds r3, r7, r0
	ldr r1, _081785FC @ =0x00001022
	adds r0, r7, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _0817862E
	subs r1, #0x10
	adds r0, r7, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	subs r5, r0, #1
	cmp r5, #0
	blt _0817862E
	movs r2, #1
	lsls r0, r5, #3
	adds r0, r0, r5
	lsls r0, r0, #3
	adds r0, r0, r5
	lsls r0, r0, #2
	adds r1, r0, #0
	adds r1, #0x98
	adds r6, r1, r3
	adds r0, #0xfd
	adds r4, r0, r3
_081785F0:
	ldrb r0, [r4]
	ands r0, r2
	cmp r0, #0
	beq _08178600
	movs r0, #1
	b _08178602
	.align 2, 0
_081785FC: .4byte 0x00001022
_08178600:
	movs r0, #0
_08178602:
	cmp r0, #0
	bne _08178622
	adds r0, r6, #0
	str r2, [sp]
	bl Hitbox_Unregister
	ldrb r1, [r4]
	ldr r2, [sp]
	adds r0, r2, #0
	orrs r0, r1
	strb r0, [r4]
	ldr r0, _08178638 @ =0x00001022
	adds r1, r7, r0
	ldrb r0, [r1]
	subs r0, #1
	strb r0, [r1]
_08178622:
	ldr r1, _0817863C @ =0xFFFFFEDC
	adds r6, r6, r1
	adds r4, r4, r1
	subs r5, #1
	cmp r5, #0
	bge _081785F0
_0817862E:
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08178638: .4byte 0x00001022
_0817863C: .4byte 0xFFFFFEDC
