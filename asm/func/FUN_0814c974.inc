	push {r4, r5, lr}
	adds r5, r0, #0
	adds r4, r1, #0
	ldr r0, _0814C98C @ =0x0000046D
	adds r1, r5, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _0814C990
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0814C992
	.align 2, 0
_0814C98C: .4byte 0x0000046D
_0814C990:
	movs r0, #0
_0814C992:
	cmp r0, #0
	beq _0814C9B4
	adds r0, r5, #0
	movs r1, #6
	bl Enemy_PlayAnim
	movs r0, #2
	movs r1, #0xc0
	lsls r1, r1, #1
	adds r2, r5, r1
	ldrh r1, [r2]
	ands r0, r1
	cmp r0, #0
	bne _0814C9B4
	movs r0, #1
	orrs r0, r1
	strh r0, [r2]
_0814C9B4:
	adds r0, r4, #0
	movs r1, #0x3c
	bl Mod
	cmp r0, #0
	bne _0814C9D0
	ldr r2, _0814CA1C @ =0x000001DF
	adds r0, r5, r2
	ldrb r3, [r0]
	adds r0, r5, #0
	movs r1, #2
	movs r2, #0
	bl Enemy_SetEmote
_0814C9D0:
	ldr r1, _0814CA20 @ =0x00000466
	adds r0, r5, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #0
	bgt _0814CA16
	movs r1, #0x80
	lsls r1, r1, #5
	movs r2, #0xbe
	lsls r2, r2, #1
	adds r0, r5, r2
	ldr r4, [r0]
	ands r4, r1
	cmp r4, #0
	bne _0814CA16
	ldr r3, _0814CA24 @ =FUN_0814ca30
	movs r2, #6
	ldr r0, _0814CA28 @ =0x0000046D
	adds r1, r5, r0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _0814CA2C @ =0x0000046B
	adds r0, r5, r1
	strb r4, [r0]
	adds r1, #0xe8
	adds r0, r5, r1
	strb r2, [r0]
	movs r2, #0xaf
	lsls r2, r2, #3
	adds r0, r5, r2
	str r3, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r0, r5, r1
	strh r4, [r0]
_0814CA16:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0814CA1C: .4byte 0x000001DF
_0814CA20: .4byte 0x00000466
_0814CA24: .4byte FUN_0814ca30
_0814CA28: .4byte 0x0000046D
_0814CA2C: .4byte 0x0000046B
