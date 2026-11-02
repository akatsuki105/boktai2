	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	adds r4, r0, #0
	mov sl, r1
	mov sb, r2
	mov r8, r3
	ldr r0, _081EE6F8 @ =0x030001D0
	ldr r6, [r0]
	cmp r6, #0
	bne _081EE5F6
	bl Entity081ee7a8_Create
	adds r6, r0, #0
	cmp r6, #0
	beq _081EE6E8
_081EE5F6:
	adds r0, r6, #0
	bl Entity081ee7a8_AllocElem
	adds r7, r0, #0
	cmp r7, #0
	beq _081EE6E8
	adds r0, #0x58
	movs r5, #0
	movs r1, #1
	strb r1, [r0]
	adds r0, #0xe
	strh r5, [r0]
	ldr r0, [r4]
	ldr r1, [r4, #4]
	str r0, [r7, #0x1c]
	str r1, [r7, #0x20]
	adds r4, r7, #0
	adds r4, #0x2c
	adds r0, r4, #0
	ldr r1, [sp, #0x48]
	bl Video_GetAuxSprite
	ldr r0, _081EE6FC @ =0x0000922E
	ldr r1, [sp, #0x4c]
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	bl GetFile
	str r0, [r6, #0x18]
	adds r0, r7, #0
	adds r1, r4, #0
	movs r2, #0
	bl AuxSprite_Add
	adds r0, r7, #0
	adds r0, #0x48
	ldr r1, [r6, #0x18]
	ldr r2, [sp, #0x50]
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	ldr r3, [sp, #0x54]
	lsls r3, r3, #0x18
	lsrs r3, r3, #0x18
	str r5, [sp]
	bl AuxAnim_SetAnim
	adds r0, r4, #0
	ldr r1, [sp, #0x58]
	bl Video_SetAuxSpritePltt
	ldr r6, _081EE700 @ =0x0203B400
	ldr r4, _081EE704 @ =0x030046B8
	ldr r0, [r4]
	adds r0, #1
	ldr r5, _081EE708 @ =0x000003FF
	ands r0, r5
	str r0, [r4]
	lsls r0, r0, #1
	adds r0, r0, r6
	ldrh r0, [r0]
	mov r1, sb
	bl Mod
	add r0, sl
	adds r1, r7, #0
	adds r1, #0x5c
	strh r0, [r1]
	ldr r0, [r4]
	adds r0, #1
	ands r0, r5
	str r0, [r4]
	lsls r0, r0, #1
	adds r0, r0, r6
	ldrh r0, [r0]
	ldr r1, [sp, #0x24]
	bl Mod
	ldr r2, [sp, #0x24]
	asrs r1, r2, #1
	subs r0, r0, r1
	add r0, r8
	adds r2, r7, #0
	adds r2, #0x5e
	strh r0, [r2]
	ldr r0, [r4]
	adds r0, #1
	ands r0, r5
	str r0, [r4]
	lsls r0, r0, #1
	adds r0, r0, r6
	ldrh r0, [r0]
	ldr r1, [sp, #0x30]
	bl Mod
	ldr r1, [sp, #0x2c]
	adds r1, r1, r0
	adds r0, r7, #0
	adds r0, #0x5a
	strb r1, [r0]
	adds r1, r7, #0
	adds r1, #0x64
	ldr r0, [sp, #0x28]
	strh r0, [r1]
	adds r1, #4
	ldr r0, [sp, #0x34]
	strh r0, [r1]
	adds r1, #5
	movs r0, #0xc
	strb r0, [r1]
	ldr r0, [r7]
	movs r1, #1
	orrs r0, r1
	ldr r1, [sp, #0x40]
	orrs r0, r1
	str r0, [r7]
	ldr r0, [sp, #0x38]
	strb r0, [r7, #7]
	adds r1, r7, #0
	adds r1, #0x6e
	ldr r0, [sp, #0x44]
	strh r0, [r1]
_081EE6E8:
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081EE6F8: .4byte 0x030001D0
_081EE6FC: .4byte 0x0000922E
_081EE700: .4byte 0x0203B400
_081EE704: .4byte 0x030046B8
_081EE708: .4byte 0x000003FF
