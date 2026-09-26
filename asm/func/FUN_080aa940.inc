	push {r4, r5, r6, lr}
	sub sp, #0x30
	adds r5, r0, #0
	ldr r0, _080AA9C8 @ =0x0000CB05
	ldr r1, _080AA9CC @ =0x00005D04
	bl GetFile
	adds r1, r0, #0
	add r2, sp, #0x10
	ldm r0!, {r3, r4, r6}
	stm r2!, {r3, r4, r6}
	ldm r0!, {r3, r4, r6}
	stm r2!, {r3, r4, r6}
	ldm r0!, {r3, r4}
	stm r2!, {r3, r4}
	add r0, sp, #0x10
	bl OpenMainSpriteFile
	movs r6, #0xd2
	lsls r6, r6, #2
	adds r0, r5, r6
	ldrh r0, [r0]
	movs r2, #0x2c
	cmp r0, #0
	bne _080AA974
	movs r2, #0x27
_080AA974:
	adds r3, r5, #0
	adds r3, #0x84
	ldrh r0, [r3]
	subs r0, #8
	adds r1, r5, #0
	adds r1, #0x7c
	movs r4, #0
	strh r0, [r1]
	adds r0, r5, #0
	adds r0, #0x86
	ldrh r0, [r0]
	subs r0, #0x28
	adds r1, #2
	strh r0, [r1]
	adds r0, r5, #0
	adds r0, #0x88
	ldrh r1, [r0]
	subs r0, #8
	strh r1, [r0]
	subs r0, #0x64
	adds r2, #0x68
	movs r1, #1
	str r1, [sp]
	str r4, [sp, #4]
	movs r1, #0x3c
	str r1, [sp, #8]
	str r3, [sp, #0xc]
	add r1, sp, #0x10
	movs r3, #0x32
	bl MainSprite_Add
	adds r0, r5, #0
	adds r0, #0x51
	movs r1, #0x22
	strb r1, [r0]
	subs r0, #1
	strb r1, [r0]
	add sp, #0x30
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080AA9C8: .4byte 0x0000CB05
_080AA9CC: .4byte 0x00005D04
