	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x90
	adds r7, r0, #0
	ldr r0, _0810F6A0 @ =0x0000046C
	adds r1, r7, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _0810F6A4
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0810F6A6
	.align 2, 0
_0810F6A0: .4byte 0x0000046C
_0810F6A4:
	movs r0, #0
_0810F6A6:
	cmp r0, #0
	beq _0810F6B4
	movs r1, #0xfe
	lsls r1, r1, #1
	adds r0, r7, r1
	ldrb r0, [r0]
	strb r0, [r7, #5]
_0810F6B4:
	movs r2, #0xc1
	lsls r2, r2, #3
	adds r0, r7, r2
	ldr r1, [r0]
	adds r0, r7, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0810F6CC
	bl _0810FF36
_0810F6CC:
	adds r0, r7, #0
	bl FUN_080f0a0c
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
	cmp r6, #0
	beq _0810F6DE
	bl _0810FF36
_0810F6DE:
	ldr r3, _0810F7D0 @ =0x00000484
	adds r1, r7, r3
	ldr r0, [r1]
	cmp r0, #0x3c
	bgt _0810F6EC
	bl _0810FF32
_0810F6EC:
	movs r0, #0x80
	movs r4, #0xc0
	lsls r4, r4, #1
	adds r2, r7, r4
	ldrh r1, [r2]
	ands r1, r0
	lsls r1, r1, #0x10
	lsrs r3, r1, #0x10
	str r2, [sp, #0x48]
	cmp r3, #0
	bne _0810F704
	b _0810FCF8
_0810F704:
	movs r0, #0xc
	movs r1, #0x8d
	lsls r1, r1, #3
	adds r1, r7, r1
	str r1, [sp, #8]
	strb r6, [r1]
	ldr r2, _0810F7D4 @ =0x00000469
	adds r2, r7, r2
	str r2, [sp, #0xc]
	strb r6, [r2]
	ldr r3, _0810F7D8 @ =0x0000046A
	adds r3, r7, r3
	str r3, [sp, #0x10]
	strb r0, [r3]
	ldr r4, _0810F7D0 @ =0x00000484
	adds r4, r7, r4
	str r4, [sp, #0x14]
	str r6, [r4]
	ldr r0, _0810F7DC @ =0x0000046C
	adds r0, r0, r7
	mov sb, r0
	movs r1, #1
	strb r1, [r0]
	movs r2, #0xb7
	lsls r2, r2, #3
	adds r0, r7, r2
	ldr r2, [r0]
	movs r0, #0x1a
	ldr r3, _0810F7E0 @ =0x0000046D
	adds r3, r7, r3
	str r3, [sp, #0x18]
	strb r1, [r3]
	ldr r4, _0810F7E4 @ =0x0000046B
	adds r4, r4, r7
	mov r8, r4
	strb r6, [r4]
	ldr r1, _0810F7E8 @ =0x00000553
	adds r1, r1, r7
	mov sl, r1
	strb r0, [r1]
	movs r3, #0xaf
	lsls r3, r3, #3
	adds r5, r7, r3
	str r2, [r5]
	movs r0, #0xe4
	lsls r0, r0, #1
	adds r4, r7, r0
	strh r6, [r4]
	movs r1, #0x95
	lsls r1, r1, #3
	adds r3, r7, r1
	ldr r2, [r3]
	str r2, [sp, #0x1c]
	adds r2, r7, #0
	adds r2, #0x9c
	ldr r0, [r2, #8]
	ldrh r1, [r0]
	ldr r6, [sp, #0x1c]
	strh r1, [r6]
	ldr r0, [r2, #8]
	ldrh r0, [r0, #2]
	strh r0, [r6, #4]
	lsls r1, r1, #0x10
	asrs r1, r1, #0x18
	mov ip, r1
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	mov r0, sb
	str r0, [sp, #0x80]
	ldr r6, [sp, #8]
	str r6, [sp, #0x70]
	ldr r0, [sp, #0xc]
	str r0, [sp, #0x74]
	ldr r6, [sp, #0x10]
	str r6, [sp, #0x78]
	ldr r0, [sp, #0x14]
	str r0, [sp, #0x8c]
	ldr r6, [sp, #0x18]
	str r6, [sp, #0x84]
	mov r0, r8
	str r0, [sp, #0x7c]
	mov r6, sl
	str r6, [sp, #0x60]
	str r5, [sp, #0x68]
	str r4, [sp, #0x64]
	adds r6, r3, #0
	mov r8, r2
	mov r0, ip
	cmp r0, #0
	blt _0810F7CC
	cmp r1, #0
	blt _0810F7CC
	ldr r0, _0810F7EC @ =0x030046A8
	ldr r0, [r0]
	cmp ip, r0
	bhs _0810F7CC
	ldr r0, _0810F7F0 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0810F7F4
_0810F7CC:
	movs r4, #0
	b _0810F804
	.align 2, 0
_0810F7D0: .4byte 0x00000484
_0810F7D4: .4byte 0x00000469
_0810F7D8: .4byte 0x0000046A
_0810F7DC: .4byte 0x0000046C
_0810F7E0: .4byte 0x0000046D
_0810F7E4: .4byte 0x0000046B
_0810F7E8: .4byte 0x00000553
_0810F7EC: .4byte 0x030046A8
_0810F7F0: .4byte 0x030046AC
_0810F7F4:
	ldr r0, _0810F814 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	mov r1, ip
	adds r4, r0, r1
_0810F804:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _0810F818
	adds r0, #4
	b _0810F824
	.align 2, 0
_0810F814: .4byte 0x030046A4
_0810F818:
	ldr r0, _0810F838 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0810F824:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _0810F83C
	cmp r2, #2
	beq _0810F842
	b _0810F848
	.align 2, 0
_0810F838: .4byte 0x030046A4
_0810F83C:
	ldr r2, [sp, #0x1c]
	ldrb r0, [r2, #4]
	b _0810F846
_0810F842:
	ldr r3, [sp, #0x1c]
	ldrb r0, [r3]
_0810F846:
	subs r1, r1, r0
_0810F848:
	ldr r4, [sp, #0x1c]
	strh r1, [r4, #2]
	ldr r0, _0810F860 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _0810F864
	movs r0, #1
	b _0810F866
	.align 2, 0
_0810F860: .4byte 0x030047A4
_0810F864:
	movs r0, #0
_0810F866:
	cmp r0, #0
	beq _0810F8A4
	movs r1, #0xec
	lsls r1, r1, #1
	adds r0, r7, r1
	ldr r1, [r0]
	cmp r1, #0
	beq _0810F886
	ldrb r0, [r1, #4]
	movs r2, #1
	rsbs r2, r2, #0
	cmp r0, #3
	bhi _0810F882
	adds r2, r0, #0
_0810F882:
	cmp r2, #0
	bge _0810F890
_0810F886:
	ldr r2, _0810F88C @ =0x000005C4
	adds r0, r7, r2
	b _0810FCE6
	.align 2, 0
_0810F88C: .4byte 0x000005C4
_0810F890:
	ldr r1, _0810F8A0 @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r0, [r0, #0x3c]
	ldrh r5, [r0, #6]
	b _0810F8EC
	.align 2, 0
_0810F8A0: .4byte 0x03002BE0
_0810F8A4:
	movs r3, #0xec
	lsls r3, r3, #1
	adds r0, r7, r3
	ldr r1, [r0]
	ldrh r0, [r1, #8]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r1, #0xc]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _0810F8D0
	cmp r1, #0
	blt _0810F8D0
	ldr r0, _0810F8D4 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _0810F8D0
	ldr r0, _0810F8D8 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0810F8DC
_0810F8D0:
	movs r5, #0
	b _0810F8EA
	.align 2, 0
_0810F8D4: .4byte 0x030046A8
_0810F8D8: .4byte 0x030046AC
_0810F8DC:
	ldr r0, _0810F97C @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r5, r0, r2
_0810F8EA:
	movs r2, #0
_0810F8EC:
	ldr r4, _0810F980 @ =0x00000256
	adds r0, r7, r4
	ldrh r0, [r0]
	cmp r5, r0
	beq _0810F90C
	ldr r1, _0810F984 @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #0xa
	ldr r0, [r0, #0x20]
	ands r0, r1
	cmp r0, #0
	bne _0810F90C
	b _0810FC24
_0810F90C:
	movs r1, #0x80
	lsls r1, r1, #3
	ldr r2, [sp, #0x48]
	ldrh r0, [r2]
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	cmp r4, #0
	beq _0810F920
	b _0810FF36
_0810F920:
	ldr r3, _0810F988 @ =0x00000222
	adds r2, r7, r3
	movs r0, #5
	rsbs r0, r0, #0
	ldrh r1, [r2]
	ands r0, r1
	movs r5, #0
	strh r0, [r2]
	movs r1, #0x80
	ldr r3, [sp, #0x48]
	ldrh r0, [r3]
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	mov sl, r2
	cmp r3, #0
	beq _0810F98C
	movs r6, #0xb7
	lsls r6, r6, #3
	adds r0, r7, r6
	ldr r1, [r0]
	movs r0, #0x1a
	movs r2, #1
	ldr r3, [sp, #0x84]
	strb r2, [r3]
	ldr r6, [sp, #0x7c]
	strb r5, [r6]
	ldr r3, [sp, #0x60]
	strb r0, [r3]
	ldr r6, [sp, #0x68]
	str r1, [r6]
	ldr r0, [sp, #0x64]
	strh r4, [r0]
	movs r0, #0xc
	ldr r1, [sp, #0x70]
	strb r5, [r1]
	ldr r3, [sp, #0x74]
	strb r5, [r3]
	ldr r6, [sp, #0x78]
	strb r0, [r6]
	ldr r0, [sp, #0x8c]
	str r4, [r0]
	ldr r1, [sp, #0x80]
	strb r2, [r1]
	b _0810FADA
	.align 2, 0
_0810F97C: .4byte 0x030046A4
_0810F980: .4byte 0x00000256
_0810F984: .4byte 0x03002BE0
_0810F988: .4byte 0x00000222
_0810F98C:
	movs r2, #0xb4
	lsls r2, r2, #3
	adds r0, r7, r2
	ldr r1, [r0]
	movs r0, #1
	ldr r4, [sp, #0x84]
	strb r0, [r4]
	ldr r2, [sp, #0x7c]
	strb r5, [r2]
	ldr r4, [sp, #0x60]
	strb r0, [r4]
	ldr r2, [sp, #0x68]
	str r1, [r2]
	ldr r4, [sp, #0x64]
	strh r3, [r4]
	movs r1, #5
	ldr r2, [sp, #0x70]
	strb r5, [r2]
	ldr r4, [sp, #0x74]
	strb r5, [r4]
	ldr r2, [sp, #0x78]
	strb r1, [r2]
	ldr r4, [sp, #0x8c]
	str r3, [r4]
	ldr r1, [sp, #0x80]
	strb r0, [r1]
	ldr r5, [r6]
	mov r2, r8
	ldr r0, [r2, #8]
	ldrh r1, [r0]
	strh r1, [r5]
	ldr r0, [r2, #8]
	ldrh r0, [r0, #2]
	strh r0, [r5, #4]
	lsls r1, r1, #0x10
	asrs r2, r1, #0x18
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _0810F9F0
	cmp r1, #0
	blt _0810F9F0
	ldr r0, _0810F9F4 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _0810F9F0
	ldr r0, _0810F9F8 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0810F9FC
_0810F9F0:
	movs r4, #0
	b _0810FA0A
	.align 2, 0
_0810F9F4: .4byte 0x030046A8
_0810F9F8: .4byte 0x030046AC
_0810F9FC:
	ldr r0, _0810FA1C @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_0810FA0A:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _0810FA20
	adds r0, #4
	b _0810FA2C
	.align 2, 0
_0810FA1C: .4byte 0x030046A4
_0810FA20:
	ldr r0, _0810FA40 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0810FA2C:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _0810FA44
	cmp r2, #2
	beq _0810FA48
	b _0810FA4C
	.align 2, 0
_0810FA40: .4byte 0x030046A4
_0810FA44:
	ldrb r0, [r5, #4]
	b _0810FA4A
_0810FA48:
	ldrb r0, [r5]
_0810FA4A:
	subs r1, r1, r0
_0810FA4C:
	strh r1, [r5, #2]
	ldr r0, [r6]
	ldrh r1, [r0]
	lsls r1, r1, #0x10
	asrs r2, r1, #0x18
	ldrh r0, [r0, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _0810FA74
	cmp r1, #0
	blt _0810FA74
	ldr r0, _0810FA78 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _0810FA74
	ldr r0, _0810FA7C @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0810FA80
_0810FA74:
	movs r4, #0
	b _0810FA8E
	.align 2, 0
_0810FA78: .4byte 0x030046A8
_0810FA7C: .4byte 0x030046AC
_0810FA80:
	ldr r0, _0810FAA0 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_0810FA8E:
	ldr r5, [r6]
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _0810FAA4
	adds r0, #4
	b _0810FAB0
	.align 2, 0
_0810FAA0: .4byte 0x030046A4
_0810FAA4:
	ldr r0, _0810FAC4 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0810FAB0:
	ldrb r1, [r0]
	lsrs r3, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r2, r0, #8
	cmp r3, #1
	beq _0810FAC8
	cmp r3, #2
	beq _0810FACC
	b _0810FAD0
	.align 2, 0
_0810FAC4: .4byte 0x030046A4
_0810FAC8:
	ldrb r0, [r5, #4]
	b _0810FACE
_0810FACC:
	ldrb r0, [r5]
_0810FACE:
	subs r2, r2, r0
_0810FAD0:
	ldr r0, [r6]
	movs r1, #0
	strh r2, [r0, #2]
	ldr r0, [r6]
	strh r1, [r0, #6]
_0810FADA:
	ldrb r3, [r7, #5]
	str r3, [sp, #0x20]
	movs r1, #0x80
	lsls r1, r1, #3
	ldr r4, [sp, #0x48]
	ldrh r0, [r4]
	ands r0, r1
	mov sb, r3
	ldr r6, _0810FB04 @ =0x00000482
	adds r6, r7, r6
	str r6, [sp, #0x88]
	cmp r0, #0
	bne _0810FBE8
	movs r1, #4
	mov r2, sl
	ldrh r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _0810FB08
	movs r0, #1
	b _0810FB0A
	.align 2, 0
_0810FB04: .4byte 0x00000482
_0810FB08:
	movs r0, #0
_0810FB0A:
	ldr r3, _0810FBF8 @ =0x00000482
	adds r3, r7, r3
	str r3, [sp, #0x88]
	cmp r0, #0
	bne _0810FBE8
	movs r3, #0
	movs r4, #0xa8
	lsls r4, r4, #3
	adds r4, r4, r7
	mov r8, r4
	movs r6, #0xa9
	lsls r6, r6, #3
	adds r6, r6, r7
	mov sl, r6
	ldr r0, _0810FBFC @ =0x0000054F
	adds r0, r0, r7
	mov ip, r0
	ldr r1, _0810FC00 @ =0x0000054C
	adds r1, r7, r1
	str r1, [sp, #0x54]
	ldr r2, _0810FC04 @ =0x0000054D
	adds r2, r7, r2
	str r2, [sp, #0x58]
	ldr r4, _0810FC08 @ =0x0000054E
	adds r4, r7, r4
	str r4, [sp, #0x5c]
	ldr r6, _0810FC0C @ =0x00000541
	adds r6, r7, r6
	str r6, [sp, #0x4c]
	ldr r0, _0810FC10 @ =0x000005BC
	adds r0, r7, r0
	str r0, [sp, #0x6c]
	ldr r1, _0810FC14 @ =0x00000542
	adds r1, r7, r1
	str r1, [sp, #0x50]
	ldr r6, _0810FC18 @ =0x0203B400
	ldr r1, _0810FC1C @ =0x030046B8
	ldr r5, _0810FC20 @ =0x000003FF
	movs r4, #3
	mov r2, sb
_0810FB5A:
	ldr r0, [r1]
	adds r0, #1
	ands r0, r5
	str r0, [r1]
	lsls r0, r0, #1
	adds r0, r0, r6
	ldrh r0, [r0]
	ands r0, r4
	lsls r0, r0, #6
	cmp r0, r2
	bne _0810FB78
	adds r3, #1
	cmp r3, #3
	ble _0810FB5A
	mov r0, sb
_0810FB78:
	movs r3, #0
	mov r2, r8
	strb r0, [r2]
	ldr r4, [sp, #0x68]
	ldr r0, [r4]
	mov r6, sl
	str r0, [r6]
	ldr r1, [sp, #0x60]
	ldrb r0, [r1]
	mov r2, ip
	strb r0, [r2]
	ldr r4, [sp, #0x70]
	ldrb r0, [r4]
	ldr r6, [sp, #0x54]
	strb r0, [r6]
	ldr r1, [sp, #0x74]
	ldrb r0, [r1]
	ldr r2, [sp, #0x58]
	strb r0, [r2]
	ldr r4, [sp, #0x78]
	ldrb r0, [r4]
	ldr r6, [sp, #0x5c]
	strb r0, [r6]
	add r0, sp, #0x20
	ldrb r1, [r0]
	ldr r0, [sp, #0x4c]
	strb r1, [r0]
	ldr r1, [sp, #0x6c]
	ldr r2, [r1]
	movs r0, #0x1b
	movs r1, #1
	ldr r4, [sp, #0x84]
	strb r1, [r4]
	ldr r6, [sp, #0x7c]
	strb r3, [r6]
	ldr r4, [sp, #0x60]
	strb r0, [r4]
	ldr r6, [sp, #0x68]
	str r2, [r6]
	movs r2, #0
	ldr r0, [sp, #0x64]
	strh r3, [r0]
	movs r0, #3
	ldr r4, [sp, #0x70]
	strb r0, [r4]
	ldr r6, [sp, #0x74]
	strb r1, [r6]
	ldr r0, [sp, #0x78]
	strb r2, [r0]
	ldr r2, [sp, #0x8c]
	str r3, [r2]
	ldr r3, [sp, #0x80]
	strb r1, [r3]
	movs r0, #6
	ldr r4, [sp, #0x50]
	strb r0, [r4]
_0810FBE8:
	adds r0, r7, #0
	bl FUN_080e7b6c
	movs r0, #2
	ldr r6, [sp, #0x88]
	strh r0, [r6]
	b _0810FF36
	.align 2, 0
_0810FBF8: .4byte 0x00000482
_0810FBFC: .4byte 0x0000054F
_0810FC00: .4byte 0x0000054C
_0810FC04: .4byte 0x0000054D
_0810FC08: .4byte 0x0000054E
_0810FC0C: .4byte 0x00000541
_0810FC10: .4byte 0x000005BC
_0810FC14: .4byte 0x00000542
_0810FC18: .4byte 0x0203B400
_0810FC1C: .4byte 0x030046B8
_0810FC20: .4byte 0x000003FF
_0810FC24:
	mov sb, sp
	ldr r6, _0810FC60 @ =0x030046A4
	ldr r0, [r6]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
	adds r0, r5, #0
	bl Mod
	adds r4, r0, #0
	ldr r0, [r6]
	ldr r0, [r0, #4]
	movs r3, #4
	ldrsh r1, [r0, r3]
	adds r0, r5, #0
	bl Div
	mov r8, r0
	lsls r4, r4, #8
	adds r4, #0x80
	mov r0, sp
	strh r4, [r0]
	adds r0, r5, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _0810FC64
	adds r0, #4
	b _0810FC6E
	.align 2, 0
_0810FC60: .4byte 0x030046A4
_0810FC64:
	ldr r0, [r6]
	lsls r1, r5, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_0810FC6E:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	lsls r0, r0, #8
	mov r4, sb
	strh r0, [r4, #2]
	mov r6, r8
	lsls r0, r6, #8
	adds r0, #0x80
	strh r0, [r4, #4]
	ldr r1, _0810FCA8 @ =0x000004A4
	adds r0, r7, r1
	ldr r4, [r0]
	adds r5, r7, #0
	adds r5, #8
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sp
	bl Map_IsPosInAgentIsland
	cmp r0, #0
	bne _0810FCB0
	ldr r0, _0810FCAC @ =0xFFFFFDFF
	ldr r2, [sp, #0x48]
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	b _0810FCDA
	.align 2, 0
_0810FCA8: .4byte 0x000004A4
_0810FCAC: .4byte 0xFFFFFDFF
_0810FCB0:
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sp
	bl Map_TryFindNavRoute
	cmp r0, #0
	beq _0810FCD0
	cmp r0, #2
	beq _0810FCCC
	adds r0, r7, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_0810FCCC:
	movs r0, #1
	b _0810FCDC
_0810FCD0:
	ldr r0, _0810FCF0 @ =0xFFFFFDFF
	ldr r3, [sp, #0x48]
	ldrh r1, [r3]
	ands r0, r1
	strh r0, [r3]
_0810FCDA:
	movs r0, #0
_0810FCDC:
	cmp r0, #0
	beq _0810FCE2
	b _0810FF36
_0810FCE2:
	ldr r4, _0810FCF4 @ =0x000005C4
	adds r0, r7, r4
_0810FCE6:
	ldr r1, [r0]
	adds r0, r7, #0
	bl _call_via_r1
	b _0810FF36
	.align 2, 0
_0810FCF0: .4byte 0xFFFFFDFF
_0810FCF4: .4byte 0x000005C4
_0810FCF8:
	movs r0, #3
	movs r1, #1
	movs r6, #0x8d
	lsls r6, r6, #3
	adds r6, r7, r6
	str r6, [sp, #0x24]
	strb r0, [r6]
	ldr r0, _0810FDFC @ =0x00000469
	adds r0, r7, r0
	str r0, [sp, #0x28]
	strb r1, [r0]
	ldr r2, _0810FE00 @ =0x0000046A
	adds r2, r7, r2
	str r2, [sp, #0x2c]
	strb r3, [r2]
	ldr r4, _0810FE04 @ =0x00000484
	adds r4, r7, r4
	str r4, [sp, #0x30]
	str r3, [r4]
	ldr r6, _0810FE08 @ =0x0000046C
	adds r6, r7, r6
	str r6, [sp, #0x34]
	strb r1, [r6]
	ldr r2, _0810FE0C @ =Enemy_WaitPendingState
	movs r0, #0xe
	ldr r4, _0810FE10 @ =0x0000046D
	adds r4, r7, r4
	str r4, [sp, #0x38]
	strb r1, [r4]
	ldr r6, _0810FE14 @ =0x0000046B
	adds r6, r7, r6
	str r6, [sp, #0x3c]
	strb r3, [r6]
	ldr r1, _0810FE18 @ =0x00000553
	adds r1, r7, r1
	str r1, [sp, #0x40]
	strb r0, [r1]
	movs r4, #0xaf
	lsls r4, r4, #3
	adds r4, r4, r7
	mov r8, r4
	str r2, [r4]
	movs r6, #0xe4
	lsls r6, r6, #1
	adds r6, r7, r6
	str r6, [sp, #0x44]
	movs r5, #0
	strh r3, [r6]
	ldr r1, _0810FE1C @ =0x000001DF
	adds r0, r7, r1
	ldrb r3, [r0]
	adds r0, r7, #0
	movs r1, #0
	movs r2, #2
	bl Enemy_SetEmote
	movs r2, #0xb4
	lsls r2, r2, #3
	adds r0, r7, r2
	ldr r3, [r0]
	movs r4, #7
	movs r1, #0x1e
	movs r6, #0xab
	lsls r6, r6, #3
	adds r2, r7, r6
	subs r6, #4
	adds r0, r7, r6
	str r1, [r0]
	str r3, [r2]
	movs r1, #0xaa
	lsls r1, r1, #3
	adds r0, r7, r1
	strb r5, [r0]
	ldr r2, _0810FE20 @ =0x00000551
	adds r0, r7, r2
	strb r5, [r0]
	ldr r3, _0810FE24 @ =0x00000552
	adds r0, r7, r3
	strb r4, [r0]
	movs r4, #0x95
	lsls r4, r4, #3
	adds r0, r7, r4
	ldr r5, [r0]
	adds r2, r7, #0
	adds r2, #0x9c
	ldr r0, [r2, #8]
	ldrh r1, [r0]
	strh r1, [r5]
	ldr r0, [r2, #8]
	ldrh r0, [r0, #2]
	strh r0, [r5, #4]
	lsls r1, r1, #0x10
	asrs r2, r1, #0x18
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	ldr r6, [sp, #0x34]
	str r6, [sp, #0x80]
	ldr r0, [sp, #0x24]
	str r0, [sp, #0x70]
	ldr r3, [sp, #0x28]
	str r3, [sp, #0x74]
	ldr r4, [sp, #0x2c]
	str r4, [sp, #0x78]
	ldr r6, [sp, #0x30]
	str r6, [sp, #0x8c]
	ldr r0, [sp, #0x38]
	str r0, [sp, #0x84]
	ldr r3, [sp, #0x3c]
	str r3, [sp, #0x7c]
	ldr r4, [sp, #0x40]
	str r4, [sp, #0x60]
	mov r6, r8
	str r6, [sp, #0x68]
	ldr r0, [sp, #0x44]
	str r0, [sp, #0x64]
	cmp r2, #0
	blt _0810FDF6
	cmp r1, #0
	blt _0810FDF6
	ldr r0, _0810FE28 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _0810FDF6
	ldr r0, _0810FE2C @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0810FE30
_0810FDF6:
	movs r4, #0
	b _0810FE3E
	.align 2, 0
_0810FDFC: .4byte 0x00000469
_0810FE00: .4byte 0x0000046A
_0810FE04: .4byte 0x00000484
_0810FE08: .4byte 0x0000046C
_0810FE0C: .4byte Enemy_WaitPendingState
_0810FE10: .4byte 0x0000046D
_0810FE14: .4byte 0x0000046B
_0810FE18: .4byte 0x00000553
_0810FE1C: .4byte 0x000001DF
_0810FE20: .4byte 0x00000551
_0810FE24: .4byte 0x00000552
_0810FE28: .4byte 0x030046A8
_0810FE2C: .4byte 0x030046AC
_0810FE30:
	ldr r0, _0810FE50 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_0810FE3E:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _0810FE54
	adds r0, #4
	b _0810FE60
	.align 2, 0
_0810FE50: .4byte 0x030046A4
_0810FE54:
	ldr r0, _0810FE74 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0810FE60:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _0810FE78
	cmp r2, #2
	beq _0810FE7C
	b _0810FE80
	.align 2, 0
_0810FE74: .4byte 0x030046A4
_0810FE78:
	ldrb r0, [r5, #4]
	b _0810FE7E
_0810FE7C:
	ldrb r0, [r5]
_0810FE7E:
	subs r1, r1, r0
_0810FE80:
	strh r1, [r5, #2]
	ldr r1, _0810FEB0 @ =0x000004A4
	adds r0, r7, r1
	ldr r5, [r0]
	adds r6, r7, #0
	adds r6, #8
	movs r2, #0x95
	lsls r2, r2, #3
	adds r0, r7, r2
	ldr r4, [r0]
	adds r0, r5, #0
	adds r1, r6, #0
	adds r2, r4, #0
	bl Map_IsPosInAgentIsland
	cmp r0, #0
	bne _0810FEB8
	ldr r0, _0810FEB4 @ =0xFFFFFDFF
	ldr r3, [sp, #0x48]
	ldrh r1, [r3]
	ands r0, r1
	strh r0, [r3]
	b _0810FEE2
	.align 2, 0
_0810FEB0: .4byte 0x000004A4
_0810FEB4: .4byte 0xFFFFFDFF
_0810FEB8:
	adds r0, r5, #0
	adds r1, r6, #0
	adds r2, r4, #0
	bl Map_TryFindNavRoute
	cmp r0, #0
	beq _0810FED8
	cmp r0, #2
	beq _0810FED4
	adds r0, r7, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_0810FED4:
	movs r0, #1
	b _0810FEE4
_0810FED8:
	ldr r0, _0810FF1C @ =0xFFFFFDFF
	ldr r4, [sp, #0x48]
	ldrh r1, [r4]
	ands r0, r1
	strh r0, [r4]
_0810FEE2:
	movs r0, #0
_0810FEE4:
	adds r3, r0, #0
	cmp r3, #0
	bne _0810FF24
	ldr r0, _0810FF20 @ =Enemy_ClearStateBegun
	movs r2, #1
	ldr r6, [sp, #0x84]
	strb r2, [r6]
	ldr r1, [sp, #0x7c]
	strb r3, [r1]
	ldr r4, [sp, #0x60]
	strb r3, [r4]
	ldr r6, [sp, #0x68]
	str r0, [r6]
	movs r1, #0
	ldr r0, [sp, #0x64]
	strh r3, [r0]
	movs r0, #3
	ldr r4, [sp, #0x70]
	strb r0, [r4]
	ldr r6, [sp, #0x74]
	strb r1, [r6]
	ldr r0, [sp, #0x78]
	strb r1, [r0]
	ldr r1, [sp, #0x8c]
	str r3, [r1]
	ldr r3, [sp, #0x80]
	strb r2, [r3]
	b _0810FF36
	.align 2, 0
_0810FF1C: .4byte 0xFFFFFDFF
_0810FF20: .4byte Enemy_ClearStateBegun
_0810FF24:
	movs r4, #0x95
	lsls r4, r4, #3
	adds r0, r7, r4
	ldr r1, [r0]
	movs r0, #1
	strh r0, [r1, #6]
	b _0810FF36

_0810FF32:
	adds r0, #1
	str r0, [r1]
_0810FF36:
	add sp, #0x90
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
