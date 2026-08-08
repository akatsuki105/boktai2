	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r5, r0, #0
	movs r1, #0x80
	lsls r1, r1, #1
	movs r0, #0xc0
	lsls r0, r0, #1
	adds r6, r5, r0
	ldrh r0, [r6]
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	cmp r4, #0
	beq _080FF7E0
	b _080FFA30
_080FF7E0:
	movs r1, #3
	movs r2, #1
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r0, r5, r3
	strb r1, [r0]
	ldr r7, _080FF8A8 @ =0x00000469
	adds r0, r5, r7
	strb r2, [r0]
	ldr r1, _080FF8AC @ =0x0000046A
	adds r0, r5, r1
	strb r4, [r0]
	adds r3, #0x1c
	adds r0, r5, r3
	str r4, [r0]
	adds r7, #3
	adds r0, r5, r7
	strb r2, [r0]
	ldr r3, _080FF8B0 @ =0x080E6795
	movs r1, #0xe
	adds r7, #1
	adds r0, r5, r7
	strb r2, [r0]
	ldr r2, _080FF8B4 @ =0x0000046B
	adds r0, r5, r2
	strb r4, [r0]
	adds r7, #0xe6
	adds r0, r5, r7
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r5, r1
	str r3, [r0]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r0, r5, r2
	movs r7, #0
	strh r4, [r0]
	movs r3, #0x80
	mov ip, r3
	ldrh r0, [r6]
	ands r0, r3
	cmp r0, #0
	beq _080FF8CC
	ldr r4, _080FF8B8 @ =0x00000482
	adds r1, r5, r4
	movs r0, #2
	strh r0, [r1]
	movs r1, #0xb7
	lsls r1, r1, #3
	adds r0, r5, r1
	ldr r3, [r0]
	movs r2, #0xc
	mov r8, r2
	movs r1, #0x1e
	adds r4, #0xd6
	adds r2, r5, r4
	subs r4, #4
	adds r0, r5, r4
	str r1, [r0]
	str r3, [r2]
	movs r1, #0xaa
	lsls r1, r1, #3
	adds r0, r5, r1
	strb r7, [r0]
	ldr r2, _080FF8BC @ =0x00000551
	adds r0, r5, r2
	strb r7, [r0]
	ldr r3, _080FF8C0 @ =0x00000552
	adds r0, r5, r3
	mov r4, r8
	strb r4, [r0]
	movs r0, #4
	ldr r7, _080FF8C4 @ =0x00000222
	adds r2, r5, r7
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
	ldrh r0, [r6]
	mov r1, ip
	ands r0, r1
	cmp r0, #0
	beq _080FF910
	ldr r3, _080FF8C8 @ =0x0000024E
	adds r2, r5, r3
	movs r4, #0x96
	lsls r4, r4, #1
	adds r0, r4, #0
	ldrh r6, [r2]
	adds r0, r0, r6
	strh r0, [r2]
	adds r7, #0x2a
	adds r1, r5, r7
	ldrh r1, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, r1
	bls _080FF910
	strh r1, [r2]
	b _080FF910
	.align 2, 0
_080FF8A8: .4byte 0x00000469
_080FF8AC: .4byte 0x0000046A
_080FF8B0: .4byte 0x080E6795
_080FF8B4: .4byte 0x0000046B
_080FF8B8: .4byte 0x00000482
_080FF8BC: .4byte 0x00000551
_080FF8C0: .4byte 0x00000552
_080FF8C4: .4byte 0x00000222
_080FF8C8: .4byte 0x0000024E
_080FF8CC:
	movs r2, #0x10
	movs r0, #0xbc
	lsls r0, r0, #1
	adds r1, r5, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	ldr r2, _080FF94C @ =0x00000482
	adds r1, r5, r2
	movs r0, #2
	strh r0, [r1]
	movs r3, #0xb4
	lsls r3, r3, #3
	adds r0, r5, r3
	ldr r3, [r0]
	movs r4, #7
	movs r1, #0x3c
	movs r6, #0xab
	lsls r6, r6, #3
	adds r2, r5, r6
	subs r6, #4
	adds r0, r5, r6
	str r1, [r0]
	str r3, [r2]
	movs r1, #0xaa
	lsls r1, r1, #3
	adds r0, r5, r1
	strb r7, [r0]
	ldr r2, _080FF950 @ =0x00000551
	adds r0, r5, r2
	strb r7, [r0]
	ldr r3, _080FF954 @ =0x00000552
	adds r0, r5, r3
	strb r4, [r0]
