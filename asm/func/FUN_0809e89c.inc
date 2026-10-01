	push {r4, r5, r6, r7, lr}
	sub sp, #0x1c
	adds r5, r0, #0
	adds r1, r5, #0
	adds r1, #0x28
	ldrb r0, [r1]
	ldr r7, _0809E9A8 @ =0x030046A0
	cmp r0, #0
	bne _0809E8E2
	movs r0, #1
	strb r0, [r1]
	movs r3, #0
	adds r0, r5, #0
	adds r0, #0x26
	ldrb r1, [r0]
	cmp r3, r1
	bge _0809E8E2
	movs r6, #2
	rsbs r6, r6, #0
	adds r2, r5, #0
	adds r2, #0xc6
	adds r1, r5, #0
	adds r4, r0, #0
_0809E8CA:
	ldrb r0, [r2]
	cmp r0, #0
	beq _0809E8D6
	ldr r0, [r1, #0x34]
	ands r0, r6
	str r0, [r1, #0x34]
_0809E8D6:
	adds r2, #0xa8
	adds r1, #0xa8
	adds r3, #1
	ldrb r0, [r4]
	cmp r3, r0
	blt _0809E8CA
_0809E8E2:
	movs r4, #0
	ldr r0, [r7]
	ldr r1, _0809E9AC @ =0x00000934
	adds r0, r0, r1
	ldrh r1, [r0]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	bne _0809E906
	ldr r0, [r5, #0x18]
	adds r0, #0x2c
	bl FUN_0809e05c
	cmp r0, #0
	blt _0809E902
	movs r4, #1
_0809E902:
	cmp r4, #0
	beq _0809E9BE
_0809E906:
	ldr r2, [r5, #0x18]
	movs r3, #0xdf
	lsls r3, r3, #2
	adds r0, r2, r3
	ldrb r1, [r0]
	cmp r1, #7
	bne _0809E9B8
	adds r3, #1
	adds r0, r2, r3
	ldrb r0, [r0]
	cmp r0, #3
	bhi _0809E9B8
	cmp r0, #3
	bne _0809E9C0
	ldrh r0, [r5, #0x22]
	cmp r0, #0x3e
	bhi _0809E9C0
	ands r1, r0
	cmp r1, #0
	bne _0809E99E
	ldr r0, [r2, #0x2c]
	ldr r1, [r2, #0x30]
	str r0, [sp, #0xc]
	str r1, [sp, #0x10]
	add r0, sp, #0xc
	ldrh r0, [r0]
	subs r0, #0x64
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r3, _0809E9B0 @ =0xFFFF0000
	ldr r2, [sp, #0xc]
	ands r2, r3
	orrs r2, r0
	str r2, [sp, #0xc]
	add r0, sp, #0xc
	ldrh r0, [r0, #4]
	subs r0, #0x64
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, [sp, #0x10]
	ands r1, r3
	orrs r1, r0
	str r1, [sp, #0x10]
	asrs r1, r2, #0x10
	movs r0, #0x80
	lsls r0, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #0x10
	ldr r4, _0809E9B4 @ =0x0000FFFF
	adds r0, r4, #0
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #0xc]
	ldr r0, [sp, #0x14]
	ands r0, r3
	movs r2, #0x80
	lsls r2, r2, #1
	orrs r0, r2
	ands r0, r4
	str r0, [sp, #0x14]
	add r1, sp, #0x14
	ldr r0, [r1, #4]
	ands r0, r3
	orrs r0, r2
	str r0, [r1, #4]
	str r1, [sp]
	movs r0, #0xb4
	str r0, [sp, #4]
	movs r0, #0x3c
	str r0, [sp, #8]
	movs r0, #1
	movs r1, #1
	movs r2, #0x19
	add r3, sp, #0xc
	bl Entity0800a89c_Spawn
_0809E99E:
	ldrh r0, [r5, #0x22]
	adds r0, #1
	strh r0, [r5, #0x22]
	b _0809E9C0
	.align 2, 0
_0809E9A8: .4byte 0x030046A0
_0809E9AC: .4byte 0x00000934
_0809E9B0: .4byte 0xFFFF0000
_0809E9B4: .4byte 0x0000FFFF
_0809E9B8:
	movs r0, #0
	strh r0, [r5, #0x22]
	b _0809E9C0
_0809E9BE:
	strh r4, [r5, #0x22]
_0809E9C0:
	adds r0, r5, #0
	bl FUN_0809e75c
	add sp, #0x1c
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
