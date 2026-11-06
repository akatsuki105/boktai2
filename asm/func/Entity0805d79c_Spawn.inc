	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0xc
	mov sb, r1
	adds r5, r2, #0
	adds r7, r3, #0
	adds r6, r0, #0
	add r1, sp, #8
	bl Entity0805d79c_AllocElem
	adds r3, r0, #0
	cmp r3, #0
	bne _0805D830
	movs r0, #1
	rsbs r0, r0, #0
	b _0805D90A
_0805D830:
	movs r0, #0x38
	adds r0, r0, r3
	mov r8, r0
	movs r0, #0
	adds r4, r3, #0
	stm r4!, {r0}
	ldr r2, _0805D858 @ =gSineTable
	adds r0, r5, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r7, r0
	cmp r0, #0
	blt _0805D85C
	asrs r1, r0, #0xc
	b _0805D862
	.align 2, 0
_0805D858: .4byte gSineTable
_0805D85C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0805D862:
	movs r0, #0
	strh r1, [r4]
	strh r0, [r4, #2]
	movs r0, #0xff
	ands r0, r5
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r7, r0
	cmp r0, #0
	blt _0805D87E
	asrs r0, r0, #0xc
	b _0805D884
_0805D87E:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0805D884:
	strh r0, [r4, #4]
	ldr r2, [sp, #0x28]
	ldr r0, [r2]
	ldr r1, [r2, #4]
	str r0, [r3, #0x28]
	str r1, [r3, #0x2c]
	adds r0, r5, #0
	adds r0, #0x60
	movs r1, #0xff
	ands r0, r1
	lsrs r2, r0, #4
	cmp r2, #8
	bls _0805D8AA
	movs r0, #0x10
	subs r0, r0, r2
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	movs r4, #1
	b _0805D8AC
_0805D8AA:
	movs r4, #0
_0805D8AC:
	adds r1, r3, #0
	adds r1, #0xc
	adds r0, r2, #4
	strh r0, [r1, #0x10]
	adds r2, r1, #0
	cmp r4, #0
	beq _0805D8C2
	ldr r0, [r3, #0xc]
	movs r1, #4
	orrs r0, r1
	b _0805D8CA
_0805D8C2:
	ldr r0, [r3, #0xc]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_0805D8CA:
	str r0, [r3, #0xc]
	ldr r0, [r3, #0xc]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r3, #0xc]
	adds r0, r2, #0
	movs r1, #0
	bl Video_AddAuxSpriteIntoDrawList
	movs r0, #0
	str r0, [sp]
	movs r0, #0x14
	str r0, [sp, #4]
	mov r0, r8
	mov r1, sb
	movs r2, #0x14
	movs r3, #0
	bl Hitbox_SetAttack
	mov r0, r8
	ldr r1, [sp, #0x28]
	movs r2, #0
	bl Hitbox_SetPos
	ldr r0, [sp, #8]
	movs r1, #1
	lsls r1, r0
	ldr r0, [r6, #0x18]
	orrs r0, r1
	str r0, [r6, #0x18]
	movs r0, #0
_0805D90A:
	add sp, #0xc
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
