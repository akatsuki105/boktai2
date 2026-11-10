	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x7c
	adds r7, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r7, r1
	ldr r0, [r0]
	mov sl, r0
	movs r0, #0x9f
	lsls r0, r0, #1
	bl PlaySound_082406e0
	ldr r6, _0815F910 @ =0x00008004
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r5, r7, r2
	ldrh r3, [r5]
	adds r2, r3, #0
	ands r6, r2
	cmp r6, #0
	beq _0815F914
	movs r3, #0x99
	lsls r3, r3, #2
	adds r4, r7, r3
_0815F8F8:
	ldr r0, [r4]
	bl Entity081e9cacElem_Remove
	str r0, [r4]
	movs r0, #0x21
	rsbs r0, r0, #0
	ldrh r1, [r5]
	ands r0, r1
	strh r0, [r5]
	bl _081604B8
	.align 2, 0
_0815F910: .4byte 0x00008004
_0815F914:
	ldr r4, _0815FA70 @ =0x0000049C
	adds r0, r7, r4
	ldr r1, [r0]
	movs r0, #0x80
	lsls r0, r0, #7
	ands r0, r1
	cmp r0, #0
	bne _0815F926
	b _0815FAB4
_0815F926:
	movs r0, #4
	movs r1, #0
	mov r8, r1
	orrs r0, r3
	ldr r1, _0815FA74 @ =0xFFFFE854
	ands r0, r1
	strh r0, [r5]
	ldr r2, _0815FA78 @ =0x00000482
	adds r1, r7, r2
	movs r0, #1
	strh r0, [r1]
	ldr r3, _0815FA7C @ =0x00000222
	adds r0, r7, r3
	strh r6, [r0]
	ldr r4, _0815FA80 @ =0x0000024E
	adds r0, r7, r4
	strh r6, [r0]
	ldr r0, _0815FA84 @ =0xFFFFFC7F
	ldrh r1, [r5]
	ands r0, r1
	strh r0, [r5]
	movs r0, #0xbc
	lsls r0, r0, #1
	adds r2, r7, r0
	ldr r1, _0815FA88 @ =0xF3FFFFFF
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	movs r1, #0x80
	lsls r1, r1, #0xe
	ands r0, r1
	movs r1, #0xbe
	lsls r1, r1, #1
	adds r1, r1, r7
	mov sb, r1
	cmp r0, #0
	beq _0815F996
	ldr r1, _0815FA8C @ =0xFEFFFFFF
	mov r3, sb
	ldr r0, [r3]
	ands r0, r1
	str r0, [r3]
	ldr r0, _0815FA90 @ =0xFFFFFDFF
	ldrh r1, [r5]
	ands r0, r1
	strh r0, [r5]
	subs r4, #0x32
	adds r0, r7, r4
	mov r1, r8
	strb r1, [r0]
	ldr r3, _0815FA94 @ =0x0000021E
	adds r0, r7, r3
	strh r6, [r0]
	subs r4, #0x1a
	adds r0, r7, r4
	strh r6, [r0]
_0815F996:
	ldr r0, _0815FA98 @ =0xFFFFFBFF
	ldrh r1, [r5]
	ands r0, r1
	strh r0, [r5]
	ldr r0, _0815FA9C @ =0x00000542
	adds r1, r7, r0
	movs r0, #0xff
	strb r0, [r1]
	movs r1, #0x81
	rsbs r1, r1, #0
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	movs r1, #0x99
	lsls r1, r1, #2
	adds r4, r7, r1
	ldr r0, [r4]
	bl Entity081e9cacElem_Remove
	str r0, [r4]
	movs r0, #0x9f
	lsls r0, r0, #1
	bl PlaySound_082406e0
	ldr r2, _0815FAA0 @ =Cockatrice_StateStunned
	movs r1, #0x2e
	ldr r3, _0815FAA4 @ =0x0000046D
	adds r0, r7, r3
	movs r4, #1
	strb r4, [r0]
	subs r3, #2
	adds r0, r7, r3
	mov r4, r8
	strb r4, [r0]
	adds r3, #0xe8
	adds r0, r7, r3
	strb r1, [r0]
	movs r4, #0xaf
	lsls r4, r4, #3
	adds r0, r7, r4
	str r2, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r0, r7, r1
	strh r6, [r0]
	movs r1, #3
	movs r2, #0x8d
	lsls r2, r2, #3
	adds r0, r7, r2
	strb r1, [r0]
	subs r3, #0xea
	adds r0, r7, r3
	mov r4, r8
	strb r4, [r0]
	ldr r1, _0815FAA8 @ =0x0000046A
	adds r0, r7, r1
	strb r4, [r0]
	adds r2, #0x1c
	adds r0, r7, r2
	str r6, [r0]
	adds r3, #3
	adds r0, r7, r3
	movs r4, #1
	strb r4, [r0]
	ldr r0, _0815FAAC @ =0x000006DC
	add r0, sl
	strh r6, [r0]
	movs r2, #0xe0
	lsls r2, r2, #3
	add r2, sl
	ldr r1, _0815FAB0 @ =0xFFFFFF00
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	adds r0, r7, #0
	movs r1, #0
	movs r2, #0x7f
	movs r3, #0
	bl Enemy_SetEmote
	adds r0, r7, #0
	movs r1, #1
	movs r2, #0x7f
	movs r3, #0
	bl Enemy_SetEmote
	adds r0, r7, #0
	movs r1, #3
	movs r2, #0x7f
	movs r3, #0
	bl Enemy_SetEmote
	movs r1, #3
	rsbs r1, r1, #0
	mov r6, sb
	ldr r0, [r6]
	ands r0, r1
	ldr r1, _0815FA8C @ =0xFEFFFFFF
	ands r0, r1
	str r0, [r6]
	movs r0, #0x21
	rsbs r0, r0, #0
	ldrh r1, [r5]
	ands r0, r1
	strh r0, [r5]
	movs r0, #1
	bl _081604BA
	.align 2, 0
