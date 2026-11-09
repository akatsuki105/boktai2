	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x1c
	mov r8, r0
	adds r7, r1, #0
	mov sb, r7
	ldr r0, [r7, #0x2c]
	ldr r1, [r7, #0x30]
	str r0, [r7, #0x1c]
	str r1, [r7, #0x20]
	ldr r0, [r7]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r7]
	ldrh r0, [r7, #0x34]
	ldrh r1, [r7, #0x2c]
	adds r0, r0, r1
	strh r0, [r7, #0x2c]
	ldrh r1, [r7, #0x36]
	ldrh r2, [r7, #0x2e]
	adds r0, r1, r2
	strh r0, [r7, #0x2e]
	ldrh r0, [r7, #0x38]
	ldrh r2, [r7, #0x30]
	adds r0, r0, r2
	strh r0, [r7, #0x30]
	subs r1, #1
	strh r1, [r7, #0x36]
	movs r0, #0x1e
	ldrsh r6, [r7, r0]
	adds r5, r7, #0
	adds r5, #0x1c
	ldrh r0, [r7, #0x1c]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r5, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _081EA2D4
	cmp r1, #0
	blt _081EA2D4
	ldr r0, _081EA2D8 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081EA2D4
	ldr r0, _081EA2DC @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081EA2E0
_081EA2D4:
	movs r4, #0
	b _081EA2EE
	.align 2, 0
_081EA2D8: .4byte 0x030046A8
_081EA2DC: .4byte 0x030046AC
_081EA2E0:
	ldr r0, _081EA300 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_081EA2EE:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081EA304
	adds r0, #4
	b _081EA310
	.align 2, 0
_081EA300: .4byte 0x030046A4
_081EA304:
	ldr r0, _081EA324 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081EA310:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _081EA328
	cmp r2, #2
	beq _081EA32C
	b _081EA330
	.align 2, 0
_081EA324: .4byte 0x030046A4
_081EA328:
	ldrb r0, [r5, #4]
	b _081EA32E
_081EA32C:
	ldrb r0, [r5]
_081EA32E:
	subs r1, r1, r0
_081EA330:
	cmp r6, r1
	blo _081EA33E
	mov r1, sb
	movs r2, #0x1e
	ldrsh r0, [r1, r2]
	cmp r0, #0
	bgt _081EA424
_081EA33E:
	movs r0, #0xeb
	lsls r0, r0, #1
	bl PlaySound_082406e0
	adds r5, r7, #0
	adds r5, #0xd3
	movs r0, #0
	ldrsb r0, [r5, r0]
	movs r1, #1
	lsls r1, r0
	mov r2, r8
	ldr r0, [r2, #0x34]
	bics r0, r1
	str r0, [r2, #0x34]
	adds r0, r7, #0
	adds r0, #0xd2
	movs r4, #0
	strb r4, [r0]
	mov r0, sb
	bl AuxSprite_Remove
	adds r0, r7, #0
	adds r0, #0x8c
	bl ParticleShadow_Remove
	movs r0, #0xff
	strb r0, [r5]
	adds r0, r7, #0
	adds r0, #0xd0
	strh r4, [r0]
	subs r0, #4
	str r4, [r0]
	ldr r5, _081EA40C @ =0xFFFF0000
	ldr r4, [sp, #0xc]
	ands r4, r5
	ldr r6, _081EA410 @ =0x0000FFF4
	orrs r4, r6
	str r4, [sp, #0xc]
	ldr r0, _081EA414 @ =0x0203B400
	mov ip, r0
	ldr r1, _081EA418 @ =0x030046B8
	mov sl, r1
	ldr r1, [r1]
	adds r1, #1
	ldr r2, _081EA41C @ =0x000003FF
	mov r8, r2
	ands r1, r2
	lsls r0, r1, #1
	add r0, ip
	ldrh r2, [r0]
	movs r0, #7
	mov sb, r0
	mov r0, sb
	ands r2, r0
	lsls r2, r2, #0x10
	ldr r3, _081EA420 @ =0x0000FFFF
	adds r0, r3, #0
	ands r0, r4
	orrs r0, r2
	str r0, [sp, #0xc]
	ldr r0, [sp, #0x10]
	ands r0, r5
	orrs r0, r6
	str r0, [sp, #0x10]
	ldr r2, [sp, #0x14]
	ands r2, r5
	movs r4, #0x18
	orrs r2, r4
	str r2, [sp, #0x14]
	adds r1, #1
	mov r0, r8
	ands r1, r0
	mov r0, sl
	str r1, [r0]
	lsls r1, r1, #1
	add r1, ip
	ldrh r0, [r1]
	mov r1, sb
	ands r0, r1
	adds r0, #3
	lsls r0, r0, #0x10
	ands r3, r2
	orrs r3, r0
	str r3, [sp, #0x14]
	add r1, sp, #0x14
	ldr r0, [r1, #4]
	ands r0, r5
	orrs r0, r4
	str r0, [r1, #4]
	adds r2, r7, #0
	adds r2, #0x2c
	str r1, [sp]
	movs r0, #0x20
	str r0, [sp, #4]
	movs r0, #0x1f
	str r0, [sp, #8]
	movs r0, #6
	movs r1, #3
	add r3, sp, #0xc
	bl ScatterEffect_Spawn
	b _081EA43A
	.align 2, 0
_081EA40C: .4byte 0xFFFF0000
_081EA410: .4byte 0x0000FFF4
_081EA414: .4byte 0x0203B400
_081EA418: .4byte 0x030046B8
_081EA41C: .4byte 0x000003FF
_081EA420: .4byte 0x0000FFFF
_081EA424:
	adds r4, r7, #0
	adds r4, #0x3c
	adds r1, r7, #0
	adds r1, #0x2c
	adds r0, r4, #0
	movs r2, #0
	bl Hitbox_SetPos
	adds r0, r4, #0
	bl Hitbox_Register
_081EA43A:
	add sp, #0x1c
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
