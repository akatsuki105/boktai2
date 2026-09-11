	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	adds r5, r1, #0
	ldr r0, [r5]
	ldr r1, [r5, #4]
	str r0, [r6, #0x60]
	str r1, [r6, #0x64]
	movs r0, #0
	str r0, [r6, #0x68]
	adds r4, r6, #0
	adds r4, #0x44
	ldr r1, _0821B7F4 @ =0x00003641
	adds r0, r4, #0
	bl Video_GetActorSprite
	adds r0, r6, #0
	adds r0, #0x18
	adds r1, r4, #0
	movs r2, #2
	bl FUN_0822a470
	ldr r0, [r5]
	ldr r1, [r5, #4]
	str r0, [r6, #0x34]
	str r1, [r6, #0x38]
	adds r0, r6, #0
	adds r0, #0x20
	movs r1, #0x40
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
	movs r0, #3
	strb r0, [r6, #0x1f]
	ldr r0, _0821B7F8 @ =0x00001C1E
	bl GetParticleGroup
	str r0, [r6, #0x78]
	movs r7, #4
	rsbs r7, r7, #0
	adds r4, #0x38
	movs r5, #7
_0821B7B2:
	ldr r1, [r6, #0x78]
	adds r0, r4, #0
	movs r2, #1
	bl FUN_0822d9f0
	adds r0, r4, #0
	adds r1, r7, #0
	adds r2, r7, #0
	bl FUN_0822dad4
	ldr r1, [r6, #0x78]
	adds r0, r4, #0
	movs r2, #2
	bl FUN_0822dafc
	adds r0, r4, #0
	movs r1, #1
	bl FUN_0822dadc
	movs r0, #0
	strh r0, [r4, #0x28]
	adds r4, #0x30
	subs r5, #1
	cmp r5, #0
	bge _0821B7B2
	str r0, [r6, #0x6c]
	str r0, [r6, #0x70]
	movs r0, #1
	str r0, [r6, #0x74]
	movs r0, #0
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0821B7F4: .4byte 0x00003641
_0821B7F8: .4byte 0x00001C1E