_0815FA70: .4byte 0x0000049C
_0815FA74: .4byte 0xFFFFE854
_0815FA78: .4byte 0x00000482
_0815FA7C: .4byte 0x00000222
_0815FA80: .4byte 0x0000024E
_0815FA84: .4byte 0xFFFFFC7F
_0815FA88: .4byte 0xF3FFFFFF
_0815FA8C: .4byte 0xFEFFFFFF
_0815FA90: .4byte 0xFFFFFDFF
_0815FA94: .4byte 0x0000021E
_0815FA98: .4byte 0xFFFFFBFF
_0815FA9C: .4byte 0x00000542
_0815FAA0: .4byte Cockatrice_StateStunned
_0815FAA4: .4byte 0x0000046D
_0815FAA8: .4byte 0x0000046A
_0815FAAC: .4byte 0x000006DC
_0815FAB0: .4byte 0xFFFFFF00
_0815FAB4:
	movs r4, #2
	adds r0, r2, #0
	ands r0, r4
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	cmp r6, #0
	beq _0815FACA
	movs r0, #0x99
	lsls r0, r0, #2
	adds r4, r7, r0
	b _0815F8F8
_0815FACA:
	movs r0, #0xc0
	lsls r0, r0, #0xc
	ands r1, r0
	cmp r1, #0
	beq _0815FB7C
	movs r1, #0x99
	lsls r1, r1, #2
	adds r4, r7, r1
	ldr r0, [r4]
	bl Entity081e9cacElem_Remove
	str r0, [r4]
	ldr r2, _0815FB58 @ =0x000005CC
	adds r0, r7, r2
	ldr r2, [r0]
	movs r1, #0x12
	ldr r3, _0815FB5C @ =0x0000046D
	adds r0, r7, r3
	movs r3, #1
	strb r3, [r0]
	ldr r4, _0815FB60 @ =0x0000046B
	adds r0, r7, r4
	strb r6, [r0]
	ldr r5, _0815FB64 @ =0x00000553
	adds r0, r7, r5
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r7, r1
	str r2, [r0]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r0, r7, r2
	movs r2, #0
	strh r6, [r0]
	movs r1, #3
	subs r4, #3
	adds r0, r7, r4
	strb r1, [r0]
	subs r5, #0xea
	adds r0, r7, r5
	strb r2, [r0]
	ldr r1, _0815FB68 @ =0x0000046A
	adds r0, r7, r1
	strb r2, [r0]
	ldr r2, _0815FB6C @ =0x00000484
	adds r0, r7, r2
	str r6, [r0]
	adds r4, #4
	adds r0, r7, r4
	strb r3, [r0]
	ldr r0, _0815FB70 @ =0x000006DC
	add r0, sl
	strh r6, [r0]
	movs r2, #0xe0
	lsls r2, r2, #3
	add r2, sl
	ldr r1, _0815FB74 @ =0xFFFFFF00
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	movs r5, #0xbe
	lsls r5, r5, #1
	adds r2, r7, r5
	ldr r1, _0815FB78 @ =0xFEFFFFFF
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	movs r0, #1
	bl _081604BA
	.align 2, 0
_0815FB58: .4byte 0x000005CC
_0815FB5C: .4byte 0x0000046D
_0815FB60: .4byte 0x0000046B
_0815FB64: .4byte 0x00000553
_0815FB68: .4byte 0x0000046A
_0815FB6C: .4byte 0x00000484
_0815FB70: .4byte 0x000006DC
_0815FB74: .4byte 0xFFFFFF00
_0815FB78: .4byte 0xFEFFFFFF
_0815FB7C:
	movs r0, #0x80
	lsls r0, r0, #1
	ands r2, r0
	cmp r2, #0
	bne _0815FB90
	ldr r6, _0815FB9C @ =0x000004BE
	adds r0, r7, r6
	ldrh r0, [r0]
	cmp r0, #0
	beq _0815FBA0
_0815FB90:
	movs r0, #0x21
	rsbs r0, r0, #0
	ands r0, r3
	strh r0, [r5]
	bl _081604B8
	.align 2, 0
