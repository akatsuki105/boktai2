	push {r4, r5, r6, r7, lr}
	sub sp, #0x18
	adds r4, r0, #0
	adds r5, r1, #0
	ldr r0, _080A60B4 @ =0x0000CB05
	ldr r1, _080A60B8 @ =0x0000DCC1
	bl GetFile
	adds r2, r0, #0
	cmp r2, #0
	beq _080A6108
	adds r1, r4, #0
	adds r1, #0x18
	ldm r0!, {r3, r6, r7}
	stm r1!, {r3, r6, r7}
	ldm r0!, {r3, r6, r7}
	stm r1!, {r3, r6, r7}
	ldm r0!, {r3, r6}
	stm r1!, {r3, r6}
	adds r7, r4, #0
	adds r7, #0x18
	adds r0, r7, #0
	adds r1, r2, #0
	bl OpenMainSpriteFile
	ldr r1, _080A60BC @ =0xFFFF0000
	movs r6, #0
	str r6, [sp, #0x10]
	ldr r0, [sp, #0x14]
	ands r0, r1
	str r0, [sp, #0x14]
	cmp r5, #0
	bne _080A60C0
	adds r4, #0x38
	str r5, [sp]
	str r5, [sp, #4]
	movs r0, #0x3c
	str r0, [sp, #8]
	add r0, sp, #0x10
	str r0, [sp, #0xc]
	adds r0, r4, #0
	adds r1, r7, #0
	movs r2, #0x20
	movs r3, #0x30
	bl MainSprite_Add
	str r5, [sp]
	adds r0, r4, #0
	adds r1, r7, #0
	movs r2, #0
	movs r3, #2
	bl MainSprite_SetAnim
	b _080A6108
	.align 2, 0
_080A60B4: .4byte 0x0000CB05
_080A60B8: .4byte 0x0000DCC1
_080A60BC: .4byte 0xFFFF0000
_080A60C0:
	cmp r5, #1
	bne _080A60E0
	adds r0, r4, #0
	adds r0, #0x38
	str r6, [sp]
	str r6, [sp, #4]
	movs r1, #0x3c
	str r1, [sp, #8]
	add r1, sp, #0x10
	str r1, [sp, #0xc]
	adds r1, r7, #0
	movs r2, #0x25
	movs r3, #0x30
	bl MainSprite_Add
	b _080A6108
_080A60E0:
	adds r4, #0x38
	str r6, [sp]
	str r6, [sp, #4]
	movs r0, #0x3c
	str r0, [sp, #8]
	add r3, sp, #0x10
	str r3, [sp, #0xc]
	adds r0, r4, #0
	adds r1, r7, #0
	movs r2, #0x20
	movs r3, #0x30
	bl MainSprite_Add
	str r6, [sp]
	adds r0, r4, #0
	adds r1, r7, #0
	movs r2, #0
	movs r3, #2
	bl MainSprite_SetAnim
_080A6108:
	add sp, #0x18
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
