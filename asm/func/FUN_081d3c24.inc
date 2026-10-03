	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0x10
	mov r8, r0
	movs r0, #1
	bl FUN_08086978
	cmp r0, #0
	bne _081D3C3C
	b _081D3DC0
_081D3C3C:
	movs r2, #0x10
	mov r1, r8
	adds r1, #0xb4
	ldrh r0, [r1]
	ands r0, r2
	mov sb, r1
	cmp r0, #0
	beq _081D3C50
	movs r0, #1
	b _081D3C52
_081D3C50:
	movs r0, #0
_081D3C52:
	cmp r0, #0
	bne _081D3C58
	b _081D3DC0
_081D3C58:
	mov r4, sp
	mov r0, sp
	bl FUN_08086a28
	mov r0, sp
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r4, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _081D3C86
	cmp r1, #0
	blt _081D3C86
	ldr r0, _081D3C8C @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081D3C86
	ldr r0, _081D3C90 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081D3C94
_081D3C86:
	movs r4, #0
	b _081D3CA2
	.align 2, 0
_081D3C8C: .4byte 0x030046A8
_081D3C90: .4byte 0x030046AC
_081D3C94:
	ldr r0, _081D3CB4 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_081D3CA2:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081D3CB8
	adds r0, #4
	b _081D3CC4
	.align 2, 0
_081D3CB4: .4byte 0x030046A4
_081D3CB8:
	ldr r0, _081D3D50 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081D3CC4:
	ldrh r0, [r0, #2]
	movs r1, #0x80
	ands r0, r1
	cmp r0, #0
	beq _081D3DC0
	add r3, sp, #8
	mov r4, r8
	adds r4, #0xfc
	mov r5, sp
	mov r0, sp
	ldrh r1, [r0]
	ldrh r0, [r4]
	subs r1, r1, r0
	strh r1, [r3]
	ldrh r2, [r5, #2]
	ldrh r0, [r4, #2]
	subs r6, r2, r0
	strh r6, [r3, #2]
	ldrh r2, [r5, #4]
	ldrh r0, [r4, #4]
	subs r7, r2, r0
	strh r7, [r3, #4]
	ldr r0, _081D3D54 @ =0x085AE0D0
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	movs r5, #0
	ldrsh r2, [r0, r5]
	adds r5, r0, #0
	cmp r1, r2
	bgt _081D3D4A
	movs r0, #0
	ldrsh r1, [r3, r0]
	movs r2, #0
	ldrsh r0, [r5, r2]
	cmn r1, r0
	blt _081D3D3C
	lsls r0, r6, #0x10
	asrs r0, r0, #0x10
	movs r6, #2
	ldrsh r1, [r5, r6]
	cmp r0, r1
	bgt _081D3D3C
	movs r0, #2
	ldrsh r1, [r3, r0]
	movs r2, #2
	ldrsh r0, [r5, r2]
	cmn r1, r0
	blt _081D3D3C
	lsls r0, r7, #0x10
	asrs r0, r0, #0x10
	movs r6, #4
	ldrsh r1, [r5, r6]
	cmp r0, r1
	bgt _081D3D3C
	movs r0, #4
	ldrsh r1, [r3, r0]
	movs r2, #4
	ldrsh r0, [r5, r2]
	cmn r1, r0
	bge _081D3DC0
_081D3D3C:
	movs r6, #0
	ldrsh r1, [r3, r6]
	ldrh r2, [r5]
	movs r6, #0
	ldrsh r0, [r5, r6]
	cmp r1, r0
	ble _081D3D58
_081D3D4A:
	ldrh r0, [r5]
	b _081D3D66
	.align 2, 0
_081D3D50: .4byte 0x030046A4
_081D3D54: .4byte 0x085AE0D0
_081D3D58:
	movs r0, #0
	ldrsh r1, [r3, r0]
	movs r6, #0
	ldrsh r0, [r5, r6]
	cmn r1, r0
	bge _081D3D68
	rsbs r0, r2, #0
_081D3D66:
	strh r0, [r3]
_081D3D68:
	movs r0, #4
	ldrsh r1, [r3, r0]
	ldrh r2, [r5, #4]
	movs r6, #4
	ldrsh r0, [r5, r6]
	cmp r1, r0
	ble _081D3D7A
	strh r2, [r3, #4]
	b _081D3D8A
_081D3D7A:
	movs r0, #4
	ldrsh r1, [r3, r0]
	movs r6, #4
	ldrsh r0, [r5, r6]
	cmn r1, r0
	bge _081D3D8A
	rsbs r0, r2, #0
	strh r0, [r3, #4]
_081D3D8A:
	ldrh r0, [r3]
	ldrh r4, [r4]
	adds r0, r0, r4
	mov r1, sp
	strh r0, [r1]
	mov r0, r8
	adds r0, #0xfe
	ldrh r0, [r0]
	mov r2, sp
	strh r0, [r2, #2]
	movs r1, #0x80
	lsls r1, r1, #1
	add r1, r8
	add r0, sp, #8
	ldrh r0, [r0, #4]
	ldrh r1, [r1]
	adds r0, r0, r1
	strh r0, [r2, #4]
	mov r0, sp
	bl FUN_08086a4c
	movs r0, #0x80
	lsls r0, r0, #2
	mov r2, sb
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
_081D3DC0:
	add sp, #0x10
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
