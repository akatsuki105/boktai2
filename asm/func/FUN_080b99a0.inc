	push {r4, r5, r6, r7, lr}
	sub sp, #0x18
	adds r6, r0, #0
	ldr r0, _080B9A00 @ =0x0000CB05
	ldr r1, _080B9A04 @ =0x00005D04
	bl GetFile
	adds r1, r0, #0
	adds r2, r6, #0
	ldm r0!, {r3, r4, r5}
	stm r2!, {r3, r4, r5}
	ldm r0!, {r3, r4, r5}
	stm r2!, {r3, r4, r5}
	ldm r0!, {r3, r4}
	stm r2!, {r3, r4}
	adds r0, r6, #0
	bl OpenMainSpriteFile
	ldr r1, _080B9A08 @ =0xFFFF0000
	movs r0, #0
	str r0, [sp, #0x10]
	ldr r0, [sp, #0x14]
	ands r0, r1
	str r0, [sp, #0x14]
	movs r7, #0
	adds r4, r6, #0
	adds r4, #0x20
	movs r5, #1
_080B99D8:
	str r7, [sp]
	str r7, [sp, #4]
	movs r0, #0x3c
	str r0, [sp, #8]
	add r0, sp, #0x10
	str r0, [sp, #0xc]
	adds r0, r4, #0
	adds r1, r6, #0
	movs r2, #0
	movs r3, #0x31
	bl MainSprite_Add
	adds r4, #0x60
	subs r5, #1
	cmp r5, #0
	bge _080B99D8
	add sp, #0x18
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080B9A00: .4byte 0x0000CB05
_080B9A04: .4byte 0x00005D04
_080B9A08: .4byte 0xFFFF0000
