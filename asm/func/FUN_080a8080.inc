	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	mov r8, r0
	ldr r0, _080A8100 @ =0x00001C1E
	bl GetParticleGroup
	mov r1, r8
	adds r1, #0x9c
	str r0, [r1]
	movs r6, #0
	adds r7, r1, #0
	mov sl, r6
	movs r0, #4
	rsbs r0, r0, #0
	mov sb, r0
_080A80A4:
	movs r0, #0x2c
	adds r5, r6, #0
	muls r5, r0, r5
	adds r4, r5, #0
	adds r4, #0xa0
	add r4, r8
	ldr r1, [r7]
	adds r0, r4, #0
	movs r2, #1
	bl FUN_0822d9f0
	adds r0, r4, #0
	mov r1, sb
	mov r2, sb
	bl FUN_0822dad4
	ldr r1, [r7]
	adds r0, r4, #0
	movs r2, #8
	bl FUN_0822dafc
	adds r0, r4, #0
	movs r1, #1
	bl FUN_0822dadc
	movs r0, #2
	strb r0, [r4, #0xf]
	movs r0, #0xec
	strb r0, [r4, #0x10]
	add r5, r8
	adds r0, r5, #0
	adds r0, #0xc8
	mov r1, sl
	strb r1, [r0]
	adds r5, #0xc9
	strb r1, [r5]
	adds r6, #1
	cmp r6, #7
	ble _080A80A4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080A8100: .4byte 0x00001C1E
