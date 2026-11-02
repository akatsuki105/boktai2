	push {r4, r5, r6, lr}
	sub sp, #8
	adds r2, r0, #0
	adds r4, r1, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _08053F72
	movs r1, #0
	strb r1, [r4, #0xe]
	ldr r0, [r4, #0x20]
	cmp r0, #3
	beq _08053F6E
	str r1, [sp]
	movs r0, #4
	str r0, [sp, #4]
	adds r0, r2, #0
	adds r1, r4, #0
	movs r2, #3
	movs r3, #1
	bl BlackPantherElem_PlayAnim
_08053F6E:
	ldrb r0, [r4, #9]
	strb r0, [r4, #8]
_08053F72:
	adds r5, r4, #0
	adds r5, #0x74
	movs r0, #0
	ldrsh r2, [r5, r0]
	ldr r1, _08053FA4 @ =0x085AB740
	ldrb r0, [r4, #8]
	lsls r0, r0, #1
	adds r3, r0, r1
	movs r1, #0
	ldrsh r0, [r3, r1]
	subs r2, r2, r0
	cmp r2, #0
	bge _08053F8E
	rsbs r2, r2, #0
_08053F8E:
	cmp r2, #0xc
	bgt _08053FA8
	ldrh r0, [r3]
	movs r1, #0
	strh r0, [r5]
	movs r0, #3
	strb r0, [r4, #0xd]
	movs r0, #1
	strb r0, [r4, #0xe]
	str r1, [r4, #0x1c]
	b _08053FC8
	.align 2, 0
_08053FA4: .4byte 0x085AB740
_08053FA8:
	ldrh r2, [r5]
	movs r6, #0
	ldrsh r1, [r5, r6]
	movs r6, #0
	ldrsh r0, [r3, r6]
	cmp r1, r0
	bge _08053FBC
	adds r0, r2, #0
	adds r0, #0xc
	b _08053FC0
_08053FBC:
	adds r0, r2, #0
	subs r0, #0xc
_08053FC0:
	strh r0, [r5]
	ldr r0, [r4, #0x1c]
	adds r0, #1
	str r0, [r4, #0x1c]
_08053FC8:
	add sp, #8
	pop {r4, r5, r6}
	pop {r0}
	bx r0
