	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	mov sb, r0
	movs r0, #0
	mov r8, r0
	ldr r7, _080B0C4C @ =0x030046B8
	ldr r1, _080B0C50 @ =0x000003FF
	mov sl, r1
_080B0C0C:
	movs r0, #0x68
	mov r3, r8
	muls r3, r0, r3
	adds r0, r3, #0
	adds r0, #0x68
	mov r1, sb
	adds r5, r1, r0
	adds r6, r5, #0
	adds r4, r5, #0
	adds r4, #0x2c
	ldr r0, _080B0C54 @ =0x08251DD0
	bl FUN_08230860
	adds r1, r0, #0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	adds r0, r4, #0
	bl Video_GetAuxSprite
	mov r0, r8
	movs r3, #1
	ands r0, r3
	cmp r0, #0
	beq _080B0C58
	adds r0, r5, #0
	adds r1, r4, #0
	movs r2, #0x80
	lsls r2, r2, #2
	bl AuxSprite_Add
	b _080B0C64
	.align 2, 0
_080B0C4C: .4byte 0x030046B8
_080B0C50: .4byte 0x000003FF
_080B0C54: .4byte 0x08251DD0
_080B0C58:
	adds r0, r5, #0
	adds r1, r4, #0
	movs r2, #0x80
	lsls r2, r2, #3
	bl AuxSprite_Add
_080B0C64:
	movs r0, #0
	strh r0, [r5, #0x10]
	movs r1, #1
	strb r1, [r5, #7]
	movs r0, #0xc3
	lsls r0, r0, #3
	add r0, sb
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [r5, #0x1c]
	str r1, [r5, #0x20]
	mov r3, r8
	lsls r0, r3, #5
	adds r1, r6, #0
	adds r1, #0x66
	strh r0, [r1]
	ldr r0, [r7]
	adds r0, #1
	mov r1, sl
	ands r0, r1
	str r0, [r7]
	lsls r0, r0, #1
	ldr r3, _080B0D1C @ =0x0203B400
	adds r0, r0, r3
	ldrb r1, [r0]
	adds r0, r6, #0
	adds r0, #0x64
	strh r1, [r0]
	ldr r0, _080B0D20 @ =0x08251DD4
	bl FUN_08230860
	adds r1, r0, #0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r0, _080B0D24 @ =0x0000922E
	bl GetFile
	str r0, [r6, #0x58]
	ldr r0, [r7]
	adds r0, #1
	mov r1, sl
	ands r0, r1
	str r0, [r7]
	lsls r0, r0, #1
	ldr r3, _080B0D1C @ =0x0203B400
	adds r0, r0, r3
	ldrh r0, [r0]
	movs r1, #3
	bl Mod
	adds r2, r0, #0
	adds r2, #1
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	adds r0, r6, #0
	adds r0, #0x48
	ldr r1, [r6, #0x58]
	movs r3, #0
	str r3, [sp]
	bl AuxAnim_SetAnim
	ldr r0, [r7]
	adds r0, #1
	mov r1, sl
	ands r0, r1
	str r0, [r7]
	lsls r0, r0, #1
	ldr r3, _080B0D1C @ =0x0203B400
	adds r0, r0, r3
	ldrh r0, [r0]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _080B0D00
	ldr r0, [r5]
	movs r1, #4
	orrs r0, r1
	str r0, [r5]
_080B0D00:
	movs r3, #1
	add r8, r3
	mov r0, r8
	cmp r0, #7
	bgt _080B0D0C
	b _080B0C0C
_080B0D0C:
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080B0D1C: .4byte 0x0203B400
_080B0D20: .4byte 0x08251DD4
_080B0D24: .4byte 0x0000922E
