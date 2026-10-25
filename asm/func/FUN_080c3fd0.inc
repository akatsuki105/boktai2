	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	mov r8, r0
	ldr r7, _080C404C @ =0x000023D4
	add r7, r8
	adds r1, #2
	ldrb r0, [r7, #2]
	adds r1, r1, r0
	strb r1, [r7, #2]
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	cmp r1, #0x1d
	bhi _080C3FEE
	b _080C40FC
_080C3FEE:
	ldrb r1, [r7, #1]
	lsls r0, r1, #3
	subs r0, r0, r1
	lsls r0, r0, #3
	adds r0, #8
	adds r6, r7, r0
	movs r0, #0
	strb r0, [r6, #1]
	movs r0, #1
	strb r0, [r6]
	ldr r4, _080C4050 @ =0x0203B400
	ldr r1, _080C4054 @ =0x030046B8
	ldr r0, [r1]
	adds r0, #1
	ldr r2, _080C4058 @ =0x000003FF
	ands r0, r2
	lsls r1, r0, #1
	adds r1, r1, r4
	movs r5, #0xff
	ldrb r3, [r1]
	adds r0, #1
	ands r0, r2
	ldr r2, _080C4054 @ =0x030046B8
	str r0, [r2]
	lsls r0, r0, #1
	adds r0, r0, r4
	ldrh r0, [r0]
	movs r1, #0x7f
	ands r0, r1
	movs r4, #0xa0
	lsls r4, r4, #1
	adds r2, r0, r4
	ldr r1, _080C405C @ =gSineTable
	adds r0, r3, #0
	adds r0, #0x40
	ands r0, r5
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r4, #0
	ldrsh r0, [r0, r4]
	muls r0, r2, r0
	ldr r4, _080C4054 @ =0x030046B8
	cmp r0, #0
	blt _080C4060
	asrs r0, r0, #0xc
	b _080C4066
	.align 2, 0
_080C404C: .4byte 0x000023D4
_080C4050: .4byte 0x0203B400
_080C4054: .4byte 0x030046B8
_080C4058: .4byte 0x000003FF
_080C405C: .4byte gSineTable
_080C4060:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080C4066:
	strh r0, [r6, #8]
	lsls r0, r3, #1
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r2, r0
	cmp r0, #0
	blt _080C407A
	asrs r0, r0, #0xc
	b _080C4080
_080C407A:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080C4080:
	strh r0, [r6, #0xc]
	ldr r0, [r4]
	adds r0, #1
	ldr r1, _080C4108 @ =0x000003FF
	ands r0, r1
	str r0, [r4]
	lsls r0, r0, #1
	ldr r2, _080C410C @ =0x0203B400
	adds r0, r0, r2
	ldrh r0, [r0]
	movs r1, #7
	ands r0, r1
	adds r0, #0x1c
	strh r0, [r6, #6]
	adds r4, r6, #0
	adds r4, #0x10
	ldr r0, [r6, #0x10]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r6, #0x10]
	ldr r1, [r7, #4]
	adds r0, r4, #0
	movs r2, #2
	bl Particle_SetFrame
	movs r1, #0xba
	lsls r1, r1, #2
	add r1, r8
	ldrh r0, [r6, #8]
	ldrh r1, [r1]
	adds r0, r0, r1
	strh r0, [r4, #0x18]
	ldr r0, _080C4110 @ =0x000002EA
	add r0, r8
	ldrh r0, [r0]
	strh r0, [r4, #0x1a]
	movs r0, #0xbb
	lsls r0, r0, #2
	add r0, r8
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r1, r2, #0
	ldrh r6, [r6, #0xc]
	adds r1, r1, r6
	ldrh r0, [r0]
	adds r0, r0, r1
	strh r0, [r4, #0x1c]
	ldrb r0, [r7, #1]
	adds r0, #1
	strb r0, [r7, #1]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #7
	bls _080C40F2
	movs r0, #0
	strb r0, [r7, #1]
_080C40F2:
	ldrb r0, [r7, #2]
	subs r0, #0x1e
	strb r0, [r7, #2]
	movs r0, #1
	strb r0, [r7, #3]
_080C40FC:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080C4108: .4byte 0x000003FF
_080C410C: .4byte 0x0203B400
_080C4110: .4byte 0x000002EA
