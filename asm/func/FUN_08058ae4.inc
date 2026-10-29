	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0x1c
	mov r8, r0
	adds r4, r1, #0
	mov sb, r2
	adds r6, r4, #0
	adds r6, #0x4c
	ldrb r0, [r4, #8]
	cmp r0, #0
	beq _08058B16
	movs r0, #0
	strb r0, [r4, #8]
	adds r0, r4, #0
	adds r0, #0xd8
	bl ParticleShadow_Show
	adds r0, r4, #0
	adds r0, #0x30
	movs r1, #0x99
	lsls r1, r1, #1
	bl Video_SetAuxSpritePltt
_08058B16:
	ldrb r1, [r4, #0xa]
	movs r0, #1
	orrs r0, r1
	strb r0, [r4, #0xa]
	movs r0, #0xa
	strb r0, [r4, #9]
	ldr r5, [r4, #0x14]
	movs r0, #7
	ands r5, r0
	adds r7, r4, #0
	adds r7, #0x68
	cmp r5, #0
	bne _08058B66
	ldr r2, _08058B90 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _08058B94 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _08058B98 @ =0x0203B400
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
	str r5, [sp, #0x18]
	movs r0, #3
	movs r1, #9
	adds r2, r7, #0
	bl Entity080146e0_SpawnAtAngle
_08058B66:
	ldrh r0, [r6, #0x1c]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r7, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _08058B8A
	cmp r1, #0
	blt _08058B8A
	ldr r0, _08058B9C @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08058B8A
	ldr r0, _08058BA0 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08058BA4
_08058B8A:
	movs r5, #0
	b _08058BB2
	.align 2, 0
_08058B90: .4byte 0x030046B8
_08058B94: .4byte 0x000003FF
_08058B98: .4byte 0x0203B400
_08058B9C: .4byte 0x030046A8
_08058BA0: .4byte 0x030046AC
_08058BA4:
	ldr r0, _08058BC4 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r5, r0, r2
_08058BB2:
	adds r0, r5, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _08058BC8
	adds r0, #4
	b _08058BD4
	.align 2, 0
_08058BC4: .4byte 0x030046A4
_08058BC8:
	ldr r0, _08058BE8 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r5, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08058BD4:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _08058BEC
	cmp r2, #2
	beq _08058BF0
	b _08058BF4
	.align 2, 0
_08058BE8: .4byte 0x030046A4
_08058BEC:
	ldrb r0, [r7, #4]
	b _08058BF2
_08058BF0:
	ldrb r0, [r7]
_08058BF2:
	subs r1, r1, r0
_08058BF4:
	adds r3, r1, #0
	ldr r2, _08058C14 @ =gSineTable
	ldr r0, [r4, #0x14]
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
	blt _08058C18
	asrs r0, r0, #0xc
	b _08058C1E
	.align 2, 0
_08058C14: .4byte gSineTable
_08058C18:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08058C1E:
	adds r0, r3, r0
	movs r2, #0
	strh r0, [r6, #0x1e]
	adds r0, r4, #0
	adds r0, #0x78
	mov r3, r8
	ldr r1, [r3, #0x18]
	str r2, [sp]
	movs r2, #2
	movs r3, #0
	bl AuxAnim_SetAnim
	ldr r1, [r4, #0x14]
	cmp r1, #7
	bls _08058C4C
	movs r0, #3
	ands r1, r0
	cmp r1, #0
	bne _08058C60
	ldr r0, [r6]
	movs r1, #1
	orrs r0, r1
	b _08058C68
_08058C4C:
	cmp r1, #0xf
	bls _08058C6A
	movs r0, #3
	ands r1, r0
	cmp r1, #2
	bhi _08058C60
	ldr r0, [r6]
	movs r1, #1
	orrs r0, r1
	b _08058C68
_08058C60:
	ldr r0, [r6]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
_08058C68:
	str r0, [r6]
_08058C6A:
	ldr r0, [r4, #0x14]
	cmp r0, #0x1f
	bls _08058C94
	adds r0, r4, #0
	adds r0, #0xd8
	bl ParticleShadow_Hide
	adds r0, r6, #0
	bl AuxSprite_Remove
	mov r0, r8
	adds r1, r4, #0
	bl Entity08058ffc_UnregisterElemHitbox
	movs r1, #1
	mov r0, sb
	lsls r1, r0
	mov r2, r8
	ldr r0, [r2, #0x1c]
	bics r0, r1
	str r0, [r2, #0x1c]
_08058C94:
	ldr r0, [r4, #0x14]
	adds r0, #1
	str r0, [r4, #0x14]
	add sp, #0x1c
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