_080FF910:
	movs r4, #0x95
	lsls r4, r4, #3
	adds r0, r5, r4
	ldr r6, [r0]
	adds r2, r5, #0
	adds r2, #0x9c
	ldr r0, [r2, #8]
	ldrh r1, [r0]
	strh r1, [r6]
	ldr r0, [r2, #8]
	ldrh r0, [r0, #2]
	strh r0, [r6, #4]
	lsls r1, r1, #0x10
	asrs r2, r1, #0x18
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _080FF948
	cmp r1, #0
	blt _080FF948
	ldr r0, _080FF958 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _080FF948
	ldr r0, _080FF95C @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _080FF960
_080FF948:
	movs r4, #0
	b _080FF96E
	.align 2, 0
_080FF94C: .4byte 0x00000482
_080FF950: .4byte 0x00000551
_080FF954: .4byte 0x00000552
_080FF958: .4byte 0x030046A8
_080FF95C: .4byte 0x030046AC
_080FF960:
	ldr r0, _080FF980 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_080FF96E:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _080FF984
	adds r0, #4
	b _080FF990
	.align 2, 0
_080FF980: .4byte 0x030046A4
_080FF984:
	ldr r0, _080FF9A4 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_080FF990:
	ldrb r1, [r0]
	lsrs r3, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r2, r0, #8
	cmp r3, #1
	beq _080FF9A8
	cmp r3, #2
	beq _080FF9AC
	b _080FF9B0
	.align 2, 0
_080FF9A4: .4byte 0x030046A4
_080FF9A8:
	ldrb r0, [r6, #4]
	b _080FF9AE
_080FF9AC:
	ldrb r0, [r6]
_080FF9AE:
	subs r2, r2, r0
_080FF9B0:
	movs r1, #0
	strh r2, [r6, #2]
	movs r6, #0x95
	lsls r6, r6, #3
	adds r0, r5, r6
	ldr r0, [r0]
	strh r1, [r0, #6]
	ldr r7, _080FF9EC @ =0x000004A4
	adds r0, r5, r7
	ldr r6, [r0]
	adds r7, r5, #0
	adds r7, #8
	movs r1, #0xec
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r0, [r0]
	adds r4, r0, #0
	adds r4, #8
	adds r0, r6, #0
	adds r1, r7, #0
	adds r2, r4, #0
	bl FUN_0823599c
	cmp r0, #0
	bne _080FF9F0
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r0, r5, r2
	b _080FFA16
	.align 2, 0
_080FF9EC: .4byte 0x000004A4
_080FF9F0:
	adds r0, r6, #0
	adds r1, r7, #0
	adds r2, r4, #0
	bl FUN_08235f40
	cmp r0, #0
	beq _080FFA10
	cmp r0, #2
	beq _080FFA0C
	adds r0, r5, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_080FFA0C:
	movs r0, #1
	b _080FFA20
_080FFA10:
	movs r3, #0xc0
	lsls r3, r3, #1
	adds r0, r5, r3
_080FFA16:
	ldr r1, _080FFA3C @ =0xFFFFFDFF
	ldrh r2, [r0]
	ands r1, r2
	strh r1, [r0]
	movs r0, #0
_080FFA20:
	cmp r0, #0
	bne _080FFA30
	ldr r4, _080FFA40 @ =0x000005C4
	adds r0, r5, r4
	ldr r1, [r0]
	adds r0, r5, #0
	bl _call_via_r1
_080FFA30:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080FFA3C: .4byte 0xFFFFFDFF
_080FFA40: .4byte 0x000005C4
