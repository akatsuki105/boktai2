	push {r4, r5, r6, r7, lr}
	sub sp, #0x10
	adds r7, r0, #0
	ldr r0, _0807FEC8 @ =0x0000CB05
	ldr r1, _0807FECC @ =0x0000DE23
	bl GetFile
	adds r2, r0, #0
	cmp r2, #0
	beq _0807FEBE
	adds r1, r7, #0
	adds r1, #0x1c
	ldm r0!, {r3, r4, r5}
	stm r1!, {r3, r4, r5}
	ldm r0!, {r3, r4, r5}
	stm r1!, {r3, r4, r5}
	ldm r0!, {r3, r4}
	stm r1!, {r3, r4}
	adds r4, r7, #0
	adds r4, #0x1c
	adds r0, r4, #0
	adds r1, r2, #0
	bl OpenSpriteSetFile
	adds r6, r7, #0
	adds r6, #0x3c
	movs r3, #0x90
	lsls r3, r3, #8
	movs r0, #2
	str r0, [sp]
	movs r5, #0
	str r5, [sp, #4]
	movs r0, #0x3c
	str r0, [sp, #8]
	ldr r0, [r7, #0x18]
	adds r0, #0x2c
	str r0, [sp, #0xc]
	adds r0, r6, #0
	adds r1, r4, #0
	movs r2, #0
	bl FUN_0822f3fc
	movs r2, #0xc7
	lsls r2, r2, #1
	str r5, [sp]
	adds r0, r6, #0
	adds r1, r4, #0
	movs r3, #1
	bl FUN_082370cc
	adds r1, r7, #0
	adds r1, #0x76
	movs r0, #0x26
	strh r0, [r1]
	adds r1, #0xe
	ldr r0, [r7, #0x18]
	adds r0, #0xd0
	ldr r0, [r0]
	str r0, [r1]
_0807FEBE:
	add sp, #0x10
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0807FEC8: .4byte 0x0000CB05
_0807FECC: .4byte 0x0000DE23
