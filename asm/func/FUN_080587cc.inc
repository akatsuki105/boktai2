	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0x1c
	mov r8, r0
	adds r5, r1, #0
	mov sb, r2
	adds r6, r5, #0
	adds r6, #0x4c
	ldrb r0, [r5, #8]
	cmp r0, #0
	beq _080588AC
	movs r0, #0
	strb r0, [r5, #8]
	adds r0, r5, #0
	adds r0, #0xd8
	bl ParticleShadow_Show
	adds r7, r5, #0
	adds r7, #0x68
	ldrh r0, [r6, #0x1c]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r7, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _0805881A
	cmp r1, #0
	blt _0805881A
	ldr r0, _08058820 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _0805881A
	ldr r0, _08058824 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08058828
_0805881A:
	movs r4, #0
	b _08058836
	.align 2, 0
_08058820: .4byte 0x030046A8
_08058824: .4byte 0x030046AC
_08058828:
	ldr r0, _08058848 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_08058836:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _0805884C
	adds r0, #4
	b _08058858
	.align 2, 0
_08058848: .4byte 0x030046A4
_0805884C:
	ldr r0, _0805888C @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08058858:
	ldrh r0, [r0, #2]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	bne _080588AC
	ldrh r0, [r7]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r7, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _08058886
	cmp r1, #0
	blt _08058886
	ldr r0, _08058890 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08058886
	ldr r0, _08058894 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08058898
_08058886:
	movs r0, #0
	b _080588A6
	.align 2, 0
_0805888C: .4byte 0x030046A4
_08058890: .4byte 0x030046A8
_08058894: .4byte 0x030046AC
_08058898:
	ldr r0, _08058930 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r0, r0, r2
_080588A6:
	movs r1, #1
	bl Map_FindTileOverride
_080588AC:
	ldr r4, [r5, #0x14]
	movs r0, #7
	ands r4, r0
	adds r7, r6, #0
	adds r7, #0x1c
	cmp r4, #0
	bne _080588F0
	ldr r2, _08058934 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _08058938 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _0805893C @ =0x0203B400
	adds r0, r0, r1
	ldrb r3, [r0]
	movs r0, #0x20
	str r0, [sp]
	movs r0, #6
	str r0, [sp, #4]
	movs r1, #2
	str r1, [sp, #8]
	movs r0, #3
	str r0, [sp, #0xc]
	str r1, [sp, #0x10]
	movs r0, #0x10
	str r0, [sp, #0x14]
	str r4, [sp, #0x18]
	movs r0, #3
	movs r1, #9
	adds r2, r7, #0
	bl Entity080146e0_SpawnAtAngle
_080588F0:
	mov r0, r8
	adds r1, r5, #0
	bl FUN_08056b08
	ldrh r0, [r5, #0x20]
	ldrh r2, [r6, #0x1c]
	adds r0, r0, r2
	strh r0, [r6, #0x1c]
	ldrh r1, [r5, #0x24]
	ldrh r2, [r6, #0x20]
	adds r1, r1, r2
	strh r1, [r6, #0x20]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r7, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _0805892A
	cmp r1, #0
	blt _0805892A
	ldr r0, _08058940 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _0805892A
	ldr r0, _08058944 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08058948
_0805892A:
	movs r4, #0
	b _08058956
	.align 2, 0
_08058930: .4byte 0x030046A4
_08058934: .4byte 0x030046B8
_08058938: .4byte 0x000003FF
_0805893C: .4byte 0x0203B400
_08058940: .4byte 0x030046A8
_08058944: .4byte 0x030046AC
_08058948:
	ldr r0, _08058968 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_08058956:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _0805896C
	adds r0, #4
	b _08058978
	.align 2, 0
_08058968: .4byte 0x030046A4
_0805896C:
	ldr r0, _0805898C @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08058978:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _08058990
	cmp r2, #2
	beq _08058994
	b _08058998
	.align 2, 0
_0805898C: .4byte 0x030046A4
_08058990:
	ldrb r0, [r7, #4]
	b _08058996
_08058994:
	ldrb r0, [r7]
_08058996:
	subs r1, r1, r0
_08058998:
	adds r3, r1, #0
	ldr r2, _080589B8 @ =gSineTable
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
	blt _080589BC
	asrs r0, r0, #0xc
	b _080589C2
	.align 2, 0
_080589B8: .4byte gSineTable
_080589BC:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080589C2:
	adds r0, r3, r0
	strh r0, [r6, #0x1e]
	movs r0, #0x20
	ldrsh r1, [r5, r0]
	cmp r1, #0
	bge _080589D0
	rsbs r1, r1, #0
_080589D0:
	movs r2, #0x24
	ldrsh r0, [r5, r2]
	cmp r0, #0
	bge _080589DA
	rsbs r0, r0, #0
_080589DA:
	cmp r1, r0
	bge _080589F4
	adds r0, r5, #0
	adds r0, #0x78
	mov r2, r8
	ldr r1, [r2, #0x18]
	movs r2, #0
	str r2, [sp]
	movs r2, #2
	movs r3, #0
	bl AuxAnim_SetAnim
	b _08058A08
_080589F4:
	adds r0, r5, #0
	adds r0, #0x78
	mov r2, r8
	ldr r1, [r2, #0x18]
	movs r2, #1
	str r2, [sp]
	movs r2, #2
	movs r3, #0
	bl AuxAnim_SetAnim
_08058A08:
	ldrb r1, [r5, #0xa]
	movs r0, #1
	orrs r0, r1
	strb r0, [r5, #0xa]
	ldr r1, [r5, #0x14]
	cmp r1, #7
	bls _08058A26
	movs r0, #3
	ands r1, r0
	cmp r1, #0
	bne _08058A3A
	ldr r0, [r6]
	movs r1, #1
	orrs r0, r1
	b _08058A42
_08058A26:
	cmp r1, #0xf
	bls _08058A44
	movs r0, #3
	ands r1, r0
	cmp r1, #2
	bhi _08058A3A
	ldr r0, [r6]
	movs r1, #1
	orrs r0, r1
	b _08058A42
_08058A3A:
	ldr r0, [r6]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
_08058A42:
	str r0, [r6]
_08058A44:
	ldr r0, [r5, #0x14]
	cmp r0, #0x1f
	bls _08058A84
	mov r0, r8
	adds r1, r5, #0
	bl FUN_08057354
	adds r0, r5, #0
	adds r0, #0xd8
	bl ParticleShadow_Hide
	adds r0, r6, #0
	bl AuxSprite_Remove
	mov r0, r8
	adds r1, r5, #0
	bl Entity08058ffc_UnregisterElemHitbox
	movs r1, #1
	mov r0, sb
	lsls r1, r0
	mov r2, r8
	ldr r0, [r2, #0x1c]
	bics r0, r1
	str r0, [r2, #0x1c]
	ldr r0, [r2, #0x34]
	bl AddPlayerExp
	mov r1, r8
	ldr r0, [r1, #0x2c]
	adds r0, #1
	str r0, [r1, #0x2c]
_08058A84:
	ldr r0, [r5, #0x14]
	adds r0, #1
	str r0, [r5, #0x14]
	add sp, #0x1c
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
