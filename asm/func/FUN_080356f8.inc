	push {r4, r5, r6, r7, lr}
	sub sp, #0x10
	adds r5, r0, #0
	adds r4, r1, #0
	adds r6, r5, #0
	adds r1, r6, #0
	adds r1, #0xa9
	ldrb r0, [r1]
	cmp r0, #0
	beq _080357B2
	movs r0, #0
	strb r0, [r1]
	movs r2, #0xaf
	lsls r2, r2, #1
	adds r1, r6, r2
	strh r0, [r1]
	movs r3, #0xae
	lsls r3, r3, #1
	adds r1, r6, r3
	strh r0, [r1]
	adds r0, r6, #0
	adds r0, #0xab
	ldrb r0, [r0]
	cmp r0, #0
	beq _08035740
	ldr r7, _0803573C @ =0x00000824
	adds r0, r6, r7
	ldr r0, [r0]
	movs r3, #0x18
	cmp r0, #0
	bne _08035750
	movs r3, #0x14
	b _08035750
	.align 2, 0
_0803573C: .4byte 0x00000824
_08035740:
	movs r1, #0x82
	lsls r1, r1, #4
	adds r0, r6, r1
	ldr r0, [r0]
	movs r3, #0x14
	cmp r0, #0
	beq _08035750
	movs r3, #0x18
