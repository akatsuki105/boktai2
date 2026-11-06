	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x10
	adds r7, r0, #0
	add r4, sp, #4
	movs r5, #0
	str r5, [sp]
	mov r0, sp
	adds r1, r4, #0
	ldr r2, _081F6650 @ =0x05000002
	bl CpuSet
	movs r1, #0xdd
	lsls r1, r1, #3
	adds r0, r7, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	mov r8, r4
	cmp r0, #5
	bgt _081F668C
	subs r1, #0xe
	adds r0, r7, r1
	ldrb r0, [r0]
	adds r3, r0, #0
	adds r3, #0x80
	movs r1, #0xff
	mov r5, r8
	ands r3, r1
	ldr r2, _081F6654 @ =gSineTable
	adds r0, r3, #0
	adds r0, #0x40
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	lsls r0, r0, #6
	mov sl, r2
	cmp r0, #0
	blt _081F6658
	asrs r1, r0, #0xc
	b _081F665E
	.align 2, 0
_081F6650: .4byte 0x05000002
_081F6654: .4byte gSineTable
_081F6658:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_081F665E:
	movs r0, #0
	strh r1, [r5]
	strh r0, [r5, #2]
	lsls r0, r3, #1
	add r0, sl
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r0, #0x40
	muls r0, r1, r0
	cmp r0, #0
	blt _081F6678
	asrs r0, r0, #0xc
	b _081F667E
_081F6678:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_081F667E:
	strh r0, [r5, #4]
	movs r0, #0x20
	mov r2, r8
	strh r0, [r2, #2]
	adds r0, r7, #0
	mov r1, r8
	b _081F67CA
_081F668C:
	cmp r0, #0xb
	bgt _081F6698
	ldr r0, _081F6694 @ =0x0000FFE8
	b _081F67C4
	.align 2, 0
_081F6694: .4byte 0x0000FFE8
_081F6698:
	cmp r0, #0x15
	bgt _081F66AC
	ldr r0, _081F66A8 @ =0x0000FFF8
	mov r2, r8
	strh r0, [r2, #2]
	adds r0, r7, #0
	mov r1, r8
	b _081F67CA
	.align 2, 0
_081F66A8: .4byte 0x0000FFF8
_081F66AC:
	cmp r0, #0x1d
	bgt _081F670A
	ldr r1, _081F66D8 @ =0x000006DA
	adds r0, r7, r1
	mov r4, r8
	ldrb r3, [r0]
	movs r5, #0xc
	ldr r2, _081F66DC @ =gSineTable
	adds r0, r3, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r5, r0
	mov sl, r2
	cmp r0, #0
	blt _081F66E0
	asrs r1, r0, #0xc
	b _081F66E6
	.align 2, 0
_081F66D8: .4byte 0x000006DA
_081F66DC: .4byte gSineTable
_081F66E0:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_081F66E6:
	movs r0, #0
	strh r1, [r4]
	strh r0, [r4, #2]
	lsls r0, r3, #1
	add r0, sl
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r5, r0
	cmp r0, #0
	blt _081F66FE
	asrs r0, r0, #0xc
	b _081F6704
_081F66FE:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_081F6704:
	strh r0, [r4, #4]
	movs r0, #0x2a
	b _081F67C4
_081F670A:
	cmp r0, #0x27
	bgt _081F6768
	ldr r2, _081F6734 @ =0x000006DA
	adds r0, r7, r2
	mov r4, r8
	ldrb r3, [r0]
	ldr r2, _081F6738 @ =gSineTable
	adds r0, r3, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	lsls r0, r0, #5
	mov sl, r2
	cmp r0, #0
	blt _081F673C
	asrs r1, r0, #0xc
	b _081F6742
	.align 2, 0
_081F6734: .4byte 0x000006DA
_081F6738: .4byte gSineTable
_081F673C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_081F6742:
	movs r0, #0
	strh r1, [r4]
	strh r0, [r4, #2]
	lsls r0, r3, #1
	add r0, sl
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r0, #0x20
	muls r0, r1, r0
	cmp r0, #0
	blt _081F675C
	asrs r0, r0, #0xc
	b _081F6762
_081F675C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_081F6762:
	strh r0, [r4, #4]
	movs r0, #0xc
	b _081F67C4
_081F6768:
	cmp r0, #0x35
	bgt _081F67D8
	ldr r2, _081F6794 @ =0x000006DA
	adds r0, r7, r2
	mov r4, r8
	ldrb r3, [r0]
	movs r5, #0x30
	ldr r2, _081F6798 @ =gSineTable
	adds r0, r3, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r5, r0
	mov sl, r2
	cmp r0, #0
	blt _081F679C
	asrs r1, r0, #0xc
	b _081F67A2
	.align 2, 0
_081F6794: .4byte 0x000006DA
_081F6798: .4byte gSineTable
_081F679C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_081F67A2:
	movs r0, #0
	strh r1, [r4]
	strh r0, [r4, #2]
	lsls r0, r3, #1
	add r0, sl
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r5, r0
	cmp r0, #0
	blt _081F67BA
	asrs r0, r0, #0xc
	b _081F67C0
_081F67BA:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_081F67C0:
	strh r0, [r4, #4]
	ldr r0, _081F67D4 @ =0x0000FFE0
_081F67C4:
	mov r1, r8
	strh r0, [r1, #2]
	adds r0, r7, #0
_081F67CA:
	movs r2, #5
	bl Entity081f73ec_SetSegVel
	b _081F6892
	.align 2, 0
_081F67D4: .4byte 0x0000FFE0
_081F67D8:
	movs r2, #0xdb
	lsls r2, r2, #3
	adds r0, r7, r2
	strb r5, [r0]
	movs r5, #1
	mov r6, r8
	movs r0, #0xff
	mov sb, r0
	ldr r1, _081F6818 @ =gSineTable
	mov sl, r1
	movs r2, #0x88
	lsls r2, r2, #2
	adds r4, r7, r2
	movs r3, #8
_081F67F4:
	ldr r1, _081F681C @ =0x000006DA
	adds r0, r7, r1
	ldrb r2, [r0]
	ldr r0, _081F6818 @ =gSineTable
	mov ip, r0
	adds r0, r2, #0
	adds r0, #0x40
	mov r1, sb
	ands r0, r1
	lsls r0, r0, #1
	add r0, ip
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r3, r0
	cmp r0, #0
	blt _081F6820
	asrs r1, r0, #0xc
	b _081F6826
	.align 2, 0
_081F6818: .4byte gSineTable
_081F681C: .4byte 0x000006DA
_081F6820:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_081F6826:
	movs r0, #0
	strh r1, [r6]
	strh r0, [r6, #2]
	mov r0, sb
	ands r2, r0
	lsls r0, r2, #1
	add r0, sl
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r3, r0
	cmp r0, #0
	blt _081F6842
	asrs r0, r0, #0xc
	b _081F6848
_081F6842:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_081F6848:
	strh r0, [r6, #4]
	ldrb r0, [r4]
	adds r0, #0xa
	strb r0, [r4]
	ldrb r0, [r4]
	adds r0, #0x40
	mov r2, sb
	ands r0, r2
	lsls r0, r0, #1
	add r0, sl
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r0, #0x16
	muls r0, r5, r0
	muls r0, r1, r0
	cmp r0, #0
	blt _081F686E
	asrs r0, r0, #0xc
	b _081F6874
_081F686E:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_081F6874:
	strh r0, [r6, #2]
	adds r0, r7, #0
	adds r1, r6, #0
	adds r2, r5, #0
	str r3, [sp, #0xc]
	bl Entity081f73ec_SetSegVel
	movs r0, #0x92
	lsls r0, r0, #1
	adds r4, r4, r0
	ldr r3, [sp, #0xc]
	adds r3, #8
	adds r5, #1
	cmp r5, #5
	ble _081F67F4
_081F6892:
	movs r1, #0xdd
	lsls r1, r1, #3
	adds r0, r7, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	movs r1, #0x1e
	bl Mod
	cmp r0, #0
	bne _081F6954
	movs r1, #0xdb
	lsls r1, r1, #3
	adds r0, r7, r1
	ldrb r1, [r0]
	lsls r0, r1, #3
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r7, r0
	ldr r1, [r0, #0x20]
	ldr r0, [r0, #0x1c]
	str r0, [sp, #4]
	str r1, [sp, #8]
	add r0, sp, #4
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	mov r1, r8
	ldrh r0, [r1, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _081F68EA
	cmp r1, #0
	blt _081F68EA
	ldr r0, _081F68F0 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081F68EA
	ldr r0, _081F68F4 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081F68F8
_081F68EA:
	movs r5, #0
	b _081F6906
	.align 2, 0
_081F68F0: .4byte 0x030046A8
_081F68F4: .4byte 0x030046AC
_081F68F8:
	ldr r0, _081F6918 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r5, r0, r2
_081F6906:
	mov r4, r8
	adds r0, r5, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081F691C
	adds r0, #4
	b _081F6928
	.align 2, 0
_081F6918: .4byte 0x030046A4
_081F691C:
	ldr r0, _081F693C @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r5, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081F6928:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _081F6940
	cmp r2, #2
	beq _081F6944
	b _081F6948
	.align 2, 0
_081F693C: .4byte 0x030046A4
_081F6940:
	ldrb r0, [r4, #4]
	b _081F6946
_081F6944:
	ldrb r0, [r4]
_081F6946:
	subs r1, r1, r0
_081F6948:
	mov r2, r8
	strh r1, [r2, #2]
	mov r0, r8
	movs r1, #1
	bl Entity081f73ec_SpawnDust
_081F6954:
	adds r0, r7, #0
	bl Entity081f73ec_ApplySegVel
	adds r0, r7, #0
	bl Entity081f73ec_SnapToGround
	movs r0, #0x80
	lsls r0, r0, #1
	adds r1, r7, r0
	movs r2, #0x92
	lsls r2, r2, #1
	movs r5, #5
_081F696C:
	ldrh r0, [r1]
	cmp r0, #0
	beq _081F6976
	subs r0, #1
	strh r0, [r1]
_081F6976:
	adds r1, r1, r2
	subs r5, #1
	cmp r5, #0
	bge _081F696C
	ldr r2, _081F699C @ =0x000006DB
	adds r1, r7, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _081F698C
	subs r0, #1
	strb r0, [r1]
_081F698C:
	add sp, #0x10
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081F699C: .4byte 0x000006DB
