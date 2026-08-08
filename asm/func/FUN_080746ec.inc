	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	adds r6, r0, #0
	ldr r0, _08074770 @ =0x0000037E
	adds r0, r0, r6
	mov sb, r0
	ldrh r0, [r0]
	cmp r0, #0
	bne _0807470C
	movs r0, #0xa6
	lsls r0, r0, #2
	bl PlaySound_082406e0
_0807470C:
	ldr r1, _08074774 @ =0x0000049C
	adds r1, r1, r6
	mov r8, r1
	movs r2, #0
	ldrsh r5, [r1, r2]
	movs r3, #0x2c
	ldrsh r0, [r6, r3]
	subs r5, r5, r0
	movs r0, #0x94
	lsls r0, r0, #3
	adds r7, r6, r0
	movs r1, #0
	ldrsh r4, [r7, r1]
	movs r2, #0x30
	ldrsh r0, [r6, r2]
	subs r4, r4, r0
	adds r0, r5, #0
	adds r1, r4, #0
	bl FUN_0823785c
	mov sl, r0
	adds r1, r5, #0
	muls r1, r5, r1
	adds r0, r4, #0
	muls r0, r4, r0
	adds r4, r1, r0
	movs r0, #0x80
	lsls r0, r0, #3
	cmp r4, r0
	bgt _080747F8
	mov r3, r8
	ldrh r0, [r3]
	strh r0, [r6, #0x2c]
	ldrh r0, [r7]
	strh r0, [r6, #0x30]
	ldr r0, _08074778 @ =0x000004A9
	adds r1, r6, r0
	ldrb r2, [r1]
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r0, #0
	blt _0807477C
	movs r3, #0xba
	lsls r3, r3, #2
	adds r0, r6, r3
	strb r2, [r0]
	movs r0, #0xff
	strb r0, [r1]
	b _08074798
	.align 2, 0
_08074770: .4byte 0x0000037E
_08074774: .4byte 0x0000049C
_08074778: .4byte 0x000004A9
_0807477C:
	mov r1, sl
	lsls r0, r1, #0x10
	lsrs r0, r0, #0x10
	adds r0, #0x10
	movs r1, #0xff
	ands r0, r1
	asrs r0, r0, #5
	adds r0, #3
	movs r1, #7
	ands r1, r0
	movs r2, #0xba
	lsls r2, r2, #2
	adds r0, r6, r2
	strb r1, [r0]
_08074798:
	movs r3, #0xba
	lsls r3, r3, #2
	adds r0, r6, r3
	ldrb r2, [r0]
	cmp r2, #4
	bls _080747BC
	movs r0, #8
	subs r0, r0, r2
	ldr r2, _080747B8 @ =0x000002E6
	adds r1, r6, r2
	strb r0, [r1]
	subs r3, #1
	adds r1, r6, r3
	movs r0, #1
	strb r0, [r1]
	b _080747CA
	.align 2, 0
_080747B8: .4byte 0x000002E6
_080747BC:
	ldr r1, _080747F0 @ =0x000002E6
	adds r0, r6, r1
	movs r1, #0
	strb r2, [r0]
	ldr r2, _080747F4 @ =0x000002E7
	adds r0, r6, r2
	strb r1, [r0]
_080747CA:
	movs r3, #0xd6
	lsls r3, r3, #2
	adds r0, r6, r3
	ldrb r0, [r0]
	movs r1, #0
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r6, #0
	movs r2, #0x40
	bl FUN_08060a24
	adds r0, r6, #0
	bl FUN_08072620
	adds r0, r6, #0
	bl FUN_080726b4
	b _0807497E
	.align 2, 0
_080747F0: .4byte 0x000002E6
_080747F4: .4byte 0x000002E7
_080747F8:
	adds r0, r6, #0
	movs r1, #4
	bl FUN_08060c40
	mov r1, sb
	ldrh r0, [r1]
	cmp r0, #3
	bhi _08074824
	ldr r2, _0807481C @ =0x0000095E
	adds r1, r6, r2
	ldr r0, _08074820 @ =0x00000127
	strh r0, [r1]
	movs r3, #0x96
	lsls r3, r3, #4
	adds r1, r6, r3
	movs r0, #0x18
	strh r0, [r1]
	b _0807482C
	.align 2, 0
_0807481C: .4byte 0x0000095E
_08074820: .4byte 0x00000127
_08074824:
	movs r0, #0x80
	lsls r0, r0, #7
	cmp r4, r0
	bgt _08074836
_0807482C:
	adds r0, r6, #0
	movs r1, #2
	bl FUN_08060c40
	b _08074850
_08074836:
	ldr r0, _08074878 @ =0x0000095E
	adds r1, r6, r0
	ldr r0, _0807487C @ =0x00000127
	strh r0, [r1]
	movs r2, #0x96
	lsls r2, r2, #4
	adds r1, r6, r2
	movs r0, #0x18
	strh r0, [r1]
	adds r0, r6, #0
	movs r1, #1
	bl FUN_08060c40
_08074850:
	ldr r3, _08074880 @ =0x0000037E
	adds r1, r6, r3
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	ldr r2, _08074884 @ =0x085B0A08
	mov r0, sl
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	movs r3, #0x20
	muls r0, r3, r0
	cmp r0, #0
	blt _08074888
	asrs r0, r0, #0xc
	b _0807488E
	.align 2, 0
_08074878: .4byte 0x0000095E
_0807487C: .4byte 0x00000127
_08074880: .4byte 0x0000037E
_08074884: .4byte 0x085B0A08
_08074888:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0807488E:
	strh r0, [r6, #0x34]
	movs r0, #0xff
	mov r1, sl
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	movs r3, #0x20
	muls r0, r3, r0
	cmp r0, #0
	blt _080748AA
	asrs r0, r0, #0xc
	b _080748B0
_080748AA:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080748B0:
	strh r0, [r6, #0x38]
	ldr r2, _080748D0 @ =0x000001C7
	adds r1, r6, r2
	ldrb r1, [r1]
	cmp r1, #1
	bne _080748EE
	cmp r0, #0
	bge _080748D4
	movs r3, #0x38
	ldrsh r1, [r6, r3]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #3
	cmp r0, #0
	bge _080748E0
	b _080748E4
	.align 2, 0
_080748D0: .4byte 0x000001C7
_080748D4:
	movs r0, #0x38
	ldrsh r1, [r6, r0]
	movs r0, #0x34
	muls r0, r1, r0
	cmp r0, #0
	blt _080748E4
_080748E0:
	asrs r0, r0, #6
	b _080748EA
_080748E4:
	rsbs r0, r0, #0
	asrs r0, r0, #6
	rsbs r0, r0, #0
_080748EA:
	strh r0, [r6, #0x38]
	b _08074920
_080748EE:
	cmp r1, #2
	bne _08074920
	movs r1, #0x34
	ldrsh r0, [r6, r1]
	cmp r0, #0
	bge _08074908
	adds r1, r0, #0
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #3
	cmp r0, #0
	bge _08074914
	b _08074918
_08074908:
	movs r3, #0x34
	ldrsh r1, [r6, r3]
	movs r0, #0x34
	muls r0, r1, r0
	cmp r0, #0
	blt _08074918
_08074914:
	asrs r0, r0, #6
	b _0807491E
_08074918:
	rsbs r0, r0, #0
	asrs r0, r0, #6
	rsbs r0, r0, #0
_0807491E:
	strh r0, [r6, #0x34]
_08074920:
	mov r0, sl
	adds r0, #0x10
	movs r1, #0xff
	ands r0, r1
	asrs r0, r0, #5
	adds r1, r0, #3
	movs r0, #7
	ands r1, r0
	movs r2, #0xba
	lsls r2, r2, #2
	adds r0, r6, r2
	strb r1, [r0]
	cmp r1, #4
	bls _08074958
	movs r0, #8
	subs r0, r0, r1
	ldr r3, _08074950 @ =0x000002E6
	adds r1, r6, r3
	strb r0, [r1]
	ldr r0, _08074954 @ =0x000002E7
	adds r1, r6, r0
	movs r0, #1
	b _08074964
	.align 2, 0
_08074950: .4byte 0x000002E6
_08074954: .4byte 0x000002E7
_08074958:
	ldr r2, _0807498C @ =0x000002E6
	adds r0, r6, r2
	strb r1, [r0]
	ldr r3, _08074990 @ =0x000002E7
	adds r1, r6, r3
	movs r0, #0
_08074964:
	strb r0, [r1]
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r6, r1
	ldrb r0, [r0]
	movs r1, #1
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r6, #0
	movs r2, #0x20
	bl FUN_08060a24
_0807497E:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0807498C: .4byte 0x000002E6
_08074990: .4byte 0x000002E7
