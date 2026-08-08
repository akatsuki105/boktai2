	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0xc
	adds r5, r0, #0
	mov ip, r2
	mov r8, r3
	ldr r0, _082467F4 @ =0x030026B0
	ldr r7, [r0]
	cmp r7, #0
	beq _08246808
	cmp r1, #0
	bne _082467F8
	adds r0, r5, #0
	bl FUN_08246790
	b _082469A8
	.align 2, 0
_082467F4: .4byte 0x030026B0
_082467F8:
	ldrb r2, [r5, #2]
	cmp r2, #0
	beq _08246804
	ldrb r0, [r5, #1]
	cmp r0, r1
	bne _08246808
_08246804:
	cmp r2, #3
	bls _0824680E
_08246808:
	movs r0, #1
	rsbs r0, r0, #0
	b _082469AA
_0824680E:
	ldrb r0, [r5, #1]
	cmp r0, r1
	beq _0824686A
	strb r1, [r5, #1]
	ldrb r0, [r5, #1]
	cmp r0, #1
	beq _08246840
	cmp r0, #1
	bgt _08246826
	cmp r0, #0
	beq _08246830
	b _0824686A
_08246826:
	cmp r0, #2
	beq _08246850
	cmp r0, #3
	beq _08246860
	b _0824686A
_08246830:
	movs r0, #0x96
	lsls r0, r0, #1
	adds r1, r5, r0
	ldr r0, _0824683C @ =FUN_0824666c
	b _08246868
	.align 2, 0
_0824683C: .4byte FUN_0824666c
_08246840:
	movs r2, #0x96
	lsls r2, r2, #1
	adds r1, r5, r2
	ldr r0, _0824684C @ =FUN_082470a8
	b _08246868
	.align 2, 0
_0824684C: .4byte FUN_082470a8
_08246850:
	movs r0, #0x96
	lsls r0, r0, #1
	adds r1, r5, r0
	ldr r0, _0824685C @ =FUN_08247194
	b _08246868
	.align 2, 0
_0824685C: .4byte FUN_08247194
_08246860:
	movs r2, #0x96
	lsls r2, r2, #1
	adds r1, r5, r2
	ldr r0, _08246890 @ =FUN_08247280
_08246868:
	str r0, [r1]
_0824686A:
	movs r0, #0
	mov sb, r0
	add r6, sp, #4
	ldr r2, [r5, #8]
	ldrh r0, [r2]
	lsls r0, r0, #0x10
	asrs r4, r0, #0x11
	ldrh r0, [r2, #4]
	lsls r0, r0, #0x10
	asrs r3, r0, #0x11
	subs r1, r4, r3
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	cmp r0, #0
	blt _08246894
	asrs r0, r0, #8
	b _0824689A
	.align 2, 0
_08246890: .4byte FUN_08247280
_08246894:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_0824689A:
	strh r0, [r6]
	adds r1, r4, r3
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	cmp r0, #0
	blt _082468AC
	asrs r0, r0, #8
	b _082468B2
_082468AC:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_082468B2:
	adds r4, r0, #0
	movs r0, #2
	ldrsh r1, [r2, r0]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	cmp r0, #0
	blt _08246924
	asrs r0, r0, #8
	b _0824692A
_082468C6:
	movs r0, #1
	strb r0, [r4]
	strh r6, [r4, #2]
	mov r2, ip
	strh r2, [r4, #4]
	mov r2, r8
	ldr r0, [r2]
	ldr r1, [r2, #4]
	str r0, [r4, #8]
	str r1, [r4, #0xc]
	add r1, sp, #4
	ldrh r0, [r4, #8]
	ldrh r1, [r1]
	adds r0, r0, r1
	strh r0, [r4, #0x28]
	add r2, sp, #4
	ldrh r0, [r2, #2]
	ldrh r1, [r4, #0xa]
	adds r0, r0, r1
	strh r0, [r4, #0x2a]
	ldrh r0, [r4, #0xc]
	ldrh r2, [r2, #4]
	adds r0, r0, r2
	strh r0, [r4, #0x2c]
	ldr r0, [r4, #0x10]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r4, #0x10]
	adds r0, r4, #0
	adds r0, #0x38
	ldr r1, [r7, #0x1c]
	ldr r3, _08246920 @ =0x08DBD810
	ldrb r2, [r5, #1]
	lsls r2, r2, #1
	adds r2, r2, r3
	ldrh r2, [r2]
	str r6, [sp]
	movs r3, #0
	bl FUN_08236fac
	movs r0, #1
	mov sb, r0
	b _0824695C
	.align 2, 0
_08246920: .4byte 0x08DBD810
_08246924:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_0824692A:
	subs r2, r4, r0
	adds r4, r4, r0
	ldr r3, _0824697C @ =0x030047C8
	ldrh r0, [r6]
	ldrh r1, [r3]
	subs r0, r0, r1
	adds r0, #0x78
	strh r0, [r6]
	ldrh r0, [r3, #2]
	subs r2, r2, r0
	adds r2, #0x5a
	strh r2, [r6, #2]
	ldrh r0, [r3, #4]
	subs r4, r4, r0
	strh r4, [r6, #4]
	movs r2, #0
	adds r4, r5, #0
	adds r4, #0xc
_0824694E:
	ldrb r6, [r4]
	cmp r6, #0
	beq _082468C6
	adds r4, #0x48
	adds r2, #1
	cmp r2, #3
	ble _0824694E
_0824695C:
	ldrb r0, [r5, #1]
	cmp r0, #2
	bne _08246980
	movs r3, #0x80
	lsls r3, r3, #2
	adds r1, r5, #0
	adds r1, #0x1c
	movs r2, #3
_0824696C:
	ldr r0, [r1]
	orrs r0, r3
	str r0, [r1]
	adds r1, #0x48
	subs r2, #1
	cmp r2, #0
	bge _0824696C
	b _08246996
	.align 2, 0
_0824697C: .4byte 0x030047C8
_08246980:
	ldr r3, _082469B8 @ =0xFFFFFDFF
	adds r1, r5, #0
	adds r1, #0x1c
	movs r2, #3
_08246988:
	ldr r0, [r1]
	ands r0, r3
	str r0, [r1]
	adds r1, #0x48
	subs r2, #1
	cmp r2, #0
	bge _08246988
_08246996:
	mov r2, sb
	cmp r2, #0
	beq _082469A8
	ldrb r0, [r5, #2]
	adds r0, #1
	strb r0, [r5, #2]
	ldrb r0, [r5, #3]
	adds r0, #1
	strb r0, [r5, #3]
_082469A8:
	movs r0, #0
_082469AA:
	add sp, #0xc
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_082469B8: .4byte 0xFFFFFDFF
