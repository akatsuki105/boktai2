	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #8
	adds r6, r0, #0
	adds r4, r3, #0
	movs r0, #0x46
	muls r0, r1, r0
	cmp r0, #0
	blt _08068EAC
	asrs r0, r0, #0xc
	b _08068EB2
_08068EAC:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08068EB2:
	adds r7, r0, #0
	movs r0, #0x46
	muls r0, r2, r0
	cmp r0, #0
	blt _08068EC0
	asrs r0, r0, #0xc
	b _08068EC6
_08068EC0:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08068EC6:
	mov r8, r0
	bl FUN_080865c0
	adds r5, r0, #0
	movs r1, #0
	ldrsh r0, [r5, r1]
	movs r2, #0x2c
	ldrsh r1, [r6, r2]
	subs r0, r0, r1
	subs r3, r0, r7
	movs r1, #4
	ldrsh r0, [r5, r1]
	movs r2, #0x30
	ldrsh r1, [r6, r2]
	subs r0, r0, r1
	mov r1, r8
	subs r2, r0, r1
	adds r0, r3, #0
	muls r0, r3, r0
	adds r1, r2, #0
	muls r1, r2, r1
	adds r0, r0, r1
	adds r1, r4, #0
	muls r1, r4, r1
	cmp r0, r1
	bgt _08068EFC
	b _0806920A
_08068EFC:
	adds r0, r3, #0
	adds r1, r2, #0
	bl FUN_0823785c
	adds r3, r0, #0
	ldr r2, _08068F20 @ =0x085B0A08
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r4, r0
	cmp r0, #0
	blt _08068F24
	asrs r0, r0, #0xc
	b _08068F2A
	.align 2, 0
