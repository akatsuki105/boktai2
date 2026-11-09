	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x1c
	adds r5, r0, #0
	str r1, [sp, #0xc]
	str r2, [sp, #0x10]
	str r3, [sp, #0x14]
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r6, [r0]
	ldr r2, _0818EF74 @ =0x00000F36
	adds r4, r6, r2
	movs r0, #6
	strh r0, [r4]
	movs r1, #6
	adds r2, #0x10
	adds r0, r6, r2
	strb r1, [r0]
	ldr r0, _0818EF78 @ =0x00000F48
	adds r1, r6, r0
	ldr r0, _0818EF7C @ =0x7FFFFFFF
	str r0, [r1]
	movs r1, #0xc2
	lsls r1, r1, #1
	adds r0, r5, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	movs r2, #0
	ldrsh r1, [r4, r2]
	adds r1, #1
	bl Div
	ldr r2, _0818EF80 @ =0x00000F47
	adds r1, r6, r2
	strb r0, [r1]
	movs r0, #0
	str r0, [sp, #0x18]
	movs r7, #0
	movs r1, #0
	mov sb, r1
	movs r2, #0
	ldrsh r0, [r4, r2]
	cmp sb, r0
	bge _0818EFF2
	mov sl, r1
	movs r0, #0xe8
	lsls r0, r0, #3
	adds r4, r6, r0
	ldr r1, _0818EF84 @ =0x00000684
	adds r5, r6, r1
	movs r2, #0xcb
	lsls r2, r2, #3
	adds r2, r2, r6
	mov r8, r2
_0818EF0C:
	adds r0, r5, #0
	ldr r1, [sp, #0xc]
	bl Video_GetAuxSprite
	mov r0, r8
	adds r1, r5, #0
	movs r2, #0
	bl AuxSprite_Add
	adds r0, r5, #0
	ldr r1, _0818EF88 @ =0x000001A3
	bl Video_SetAuxSpritePltt
	mov r0, sp
	ldrb r0, [r0, #0x14]
	strb r0, [r4, #0x14]
	ldr r2, [sp, #0x10]
	lsls r1, r2, #0x10
	ldr r0, _0818EF8C @ =0x0000922E
	lsrs r1, r1, #0x10
	bl GetFile
	str r0, [r4, #0x10]
	ldrb r0, [r4, #0x14]
	add r1, sp, #4
	add r2, sp, #8
	bl Serpent_GetAnimVariant
	ldr r1, _0818EF74 @ =0x00000F36
	adds r0, r6, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	subs r0, #1
	cmp sb, r0
	bne _0818EF90
	ldr r1, [r4, #0x10]
	ldr r3, [sp, #4]
	lsls r3, r3, #0x18
	lsrs r3, r3, #0x18
	ldr r0, [sp, #8]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	str r0, [sp]
	adds r0, r4, #0
	movs r2, #0xb
	bl AuxAnim_SetAnim
	movs r0, #4
	ldrh r1, [r4, #0x3a]
	orrs r0, r1
	strh r0, [r4, #0x3a]
	b _0818EFB2
	.align 2, 0
_0818EF74: .4byte 0x00000F36
_0818EF78: .4byte 0x00000F48
_0818EF7C: .4byte 0x7FFFFFFF
_0818EF80: .4byte 0x00000F47
_0818EF84: .4byte 0x00000684
_0818EF88: .4byte 0x000001A3
_0818EF8C: .4byte 0x0000922E
_0818EF90:
	ldr r1, [r4, #0x10]
	ldr r3, [sp, #4]
	lsls r3, r3, #0x18
	lsrs r3, r3, #0x18
	ldr r0, [sp, #8]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	str r0, [sp]
	adds r0, r4, #0
	movs r2, #6
	bl AuxAnim_SetAnim
	strh r7, [r4, #8]
	adds r7, #1
	cmp r7, #3
	ble _0818EFB2
	movs r7, #0
_0818EFB2:
	str r6, [r4, #0x34]
	movs r1, #0
	movs r0, #0
	strh r0, [r4, #0x38]
	ldr r0, [sp, #0x18]
	cmp r0, #0
	bne _0818EFCE
	mov r1, sl
	strb r1, [r4, #0x1a]
	movs r0, #2
	ldrh r1, [r4, #0x3a]
	orrs r0, r1
	strh r0, [r4, #0x3a]
	b _0818EFD4
_0818EFCE:
	ldr r2, [sp, #0x18]
	adds r2, #1
	str r2, [sp, #0x18]
_0818EFD4:
	movs r0, #0x18
	add sl, r0
	movs r1, #0x92
	lsls r1, r1, #1
	adds r4, r4, r1
	adds r5, r5, r1
	add r8, r1
	movs r2, #1
	add sb, r2
	ldr r1, _0818F004 @ =0x00000F36
	adds r0, r6, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp sb, r0
	blt _0818EF0C
_0818EFF2:
	add sp, #0x1c
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0818F004: .4byte 0x00000F36
