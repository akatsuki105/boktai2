	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x1c
	adds r6, r0, #0
	movs r1, #0xea
	lsls r1, r1, #1
	adds r0, r6, r1
	ldr r1, _0801F5C8 @ =0x08DAA084
	movs r2, #0x24
	bl CopyMemory
	ldr r4, _0801F5CC @ =0x0000CB05
	ldr r1, _0801F5D0 @ =0x0000414C
	adds r0, r4, #0
	bl GetFile
	adds r3, r0, #0
	cmp r3, #0
	beq _0801F5C0
	movs r2, #0xb0
	adds r2, r2, r6
	mov r8, r2
	adds r1, r3, #0
	ldm r1!, {r0, r5, r7}
	stm r2!, {r0, r5, r7}
	ldm r1!, {r0, r5, r7}
	stm r2!, {r0, r5, r7}
	ldm r1!, {r5, r7}
	stm r2!, {r5, r7}
	mov r0, r8
	adds r1, r3, #0
	bl OpenMainSpriteFile
	ldr r1, _0801F5D4 @ =0x0000B343
	adds r0, r4, #0
	bl GetFile
	adds r3, r0, #0
	cmp r3, #0
	beq _0801F5C0
	movs r0, #0xd0
	adds r0, r0, r6
	mov r8, r0
	mov r2, r8
	adds r1, r3, #0
	ldm r1!, {r0, r5, r7}
	stm r2!, {r0, r5, r7}
	ldm r1!, {r0, r5, r7}
	stm r2!, {r0, r5, r7}
	ldm r1!, {r5, r7}
	stm r2!, {r5, r7}
	mov r0, r8
	adds r1, r3, #0
	bl OpenMainSpriteFile
	ldr r1, _0801F5D8 @ =0x00005D04
	adds r0, r4, #0
	bl GetFile
	adds r3, r0, #0
	cmp r3, #0
	beq _0801F5C0
	movs r0, #0xf0
	adds r0, r0, r6
	mov r8, r0
	mov r2, r8
	adds r1, r3, #0
	ldm r1!, {r0, r5, r7}
	stm r2!, {r0, r5, r7}
	ldm r1!, {r0, r5, r7}
	stm r2!, {r0, r5, r7}
	ldm r1!, {r5, r7}
	stm r2!, {r5, r7}
	mov r0, r8
	adds r1, r3, #0
	bl OpenMainSpriteFile
	ldr r1, _0801F5DC @ =0x000082F1
	adds r0, r4, #0
	bl GetFile
	adds r3, r0, #0
	cmp r3, #0
	beq _0801F5C0
	movs r1, #0x88
	lsls r1, r1, #1
	adds r0, r6, r1
	adds r2, r0, #0
	adds r1, r3, #0
	ldm r1!, {r4, r5, r7}
	stm r2!, {r4, r5, r7}
	ldm r1!, {r4, r5, r7}
	stm r2!, {r4, r5, r7}
	ldm r1!, {r4, r5}
	stm r2!, {r4, r5}
	adds r1, r3, #0
	bl OpenMainSpriteFile
	movs r0, #0x65
	movs r1, #0
	bl VM_GetNamedArgValue
	adds r1, r6, #0
	adds r1, #0x90
	str r0, [r1]
	movs r0, #0x45
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _0801F5C0
	bl FUN_0823d340
	adds r1, r0, #0
	movs r7, #0xeb
	lsls r7, r7, #3
	adds r0, r6, r7
	str r1, [r0]
	cmp r1, #0
	bne _0801F5E0
_0801F5C0:
	movs r0, #1
	rsbs r0, r0, #0
	b _0801F6FE
	.align 2, 0
