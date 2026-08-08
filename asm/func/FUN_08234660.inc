	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	mov r8, r0
	movs r0, #0
	str r0, [sp]
	ldr r1, _082346D4 @ =0x0300077C
	movs r0, #1
	str r0, [r1]
	mov r0, r8
	ldrb r5, [r0, #3]
	movs r2, #0
	ldr r1, _082346D8 @ =0x030046A4
	ldr r0, [r1]
	ldrh r0, [r0]
	cmp r2, r0
	blt _0823468A
	b _08234848
_0823468A:
	ldr r3, _082346DC @ =0x00001516
	mov sl, r3
_0823468E:
	movs r0, #0x2c
	muls r0, r2, r0
	movs r7, #0x89
	lsls r7, r7, #2
	adds r0, r0, r7
	ldr r1, [r1]
	adds r1, r1, r0
	mov ip, r1
	ldrh r0, [r1, #6]
	mov r1, r8
	ldrh r1, [r1]
	cmp r0, r1
	beq _082346B4
	adds r3, r2, #1
	mov sb, r3
	ldr r7, _082346E0 @ =0x000014C9
	cmp r0, r7
	beq _082346B4
	b _0823483A
_082346B4:
	mov r0, ip
	ldrh r1, [r0, #0xc]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _082346E8
	ldr r0, _082346E4 @ =0x030044E0
	ldrh r1, [r0, #2]
	mov r3, ip
	ldr r0, [r3, #0x20]
	ands r1, r0
	rsbs r0, r1, #0
	orrs r0, r1
	lsrs r0, r0, #0x1f
	b _082346EA
	.align 2, 0
_082346D4: .4byte 0x0300077C
_082346D8: .4byte 0x030046A4
_082346DC: .4byte 0x00001516
_082346E0: .4byte 0x000014C9
_082346E4: .4byte 0x030044E0
_082346E8:
	movs r0, #1
_082346EA:
	adds r2, #1
	mov sb, r2
	cmp r0, #0
	beq _082347C4
	mov r7, r8
	ldr r7, [r7, #4]
	str r7, [sp, #4]
	mov r0, ip
	ldr r2, [r0, #0x28]
	movs r4, #0
	ldrh r6, [r0, #0xe]
	cmp r4, r6
	bge _082347C4
	movs r1, #0
	ldrsh r3, [r7, r1]
_08234708:
	movs r7, #0
	ldrsh r0, [r2, r7]
	cmp r3, r0
	blt _0823472E
	movs r1, #4
	ldrsh r0, [r2, r1]
	cmp r3, r0
	bge _0823472E
	ldr r7, [sp, #4]
	movs r0, #4
	ldrsh r1, [r7, r0]
	movs r7, #2
	ldrsh r0, [r2, r7]
	cmp r1, r0
	blt _0823472E
	movs r7, #6
	ldrsh r0, [r2, r7]
	cmp r1, r0
	blt _08234738
_0823472E:
	adds r2, #0xc
	adds r4, #1
	cmp r4, r6
	blt _08234708
	b _082347C4
_08234738:
	mov r7, r8
	adds r7, #8
	mov r6, sp
	movs r2, #0
	mov r0, ip
	ldr r4, [r0]
	cmp r2, r5
	bge _0823476C
	adds r3, r4, #0
	adds r1, r7, #0
_0823474C:
	ldr r0, [r1]
	cmp r0, r3
	bne _08234764
	str r2, [r6]
	mov r3, ip
	ldrh r1, [r3, #4]
	ldr r0, _08234760 @ =0x0000A5BF
	cmp r1, r0
	beq _082347AE
	b _082347A4
	.align 2, 0
_08234760: .4byte 0x0000A5BF
_08234764:
	adds r1, #4
	adds r2, #1
	cmp r2, r5
	blt _0823474C
_0823476C:
	lsls r0, r5, #2
	adds r0, r0, r7
	str r4, [r0]
	str r5, [r6]
	mov r7, ip
	ldrh r1, [r7, #4]
	ldr r0, _0823479C @ =0x00000DD2
	cmp r1, r0
	beq _0823478E
	ldr r0, _082347A0 @ =0x000014C9
	cmp r1, r0
	beq _0823478E
	cmp r1, sl
	beq _0823478E
	adds r0, #0x4e
	cmp r1, r0
	bne _08234798
_0823478E:
	mov r0, r8
	mov r1, ip
	ldr r2, _0823479C @ =0x00000DD2
	bl FUN_08234868
_08234798:
	adds r5, #1
	b _0823483A
	.align 2, 0
_0823479C: .4byte 0x00000DD2
_082347A0: .4byte 0x000014C9
_082347A4:
	cmp r1, sl
	beq _082347AE
	ldr r0, _082347BC @ =0x00001517
	cmp r1, r0
	bne _0823483A
_082347AE:
	mov r0, r8
	mov r1, ip
	ldr r2, _082347C0 @ =0x0000A5BF
	bl FUN_08234868
	b _0823483A
	.align 2, 0
_082347BC: .4byte 0x00001517
_082347C0: .4byte 0x0000A5BF
_082347C4:
	mov r4, sp
	movs r2, #0
	cmp r2, r5
	bge _08234814
	mov r3, r8
	adds r3, #8
	adds r6, r3, #0
_082347D2:
	ldr r1, [r3]
	mov r7, ip
	ldr r0, [r7]
	cmp r1, r0
	bne _0823480C
	str r2, [r4]
	cmp r2, r5
	bge _08234808
	subs r4, r5, #1
	adds r3, r6, #0
	movs r6, #0
_082347E8:
	cmp r2, r4
	bge _082347FC
	lsls r1, r2, #2
	adds r1, r3, r1
	adds r2, #1
	lsls r0, r2, #2
	adds r0, r3, r0
	ldr r0, [r0]
	str r0, [r1]
	b _08234804
_082347FC:
	lsls r0, r2, #2
	adds r0, r3, r0
	str r6, [r0]
	adds r2, #1
_08234804:
	cmp r2, r5
	blt _082347E8
_08234808:
	movs r0, #1
	b _08234816
_0823480C:
	adds r3, #4
	adds r2, #1
	cmp r2, r5
	blt _082347D2
_08234814:
	movs r0, #0
_08234816:
	cmp r0, #1
	bne _0823483A
	subs r5, #1
	mov r0, ip
	ldrh r1, [r0, #4]
	ldr r0, _0823485C @ =0x0000D5CC
	cmp r1, r0
	beq _08234830
	ldr r3, _08234860 @ =0x000014C9
	cmp r1, r3
	beq _08234830
	cmp r1, sl
	bne _0823483A
_08234830:
	mov r0, r8
	mov r1, ip
	ldr r2, _0823485C @ =0x0000D5CC
	bl FUN_08234868
_0823483A:
	mov r2, sb
	ldr r1, _08234864 @ =0x030046A4
	ldr r0, [r1]
	ldrh r0, [r0]
	cmp r2, r0
	bge _08234848
	b _0823468E
_08234848:
	mov r7, r8
	strb r5, [r7, #3]
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0823485C: .4byte 0x0000D5CC
_08234860: .4byte 0x000014C9
_08234864: .4byte 0x030046A4
