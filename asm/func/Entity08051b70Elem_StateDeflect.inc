	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #4
	adds r6, r1, #0
	adds r3, r2, #0
	adds r7, r6, #0
	adds r7, #0x50
	movs r0, #0x24
	adds r0, r0, r6
	mov r8, r0
	ldrb r0, [r6, #1]
	cmp r0, #0
	beq _08051478
	movs r2, #0
	strb r2, [r6, #1]
	ldrb r0, [r6, #3]
	mov r1, r8
	strh r0, [r1, #0x10]
	ldrb r0, [r6, #2]
	strh r0, [r7, #0x10]
	ldr r0, [r6, #0x24]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r6, #0x24]
	ldr r0, [r6, #0x50]
	ands r0, r1
	str r0, [r6, #0x50]
	adds r5, r6, #0
	adds r5, #0xc
	movs r0, #3
	ands r0, r3
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #3
	movs r3, #0x88
	lsls r3, r3, #1
	adds r0, r1, r3
	strh r0, [r6, #0xc]
	movs r0, #0x20
	strh r0, [r5, #2]
	strh r2, [r5, #4]
	adds r4, r6, #0
	adds r4, #0x14
	adds r1, #0x50
	strh r1, [r6, #0x14]
	movs r0, #0x90
	strh r0, [r4, #2]
	strh r2, [r4, #4]
	adds r0, r6, #0
	movs r1, #0x20
	movs r2, #0xf
	bl Entity08051b70Elem_SetRandomWobble
	movs r1, #0xc
	ldrsh r0, [r6, r1]
	movs r2, #0x14
	ldrsh r1, [r6, r2]
	subs r0, r0, r1
	movs r3, #2
	ldrsh r1, [r5, r3]
	movs r3, #2
	ldrsh r2, [r4, r3]
	subs r1, r1, r2
	bl ArcTan2_8
	ldr r3, _08051434 @ =0x030046B8
	ldr r1, [r3]
	adds r1, #1
	ldr r2, _08051438 @ =0x000003FF
	ands r1, r2
	str r1, [r3]
	lsls r1, r1, #1
	ldr r2, _0805143C @ =0x0203B400
	adds r1, r1, r2
	ldrh r2, [r1]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	subs r0, #0x10
	movs r1, #0x1f
	ands r2, r1
	adds r0, r0, r2
	lsls r0, r0, #0x18
	adds r4, #8
	asrs r3, r0, #0x18
	ldr r2, _08051440 @ =gSineTable
	adds r0, r3, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	lsls r0, r0, #3
	cmp r0, #0
	blt _08051444
	asrs r0, r0, #0xc
	b _0805144A
	.align 2, 0
_08051434: .4byte 0x030046B8
_08051438: .4byte 0x000003FF
_0805143C: .4byte 0x0203B400
_08051440: .4byte gSineTable
_08051444:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0805144A:
	strh r0, [r4]
	ldr r1, _08051468 @ =gSineTable
	movs r0, #0xff
	ands r3, r0
	lsls r0, r3, #1
	adds r0, r0, r1
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r0, #8
	muls r0, r1, r0
	cmp r0, #0
	blt _0805146C
	asrs r1, r0, #0xc
	b _08051472
	.align 2, 0
_08051468: .4byte gSineTable
_0805146C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_08051472:
	movs r0, #0
	strh r1, [r4, #2]
	strh r0, [r4, #4]
_08051478:
	ldr r3, [r6, #8]
	cmp r3, #0x1b
	bhi _080514A2
	adds r4, r7, #0
	adds r4, #0x1c
	adds r1, r6, #0
	adds r1, #0xc
	adds r2, r6, #0
	adds r2, #0x14
	movs r0, #5
	str r0, [sp]
	adds r0, r4, #0
	bl LerpVec3
	ldr r1, [r6, #8]
	movs r3, #6
	ldrsh r2, [r6, r3]
	adds r0, r4, #0
	bl Entity08051b70_ApplyWobble
	b _080514C2
_080514A2:
	adds r1, r7, #0
	adds r1, #0x1c
	adds r2, r6, #0
	adds r2, #0x1c
	ldrh r0, [r6, #0x1c]
	ldrh r3, [r7, #0x1c]
	adds r0, r0, r3
	strh r0, [r7, #0x1c]
	ldrh r0, [r2, #2]
	ldrh r3, [r1, #2]
	adds r0, r0, r3
	strh r0, [r1, #2]
	ldrh r0, [r2, #4]
	ldrh r2, [r1, #4]
	adds r0, r0, r2
	strh r0, [r1, #4]
_080514C2:
	ldr r0, [r7, #0x1c]
	ldr r1, [r7, #0x20]
	mov r3, r8
	str r0, [r3, #0x1c]
	str r1, [r3, #0x20]
	ldr r0, [r6, #8]
	cmp r0, #0x2b
	bls _080514DC
	movs r1, #0
	strb r1, [r6]
	movs r0, #1
	strb r0, [r6, #1]
	str r1, [r6, #8]
_080514DC:
	ldr r0, [r6, #8]
	adds r0, #1
	str r0, [r6, #8]
	add sp, #4
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
