	push {r4, lr}
	adds r4, r0, #0
	bl FUN_0801d7d8
	cmp r0, #0
	beq _0801D830
	ldr r0, _0801D858 @ =0x00001302
	adds r1, r4, r0
	movs r0, #0x9f
	strh r0, [r1]
_0801D830:
	ldr r1, [r4, #0x6c]
	cmp r1, #0
	beq _0801D860
	adds r2, r4, #0
	adds r2, #0x84
	adds r1, #3
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #1
	ldr r1, [r2]
	adds r1, r1, r0
	str r1, [r2]
	ldr r0, _0801D85C @ =0x000015FF
	adds r3, r2, #0
	cmp r1, r0
	ble _0801D872
	adds r0, #1
	str r0, [r3]
	b _0801D872
	.align 2, 0
_0801D858: .4byte 0x00001302
_0801D85C: .4byte 0x000015FF
_0801D860:
	adds r2, r4, #0
	adds r2, #0x84
	ldr r1, [r2]
	lsls r0, r1, #4
	subs r0, r0, r1
	lsls r0, r0, #2
	asrs r0, r0, #6
	str r0, [r2]
	adds r3, r2, #0
_0801D872:
	ldr r0, _0801D8AC @ =0x030044E0
	ldrh r1, [r0, #2]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _0801D8B8
	ldr r0, _0801D8B0 @ =0x00000E64
	adds r2, r4, r0
	adds r1, r4, #0
	adds r1, #0x80
	ldr r0, [r3]
	str r0, [r1]
	asrs r0, r0, #5
	strh r0, [r2, #0x20]
	ldr r1, _0801D8B4 @ =FUN_0801d8cc
	adds r0, r4, #0
	bl FUN_0801d7f8
	adds r0, r4, #0
	movs r1, #4
	movs r2, #0
	movs r3, #0
	bl FUN_0801d4dc
	adds r0, r4, #0
	bl FUN_0801d420
	b _0801D8C2
	.align 2, 0
_0801D8AC: .4byte 0x030044E0
_0801D8B0: .4byte 0x00000E64
_0801D8B4: .4byte FUN_0801d8cc
_0801D8B8:
	ldr r0, _0801D8C8 @ =0x00001314
	adds r1, r4, r0
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_0801D8C2:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0801D8C8: .4byte 0x00001314
