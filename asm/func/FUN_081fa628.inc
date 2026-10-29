	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x60
	adds r6, r0, #0
	adds r5, r1, #0
	add r4, sp, #0x3c
	movs r0, #0
	str r0, [sp, #0x38]
	add r0, sp, #0x38
	adds r1, r4, #0
	ldr r2, _081FA654 @ =0x05000002
	bl CpuSet
	cmp r5, #0
	beq _081FA658
	cmp r5, #1
	bne _081FA652
	b _081FA800
_081FA652:
	b _081FABA4
	.align 2, 0
_081FA654: .4byte 0x05000002
_081FA658:
	adds r0, r6, #0
	adds r0, #0x4d
	add r3, sp, #0x44
	ldrb r4, [r0]
	ldr r5, _081FA680 @ =0xFFFFFF00
	ldr r2, _081FA684 @ =gSineTable
	adds r0, r4, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r5, r0
	cmp r0, #0
	blt _081FA688
	asrs r1, r0, #0xc
	b _081FA68E
	.align 2, 0
_081FA680: .4byte 0xFFFFFF00
_081FA684: .4byte gSineTable
_081FA688:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_081FA68E:
	movs r0, #0
	strh r1, [r3]
	strh r0, [r3, #2]
	ldr r1, _081FA6A8 @ =gSineTable
	lsls r0, r4, #1
	adds r0, r0, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r5, r0
	cmp r0, #0
	blt _081FA6AC
	asrs r0, r0, #0xc
	b _081FA6B2
	.align 2, 0
_081FA6A8: .4byte gSineTable
_081FA6AC:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_081FA6B2:
	strh r0, [r3, #4]
	adds r2, r6, #0
	adds r2, #0x50
	add r1, sp, #0x44
	ldrh r0, [r2]
	ldrh r3, [r1]
	adds r0, r0, r3
	strh r0, [r1]
	movs r5, #0x46
	add r5, sp
	ldrh r0, [r5]
	ldrh r1, [r2, #2]
	adds r0, r0, r1
	strh r0, [r5]
	ldrh r1, [r2, #4]
	add r6, sp, #0x48
	ldrh r6, [r6]
	adds r1, r1, r6
	add r0, sp, #0x48
	strh r1, [r0]
	add r5, sp, #0x44
	ldrh r0, [r5]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	lsls r1, r1, #0x10
	asrs r1, r1, #0x18
	cmp r2, #0
	blt _081FA6FE
	cmp r1, #0
	blt _081FA6FE
	ldr r0, _081FA704 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081FA6FE
	ldr r0, _081FA708 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081FA70C
_081FA6FE:
	movs r4, #0
	b _081FA71A
	.align 2, 0
_081FA704: .4byte 0x030046A8
_081FA708: .4byte 0x030046AC
_081FA70C:
	ldr r0, _081FA72C @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_081FA71A:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081FA730
	adds r0, #4
	b _081FA73C
	.align 2, 0
_081FA72C: .4byte 0x030046A4
_081FA730:
	ldr r0, _081FA7E4 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081FA73C:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	lsls r0, r0, #8
	strh r0, [r5, #2]
	movs r1, #0xff
	mov sl, r1
	ldr r2, _081FA7E8 @ =gSineTable
	mov sb, r2
	add r7, sp, #0x4c
	movs r3, #0
	mov r8, r3
	movs r6, #0
_081FA756:
	ldr r5, _081FA7EC @ =0x030046B8
	ldr r0, [r5]
	adds r0, #1
	ldr r1, _081FA7F0 @ =0x000003FF
	ands r0, r1
	str r0, [r5]
	lsls r0, r0, #1
	ldr r1, _081FA7F4 @ =0x0203B400
	adds r0, r0, r1
	ldrh r1, [r0]
	mov r2, sl
	ands r1, r2
	add r0, sp, #0x44
	movs r5, #0
	ldrsh r3, [r0, r5]
	lsls r0, r1, #1
	add r0, sb
	movs r2, #0
	ldrsh r4, [r0, r2]
	add r0, sp, #0x44
	movs r2, #2
	ldrsh r5, [r0, r2]
	mov ip, r5
	movs r5, #4
	ldrsh r2, [r0, r5]
	adds r1, #0x40
	mov r0, sl
	ands r1, r0
	lsls r1, r1, #1
	add r1, sb
	movs r5, #0
	ldrsh r0, [r1, r5]
	adds r3, r3, r4
	adds r2, r2, r0
	add r0, sp, #0x4c
	strh r3, [r0]
	mov r0, ip
	strh r0, [r7, #2]
	strh r2, [r7, #4]
	movs r0, #3
	str r0, [sp]
	str r6, [sp, #4]
	movs r0, #9
	str r0, [sp, #8]
	movs r0, #0xda
	str r0, [sp, #0xc]
	movs r0, #1
	str r0, [sp, #0x10]
	str r6, [sp, #0x14]
	str r6, [sp, #0x18]
	str r6, [sp, #0x1c]
	str r6, [sp, #0x20]
	str r6, [sp, #0x24]
	str r6, [sp, #0x28]
	str r6, [sp, #0x2c]
	str r6, [sp, #0x30]
	str r6, [sp, #0x34]
	adds r0, r7, #0
	add r1, sp, #0x3c
	ldr r2, _081FA7F8 @ =0x00002E78
	ldr r3, _081FA7FC @ =0x000038E2
	bl Entity081f26bc_Spawn
	movs r1, #1
	rsbs r1, r1, #0
	add r8, r1
	mov r2, r8
	cmp r2, #0
	bge _081FA756
	b _081FABA4
	.align 2, 0
_081FA7E4: .4byte 0x030046A4
_081FA7E8: .4byte gSineTable
_081FA7EC: .4byte 0x030046B8
_081FA7F0: .4byte 0x000003FF
_081FA7F4: .4byte 0x0203B400
_081FA7F8: .4byte 0x00002E78
_081FA7FC: .4byte 0x000038E2
_081FA800:
	adds r3, r6, #0
	adds r3, #0x4d
	add r4, sp, #0x44
	ldrb r5, [r3]
	movs r7, #0x1e
	rsbs r7, r7, #0
	ldr r2, _081FA82C @ =gSineTable
	adds r0, r5, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r7, r0
	str r3, [sp, #0x54]
	cmp r0, #0
	blt _081FA830
	asrs r1, r0, #0xc
	b _081FA836
	.align 2, 0
_081FA82C: .4byte gSineTable
_081FA830:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_081FA836:
	movs r0, #0
	strh r1, [r4]
	strh r0, [r4, #2]
	ldr r1, _081FA850 @ =gSineTable
	lsls r0, r5, #1
	adds r0, r0, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r7, r0
	cmp r0, #0
	blt _081FA854
	asrs r0, r0, #0xc
	b _081FA85A
	.align 2, 0
_081FA850: .4byte gSineTable
_081FA854:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_081FA85A:
	strh r0, [r4, #4]
	adds r2, r6, #0
	adds r2, #0x50
	add r1, sp, #0x44
	ldrh r0, [r2]
	ldrh r3, [r1]
	adds r0, r0, r3
	strh r0, [r1]
	movs r5, #0x46
	add r5, sp
	ldrh r0, [r5]
	ldrh r1, [r2, #2]
	adds r0, r0, r1
	strh r0, [r5]
	ldrh r1, [r2, #4]
	add r6, sp, #0x48
	ldrh r6, [r6]
	adds r1, r1, r6
	add r0, sp, #0x48
	strh r1, [r0]
	add r5, sp, #0x44
	ldrh r0, [r5]
	lsls r0, r0, #0x10
	asrs r3, r0, #0x18
	lsls r1, r1, #0x10
	asrs r1, r1, #0x18
	str r2, [sp, #0x58]
	cmp r3, #0
	blt _081FA8A8
	cmp r1, #0
	blt _081FA8A8
	ldr r0, _081FA8AC @ =0x030046A8
	ldr r0, [r0]
	cmp r3, r0
	bhs _081FA8A8
	ldr r0, _081FA8B0 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081FA8B4
_081FA8A8:
	movs r4, #0
	b _081FA8C2
	.align 2, 0
_081FA8AC: .4byte 0x030046A8
_081FA8B0: .4byte 0x030046AC
_081FA8B4:
	ldr r0, _081FA8D4 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r3
_081FA8C2:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081FA8D8
	adds r0, #4
	b _081FA8E4
	.align 2, 0
_081FA8D4: .4byte 0x030046A4
_081FA8D8:
	ldr r0, _081FA934 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081FA8E4:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	lsls r0, r0, #8
	strh r0, [r5, #2]
	movs r1, #0
	mov r8, r1
	mov r2, sp
	adds r2, #0x4c
	str r2, [sp, #0x5c]
	ldr r3, _081FA938 @ =gSineTable
	mov sl, r3
	adds r7, r2, #0
	movs r4, #0
	ldr r5, _081FA93C @ =0x030046B8
	mov sb, r5
_081FA904:
	mov r6, sb
	ldr r0, [r6]
	adds r0, #1
	ldr r1, _081FA940 @ =0x000003FF
	ands r0, r1
	str r0, [r6]
	lsls r0, r0, #1
	ldr r1, _081FA944 @ =0x0203B400
	adds r0, r0, r1
	ldrh r1, [r0]
	mov r3, r8
	lsls r2, r3, #6
	movs r0, #0xf
	ands r1, r0
	adds r2, r2, r1
	lsls r0, r2, #1
	add r0, sl
	movs r5, #0
	ldrsh r0, [r0, r5]
	lsls r0, r0, #8
	cmp r0, #0
	blt _081FA948
	asrs r0, r0, #0xc
	b _081FA94E
	.align 2, 0
_081FA934: .4byte 0x030046A4
_081FA938: .4byte gSineTable
_081FA93C: .4byte 0x030046B8
_081FA940: .4byte 0x000003FF
_081FA944: .4byte 0x0203B400
_081FA948:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_081FA94E:
	adds r5, r0, #0
	add r0, sp, #0x44
	movs r6, #0
	ldrsh r3, [r0, r6]
	movs r6, #2
	ldrsh r1, [r0, r6]
	mov ip, r1
	adds r0, r2, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	add r0, sl
	movs r1, #0
	ldrsh r0, [r0, r1]
	movs r2, #0x80
	lsls r2, r2, #1
	muls r0, r2, r0
	cmp r0, #0
	blt _081FA97A
	asrs r0, r0, #0xc
	b _081FA980
_081FA97A:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_081FA980:
	add r2, sp, #0x48
	movs r6, #0
	ldrsh r1, [r2, r6]
	adds r2, r3, r5
	adds r1, r1, r0
	add r0, sp, #0x4c
	strh r2, [r0]
	mov r3, ip
	strh r3, [r7, #2]
	strh r1, [r7, #4]
	movs r0, #6
	str r0, [sp]
	str r4, [sp, #4]
	movs r0, #9
	str r0, [sp, #8]
	ldr r0, _081FA9F4 @ =0x00000237
	str r0, [sp, #0xc]
	movs r0, #1
	str r0, [sp, #0x10]
	str r4, [sp, #0x14]
	str r4, [sp, #0x18]
	str r4, [sp, #0x1c]
	str r4, [sp, #0x20]
	str r4, [sp, #0x24]
	str r4, [sp, #0x28]
	str r4, [sp, #0x2c]
	str r4, [sp, #0x30]
	str r4, [sp, #0x34]
	adds r0, r7, #0
	add r1, sp, #0x3c
	ldr r2, _081FA9F8 @ =0x0000F422
	ldr r3, _081FA9FC @ =0x0000121B
	bl Entity081f26bc_Spawn
	movs r5, #1
	add r8, r5
	mov r6, r8
	cmp r6, #3
	ble _081FA904
	add r4, sp, #0x44
	ldr r0, [sp, #0x54]
	ldrb r3, [r0]
	ldr r5, _081FAA00 @ =0xFFFFFED4
	ldr r2, _081FAA04 @ =gSineTable
	adds r0, r3, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r5, r0
	cmp r0, #0
	blt _081FAA08
	asrs r1, r0, #0xc
	b _081FAA0E
	.align 2, 0
_081FA9F4: .4byte 0x00000237
_081FA9F8: .4byte 0x0000F422
_081FA9FC: .4byte 0x0000121B
_081FAA00: .4byte 0xFFFFFED4
_081FAA04: .4byte gSineTable
_081FAA08:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_081FAA0E:
	movs r0, #0
	strh r1, [r4]
	strh r0, [r4, #2]
	ldr r1, _081FAA28 @ =gSineTable
	lsls r0, r3, #1
	adds r0, r0, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r5, r0
	cmp r0, #0
	blt _081FAA2C
	asrs r0, r0, #0xc
	b _081FAA32
	.align 2, 0
_081FAA28: .4byte gSineTable
_081FAA2C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_081FAA32:
	strh r0, [r4, #4]
	add r1, sp, #0x44
	ldr r3, [sp, #0x58]
	ldrh r0, [r3]
	ldrh r5, [r1]
	adds r0, r0, r5
	strh r0, [r1]
	movs r6, #0x46
	add r6, sp
	ldrh r0, [r6]
	ldrh r1, [r3, #2]
	adds r0, r0, r1
	strh r0, [r6]
	ldrh r1, [r3, #4]
	add r0, sp, #0x48
	ldrh r0, [r0]
	adds r1, r1, r0
	add r2, sp, #0x48
	strh r1, [r2]
	add r5, sp, #0x44
	ldrh r0, [r5]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	lsls r1, r1, #0x10
	asrs r1, r1, #0x18
	cmp r2, #0
	blt _081FAA7C
	cmp r1, #0
	blt _081FAA7C
	ldr r0, _081FAA80 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081FAA7C
	ldr r0, _081FAA84 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081FAA88
_081FAA7C:
	movs r4, #0
	b _081FAA96
	.align 2, 0
_081FAA80: .4byte 0x030046A8
_081FAA84: .4byte 0x030046AC
_081FAA88:
	ldr r0, _081FAAA8 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_081FAA96:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081FAAAC
	adds r0, #4
	b _081FAAB8
	.align 2, 0
_081FAAA8: .4byte 0x030046A4
_081FAAAC:
	ldr r0, _081FAB08 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081FAAB8:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	lsls r0, r0, #8
	strh r0, [r5, #2]
	movs r3, #0
	mov r8, r3
	ldr r5, _081FAB0C @ =gSineTable
	mov sl, r5
	ldr r7, [sp, #0x5c]
	movs r4, #0
	ldr r6, _081FAB10 @ =0x030046B8
	mov sb, r6
_081FAAD2:
	mov r1, sb
	ldr r0, [r1]
	adds r0, #1
	ldr r1, _081FAB14 @ =0x000003FF
	ands r0, r1
	mov r2, sb
	str r0, [r2]
	lsls r0, r0, #1
	ldr r3, _081FAB18 @ =0x0203B400
	adds r0, r0, r3
	ldrh r1, [r0]
	mov r5, r8
	lsls r2, r5, #6
	movs r0, #0x1f
	ands r1, r0
	adds r2, r2, r1
	ldr r1, _081FAB0C @ =gSineTable
	lsls r0, r2, #1
	adds r0, r0, r1
	movs r6, #0
	ldrsh r0, [r0, r6]
	lsls r0, r0, #8
	cmp r0, #0
	blt _081FAB1C
	asrs r0, r0, #0xc
	b _081FAB22
	.align 2, 0
_081FAB08: .4byte 0x030046A4
_081FAB0C: .4byte gSineTable
_081FAB10: .4byte 0x030046B8
_081FAB14: .4byte 0x000003FF
_081FAB18: .4byte 0x0203B400
_081FAB1C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_081FAB22:
	adds r5, r0, #0
	add r1, sp, #0x44
	movs r0, #0
	ldrsh r3, [r1, r0]
	adds r0, r1, #0
	movs r1, #2
	ldrsh r6, [r0, r1]
	mov ip, r6
	adds r0, r2, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	add r0, sl
	movs r2, #0
	ldrsh r0, [r0, r2]
	movs r6, #0x80
	lsls r6, r6, #1
	muls r0, r6, r0
	cmp r0, #0
	blt _081FAB50
	asrs r0, r0, #0xc
	b _081FAB56
_081FAB50:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_081FAB56:
	add r6, sp, #0x48
	movs r2, #0
	ldrsh r1, [r6, r2]
	adds r2, r3, r5
	adds r1, r1, r0
	add r0, sp, #0x4c
	strh r2, [r0]
	mov r0, ip
	strh r0, [r7, #2]
	strh r1, [r7, #4]
	movs r0, #6
	str r0, [sp]
	str r4, [sp, #4]
	movs r0, #9
	str r0, [sp, #8]
	ldr r0, _081FABB4 @ =0x00000237
	str r0, [sp, #0xc]
	movs r0, #1
	str r0, [sp, #0x10]
	str r4, [sp, #0x14]
	str r4, [sp, #0x18]
	str r4, [sp, #0x1c]
	str r4, [sp, #0x20]
	str r4, [sp, #0x24]
	str r4, [sp, #0x28]
	str r4, [sp, #0x2c]
	str r4, [sp, #0x30]
	str r4, [sp, #0x34]
	adds r0, r7, #0
	add r1, sp, #0x3c
	ldr r2, _081FABB8 @ =0x0000F422
	ldr r3, _081FABBC @ =0x0000121B
	bl Entity081f26bc_Spawn
	movs r1, #1
	add r8, r1
	mov r2, r8
	cmp r2, #3
	ble _081FAAD2
_081FABA4:
	add sp, #0x60
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081FABB4: .4byte 0x00000237
_081FABB8: .4byte 0x0000F422
_081FABBC: .4byte 0x0000121B
