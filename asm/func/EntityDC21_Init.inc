	push {r4, r5, lr}
	adds r5, r0, #0
	adds r2, r1, #0
	ldr r0, _0809F598 @ =0x03002BE0
	ldr r1, [r0]
	movs r3, #0x96
	lsls r3, r3, #2
	adds r0, r5, r3
	str r1, [r0]
	cmp r1, #0
	bne _0809F59C
	movs r0, #1
	rsbs r0, r0, #0
	b _0809F5FA
	.align 2, 0
_0809F598: .4byte 0x03002BE0
_0809F59C:
	movs r1, #0x97
	lsls r1, r1, #2
	adds r0, r5, r1
	movs r4, #0
	strh r2, [r0]
	adds r0, r5, #0
	bl EntityDC21_InitSprite
	adds r0, r5, #0
	bl FUN_0809f4b0
	adds r0, r5, #0
	bl EntityDC21_InitHitbox
	adds r0, r5, #0
	bl EntityDC21_InitMainSprites
	ldr r3, _0809F5EC @ =0x0000025E
	adds r0, r5, r3
	strb r4, [r0]
	movs r1, #0x98
	lsls r1, r1, #2
	adds r0, r5, r1
	strb r4, [r0]
	adds r3, #3
	adds r0, r5, r3
	strb r4, [r0]
	subs r1, #1
	adds r0, r5, r1
	strb r4, [r0]
	ldr r0, [r5, #0x18]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	beq _0809F5F0
	adds r3, #1
	adds r1, r5, r3
	movs r0, #7
	b _0809F5F6
	.align 2, 0
_0809F5EC: .4byte 0x0000025E
_0809F5F0:
	ldr r0, _0809F600 @ =0x00000262
	adds r1, r5, r0
	movs r0, #1
_0809F5F6:
	strh r0, [r1]
	movs r0, #0
_0809F5FA:
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_0809F600: .4byte 0x00000262
