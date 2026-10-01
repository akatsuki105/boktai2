	push {r4, lr}
	adds r4, r0, #0
	bl FUN_0801d7d8
	cmp r0, #0
	beq _0801DAD0
	ldr r0, _0801DAF4 @ =0x00000E64
	adds r3, r4, r0
	ldr r0, _0801DAF8 @ =0x03003584
	ldr r2, [r0]
	ldr r1, _0801DAFC @ =0x000053E0
	adds r2, r2, r1
	ldr r0, [r3, #8]
	movs r1, #1
	orrs r0, r1
	str r0, [r3, #8]
	ldrh r2, [r2, #0x1e]
	ldr r1, _0801DB00 @ =0x00001302
	adds r0, r4, r1
	movs r1, #0
	strh r2, [r0]
	adds r0, r4, #0
	adds r0, #0x88
	str r1, [r0]
	str r1, [r4, #0x7c]
	adds r0, r4, #0
	movs r1, #8
	movs r2, #0
	movs r3, #0
	bl FUN_0801d4dc
	adds r0, r4, #0
	bl FUN_0801d488
	adds r0, r4, #0
	bl FUN_0801d4c4
	ldr r0, _0801DB04 @ =0x03002BE0
	ldr r0, [r0]
	movs r1, #0
	bl FUN_0807c7c8
_0801DAD0:
	adds r2, r4, #0
	adds r2, #0x84
	ldr r1, [r2]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	asrs r0, r0, #5
	str r0, [r2]
	ldr r0, _0801DB08 @ =0x00001314
	adds r1, r4, r0
	ldr r0, [r1]
	cmp r0, #0x1f
	bls _0801DB10
	ldr r1, _0801DB0C @ =FUN_0801d81c
	adds r0, r4, #0
	bl FUN_0801d7f8
	b _0801DB14
	.align 2, 0
_0801DAF4: .4byte 0x00000E64
_0801DAF8: .4byte 0x03003584
_0801DAFC: .4byte 0x000053E0
_0801DB00: .4byte 0x00001302
_0801DB04: .4byte 0x03002BE0
_0801DB08: .4byte 0x00001314
_0801DB0C: .4byte FUN_0801d81c
_0801DB10:
	adds r0, #1
	str r0, [r1]
_0801DB14:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
