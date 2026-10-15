	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r7, r0, #0
	movs r0, #0x77
	adds r0, r0, r7
	mov r8, r0
	ldrb r1, [r0]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	adds r0, r7, r0
	adds r0, #0xa4
	movs r3, #0
	movs r1, #1
	strb r1, [r0]
	mov r0, r8
	ldrb r1, [r0]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	adds r1, r7, #0
	adds r1, #0x7c
	adds r1, r1, r0
	ldr r0, [r1]
	movs r2, #2
	rsbs r2, r2, #0
	ands r0, r2
	str r0, [r1]
	mov r0, r8
	ldrb r1, [r0]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	adds r0, r7, r0
	adds r0, #0xa8
	strh r3, [r0]
	ldr r6, _080C1760 @ =0x0203B400
	ldr r5, _080C1764 @ =0x030046B8
	ldr r1, [r5]
	adds r1, #1
	ldr r4, _080C1768 @ =0x000003FF
	ands r1, r4
	lsls r0, r1, #1
	adds r0, r0, r6
	ldrh r2, [r0]
	mov r0, r8
	ldrb r3, [r0]
	lsls r0, r3, #1
	adds r0, r0, r3
	lsls r0, r0, #4
	adds r0, r7, r0
	asrs r2, r2, #3
	movs r3, #0x7f
	ands r2, r3
	adds r2, #0x40
	adds r0, #0xa6
	strh r2, [r0]
	adds r1, #1
	ands r1, r4
	str r1, [r5]
	lsls r1, r1, #1
	adds r1, r1, r6
	ldrh r0, [r1]
	movs r1, #0x60
	bl Mod
	mov r1, r8
	ldrb r2, [r1]
	lsls r1, r2, #1
	adds r1, r1, r2
	lsls r1, r1, #4
	adds r1, r7, r1
	subs r0, #0x30
	adds r1, #0xa5
	strb r0, [r1]
	adds r0, r7, #0
	adds r0, #0x6e
	ldrb r0, [r0]
	adds r0, #5
	movs r1, #7
	ands r0, r1
	lsls r4, r0, #5
	mov r1, r8
	ldrb r0, [r1]
	lsls r2, r0, #1
	adds r2, r2, r0
	lsls r2, r2, #4
	adds r2, r7, r2
	adds r0, r2, #0
	adds r0, #0xa5
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	movs r1, #0x80
	lsls r1, r1, #1
	adds r0, r0, r1
	adds r4, r4, r0
	movs r3, #0xff
	ands r4, r3
	adds r2, #0x94
	ldr r0, [r7, #0x38]
	ldr r1, [r7, #0x3c]
	str r0, [r2]
	str r1, [r2, #4]
	mov r0, r8
	ldrb r1, [r0]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	adds r0, r7, r0
	adds r0, #0xa6
	ldrh r2, [r0]
	ldr r1, _080C176C @ =0x085B0A08
	adds r0, r4, #0
	adds r0, #0x40
	ands r0, r3
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r2, r0
	cmp r0, #0
	blt _080C1770
	asrs r2, r0, #0xc
	b _080C1776
	.align 2, 0
_080C1760: .4byte 0x0203B400
_080C1764: .4byte 0x030046B8
_080C1768: .4byte 0x000003FF
_080C176C: .4byte 0x085B0A08
_080C1770:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_080C1776:
	adds r3, r7, #0
	adds r3, #0x77
	ldrb r1, [r3]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	adds r0, r7, r0
	adds r0, #0x94
	ldrh r1, [r0]
	adds r1, r1, r2
	strh r1, [r0]
	ldrb r1, [r3]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	adds r0, r7, r0
	adds r0, #0xa6
	ldrh r2, [r0]
	ldr r1, _080C17B0 @ =0x085B0A08
	lsls r0, r4, #1
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r2, r0
	cmp r0, #0
	blt _080C17B4
	asrs r2, r0, #0xc
	b _080C17BA
	.align 2, 0
_080C17B0: .4byte 0x085B0A08
_080C17B4:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_080C17BA:
	ldrb r1, [r3]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	adds r0, r7, r0
	adds r0, #0x98
	ldrh r1, [r0]
	adds r1, r1, r2
	strh r1, [r0]
	ldrb r0, [r3]
	adds r0, #1
	strb r0, [r3]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #3
	bls _080C17DE
	movs r0, #0
	strb r0, [r3]
_080C17DE:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
