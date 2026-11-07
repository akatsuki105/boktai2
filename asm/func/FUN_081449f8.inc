	push {r4, r5, r6, r7, lr}
	sub sp, #8
	adds r5, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r7, [r0]
	movs r0, #0xcb
	lsls r0, r0, #3
	adds r2, r7, r0
	movs r1, #3
	rsbs r1, r1, #0
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	ldr r1, _08144A90 @ =0x00000553
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0x24
	beq _08144A22
	b _08144B5E
_08144A22:
	mov r3, sp
	adds r4, r5, #0
	adds r4, #8
	movs r0, #0xe0
	lsls r0, r0, #1
	adds r2, r5, r0
	ldrh r0, [r5, #8]
	ldrh r1, [r2]
	adds r0, r0, r1
	mov r1, sp
	strh r0, [r1]
	ldrh r0, [r4, #2]
	ldrh r1, [r2, #2]
	adds r0, r0, r1
	strh r0, [r3, #2]
	ldrh r0, [r4, #4]
	ldrh r2, [r2, #4]
	adds r0, r0, r2
	strh r0, [r3, #4]
	adds r2, r5, #0
	adds r2, #0x10
	mov r0, sp
	ldrh r0, [r0]
	ldrh r1, [r5, #0x10]
	adds r0, r0, r1
	mov r1, sp
	strh r0, [r1]
	ldrh r0, [r3, #2]
	ldrh r1, [r2, #2]
	adds r0, r0, r1
	strh r0, [r3, #2]
	ldrh r1, [r3, #4]
	ldrh r2, [r2, #4]
	adds r1, r1, r2
	strh r1, [r3, #4]
	mov r0, sp
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	lsls r1, r1, #0x10
	asrs r1, r1, #0x18
	cmp r2, #0
	blt _08144A8C
	cmp r1, #0
	blt _08144A8C
	ldr r0, _08144A94 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08144A8C
	ldr r0, _08144A98 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08144A9C
_08144A8C:
	movs r4, #0
	b _08144AAA
	.align 2, 0
_08144A90: .4byte 0x00000553
_08144A94: .4byte 0x030046A8
_08144A98: .4byte 0x030046AC
_08144A9C:
	ldr r0, _08144ABC @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_08144AAA:
	mov r6, sp
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _08144AC0
	adds r0, #4
	b _08144ACC
	.align 2, 0
_08144ABC: .4byte 0x030046A4
_08144AC0:
	ldr r0, _08144AE0 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08144ACC:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r3, r0, #8
	cmp r2, #1
	beq _08144AE4
	cmp r2, #2
	beq _08144AE8
	b _08144AEC
	.align 2, 0
_08144AE0: .4byte 0x030046A4
_08144AE4:
	ldrb r0, [r6, #4]
	b _08144AEA
_08144AE8:
	ldrb r0, [r6]
_08144AEA:
	subs r3, r3, r0
_08144AEC:
	ldr r2, _08144B68 @ =0x00000472
	adds r1, r5, r2
	movs r2, #0xdf
	lsls r2, r2, #1
	adds r0, r5, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	ldrh r1, [r1]
	adds r0, r0, r1
	cmp r0, r3
	bge _08144B42
	movs r0, #0xe0
	lsls r0, r0, #1
	adds r1, r5, r0
	movs r0, #0
	strh r0, [r1]
	movs r2, #0xe1
	lsls r2, r2, #1
	adds r1, r5, r2
	strh r0, [r1]
	adds r2, #2
	adds r1, r5, r2
	strh r0, [r1]
	movs r2, #0xd6
	lsls r2, r2, #3
	adds r1, r7, r2
	strh r0, [r1]
	adds r2, #2
	adds r1, r7, r2
	strh r0, [r1]
	adds r2, #2
	adds r1, r7, r2
	strh r0, [r1]
	strh r0, [r5, #0x10]
	strh r0, [r5, #0x14]
	strh r0, [r5, #0x12]
	movs r2, #2
	movs r0, #0xcb
	lsls r0, r0, #3
	adds r1, r7, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
_08144B42:
	mov r0, sp
	movs r1, #2
	ldrsh r0, [r0, r1]
	cmp r0, r3
	bge _08144B5E
	movs r2, #0xe1
	lsls r2, r2, #1
	adds r1, r5, r2
	movs r0, #0
	strh r0, [r1]
	strh r0, [r5, #0x12]
	ldr r2, _08144B6C @ =0x000006B2
	adds r1, r7, r2
	strh r0, [r1]
_08144B5E:
	add sp, #8
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08144B68: .4byte 0x00000472
_08144B6C: .4byte 0x000006B2
