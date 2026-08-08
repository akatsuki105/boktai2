	push {r4, lr}
	sub sp, #0xc
	ldr r3, _0823DD40 @ =gClock
	ldrb r0, [r3, #7]
	adds r0, #1
	movs r1, #0
	strb r0, [r3, #7]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x3b
	bls _0823DD36
	strb r1, [r3, #7]
	adds r4, r3, #0
	ldrb r0, [r4, #6]
	adds r0, #1
	strb r0, [r4, #6]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x3b
	bls _0823DD36
	strb r1, [r4, #6]
	ldrb r0, [r4, #5]
	adds r0, #1
	strb r0, [r4, #5]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x3b
	bls _0823DD12
	strb r1, [r4, #5]
	ldrb r0, [r4, #4]
	adds r0, #1
	strb r0, [r4, #4]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x17
	bls _0823DD12
	strb r1, [r4, #4]
	add r1, sp, #4
	add r2, sp, #8
	ldr r3, [r4]
	mov r0, sp
	bl FUN_0823db08
	ldr r0, [sp, #8]
	adds r0, #1
	str r0, [sp, #8]
	ldr r0, [sp]
	ldr r1, [sp, #4]
	bl FUN_0823d970
	ldr r1, [sp, #8]
	cmp r1, r0
	blt _0823DCFA
	movs r1, #1
	str r1, [sp, #8]
	ldr r0, [sp, #4]
	adds r0, #1
	str r0, [sp, #4]
	cmp r0, #0xc
	ble _0823DCFA
	str r1, [sp, #4]
	ldr r0, [sp]
	adds r0, #1
	str r0, [sp]
	ldr r1, _0823DD44 @ =0x00000832
	cmp r0, r1
	ble _0823DCFA
	ldr r0, _0823DD48 @ =0x00000833
	str r0, [sp]
_0823DCFA:
	ldr r0, [sp]
	ldr r1, [sp, #4]
	ldr r2, [sp, #8]
	bl FUN_0823db74
	str r0, [r4]
	ldr r0, [sp]
	ldr r1, [sp, #4]
	ldr r2, [sp, #8]
	bl FUN_0823daa4
	strb r0, [r4, #8]
_0823DD12:
	ldr r0, _0823DD4C @ =0x030047B4
	movs r1, #1
	str r1, [r0]
	ldr r2, _0823DD40 @ =gClock
	ldrh r0, [r2, #0xc]
	ldrh r4, [r4, #4]
	cmp r0, r4
	bne _0823DD36
	ldrh r0, [r2, #0x14]
	adds r0, #1
	strh r0, [r2, #0x14]
	lsls r0, r0, #0x10
	movs r1, #0x8c
	lsls r1, r1, #0x11
	cmp r0, r1
	bls _0823DD36
	movs r0, #0
	strh r0, [r2, #0x14]
_0823DD36:
	add sp, #0xc
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0823DD40: .4byte gClock
_0823DD44: .4byte 0x00000832
_0823DD48: .4byte 0x00000833
_0823DD4C: .4byte 0x030047B4