_08035750:
	movs r2, #0xbd
	lsls r2, r2, #2
	adds r1, r6, r2
	movs r7, #0xb5
	lsls r7, r7, #2
	adds r2, r6, r7
	movs r0, #1
	str r0, [sp]
	movs r0, #4
	str r0, [sp, #4]
	adds r0, r5, #0
	bl Boss_PlayAnim
	movs r0, #6
	movs r2, #0xce
	ldr r3, _08035790 @ =0x0000087C
	adds r1, r6, r3
	movs r3, #0
	strb r0, [r1]
	ldr r7, _08035794 @ =0x0000087A
	adds r0, r6, r7
	strh r2, [r0]
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r0, #1
	bne _0803579C
	ldr r0, _08035798 @ =0x00000878
	adds r1, r6, r0
	movs r0, #0x1f
	strh r0, [r1]
	b _080357B2
	.align 2, 0
_08035790: .4byte 0x0000087C
_08035794: .4byte 0x0000087A
_08035798: .4byte 0x00000878
_0803579C:
	cmp r0, #0
	bne _080357AC
	ldr r1, _080357A8 @ =0x00000878
	adds r0, r6, r1
	b _080357B0
	.align 2, 0
_080357A8: .4byte 0x00000878
_080357AC:
	ldr r2, _08035820 @ =0x00000878
	adds r0, r6, r2
_080357B0:
	strh r3, [r0]
_080357B2:
	movs r3, #0xc0
	lsls r3, r3, #1
	adds r1, r6, r3
	movs r2, #0
	movs r0, #0
	strh r0, [r1]
	movs r7, #0xb3
	lsls r7, r7, #1
	adds r0, r6, r7
	strb r2, [r0]
	ldr r1, _08035824 @ =0x00000167
	adds r0, r6, r1
	strb r2, [r0]
	movs r2, #0xc
	adds r1, r5, #0
	adds r1, #0x98
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	adds r2, #0xf4
	adds r0, r5, r2
	ldr r1, [r0]
	adds r0, r5, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _080357EC
	b _08035A2A
_080357EC:
	movs r3, #0xb1
	lsls r3, r3, #1
	adds r0, r6, r3
	ldrh r2, [r0]
	movs r7, #0
	ldrsh r1, [r0, r7]
	adds r3, r0, #0
	cmp r1, #0x3d
	bgt _08035802
	adds r0, r2, #2
	strh r0, [r3]
_08035802:
	ldr r2, _08035828 @ =gSineTable
	lsls r0, r4, #1
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r1, [r0, r2]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #3
	cmp r0, #0
	blt _0803582C
	asrs r1, r0, #0xc
	b _08035832
	.align 2, 0
_08035820: .4byte 0x00000878
_08035824: .4byte 0x00000167
_08035828: .4byte gSineTable
_0803582C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_08035832:
	ldrh r0, [r3]
	adds r0, r0, r1
	movs r3, #0xb0
	lsls r3, r3, #1
	adds r1, r6, r3
	movs r7, #0
	strh r0, [r1]
	lsls r0, r0, #0x10
	cmp r0, #0
	bge _08035848
	strh r7, [r1]
_08035848:
	movs r0, #0xaf
	lsls r0, r0, #1
	adds r4, r6, r0
	ldrh r2, [r4]
	cmp r2, #1
	beq _080358DA
	cmp r2, #1
	bgt _0803585E
	cmp r2, #0
	beq _08035864
	b _08035922
_0803585E:
	cmp r2, #2
	beq _08035918
	b _08035922
_08035864:
	movs r2, #0xae
	lsls r2, r2, #1
	adds r1, r6, r2
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x1d
	bls _08035918
	adds r0, r6, #0
	adds r0, #0xab
	ldrb r0, [r0]
	cmp r0, #0
	beq _08035898
	ldr r3, _08035894 @ =0x00000824
	adds r0, r6, r3
	ldr r0, [r0]
	movs r3, #0x19
	cmp r0, #0
	bne _080358A8
	movs r3, #0x15
	b _080358A8
	.align 2, 0
_08035894: .4byte 0x00000824
_08035898:
	movs r7, #0x82
	lsls r7, r7, #4
	adds r0, r6, r7
	ldr r0, [r0]
	movs r3, #0x15
	cmp r0, #0
	beq _080358A8
	movs r3, #0x19
_080358A8:
	movs r0, #0xbd
	lsls r0, r0, #2
	adds r1, r6, r0
	movs r7, #0xb5
	lsls r7, r7, #2
	adds r2, r6, r7
	movs r0, #2
	str r0, [sp]
	movs r0, #4
	str r0, [sp, #4]
	adds r0, r5, #0
	bl Boss_PlayAnim
	movs r0, #0xaf
	lsls r0, r0, #1
	adds r2, r6, r0
	ldrh r0, [r2]
	adds r0, #1
	movs r1, #0
	strh r0, [r2]
	movs r2, #0xae
	lsls r2, r2, #1
	adds r0, r6, r2
	strh r1, [r0]
	b _08035918
_080358DA:
	movs r0, #0xae
	lsls r0, r0, #1
	adds r3, r6, r0
	ldrh r0, [r3]
	adds r0, #1
	strh r0, [r3]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xb3
	bls _0803590A
	ldr r1, _08035914 @ =0x00000311
	adds r0, r6, r1
	ldrb r1, [r0]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _0803590A
	adds r0, r5, #0
	adds r0, #0xa7
	strb r2, [r0]
	ldrh r0, [r4]
	adds r0, #1
	strh r0, [r4]
	strh r7, [r3]
_0803590A:
	movs r0, #4
	movs r2, #0xc5
	lsls r2, r2, #1
	adds r1, r6, r2
	b _08035920
	.align 2, 0
_08035914: .4byte 0x00000311
_08035918:
	movs r0, #4
	movs r3, #0xc5
	lsls r3, r3, #1
	adds r1, r6, r3
_08035920:
	strb r0, [r1]
_08035922:
	movs r7, #0xaf
	lsls r7, r7, #1
	adds r0, r6, r7
	ldrh r0, [r0]
	cmp r0, #0
	bne _08035944
	adds r0, r5, #0
	adds r0, #0xe0
	ldr r0, [r0]
	movs r1, #0xf
	ands r0, r1
	cmp r0, #0
	bne _08035A2A
	adds r0, r6, #0
	bl FUN_08028cb0
	b _08035A2A
_08035944:
	adds r0, r5, #0
	adds r0, #0xe0
	ldr r0, [r0]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	bne _08035A2A
	ldr r4, _0803599C @ =0x0203B400
	ldr r3, _080359A0 @ =0x030046B8
	ldr r0, [r3]
	adds r0, #1
	ldr r2, _080359A4 @ =0x000003FF
	ands r0, r2
	lsls r1, r0, #1
	adds r1, r1, r4
	movs r5, #0xff
	mov ip, r5
	ldrb r1, [r1]
	adds r0, #1
	ands r0, r2
	str r0, [r3]
	lsls r0, r0, #1
	adds r0, r0, r4
	ldrh r4, [r0]
	movs r0, #0x3f
	add r7, sp, #8
	adds r5, r1, #0
	ands r4, r0
	ldr r1, _080359A8 @ =gSineTable
	adds r0, r5, #0
	adds r0, #0x40
	mov r2, ip
	ands r0, r2
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r4, r0
	mov ip, r3
	cmp r0, #0
	blt _080359AC
	asrs r2, r0, #0xc
	b _080359B2
	.align 2, 0
_0803599C: .4byte 0x0203B400
_080359A0: .4byte 0x030046B8
_080359A4: .4byte 0x000003FF
_080359A8: .4byte gSineTable
_080359AC:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_080359B2:
	movs r0, #0
	strh r2, [r7]
	strh r0, [r7, #2]
	lsls r0, r5, #1
	adds r0, r0, r1
	movs r3, #0
	ldrsh r0, [r0, r3]
	muls r0, r4, r0
	cmp r0, #0
	blt _080359CA
	asrs r0, r0, #0xc
	b _080359D0
_080359CA:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080359D0:
	strh r0, [r7, #4]
	add r3, sp, #8
	movs r5, #0xc5
	lsls r5, r5, #2
	adds r2, r6, r5
	adds r1, r3, #0
	ldrh r0, [r2]
	ldrh r1, [r1]
	adds r0, r0, r1
	adds r1, r3, #0
	strh r0, [r1]
	ldrh r1, [r3, #2]
	ldrh r0, [r2, #2]
	adds r1, r1, r0
	ldrh r0, [r2, #4]
	ldrh r7, [r3, #4]
	adds r0, r0, r7
	strh r0, [r3, #4]
	movs r0, #0x80
	lsls r0, r0, #1
	adds r1, r1, r0
	strh r1, [r3, #2]
	ldr r3, _08035A34 @ =0x0203B400
	mov r2, ip
	ldr r1, [r2]
	adds r1, #1
	ldr r2, _08035A38 @ =0x000003FF
	ands r1, r2
	lsls r0, r1, #1
	adds r0, r0, r3
	ldrb r0, [r0]
	adds r1, #1
	ands r1, r2
	mov r5, ip
	str r1, [r5]
	lsls r1, r1, #1
	adds r1, r1, r3
	ldrh r1, [r1]
	movs r2, #0xf
	ands r1, r2
	adds r1, #0x10
	movs r2, #0x10
	add r3, sp, #8
	bl Entity08060470_Spawn
_08035A2A:
	add sp, #0x10
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08035A34: .4byte 0x0203B400
_08035A38: .4byte 0x000003FF
