	push {r4, r5, lr}
	sub sp, #0xc
	adds r4, r0, #0
	movs r5, #0
	str r5, [r4, #0x20]
	adds r0, #0x24
	strb r5, [r0]
	adds r0, #1
	strb r5, [r0]
	adds r0, #1
	strb r5, [r0]
	adds r0, #1
	strb r5, [r0]
	ldr r1, _08211AF4 @ =0x00000868
	adds r0, r4, r1
	strh r5, [r0]
	adds r0, r4, #0
	movs r1, #0
	bl FUN_082117bc
	ldr r2, _08211AF8 @ =0x0000086A
	adds r0, r4, r2
	strh r5, [r0]
	adds r0, r4, #0
	bl FUN_082113d4
	adds r0, r4, #0
	bl FUN_08211730
	adds r0, r4, #0
	bl FUN_0821126c
	adds r0, r4, #0
	bl FUN_08211378
	movs r0, #0x6d
	bl prepare_08231510
	cmp r0, #0
	beq _08211AEC
	bl FUN_0823d340
	ldr r2, _08211AFC @ =0x00000874
	adds r1, r4, r2
	str r0, [r1]
	cmp r0, #0
	beq _08211AEC
	movs r0, #0x6e
	bl prepare_08231510
	cmp r0, #0
	beq _08211AEC
	bl FUN_0823d340
	movs r2, #0x87
	lsls r2, r2, #4
	adds r1, r4, r2
	str r0, [r1]
	cmp r0, #0
	beq _08211AEC
	movs r0, #0x68
	bl prepare_08231510
	cmp r0, #0
	beq _08211AEC
	bl FUN_0823d340
	ldr r2, _08211B00 @ =0x00000878
	adds r1, r4, r2
	str r0, [r1]
	cmp r0, #0
	bne _08211B04
_08211AEC:
	movs r0, #1
	rsbs r0, r0, #0
	b _08211B52
	.align 2, 0
_08211AF4: .4byte 0x00000868
_08211AF8: .4byte 0x0000086A
_08211AFC: .4byte 0x00000874
_08211B00: .4byte 0x00000878
_08211B04:
	movs r0, #0x65
	movs r1, #0
	bl FUN_0823174c
	ldr r2, _08211B5C @ =0x0000087C
	adds r1, r4, r2
	str r0, [r1]
	movs r0, #1
	movs r1, #0x10
	movs r2, #0x1d
	movs r3, #4
	bl FUN_0804a084
	ldr r2, _08211B60 @ =0x0000086C
	adds r1, r4, r2
	str r0, [r1]
	bl FUN_08049f5c
	bl FUN_08049e5c
	adds r0, r4, #0
	bl FUN_082111cc
	movs r0, #4
	str r0, [sp]
	ldr r0, _08211B64 @ =0x0000FFFF
	str r0, [sp, #4]
	str r5, [sp, #8]
	movs r0, #0
	movs r1, #4
	movs r2, #4
	movs r3, #4
	bl FUN_0823ce68
	movs r0, #0x8c
	lsls r0, r0, #1
	bl PlaySound_082406e0
	movs r0, #0
_08211B52:
	add sp, #0xc
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_08211B5C: .4byte 0x0000087C
_08211B60: .4byte 0x0000086C
_08211B64: .4byte 0x0000FFFF
