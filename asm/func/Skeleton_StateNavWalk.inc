	push {r4, r5, lr}
	adds r3, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r3, r1
	ldr r5, [r0]
	ldr r2, _0810DD30 @ =0x0000046D
	adds r1, r3, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _0810DD34
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0810DD36
	.align 2, 0
_0810DD30: .4byte 0x0000046D
_0810DD34:
	movs r0, #0
_0810DD36:
	cmp r0, #0
	bne _0810DE08
	movs r2, #0x80
	lsls r2, r2, #1
	movs r4, #0xe6
	lsls r4, r4, #3
	adds r1, r5, r4
	ldrh r0, [r1]
	ands r0, r2
	adds r4, r1, #0
	cmp r0, #0
	beq _0810DD52
	movs r0, #1
	b _0810DD54
_0810DD52:
	movs r0, #0
_0810DD54:
	cmp r0, #0
	beq _0810DE00
	movs r1, #0xf2
	lsls r1, r1, #1
	adds r0, r3, r1
	movs r2, #0xec
	lsls r2, r2, #3
	adds r1, r5, r2
	ldr r2, [r0]
	ldr r0, [r1]
	cmp r2, r0
	bls _0810DDD6
	ldr r4, _0810DD7C @ =0x000001DF
	adds r0, r3, r4
	ldrb r0, [r0]
	cmp r0, #8
	bne _0810DD80
	movs r2, #0x14
	b _0810DD82
	.align 2, 0
_0810DD7C: .4byte 0x000001DF
_0810DD80:
	movs r2, #0x11
_0810DD82:
	movs r1, #0x8d
	lsls r1, r1, #3
	adds r0, r3, r1
	movs r1, #0
	strb r1, [r0]
	ldr r4, _0810DDB8 @ =0x00000469
	adds r0, r3, r4
	strb r1, [r0]
	adds r4, #1
	adds r0, r3, r4
	strb r2, [r0]
	ldr r2, _0810DDBC @ =0x00000484
	adds r0, r3, r2
	str r1, [r0]
	adds r4, #2
	adds r1, r3, r4
	movs r0, #1
	strb r0, [r1]
	movs r1, #0xfe
	lsls r1, r1, #1
	adds r0, r3, r1
	ldrb r0, [r0]
	cmp r0, #0
	blt _0810DDC0
	asrs r0, r0, #5
	b _0810DDC6
	.align 2, 0
_0810DDB8: .4byte 0x00000469
_0810DDBC: .4byte 0x00000484
_0810DDC0:
	rsbs r0, r0, #0
	asrs r0, r0, #5
	rsbs r0, r0, #0
_0810DDC6:
	adds r0, #3
	movs r1, #7
	ands r0, r1
	movs r2, #0xee
	lsls r2, r2, #1
	adds r1, r3, r2
	strb r0, [r1]
	b _0810DE08
_0810DDD6:
	ldr r0, _0810DDF0 @ =0xFFFFFEFF
	ldrh r1, [r4]
	ands r0, r1
	strh r0, [r4]
	ldr r4, _0810DDF4 @ =0x000001DF
	adds r0, r3, r4
	ldrb r0, [r0]
	cmp r0, #8
	bne _0810DDF8
	adds r0, r3, #0
	bl Skeleton_LichRelocate
	b _0810DE08
	.align 2, 0
_0810DDF0: .4byte 0xFFFFFEFF
_0810DDF4: .4byte 0x000001DF
_0810DDF8:
	adds r0, r3, #0
	bl Skeleton_RetreatOrChase
	b _0810DE08
_0810DE00:
	adds r0, r3, #0
	movs r1, #1
	bl Enemy_PlayAnim
_0810DE08:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