_0801F5C8: .4byte 0x08DAA084
_0801F5CC: .4byte 0x0000CB05
_0801F5D0: .4byte 0x0000414C
_0801F5D4: .4byte 0x0000B343
_0801F5D8: .4byte 0x00005D04
_0801F5DC: .4byte 0x000082F1
_0801F5E0:
	adds r0, r1, #0
	bl TextBox_Start
	movs r0, #1
	movs r1, #1
	movs r2, #0x1e
	movs r3, #6
	bl TextBox_SetRect
	ldr r0, _0801F710 @ =0x0000A41A
	bl TextBox_SetBgPltt
	movs r0, #1
	bl TextBox_SetInstant
	adds r0, r6, #0
	movs r1, #1
	bl FUN_0801e2a8
	adds r0, r6, #0
	bl FUN_0801e328
	adds r0, r6, #0
	bl FUN_0801e458
	adds r0, r6, #0
	bl FUN_0801e4b0
	ldr r0, _0801F714 @ =0x00001C1A
	bl GetParticleGroup
	movs r2, #0x98
	lsls r2, r2, #1
	adds r1, r6, r2
	str r0, [r1]
	add r4, sp, #0x14
	mov sl, r4
	adds r7, r1, #0
	movs r0, #0xa6
	lsls r0, r0, #1
	adds r5, r6, r0
	movs r1, #0x9a
	lsls r1, r1, #1
	adds r4, r6, r1
	movs r2, #8
	rsbs r2, r2, #0
	mov sb, r2
	movs r0, #3
	mov r8, r0
_0801F642:
	ldr r1, [r7]
	adds r0, r4, #0
	movs r2, #0x11
	bl FUN_0822d9f0
	adds r0, r4, #0
	mov r1, sb
	mov r2, sb
	bl Particle_SetOffset
	ldr r1, [r7]
	adds r0, r4, #0
	movs r2, #0x33
	bl FUN_0822dafc
	movs r1, #1
	strb r1, [r4, #0xf]
	movs r2, #0
	str r2, [sp, #0x10]
	add r0, sp, #0x10
	adds r1, r5, #0
	ldr r2, _0801F718 @ =0x05000002
	bl CpuSet
	adds r5, #0x28
	adds r4, #0x28
	movs r0, #1
	rsbs r0, r0, #0
	add r8, r0
	mov r1, r8
	cmp r1, #0
	bge _0801F642
	movs r4, #0
	movs r0, #4
	str r0, [sp]
	ldr r5, _0801F71C @ =0x0000FFFF
	str r5, [sp, #4]
	str r4, [sp, #8]
	movs r0, #0
	movs r1, #4
	movs r2, #4
	movs r3, #4
	bl FUN_0823ce68
	adds r0, r6, #0
	movs r1, #0
	bl FUN_0801e284
	strb r4, [r6, #0x1b]
	strb r4, [r6, #0x1e]
	ldr r2, _0801F720 @ =0xFFFF0000
	ldr r0, [sp, #0x14]
	ands r0, r2
	movs r1, #0xdf
	orrs r0, r1
	ands r0, r5
	movs r1, #0x88
	lsls r1, r1, #0xf
	orrs r0, r1
	str r0, [sp, #0x14]
	mov r5, sl
	ldr r0, [r5, #4]
	ands r0, r2
	str r0, [r5, #4]
	movs r7, #0xdb
	lsls r7, r7, #3
	adds r5, r6, r7
	movs r0, #0x88
	lsls r0, r0, #1
	adds r6, r6, r0
	str r4, [sp]
	movs r1, #1
	str r1, [sp, #4]
	movs r0, #0x3c
	str r0, [sp, #8]
	mov r2, sl
	str r2, [sp, #0xc]
	adds r0, r5, #0
	adds r1, r6, #0
	movs r2, #8
	movs r3, #0x51
	bl MainSprite_Add
	str r4, [sp]
	adds r0, r5, #0
	adds r1, r6, #0
	movs r2, #0
	movs r3, #1
	bl MainSprite_SetAnim
	movs r0, #0xaa
	bl sound_08240264
	movs r0, #0
_0801F6FE:
	add sp, #0x1c
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0801F710: .4byte 0x0000A41A
_0801F714: .4byte 0x00001C1A
_0801F718: .4byte 0x05000002
_0801F71C: .4byte 0x0000FFFF
_0801F720: .4byte 0xFFFF0000
