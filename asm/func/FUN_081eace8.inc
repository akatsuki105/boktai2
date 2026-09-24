	push {r4, r5, r6, r7, lr}
	sub sp, #0x10
	adds r7, r0, #0
	ldr r0, _081EAD4C @ =0x030001C0
	ldr r5, [r0]
	lsls r4, r2, #1
	adds r4, r4, r2
	lsls r0, r1, #3
	adds r0, r0, r1
	adds r4, r4, r0
	movs r1, #0x95
	lsls r1, r1, #1
	adds r0, r7, r1
	movs r6, #0
	strh r4, [r0]
	subs r1, #2
	adds r0, r7, r1
	strh r3, [r0]
	adds r1, #4
	adds r0, r7, r1
	movs r1, #1
	strh r1, [r0]
	adds r5, #0x18
	str r1, [sp]
	movs r0, #2
	str r0, [sp, #4]
	movs r0, #0x78
	str r0, [sp, #8]
	adds r0, r7, #0
	adds r0, #0xd0
	str r0, [sp, #0xc]
	adds r0, r7, #0
	adds r1, r5, #0
	movs r2, #0xd
	movs r3, #0
	bl MainSprite_Add
	ldr r0, _081EAD50 @ =0x085AE478
	ldrb r2, [r0, #0x12]
	str r6, [sp]
	adds r0, r7, #0
	adds r1, r5, #0
	movs r3, #2
	bl MainSprite_SetAnim
	add sp, #0x10
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081EAD4C: .4byte 0x030001C0
_081EAD50: .4byte 0x085AE478
