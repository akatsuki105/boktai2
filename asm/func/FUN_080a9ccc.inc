	push {r4, r5, r6, lr}
	sub sp, #0x30
	adds r4, r0, #0
	ldr r0, _080A9D28 @ =0x0000CB05
	ldr r1, _080A9D2C @ =0x00005D04
	bl GetFile
	adds r1, r0, #0
	add r2, sp, #0x10
	ldm r0!, {r3, r5, r6}
	stm r2!, {r3, r5, r6}
	ldm r0!, {r3, r5, r6}
	stm r2!, {r3, r5, r6}
	ldm r0!, {r3, r5}
	stm r2!, {r3, r5}
	add r0, sp, #0x10
	bl OpenMainSpriteFile
	adds r2, r4, #0
	adds r2, #0x7c
	movs r1, #0
	movs r0, #8
	strh r0, [r2]
	adds r3, r4, #0
	adds r3, #0x7e
	movs r0, #0x18
	strh r0, [r3]
	adds r0, r4, #0
	adds r0, #0x80
	strh r1, [r0]
	subs r0, #0x64
	str r1, [sp]
	str r1, [sp, #4]
	movs r1, #0x3c
	str r1, [sp, #8]
	str r2, [sp, #0xc]
	add r1, sp, #0x10
	movs r2, #0x98
	movs r3, #0x33
	bl MainSprite_Add
	add sp, #0x30
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080A9D28: .4byte 0x0000CB05
_080A9D2C: .4byte 0x00005D04
