	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #4
	mov r8, r0
	adds r5, r1, #0
	adds r7, r5, #0
	adds r7, #0x4c
	ldrb r0, [r5, #8]
	cmp r0, #0
	beq _0805853C
	movs r0, #0
	strb r0, [r5, #8]
	adds r0, r5, #0
	adds r0, #0xd8
	bl ParticleShadow_Show
	adds r6, r5, #0
	adds r6, #0x68
	ldrh r0, [r7, #0x1c]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r6, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _080584AC
	cmp r1, #0
	blt _080584AC
	ldr r0, _080584B0 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _080584AC
	ldr r0, _080584B4 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _080584B8
_080584AC:
	movs r4, #0
	b _080584C6
	.align 2, 0
_080584B0: .4byte 0x030046A8
_080584B4: .4byte 0x030046AC
_080584B8:
	ldr r0, _080584D8 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_080584C6:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _080584DC
	adds r0, #4
	b _080584E8
	.align 2, 0
_080584D8: .4byte 0x030046A4
_080584DC:
	ldr r0, _0805851C @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_080584E8:
	ldrh r0, [r0, #2]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	bne _0805853C
	ldrh r0, [r6]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r6, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _08058516
	cmp r1, #0
	blt _08058516
	ldr r0, _08058520 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08058516
	ldr r0, _08058524 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08058528
_08058516:
	movs r0, #0
	b _08058536
	.align 2, 0
_0805851C: .4byte 0x030046A4
_08058520: .4byte 0x030046A8
_08058524: .4byte 0x030046AC
_08058528:
	ldr r0, _08058580 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r0, r0, r2
_08058536:
	movs r1, #1
	bl Map_FindTileOverride
_0805853C:
	mov r0, r8
	adds r1, r5, #0
	bl FUN_08056b08
	ldrh r0, [r5, #0x20]
	ldrh r1, [r7, #0x1c]
	adds r0, r0, r1
	strh r0, [r7, #0x1c]
	ldrh r1, [r5, #0x24]
	ldrh r2, [r7, #0x20]
	adds r1, r1, r2
	strh r1, [r7, #0x20]
	adds r6, r7, #0
	adds r6, #0x1c
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r6, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	mov sb, r6
	cmp r2, #0
	blt _0805857C
	cmp r1, #0
	blt _0805857C
	ldr r0, _08058584 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _0805857C
	ldr r0, _08058588 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0805858C
_0805857C:
	movs r4, #0
	b _0805859A
	.align 2, 0
_08058580: .4byte 0x030046A4
_08058584: .4byte 0x030046A8
_08058588: .4byte 0x030046AC
_0805858C:
	ldr r0, _080585AC @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_0805859A:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _080585B0
	adds r0, #4
	b _080585BC
	.align 2, 0
_080585AC: .4byte 0x030046A4
_080585B0:
	ldr r0, _080585D0 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_080585BC:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _080585D4
	cmp r2, #2
	beq _080585D8
	b _080585DC
	.align 2, 0
_080585D0: .4byte 0x030046A4
_080585D4:
	ldrb r0, [r6, #4]
	b _080585DA
_080585D8:
	ldrb r0, [r6]
_080585DA:
	subs r1, r1, r0
_080585DC:
	adds r3, r1, #0
	ldr r2, _080585FC @ =gSineTable
	ldr r0, [r5, #0x14]
	lsls r0, r0, #2
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r0, #0xfa
	muls r0, r1, r0
	cmp r0, #0
	blt _08058600
	asrs r0, r0, #0xc
	b _08058606
	.align 2, 0
_080585FC: .4byte gSineTable
_08058600:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08058606:
	adds r0, r3, r0
	strh r0, [r7, #0x1e]
	movs r0, #0x20
	ldrsh r1, [r5, r0]
	cmp r1, #0
	bge _08058614
	rsbs r1, r1, #0
_08058614:
	movs r2, #0x24
	ldrsh r0, [r5, r2]
	cmp r0, #0
	bge _0805861E
	rsbs r0, r0, #0
_0805861E:
	cmp r1, r0
	bge _08058638
	adds r0, r5, #0
	adds r0, #0x78
	mov r2, r8
	ldr r1, [r2, #0x18]
	movs r2, #0
	str r2, [sp]
	movs r2, #2
	movs r3, #0
	bl AuxAnim_SetAnim
	b _0805864C
_08058638:
	adds r0, r5, #0
	adds r0, #0x78
	mov r2, r8
	ldr r1, [r2, #0x18]
	movs r2, #1
	str r2, [sp]
	movs r2, #2
	movs r3, #0
	bl AuxAnim_SetAnim
_0805864C:
	ldrb r0, [r5, #0xa]
	movs r1, #1
	orrs r1, r0
	strb r1, [r5, #0xa]
	ldr r0, [r5, #0x14]
	cmp r0, #0x1f
	bhi _0805865C
	b _080587B4
_0805865C:
	movs r1, #4
	mov r2, r8
	ldr r0, [r2, #0x30]
	cmp r0, #0
	beq _08058668
	movs r1, #8
_08058668:
	strb r1, [r5, #4]
	movs r0, #1
	strb r0, [r5, #8]
	movs r0, #0
	str r0, [r5, #0x14]
	mov r6, sb
	ldrh r0, [r7, #0x1c]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r6, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _08058698
	cmp r1, #0
	blt _08058698
	ldr r0, _0805869C @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08058698
	ldr r0, _080586A0 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _080586A4
_08058698:
	movs r4, #0
	b _080586B2
	.align 2, 0
_0805869C: .4byte 0x030046A8
_080586A0: .4byte 0x030046AC
_080586A4:
	ldr r0, _080586C4 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_080586B2:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _080586C8
	adds r0, #4
	b _080586D4
	.align 2, 0
_080586C4: .4byte 0x030046A4
_080586C8:
	ldr r0, _080586E8 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_080586D4:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _080586EC
	cmp r2, #2
	beq _080586F0
	b _080586F4
	.align 2, 0
_080586E8: .4byte 0x030046A4
_080586EC:
	ldrb r0, [r6, #4]
	b _080586F2
_080586F0:
	ldrb r0, [r6]
_080586F2:
	subs r1, r1, r0
_080586F4:
	strh r1, [r7, #0x1e]
	mov r6, sb
	ldrh r0, [r7, #0x1c]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r6, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _0805871C
	cmp r1, #0
	blt _0805871C
	ldr r0, _08058720 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _0805871C
	ldr r0, _08058724 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08058728
_0805871C:
	movs r4, #0
	b _08058736
	.align 2, 0
_08058720: .4byte 0x030046A8
_08058724: .4byte 0x030046AC
_08058728:
	ldr r0, _08058748 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_08058736:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _0805874C
	adds r0, #4
	b _08058758
	.align 2, 0
_08058748: .4byte 0x030046A4
_0805874C:
	ldr r0, _0805878C @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08058758:
	ldrh r0, [r0, #2]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	bne _080587AC
	ldrh r0, [r6]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r6, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _08058786
	cmp r1, #0
	blt _08058786
	ldr r0, _08058790 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08058786
	ldr r0, _08058794 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08058798
_08058786:
	movs r0, #0
	b _080587A6
	.align 2, 0
_0805878C: .4byte 0x030046A4
_08058790: .4byte 0x030046A8
_08058794: .4byte 0x030046AC
_08058798:
	ldr r0, _080587C8 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r0, r0, r2
_080587A6:
	movs r1, #1
	bl Map_FindTileOverride
_080587AC:
	adds r0, r5, #0
	adds r0, #0xd8
	bl ParticleShadow_Hide
_080587B4:
	ldr r0, [r5, #0x14]
	adds r0, #1
	str r0, [r5, #0x14]
	add sp, #4
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080587C8: .4byte 0x030046A4