_08068F20: .4byte 0x085B0A08
_08068F24:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08068F2A:
	ldrh r1, [r6, #0x2c]
	adds r1, r1, r0
	adds r1, r1, r7
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r2, _08068F58 @ =0xFFFF0000
	ldr r0, [sp]
	ands r0, r2
	orrs r0, r1
	str r0, [sp]
	ldr r1, _08068F5C @ =0x085B0A08
	movs r0, #0xff
	ands r0, r3
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r7, #0
	ldrsh r0, [r0, r7]
	muls r0, r4, r0
	cmp r0, #0
	blt _08068F60
	asrs r1, r0, #0xc
	b _08068F66
	.align 2, 0
_08068F58: .4byte 0xFFFF0000
_08068F5C: .4byte 0x085B0A08
_08068F60:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_08068F66:
	ldrh r0, [r6, #0x30]
	adds r0, r0, r1
	add r0, r8
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r2, _08068FE8 @ =0xFFFF0000
	mov r4, sp
	ldr r3, [sp, #4]
	ands r3, r2
	orrs r3, r0
	str r3, [sp, #4]
	movs r1, #0
	ldrsh r0, [r5, r1]
	lsls r1, r0, #1
	adds r1, r1, r0
	mov r0, sp
	movs r7, #0
	ldrsh r0, [r0, r7]
	adds r1, r1, r0
	lsls r1, r1, #0xe
	lsrs r1, r1, #0x10
	ldr r0, [sp]
	ands r0, r2
	orrs r0, r1
	str r0, [sp]
	movs r0, #4
	ldrsh r1, [r5, r0]
	lsls r0, r1, #1
	adds r0, r0, r1
	movs r5, #4
	ldrsh r1, [r4, r5]
	adds r0, r0, r1
	lsls r0, r0, #0xe
	lsrs r0, r0, #0x10
	ands r2, r3
	orrs r2, r0
	str r2, [sp, #4]
	adds r0, r6, #0
	mov r1, sp
	bl FUN_08068d18
	cmp r0, #0
	beq _08068FBE
	b _08069140
_08068FBE:
	ldrh r1, [r6, #0x2c]
	lsls r0, r1, #0x10
	asrs r3, r0, #0x18
	ldrh r0, [r6, #0x30]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	adds r4, r1, #0
	cmp r3, #0
	blt _08068FE4
	cmp r2, #0
	blt _08068FE4
	ldr r0, _08068FEC @ =0x030046A8
	ldr r0, [r0]
	cmp r3, r0
	bhs _08068FE4
	ldr r0, _08068FF0 @ =0x030046AC
	ldr r0, [r0]
	cmp r2, r0
	blo _08068FF4
_08068FE4:
	movs r3, #0
	b _08069002
	.align 2, 0
_08068FE8: .4byte 0xFFFF0000
_08068FEC: .4byte 0x030046A8
_08068FF0: .4byte 0x030046AC
_08068FF4:
	ldr r0, _08069030 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r2, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r3, r0, r3
_08069002:
	mov r1, sp
	mov r0, sp
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r1, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _0806902A
	cmp r1, #0
	blt _0806902A
	ldr r0, _08069034 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _0806902A
	ldr r0, _08069038 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0806903C
_0806902A:
	movs r2, #0
	b _0806904A
	.align 2, 0
_08069030: .4byte 0x030046A4
_08069034: .4byte 0x030046A8
_08069038: .4byte 0x030046AC
_0806903C:
	ldr r0, _0806905C @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r2, r0, r2
_0806904A:
	adds r0, r2, #1
	cmp r3, r0
	bne _08069060
	lsls r0, r4, #0x10
	asrs r0, r0, #0x18
	lsls r0, r0, #8
	adds r0, #2
	b _08069070
	.align 2, 0
_0806905C: .4byte 0x030046A4
_08069060:
	subs r0, r2, #1
	cmp r3, r0
	bne _08069076
	lsls r0, r4, #0x10
	asrs r0, r0, #0x18
	adds r0, #1
	lsls r0, r0, #8
	subs r0, #2
_08069070:
	mov r1, sp
	strh r0, [r1]
	b _080690B8
_08069076:
	ldr r0, _08069094 @ =0x030046A4
	ldr r0, [r0]
	ldr r0, [r0, #4]
	movs r7, #4
	ldrsh r1, [r0, r7]
	adds r0, r2, r1
	cmp r3, r0
	bne _08069098
	ldrh r0, [r6, #0x30]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x18
	lsls r0, r0, #8
	adds r0, #2
	b _080690AA
	.align 2, 0
_08069094: .4byte 0x030046A4
_08069098:
	subs r0, r2, r1
	cmp r3, r0
	bne _080690B0
	ldrh r0, [r6, #0x30]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x18
	adds r0, #1
	lsls r0, r0, #8
	subs r0, #2
_080690AA:
	mov r1, sp
	strh r0, [r1, #4]
	b _080690B8
_080690B0:
	mov r0, sp
	strh r4, [r0]
	ldrh r1, [r6, #0x30]
	strh r1, [r0, #4]
_080690B8:
	bl FUN_08086958
	cmp r0, #0
	beq _080690C2
	b _080691D0
_080690C2:
	mov r5, sp
	mov r0, sp
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r5, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _080690EA
	cmp r1, #0
	blt _080690EA
	ldr r0, _080690F0 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _080690EA
	ldr r0, _080690F4 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _080690F8
_080690EA:
	movs r4, #0
	b _08069106
	.align 2, 0
_080690F0: .4byte 0x030046A8
_080690F4: .4byte 0x030046AC
_080690F8:
	ldr r0, _08069118 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_08069106:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _0806911C
	adds r0, #4
	b _08069128
	.align 2, 0
_08069118: .4byte 0x030046A4
_0806911C:
	ldr r0, _0806913C @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08069128:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	bne _080691BA
	ldrb r0, [r5, #4]
	b _080691CA
	.align 2, 0
_0806913C: .4byte 0x030046A4
_08069140:
	bl FUN_08086958
	cmp r0, #0
	bne _080691D0
	mov r5, sp
	mov r0, sp
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r5, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _08069170
	cmp r1, #0
	blt _08069170
	ldr r0, _08069174 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08069170
	ldr r0, _08069178 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0806917C
_08069170:
	movs r4, #0
	b _0806918A
	.align 2, 0
_08069174: .4byte 0x030046A8
_08069178: .4byte 0x030046AC
_0806917C:
	ldr r0, _0806919C @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_0806918A:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _080691A0
	adds r0, #4
	b _080691AC
	.align 2, 0
_0806919C: .4byte 0x030046A4
_080691A0:
	ldr r0, _080691C0 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_080691AC:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _080691C4
_080691BA:
	cmp r2, #2
	beq _080691C8
	b _080691CC
	.align 2, 0
_080691C0: .4byte 0x030046A4
_080691C4:
	ldrb r0, [r5, #4]
	b _080691CA
_080691C8:
	ldrb r0, [r5]
_080691CA:
	subs r1, r1, r0
_080691CC:
	mov r0, sp
	strh r1, [r0, #2]
_080691D0:
	movs r0, #0x2c
	ldrsh r1, [r6, r0]
	mov r0, sp
	movs r2, #0
	ldrsh r0, [r0, r2]
	subs r3, r1, r0
	movs r5, #0x30
	ldrsh r1, [r6, r5]
	mov r0, sp
	movs r7, #4
	ldrsh r0, [r0, r7]
	subs r2, r1, r0
	adds r0, r3, #0
	adds r1, r2, #0
	bl FUN_0823785c
	adds r1, r0, #0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	adds r1, #0x10
	movs r0, #0xff
	ands r1, r0
	asrs r1, r1, #5
	adds r1, #3
	movs r0, #7
	ands r1, r0
	mov r0, sp
	bl FUN_08086590
_0806920A:
	add sp, #8
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
