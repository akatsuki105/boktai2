	push {r4, r5, r6, lr}
	sub sp, #0x18
	adds r5, r0, #0
	ldr r0, _0809F4A4 @ =0x0000CB05
	ldr r1, _0809F4A8 @ =0x0000B343
	bl GetFile
	adds r2, r0, #0
	cmp r2, #0
	beq _0809F49A
	adds r1, r5, #0
	adds r1, #0x60
	ldm r0!, {r3, r4, r6}
	stm r1!, {r3, r4, r6}
	ldm r0!, {r3, r4, r6}
	stm r1!, {r3, r4, r6}
	ldm r0!, {r3, r4}
	stm r1!, {r3, r4}
	adds r4, r5, #0
	adds r4, #0x60
	adds r0, r4, #0
	adds r1, r2, #0
	bl OpenMainSpriteFile
	ldr r1, _0809F4AC @ =0xFFFF0000
	movs r0, #0
	str r0, [sp, #0x10]
	ldr r0, [sp, #0x14]
	ands r0, r1
	str r0, [sp, #0x14]
	adds r6, r4, #0
	adds r4, #0x20
	movs r5, #3
_0809F476:
	movs r0, #1
	str r0, [sp]
	movs r0, #0
	str r0, [sp, #4]
	movs r0, #0x3c
	str r0, [sp, #8]
	add r0, sp, #0x10
	str r0, [sp, #0xc]
	adds r0, r4, #0
	adds r1, r6, #0
	movs r2, #0x1e
	movs r3, #0x31
	bl MainSprite_Add
	adds r4, #0x60
	subs r5, #1
	cmp r5, #0
	bge _0809F476
_0809F49A:
	add sp, #0x18
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0809F4A4: .4byte 0x0000CB05
_0809F4A8: .4byte 0x0000B343
_0809F4AC: .4byte 0xFFFF0000
