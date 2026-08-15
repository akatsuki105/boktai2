	push {r4, r5, r6, r7, lr}
	ldr r1, _080622C8 @ =0x00000858
	adds r5, r0, r1
	ldr r0, _080622CC @ =0x00001C1E
	bl GetParticleGroup
	str r0, [r5]
	movs r6, #0
	movs r7, #4
	rsbs r7, r7, #0
_0806228C:
	movs r0, #0x34
	adds r4, r6, #0
	muls r4, r0, r4
	adds r4, #8
	adds r4, r5, r4
	ldr r1, [r5]
	adds r0, r4, #0
	movs r2, #1
	bl FUN_0822d9f0
	adds r0, r4, #0
	adds r1, r7, #0
	adds r2, r7, #0
	bl FUN_0822dad4
	adds r0, r4, #0
	movs r1, #1
	bl FUN_0822dadc
	movs r0, #2
	strb r0, [r4, #0xf]
	adds r6, #1
	cmp r6, #3
	ble _0806228C
	movs r0, #0
	strb r0, [r5, #5]
	strb r0, [r5, #6]
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080622C8: .4byte 0x00000858
_080622CC: .4byte 0x00001C1E
