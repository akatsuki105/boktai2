	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	adds r5, r0, #0
	movs r0, #0xed
	lsls r0, r0, #1
	adds r1, r5, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x1d
	bls _080A8870
	adds r4, r5, #0
	adds r4, #0x6c
	movs r1, #0xd0
	lsls r1, r1, #1
	adds r6, r5, r1
_080A8848:
	ldr r0, [r4]
	movs r1, #1
	orrs r0, r1
	str r0, [r4]
	adds r0, r5, #0
	ldr r1, _080A886C @ =FUN_080a8950
	bl Entity080a8ff8_SetState
	adds r4, #0x2c
	cmp r4, r6
	ble _080A8848
	ldr r0, [r5, #0x1c]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r5, #0x1c]
	b _080A8940
	.align 2, 0
_080A886C: .4byte FUN_080a8950
_080A8870:
	ldrh r1, [r1]
	movs r0, #0x20
	subs r6, r0, r1
	adds r2, r6, #1
	str r2, [sp]
	adds r0, r5, #0
	adds r0, #0x64
	str r0, [sp, #4]
	movs r1, #0x66
	adds r1, r1, r5
	mov sl, r1
	movs r2, #0x68
	adds r2, r2, r5
	mov sb, r2
	ldr r0, _080A88C8 @ =0x085B0A08
	mov r8, r0
	adds r4, r5, #0
	adds r4, #0x6c
	movs r7, #7
_080A8896:
	ldrh r0, [r4, #0x28]
	adds r0, #4
	movs r1, #0xff
	ands r0, r1
	strh r0, [r4, #0x28]
	ldrh r0, [r4, #0x2a]
	muls r0, r6, r0
	ldr r1, [sp]
	bl Div
	strh r0, [r4, #0x2a]
	ldrh r2, [r4, #0x2a]
	ldrh r0, [r4, #0x28]
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	add r0, r8
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r2, r0
	cmp r0, #0
	blt _080A88CC
	asrs r2, r0, #0xc
	b _080A88D2
	.align 2, 0
_080A88C8: .4byte 0x085B0A08
_080A88CC:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_080A88D2:
	ldr r1, [sp, #4]
	ldrh r0, [r1]
	adds r0, r0, r2
	strh r0, [r4, #0x18]
	movs r2, #0xed
	lsls r2, r2, #1
	adds r0, r5, r2
	ldrh r0, [r0]
	movs r1, #0x1e
	subs r1, r1, r0
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #1
	mov r1, sl
	ldrh r1, [r1]
	adds r0, r0, r1
	strh r0, [r4, #0x1a]
	ldrh r2, [r4, #0x2a]
	ldrh r1, [r4, #0x28]
	movs r0, #0xff
	ands r0, r1
	lsls r0, r0, #1
	add r0, r8
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r2, r0
	cmp r0, #0
	blt _080A890E
	asrs r2, r0, #0xc
	b _080A8914
_080A890E:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_080A8914:
	mov r1, sb
	ldrh r0, [r1]
	adds r0, r0, r2
	strh r0, [r4, #0x1c]
	movs r2, #0xed
	lsls r2, r2, #1
	adds r0, r5, r2
	ldrh r0, [r0]
	cmp r0, #8
	bne _080A8938
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r1, [r0]
	adds r0, r4, #0
	movs r2, #6
	bl FUN_0822dafc
_080A8938:
	adds r4, #0x2c
	subs r7, #1
	cmp r7, #0
	bge _080A8896
_080A8940:
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
