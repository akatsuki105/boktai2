	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x1c
	adds r7, r0, #0
	adds r3, r1, #0
	movs r0, #0x48
	adds r0, r0, r7
	mov r8, r0
	ldr r1, _080291E4 @ =0x00001050
	adds r0, r7, r1
	ldr r0, [r0]
	cmp r0, #0
	bne _08029186
	b _080292A2
_08029186:
	ldr r2, _080291E8 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _080291EC @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r2, _080291F0 @ =0x0203B400
	adds r0, r0, r2
	ldrh r5, [r0]
	movs r0, #0x1f
	ands r5, r0
	adds r0, #0xe1
	mov sl, r0
	lsls r3, r3, #2
	str r3, [sp, #0x14]
	movs r1, #0x86
	lsls r1, r1, #1
	adds r1, r7, r1
	str r1, [sp, #0x18]
	add r4, sp, #8
	movs r2, #2
	mov sb, r2
	adds r3, r7, #0
	adds r3, #0x50
	str r3, [sp, #0x10]
_080291BA:
	ldr r1, [sp, #0x18]
	ldr r2, [sp, #0x14]
	adds r0, r1, r2
	ldr r6, [r0]
	ldr r2, _080291F4 @ =gSineTable
	adds r0, r5, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r3, #0
	ldrsh r0, [r0, r3]
	mov r1, sl
	muls r1, r0, r1
	adds r0, r1, #0
	cmp r0, #0
	blt _080291F8
	asrs r1, r0, #0xc
	b _080291FE
	.align 2, 0
_080291E4: .4byte 0x00001050
_080291E8: .4byte 0x030046B8
_080291EC: .4byte 0x000003FF
_080291F0: .4byte 0x0203B400
_080291F4: .4byte gSineTable
_080291F8:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_080291FE:
	movs r0, #0
	strh r1, [r4]
	strh r0, [r4, #2]
	movs r0, #0xff
	ands r0, r5
	lsls r0, r0, #1
	ldr r2, _08029220 @ =gSineTable
	adds r0, r0, r2
	movs r3, #0
	ldrsh r0, [r0, r3]
	mov r1, sl
	muls r1, r0, r1
	adds r0, r1, #0
	cmp r0, #0
	blt _08029224
	asrs r1, r0, #0xc
	b _0802922A
	.align 2, 0
_08029220: .4byte gSineTable
_08029224:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0802922A:
	mov r2, r8
	ldrh r0, [r2, #8]
	ldrh r3, [r4]
	adds r0, r0, r3
	strh r0, [r4]
	ldr r2, [sp, #0x10]
	ldrh r0, [r2, #4]
	adds r0, r1, r0
	strh r0, [r4, #4]
	mov r3, r8
	ldrh r0, [r3, #0xa]
	adds r0, #0xa4
	strh r0, [r4, #2]
	adds r5, #0x56
	movs r1, #0
	ldrsh r0, [r6, r1]
	movs r2, #0
	ldrsh r1, [r4, r2]
	subs r0, r0, r1
	movs r3, #4
	ldrsh r1, [r6, r3]
	movs r3, #4
	ldrsh r2, [r4, r3]
	subs r1, r1, r2
	bl ArcTan2_8
	adds r3, r0, #0
	ldr r2, _080292B4 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _080292B8 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _080292BC @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	movs r1, #0x1f
	ands r0, r1
	adds r3, r3, r0
	subs r3, #0x10
	ldr r2, _080292C0 @ =0x00001050
	adds r0, r7, r2
	ldr r0, [r0]
	movs r1, #0xf
	str r1, [sp]
	ldr r2, _080292C4 @ =0x000008BE
	adds r1, r7, r2
	ldrh r1, [r1]
	str r1, [sp, #4]
	add r1, sp, #8
	adds r2, r6, #0
	bl FUN_0805b0b0
	movs r3, #1
	rsbs r3, r3, #0
	add sb, r3
	mov r0, sb
	cmp r0, #0
	bge _080291BA
_080292A2:
	add sp, #0x1c
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080292B4: .4byte 0x030046B8
_080292B8: .4byte 0x000003FF
_080292BC: .4byte 0x0203B400
_080292C0: .4byte 0x00001050
_080292C4: .4byte 0x000008BE
