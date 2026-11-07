	push {r4, r5, lr}
	sub sp, #8
	adds r5, r0, #0
	adds r4, r1, #0
	ldr r0, _0814DD54 @ =0x0000046D
	adds r1, r5, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _0814DD58
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0814DD5A
	.align 2, 0
_0814DD54: .4byte 0x0000046D
_0814DD58:
	movs r0, #0
_0814DD5A:
	cmp r0, #0
	beq _0814DD66
	adds r0, r5, #0
	movs r1, #0x11
	bl Enemy_PlayAnim
_0814DD66:
	ldr r0, [r5, #0x44]
	adds r0, #0x48
	movs r1, #0
	strh r1, [r0, #8]
	ldr r0, [r5, #0x44]
	adds r0, #0x48
	strh r1, [r0, #0xe]
	adds r0, r4, #0
	movs r1, #4
	bl Mod
	cmp r0, #0
	bne _0814DDEE
	ldrb r0, [r5, #5]
	adds r0, #0x20
	movs r1, #0xff
	ands r0, r1
	asrs r2, r0, #6
	ldr r0, [r5, #8]
	ldr r1, [r5, #0xc]
	str r0, [sp]
	str r1, [sp, #4]
	cmp r2, #1
	beq _0814DDB2
	cmp r2, #1
	bgt _0814DDA0
	cmp r2, #0
	beq _0814DDAA
	b _0814DDE8
_0814DDA0:
	cmp r2, #2
	beq _0814DDBA
	cmp r2, #3
	beq _0814DDD4
	b _0814DDE8
_0814DDAA:
	mov r0, sp
	ldrh r1, [r0]
	adds r1, #0x80
	b _0814DDC0
_0814DDB2:
	mov r0, sp
	ldrh r1, [r0, #4]
	adds r1, #0x80
	b _0814DDDA
_0814DDBA:
	mov r0, sp
	ldrh r1, [r0]
	subs r1, #0xa0
_0814DDC0:
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r2, _0814DDD0 @ =0xFFFF0000
	ldr r0, [sp]
	ands r0, r2
	orrs r0, r1
	str r0, [sp]
	b _0814DDE8
	.align 2, 0
_0814DDD0: .4byte 0xFFFF0000
_0814DDD4:
	mov r0, sp
	ldrh r1, [r0, #4]
	subs r1, #0x80
_0814DDDA:
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r2, _0814DE24 @ =0xFFFF0000
	ldr r0, [sp, #4]
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #4]
_0814DDE8:
	mov r0, sp
	bl FUN_0814b7a4
_0814DDEE:
	cmp r4, #0x1e
	ble _0814DE1A
	ldr r4, _0814DE28 @ =FUN_0814de34
	movs r3, #0x25
	ldr r0, _0814DE2C @ =0x0000046D
	adds r1, r5, r0
	movs r2, #0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _0814DE30 @ =0x0000046B
	adds r0, r5, r1
	strb r2, [r0]
	adds r1, #0xe8
	adds r0, r5, r1
	strb r3, [r0]
	adds r1, #0x25
	adds r0, r5, r1
	str r4, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r0, r5, r1
	strh r2, [r0]
_0814DE1A:
	add sp, #8
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0814DE24: .4byte 0xFFFF0000
_0814DE28: .4byte FUN_0814de34
_0814DE2C: .4byte 0x0000046D
_0814DE30: .4byte 0x0000046B
