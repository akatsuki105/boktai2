	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x8c
	adds r7, r0, #0
	adds r4, r1, #0
	ldr r0, _081B5730 @ =0x0000046D
	adds r1, r7, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _081B5734
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _081B5736
	.align 2, 0
_081B5730: .4byte 0x0000046D
_081B5734:
	movs r0, #0
_081B5736:
	cmp r0, #0
	beq _081B5742
	adds r0, r7, #0
	movs r1, #3
	bl Enemy_PlayAnim
_081B5742:
	movs r0, #0x10
	movs r2, #0xc1
	lsls r2, r2, #1
	adds r1, r7, r2
	ldrh r2, [r1]
	orrs r0, r2
	strh r0, [r1]
	adds r5, r1, #0
	cmp r4, #0x11
	bgt _081B5776
	ldr r0, [r7, #0x44]
	adds r3, r0, #0
	adds r3, #0x48
	ldrh r4, [r3, #8]
	cmp r4, #0
	bne _081B5776
	ldrh r1, [r3, #0xe]
	ldrb r2, [r3, #7]
	rsbs r0, r2, #0
	orrs r0, r2
	lsrs r0, r0, #0x1f
	cmp r1, r0
	bne _081B5776
	cmp r2, #1
	beq _081B5776
	strh r4, [r3, #0xe]
_081B5776:
	ldr r3, _081B5800 @ =0x0000046E
	adds r0, r7, r3
	ldrb r0, [r0]
	cmp r0, #0
	bne _081B5784
	bl _081B60AC
_081B5784:
	ldr r4, _081B5804 @ =0x0000046B
	adds r0, r7, r4
	movs r4, #0
	movs r1, #1
	strb r1, [r0]
	movs r0, #2
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r1, r7, r2
	ldrh r2, [r1]
	ands r0, r2
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	str r1, [sp, #0x78]
	cmp r3, #0
	beq _081B581C
	movs r1, #3
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r0, r7, r3
	strb r1, [r0]
	ldr r1, _081B5808 @ =0x00000469
	adds r0, r7, r1
	strb r4, [r0]
	ldr r2, _081B580C @ =0x0000046A
	adds r0, r7, r2
	strb r4, [r0]
	adds r3, #0x1c
	adds r0, r7, r3
	str r4, [r0]
	adds r1, #3
	adds r0, r7, r1
	movs r2, #1
	strb r2, [r0]
	ldr r3, _081B5810 @ =0x00000594
	adds r0, r7, r3
	ldr r2, [r0]
	movs r1, #7
	ldr r3, _081B5814 @ =0x0000046D
	adds r0, r7, r3
	movs r3, #1
	strb r3, [r0]
	ldr r3, _081B5804 @ =0x0000046B
	adds r0, r7, r3
	strb r4, [r0]
	adds r3, #0xe8
	adds r0, r7, r3
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r7, r1
	str r2, [r0]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r0, r7, r2
	strh r4, [r0]
	ldr r0, _081B5818 @ =0xFFFFF67C
	ldrh r1, [r5]
	ands r0, r1
	strh r0, [r5]
	bl _081B60AC
	.align 2, 0
_081B5800: .4byte 0x0000046E
_081B5804: .4byte 0x0000046B
_081B5808: .4byte 0x00000469
_081B580C: .4byte 0x0000046A
_081B5810: .4byte 0x00000594
_081B5814: .4byte 0x0000046D
_081B5818: .4byte 0xFFFFF67C
_081B581C:
	movs r0, #0x80
	ands r2, r0
	lsls r0, r2, #0x10
	lsrs r5, r0, #0x10
	cmp r5, #0
	bne _081B582A
	b _081B5E64
_081B582A:
	adds r0, r7, #0
	movs r1, #0
	str r3, [sp, #0x88]
	bl Enemy_PlayAnim
	movs r0, #3
	movs r4, #0x8d
	lsls r4, r4, #3
	adds r4, r7, r4
	str r4, [sp, #8]
	strb r0, [r4]
	ldr r5, _081B593C @ =0x00000469
	adds r5, r7, r5
	str r5, [sp, #0xc]
	movs r0, #1
	strb r0, [r5]
	ldr r1, _081B5940 @ =0x0000046A
	adds r1, r7, r1
	str r1, [sp, #0x10]
	ldr r3, [sp, #0x88]
	strb r3, [r1]
	ldr r2, _081B5944 @ =0x00000484
	adds r2, r7, r2
	str r2, [sp, #0x14]
	str r3, [r2]
	ldr r4, _081B5948 @ =0x0000046C
	adds r4, r4, r7
	mov sb, r4
	strb r0, [r4]
	ldr r1, _081B594C @ =Enemy_WaitPendingState
	movs r0, #0xe
	ldr r5, _081B5950 @ =0x0000046D
	adds r6, r7, r5
	movs r2, #1
	strb r2, [r6]
	ldr r4, _081B5954 @ =0x0000046B
	adds r4, r4, r7
	mov sl, r4
	strb r3, [r4]
	adds r5, #0xe6
	adds r5, r7, r5
	str r5, [sp, #0x18]
	strb r0, [r5]
	movs r0, #0xaf
	lsls r0, r0, #3
	adds r0, r7, r0
	str r0, [sp, #0x1c]
	str r1, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r1, r1, r7
	mov r8, r1
	movs r4, #0
	strh r3, [r1]
	movs r2, #0xb7
	lsls r2, r2, #3
	adds r0, r7, r2
	ldr r3, [r0]
	movs r5, #0xc
	mov ip, r5
	movs r1, #0x1e
	movs r0, #0xab
	lsls r0, r0, #3
	adds r2, r7, r0
	ldr r5, _081B5958 @ =0x00000554
	adds r0, r7, r5
	str r1, [r0]
	str r3, [r2]
	movs r1, #0xaa
	lsls r1, r1, #3
	adds r0, r7, r1
	strb r4, [r0]
	ldr r2, _081B595C @ =0x00000551
	adds r0, r7, r2
	strb r4, [r0]
	ldr r3, _081B5960 @ =0x00000552
	adds r0, r7, r3
	mov r4, ip
	strb r4, [r0]
	adds r0, r7, #0
	bl Enemy_TargetNearestLinkPlayer
	lsls r0, r0, #0x18
	str r6, [sp, #0x54]
	ldr r5, [sp, #8]
	str r5, [sp, #0x40]
	ldr r1, [sp, #0xc]
	str r1, [sp, #0x44]
	ldr r2, [sp, #0x10]
	str r2, [sp, #0x48]
	ldr r3, [sp, #0x14]
	str r3, [sp, #0x5c]
	mov r4, sb
	str r4, [sp, #0x50]
	mov r5, sl
	str r5, [sp, #0x4c]
	ldr r1, [sp, #0x18]
	str r1, [sp, #0x74]
	ldr r2, [sp, #0x1c]
	str r2, [sp, #0x7c]
	mov r3, r8
	str r3, [sp, #0x80]
	cmp r0, #0
	bne _081B58FC
	b _081B60AC
_081B58FC:
	movs r4, #0x95
	lsls r4, r4, #3
	adds r3, r7, r4
	ldr r5, [r3]
	adds r2, r7, #0
	adds r2, #0x9c
	ldr r0, [r2, #8]
	ldrh r1, [r0]
	strh r1, [r5]
	ldr r0, [r2, #8]
	ldrh r0, [r0, #2]
	strh r0, [r5, #4]
	lsls r1, r1, #0x10
	asrs r4, r1, #0x18
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	adds r6, r3, #0
	mov r8, r2
	cmp r4, #0
	blt _081B5938
	cmp r1, #0
	blt _081B5938
	ldr r0, _081B5964 @ =0x030046A8
	ldr r0, [r0]
	cmp r4, r0
	bhs _081B5938
	ldr r0, _081B5968 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081B596C
_081B5938:
	movs r4, #0
	b _081B597A
	.align 2, 0
_081B593C: .4byte 0x00000469
_081B5940: .4byte 0x0000046A
_081B5944: .4byte 0x00000484
_081B5948: .4byte 0x0000046C
_081B594C: .4byte Enemy_WaitPendingState
_081B5950: .4byte 0x0000046D
_081B5954: .4byte 0x0000046B
_081B5958: .4byte 0x00000554
_081B595C: .4byte 0x00000551
_081B5960: .4byte 0x00000552
_081B5964: .4byte 0x030046A8
_081B5968: .4byte 0x030046AC
_081B596C:
	ldr r0, _081B598C @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r4
_081B597A:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081B5990
	adds r0, #4
	b _081B599C
	.align 2, 0
_081B598C: .4byte 0x030046A4
_081B5990:
	ldr r0, _081B59B0 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081B599C:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _081B59B4
	cmp r2, #2
	beq _081B59B8
	b _081B59BC
	.align 2, 0
_081B59B0: .4byte 0x030046A4
_081B59B4:
	ldrb r0, [r5, #4]
	b _081B59BA
_081B59B8:
	ldrb r0, [r5]
_081B59BA:
	subs r1, r1, r0
_081B59BC:
	strh r1, [r5, #2]
	ldr r0, _081B59D0 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _081B59D4
	movs r0, #1
	b _081B59D6
	.align 2, 0
_081B59D0: .4byte 0x030047A4
_081B59D4:
	movs r0, #0
_081B59D6:
	cmp r0, #0
	beq _081B5A14
	movs r5, #0xec
	lsls r5, r5, #1
	adds r0, r7, r5
	ldr r1, [r0]
	cmp r1, #0
	beq _081B59F6
	ldrb r0, [r1, #4]
	movs r2, #1
	rsbs r2, r2, #0
	cmp r0, #3
	bhi _081B59F2
	adds r2, r0, #0
_081B59F2:
	cmp r2, #0
	bge _081B5A00
_081B59F6:
	ldr r1, _081B59FC @ =0x000005C4
	adds r0, r7, r1
	b _081B5E52
	.align 2, 0
_081B59FC: .4byte 0x000005C4
_081B5A00:
	ldr r1, _081B5A10 @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r0, [r0, #0x3c]
	ldrh r5, [r0, #6]
	b _081B5A5C
	.align 2, 0
_081B5A10: .4byte 0x03002BE0
_081B5A14:
	movs r2, #0xec
	lsls r2, r2, #1
	adds r0, r7, r2
	ldr r1, [r0]
	ldrh r0, [r1, #8]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r1, #0xc]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _081B5A40
	cmp r1, #0
	blt _081B5A40
	ldr r0, _081B5A44 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081B5A40
	ldr r0, _081B5A48 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081B5A4C
_081B5A40:
	movs r5, #0
	b _081B5A5A
	.align 2, 0
_081B5A44: .4byte 0x030046A8
_081B5A48: .4byte 0x030046AC
_081B5A4C:
	ldr r0, _081B5AEC @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r5, r0, r2
_081B5A5A:
	movs r2, #0
_081B5A5C:
	ldr r3, _081B5AF0 @ =0x00000256
	adds r0, r7, r3
	ldrh r0, [r0]
	cmp r5, r0
	beq _081B5A7C
	ldr r1, _081B5AF4 @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #0xa
	ldr r0, [r0, #0x20]
	ands r0, r1
	cmp r0, #0
	bne _081B5A7C
	b _081B5D90
_081B5A7C:
	movs r1, #0x80
	lsls r1, r1, #3
	ldr r4, [sp, #0x78]
	ldrh r0, [r4]
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	cmp r4, #0
	beq _081B5A90
	b _081B60AC
_081B5A90:
	ldr r5, _081B5AF8 @ =0x00000222
	adds r2, r7, r5
	movs r0, #5
	rsbs r0, r0, #0
	ldrh r1, [r2]
	ands r0, r1
	movs r5, #0
	strh r0, [r2]
	movs r1, #0x80
	ldr r3, [sp, #0x78]
	ldrh r0, [r3]
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	mov sb, r2
	cmp r3, #0
	beq _081B5AFC
	movs r1, #0xb7
	lsls r1, r1, #3
	adds r0, r7, r1
	ldr r1, [r0]
	movs r0, #0x1a
	movs r2, #1
	ldr r3, [sp, #0x54]
	strb r2, [r3]
	ldr r3, [sp, #0x4c]
	strb r5, [r3]
	ldr r3, [sp, #0x74]
	strb r0, [r3]
	ldr r0, [sp, #0x7c]
	str r1, [r0]
	ldr r1, [sp, #0x80]
	strh r4, [r1]
	movs r0, #0xc
	ldr r3, [sp, #0x40]
	strb r5, [r3]
	ldr r1, [sp, #0x44]
	strb r5, [r1]
	ldr r3, [sp, #0x48]
	strb r0, [r3]
	ldr r5, [sp, #0x5c]
	str r4, [r5]
	ldr r0, [sp, #0x50]
	strb r2, [r0]
	b _081B5C4A
	.align 2, 0
_081B5AEC: .4byte 0x030046A4
_081B5AF0: .4byte 0x00000256
_081B5AF4: .4byte 0x03002BE0
_081B5AF8: .4byte 0x00000222
_081B5AFC:
	movs r1, #0xb4
	lsls r1, r1, #3
	adds r0, r7, r1
	ldr r1, [r0]
	movs r0, #1
	ldr r2, [sp, #0x54]
	strb r0, [r2]
	ldr r4, [sp, #0x4c]
	strb r5, [r4]
	ldr r2, [sp, #0x74]
	strb r0, [r2]
	ldr r4, [sp, #0x7c]
	str r1, [r4]
	ldr r1, [sp, #0x80]
	strh r3, [r1]
	movs r1, #5
	ldr r2, [sp, #0x40]
	strb r5, [r2]
	ldr r4, [sp, #0x44]
	strb r5, [r4]
	ldr r5, [sp, #0x48]
	strb r1, [r5]
	ldr r1, [sp, #0x5c]
	str r3, [r1]
	ldr r2, [sp, #0x50]
	strb r0, [r2]
	ldr r5, [r6]
	mov r3, r8
	ldr r0, [r3, #8]
	ldrh r1, [r0]
	strh r1, [r5]
	ldr r0, [r3, #8]
	ldrh r0, [r0, #2]
	strh r0, [r5, #4]
	lsls r1, r1, #0x10
	asrs r2, r1, #0x18
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _081B5B60
	cmp r1, #0
	blt _081B5B60
	ldr r0, _081B5B64 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081B5B60
	ldr r0, _081B5B68 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081B5B6C
_081B5B60:
	movs r4, #0
	b _081B5B7A
	.align 2, 0
_081B5B64: .4byte 0x030046A8
_081B5B68: .4byte 0x030046AC
_081B5B6C:
	ldr r0, _081B5B8C @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_081B5B7A:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081B5B90
	adds r0, #4
	b _081B5B9C
	.align 2, 0
_081B5B8C: .4byte 0x030046A4
_081B5B90:
	ldr r0, _081B5BB0 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081B5B9C:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _081B5BB4
	cmp r2, #2
	beq _081B5BB8
	b _081B5BBC
	.align 2, 0
_081B5BB0: .4byte 0x030046A4
_081B5BB4:
	ldrb r0, [r5, #4]
	b _081B5BBA
_081B5BB8:
	ldrb r0, [r5]
_081B5BBA:
	subs r1, r1, r0
_081B5BBC:
	strh r1, [r5, #2]
	ldr r0, [r6]
	ldrh r1, [r0]
	lsls r1, r1, #0x10
	asrs r2, r1, #0x18
	ldrh r0, [r0, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _081B5BE4
	cmp r1, #0
	blt _081B5BE4
	ldr r0, _081B5BE8 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081B5BE4
	ldr r0, _081B5BEC @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081B5BF0
_081B5BE4:
	movs r4, #0
	b _081B5BFE
	.align 2, 0
_081B5BE8: .4byte 0x030046A8
_081B5BEC: .4byte 0x030046AC
_081B5BF0:
	ldr r0, _081B5C10 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_081B5BFE:
	ldr r5, [r6]
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081B5C14
	adds r0, #4
	b _081B5C20
	.align 2, 0
_081B5C10: .4byte 0x030046A4
_081B5C14:
	ldr r0, _081B5C34 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081B5C20:
	ldrb r1, [r0]
	lsrs r3, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r2, r0, #8
	cmp r3, #1
	beq _081B5C38
	cmp r3, #2
	beq _081B5C3C
	b _081B5C40
	.align 2, 0
_081B5C34: .4byte 0x030046A4
_081B5C38:
	ldrb r0, [r5, #4]
	b _081B5C3E
_081B5C3C:
	ldrb r0, [r5]
_081B5C3E:
	subs r2, r2, r0
_081B5C40:
	ldr r0, [r6]
	movs r1, #0
	strh r2, [r0, #2]
	ldr r0, [r6]
	strh r1, [r0, #6]
_081B5C4A:
	ldrb r4, [r7, #5]
	str r4, [sp, #0x20]
	movs r1, #0x80
	lsls r1, r1, #3
	ldr r5, [sp, #0x78]
	ldrh r0, [r5]
	ands r0, r1
	mov r8, r4
	adds r1, #0x82
	adds r1, r7, r1
	str r1, [sp, #0x58]
	cmp r0, #0
	bne _081B5D54
	movs r1, #4
	mov r2, sb
	ldrh r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _081B5C74
	movs r0, #1
	b _081B5C76
_081B5C74:
	movs r0, #0
_081B5C76:
	ldr r3, _081B5D64 @ =0x00000482
	adds r3, r7, r3
	str r3, [sp, #0x58]
	cmp r0, #0
	bne _081B5D54
	movs r3, #0
	movs r4, #0xa8
	lsls r4, r4, #3
	adds r4, r4, r7
	mov sb, r4
	movs r5, #0xa9
	lsls r5, r5, #3
	adds r5, r5, r7
	mov sl, r5
	ldr r0, _081B5D68 @ =0x0000054F
	adds r0, r0, r7
	mov ip, r0
	ldr r1, _081B5D6C @ =0x0000054C
	adds r1, r7, r1
	str r1, [sp, #0x68]
	ldr r2, _081B5D70 @ =0x0000054D
	adds r2, r7, r2
	str r2, [sp, #0x6c]
	ldr r4, _081B5D74 @ =0x0000054E
	adds r4, r7, r4
	str r4, [sp, #0x70]
	ldr r5, _081B5D78 @ =0x00000541
	adds r5, r7, r5
	str r5, [sp, #0x60]
	ldr r0, _081B5D7C @ =0x000005BC
	adds r0, r7, r0
	str r0, [sp, #0x84]
	ldr r1, _081B5D80 @ =0x00000542
	adds r1, r7, r1
	str r1, [sp, #0x64]
	ldr r6, _081B5D84 @ =0x0203B400
	ldr r1, _081B5D88 @ =0x030046B8
	ldr r2, _081B5D8C @ =0x000003FF
	movs r5, #3
	mov r4, r8
_081B5CC6:
	ldr r0, [r1]
	adds r0, #1
	ands r0, r2
	str r0, [r1]
	lsls r0, r0, #1
	adds r0, r0, r6
	ldrh r0, [r0]
	ands r0, r5
	lsls r0, r0, #6
	cmp r0, r4
	bne _081B5CE4
	adds r3, #1
	cmp r3, #3
	ble _081B5CC6
	mov r0, r8
_081B5CE4:
	movs r3, #0
	mov r2, sb
	strb r0, [r2]
	ldr r4, [sp, #0x7c]
	ldr r0, [r4]
	mov r5, sl
	str r0, [r5]
	ldr r1, [sp, #0x74]
	ldrb r0, [r1]
	mov r2, ip
	strb r0, [r2]
	ldr r4, [sp, #0x40]
	ldrb r0, [r4]
	ldr r5, [sp, #0x68]
	strb r0, [r5]
	ldr r1, [sp, #0x44]
	ldrb r0, [r1]
	ldr r2, [sp, #0x6c]
	strb r0, [r2]
	ldr r4, [sp, #0x48]
	ldrb r0, [r4]
	ldr r5, [sp, #0x70]
	strb r0, [r5]
	add r0, sp, #0x20
	ldrb r1, [r0]
	ldr r0, [sp, #0x60]
	strb r1, [r0]
	ldr r1, [sp, #0x84]
	ldr r2, [r1]
	movs r0, #0x1b
	movs r1, #1
	ldr r4, [sp, #0x54]
	strb r1, [r4]
	ldr r5, [sp, #0x4c]
	strb r3, [r5]
	ldr r4, [sp, #0x74]
	strb r0, [r4]
	ldr r5, [sp, #0x7c]
	str r2, [r5]
	movs r2, #0
	ldr r0, [sp, #0x80]
	strh r3, [r0]
	movs r0, #3
	ldr r4, [sp, #0x40]
	strb r0, [r4]
	ldr r5, [sp, #0x44]
	strb r1, [r5]
	ldr r0, [sp, #0x48]
	strb r2, [r0]
	ldr r2, [sp, #0x5c]
	str r3, [r2]
	ldr r3, [sp, #0x50]
	strb r1, [r3]
	movs r0, #6
	ldr r4, [sp, #0x64]
	strb r0, [r4]
_081B5D54:
	adds r0, r7, #0
	bl Enemy_StepToFloorEdge
	movs r0, #2
	ldr r5, [sp, #0x58]
	strh r0, [r5]
	b _081B60AC
	.align 2, 0
_081B5D64: .4byte 0x00000482
_081B5D68: .4byte 0x0000054F
_081B5D6C: .4byte 0x0000054C
_081B5D70: .4byte 0x0000054D
_081B5D74: .4byte 0x0000054E
_081B5D78: .4byte 0x00000541
_081B5D7C: .4byte 0x000005BC
_081B5D80: .4byte 0x00000542
_081B5D84: .4byte 0x0203B400
_081B5D88: .4byte 0x030046B8
_081B5D8C: .4byte 0x000003FF
_081B5D90:
	mov sb, sp
	ldr r6, _081B5DCC @ =0x030046A4
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
	beq _081B5DD0
	adds r0, #4
	b _081B5DDA
	.align 2, 0
_081B5DCC: .4byte 0x030046A4
_081B5DD0:
	ldr r0, [r6]
	lsls r1, r5, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_081B5DDA:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	lsls r0, r0, #8
	mov r4, sb
	strh r0, [r4, #2]
	mov r5, r8
	lsls r0, r5, #8
	adds r0, #0x80
	strh r0, [r4, #4]
	ldr r1, _081B5E14 @ =0x000004A4
	adds r0, r7, r1
	ldr r4, [r0]
	adds r5, r7, #0
	adds r5, #8
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sp
	bl Map_IsPosInAgentIsland
	cmp r0, #0
	bne _081B5E1C
	ldr r0, _081B5E18 @ =0xFFFFFDFF
	ldr r2, [sp, #0x78]
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	b _081B5E46
	.align 2, 0
_081B5E14: .4byte 0x000004A4
_081B5E18: .4byte 0xFFFFFDFF
_081B5E1C:
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sp
	bl Map_TryFindNavRoute
	cmp r0, #0
	beq _081B5E3C
	cmp r0, #2
	beq _081B5E38
	adds r0, r7, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_081B5E38:
	movs r0, #1
	b _081B5E48
_081B5E3C:
	ldr r0, _081B5E5C @ =0xFFFFFDFF
	ldr r3, [sp, #0x78]
	ldrh r1, [r3]
	ands r0, r1
	strh r0, [r3]
_081B5E46:
	movs r0, #0
_081B5E48:
	cmp r0, #0
	beq _081B5E4E
	b _081B60AC
_081B5E4E:
	ldr r4, _081B5E60 @ =0x000005C4
	adds r0, r7, r4
_081B5E52:
	ldr r1, [r0]
	adds r0, r7, #0
	bl _call_via_r1
	b _081B60AC
	.align 2, 0
_081B5E5C: .4byte 0xFFFFFDFF
_081B5E60: .4byte 0x000005C4
_081B5E64:
	adds r0, r7, #0
	movs r1, #0
	bl Enemy_PlayAnim
	movs r0, #3
	movs r1, #0x8d
	lsls r1, r1, #3
	adds r1, r7, r1
	str r1, [sp, #0x24]
	strb r0, [r1]
	ldr r2, _081B5F7C @ =0x00000469
	adds r2, r7, r2
	str r2, [sp, #0x28]
	movs r3, #1
	strb r3, [r2]
	ldr r4, _081B5F80 @ =0x0000046A
	adds r4, r7, r4
	str r4, [sp, #0x2c]
	strb r5, [r4]
	ldr r0, _081B5F84 @ =0x00000484
	adds r0, r7, r0
	str r0, [sp, #0x30]
	str r5, [r0]
	ldr r1, _081B5F88 @ =0x0000046C
	adds r1, r7, r1
	str r1, [sp, #0x34]
	strb r3, [r1]
	ldr r1, _081B5F8C @ =Enemy_WaitPendingState
	movs r0, #0xe
	ldr r2, _081B5F90 @ =0x0000046D
	adds r6, r7, r2
	strb r3, [r6]
	ldr r3, _081B5F94 @ =0x0000046B
	adds r3, r3, r7
	mov ip, r3
	strb r5, [r3]
	ldr r4, _081B5F98 @ =0x00000553
	adds r4, r7, r4
	str r4, [sp, #0x38]
	strb r0, [r4]
	movs r0, #0xaf
	lsls r0, r0, #3
	adds r0, r7, r0
	str r0, [sp, #0x3c]
	str r1, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r1, r1, r7
	mov r8, r1
	movs r4, #0
	strh r5, [r1]
	movs r2, #0xb4
	lsls r2, r2, #3
	adds r0, r7, r2
	ldr r3, [r0]
	movs r1, #0x3c
	movs r5, #0xab
	lsls r5, r5, #3
	adds r2, r7, r5
	subs r5, #4
	adds r0, r7, r5
	str r1, [r0]
	str r3, [r2]
	movs r1, #0xaa
	lsls r1, r1, #3
	adds r0, r7, r1
	strb r4, [r0]
	ldr r2, _081B5F9C @ =0x00000551
	adds r0, r7, r2
	strb r4, [r0]
	ldr r3, _081B5FA0 @ =0x00000552
	adds r0, r7, r3
	movs r4, #7
	strb r4, [r0]
	subs r5, #0xd2
	adds r0, r7, r5
	movs r1, #1
	strh r1, [r0]
	movs r2, #0x10
	movs r3, #0xbc
	lsls r3, r3, #1
	adds r1, r7, r3
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	movs r0, #0x21
	rsbs r0, r0, #0
	ldr r4, [sp, #0x78]
	ldrh r1, [r4]
	ands r0, r1
	strh r0, [r4]
	adds r5, #0x26
	adds r0, r7, r5
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
	str r6, [sp, #0x54]
	ldr r0, [sp, #0x24]
	str r0, [sp, #0x40]
	ldr r3, [sp, #0x28]
	str r3, [sp, #0x44]
	ldr r4, [sp, #0x2c]
	str r4, [sp, #0x48]
	ldr r0, [sp, #0x30]
	str r0, [sp, #0x5c]
	ldr r3, [sp, #0x34]
	str r3, [sp, #0x50]
	mov r4, ip
	str r4, [sp, #0x4c]
	ldr r0, [sp, #0x38]
	str r0, [sp, #0x74]
	ldr r3, [sp, #0x3c]
	str r3, [sp, #0x7c]
	mov r4, r8
	str r4, [sp, #0x80]
	cmp r2, #0
	blt _081B5F76
	cmp r1, #0
	blt _081B5F76
	ldr r0, _081B5FA4 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081B5F76
	ldr r0, _081B5FA8 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081B5FAC
_081B5F76:
	movs r4, #0
	b _081B5FBA
	.align 2, 0
_081B5F7C: .4byte 0x00000469
_081B5F80: .4byte 0x0000046A
_081B5F84: .4byte 0x00000484
_081B5F88: .4byte 0x0000046C
_081B5F8C: .4byte Enemy_WaitPendingState
_081B5F90: .4byte 0x0000046D
_081B5F94: .4byte 0x0000046B
_081B5F98: .4byte 0x00000553
_081B5F9C: .4byte 0x00000551
_081B5FA0: .4byte 0x00000552
_081B5FA4: .4byte 0x030046A8
_081B5FA8: .4byte 0x030046AC
_081B5FAC:
	ldr r0, _081B5FCC @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_081B5FBA:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081B5FD0
	adds r0, #4
	b _081B5FDC
	.align 2, 0
_081B5FCC: .4byte 0x030046A4
_081B5FD0:
	ldr r0, _081B5FF0 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081B5FDC:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _081B5FF4
	cmp r2, #2
	beq _081B5FF8
	b _081B5FFC
	.align 2, 0
_081B5FF0: .4byte 0x030046A4
_081B5FF4:
	ldrb r0, [r5, #4]
	b _081B5FFA
_081B5FF8:
	ldrb r0, [r5]
_081B5FFA:
	subs r1, r1, r0
_081B5FFC:
	strh r1, [r5, #2]
	ldr r5, _081B602C @ =0x000004A4
	adds r0, r7, r5
	ldr r5, [r0]
	adds r6, r7, #0
	adds r6, #8
	movs r1, #0x95
	lsls r1, r1, #3
	adds r0, r7, r1
	ldr r4, [r0]
	adds r0, r5, #0
	adds r1, r6, #0
	adds r2, r4, #0
	bl Map_IsPosInAgentIsland
	cmp r0, #0
	bne _081B6034
	ldr r0, _081B6030 @ =0xFFFFFDFF
	ldr r2, [sp, #0x78]
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	b _081B605E
	.align 2, 0
_081B602C: .4byte 0x000004A4
_081B6030: .4byte 0xFFFFFDFF
_081B6034:
	adds r0, r5, #0
	adds r1, r6, #0
	adds r2, r4, #0
	bl Map_TryFindNavRoute
	cmp r0, #0
	beq _081B6054
	cmp r0, #2
	beq _081B6050
	adds r0, r7, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_081B6050:
	movs r0, #1
	b _081B6060
_081B6054:
	ldr r0, _081B6098 @ =0xFFFFFDFF
	ldr r3, [sp, #0x78]
	ldrh r1, [r3]
	ands r0, r1
	strh r0, [r3]
_081B605E:
	movs r0, #0
_081B6060:
	adds r3, r0, #0
	cmp r3, #0
	bne _081B60A0
	ldr r0, _081B609C @ =Enemy_ClearStateBegun
	movs r2, #1
	ldr r4, [sp, #0x54]
	strb r2, [r4]
	ldr r5, [sp, #0x4c]
	strb r3, [r5]
	ldr r1, [sp, #0x74]
	strb r3, [r1]
	ldr r4, [sp, #0x7c]
	str r0, [r4]
	movs r1, #0
	ldr r5, [sp, #0x80]
	strh r3, [r5]
	movs r0, #3
	ldr r4, [sp, #0x40]
	strb r0, [r4]
	ldr r5, [sp, #0x44]
	strb r1, [r5]
	ldr r0, [sp, #0x48]
	strb r1, [r0]
	ldr r1, [sp, #0x5c]
	str r3, [r1]
	ldr r3, [sp, #0x50]
	strb r2, [r3]
	b _081B60AC
	.align 2, 0
_081B6098: .4byte 0xFFFFFDFF
_081B609C: .4byte Enemy_ClearStateBegun
_081B60A0:
	movs r4, #0x95
	lsls r4, r4, #3
	adds r0, r7, r4
	ldr r1, [r0]
	movs r0, #1
	strh r0, [r1, #6]
_081B60AC:
	add sp, #0x8c
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
