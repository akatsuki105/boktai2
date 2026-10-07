	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	adds r5, r0, #0
	ldr r0, _08084AE0 @ =0x0000020D
	bl PlaySound_082406e0
	ldr r7, _08084AE4 @ =0x030046B8
	ldr r0, _08084AE8 @ =0x000003FF
	mov sl, r0
	movs r1, #0
	str r1, [sp]
	adds r6, r5, #0
	adds r6, #0xd4
	adds r4, r6, #0
	movs r2, #0xff
	mov sb, r2
	movs r3, #0xb
	mov r8, r3
_08084A40:
	ldr r1, [r4]
	movs r0, #2
	rsbs r0, r0, #0
	ands r1, r0
	ldr r0, _08084AEC @ =0xFFFFFDFF
	ands r1, r0
	str r1, [r4]
	adds r0, r5, #0
	adds r0, #0xd0
	ldr r1, [r0]
	ldr r0, [r7]
	adds r0, #1
	mov r2, sl
	ands r0, r2
	str r0, [r7]
	lsls r0, r0, #1
	ldr r3, _08084AF0 @ =0x0203B400
	adds r0, r0, r3
	ldrh r2, [r0]
	movs r0, #1
	ands r2, r0
	adds r2, #4
	adds r0, r6, #0
	bl Particle_SetFrame
	adds r0, r5, #0
	adds r0, #0xc0
	ldrh r0, [r0]
	strh r0, [r4, #0x18]
	adds r0, r5, #0
	adds r0, #0xc2
	ldrh r0, [r0]
	strh r0, [r4, #0x1a]
	adds r0, r5, #0
	adds r0, #0xc4
	ldrh r0, [r0]
	strh r0, [r4, #0x1c]
	ldr r0, [r7]
	adds r0, #1
	mov r1, sl
	ands r0, r1
	str r0, [r7]
	lsls r0, r0, #1
	ldr r2, _08084AF0 @ =0x0203B400
	adds r0, r0, r2
	ldrh r0, [r0]
	movs r1, #0x60
	bl Mod
	adds r2, r0, #0
	adds r2, #0x30
	ldr r0, [r7]
	adds r0, #1
	mov r3, sl
	ands r0, r3
	str r0, [r7]
	lsls r0, r0, #1
	ldr r1, _08084AF0 @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	movs r1, #0xf
	ands r0, r1
	ldr r3, [sp]
	adds r1, r3, r0
	mov r0, sb
	ands r1, r0
	adds r0, r1, #0
	adds r0, #0x40
	mov r3, sb
	ands r0, r3
	lsls r0, r0, #1
	ldr r3, _08084AF4 @ =0x085B0A08
	adds r0, r0, r3
	movs r3, #0
	ldrsh r0, [r0, r3]
	muls r0, r2, r0
	cmp r0, #0
	blt _08084AF8
	asrs r0, r0, #0xc
	b _08084AFE
	.align 2, 0
_08084AE0: .4byte 0x0000020D
_08084AE4: .4byte 0x030046B8
_08084AE8: .4byte 0x000003FF
_08084AEC: .4byte 0xFFFFFDFF
_08084AF0: .4byte 0x0203B400
_08084AF4: .4byte 0x085B0A08
_08084AF8:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08084AFE:
	strh r0, [r4, #0x34]
	mov r0, sb
	ands r1, r0
	lsls r0, r1, #1
	ldr r1, _08084B18 @ =0x085B0A08
	adds r0, r0, r1
	movs r3, #0
	ldrsh r0, [r0, r3]
	muls r0, r2, r0
	cmp r0, #0
	blt _08084B1C
	asrs r1, r0, #0xc
	b _08084B22
	.align 2, 0
_08084B18: .4byte 0x085B0A08
_08084B1C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_08084B22:
	movs r0, #0
	strh r1, [r4, #0x36]
	ldr r1, _08084B58 @ =FUN_080849a4
	str r1, [r4, #0x38]
	movs r1, #1
	strh r1, [r4, #0x2c]
	strh r0, [r4, #0x2e]
	ldr r0, [sp]
	adds r0, #0x14
	str r0, [sp]
	adds r4, #0x3c
	adds r6, #0x3c
	subs r1, #2
	add r8, r1
	mov r2, r8
	cmp r2, #0
	blt _08084B46
	b _08084A40
_08084B46:
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08084B58: .4byte FUN_080849a4
