	push {r4, r5, r6, lr}
	sub sp, #8
	adds r5, r0, #0
	ldrh r1, [r5, #0x34]
	ldrh r0, [r5, #0x2c]
	adds r1, r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r2, _080840D0 @ =0xFFFF0000
	ldr r0, [sp]
	ands r0, r2
	orrs r0, r1
	str r0, [sp]
	ldrh r1, [r5, #0x38]
	ldrh r0, [r5, #0x30]
	adds r1, r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	mov r3, sp
	ldr r0, [sp, #4]
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #4]
	mov r0, sp
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r3, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _080840CC
	cmp r1, #0
	blt _080840CC
	ldr r0, _080840D4 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _080840CC
	ldr r0, _080840D8 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _080840DC
_080840CC:
	movs r4, #0
	b _080840EA
	.align 2, 0
_080840D0: .4byte 0xFFFF0000
_080840D4: .4byte 0x030046A8
_080840D8: .4byte 0x030046AC
_080840DC:
	ldr r0, _080840FC @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_080840EA:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _08084100
	adds r0, #4
	b _0808410C
	.align 2, 0
_080840FC: .4byte 0x030046A4
_08084100:
	ldr r0, _08084160 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0808410C:
	ldrh r0, [r0, #2]
	movs r1, #2
	ands r0, r1
	cmp r0, #0
	beq _0808411C
	movs r0, #0
	strh r0, [r5, #0x34]
	strh r0, [r5, #0x38]
_0808411C:
	adds r0, r5, #0
	movs r1, #0x10
	bl FUN_08080ed8
	cmp r0, #0
	beq _080841C0
	movs r0, #0
	str r0, [r5, #0x3c]
	adds r0, r5, #0
	adds r0, #0x24
	bl Mover_ApplyMove
	adds r6, r5, #0
	adds r6, #0x2c
	ldrh r0, [r5, #0x2c]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r6, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _0808415C
	cmp r1, #0
	blt _0808415C
	ldr r0, _08084164 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _0808415C
	ldr r0, _08084168 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0808416C
_0808415C:
	movs r4, #0
	b _0808417A
	.align 2, 0
_08084160: .4byte 0x030046A4
_08084164: .4byte 0x030046A8
_08084168: .4byte 0x030046AC
_0808416C:
	ldr r0, _0808418C @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_0808417A:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _08084190
	adds r0, #4
	b _0808419C
	.align 2, 0
_0808418C: .4byte 0x030046A4
_08084190:
	ldr r0, _080841B0 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0808419C:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _080841B4
	cmp r2, #2
	beq _080841B8
	b _080841BC
	.align 2, 0
_080841B0: .4byte 0x030046A4
_080841B4:
	ldrb r0, [r6, #4]
	b _080841BA
_080841B8:
	ldrb r0, [r6]
_080841BA:
	subs r1, r1, r0
_080841BC:
	strh r1, [r5, #0x2e]
	b _080841E0
_080841C0:
	ldr r0, [r5, #0x3c]
	cmp r0, #0
	bne _080841D8
	movs r1, #0xde
	lsls r1, r1, #1
	adds r4, r5, r1
	adds r1, r5, #0
	adds r1, #0x2c
	adds r0, r4, #0
	bl Map_InitMoverTile
	str r4, [r5, #0x3c]
_080841D8:
	adds r0, r5, #0
	adds r0, #0x24
	bl Mover_ApplyMove
_080841E0:
	adds r0, r5, #0
	movs r1, #8
	bl FUN_08080ed8
	cmp r0, #0
	beq _080841FC
	movs r0, #0xb9
	lsls r0, r0, #1
	adds r2, r5, r0
	ldrh r1, [r2]
	movs r0, #4
	orrs r0, r1
	strh r0, [r2]
	b _0808421A
_080841FC:
	movs r1, #0xb9
	lsls r1, r1, #1
	adds r2, r5, r1
	ldrh r1, [r2]
	ldr r0, _08084230 @ =0x0000FFFB
	ands r0, r1
	strh r0, [r2]
	movs r2, #0xb6
	lsls r2, r2, #1
	adds r0, r5, r2
	adds r1, r5, #0
	adds r1, #0x2c
	movs r2, #0
	bl Hitbox_SetPos
_0808421A:
	adds r0, r5, #0
	movs r1, #0x20
	bl FUN_08080ed8
	cmp r0, #0
	beq _08084238
	ldr r0, _08084234 @ =0x00000464
	adds r1, r5, r0
	movs r0, #0
	strb r0, [r1]
	b _08084262
	.align 2, 0
_08084230: .4byte 0x0000FFFB
_08084234: .4byte 0x00000464
_08084238:
	ldr r1, _08084298 @ =0x00000464
	adds r4, r5, r1
	ldrb r0, [r4]
	adds r6, r5, #0
	adds r6, #0x2c
	cmp r0, #0
	bne _08084256
	movs r2, #0xfe
	lsls r2, r2, #1
	adds r0, r5, r2
	adds r1, r6, #0
	bl Map_InitNavAgent
	movs r0, #1
	strb r0, [r4]
_08084256:
	movs r1, #0xfe
	lsls r1, r1, #1
	adds r0, r5, r1
	adds r1, r6, #0
	bl Map_StepNavPath
_08084262:
	adds r2, r5, #0
	adds r2, #0xa8
	ldr r0, [r5, #0x2c]
	ldr r1, [r5, #0x30]
	str r0, [r2]
	str r1, [r2, #4]
	adds r1, r5, #0
	adds r1, #0xaa
	ldr r2, _0808429C @ =0x000003F6
	adds r0, r5, r2
	ldrh r0, [r0]
	ldrh r2, [r1]
	adds r0, r0, r2
	strh r0, [r1]
	adds r0, r5, #0
	movs r1, #1
	bl FUN_08080ed8
	cmp r0, #0
	beq _080842A0
	adds r0, r5, #0
	adds r0, #0x90
	ldr r1, [r0]
	movs r2, #1
	orrs r1, r2
	b _080842AC
	.align 2, 0
_08084298: .4byte 0x00000464
_0808429C: .4byte 0x000003F6
_080842A0:
	adds r0, r5, #0
	adds r0, #0x90
	ldr r1, [r0]
	movs r2, #2
	rsbs r2, r2, #0
	ands r1, r2
_080842AC:
	str r1, [r0]
	adds r4, r0, #0
	adds r0, r5, #0
	movs r1, #2
	bl FUN_08080ed8
	cmp r0, #0
	beq _080842C6
	ldr r0, [r4]
	movs r1, #0x80
	lsls r1, r1, #2
	orrs r0, r1
	b _080842CC
_080842C6:
	ldr r0, [r4]
	ldr r1, _080842E4 @ =0xFFFFFDFF
	ands r0, r1
_080842CC:
	str r0, [r4]
	adds r0, r5, #0
	movs r1, #4
	bl FUN_08080ed8
	cmp r0, #0
	beq _080842EC
	ldr r1, _080842E8 @ =0x0000060C
	adds r0, r5, r1
	bl ParticleShadow_Hide
	b _080842F4
	.align 2, 0
_080842E4: .4byte 0xFFFFFDFF
_080842E8: .4byte 0x0000060C
_080842EC:
	ldr r2, _08084310 @ =0x0000060C
	adds r0, r5, r2
	bl ParticleShadow_Show
_080842F4:
	adds r0, r5, #0
	movs r1, #0x80
	bl FUN_08080ed8
	cmp r0, #0
	beq _08084318
	ldr r1, _08084314 @ =0x000009C8
	adds r0, r5, r1
	ldr r1, [r0]
	movs r2, #2
	rsbs r2, r2, #0
	ands r1, r2
	b _08084322
	.align 2, 0
_08084310: .4byte 0x0000060C
_08084314: .4byte 0x000009C8
_08084318:
	ldr r2, _0808432C @ =0x000009C8
	adds r0, r5, r2
	ldr r1, [r0]
	movs r2, #1
	orrs r1, r2
_08084322:
	str r1, [r0]
	add sp, #8
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0808432C: .4byte 0x000009C8
