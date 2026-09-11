	push {r4, r5, r6, r7, lr}
	sub sp, #0x14
	adds r5, r2, #0
	ldrh r6, [r0, #0x3e]
	cmp r6, #0
	bne _0800C0CA
	movs r1, #0x40
	ldr r0, [r0, #0x38]
	ands r0, r1
	movs r6, #0x1e
	cmp r0, #0
	beq _0800C0CA
	movs r6, #0x32
_0800C0CA:
	ldrh r7, [r5, #0x28]
	cmp r7, #0
	bne _0800C126
	cmp r6, #0
	ble _0800C126
	movs r4, #8
	strh r4, [r5, #0x28]
	adds r0, r5, #0
	adds r0, #0x3c
	movs r1, #0xb5
	lsls r1, r1, #1
	bl Video_SetActorSpritePltt
	strh r4, [r5, #0x2e]
	ldrh r0, [r5, #0x24]
	subs r0, r0, r6
	strh r0, [r5, #0x24]
	lsls r0, r0, #0x10
	cmp r0, #0
	bgt _0800C126
	ldrh r0, [r5, #0x26]
	strh r0, [r5, #0x24]
	ldr r0, [r5, #0x74]
	ldr r1, [r5, #0x78]
	str r0, [sp, #0xc]
	str r1, [sp, #0x10]
	ldr r2, [sp, #0xc]
	asrs r1, r2, #0x10
	adds r1, #0x40
	lsls r1, r1, #0x10
	ldr r0, _0800C130 @ =0x0000FFFF
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #0xc]
	ldrh r0, [r5, #0x36]
	ldrh r2, [r5, #0x38]
	str r7, [sp]
	movs r1, #0x96
	lsls r1, r1, #2
	str r1, [sp, #4]
	movs r1, #0x64
	str r1, [sp, #8]
	movs r1, #1
	add r3, sp, #0xc
	bl FUN_0800ac80
_0800C126:
	add sp, #0x14
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0800C130: .4byte 0x0000FFFF
