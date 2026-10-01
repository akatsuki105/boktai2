	push {r4, r5, r6, lr}
	sub sp, #4
	adds r5, r0, #0
	ldr r0, _0801C668 @ =0x00000B64
	adds r6, r5, r0
	adds r4, r5, #0
	adds r4, #0x3e
	ldrb r0, [r4]
	cmp r0, #0
	beq _0801C6F0
	movs r0, #0xde
	bl PlaySound_082406e0
	ldr r1, _0801C66C @ =0x00000B04
	adds r0, r5, r1
	adds r1, r5, #0
	adds r1, #0xf8
	movs r2, #0
	str r2, [sp]
	movs r3, #1
	bl MainSprite_SetAnim
	ldrb r0, [r4]
	subs r0, #1
	strb r0, [r4]
	ldrb r1, [r4]
	lsls r0, r1, #5
	adds r0, r0, r1
	lsls r0, r0, #2
	ldr r2, _0801C670 @ =0x00000978
	adds r0, r0, r2
	adds r0, r5, r0
	ldr r1, [r0, #0x2c]
	movs r2, #1
	orrs r1, r2
	str r1, [r0, #0x2c]
	ldrb r0, [r4]
	cmp r0, #0
	bne _0801C674
	movs r0, #0x10
	b _0801C676
	.align 2, 0
_0801C668: .4byte 0x00000B64
_0801C66C: .4byte 0x00000B04
_0801C670: .4byte 0x00000978
_0801C674:
	movs r0, #0x40
_0801C676:
	strh r0, [r6, #0x20]
	movs r0, #0x28
	strh r0, [r6, #0x22]
	adds r6, r5, #0
	adds r6, #0x3e
	ldrb r0, [r6]
	adds r4, r5, #0
	adds r4, #0x41
	adds r0, r4, r0
	movs r1, #1
	ldrb r0, [r0]
	lsls r1, r0
	ldr r0, [r5, #0x50]
	orrs r0, r1
	str r0, [r5, #0x50]
	ldrb r0, [r6]
	adds r0, r4, r0
	ldrb r1, [r0]
	lsls r0, r1, #5
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r5, r0
	movs r3, #0xcb
	lsls r3, r3, #1
	adds r1, r0, r3
	ldr r0, _0801C6E8 @ =0x000002DF
	strh r0, [r1]
	movs r0, #0
	bl FUN_0801b670
	ldrb r1, [r6]
	adds r4, r4, r1
	ldrb r1, [r4]
	lsls r2, r1, #5
	adds r2, r2, r1
	lsls r2, r2, #2
	movs r3, #0xd2
	lsls r3, r3, #1
	adds r1, r5, r3
	adds r1, r1, r2
	str r0, [r1]
	movs r0, #2
	movs r1, #0x10
	movs r2, #0x1e
	movs r3, #2
	bl TextBox_SetRect
	adds r0, r5, #0
	movs r1, #0
	bl FUN_0801bf88
	ldr r1, _0801C6EC @ =FUN_0801c9e4
	adds r0, r5, #0
	bl EntityDA0B_SetFn
	b _0801C6FE
	.align 2, 0
_0801C6E8: .4byte 0x000002DF
_0801C6EC: .4byte FUN_0801c9e4
_0801C6F0:
	movs r0, #0xde
	bl PlaySound_082406e0
	ldr r1, _0801C708 @ =FUN_0801cec0
	adds r0, r5, #0
	bl EntityDA0B_SetFn
_0801C6FE:
	add sp, #4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0801C708: .4byte FUN_0801cec0
