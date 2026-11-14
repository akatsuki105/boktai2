	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #4
	mov r8, r0
	adds r4, r1, #0
	adds r7, r4, #0
	adds r7, #0x4c
	ldrb r0, [r4, #8]
	cmp r0, #0
	beq _080574B6
	movs r2, #0
	strb r2, [r4, #8]
	adds r0, r4, #0
	adds r0, #0x78
	mov r3, r8
	ldr r1, [r3, #0x18]
	str r2, [sp]
	movs r2, #2
	movs r3, #0
	bl AuxAnim_SetAnim
	ldr r0, [r4, #0x4c]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r4, #0x4c]
	adds r0, r4, #0
	adds r0, #0xd8
	bl ParticleShadow_Show
_080574B6:
	ldrh r0, [r7, #0x1e]
	subs r0, #0x20
	strh r0, [r7, #0x1e]
	adds r6, r4, #0
	adds r6, #0x68
	ldrh r0, [r7, #0x1c]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r6, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _080574E4
	cmp r1, #0
	blt _080574E4
	ldr r0, _080574E8 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _080574E4
	ldr r0, _080574EC @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _080574F0
_080574E4:
	movs r5, #0
	b _080574FE
	.align 2, 0
_080574E8: .4byte 0x030046A8
_080574EC: .4byte 0x030046AC
_080574F0:
	ldr r0, _08057510 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r5, r0, r2
_080574FE:
	adds r0, r5, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _08057514
	adds r0, #4
	b _08057520
	.align 2, 0
_08057510: .4byte 0x030046A4
_08057514:
	ldr r0, _08057534 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r5, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08057520:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _08057538
	cmp r2, #2
	beq _0805753C
	b _08057540
	.align 2, 0
_08057534: .4byte 0x030046A4
_08057538:
	ldrb r0, [r6, #4]
	b _0805753E
_0805753C:
	ldrb r0, [r6]
_0805753E:
	subs r1, r1, r0
_08057540:
	movs r2, #0x1e
	ldrsh r0, [r7, r2]
	cmp r0, r1
	bgt _08057578
	movs r2, #0
	strh r1, [r7, #0x1e]
	movs r1, #0x80
	lsls r1, r1, #0xd
	ldr r0, [r4, #0x18]
	cmp r0, r1
	bhi _0805755A
	movs r1, #4
	b _0805755C
_0805755A:
	movs r1, #2
_0805755C:
	mov r3, r8
	ldr r0, [r3, #0x30]
	cmp r0, #0
	beq _08057566
	movs r1, #8
_08057566:
	strb r1, [r4, #4]
	movs r0, #1
	strb r0, [r4, #8]
	str r2, [r4, #0x14]
	adds r0, r4, #0
	adds r0, #0xd8
	bl ParticleShadow_Hide
	b _0805757E
_08057578:
	ldr r0, [r4, #0x14]
	adds r0, #1
	str r0, [r4, #0x14]
_0805757E:
	add sp, #4
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