_0815FB9C: .4byte 0x000004BE
_0815FBA0:
	movs r1, #0xe0
	lsls r1, r1, #3
	add r1, sl
	ldr r0, [r1]
	ands r0, r4
	adds r6, r1, #0
	cmp r0, #0
	beq _0815FBB4
	movs r0, #1
	b _0815FBB6
_0815FBB4:
	movs r0, #0
_0815FBB6:
	cmp r0, #0
	beq _0815FC68
	movs r0, #0xc1
	lsls r0, r0, #1
	adds r4, r7, r0
	ldr r1, _0815FC48 @ =0xFFFFF636
	ldrh r0, [r4]
	ands r1, r0
	movs r2, #0
	movs r3, #0
	strh r1, [r4]
	ldr r1, _0815FC4C @ =0x000005CC
	adds r0, r7, r1
	ldr r0, [r0]
	mov r8, r0
	movs r1, #0x12
	ldr r4, _0815FC50 @ =0x0000046D
	adds r0, r7, r4
	movs r5, #1
	strb r5, [r0]
	subs r4, #2
	adds r0, r7, r4
	strb r2, [r0]
	adds r4, #0xe8
	adds r0, r7, r4
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r7, r1
	mov r4, r8
	str r4, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r0, r7, r1
	strh r3, [r0]
	movs r1, #3
	movs r4, #0x8d
	lsls r4, r4, #3
	adds r0, r7, r4
	strb r1, [r0]
	ldr r1, _0815FC54 @ =0x00000469
	adds r0, r7, r1
	strb r2, [r0]
	adds r4, #2
	adds r0, r7, r4
	strb r2, [r0]
	adds r1, #0x1b
	adds r0, r7, r1
	str r3, [r0]
	ldr r2, _0815FC58 @ =0x0000046C
	adds r0, r7, r2
	strb r5, [r0]
	ldr r0, _0815FC5C @ =0x000006DC
	add r0, sl
	strh r3, [r0]
	ldr r1, _0815FC60 @ =0xFFFFFF00
	ldr r0, [r6]
	ands r0, r1
	str r0, [r6]
	movs r3, #0xbe
	lsls r3, r3, #1
	adds r2, r7, r3
	ldr r1, _0815FC64 @ =0xFEFFFFFF
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	adds r0, r7, #0
	bl Cockatrice_StartFlee
	movs r0, #1
	bl _081604BA
	.align 2, 0
