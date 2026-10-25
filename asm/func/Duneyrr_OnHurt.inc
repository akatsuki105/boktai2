	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	adds r6, r1, #0
	adds r5, r2, #0
	adds r7, r5, #0
	movs r1, #0x80
	lsls r1, r1, #1
	ldrh r0, [r4, #6]
	ands r0, r1
	cmp r0, #0
	beq _08023486
	adds r0, r4, #0
	adds r0, #0x42
	ldrb r0, [r0]
	b _0802349E
_08023486:
	movs r3, #0x24
	ldrsh r0, [r6, r3]
	movs r2, #0x24
	ldrsh r1, [r4, r2]
	subs r0, r0, r1
	movs r3, #0x28
	ldrsh r1, [r6, r3]
	movs r3, #0x28
	ldrsh r2, [r4, r3]
	subs r1, r1, r2
	bl ArcTan2_8
_0802349E:
	movs r2, #0xb3
	lsls r2, r2, #1
	adds r1, r5, r2
	strb r0, [r1]
	adds r0, r4, #0
	adds r1, r6, #0
	bl Hitbox_ApplyDamage
	ldrh r1, [r6, #0x3e]
	movs r3, #0xa8
	lsls r3, r3, #3
	adds r0, r7, r3
	strh r1, [r0]
	adds r1, r5, #0
	adds r1, #0xde
	ldrh r0, [r4, #0x3e]
	ldrb r1, [r1]
	adds r0, r0, r1
	strh r0, [r4, #0x3e]
	ldr r1, [r4, #0x34]
	adds r0, r5, #0
	adds r0, #0xb4
	str r1, [r0]
	ldr r1, [r4, #0x38]
	adds r0, #4
	str r1, [r0]
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
