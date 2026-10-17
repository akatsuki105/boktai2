	push {r4, lr}
	adds r4, r0, #0
	movs r0, #0x73
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _081DB954
	bl VM_GetPC_Proxy
	movs r2, #0xc3
	lsls r2, r2, #2
	adds r1, r4, r2
	str r0, [r1]
	cmp r0, #0
	bne _081DB954
	movs r0, #1
	rsbs r0, r0, #0
	b _081DB9A4
_081DB954:
	movs r0, #0
	bl ClearBGTilemapBuffer
	adds r0, r4, #0
	bl FUN_081daeb8
	adds r0, r4, #0
	bl FUN_081db074
	adds r0, r4, #0
	bl FUN_081db14c
	adds r0, r4, #0
	bl FUN_081db1e8
	adds r0, r4, #0
	bl FUN_081db32c
	adds r0, r4, #0
	movs r1, #0x3c
	bl FUN_081db3c0
	ldr r3, _081DB9AC @ =0x00000329
	adds r0, r4, r3
	movs r2, #0
	strb r2, [r0]
	ldr r1, _081DB9B0 @ =FUN_081db57c
	subs r3, #0x21
	adds r0, r4, r3
	str r1, [r0]
	movs r0, #0xcb
	lsls r0, r0, #2
	adds r1, r4, r0
	movs r0, #1
	strb r0, [r1]
	movs r1, #0xc8
	lsls r1, r1, #2
	adds r0, r4, r1
	strb r2, [r0]
	movs r0, #1
_081DB9A4:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_081DB9AC: .4byte 0x00000329
_081DB9B0: .4byte FUN_081db57c