_0815FC48: .4byte 0xFFFFF636
_0815FC4C: .4byte 0x000005CC
_0815FC50: .4byte 0x0000046D
_0815FC54: .4byte 0x00000469
_0815FC58: .4byte 0x0000046C
_0815FC5C: .4byte 0x000006DC
_0815FC60: .4byte 0xFFFFFF00
_0815FC64: .4byte 0xFEFFFFFF
_0815FC68:
	movs r4, #0xc0
	lsls r4, r4, #1
	adds r2, r7, r4
	movs r0, #0x21
	rsbs r0, r0, #0
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	ldr r5, _0815FD40 @ =0x0000048D
	adds r3, r7, r5
	ldrb r0, [r3]
	str r2, [sp, #0x48]
	cmp r0, #0
	bne _0815FCA6
	ldr r1, _0815FD44 @ =0x0000048C
	adds r0, r7, r1
	ldrb r1, [r0]
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	beq _0815FCA6
	ldr r2, _0815FD48 @ =0x000004BE
	adds r0, r7, r2
	movs r1, #0x2d
	strh r1, [r0]
	movs r0, #0x41
	strb r0, [r3]
	adds r0, r7, #0
	movs r1, #3
	bl Enemy_PlayAnim
_0815FCA6:
	ldr r3, _0815FD4C @ =0x00000544
	adds r1, r7, r3
	movs r0, #0x96
	lsls r0, r0, #1
	strh r0, [r1]
	movs r5, #0x80
	ldr r4, [sp, #0x48]
	ldrh r0, [r4]
	ands r0, r5
	cmp r0, #0
	bne _0815FCBE
	b _08160428
_0815FCBE:
	movs r6, #0x99
	lsls r6, r6, #2
	adds r4, r7, r6
	ldr r0, [r4]
	bl Entity081e9cacElem_Remove
	str r0, [r4]
	movs r0, #0xec
	lsls r0, r0, #1
	adds r2, r7, r0
	ldr r0, [r2]
	cmp r0, #0
	bne _0815FCDC
	bl _081604B8
_0815FCDC:
	movs r3, #0xbc
	lsls r3, r3, #1
	adds r1, r7, r3
	ldr r0, [r1]
	orrs r0, r5
	str r0, [r1]
	movs r0, #4
	ldr r4, _0815FD50 @ =0x00000222
	adds r3, r7, r4
	ldrh r1, [r3]
	orrs r0, r1
	strh r0, [r3]
	ldr r0, _0815FD54 @ =0x03002BE0
	ldr r0, [r0]
	adds r0, #0x24
	str r0, [r2]
	movs r5, #0x95
	lsls r5, r5, #3
	adds r4, r7, r5
	ldr r6, [r4]
	adds r2, r7, #0
	adds r2, #0x9c
	ldr r0, [r2, #8]
	ldrh r1, [r0]
	strh r1, [r6]
	ldr r0, [r2, #8]
	ldrh r0, [r0, #2]
	strh r0, [r6, #4]
	lsls r1, r1, #0x10
	asrs r5, r1, #0x18
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	str r3, [sp, #0x50]
	str r4, [sp, #0x74]
	str r2, [sp, #0x24]
	cmp r5, #0
	blt _0815FD3A
	cmp r1, #0
	blt _0815FD3A
	ldr r0, _0815FD58 @ =0x030046A8
	ldr r0, [r0]
	cmp r5, r0
	bhs _0815FD3A
	ldr r0, _0815FD5C @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0815FD60
_0815FD3A:
	movs r4, #0
	b _0815FD6E
	.align 2, 0
_0815FD40: .4byte 0x0000048D
_0815FD44: .4byte 0x0000048C
_0815FD48: .4byte 0x000004BE
_0815FD4C: .4byte 0x00000544
_0815FD50: .4byte 0x00000222
_0815FD54: .4byte 0x03002BE0
_0815FD58: .4byte 0x030046A8
_0815FD5C: .4byte 0x030046AC
_0815FD60:
	ldr r0, _0815FD80 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r5
_0815FD6E:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _0815FD84
	adds r0, #4
	b _0815FD90
	.align 2, 0
_0815FD80: .4byte 0x030046A4
_0815FD84:
	ldr r0, _0815FDA4 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0815FD90:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _0815FDA8
	cmp r2, #2
	beq _0815FDAC
	b _0815FDB0
	.align 2, 0
_0815FDA4: .4byte 0x030046A4
_0815FDA8:
	ldrb r0, [r6, #4]
	b _0815FDAE
_0815FDAC:
	ldrb r0, [r6]
_0815FDAE:
	subs r1, r1, r0
_0815FDB0:
	strh r1, [r6, #2]
	ldr r0, _0815FDC4 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _0815FDC8
	movs r0, #1
	b _0815FDCA
	.align 2, 0
_0815FDC4: .4byte 0x030047A4
_0815FDC8:
	movs r0, #0
_0815FDCA:
	cmp r0, #0
	beq _0815FE08
	movs r6, #0xec
	lsls r6, r6, #1
	adds r0, r7, r6
	ldr r1, [r0]
	cmp r1, #0
	beq _0815FDEA
	ldrb r0, [r1, #4]
	movs r2, #1
	rsbs r2, r2, #0
	cmp r0, #3
	bhi _0815FDE6
	adds r2, r0, #0
_0815FDE6:
	cmp r2, #0
	bge _0815FDF4
_0815FDEA:
	ldr r1, _0815FDF0 @ =0x000005C4
	adds r0, r7, r1
	b _08160324
	.align 2, 0
_0815FDF0: .4byte 0x000005C4
_0815FDF4:
	ldr r1, _0815FE04 @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r0, [r0, #0x3c]
	ldrh r5, [r0, #6]
	b _0815FE50
	.align 2, 0
_0815FE04: .4byte 0x03002BE0
_0815FE08:
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
	blt _0815FE34
	cmp r1, #0
	blt _0815FE34
	ldr r0, _0815FE38 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _0815FE34
	ldr r0, _0815FE3C @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0815FE40
_0815FE34:
	movs r5, #0
	b _0815FE4E
	.align 2, 0
_0815FE38: .4byte 0x030046A8
_0815FE3C: .4byte 0x030046AC
_0815FE40:
	ldr r0, _0815FE88 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r5, r0, r2
_0815FE4E:
	movs r2, #0
_0815FE50:
	ldr r3, _0815FE8C @ =0x00000256
	adds r0, r7, r3
	ldrh r0, [r0]
	cmp r5, r0
	beq _0815FE70
	ldr r1, _0815FE90 @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #0xa
	ldr r0, [r0, #0x20]
	ands r0, r1
	cmp r0, #0
	bne _0815FE70
	b _08160264
_0815FE70:
	movs r1, #0x80
	lsls r1, r1, #3
	ldr r4, [sp, #0x48]
	ldrh r0, [r4]
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov sb, r0
	cmp r0, #0
	beq _0815FE94
	movs r0, #0
	b _0816033A
	.align 2, 0
_0815FE88: .4byte 0x030046A4
_0815FE8C: .4byte 0x00000256
_0815FE90: .4byte 0x03002BE0
_0815FE94:
	movs r0, #5
	rsbs r0, r0, #0
	ldr r5, [sp, #0x50]
	ldrh r1, [r5]
	ands r0, r1
	strh r0, [r5]
	movs r1, #0x80
	ldr r6, [sp, #0x48]
	ldrh r0, [r6]
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	cmp r2, #0
	beq _0815FF4C
	movs r1, #0xb7
	lsls r1, r1, #3
	adds r0, r7, r1
	ldr r1, [r0]
	movs r0, #0x1a
	ldr r2, _0815FF30 @ =0x0000046D
	adds r2, r2, r7
	mov sl, r2
	movs r3, #1
	strb r3, [r2]
	ldr r4, _0815FF34 @ =0x0000046B
	adds r4, r7, r4
	str r4, [sp, #8]
	movs r5, #0
	strb r5, [r4]
	ldr r6, _0815FF38 @ =0x00000553
	adds r6, r6, r7
	mov r8, r6
	strb r0, [r6]
	movs r0, #0xaf
	lsls r0, r0, #3
	adds r0, r7, r0
	str r0, [sp, #0x78]
	str r1, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r5, r7, r1
	mov r2, sb
	strh r2, [r5]
	movs r0, #0xc
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r4, r7, r3
	movs r6, #0
	strb r6, [r4]
	ldr r1, _0815FF3C @ =0x00000469
	adds r3, r7, r1
	strb r6, [r3]
	ldr r6, _0815FF40 @ =0x0000046A
	adds r2, r7, r6
	strb r0, [r2]
	ldr r0, _0815FF44 @ =0x00000484
	adds r1, r7, r0
	mov r6, sb
	str r6, [r1]
	ldr r6, _0815FF48 @ =0x0000046C
	adds r0, r7, r6
	movs r6, #1
	strb r6, [r0]
	mov r6, sl
	str r6, [sp, #0x68]
	ldr r6, [sp, #8]
	str r6, [sp, #0x60]
	mov r6, r8
	str r6, [sp, #0x3c]
	ldr r6, [sp, #0x78]
	str r6, [sp, #0x40]
	str r5, [sp, #0x4c]
	str r4, [sp, #0x54]
	str r3, [sp, #0x58]
	str r2, [sp, #0x5c]
	str r1, [sp, #0x70]
	str r0, [sp, #0x64]
	b _0816011A
	.align 2, 0
_0815FF30: .4byte 0x0000046D
_0815FF34: .4byte 0x0000046B
_0815FF38: .4byte 0x00000553
_0815FF3C: .4byte 0x00000469
_0815FF40: .4byte 0x0000046A
_0815FF44: .4byte 0x00000484
_0815FF48: .4byte 0x0000046C
_0815FF4C:
	movs r1, #0xb4
	lsls r1, r1, #3
	adds r0, r7, r1
	ldr r1, [r0]
	movs r0, #1
	ldr r3, _0816000C @ =0x0000046D
	adds r3, r7, r3
	str r3, [sp, #0xc]
	strb r0, [r3]
	ldr r4, _08160010 @ =0x0000046B
	adds r4, r7, r4
	str r4, [sp, #0x10]
	movs r5, #0
	strb r5, [r4]
	ldr r6, _08160014 @ =0x00000553
	adds r6, r7, r6
	str r6, [sp, #0x14]
	strb r0, [r6]
	movs r3, #0xaf
	lsls r3, r3, #3
	adds r3, r7, r3
	str r3, [sp, #0x18]
	str r1, [r3]
	movs r4, #0xe4
	lsls r4, r4, #1
	adds r4, r4, r7
	mov r8, r4
	strh r2, [r4]
	movs r1, #5
	movs r5, #0x8d
	lsls r5, r5, #3
	adds r5, r7, r5
	str r5, [sp, #0x78]
	movs r6, #0
	strb r6, [r5]
	ldr r3, _08160018 @ =0x00000469
	adds r5, r7, r3
	strb r6, [r5]
	ldr r6, _0816001C @ =0x0000046A
	adds r4, r7, r6
	strb r1, [r4]
	ldr r1, _08160020 @ =0x00000484
	adds r3, r7, r1
	str r2, [r3]
	adds r6, #2
	adds r2, r7, r6
	strb r0, [r2]
	ldr r0, [sp, #0x74]
	ldr r0, [r0]
	str r0, [sp, #0x1c]
	ldr r1, [sp, #0x24]
	ldr r0, [r1, #8]
	ldrh r1, [r0]
	ldr r6, [sp, #0x1c]
	strh r1, [r6]
	ldr r6, [sp, #0x24]
	ldr r0, [r6, #8]
	ldrh r0, [r0, #2]
	ldr r6, [sp, #0x1c]
	strh r0, [r6, #4]
	lsls r1, r1, #0x10
	asrs r1, r1, #0x18
	mov ip, r1
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	ldr r0, [sp, #0xc]
	str r0, [sp, #0x68]
	ldr r6, [sp, #0x10]
	str r6, [sp, #0x60]
	ldr r0, [sp, #0x14]
	str r0, [sp, #0x3c]
	ldr r6, [sp, #0x18]
	str r6, [sp, #0x40]
	mov r0, r8
	str r0, [sp, #0x4c]
	ldr r6, [sp, #0x78]
	str r6, [sp, #0x54]
	str r5, [sp, #0x58]
	str r4, [sp, #0x5c]
	str r3, [sp, #0x70]
	str r2, [sp, #0x64]
	mov r0, ip
	cmp r0, #0
	blt _08160008
	cmp r1, #0
	blt _08160008
	ldr r0, _08160024 @ =0x030046A8
	ldr r0, [r0]
	cmp ip, r0
	bhs _08160008
	ldr r0, _08160028 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0816002C
_08160008:
	movs r4, #0
	b _0816003C
	.align 2, 0
_0816000C: .4byte 0x0000046D
_08160010: .4byte 0x0000046B
_08160014: .4byte 0x00000553
_08160018: .4byte 0x00000469
_0816001C: .4byte 0x0000046A
_08160020: .4byte 0x00000484
_08160024: .4byte 0x030046A8
_08160028: .4byte 0x030046AC
_0816002C:
	ldr r0, _0816004C @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	mov r1, ip
	adds r4, r0, r1
_0816003C:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _08160050
	adds r0, #4
	b _0816005C
	.align 2, 0
_0816004C: .4byte 0x030046A4
_08160050:
	ldr r0, _08160070 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0816005C:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _08160074
	cmp r2, #2
	beq _0816007A
	b _08160080
	.align 2, 0
_08160070: .4byte 0x030046A4
_08160074:
	ldr r2, [sp, #0x1c]
	ldrb r0, [r2, #4]
	b _0816007E
_0816007A:
	ldr r3, [sp, #0x1c]
	ldrb r0, [r3]
_0816007E:
	subs r1, r1, r0
_08160080:
	ldr r4, [sp, #0x1c]
	strh r1, [r4, #2]
	ldr r5, [sp, #0x74]
	ldr r0, [r5]
	ldrh r1, [r0]
	lsls r1, r1, #0x10
	asrs r2, r1, #0x18
	ldrh r0, [r0, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _081600AC
	cmp r1, #0
	blt _081600AC
	ldr r0, _081600B0 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081600AC
	ldr r0, _081600B4 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081600B8
_081600AC:
	movs r4, #0
	b _081600C6
	.align 2, 0
_081600B0: .4byte 0x030046A8
_081600B4: .4byte 0x030046AC
_081600B8:
	ldr r0, _081600DC @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_081600C6:
	ldr r6, [sp, #0x74]
	ldr r5, [r6]
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081600E0
	adds r0, #4
	b _081600EC
	.align 2, 0
_081600DC: .4byte 0x030046A4
_081600E0:
	ldr r0, _08160100 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081600EC:
	ldrb r1, [r0]
	lsrs r3, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r2, r0, #8
	cmp r3, #1
	beq _08160104
	cmp r3, #2
	beq _08160108
	b _0816010C
	.align 2, 0
_08160100: .4byte 0x030046A4
_08160104:
	ldrb r0, [r5, #4]
	b _0816010A
_08160108:
	ldrb r0, [r5]
_0816010A:
	subs r2, r2, r0
_0816010C:
	ldr r1, [sp, #0x74]
	ldr r0, [r1]
	movs r1, #0
	strh r2, [r0, #2]
	ldr r2, [sp, #0x74]
	ldr r0, [r2]
	strh r1, [r0, #6]
_0816011A:
	ldrb r3, [r7, #5]
	str r3, [sp, #0x20]
	movs r1, #0x80
	lsls r1, r1, #3
	ldr r4, [sp, #0x48]
	ldrh r0, [r4]
	ands r0, r1
	ldr r5, _08160144 @ =0x00000482
	adds r5, r7, r5
	str r5, [sp, #0x6c]
	mov sb, r3
	cmp r0, #0
	bne _08160228
	movs r1, #4
	ldr r6, [sp, #0x50]
	ldrh r0, [r6]
	ands r0, r1
	cmp r0, #0
	beq _08160148
	movs r0, #1
	b _0816014A
	.align 2, 0
_08160144: .4byte 0x00000482
_08160148:
	movs r0, #0
_0816014A:
	ldr r1, _08160238 @ =0x00000482
	adds r1, r7, r1
	str r1, [sp, #0x6c]
	cmp r0, #0
	bne _08160228
	movs r3, #0
	ldr r2, _0816023C @ =0x00000542
	adds r2, r7, r2
	str r2, [sp, #0x2c]
	movs r4, #0xa8
	lsls r4, r4, #3
	adds r4, r4, r7
	mov r8, r4
	movs r5, #0xa9
	lsls r5, r5, #3
	adds r5, r5, r7
	mov sl, r5
	ldr r6, _08160240 @ =0x0000054F
	adds r6, r6, r7
	mov ip, r6
	ldr r0, _08160244 @ =0x0000054C
	adds r0, r7, r0
	str r0, [sp, #0x30]
	ldr r1, _08160248 @ =0x0000054D
	adds r1, r7, r1
	str r1, [sp, #0x34]
	ldr r2, _0816024C @ =0x0000054E
	adds r2, r7, r2
	str r2, [sp, #0x38]
	ldr r4, _08160250 @ =0x00000541
	adds r4, r7, r4
	str r4, [sp, #0x28]
	ldr r5, _08160254 @ =0x000005BC
	adds r5, r7, r5
	str r5, [sp, #0x44]
	ldr r6, _08160258 @ =0x0203B400
	ldr r1, _0816025C @ =0x030046B8
	ldr r5, _08160260 @ =0x000003FF
	movs r4, #3
	mov r2, sb
_0816019A:
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
	bne _081601B8
	adds r3, #1
	cmp r3, #3
	ble _0816019A
	mov r0, sb
_081601B8:
	movs r3, #0
	mov r6, r8
	strb r0, [r6]
	ldr r1, [sp, #0x40]
	ldr r0, [r1]
	mov r2, sl
	str r0, [r2]
	ldr r4, [sp, #0x3c]
	ldrb r0, [r4]
	mov r5, ip
	strb r0, [r5]
	ldr r6, [sp, #0x54]
	ldrb r0, [r6]
	ldr r1, [sp, #0x30]
	strb r0, [r1]
	ldr r2, [sp, #0x58]
	ldrb r0, [r2]
	ldr r4, [sp, #0x34]
	strb r0, [r4]
	ldr r5, [sp, #0x5c]
	ldrb r0, [r5]
	ldr r6, [sp, #0x38]
	strb r0, [r6]
	add r0, sp, #0x20
	ldrb r1, [r0]
	ldr r0, [sp, #0x28]
	strb r1, [r0]
	ldr r1, [sp, #0x44]
	ldr r2, [r1]
	movs r0, #0x1b
	movs r1, #1
	ldr r4, [sp, #0x68]
	strb r1, [r4]
	ldr r5, [sp, #0x60]
	strb r3, [r5]
	ldr r6, [sp, #0x3c]
	strb r0, [r6]
	ldr r0, [sp, #0x40]
	str r2, [r0]
	movs r2, #0
	ldr r4, [sp, #0x4c]
	strh r3, [r4]
	movs r0, #3
	ldr r5, [sp, #0x54]
	strb r0, [r5]
	ldr r6, [sp, #0x58]
	strb r1, [r6]
	ldr r0, [sp, #0x5c]
	strb r2, [r0]
	ldr r2, [sp, #0x70]
	str r3, [r2]
	ldr r3, [sp, #0x64]
	strb r1, [r3]
	movs r0, #6
	ldr r4, [sp, #0x2c]
	strb r0, [r4]
_08160228:
	adds r0, r7, #0
	bl Enemy_StepToFloorEdge
	movs r0, #2
	ldr r5, [sp, #0x6c]
	strh r0, [r5]
	movs r0, #0
	b _0816033A
	.align 2, 0
_08160238: .4byte 0x00000482
_0816023C: .4byte 0x00000542
_08160240: .4byte 0x0000054F
_08160244: .4byte 0x0000054C
_08160248: .4byte 0x0000054D
_0816024C: .4byte 0x0000054E
_08160250: .4byte 0x00000541
_08160254: .4byte 0x000005BC
_08160258: .4byte 0x0203B400
_0816025C: .4byte 0x030046B8
_08160260: .4byte 0x000003FF
_08160264:
	mov sb, sp
	ldr r6, _081602A0 @ =0x030046A4
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
	beq _081602A4
	adds r0, #4
	b _081602AE
	.align 2, 0
_081602A0: .4byte 0x030046A4
_081602A4:
	ldr r0, [r6]
	lsls r1, r5, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_081602AE:
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
	ldr r6, _081602E8 @ =0x000004A4
	adds r0, r7, r6
	ldr r4, [r0]
	adds r5, r7, #0
	adds r5, #8
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sp
	bl Map_IsPosInAgentIsland
	cmp r0, #0
	bne _081602F0
	ldr r0, _081602EC @ =0xFFFFFDFF
	ldr r2, [sp, #0x48]
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	b _0816031A
	.align 2, 0
_081602E8: .4byte 0x000004A4
_081602EC: .4byte 0xFFFFFDFF
_081602F0:
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sp
	bl Map_TryFindNavRoute
	cmp r0, #0
	beq _08160310
	cmp r0, #2
	beq _0816030C
	adds r0, r7, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_0816030C:
	movs r0, #1
	b _0816031C
_08160310:
	ldr r0, _08160330 @ =0xFFFFFDFF
	ldr r3, [sp, #0x48]
	ldrh r1, [r3]
	ands r0, r1
	strh r0, [r3]
_0816031A:
	movs r0, #0
_0816031C:
	cmp r0, #0
	bne _08160338
	ldr r4, _08160334 @ =0x000005C4
	adds r0, r7, r4
_08160324:
	ldr r1, [r0]
	adds r0, r7, #0
	bl _call_via_r1
	movs r0, #0
	b _0816033A
	.align 2, 0
_08160330: .4byte 0xFFFFFDFF
_08160334: .4byte 0x000005C4
_08160338:
	movs r0, #1
_0816033A:
	cmp r0, #0
	bne _081603C0
	ldr r5, _08160370 @ =0x000004A4
	adds r0, r7, r5
	ldr r5, [r0]
	adds r6, r7, #0
	adds r6, #8
	movs r1, #0xec
	lsls r1, r1, #1
	adds r0, r7, r1
	ldr r0, [r0]
	adds r4, r0, #0
	adds r4, #8
	adds r0, r5, #0
	adds r1, r6, #0
	adds r2, r4, #0
	bl Map_IsPosInAgentIsland
	cmp r0, #0
	bne _08160378
	ldr r0, _08160374 @ =0xFFFFFDFF
	ldr r2, [sp, #0x48]
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	b _081603A2
	.align 2, 0
_08160370: .4byte 0x000004A4
_08160374: .4byte 0xFFFFFDFF
_08160378:
	adds r0, r5, #0
	adds r1, r6, #0
	adds r2, r4, #0
	bl Map_TryFindNavRoute
	cmp r0, #0
	beq _08160398
	cmp r0, #2
	beq _08160394
	adds r0, r7, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_08160394:
	movs r0, #1
	b _081603A4
_08160398:
	ldr r0, _081603B8 @ =0xFFFFFDFF
	ldr r3, [sp, #0x48]
	ldrh r1, [r3]
	ands r0, r1
	strh r0, [r3]
_081603A2:
	movs r0, #0
_081603A4:
	cmp r0, #0
	bne _081603C0
	ldr r4, _081603BC @ =0x000005C4
	adds r0, r7, r4
	ldr r1, [r0]
	adds r0, r7, #0
	bl _call_via_r1
	b _081604B8
	.align 2, 0
_081603B8: .4byte 0xFFFFFDFF
_081603BC: .4byte 0x000005C4
_081603C0:
	movs r5, #0xb7
	lsls r5, r5, #3
	adds r0, r7, r5
	ldr r3, [r0]
	movs r1, #0x1a
	ldr r6, _08160418 @ =0x0000046D
	adds r0, r7, r6
	movs r2, #0
	movs r4, #1
	strb r4, [r0]
	ldr r5, _0816041C @ =0x0000046B
	adds r0, r7, r5
	strb r2, [r0]
	adds r6, #0xe6
	adds r0, r7, r6
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r7, r1
	str r3, [r0]
	movs r3, #0xe4
	lsls r3, r3, #1
	adds r0, r7, r3
	movs r1, #0
	strh r2, [r0]
	movs r3, #0xc
	subs r5, #3
	adds r0, r7, r5
	strb r1, [r0]
	subs r6, #0xea
	adds r0, r7, r6
	strb r1, [r0]
	ldr r1, _08160420 @ =0x0000046A
	adds r0, r7, r1
	strb r3, [r0]
	ldr r3, _08160424 @ =0x00000484
	adds r0, r7, r3
	str r2, [r0]
	adds r5, #4
	adds r0, r7, r5
	strb r4, [r0]
	movs r0, #1
	b _081604BA
	.align 2, 0
_08160418: .4byte 0x0000046D
_0816041C: .4byte 0x0000046B
_08160420: .4byte 0x0000046A
_08160424: .4byte 0x00000484
_08160428:
	movs r1, #0x20
	ldr r0, [r6]
	ands r0, r1
	cmp r0, #0
	beq _08160436
	movs r0, #1
	b _08160438
_08160436:
	movs r0, #0
_08160438:
	adds r5, r0, #0
	cmp r5, #0
	bne _081604B8
	movs r6, #0x99
	lsls r6, r6, #2
	adds r4, r7, r6
	ldr r0, [r4]
	bl Entity081e9cacElem_Remove
	str r0, [r4]
	adds r0, r7, #0
	bl Cockatrice_StartFlee
	ldr r2, _081604A0 @ =Cockatrice_StateFlee
	movs r1, #0x34
	ldr r3, _081604A4 @ =0x0000046D
	adds r0, r7, r3
	movs r3, #1
	strb r3, [r0]
	ldr r4, _081604A8 @ =0x0000046B
	adds r0, r7, r4
	strb r5, [r0]
	ldr r6, _081604AC @ =0x00000553
	adds r0, r7, r6
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r7, r1
	str r2, [r0]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r0, r7, r2
	movs r1, #0
	strh r5, [r0]
	movs r2, #0x13
	subs r4, #3
	adds r0, r7, r4
	strb r1, [r0]
	subs r6, #0xea
	adds r0, r7, r6
	strb r1, [r0]
	ldr r1, _081604B0 @ =0x0000046A
	adds r0, r7, r1
	strb r2, [r0]
	ldr r2, _081604B4 @ =0x00000484
	adds r0, r7, r2
	str r5, [r0]
	adds r4, #4
	adds r0, r7, r4
	strb r3, [r0]
	movs r0, #1
	b _081604BA
	.align 2, 0
_081604A0: .4byte Cockatrice_StateFlee
_081604A4: .4byte 0x0000046D
_081604A8: .4byte 0x0000046B
_081604AC: .4byte 0x00000553
_081604B0: .4byte 0x0000046A
_081604B4: .4byte 0x00000484
_081604B8:
	movs r0, #0
_081604BA:
	add sp, #0x7c
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
