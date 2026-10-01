	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	adds r7, r1, #0
	adds r0, #0x3d
	ldrb r1, [r0]
	lsls r0, r1, #5
	adds r0, r0, r1
	lsls r0, r0, #2
	movs r1, #0x9c
	lsls r1, r1, #1
	adds r0, r0, r1
	adds r5, r4, r0
	ldr r3, _0801BFEC @ =0x00001308
	adds r6, r4, r3
	ldr r0, [r6]
	bl TextBox_Start
	adds r1, r4, #0
	adds r1, #0xbc
	adds r0, r5, #0
	bl FUN_08094d1c
	ldrb r0, [r5]
	cmp r0, #0
	beq _0801BFF4
	ldr r1, [r6]
	adds r0, r5, #0
	bl FUN_08094d48
	adds r0, r5, #0
	bl FUN_08094e70
	adds r2, r0, #0
	ldr r1, _0801BFF0 @ =0x00000DA4
	adds r0, r4, r1
	ldr r1, [r0, #8]
	movs r3, #2
	rsbs r3, r3, #0
	ands r1, r3
	str r1, [r0, #8]
	movs r3, #0x8c
	lsls r3, r3, #1
	adds r1, r4, r3
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	movs r3, #0
	bl MainSprite_SetPose
	b _0801C010
	.align 2, 0
_0801BFEC: .4byte 0x00001308
_0801BFF0: .4byte 0x00000DA4
_0801BFF4:
	cmp r7, #0
	bne _0801BFFE
	bl FUN_08049e5c
	b _0801C004
_0801BFFE:
	adds r0, r7, #0
	bl FUN_08049e30
_0801C004:
	ldr r1, _0801C018 @ =0x00000DA4
	adds r0, r4, r1
	ldr r1, [r0, #8]
	movs r2, #1
	orrs r1, r2
	str r1, [r0, #8]
_0801C010:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0801C018: .4byte 0x00000DA4
