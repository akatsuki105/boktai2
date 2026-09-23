	push {r4, lr}
	adds r4, r0, #0
	ldr r0, [r4, #0x38]
	ldr r1, _0802072C @ =0x00FFFF00
	ands r0, r1
	movs r1, #0x80
	lsls r1, r1, #2
	cmp r0, r1
	bne _080206D0
	movs r0, #0xcf
	bl PlaySound_0824078c
_080206D0:
	adds r2, r4, #0
	adds r2, #0x3a
	ldrb r0, [r2]
	adds r0, #1
	strb r0, [r2]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #7
	bls _08020726
	adds r1, r4, #0
	adds r1, #0x39
	ldrb r0, [r1]
	subs r0, #1
	strb r0, [r1]
	movs r0, #0
	strb r0, [r2]
	ldrb r0, [r1]
	cmp r0, #0
	bne _08020726
	subs r1, #2
	strb r0, [r1]
	ldr r2, [r4, #0x2c]
	ldrh r1, [r2, #6]
	movs r0, #2
	orrs r0, r1
	strh r0, [r2, #6]
	ldr r2, [r4, #0x2c]
	ldrh r1, [r2, #6]
	movs r0, #3
	orrs r0, r1
	strh r0, [r2, #6]
	ldr r2, [r4, #0x2c]
	ldrb r0, [r2, #4]
	movs r1, #0xf0
	ands r1, r0
	adds r0, r4, #0
	adds r0, #0x3b
	ldrb r0, [r0]
	adds r0, #1
	orrs r1, r0
	strb r1, [r2, #4]
	ldr r0, _08020730 @ =FUN_080206b0
	str r0, [r4, #0x30]
_08020726:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0802072C: .4byte 0x00FFFF00
_08020730: .4byte FUN_080206b0
