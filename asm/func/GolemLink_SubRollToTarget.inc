	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x10
	adds r5, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r7, [r0]
	ldr r2, _081BE880 @ =0x0000046C
	adds r1, r5, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _081BE884
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _081BE886
	.align 2, 0
_081BE880: .4byte 0x0000046C
_081BE884:
	movs r0, #0
_081BE886:
	cmp r0, #0
	beq _081BE8CC
	ldr r4, _081BE924 @ =GolemLink_StateCurlUp
	movs r3, #0x24
	ldr r6, _081BE928 @ =0x0000046D
	adds r1, r5, r6
	movs r2, #0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _081BE92C @ =0x0000046B
	adds r0, r5, r1
	strb r2, [r0]
	adds r6, #0xe6
	adds r0, r5, r6
	strb r3, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r5, r1
	str r4, [r0]
	movs r3, #0xe4
	lsls r3, r3, #1
	adds r0, r5, r3
	movs r1, #0
	strh r2, [r0]
	movs r6, #0xfe
	lsls r6, r6, #1
	adds r0, r5, r6
	ldrb r0, [r0]
	strb r0, [r5, #5]
	ldr r3, _081BE92C @ =0x0000046B
	adds r0, r5, r3
	strb r1, [r0]
	ldr r6, _081BE930 @ =0x000006BC
	adds r0, r7, r6
	strh r2, [r0]
_081BE8CC:
	adds r0, r5, #0
	bl GolemLink_TryChaseHitTarget
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _081BE8DA
	b _081BEB5A
_081BE8DA:
	ldr r1, _081BE92C @ =0x0000046B
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _081BE8E6
	b _081BEB50
_081BE8E6:
	movs r2, #0x95
	lsls r2, r2, #3
	adds r0, r5, r2
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
	blt _081BE91E
	cmp r1, #0
	blt _081BE91E
	ldr r0, _081BE934 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081BE91E
	ldr r0, _081BE938 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081BE93C
_081BE91E:
	movs r4, #0
	b _081BE94A
	.align 2, 0
_081BE924: .4byte GolemLink_StateCurlUp
_081BE928: .4byte 0x0000046D
_081BE92C: .4byte 0x0000046B
_081BE930: .4byte 0x000006BC
_081BE934: .4byte 0x030046A8
_081BE938: .4byte 0x030046AC
_081BE93C:
	ldr r0, _081BE960 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_081BE94A:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081BE964
	adds r0, #4
	ldr r3, _081BE960 @ =0x030046A4
	mov sl, r3
	b _081BE972
	.align 2, 0
_081BE960: .4byte 0x030046A4
_081BE964:
	ldr r2, _081BE988 @ =0x030046A4
	ldr r1, [r2]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
	mov sl, r2
_081BE972:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r3, r0, #8
	cmp r2, #1
	beq _081BE98C
	cmp r2, #2
	beq _081BE990
	b _081BE994
	.align 2, 0
_081BE988: .4byte 0x030046A4
_081BE98C:
	ldrb r0, [r6, #4]
	b _081BE992
_081BE990:
	ldrb r0, [r6]
_081BE992:
	subs r3, r3, r0
_081BE994:
	movs r1, #0
	movs r2, #0
	strh r3, [r6, #2]
	movs r6, #0x95
	lsls r6, r6, #3
	adds r0, r5, r6
	ldr r0, [r0]
	strh r2, [r0, #6]
	ldr r3, _081BEA20 @ =0x000006C1
	adds r0, r7, r3
	strb r1, [r0]
	ldr r6, _081BEA24 @ =0x000006B4
	adds r1, r7, r6
	movs r0, #0x78
	strh r0, [r1]
	ldr r1, _081BEA28 @ =0x000006BA
	adds r0, r7, r1
	strh r2, [r0]
	subs r3, #9
	adds r1, r7, r3
	movs r0, #2
	strh r0, [r1]
	adds r6, #2
	adds r0, r7, r6
	strh r2, [r0]
	movs r0, #0xda
	lsls r0, r0, #3
	adds r2, r7, r0
	movs r1, #0xd9
	lsls r1, r1, #3
	adds r0, r7, r1
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [r2]
	str r1, [r2, #4]
	ldr r2, _081BEA2C @ =0x00000256
	adds r0, r5, r2
	ldrh r6, [r0]
	mov sb, sp
	mov r3, sl
	ldr r0, [r3]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
	adds r0, r6, #0
	bl Mod
	adds r4, r0, #0
	mov r3, sl
	ldr r0, [r3]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
	adds r0, r6, #0
	bl Div
	mov r8, r0
	lsls r4, r4, #8
	adds r4, #0x80
	mov r0, sp
	strh r4, [r0]
	adds r0, r6, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081BEA30
	adds r0, #4
	b _081BEA3C
	.align 2, 0
_081BEA20: .4byte 0x000006C1
_081BEA24: .4byte 0x000006B4
_081BEA28: .4byte 0x000006BA
_081BEA2C: .4byte 0x00000256
_081BEA30:
	mov r3, sl
	ldr r0, [r3]
	lsls r1, r6, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_081BEA3C:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	lsls r0, r0, #8
	mov r6, sb
	strh r0, [r6, #2]
	mov r1, r8
	lsls r0, r1, #8
	adds r0, #0x80
	strh r0, [r6, #4]
	mov r6, sp
	mov r0, sp
	bl GolemLink_SnapToTileCenter
	add r3, sp, #8
	adds r4, r5, #0
	adds r4, #8
	ldrh r0, [r5, #8]
	mov r1, sp
	ldrh r1, [r1]
	subs r0, r0, r1
	strh r0, [r3]
	ldrh r0, [r4, #2]
	ldrh r1, [r6, #2]
	subs r0, r0, r1
	strh r0, [r3, #2]
	ldrh r0, [r4, #4]
	ldrh r1, [r6, #4]
	subs r0, r0, r1
	strh r0, [r3, #4]
	movs r2, #0
	ldrsh r0, [r3, r2]
	adds r1, r0, #0
	muls r1, r0, r1
	movs r2, #4
	ldrsh r0, [r3, r2]
	adds r2, r0, #0
	muls r2, r0, r2
	adds r0, r2, #0
	adds r1, r1, r0
	ldr r0, _081BEA9C @ =0x000008FF
	cmp r1, r0
	bgt _081BEAA0
	adds r0, r7, #0
	bl GolemLink_RouteTo
	b _081BEAE6
	.align 2, 0
_081BEA9C: .4byte 0x000008FF
_081BEAA0:
	ldr r1, _081BEB34 @ =0x000004A4
	adds r0, r5, r1
	ldr r2, [r0]
	ldr r0, [sp]
	ldr r1, [sp, #4]
	str r0, [r2, #0x1c]
	str r1, [r2, #0x20]
	mov r0, sp
	ldrh r0, [r0]
	ldrh r1, [r5, #8]
	subs r0, r0, r1
	strh r0, [r3]
	ldrh r0, [r6, #2]
	ldrh r1, [r4, #2]
	subs r0, r0, r1
	strh r0, [r3, #2]
	ldrh r0, [r6, #4]
	ldrh r1, [r4, #4]
	subs r0, r0, r1
	strh r0, [r3, #4]
	movs r2, #0
	ldrsh r0, [r3, r2]
	movs r6, #4
	ldrsh r1, [r3, r6]
	bl ArcTan2_8
	adds r0, #0x20
	movs r1, #0xff
	ands r0, r1
	asrs r0, r0, #6
	lsls r0, r0, #6
	strb r0, [r5, #5]
	ldr r2, _081BEB38 @ =0x000006C2
	adds r1, r7, r2
	strb r0, [r1]
_081BEAE6:
	ldr r2, _081BEB3C @ =GolemLink_StateRoll
	movs r1, #0x22
	ldr r3, _081BEB40 @ =0x0000046D
	adds r0, r5, r3
	movs r3, #0
	movs r4, #1
	strb r4, [r0]
	ldr r6, _081BEB44 @ =0x0000046B
	adds r0, r5, r6
	strb r3, [r0]
	adds r6, #0xe8
	adds r0, r5, r6
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r5, r1
	str r2, [r0]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r0, r5, r2
	movs r1, #0
	strh r3, [r0]
	movs r2, #2
	subs r6, #0xeb
	adds r0, r5, r6
	strb r1, [r0]
	ldr r1, _081BEB48 @ =0x00000469
	adds r0, r5, r1
	strb r2, [r0]
	ldr r2, _081BEB4C @ =0x0000046A
	adds r0, r5, r2
	strb r4, [r0]
	adds r6, #0x1c
	adds r0, r5, r6
	str r3, [r0]
	adds r1, #3
	adds r0, r5, r1
	strb r4, [r0]
	b _081BEB5A
	.align 2, 0
_081BEB34: .4byte 0x000004A4
_081BEB38: .4byte 0x000006C2
_081BEB3C: .4byte GolemLink_StateRoll
_081BEB40: .4byte 0x0000046D
_081BEB44: .4byte 0x0000046B
_081BEB48: .4byte 0x00000469
_081BEB4C: .4byte 0x0000046A
_081BEB50:
	ldr r2, _081BEB6C @ =0x00000484
	adds r1, r5, r2
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_081BEB5A:
	add sp, #0x10
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081BEB6C: .4byte 0x00000484
