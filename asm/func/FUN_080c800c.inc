	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0xc
	mov sb, r1
	adds r7, r0, #0
	movs r0, #0xa9
	adds r0, r0, r7
	mov r8, r0
	ldrb r0, [r0]
	cmp r0, #0
	beq _080C80A4
	movs r6, #0
	mov r1, r8
	strb r6, [r1]
	movs r3, #0xbc
	lsls r3, r3, #2
	adds r2, r7, r3
	movs r1, #0xbe
	lsls r1, r1, #2
	adds r0, r7, r1
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [r2]
	str r1, [r2, #4]
	ldr r2, _080C8138 @ =0x000002F2
	adds r1, r7, r2
	ldrh r0, [r1]
	adds r0, #0x80
	strh r0, [r1]
	adds r3, #4
	adds r1, r7, r3
	ldrh r0, [r1]
	adds r0, #0x60
	strh r0, [r1]
	ldr r2, _080C813C @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _080C8140 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _080C8144 @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	movs r1, #6
	bl Mod
	ldr r2, _080C8148 @ =0x000025FC
	adds r1, r7, r2
	strb r0, [r1]
	movs r3, #0xc0
	lsls r3, r3, #2
	adds r0, r7, r3
	movs r5, #1
	str r5, [sp]
	str r6, [sp, #4]
	movs r4, #4
	str r4, [sp, #8]
	movs r1, #0x14
	movs r2, #0
	movs r3, #0
	bl SpriteHolder_SetAnim
	movs r1, #0xe6
	lsls r1, r1, #2
	adds r0, r7, r1
	str r5, [sp]
	str r6, [sp, #4]
	str r4, [sp, #8]
	movs r1, #0x18
	movs r2, #0
	movs r3, #0
	bl SpriteHolder_SetAnim
_080C80A4:
	adds r0, r7, #0
	adds r0, #0xfc
	ldr r1, [r0]
	adds r0, r7, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	cmp r4, #0
	bne _080C8184
	mov r0, sb
	movs r1, #0x32
	bl Mod
	cmp r0, #0
	bne _080C80D6
	adds r0, r7, #0
	bl FUN_080c6b44
	movs r2, #0xbb
	lsls r2, r2, #2
	adds r1, r7, r2
	ldrh r0, [r1]
	subs r0, #0x60
	strh r0, [r1]
_080C80D6:
	adds r0, r7, #0
	bl FUN_080c4990
	ldr r0, _080C814C @ =0x03002BE0
	ldr r2, [r0]
	movs r3, #0x2c
	ldrsh r1, [r2, r3]
	movs r3, #0xba
	lsls r3, r3, #2
	adds r0, r7, r3
	movs r3, #0
	ldrsh r0, [r0, r3]
	subs r1, r1, r0
	cmp r1, #0
	bge _080C80F6
	rsbs r1, r1, #0
_080C80F6:
	cmp r1, #0x7f
	bgt _080C8160
	movs r0, #0x30
	ldrsh r1, [r2, r0]
	movs r2, #0xbb
	lsls r2, r2, #2
	adds r0, r7, r2
	movs r3, #0
	ldrsh r0, [r0, r3]
	subs r1, r1, r0
	ldr r0, _080C8150 @ =0x0000031F
	cmp r1, r0
	bgt _080C8160
	ldr r1, _080C8154 @ =0x00001909
	adds r0, r7, r1
	ldrb r1, [r0]
	ldr r2, _080C8158 @ =0x00001908
	adds r0, r7, r2
	strb r1, [r0]
	ldr r1, _080C815C @ =FUN_080c73c0
	movs r0, #3
	adds r2, r7, #0
	adds r2, #0xa3
	strb r0, [r2]
	adds r0, r7, #0
	adds r0, #0xf8
	str r1, [r0]
	subs r0, #0x6c
	str r4, [r0]
	movs r0, #1
	mov r3, r8
	strb r0, [r3]
	b _080C8184
	.align 2, 0
_080C8138: .4byte 0x000002F2
_080C813C: .4byte 0x030046B8
_080C8140: .4byte 0x000003FF
_080C8144: .4byte 0x0203B400
_080C8148: .4byte 0x000025FC
_080C814C: .4byte 0x03002BE0
_080C8150: .4byte 0x0000031F
_080C8154: .4byte 0x00001909
_080C8158: .4byte 0x00001908
_080C815C: .4byte FUN_080c73c0
_080C8160:
	ldr r0, _080C8194 @ =0x000001C1
	cmp sb, r0
	ble _080C8184
	ldr r2, _080C8198 @ =FUN_080c819c
	movs r0, #0xe
	adds r3, r7, #0
	adds r3, #0xa3
	movs r1, #0
	strb r0, [r3]
	adds r0, r7, #0
	adds r0, #0xf8
	str r2, [r0]
	subs r0, #0x6c
	str r1, [r0]
	adds r1, r7, #0
	adds r1, #0xa9
	movs r0, #1
	strb r0, [r1]
_080C8184:
	add sp, #0xc
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080C8194: .4byte 0x000001C1
_080C8198: .4byte FUN_080c819c
