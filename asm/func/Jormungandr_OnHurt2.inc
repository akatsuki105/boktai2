	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	adds r6, r1, #0
	adds r4, r2, #0
	adds r7, r6, #0
	adds r7, #0x44
	ldrh r0, [r7]
	cmp r0, #0
	bne _080C466E
	movs r1, #0x80
	lsls r1, r1, #0xc
	adds r0, r4, #0
	adds r0, #0x98
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	bne _080C466E
	ldr r1, _080C4674 @ =0x000025C8
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _080C466A
	adds r0, r5, #0
	adds r1, r6, #0
	bl Hitbox_ApplyDamage
	ldr r2, _080C4678 @ =0x00001914
	adds r1, r4, r2
	ldrh r0, [r6, #0x3e]
	ldrh r3, [r1]
	adds r0, r0, r3
	strh r0, [r1]
	ldr r0, _080C467C @ =0x0000191C
	adds r1, r4, r0
	ldrh r0, [r1]
	movs r2, #8
	orrs r0, r2
	strh r0, [r1]
	ldr r1, _080C4680 @ =0x000025C4
	adds r0, r4, r1
	strb r2, [r0]
	ldr r3, _080C4684 @ =0x000025D8
	adds r2, r4, r3
	movs r0, #0xbe
	lsls r0, r0, #2
	adds r1, r4, r0
	str r1, [r2]
	ldrh r0, [r5, #0xc]
	ldrh r1, [r1]
	subs r0, r0, r1
	adds r3, #4
	adds r1, r4, r3
	strh r0, [r1]
	ldr r1, [r2]
	ldrh r0, [r5, #0xe]
	ldrh r1, [r1, #2]
	subs r0, r0, r1
	adds r3, #2
	adds r1, r4, r3
	strh r0, [r1]
	ldr r1, [r2]
	ldrh r0, [r5, #0x10]
	ldrh r1, [r1, #4]
	subs r0, r0, r1
	ldr r2, _080C4688 @ =0x000025E0
	adds r1, r4, r2
	strh r0, [r1]
	adds r3, #6
	adds r1, r4, r3
	movs r0, #0x10
	strh r0, [r1]
	adds r0, r5, #0
	adds r0, #0x42
	ldrb r1, [r0]
	subs r2, #0xb
	adds r0, r4, r2
	strb r1, [r0]
	subs r3, #0x18
	adds r1, r4, r3
	ldrh r0, [r5, #0x3e]
	ldrh r1, [r1]
	adds r0, r0, r1
	strh r0, [r5, #0x3e]
	ldr r1, [r5, #0x34]
	subs r2, #5
	adds r0, r4, r2
	str r1, [r0]
_080C466A:
	movs r0, #0xf
	strh r0, [r7]
_080C466E:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080C4674: .4byte 0x000025C8
_080C4678: .4byte 0x00001914
_080C467C: .4byte 0x0000191C
_080C4680: .4byte 0x000025C4
_080C4684: .4byte 0x000025D8
_080C4688: .4byte 0x000025E0
