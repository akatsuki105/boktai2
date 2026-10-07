	push {r4, r5, r6, lr}
	adds r2, r1, #0
	movs r0, #0x8e
	lsls r0, r0, #1
	adds r5, r2, r0
	adds r4, r2, #0
	adds r4, #0x48
	ldrb r0, [r2, #1]
	cmp r0, #0
	beq _0800D37C
	movs r0, #0
	strb r0, [r2, #1]
_0800D37C:
	ldrh r0, [r2, #0x2a]
	movs r1, #0x10
	movs r6, #0
	orrs r1, r0
	strh r1, [r2, #0x2a]
	ldrh r0, [r4, #0xa]
	subs r0, #0x10
	strh r0, [r4, #0xa]
	ldrh r3, [r2, #0x32]
	lsls r0, r0, #0x10
	lsls r1, r3, #0x10
	cmp r0, r1
	bge _0800D3EA
	strh r3, [r4, #0xa]
	asrs r0, r1, #0x18
	movs r1, #0xf
	ands r0, r1
	adds r3, r0, #1
	cmp r3, #0xf
	ble _0800D3A6
	movs r3, #0xf
_0800D3A6:
	ldrb r0, [r5, #4]
	movs r1, #0xf0
	ands r1, r0
	orrs r1, r3
	strb r1, [r5, #4]
	movs r0, #2
	ldrb r1, [r2, #2]
	ands r1, r0
	cmp r1, #0
	beq _0800D3DC
	movs r1, #1
	strb r1, [r2, #3]
	movs r0, #0
	str r0, [r2, #4]
	strb r1, [r2, #1]
	adds r0, r2, #0
	adds r0, #0x50
	movs r1, #0x80
	bl FUN_08003014
	ldr r0, _0800D3D8 @ =0x00000143
	bl PlaySound_082406e0
	b _0800D3EA
	.align 2, 0
_0800D3D8: .4byte 0x00000143
_0800D3DC:
	strb r6, [r2, #3]
	str r1, [r2, #4]
	movs r0, #1
	strb r0, [r2, #1]
	ldr r0, _0800D3F0 @ =0x0000021B
	bl PlaySound_082406e0
_0800D3EA:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0800D3F0: .4byte 0x0000021B
