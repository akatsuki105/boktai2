	push {r4, r5, r6, r7, lr}
	sub sp, #0x18
	adds r7, r0, #0
	ldr r0, _080C20F0 @ =0x0000CB05
	ldr r1, _080C20F4 @ =0x0000DF11
	bl GetFile
	adds r1, r0, #0
	adds r2, r7, #0
	adds r2, #0x18
	ldm r0!, {r3, r4, r5}
	stm r2!, {r3, r4, r5}
	ldm r0!, {r3, r4, r5}
	stm r2!, {r3, r4, r5}
	ldm r0!, {r3, r4}
	stm r2!, {r3, r4}
	adds r6, r7, #0
	adds r6, #0x18
	adds r0, r6, #0
	bl OpenMainSpriteFile
	ldr r1, _080C20F8 @ =0xFFFF0000
	movs r4, #0
	str r4, [sp, #0x10]
	ldr r0, [sp, #0x14]
	ands r0, r1
	str r0, [sp, #0x14]
	adds r0, r7, #0
	adds r0, #0x38
	str r4, [sp]
	str r4, [sp, #4]
	movs r5, #0x3c
	str r5, [sp, #8]
	add r1, sp, #0x10
	str r1, [sp, #0xc]
	adds r1, r6, #0
	movs r2, #0xf
	movs r3, #0x30
	bl MainSprite_Add
	adds r0, r7, #0
	adds r0, #0x98
	str r4, [sp]
	str r4, [sp, #4]
	str r5, [sp, #8]
	add r3, sp, #0x10
	str r3, [sp, #0xc]
	adds r1, r6, #0
	movs r2, #0xb
	movs r3, #0x30
	bl MainSprite_Add
	adds r0, r7, #0
	adds r0, #0xf8
	str r4, [sp]
	str r4, [sp, #4]
	str r5, [sp, #8]
	add r1, sp, #0x10
	str r1, [sp, #0xc]
	adds r1, r6, #0
	movs r2, #2
	movs r3, #0x30
	bl MainSprite_Add
	movs r3, #0xdc
	lsls r3, r3, #1
	adds r0, r7, r3
	str r4, [sp]
	str r4, [sp, #4]
	str r5, [sp, #8]
	add r1, sp, #0x10
	str r1, [sp, #0xc]
	adds r1, r6, #0
	movs r2, #5
	movs r3, #0x30
	bl MainSprite_Add
	movs r3, #0xac
	lsls r3, r3, #1
	adds r0, r7, r3
	str r4, [sp]
	str r4, [sp, #4]
	str r5, [sp, #8]
	add r4, sp, #0x10
	str r4, [sp, #0xc]
	adds r1, r6, #0
	movs r2, #0
	movs r3, #0x30
	bl MainSprite_Add
	add sp, #0x18
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080C20F0: .4byte 0x0000CB05
_080C20F4: .4byte 0x0000DF11
_080C20F8: .4byte 0xFFFF0000
