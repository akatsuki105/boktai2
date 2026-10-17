	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r7, r0, #0
	mov sb, r1
	ldr r1, [r7, #0x18]
	ldr r0, _080CD24C @ =0x03002C68
	ldr r0, [r0]
	cmp r0, #0
	bne _080CD250
	movs r2, #0
	b _080CD258
	.align 2, 0
_080CD24C: .4byte 0x03002C68
_080CD250:
	adds r0, #0x60
	adds r0, r0, r1
	ldrb r0, [r0]
	adds r2, r0, #0
_080CD258:
	ldr r0, _080CD2E8 @ =0x0000085E
	adds r1, r7, r0
	ldrb r0, [r1]
	adds r0, #2
	adds r0, r2, r0
	strb r0, [r1]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x27
	bhi _080CD26E
	b _080CD39C
_080CD26E:
	ldr r1, _080CD2EC @ =0x0000085D
	adds r0, r7, r1
	ldrb r1, [r0]
	movs r0, #0x34
	muls r0, r1, r0
	movs r2, #0x86
	lsls r2, r2, #4
	adds r0, r0, r2
	adds r6, r7, r0
	mov r8, r6
	ldr r0, [r6]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r6]
	adds r1, r6, #0
	adds r1, #0x2b
	movs r0, #2
	strb r0, [r1]
	ldr r3, _080CD2F0 @ =0x00000858
	adds r0, r7, r3
	ldr r1, [r0]
	adds r0, r6, #0
	movs r2, #2
	bl Particle_SetFrame
	ldr r0, _080CD2F4 @ =0x0203B400
	mov ip, r0
	ldr r3, _080CD2F8 @ =0x030046B8
	ldr r0, [r3]
	adds r0, #1
	ldr r2, _080CD2FC @ =0x000003FF
	ands r0, r2
	lsls r1, r0, #1
	add r1, ip
	movs r5, #0xff
	ldrb r4, [r1]
	adds r0, #1
	ands r0, r2
	str r0, [r3]
	lsls r0, r0, #1
	add r0, ip
	ldrh r0, [r0]
	movs r1, #0x3f
	ands r0, r1
	adds r2, r0, #0
	adds r2, #0x80
	ldr r1, _080CD300 @ =gSineTable
	adds r0, r4, #0
	adds r0, #0x40
	ands r0, r5
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r2, r0
	cmp r0, #0
	blt _080CD304
	asrs r0, r0, #0xc
	b _080CD30A
	.align 2, 0
_080CD2E8: .4byte 0x0000085E
_080CD2EC: .4byte 0x0000085D
_080CD2F0: .4byte 0x00000858
_080CD2F4: .4byte 0x0203B400
_080CD2F8: .4byte 0x030046B8
_080CD2FC: .4byte 0x000003FF
_080CD300: .4byte gSineTable
_080CD304:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080CD30A:
	strh r0, [r6, #0x2c]
	ldr r0, _080CD320 @ =gSineTable
	lsls r1, r4, #1
	adds r1, r1, r0
	movs r3, #0
	ldrsh r0, [r1, r3]
	muls r0, r2, r0
	cmp r0, #0
	blt _080CD324
	asrs r0, r0, #0xc
	b _080CD32A
	.align 2, 0
_080CD320: .4byte gSineTable
_080CD324:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080CD32A:
	movs r3, #0
	strh r0, [r6, #0x30]
	mov r2, sb
	ldr r0, [r2]
	ldr r1, [r2, #4]
	mov r2, r8
	str r0, [r2, #0x18]
	str r1, [r2, #0x1c]
	ldrh r0, [r6, #0x2c]
	ldrh r1, [r2, #0x18]
	adds r0, r0, r1
	strh r0, [r2, #0x18]
	ldrh r0, [r6, #0x30]
	ldrh r2, [r2, #0x1c]
	adds r0, r0, r2
	mov r1, r8
	strh r0, [r1, #0x1c]
	ldr r2, _080CD3A8 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _080CD3AC @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r2, _080CD3B0 @ =0x0203B400
	adds r0, r0, r2
	ldrh r0, [r0]
	movs r1, #3
	ands r0, r1
	adds r0, #0xe
	adds r1, r6, #0
	adds r1, #0x2a
	strb r0, [r1]
	adds r0, r6, #0
	adds r0, #0x29
	strb r3, [r0]
	subs r0, #1
	movs r2, #1
	strb r2, [r0]
	ldr r0, _080CD3B4 @ =0x0000085D
	adds r1, r7, r0
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #3
	bls _080CD38C
	strb r3, [r1]
_080CD38C:
	ldr r1, _080CD3B8 @ =0x0000085E
	adds r0, r7, r1
	ldrb r1, [r0]
	subs r1, #0x28
	strb r1, [r0]
	ldr r3, _080CD3BC @ =0x0000085C
	adds r0, r7, r3
	strb r2, [r0]
_080CD39C:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080CD3A8: .4byte 0x030046B8
_080CD3AC: .4byte 0x000003FF
_080CD3B0: .4byte 0x0203B400
_080CD3B4: .4byte 0x0000085D
_080CD3B8: .4byte 0x0000085E
_080CD3BC: .4byte 0x0000085C
