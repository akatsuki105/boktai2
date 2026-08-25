	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	ldr r0, _080A8750 @ =0x00001C1E
	bl GetParticleGroup
	str r0, [r5, #0x7c]
	movs r7, #4
	rsbs r7, r7, #0
	adds r4, r5, #0
	adds r4, #0x80
	movs r6, #7
_080A871A:
	ldr r1, [r5, #0x7c]
	adds r0, r4, #0
	movs r2, #1
	bl FUN_0822d9f0
	ldr r1, [r5, #0x7c]
	adds r0, r4, #0
	movs r2, #0
	bl FUN_0822dafc
	adds r0, r4, #0
	adds r1, r7, #0
	adds r2, r7, #0
	bl FUN_0822dad4
	adds r0, r4, #0
	movs r1, #1
	bl FUN_0822dadc
	adds r4, #0x3c
	subs r6, #1
	cmp r6, #0
	bge _080A871A
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080A8750: .4byte 0x00001C1E
