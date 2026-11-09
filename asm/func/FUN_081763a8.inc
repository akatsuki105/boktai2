	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x20
	adds r5, r0, #0
	str r1, [sp, #0xc]
	str r2, [sp, #0x10]
	str r3, [sp, #0x14]
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r6, [r0]
	ldr r2, _0817647C @ =0x00001012
	adds r4, r6, r2
	movs r0, #8
	strh r0, [r4]
	movs r1, #8
	adds r2, #0x10
	adds r0, r6, r2
	strb r1, [r0]
	ldr r0, _08176480 @ =0x00001024
	adds r1, r6, r0
	ldr r0, _08176484 @ =0x7FFFFFFF
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
	ldr r2, _08176488 @ =0x00001023
	adds r1, r6, r2
	strb r0, [r1]
	movs r0, #0
	str r0, [sp, #0x18]
	mov r8, r0
	movs r7, #0
	movs r1, #0
	ldrsh r0, [r4, r1]
	cmp r7, r0
	blt _08176408
	b _0817651C
_08176408:
	movs r2, #0
	mov sl, r2
	movs r0, #0
	str r0, [sp, #0x1c]
	movs r1, #0xe8
	lsls r1, r1, #3
	adds r4, r6, r1
	movs r2, #0xcb
	lsls r2, r2, #3
	adds r2, r2, r6
	mov sb, r2
	ldr r0, _0817648C @ =0x00000684
	adds r5, r6, r0
_08176422:
	adds r0, r5, #0
	ldr r1, [sp, #0xc]
	bl Video_GetAuxSprite
	mov r0, sb
	adds r1, r5, #0
	movs r2, #0
	bl AuxSprite_Add
	adds r0, r5, #0
	movs r1, #0xd1
	lsls r1, r1, #1
	bl Video_SetAuxSpritePltt
	mov r1, sp
	ldrb r1, [r1, #0x14]
	strb r1, [r4, #0x14]
	ldr r2, [sp, #0x10]
	lsls r1, r2, #0x10
	ldr r0, _08176490 @ =0x0000922E
	lsrs r1, r1, #0x10
	bl GetFile
	adds r1, r0, #0
	str r1, [r4, #0x10]
	ldr r2, _0817647C @ =0x00001012
	adds r0, r6, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	subs r0, #1
	cmp r7, r0
	bne _08176494
	mov r0, sl
	str r0, [sp]
	adds r0, r4, #0
	movs r2, #7
	movs r3, #0
	bl AuxAnim_SetAnim
	movs r0, #4
	ldrb r1, [r4, #0x15]
	orrs r0, r1
	strb r0, [r4, #0x15]
	b _081764DC
	.align 2, 0
_0817647C: .4byte 0x00001012
_08176480: .4byte 0x00001024
_08176484: .4byte 0x7FFFFFFF
_08176488: .4byte 0x00001023
_0817648C: .4byte 0x00000684
_08176490: .4byte 0x0000922E
_08176494:
	ldrb r0, [r4, #0x14]
	add r1, sp, #4
	add r2, sp, #8
	bl Sandworm_GetAnimVariant
	cmp r7, #2
	bgt _081764A8
	movs r3, #0
	movs r0, #0x20
	b _081764B6
_081764A8:
	cmp r7, #4
	bgt _081764B2
	movs r3, #1
	movs r0, #0x10
	b _081764B6
_081764B2:
	movs r3, #2
	movs r0, #8
_081764B6:
	ldrb r1, [r4, #0x15]
	orrs r0, r1
	strb r0, [r4, #0x15]
	ldr r1, [r4, #0x10]
	mov r2, sl
	str r2, [sp]
	adds r0, r4, #0
	movs r2, #6
	bl AuxAnim_SetAnim
	mov r0, r8
	strh r0, [r4, #8]
	movs r1, #1
	add r8, r1
	mov r2, r8
	cmp r2, #3
	ble _081764DC
	movs r0, #0
	mov r8, r0
_081764DC:
	str r6, [r4, #0x34]
	mov r1, sl
	strh r1, [r4, #0x38]
	ldr r2, [sp, #0x18]
	cmp r2, #0
	bne _081764F8
	mov r0, sp
	ldrb r0, [r0, #0x1c]
	strb r0, [r4, #0x1a]
	movs r0, #2
	ldrb r1, [r4, #0x15]
	orrs r0, r1
	strb r0, [r4, #0x15]
	b _081764FE
_081764F8:
	ldr r1, [sp, #0x18]
	adds r1, #1
	str r1, [sp, #0x18]
_081764FE:
	ldr r2, [sp, #0x1c]
	adds r2, #0x18
	str r2, [sp, #0x1c]
	movs r0, #0x92
	lsls r0, r0, #1
	adds r4, r4, r0
	add sb, r0
	adds r5, r5, r0
	adds r7, #1
	ldr r1, _0817652C @ =0x00001012
	adds r0, r6, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r7, r0
	blt _08176422
_0817651C:
	add sp, #0x20
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0817652C: .4byte 0x00001012
