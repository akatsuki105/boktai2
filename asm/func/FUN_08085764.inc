	push {r4, r5, lr}
	sub sp, #0x20
	adds r3, r0, #0
	movs r1, #0x80
	lsls r1, r1, #2
	adds r0, r3, r1
	ldrb r0, [r0]
	adds r0, #1
	movs r1, #7
	ands r0, r1
	lsls r4, r0, #5
	ldr r2, _0808579C @ =gSineTable
	adds r0, r4, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r5, #0
	ldrsh r1, [r0, r5]
	movs r0, #0x64
	muls r0, r1, r0
	adds r5, r2, #0
	cmp r0, #0
	blt _080857A0
	asrs r1, r0, #0xc
	b _080857A6
	.align 2, 0
_0808579C: .4byte gSineTable
_080857A0:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_080857A6:
	adds r0, r3, #0
	adds r0, #0x48
	ldrh r0, [r0]
	adds r0, r0, r1
	lsls r0, r0, #0x10
	adds r1, r3, #0
	adds r1, #0x4a
	ldrh r1, [r1]
	lsls r1, r1, #0x10
	lsrs r0, r0, #0x10
	orrs r0, r1
	str r0, [sp, #8]
	lsls r0, r4, #1
	adds r0, r0, r5
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r0, #0x64
	muls r0, r1, r0
	cmp r0, #0
	blt _080857D2
	asrs r2, r0, #0xc
	b _080857D8
_080857D2:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_080857D8:
	adds r0, r3, #0
	adds r0, #0x4c
	ldrh r1, [r0]
	adds r1, r1, r2
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r2, _0808580C @ =0xFFFF0000
	ldr r0, [sp, #0xc]
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #0xc]
	adds r0, r4, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r5
	movs r2, #0
	ldrsh r1, [r0, r2]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #1
	cmp r0, #0
	blt _08085810
	asrs r0, r0, #0xc
	b _08085816
	.align 2, 0
_0808580C: .4byte 0xFFFF0000
_08085810:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08085816:
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp, #0x10]
	lsls r0, r4, #1
	adds r0, r0, r5
	movs r5, #0
	ldrsh r1, [r0, r5]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #1
	cmp r0, #0
	blt _08085832
	asrs r0, r0, #0xc
	b _08085838
_08085832:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08085838:
	lsls r2, r0, #0x10
	lsrs r2, r2, #0x10
	ldr r3, _08085878 @ =0xFFFF0000
	add r1, sp, #0x10
	ldr r0, [r1, #4]
	ands r0, r3
	orrs r0, r2
	str r0, [r1, #4]
	ldr r0, [sp, #0x18]
	ands r0, r3
	movs r4, #0x20
	orrs r0, r4
	ldr r2, _0808587C @ =0x0000FFFF
	ands r0, r2
	str r0, [sp, #0x18]
	add r2, sp, #0x18
	ldr r0, [r2, #4]
	ands r0, r3
	orrs r0, r4
	str r0, [r2, #4]
	movs r0, #3
	str r0, [sp]
	movs r0, #4
	str r0, [sp, #4]
	add r0, sp, #8
	movs r3, #1
	bl FUN_080dbd08
	add sp, #0x20
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08085878: .4byte 0xFFFF0000
_0808587C: .4byte 0x0000FFFF
