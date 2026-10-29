	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0xc
	mov r8, r1
	adds r7, r0, #0
	adds r1, r7, #0
	adds r1, #0xa9
	ldrb r0, [r1]
	cmp r0, #0
	beq _080C8266
	movs r6, #0
	strb r6, [r1]
	movs r0, #0xbc
	lsls r0, r0, #2
	adds r2, r7, r0
	movs r1, #0xbe
	lsls r1, r1, #2
	adds r0, r7, r1
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [r2]
	str r1, [r2, #4]
	ldr r2, _080C82B0 @ =0x000002F2
	adds r1, r7, r2
	movs r3, #0xa0
	lsls r3, r3, #2
	adds r0, r3, #0
	ldrh r2, [r1]
	adds r0, r0, r2
	strh r0, [r1]
	adds r3, #0x74
	adds r1, r7, r3
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r0, r2, #0
	ldrh r3, [r1]
	adds r0, r0, r3
	strh r0, [r1]
	movs r0, #0x8c
	lsls r0, r0, #2
	bl PlaySound_082406e0
	movs r1, #0xc0
	lsls r1, r1, #2
	adds r0, r7, r1
	movs r5, #1
	str r5, [sp]
	str r6, [sp, #4]
	movs r4, #4
	str r4, [sp, #8]
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl SpriteHolder_SetAnim
	movs r2, #0xe6
	lsls r2, r2, #2
	adds r0, r7, r2
	str r5, [sp]
	str r6, [sp, #4]
	str r4, [sp, #8]
	movs r1, #0x19
	movs r2, #0
	movs r3, #0
	bl SpriteHolder_SetAnim
_080C8266:
	adds r0, r7, #0
	adds r0, #0xfc
	ldr r1, [r0]
	adds r0, r7, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080C833E
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
	ldr r2, _080C82B4 @ =gSineTable
	mov r3, r8
	lsls r0, r3, #1
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	lsls r1, r0, #2
	adds r1, r1, r0
	lsls r0, r1, #4
	subs r0, r0, r1
	lsls r0, r0, #2
	cmp r0, #0
	blt _080C82B8
	asrs r3, r0, #0xc
	b _080C82BE
	.align 2, 0
_080C82B0: .4byte 0x000002F2
_080C82B4: .4byte gSineTable
_080C82B8:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r3, r0, #0
_080C82BE:
	movs r0, #0xbc
	lsls r0, r0, #2
	adds r1, r7, r0
	ldrh r0, [r1]
	adds r0, r0, r3
	strh r0, [r1]
	mov r1, r8
	lsls r0, r1, #2
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	lsls r0, r0, #6
	cmp r0, #0
	blt _080C82E4
	asrs r2, r0, #0xc
	b _080C82EA
_080C82E4:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_080C82EA:
	ldr r3, _080C834C @ =0x000002F2
	adds r1, r7, r3
	subs r3, #0x72
	adds r0, r3, #0
	ldrh r3, [r1]
	adds r0, r0, r3
	adds r0, r0, r2
	strh r0, [r1]
	movs r0, #0xbd
	lsls r0, r0, #2
	adds r1, r7, r0
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r0, r2, #0
	ldrh r3, [r1]
	adds r0, r0, r3
	strh r0, [r1]
	adds r0, r7, #0
	bl Jormungandr_EasePos
	ldr r1, _080C8350 @ =0x00000DBC
	adds r0, r7, r1
	movs r3, #1
	strb r3, [r0]
	mov r2, r8
	cmp r2, #0x7f
	ble _080C833E
	ldr r1, _080C8354 @ =FUN_080c8358
	movs r0, #0x10
	adds r2, r7, #0
	adds r2, #0xa3
	strb r0, [r2]
	adds r0, r7, #0
	adds r0, #0xf8
	str r1, [r0]
	adds r1, r7, #0
	adds r1, #0x8c
	movs r0, #0
	str r0, [r1]
	adds r0, r7, #0
	adds r0, #0xa9
	strb r3, [r0]
_080C833E:
	add sp, #0xc
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080C834C: .4byte 0x000002F2
_080C8350: .4byte 0x00000DBC
_080C8354: .4byte FUN_080c8358
