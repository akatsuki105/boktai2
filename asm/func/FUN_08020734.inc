	push {r4, lr}
	adds r4, r0, #0
	ldr r0, [r4, #0x38]
	ldr r1, _080207A4 @ =0x00FFFF00
	ands r0, r1
	cmp r0, #0
	bne _0802076E
	movs r0, #0xce
	bl PlaySound_0824078c
	ldr r2, [r4, #0x2c]
	ldrh r1, [r2, #6]
	ldr r0, _080207A8 @ =0x0000FFFC
	ands r0, r1
	strh r0, [r2, #6]
	ldr r2, [r4, #0x2c]
	ldrh r1, [r2, #6]
	movs r0, #2
	orrs r0, r1
	strh r0, [r2, #6]
	ldr r2, [r4, #0x2c]
	ldrb r1, [r2, #4]
	movs r0, #0xf0
	ands r0, r1
	adds r1, r4, #0
	adds r1, #0x3b
	ldrb r1, [r1]
	orrs r0, r1
	strb r0, [r2, #4]
_0802076E:
	adds r2, r4, #0
	adds r2, #0x3a
	ldrb r0, [r2]
	adds r0, #1
	strb r0, [r2]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #7
	bls _0802079E
	adds r1, r4, #0
	adds r1, #0x39
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	movs r0, #0
	strb r0, [r2]
	ldrb r0, [r1]
	cmp r0, #1
	bls _0802079E
	movs r0, #1
	subs r1, #2
	strb r0, [r1]
	ldr r0, _080207AC @ =FUN_080206b4
	str r0, [r4, #0x30]
_0802079E:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080207A4: .4byte 0x00FFFF00
_080207A8: .4byte 0x0000FFFC
_080207AC: .4byte FUN_080206b4
