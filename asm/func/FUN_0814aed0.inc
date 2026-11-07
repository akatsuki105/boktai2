	push {r4, r5, lr}
	adds r4, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r5, [r0]
	adds r0, r4, #0
	bl Enemy_IsDead
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0814AFB8
	ldr r0, _0814AF24 @ =0x0000E33F
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r1, r4, r2
	ldrh r2, [r1]
	ands r0, r2
	cmp r0, #0
	bne _0814AFB8
	movs r1, #0x10
	movs r3, #0xbc
	lsls r3, r3, #1
	adds r0, r4, r3
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	bne _0814AFB8
	ldr r1, _0814AF28 @ =0x00000553
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #1
	bhi _0814AFB8
	movs r3, #0xd8
	lsls r3, r3, #3
	adds r1, r5, r3
	ldrh r0, [r1]
	cmp r0, #0
	beq _0814AF2C
	subs r0, #1
	strh r0, [r1]
	b _0814AFB8
	.align 2, 0
_0814AF24: .4byte 0x0000E33F
_0814AF28: .4byte 0x00000553
_0814AF2C:
	movs r0, #0x80
	ands r2, r0
	cmp r2, #0
	beq _0814AF40
	ldr r2, _0814AF3C @ =0x000006C4
	adds r0, r5, r2
	b _0814AF44
	.align 2, 0
_0814AF3C: .4byte 0x000006C4
_0814AF40:
	ldr r3, _0814AF70 @ =0x000006C2
	adds r0, r5, r3
_0814AF44:
	ldrh r0, [r0]
	strh r0, [r1]
	movs r2, #1
	movs r0, #0xd5
	lsls r0, r0, #3
	adds r1, r5, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r0, [r0]
	movs r3, #0xd5
	lsls r3, r3, #3
	adds r0, r0, r3
	ldr r0, [r0]
	ands r0, r2
	cmp r0, #0
	beq _0814AF74
	movs r0, #1
	b _0814AF76
	.align 2, 0
_0814AF70: .4byte 0x000006C2
_0814AF74:
	movs r0, #0
_0814AF76:
	cmp r0, #0
	beq _0814AFB8
	movs r2, #0xf
	movs r1, #0x8d
	lsls r1, r1, #3
	adds r0, r4, r1
	movs r1, #0
	strb r1, [r0]
	ldr r3, _0814AFC0 @ =0x00000469
	adds r0, r4, r3
	strb r1, [r0]
	adds r3, #1
	adds r0, r4, r3
	strb r2, [r0]
	ldr r2, _0814AFC4 @ =0x00000484
	adds r0, r4, r2
	str r1, [r0]
	adds r3, #2
	adds r1, r4, r3
	movs r0, #1
	strb r0, [r1]
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r1, [r0]
	movs r2, #0xd5
	lsls r2, r2, #3
	adds r1, r1, r2
	movs r2, #2
	rsbs r2, r2, #0
	ldr r0, [r1]
	ands r0, r2
	str r0, [r1]
_0814AFB8:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0814AFC0: .4byte 0x00000469
_0814AFC4: .4byte 0x00000484
