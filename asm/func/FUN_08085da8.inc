	push {r4, r5, lr}
	adds r5, r0, #0
	movs r0, #0xce
	lsls r0, r0, #2
	adds r4, r5, r0
	ldrh r0, [r4]
	cmp r0, #0
	beq _08085DBC
	subs r0, #1
	strh r0, [r4]
_08085DBC:
	ldr r1, _08085DF4 @ =0x0000033A
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _08085EB0
	adds r1, #0x4a
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _08085EB0
	ldrb r0, [r5, #0x1a]
	cmp r0, #5
	bne _08085DFC
	subs r1, #0x4e
	adds r0, r5, r1
	ldrh r0, [r0]
	cmp r0, #0
	bne _08085EA2
	ldrh r0, [r4]
	cmp r0, #0
	bne _08085EA2
	ldr r0, _08085DF8 @ =0x0000026A
	bl PlaySound_082406e0
	movs r0, #0x64
	strh r0, [r4]
	b _08085EA2
	.align 2, 0
_08085DF4: .4byte 0x0000033A
_08085DF8: .4byte 0x0000026A
_08085DFC:
	ldr r1, _08085E34 @ =0x00000336
	adds r0, r5, r1
	ldrh r0, [r0]
	cmp r0, #0
	bne _08085E8E
	adds r0, r5, #0
	adds r0, #0x48
	ldrh r1, [r0]
	lsls r1, r1, #0x10
	asrs r2, r1, #0x18
	ldrh r0, [r0, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _08085E2E
	cmp r1, #0
	blt _08085E2E
	ldr r0, _08085E38 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08085E2E
	ldr r0, _08085E3C @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08085E40
_08085E2E:
	movs r4, #0
	b _08085E4E
	.align 2, 0
_08085E34: .4byte 0x00000336
_08085E38: .4byte 0x030046A8
_08085E3C: .4byte 0x030046AC
_08085E40:
	ldr r0, _08085E60 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_08085E4E:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _08085E64
	adds r0, #4
	b _08085E70
	.align 2, 0
_08085E60: .4byte 0x030046A4
_08085E64:
	ldr r0, _08085E84 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08085E70:
	ldrb r0, [r0]
	lsrs r0, r0, #4
	subs r0, #1
	cmp r0, #1
	bhi _08085E88
	movs r0, #0xd3
	bl PlaySound_082406e0
	b _08085E8E
	.align 2, 0
_08085E84: .4byte 0x030046A4
_08085E88:
	movs r0, #0xd2
	bl PlaySound_082406e0
_08085E8E:
	ldr r1, _08085EAC @ =0x00000336
	adds r0, r5, r1
	ldrh r1, [r0]
	movs r0, #7
	ands r0, r1
	cmp r0, #0
	bne _08085EA2
	adds r0, r5, #0
	bl FUN_08085764
_08085EA2:
	ldr r0, _08085EAC @ =0x00000336
	adds r1, r5, r0
	ldrh r0, [r1]
	adds r0, #1
	b _08085EB6
	.align 2, 0
_08085EAC: .4byte 0x00000336
_08085EB0:
	ldr r0, _08085EC0 @ =0x00000336
	adds r1, r5, r0
	movs r0, #0
_08085EB6:
	strh r0, [r1]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08085EC0: .4byte 0x00000336
