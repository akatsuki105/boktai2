	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	adds r7, r0, #0
	ldr r0, _081D3710 @ =0x03002BE0
	mov sl, r0
	mov r6, sp
	mov r8, sl
_081D36D6:
	movs r1, #0
	mov sb, r1
	mov r3, r8
	ldr r0, [r3]
	cmp r0, #0
	bne _081D36E4
	b _081D3884
_081D36E4:
	movs r1, #1
	bl FUN_0807a954
	cmp r0, #0
	bne _081D36FE
	mov r4, r8
	ldr r0, [r4]
	movs r1, #2
	bl FUN_0807a954
	cmp r0, #0
	bne _081D36FE
	b _081D388E
_081D36FE:
	movs r1, #8
	adds r0, r7, #0
	adds r0, #0xb4
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _081D3714
	movs r0, #1
	b _081D3716
	.align 2, 0
_081D3710: .4byte 0x03002BE0
_081D3714:
	movs r0, #0
_081D3716:
	cmp r0, #0
	bne _081D371C
	b _081D3884
_081D371C:
	mov r1, r8
	ldr r0, [r1]
	ldrh r1, [r0, #0x2c]
	lsls r1, r1, #0x10
	asrs r2, r1, #0x18
	ldrh r0, [r0, #0x30]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _081D3744
	cmp r1, #0
	blt _081D3744
	ldr r0, _081D3748 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081D3744
	ldr r0, _081D374C @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081D3750
_081D3744:
	movs r4, #0
	b _081D375E
	.align 2, 0
_081D3748: .4byte 0x030046A8
_081D374C: .4byte 0x030046AC
_081D3750:
	ldr r0, _081D3770 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_081D375E:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081D3774
	adds r0, #4
	b _081D3780
	.align 2, 0
_081D3770: .4byte 0x030046A4
_081D3774:
	ldr r0, _081D3818 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081D3780:
	ldrh r0, [r0, #2]
	movs r1, #0x40
	ands r0, r1
	cmp r0, #0
	beq _081D3884
	adds r0, r4, #0
	bl FUN_081d34e8
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081D3884
	mov r5, sp
	adds r2, r7, #0
	adds r2, #0xfc
	mov r3, r8
	ldr r0, [r3]
	adds r3, r0, #0
	adds r3, #0x2c
	ldrh r0, [r0, #0x2c]
	ldrh r1, [r2]
	subs r0, r0, r1
	strh r0, [r6]
	ldrh r1, [r3, #2]
	ldrh r0, [r2, #2]
	subs r4, r1, r0
	strh r4, [r5, #2]
	ldrh r1, [r3, #4]
	ldrh r0, [r2, #4]
	subs r3, r1, r0
	strh r3, [r5, #4]
	adds r0, r7, #0
	adds r0, #0xd6
	ldrh r1, [r0]
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	beq _081D3820
	ldr r2, _081D381C @ =0x085AE0D0
	movs r1, #0
	ldrsh r0, [r6, r1]
	mov ip, r0
	movs r1, #0
	ldrsh r0, [r2, r1]
	cmp ip, r0
	bgt _081D3874
	movs r1, #0
	ldrsh r0, [r2, r1]
	mov r1, ip
	cmn r1, r0
	blt _081D3874
	lsls r0, r4, #0x10
	asrs r0, r0, #0x10
	movs r4, #2
	ldrsh r1, [r2, r4]
	cmp r0, r1
	bgt _081D3874
	movs r0, #2
	ldrsh r1, [r5, r0]
	movs r4, #2
	ldrsh r0, [r2, r4]
	cmn r1, r0
	blt _081D3874
	lsls r0, r3, #0x10
	asrs r0, r0, #0x10
	movs r3, #4
	ldrsh r1, [r2, r3]
	cmp r0, r1
	bgt _081D3874
	movs r4, #4
	ldrsh r1, [r5, r4]
	movs r3, #4
	ldrsh r0, [r2, r3]
	cmn r1, r0
	bge _081D386E
	b _081D3874
	.align 2, 0
_081D3818: .4byte 0x030046A4
_081D381C: .4byte 0x085AE0D0
_081D3820:
	ldr r2, _081D38A0 @ =0x085AE0D8
	movs r1, #0
	ldrsh r0, [r6, r1]
	mov ip, r0
	movs r1, #0
	ldrsh r0, [r2, r1]
	cmp ip, r0
	bgt _081D386A
	movs r1, #0
	ldrsh r0, [r2, r1]
	mov r1, ip
	cmn r1, r0
	blt _081D386A
	lsls r0, r4, #0x10
	asrs r0, r0, #0x10
	movs r4, #2
	ldrsh r1, [r2, r4]
	cmp r0, r1
	bgt _081D386A
	movs r0, #2
	ldrsh r1, [r5, r0]
	movs r4, #2
	ldrsh r0, [r2, r4]
	cmn r1, r0
	blt _081D386A
	lsls r0, r3, #0x10
	asrs r0, r0, #0x10
	movs r3, #4
	ldrsh r1, [r2, r3]
	cmp r0, r1
	bgt _081D386A
	movs r4, #4
	ldrsh r1, [r5, r4]
	movs r3, #4
	ldrsh r0, [r2, r3]
	cmn r1, r0
	bge _081D386E
_081D386A:
	movs r4, #1
	mov sb, r4
_081D386E:
	mov r0, sb
	cmp r0, #0
	beq _081D3884
_081D3874:
	adds r1, r7, #0
	adds r1, #0xc0
	ldrh r0, [r1]
	cmp r0, #0
	beq _081D3884
	movs r1, #0
	bl VM_ExecByID
_081D3884:
	movs r1, #4
	add r8, r1
	cmp r8, sl
	bgt _081D388E
	b _081D36D6
_081D388E:
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081D38A0: .4byte 0x085AE0D8
