	push {r4, r5, r6, r7, lr}
	sub sp, #0x10
	adds r6, r2, #0
	mov r4, sp
	adds r3, r1, #0
	adds r3, #0xc
	adds r2, r0, #0
	adds r2, #0xc
	ldrh r0, [r0, #0xc]
	ldrh r1, [r1, #0xc]
	subs r0, r0, r1
	mov r1, sp
	strh r0, [r1]
	ldrh r0, [r2, #2]
	ldrh r1, [r3, #2]
	subs r0, r0, r1
	strh r0, [r4, #2]
	ldrh r0, [r2, #4]
	ldrh r1, [r3, #4]
	subs r0, r0, r1
	strh r0, [r4, #4]
	mov r0, sp
	movs r1, #0
	ldrsh r0, [r0, r1]
	movs r2, #4
	ldrsh r1, [r4, r2]
	bl ArcTan2_8
	adds r3, r0, #0
	adds r0, #0x10
	movs r5, #0xff
	ands r0, r5
	asrs r0, r0, #5
	lsls r3, r0, #5
	ldrh r0, [r4, #2]
	lsls r0, r0, #0x10
	cmp r0, #0
	ble _080DC570
	add r2, sp, #8
	ldr r0, _080DC514 @ =0x085B0A08
	adds r1, r3, #0
	adds r1, #0x40
	ands r1, r5
	lsls r1, r1, #1
	adds r1, r1, r0
	movs r4, #0
	ldrsh r1, [r1, r4]
	lsls r1, r1, #2
	adds r4, r2, #0
	adds r5, r0, #0
	cmp r1, #0
	blt _080DC518
	asrs r1, r1, #0xc
	b _080DC51E
	.align 2, 0
_080DC514: .4byte 0x085B0A08
_080DC518:
	rsbs r0, r1, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_080DC51E:
	movs r0, #0
	strh r1, [r2]
	strh r0, [r2, #2]
	movs r0, #0xff
	ands r0, r3
	lsls r0, r0, #1
	adds r0, r0, r5
	movs r3, #0
	ldrsh r1, [r0, r3]
	movs r0, #4
	muls r0, r1, r0
	cmp r0, #0
	blt _080DC53C
	asrs r0, r0, #0xc
	b _080DC542
_080DC53C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080DC542:
	strh r0, [r2, #4]
	ldr r0, _080DC56C @ =0x0000FFFC
	strh r0, [r4, #2]
	add r0, sp, #8
	ldrh r1, [r0]
	movs r2, #0x8e
	lsls r2, r2, #1
	adds r0, r6, r2
	strh r1, [r0]
	ldrh r0, [r4, #2]
	movs r3, #0x8f
	lsls r3, r3, #1
	adds r1, r6, r3
	strh r0, [r1]
	ldrh r1, [r4, #4]
	movs r4, #0x90
	lsls r4, r4, #1
	adds r0, r6, r4
	strh r1, [r0]
	b _080DC5F2
	.align 2, 0
_080DC56C: .4byte 0x0000FFFC
_080DC570:
	add r2, sp, #8
	movs r7, #0x12
	ldr r0, _080DC594 @ =0x085B0A08
	adds r1, r3, #0
	adds r1, #0x40
	ands r1, r5
	lsls r1, r1, #1
	adds r1, r1, r0
	movs r4, #0
	ldrsh r1, [r1, r4]
	muls r1, r7, r1
	adds r4, r2, #0
	adds r5, r0, #0
	cmp r1, #0
	blt _080DC598
	asrs r1, r1, #0xc
	b _080DC59E
	.align 2, 0
_080DC594: .4byte 0x085B0A08
_080DC598:
	rsbs r0, r1, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_080DC59E:
	movs r0, #0
	strh r1, [r2]
	strh r0, [r2, #2]
	movs r0, #0xff
	ands r0, r3
	lsls r0, r0, #1
	adds r0, r0, r5
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r7, r0
	cmp r0, #0
	blt _080DC5BA
	asrs r0, r0, #0xc
	b _080DC5C0
_080DC5BA:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080DC5C0:
	strh r0, [r2, #4]
	movs r0, #0x20
	strh r0, [r4, #2]
	movs r2, #0x8e
	lsls r2, r2, #1
	adds r1, r6, r2
	add r0, sp, #8
	ldrh r0, [r0]
	ldrh r3, [r1]
	adds r0, r0, r3
	strh r0, [r1]
	movs r0, #0x8f
	lsls r0, r0, #1
	adds r1, r6, r0
	ldrh r0, [r4, #2]
	ldrh r2, [r1]
	adds r0, r0, r2
	strh r0, [r1]
	movs r3, #0x90
	lsls r3, r3, #1
	adds r1, r6, r3
	ldrh r0, [r4, #4]
	ldrh r4, [r1]
	adds r0, r0, r4
	strh r0, [r1]
_080DC5F2:
	ldrh r0, [r6, #0x1e]
	adds r0, #1
	strh r0, [r6, #0x1e]
	ldr r0, _080DC610 @ =0x00000131
	adds r1, r6, r0
	movs r0, #0xc
	strb r0, [r1]
	movs r0, #0xb3
	lsls r0, r0, #1
	bl PlaySound_082406e0
	add sp, #0x10
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080DC610: .4byte 0x00000131
